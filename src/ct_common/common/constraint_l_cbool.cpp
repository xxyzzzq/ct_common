// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/constraint_l_cbool.h"

namespace ct_common {

REGISTER_CLASS_NAME(Constraint_L_CBool)

Constraint_L_CBool::Constraint_L_CBool()
    : Constraint_L_Atomic(), value_(false) {}

Constraint_L_CBool::~Constraint_L_CBool() = default;

const std::string& Constraint_L_CBool::get_str_value() const {
  static std::string str_true = "true";
  static std::string str_false = "false";
  if (value_) {
    return str_true;
  }
  return str_false;
}

optional<bool> Constraint_L_CBool::Evaluate(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  return value_;
}

void Constraint_L_CBool::Dump(
    std::ostream& os,
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs) const {
  os << get_str_value();
}

}  // namespace ct_common
