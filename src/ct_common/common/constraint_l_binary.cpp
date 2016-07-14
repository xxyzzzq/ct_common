// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/constraint_l_binary.h"

#include "ct_common/base/arithmetic_utils.h"

namespace ct_common {

REGISTER_CLASS_NAME(Constraint_L_Binary)

Constraint_L_Binary::Constraint_L_Binary()
    : Constraint_L() {
  oprds_.resize(2);
}

Constraint_L_Binary::~Constraint_L_Binary() = default;

optional<bool> Constraint_L_Binary::Evaluate(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  optional<bool> l_val, r_val;
  l_val = get_loprd()->Evaluate(param_specs, assignment);
  r_val = get_roprd()->Evaluate(param_specs, assignment);
  return EvaluateInternal(l_val, r_val);
}

void Constraint_L_Binary::Dump(
    std::ostream& os,
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs) const {
  os << "(";
  get_loprd()->Dump(os, param_specs);
  os << GetOpToken();
  get_roprd()->Dump(os, param_specs);
  os << ")";
}

}  // namespace ct_common
