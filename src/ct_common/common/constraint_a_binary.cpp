// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/constraint_a_binary.h"

#include "ct_common/base/arithmetic_utils.h"
#include "ct_common/base/class_name_utils.h"

namespace ct_common {

REGISTER_CLASS_NAME(Constraint_A_Binary)

Constraint_A_Binary::Constraint_A_Binary()
    : Constraint_A(), precision_(0) {
  oprds_.resize(2);
}

Constraint_A_Binary::~Constraint_A_Binary() = default;

optional<bool> Constraint_A_Binary::Evaluate(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  if (get_loprd()->get_type() == EAT_INT &&
      get_roprd()->get_type() == EAT_INT) {
    GET_EXP_VAL(int, val_l, get_loprd(), param_specs,
                assignment);
    GET_EXP_VAL(int, val_r, get_roprd(), param_specs,
                assignment);
    if (val_l && val_r) {
      return EvaluateIntInternal(val_l.value(), val_r.value());
    }
  } else {
    GET_EXP_VAL(double, val_l, get_loprd(), param_specs,
                assignment);
    GET_EXP_VAL(double, val_r, get_roprd(), param_specs,
                assignment);
    if (val_l && val_r) {
      return EvaluateDoubleInternal(val_l.value(), val_r.value());
    }
  }
  return nullopt;
}

void Constraint_A_Binary::dump(
    std::ostream& os,
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs) const {
  os << "(";
  get_loprd()->dump(os, param_specs);
  os << GetOpToken();
  get_roprd()->dump(os, param_specs);
  os << ")";
}

}  // namespace ct_common
