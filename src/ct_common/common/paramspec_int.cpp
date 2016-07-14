// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/paramspec_int.h"

#include <cstdlib>

namespace ct_common {

REGISTER_CLASS_NAME(ParamSpec_Int)

ParamSpec_Int::ParamSpec_Int() = default;

ParamSpec_Int::ParamSpec_Int(const ParamSpec_Int& from) = default;

ParamSpec_Int& ParamSpec_Int::operator=(const ParamSpec_Int& right) = default;

ParamSpec_Int::~ParamSpec_Int() = default;

void ParamSpec_Int::set_values(const std::vector<std::string>& string_values) {
  ParamSpec::set_values(string_values);
  for (std::size_t i = 0; i < string_values.size(); ++i) {
    int_values_.push_back(atoi(string_values[i].c_str()));
  }
  // now push back the invalid value
  int_values_.push_back(0);
}

}  // namespace ct_common
