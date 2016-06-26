//===----- ct_common/common/constraint_a_gt.cpp -----------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Constraint_A_GT
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/constraint_a_gt.h"

#include "ct_common/base/arithmetic_utils.h"

using namespace ct::common;

Constraint_A_GT::Constraint_A_GT(void)
  : Constraint_A_Binary() {
}

Constraint_A_GT::Constraint_A_GT(const Constraint_A_GT &from)
  : Constraint_A_Binary(from) {
}

Constraint_A_GT &Constraint_A_GT::operator = (
    const Constraint_A_GT &right) {
  Constraint_A_Binary::operator=(right);
  return *this;
}

Constraint_A_GT::~Constraint_A_GT(void) {
}

std::string Constraint_A_GT::get_class_name(void) const {
  return Constraint_A_GT::class_name();
}

std::string Constraint_A_GT::class_name(void) {
  return "Constraint_A_GT";
}

bool Constraint_A_GT::evaluate_func_int(int loprd_val, int roprd_val) const {
  return ct::common::utils::cmp_gt(loprd_val, roprd_val, this->precision_);
}

bool Constraint_A_GT::evaluate_func_double(double loprd_val, double roprd_val) const {
  return ct::common::utils::cmp_gt(loprd_val, roprd_val, this->precision_);
}

std::string Constraint_A_GT::get_op_token(void) const {
  return ">";
}
