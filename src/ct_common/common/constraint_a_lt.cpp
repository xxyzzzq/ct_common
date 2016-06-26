//===----- ct_common/common/constraint_a_lt.cpp -----------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Constraint_A_LT
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/constraint_a_lt.h"

#include "ct_common/base/arithmetic_utils.h"

using namespace ct::common;

Constraint_A_LT::Constraint_A_LT(void) : Constraint_A_Binary() {}

Constraint_A_LT::Constraint_A_LT(const Constraint_A_LT &from)
    : Constraint_A_Binary(from) {}

Constraint_A_LT &Constraint_A_LT::operator=(const Constraint_A_LT &right) {
  Constraint_A_Binary::operator=(right);
  return *this;
}

Constraint_A_LT::~Constraint_A_LT(void) {}

std::string Constraint_A_LT::get_class_name(void) const {
  return Constraint_A_LT::class_name();
}

std::string Constraint_A_LT::class_name(void) { return "Constraint_A_LT"; }

bool Constraint_A_LT::evaluate_func_int(int loprd_val, int roprd_val) const {
  return ct::common::utils::cmp_lt(loprd_val, roprd_val, this->precision_);
}

bool Constraint_A_LT::evaluate_func_double(double loprd_val,
                                           double roprd_val) const {
  return ct::common::utils::cmp_lt(loprd_val, roprd_val, this->precision_);
}

std::string Constraint_A_LT::get_op_token(void) const { return "<"; }
