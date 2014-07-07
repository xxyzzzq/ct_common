//===----- ct_common/common/constraint_a_ne.cpp -----------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Constraint_A_NE
//
//===----------------------------------------------------------------------===//

#include <ct_common/common/constraint_a_ne.h>
#include <ct_common/common/arithmetic_utils.h>

using namespace ct::common;

Constraint_A_NE::Constraint_A_NE(void)
  : Constraint_A_Binary() {
}

Constraint_A_NE::Constraint_A_NE(const Constraint_A_NE &from)
  : Constraint_A_Binary(from) {
}

Constraint_A_NE &Constraint_A_NE::operator = (
    const Constraint_A_NE &right) {
  Constraint_A_Binary::operator=(right);
  return *this;
}

Constraint_A_NE::~Constraint_A_NE(void) {
}

std::string Constraint_A_NE::get_class_name(void) const {
  return Constraint_A_NE::class_name();
}

std::string Constraint_A_NE::class_name(void) {
  return "Constraint_A_NE";
}

bool Constraint_A_NE::evaluate_func_int(int loprd_val, int roprd_val) const {
  return ct::common::utils::cmp_ne(loprd_val, roprd_val, this->precision_);
}

bool Constraint_A_NE::evaluate_func_double(double loprd_val, double roprd_val) const {
  return ct::common::utils::cmp_ne(loprd_val, roprd_val, this->precision_);
}

std::string Constraint_A_NE::get_op_token(void) const {
  return ">=";
}
