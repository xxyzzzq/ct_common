# Programming Guide for ct_common Library

## Introduction

ct_common is a utility library for developing tools for combinatorial testing
(CT), which is used in [Cascade](http://castar.iscas.ac.cn/ctportal/), a
combinatorial test generation tool.  It provides many useful classes for
describing software under test (SUT) models, and a parser which can parse
*Cascade model files* into data structures for further processing.  ct_common
contains both high-level classes, which helps describing complex SUT models more
easily, and low-level classes which are more suitable for computer processing.

ct_common has two sub-libraries:

* `libct_common`: contains many basic classes for CT.
* `libct_common_parser`: the parser interface.

## Building ct_common

Here is how to integrate ct_common into your project. The library now uses
C++11, so make sure your compiler supports C++11 (`-std=c++11` for `gcc` and
`clang`, or use MSVC 2015). C++11 is very popular now so there's no
reason not to embrass it.

ct_common uses the [CMake](http://cmake.org/) build system, so you need to install it.

If you want to use `libct_file_parse`, you need to install `python` and `bison`,
and make sure they are in your system `PATH` variable.

All other prerequisites for building ct_common can be fetched by running the
`bootstrap` script located at the ct_common root directory.

### Building ct_common as a standalone library

We don't recommend in-source build, so please make a directory for the files
generated during build.

    cd ${CT_COMMON_DIR}
    ./bootstrap
    mkdir out
    cd out
    cmake .. (Windows: cmake -G "Visual Studio 14 2015" ..)
    make

### Using ct_common in your project

It's a prefered way to put ct_common in a subdirectory of your project, and
your project use the `CMake` build system. In this case, you just need to use
`add_subdirectory()` in your `CMakeLists.txt` to include ct_common, and use
`include_directories()` to add proper include directory from ct_common, then
you are good to go. Just feel free to include the headers from ct_common, and
use `target_link_library(ct_common|ct_file_parse)` to link the libraries.

If you are not using `CMake`, it is still doable to use ct_common. You need to
build ct_common standalone, then add the include directories and library
linkage into your own building system.

Note that if you use {\tt file\_parse}, you need to add additional preprocessor
definitions to your project (otherwise there will be warning messages from the
`Quex` lexer):

    QUEX_OPTION_STRANGE_ISTREAM_IMPLEMENTATION
    QUEX_OPTION_ASSERTS_WARNING_MESSAGE_DISABLED

## Design Overview

All the classes of ct_common are included in namespace `ct_common::`.

### Sub-library libct_common

The classes of `libct_common` are included in namespace `ct_common::`.
Some important high-level classes are:

* `ParamSpec`: base class for parameter information;
* `Strength`: base class for covering strength;
* `Seed`: base class for seeds;
* `TreeNode`: base class for expressions;
* `Constraint`: base class for Boolean expressions;
* `Exp`: base class for numeric expressions and string expressions;
* `SUTModel`: a struct containing lists of `ParamSpec`, `Strength`, `Seed`,
  `Constraint`.

Some low-level classes are:

* `PVPair`: parameter-value pair;
* `Tuple`: a parameter combination;
* `TuplePool`: a pool of parameter combinations;
* `optional<T>`: the results of evaluating Boolean, numeric and string
  expressions;
* `RawStrength`: low-level representation for covering strength.

### Sub-library libct_common_parser

`libct_common_parser` depend on `lib_ct_common`. All the classes are included in
namespace `ct_common::`.

Some important high-level classes are:

* `lexer`: the lexer converting input streams into tokens;
* `parser`: the parser converting tokens into data structures of ct_common;
* `assembler`: the assembler classes which directly assembles data
  structures of `lib_ct_common`.

## A Simple Example
Here's an example to show how to use the parser.

Suppose we want to parse the input file into internal data structures,
and print the following information about the model:

* Number of parameters;
* Number of strengths;
* Number of seeds;
* Number of constraints;
* Number of target combinations;
* Number of forbidden combinations;

A program to achieve these goals is as follows (the example is included in the
source package):

```cpp
// Copyright 2016 ct_common authors. See LICENSE file for details.

#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "ct_common/common/sut_model.h"
#include "ct_common/common/tuplepool.h"
#include "ct_common/parser/assembler.h"
#include "ct_common/parser/ct_common_lexer.hpp"
#include "ct_common/parser/err_logger_cerr.h"
#include "ct_common/parser/parser.tab.hpp"

namespace ct_common {

int main(int argc, char *argv[]) {
  std::string file_name;
  if (argc < 2) {
    std::cerr << "please specify the file name" << std::endl;
    return 1;
  }
  file_name = argv[1];
  std::ifstream infile;
#ifdef _MSC_VER
  // handling file names with non-ascii characters
  wchar_t *wcstring = new wchar_t[file_name.size() + 1];
  setlocale(LC_ALL, ".OCP");
  mbstowcs(wcstring, file_name.c_str(), file_name.size() + 1);
  infile.open(wcstring);
  delete[] wcstring;
  setlocale(LC_ALL, "");
#else   // _MSC_VER
  infile.open(file_name.c_str());
#endif  // _MSC_VER
  if (!infile.is_open()) {
    std::cerr << "cannot open the input file" << std::endl;
    return 1;
  }
  SUTModel sut_model;
  Assembler assembler;
  try {
    ct_common::lexer lexer(&infile);
    assembler.SetErrLogger(std::shared_ptr<ErrLogger>(new ErrLogger_Cerr()));
    ct_common::parser parser(&lexer, &sut_model, &assembler);
    parser.parse();
  } catch (std::runtime_error e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "unhandled exception when parsing input file" << std::endl;
    std::cerr << "exiting" << std::endl;
    return 1;
  }
  if (assembler.NumErrs() > 0) {
    std::cerr << assembler.NumErrs() << " errors in the input file, exiting"
              << std::endl;
    return 2;
  }
  std::cout << "successfully parsed the input file" << std::endl;
  std::cout << "# parameters:  " << sut_model.param_specs.size() << std::endl;
  std::cout << "# strengths:   " << sut_model.strengths.size() << std::endl;
  std::cout << "# seeds:       " << sut_model.seeds.size() << std::endl;
  std::cout << "# constraints: " << sut_model.constraints.size() << std::endl;

  std::vector<RawStrength> raw_strengths;
  TuplePool tuple_pool;
  for (std::size_t i = 0; i < sut_model.strengths.size(); ++i) {
    AttachToRawStrength(sut_model.strengths[i], &raw_strengths);
  }
  for (std::size_t i = 0; i < raw_strengths.size(); ++i) {
    Tuple tuple;
    for (std::size_t j = 0; j < raw_strengths[i].size(); ++j) {
      tuple.push_back(PVPair(raw_strengths[i][j], 0));
    }
    if (tuple.size() <= 0) {
      continue;
    }
    do {
      tuple_pool.insert(tuple);
    } while (tuple.ToTheNextTuple(sut_model.param_specs));
  }
  std::cout << "# target combinations: " << tuple_pool.size() << std::endl;

  TuplePool forbidden_tuple_pool;
  for (std::size_t i = 0; i < sut_model.constraints.size(); ++i) {
    std::set<std::size_t> rel_pids;
    sut_model.constraints[i]->TouchPids(sut_model.param_specs, &rel_pids);
    Tuple tuple;
    for (std::set<std::size_t>::const_iterator iter = rel_pids.begin();
         iter != rel_pids.end(); iter++) {
      tuple.push_back(PVPair(*iter, 0));
    }
    do {
      optional<bool> result =
          sut_model.constraints[i]->Evaluate(sut_model.param_specs, tuple);
      if (result || !result.value()) {
        forbidden_tuple_pool.insert(tuple);
      }
    } while (tuple.ToTheNextTupleWithIvld(sut_model.param_specs));
  }
  std::cout << "# forbidden combinations: " << forbidden_tuple_pool.size()
            << std::endl;
  return 0;
}

}  // namespace ct_common

int main(int argc, char* argv[]) {
  ct_common::main(argc, argv);
}
```

## Useful Contents

### Cascade

ct_common is initiated from the
[Cascade combinatorial test generator](http://castar.iscas.ac.cn/ctportal/).
The features in this library are designed for general purpose, but the
interfaces are specially customized for Cascade. So many high-level features are
not compatible with some existing methods or algorithms, but they can be easily
translated into corresponding low-level representations, which are compatible
with most existing methods or algorithms.  Due to time limit, we don't have
enough time to write the detailed documentation for classes in ct_common. Thus
we strongly recommend you to read the Cascade user manual before using our
library. You can find the according words for most features of ct_common in the
[Cascade manual](http://castar.iscas.ac.cn/ctportal/download/cascade_manual_1.1.pdf).

### Quex

If you want to add more functions to the parser, you may want to modify the
lexer (`ct_lexer.qx`).

### Bison

If you want to add more functions to the parser, you may need to modify the
parser (`ct_parser.ypp`) The materials can be found at
[here](https://www.gnu.org/software/bison/).

## Authors

**Zhiqiang Zhang**, zqzhang@ios.ac.cn
