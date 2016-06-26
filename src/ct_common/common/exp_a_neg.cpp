//===----- ct_common/common/exp_a_neg.cpp -----------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Exp_A_Neg
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/exp_a_neg.h"

using namespace ct::common;

Exp_A_Neg::Exp_A_Neg(void) : Exp_A_Unary() {}

Exp_A_Neg::Exp_A_Neg(const Exp_A_Neg &from) : Exp_A_Unary(from) {}

Exp_A_Neg &Exp_A_Neg::operator=(const Exp_A_Neg &right) {
  Exp_A_Unary::operator=(right);
  return *this;
}

Exp_A_Neg::~Exp_A_Neg(void) {}

std::string Exp_A_Neg::get_class_name(void) const {
  return Exp_A_Neg::class_name();
}

std::string Exp_A_Neg::class_name(void) { return "Exp_A_Neg"; }

double Exp_A_Neg::evaluate_double(double val) const { return -val; }

int Exp_A_Neg::evaluate_int(int val) const { return -val; }

std::string Exp_A_Neg::get_op_token(void) const { return "-"; }
