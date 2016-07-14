// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/constraint_l_unary.h"

#include "ct_common/base/class_name_utils.h"

namespace ct_common {

REGISTER_CLASS_NAME(Constraint_L_Unary)

Constraint_L_Unary::Constraint_L_Unary() : Constraint_L() {
  oprds_.resize(1);
}

Constraint_L_Unary::~Constraint_L_Unary() = default;

optional<bool> Constraint_L_Unary::Evaluate(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  return EvaluateInternal(
      get_oprd()->Evaluate(param_specs, assignment));
}

void Constraint_L_Unary::Dump(
    std::ostream& os,
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs) const {
  os << GetOpToken();
  get_oprd()->Dump(os, param_specs);
}

}  // namespace ct_common
