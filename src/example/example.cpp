#include <fstream>
#include <iostream>
#include <map>

#include "ct_common/common/sut_model.h"
#include "ct_common/common/tuplepool.h"
#include "ct_common/file_parse/assembler.h"
#include "ct_common/file_parse/ct_common_lexer.hpp"
#include "ct_common/file_parse/parser.tab.hpp"
#include "ct_common/file_parse/err_logger_cerr.h"

using namespace ct_common;

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
    sut_model.constraints[i]->touch_pids(sut_model.param_specs, &rel_pids);
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
