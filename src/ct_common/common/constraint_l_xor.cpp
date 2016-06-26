//===----- ct_common/common/constraint_l_xor.cpp ----------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Constraint_L_Xor
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/constraint_l_xor.h"

using namespace ct::common;

Constraint_L_Xor::Constraint_L_Xor(void)
  : Constraint_L_Binary() {
}

Constraint_L_Xor::Constraint_L_Xor(const Constraint_L_Xor &from)
  : Constraint_L_Binary(from) {
}

Constraint_L_Xor &Constraint_L_Xor::operator = (
    const Constraint_L_Xor &right) {
  Constraint_L_Binary::operator=(right);
  return *this;
}

Constraint_L_Xor::~Constraint_L_Xor(void) {
}

std::string Constraint_L_Xor::get_class_name(void) const {
  return Constraint_L_Xor::class_name();
}

std::string Constraint_L_Xor::class_name(void) {
  return "Constraint_L_Xor";
}

EvalType_Bool Constraint_L_Xor::evaluate_func(EvalType_Bool val_l, EvalType_Bool val_r) const {
  EvalType_Bool tmp_result;
  tmp_result.is_valid_ = val_l.is_valid_ && val_r.is_valid_;
  if (tmp_result.is_valid_) {
    tmp_result.value_ = val_l.value_ != val_r.value_;
  }
  return tmp_result;
}

std::string Constraint_L_Xor::get_op_token(void) const {
  return "^^";
}
