//===----- ct_common/common/constraint_l_or.cpp -----------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Constraint_L_Or
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/constraint_l_or.h"

using namespace ct::common;

Constraint_L_Or::Constraint_L_Or(void) : Constraint_L_Binary() {}

Constraint_L_Or::Constraint_L_Or(const Constraint_L_Or &from)
    : Constraint_L_Binary(from) {}

Constraint_L_Or &Constraint_L_Or::operator=(const Constraint_L_Or &right) {
  Constraint_L_Binary::operator=(right);
  return *this;
}

Constraint_L_Or::~Constraint_L_Or(void) {}

std::string Constraint_L_Or::get_class_name(void) const {
  return Constraint_L_Or::class_name();
}

std::string Constraint_L_Or::class_name(void) { return "Constraint_L_Or"; }

EvalType_Bool Constraint_L_Or::evaluate_func(EvalType_Bool val_l,
                                             EvalType_Bool val_r) const {
  EvalType_Bool tmp_return;
  if (val_l.is_valid_ && val_r.is_valid_) {
    tmp_return.is_valid_ = true;
    tmp_return.value_ = val_l.value_ || val_r.value_;
  } else {
    tmp_return.is_valid_ =
        (val_l.is_valid_ && val_l.value_) || (val_r.is_valid_ && val_r.value_);
    tmp_return.value_ = tmp_return.is_valid_;
  }
  return tmp_return;
}

std::string Constraint_L_Or::get_op_token(void) const { return "||"; }
