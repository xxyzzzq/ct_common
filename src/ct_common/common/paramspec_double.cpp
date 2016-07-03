// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/paramspec_double.h"

#include <cstdlib>

namespace ct_common {

REGISTER_CLASS_NAME(ParamSpec_Double)

ParamSpec_Double::ParamSpec_Double() = default;

ParamSpec_Double::ParamSpec_Double(const ParamSpec_Double& from) = default;

ParamSpec_Double& ParamSpec_Double::operator=(
    const ParamSpec_Double& right) = default;

ParamSpec_Double::~ParamSpec_Double() = default;

void ParamSpec_Double::set_values(
    const std::vector<std::string>& string_values) {
  ParamSpec::set_values(string_values);
  for (std::size_t i = 0; i < string_values.size(); ++i) {
    double_values_.push_back(atof(string_values[i].c_str()));
  }
  // now push back the invalid value
  double_values_.push_back(0);
}

}  // namespace ct_common
