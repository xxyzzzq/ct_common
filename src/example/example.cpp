#include <fstream>
#include <iostream>
#include <map>

#include "ct_common/common/sutmodel.h"
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
    assembler.setErrLogger(std::shared_ptr<ErrLogger>(new ErrLogger_Cerr()));
    ct_common::parser parser(lexer, sut_model.param_specs_, sut_model.strengths_,
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
    attach_2_raw_strength(sut_model.strengths_[i], &raw_strengths);
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
    sut_model.constraints_[i]->touch_pids(sut_model.param_specs_, &rel_pids);
    Tuple tuple;
    for (std::set<std::size_t>::const_iterator iter = rel_pids.begin();
         iter != rel_pids.end(); iter++) {
      tuple.push_back(PVPair(*iter, 0));
    }
    do {
      optional<bool> result =
          sut_model.constraints_[i]->Evaluate(sut_model.param_specs_, tuple);
      if (result || !result.value()) {
        forbidden_tuple_pool.insert(tuple);
      }
    } while (tuple.to_the_next_tuple_with_ivld(sut_model.param_specs_));
  }
  std::cout << "# forbidden combinations: " << forbidden_tuple_pool.size()
            << std::endl;
  return 0;
}
