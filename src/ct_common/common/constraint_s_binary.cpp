// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/constraint_s_binary.h"

#include "ct_common/base/arithmetic_utils.h"

namespace ct_common {

REGISTER_CLASS_NAME(Constraint_S_Binary)

Constraint_S_Binary::Constraint_S_Binary() : Constraint_S() {
  oprds_.resize(2);
}

Constraint_S_Binary::~Constraint_S_Binary() = default;

optional<bool> Constraint_S_Binary::Evaluate(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  optional<std::string> val_l = get_loprd()->Evaluate(
      param_specs, assignment);
  optional<std::string> val_r = get_roprd()->Evaluate(
      param_specs, assignment);
  return EvaluateInternal(val_l, val_r);
}

void Constraint_S_Binary::Dump(
    std::ostream& os,
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs) const {
  os << "(";
  get_loprd()->Dump(os, param_specs);
  os << GetOpToken();
  get_roprd()->Dump(os, param_specs);
  os << ")";
}

}  // namespace ct_common
