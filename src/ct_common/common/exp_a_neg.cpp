// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/exp_a_neg.h"

#include "ct_common/base/class_name_utils.h"

namespace ct_common {

REGISTER_CLASS_NAME(Exp_A_Neg)

Exp_A_Neg::Exp_A_Neg() = default;

Exp_A_Neg::~Exp_A_Neg() = default;

optional<double> Exp_A_Neg::evaluate_double(
    const optional<double>& val) const {
  if (val)
    return -val.value();
  return nullopt;
}

optional<int> Exp_A_Neg::evaluate_int(
    const optional<int>& val) const {
  if (val)
    return -val.value();
  return nullopt;
}

std::string Exp_A_Neg::get_op_token() const { return "-"; }

}  // namespace ct_common
