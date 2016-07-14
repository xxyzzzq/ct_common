// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/exp_a_binary.h"

#include "ct_common/base/arithmetic_utils.h"

namespace ct_common {

class ExpABinary_InternalEvaluator {
 public:
  template <typename T>
  static optional<T> Evaluate(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const Assignment& assignment,
      const Exp_A_Binary& exp) {
    if (exp.get_loprd()->get_type() == EAT_INT &&
        exp.get_roprd()->get_type() == EAT_INT) {
      GET_EXP_VAL(int, val_l, exp.get_loprd(), param_specs, assignment);
      GET_EXP_VAL(int, val_r, exp.get_roprd(), param_specs, assignment);

      return cast_optional<T>(exp.EvaluateIntInternal(val_l, val_r));
    } else if (exp.get_loprd()->get_type() == EAT_DOUBLE ||
               exp.get_roprd()->get_type() == EAT_DOUBLE) {
      GET_EXP_VAL(double, val_l, exp.get_loprd(), param_specs, assignment);
      GET_EXP_VAL(double, val_r, exp.get_roprd(), param_specs, assignment);

      return cast_optional<T>(exp.EvaluateDoubleInternal(val_l, val_r));
    }
    CT_EXCEPTION("cannot evaluate this expression");
    return nullopt;
  }
};

REGISTER_CLASS_NAME(Exp_A_Binary)

Exp_A_Binary::Exp_A_Binary()
    : Exp_A() {
  oprds_.resize(2);
}

Exp_A_Binary::~Exp_A_Binary() = default;

optional<double> Exp_A_Binary::EvaluateDouble_Impl(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  return ExpABinary_InternalEvaluator::Evaluate<double>(
      param_specs, assignment, *this);
}

optional<int> Exp_A_Binary::EvaluateInt_Impl(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  return ExpABinary_InternalEvaluator::Evaluate<int>(
      param_specs, assignment, *this);
}

void Exp_A_Binary::Dump(
    std::ostream& os,
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs) const {
  os << "(";
  get_loprd()->Dump(os, param_specs);
  os << GetOpToken();
  get_roprd()->Dump(os, param_specs);
  os << ")";
}

}  // namespace ct_common
