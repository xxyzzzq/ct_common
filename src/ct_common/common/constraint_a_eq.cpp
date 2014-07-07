//===----- ct_common/common/constraint_a_eq.cpp -----------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Constraint_A_EQ
//
//===----------------------------------------------------------------------===//

#include <ct_common/common/constraint_a_eq.h>
#include <ct_common/common/arithmetic_utils.h>

using namespace ct::common;

Constraint_A_EQ::Constraint_A_EQ(void)
  : Constraint_A_Binary() {
}

Constraint_A_EQ::Constraint_A_EQ(const Constraint_A_EQ &from)
  : Constraint_A_Binary(from) {
}

Constraint_A_EQ &Constraint_A_EQ::operator = (
    const Constraint_A_EQ &right) {
  Constraint_A_Binary::operator=(right);
  return *this;
}

Constraint_A_EQ::~Constraint_A_EQ(void) {
}

std::string Constraint_A_EQ::get_class_name(void) const {
  return Constraint_A_EQ::class_name();
}

std::string Constraint_A_EQ::class_name(void) {
  return "Constraint_A_EQ";
}

bool Constraint_A_EQ::evaluate_func_int(int loprd_val, int roprd_val) const {
  return ct::common::utils::cmp_eq(loprd_val, roprd_val, this->precision_);
}

bool Constraint_A_EQ::evaluate_func_double(double loprd_val, double roprd_val) const {
  return ct::common::utils::cmp_eq(loprd_val, roprd_val, this->precision_);
}

std::string Constraint_A_EQ::get_op_token(void) const {
  return "==";
}
