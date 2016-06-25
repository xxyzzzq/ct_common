# Programming Guide for `ct_common` Library

## Authors

Zhiqiang Zhang, zqzhang@ios.ac.cn

## Introduction

`ct_common` is a utility library for developing tools for combinatorial testing
(CT), which is used in [Cascade](http://castar.iscas.ac.cn/ctportal/), a
combinatorial test generation tool.  It provides many useful classes for
describing software under test (SUT) models, and a parser which can parse
\emph{Cascade} model files into data structures for further processing. {\tt
ct\_common} contains both high-level classes, which helps describing complex SUT
models more easily, and low-level classes which are more suitable for computer
processing.

`ct_common` has two sub-libraries:

* `libct_common`: contains many basic classes for CT.
* `libct_file_parse`: the parser interface.

## Building `ct_common`

Here is how to integrate `ct_common` into your project. The library now uses
C++11, so make sure your compiler supports C++11 (`-std=c++11` for `gcc` and
`clang`, or use MSVC 2015). C++11 is very popular now so there's no
reason not to embrass it.

`ct_common` uses the `CMake` build system, so you need to install it.

If you want to use `libct_file_parse`, you need to install `python` and `bison`,
and make sure they are in your system `PATH` variable.

All other prerequisites for building `ct_common` can be fetched by running the
`bootstrap.sh` script located at the `ct_common` root directory.

### Building `ct_common` standalone

We don't recommend in-source build, so please make a directory for the files
generated during build.

    cd ${CT_COMMON_DIR}
    ./bootstrap
    mkdir out
    cd out
    cmake .. (Windows: cmake -G "Visual Studio 14 2015" ..)
    make

### Using `ct_common` in your project

It's a prefered way to put `ct_common` in a subdirectory of your project, and
your project use the `CMake` build system. In this case, you just need to use
`add_subdirectory()` in your `CMakeLists.txt` to include `ct_common`, and use
`include_directories()` to add proper include directory from `ct_common`, then
you are good to go. Just feel free to include the headers from `ct_common`, and
use `target_link_library(ct_common|ct_file_parse)` to link the libraries.

If you are not using `CMake`, it is still doable to use `ct_common`. You need to
build `ct_common` standalone, then add the include directories and library
linkage into your own building system.

Note that if you use {\tt file\_parse}, you need to add additional preprocessor
definitions to your project (otherwise there will be warning messages from the
`Quex` lexer):

    QUEX_OPTION_STRANGE_ISTREAM_IMPLEMENTATION
    QUEX_OPTION_ASSERTS_WARNING_MESSAGE_DISABLED

## Design Overview

All the classes of `ct_common` are included in namespace `ct::`.

### Sub-library `libct_common`

The classes of `libct_common` are included in namespace `ct::common::`.
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
* `EvalType`: the results of evaluating Boolean, numeric and string expressions;
* `RawStrength`: low-level representation for covering strength.

### Sub-library `libct_file_parse`

`file_parse` depend on `common`. All the classes are included in namespace `ct::`.

Some important high-level classes are:

* `lexer`: the lexer converting input streams into tokens;
* `parser`: the parser converting tokens into data structures of {\tt common};
* `common::assembler`: the assembler classes which directly assembles data
  structures of `common`.

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

```c++
#include <fstream>
#include <iostream>
#include <map>

#include "ct_common/common/sutmodel.h"
#include "ct_common/common/tuplepool.h"
#include "ct_common/file_parse/assembler.h"
#include "ct_common/file_parse/ct_lexer.hpp"
#include "ct_common/file_parse/ct_parser.tab.hpp"
#include "ct_common/file_parse/err_logger_cerr.h"

using namespace ct;
using namespace ct::common;

int main(int argc, char* argv[]) {
  std::string file_name;
  if (argc < 2) {
    std::cerr << "please specify the file name" << std::endl;
    return 1;
  }
  file_name = argv[1];
  std::ifstream infile;
#ifdef _MSC_VER
  // handling file names with non-ascii characters
  wchar_t* wcstring = new wchar_t[file_name.size() + 1];
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
    ct::lexer lexer(&infile);
    assembler.setErrLogger(std::shared_ptr<ErrLogger>(new ErrLogger_Cerr()));
    yy::ct_parser parser(lexer, sut_model.param_specs_, sut_model.strengths_,
                         sut_model.seeds_, sut_model.constraints_, assembler);
    parser.parse();
  } catch (std::runtime_error e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "unhandled exception when parsing input file" << std::endl;
    std::cerr << "exiting" << std::endl;
    return 1;
  }
  if (assembler.numErrs() > 0) {
    std::cerr << assembler.numErrs() << " errors in the input file, exiting"
              << std::endl;
    return 2;
  }
  std::cout << "successfully parsed the input file" << std::endl;
  std::cout << "# parameters:  " << sut_model.param_specs_.size() << std::endl;
  std::cout << "# strengths:   " << sut_model.strengths_.size() << std::endl;
  std::cout << "# seeds:       " << sut_model.seeds_.size() << std::endl;
  std::cout << "# constraints: " << sut_model.constraints_.size() << std::endl;

  std::vector<RawStrength> raw_strengths;
  TuplePool tuple_pool;
  for (std::size_t i = 0; i < sut_model.strengths_.size(); ++i) {
    attach_2_raw_strength(sut_model.strengths_[i], raw_strengths);
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
    } while (tuple.to_the_next_tuple(sut_model.param_specs_));
  }
  std::cout << "# target combinations: " << tuple_pool.size() << std::endl;

  TuplePool forbidden_tuple_pool;
  for (std::size_t i = 0; i < sut_model.constraints_.size(); ++i) {
    std::set<std::size_t> rel_pids;
    sut_model.constraints_[i]->touch_pids(sut_model.param_specs_, rel_pids);
    Tuple tuple;
    for (std::set<std::size_t>::const_iterator iter = rel_pids.begin();
         iter != rel_pids.end(); iter++) {
      tuple.push_back(PVPair(*iter, 0));
    }
    do {
      EvalType_Bool result =
          sut_model.constraints_[i]->Evaluate(sut_model.param_specs_, tuple);
      if (!result.is_valid_ || !result.value_) {
        forbidden_tuple_pool.insert(tuple);
      }
    } while (tuple.to_the_next_tuple_with_ivld(sut_model.param_specs_));
  }
  std::cout << "# forbidden combinations: " << forbidden_tuple_pool.size()
            << std::endl;
  return 0;
}
```

## Useful Contents

### Cascade

`ct_common` is initiated from the
[Cascade combinatorial test generator](http://castar.iscas.ac.cn/ctportal/).  The
features in this library are designed for general purpose, but the interfaces
are specially customized for Cascade. So many high-level features are not
compatible with some existing methods or algorithms, but they can be easily
translated into corresponding low-level representations, which are compatible
with most existing methods or algorithms.  Due to time limit, we don't have
enough time to write the detailed documentation for classes in {\tt
ct\_common}. Thus we strongly recommend you to read the Cascade user manual
before using our library. You can find the according words for most features of
{\tt ct\_common} in the
[Cascade manual](http://castar.iscas.ac.cn/ctportal/download/cascade_manual_1.1.pdf).

### Quex

If you want to add more functions to the parser, you may want to modify the
lexer (`ct_lexer.qx`).

### Bison

If you want to add more functions to the parser, you may need to modify the
parser (`ct_parser.ypp`) The materials can be found at
[here](https://www.gnu.org/software/bison/).
