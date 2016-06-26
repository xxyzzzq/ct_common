//===----- ct_common/common/constraint_l_iff.cpp ----------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Constraint_L_Iff
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/constraint_l_iff.h"

using namespace ct::common;

Constraint_L_Iff::Constraint_L_Iff(void)
  : Constraint_L_Binary() {
}

Constraint_L_Iff::Constraint_L_Iff(const Constraint_L_Iff &from)
  : Constraint_L_Binary(from) {
}

Constraint_L_Iff &Constraint_L_Iff::operator = (
    const Constraint_L_Iff &right) {
  Constraint_L_Binary::operator=(right);
  return *this;
}

Constraint_L_Iff::~Constraint_L_Iff(void) {
}

std::string Constraint_L_Iff::get_class_name(void) const {
  return Constraint_L_Iff::class_name();
}

std::string Constraint_L_Iff::class_name(void) {
  return "Constraint_L_Iff";
}

EvalType_Bool Constraint_L_Iff::evaluate_func(EvalType_Bool val_l, EvalType_Bool val_r) const {
  EvalType_Bool tmp_return;
  tmp_return.is_valid_ = val_l.is_valid_ && val_r.is_valid_;
  if (tmp_return.is_valid_) {
    tmp_return.value_ = (val_l.value_ == val_r.value_);
  }
  return tmp_return;
}

std::string Constraint_L_Iff::get_op_token(void) const {
  return "<->";
}
