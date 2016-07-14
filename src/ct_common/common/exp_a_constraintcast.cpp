// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/exp_a_constraintcast.h"

namespace ct_common {

REGISTER_CLASS_NAME(Exp_A_ConstraintCast)

Exp_A_ConstraintCast::Exp_A_ConstraintCast()
    : Exp_A_Atomic() {
  oprds_.resize(1);
}

Exp_A_ConstraintCast::~Exp_A_ConstraintCast() = default;

optional<double> Exp_A_ConstraintCast::EvaluateDouble_Impl(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  optional<bool> val = get_oprd()->Evaluate(param_specs, assignment);
  if (val)
    return nullopt;
  else
    return val.value() ? 1.0 : 0.0;
}

optional<int> Exp_A_ConstraintCast::EvaluateInt_Impl(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  optional<bool> val = get_oprd()->Evaluate(param_specs, assignment);
  if (val)
    return nullopt;
  else
    return val.value() ? 1 : 0;
}

void Exp_A_ConstraintCast::Dump(
    std::ostream& os,
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs) const {
  switch (type_) {
    case EAT_INT:
      os << "int";
      break;
    case EAT_DOUBLE:
      os << "double";
      break;
    default:
      CT_EXCEPTION("unknown cast type");
      break;
  }
  get_oprd()->Dump(os, param_specs);
}

}  // namespace ct_common
