//===----- ct_common/common/paramspec_bool.cpp ------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class ParamSpec_Bool
//
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include "ct_common/common/paramspec_bool.h"

using namespace ct::common;

ParamSpec_Bool::ParamSpec_Bool(void)
  : ParamSpec(), bool_values_() {
}

ParamSpec_Bool::ParamSpec_Bool(const ParamSpec_Bool& from)
  : ParamSpec(from), bool_values_(from.bool_values_) {
}

ParamSpec_Bool &ParamSpec_Bool::operator = (
    const ParamSpec_Bool &right) {
  ParamSpec::operator=(right);
  this->bool_values_ = right.bool_values_;
  return *this;
}

ParamSpec_Bool::~ParamSpec_Bool(void) {
}

std::string ParamSpec_Bool::get_class_name(void) const {
  return ParamSpec_Bool::class_name();
}

std::string ParamSpec_Bool::class_name(void) {
  return "ParamSpec_Bool";
}

void ParamSpec_Bool::set_values(const std::vector<std::string> &string_values) {
  std::vector<std::string> str_values;
  str_values.push_back("false");
  str_values.push_back("true");
  ParamSpec::set_values(str_values);
  this->bool_values_.push_back(false);
  this->bool_values_.push_back(true);
  this->bool_values_.push_back(false);
}
