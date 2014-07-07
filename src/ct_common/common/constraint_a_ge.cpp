//===----- ct_common/common/constraint_a_ge.cpp -----------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Constraint_A_GE
//
//===----------------------------------------------------------------------===//

#include <ct_common/common/constraint_a_ge.h>
#include <ct_common/common/arithmetic_utils.h>

using namespace ct::common;

Constraint_A_GE::Constraint_A_GE(void)
  : Constraint_A_Binary() {
}

Constraint_A_GE::Constraint_A_GE(const Constraint_A_GE &from)
  : Constraint_A_Binary(from) {
}

Constraint_A_GE &Constraint_A_GE::operator = (
    const Constraint_A_GE &right) {
  Constraint_A_Binary::operator=(right);
  return *this;
}

Constraint_A_GE::~Constraint_A_GE(void) {
}

std::string Constraint_A_GE::get_class_name(void) const {
  return Constraint_A_GE::class_name();
}

std::string Constraint_A_GE::class_name(void) {
  return "Constraint_A_GE";
}

bool Constraint_A_GE::evaluate_func_int(int loprd_val, int roprd_val) const {
  return ct::common::utils::cmp_ge(loprd_val, roprd_val, this->precision_);
}

bool Constraint_A_GE::evaluate_func_double(double loprd_val, double roprd_val) const {
  return ct::common::utils::cmp_ge(loprd_val, roprd_val, this->precision_);
}

std::string Constraint_A_GE::get_op_token(void) const {
  return ">=";
}
