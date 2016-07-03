// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/paramspec_bool.h"

#include <cstdlib>

namespace ct_common {

REGISTER_CLASS_NAME(ParamSpec_Bool)

ParamSpec_Bool::ParamSpec_Bool() = default;

ParamSpec_Bool::ParamSpec_Bool(const ParamSpec_Bool& from) = default;

ParamSpec_Bool& ParamSpec_Bool::operator=(
    const ParamSpec_Bool& right) = default;

ParamSpec_Bool::~ParamSpec_Bool() = default;

void ParamSpec_Bool::set_values(const std::vector<std::string>& string_values) {
  std::vector<std::string> str_values;
  str_values.push_back("false");
  str_values.push_back("true");
  ParamSpec::set_values(str_values);
  bool_values_.push_back(false);
  bool_values_.push_back(true);
  bool_values_.push_back(false);
}

}  // namespace ct_common
