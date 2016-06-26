//===----- ct_common/common/paramspec_int.cpp -------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class ParamSpec_Int
//
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include "ct_common/common/paramspec_int.h"

using namespace ct::common;

ParamSpec_Int::ParamSpec_Int(void)
  : ParamSpec() {
}

ParamSpec_Int::ParamSpec_Int(const ParamSpec_Int &from)
  : ParamSpec(from), int_values_(from.int_values_) {
}

ParamSpec_Int &ParamSpec_Int::operator = (const ParamSpec_Int &right) {
  ParamSpec::operator=(right);
  this->int_values_ = right.int_values_;
  return (*this);
}

ParamSpec_Int::~ParamSpec_Int(void) {
}

std::string ParamSpec_Int::get_class_name(void) const {
  return ParamSpec_Int::class_name();
}

std::string ParamSpec_Int::class_name(void) {
  return "ParamSpec_Int";
}

void ParamSpec_Int::set_values(const std::vector<std::string> &string_values){
  ParamSpec::set_values(string_values);
  for (std::size_t i = 0; i < string_values.size(); ++i) {
    this->int_values_.push_back(atoi(string_values[i].c_str()));
  }
  // now push back the invalid value
  this->int_values_.push_back(0);
}
