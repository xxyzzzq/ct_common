// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/exp_a_unary.h"

namespace ct_common {

REGISTER_CLASS_NAME(Exp_A_Unary)

Exp_A_Unary::Exp_A_Unary() : Exp_A() {
  oprds_.resize(1);
}

Exp_A_Unary::~Exp_A_Unary() = default;

optional<double> Exp_A_Unary::EvaluateDouble_Impl(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  GET_EXP_VAL(double, oprd_val, get_oprd(), param_specs,
              assignment);
  return evaluate_double(oprd_val);
}

optional<int> Exp_A_Unary::EvaluateInt_Impl(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  GET_EXP_VAL(int, oprd_val, get_oprd(), param_specs,
              assignment);
  return evaluate_int(oprd_val);
}

void Exp_A_Unary::Dump(
    std::ostream& os,
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs) const {
  os << get_op_token();
  get_oprd()->Dump(os, param_specs);
}

}  // namespace ct_common
