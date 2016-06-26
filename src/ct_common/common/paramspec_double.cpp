//===----- ct_common/common/paramspec_double.cpp ----------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class ParamSpec_Double
//
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include "ct_common/common/paramspec_double.h"

using namespace ct::common;

ParamSpec_Double::ParamSpec_Double(void)
  : ParamSpec(), double_values_() {
}

ParamSpec_Double::ParamSpec_Double(const ParamSpec_Double& from)
  : ParamSpec(from), double_values_(from.double_values_) {
}

ParamSpec_Double &ParamSpec_Double::operator = (
    const ParamSpec_Double &right) {
  ParamSpec::operator=(right);
  this->double_values_ = right.double_values_;
  return *this;
}

ParamSpec_Double::~ParamSpec_Double(void) {
}

std::string ParamSpec_Double::get_class_name(void) const {
  return ParamSpec_Double::class_name();
}

std::string ParamSpec_Double::class_name(void) {
  return "ParamSpec_Double";
}

void ParamSpec_Double::set_values(const std::vector<std::string> &string_values) {
  ParamSpec::set_values(string_values);
  for (std::size_t i = 0; i < string_values.size(); ++i) {
    this->double_values_.push_back(atof(string_values[i].c_str()));
  }
  // now push back the invalid value
  this->double_values_.push_back(0);
}
