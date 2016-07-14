// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/constraint_l_not.h"

namespace ct_common {

REGISTER_CLASS_NAME(Constraint_L_Not)

Constraint_L_Not::Constraint_L_Not() = default;

Constraint_L_Not::~Constraint_L_Not() = default;


optional<bool> Constraint_L_Not::EvaluateInternal(
    const optional<bool>& val) const {
  if (!val)
    return nullopt;
  return !val.value();
}

std::string Constraint_L_Not::GetOpToken() const { return "!"; }

}  // namespace ct_common
