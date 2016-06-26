//===----- ct_common/common/constraint_a_le.cpp -----------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Constraint_A_LE
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/constraint_a_le.h"

#include "ct_common/base/arithmetic_utils.h"

using namespace ct::common;

Constraint_A_LE::Constraint_A_LE(void)
  : Constraint_A_Binary() {
}

Constraint_A_LE::Constraint_A_LE(const Constraint_A_LE &from)
  : Constraint_A_Binary(from) {
}

Constraint_A_LE &Constraint_A_LE::operator = (
    const Constraint_A_LE &right) {
  Constraint_A_Binary::operator=(right);
  return *this;
}

Constraint_A_LE::~Constraint_A_LE(void) {
}

std::string Constraint_A_LE::get_class_name(void) const {
  return Constraint_A_LE::class_name();
}

std::string Constraint_A_LE::class_name(void) {
  return "Constraint_A_LE";
}

bool Constraint_A_LE::evaluate_func_int(int loprd_val, int roprd_val) const {
  return ct::common::utils::cmp_le(loprd_val, roprd_val, this->precision_);
}

bool Constraint_A_LE::evaluate_func_double(double loprd_val, double roprd_val) const {
  return ct::common::utils::cmp_le(loprd_val, roprd_val, this->precision_);
}

std::string Constraint_A_LE::get_op_token(void) const {
  return "<=";
}
