//===----- ct_common/common/exp_a_mult.cpp ----------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Exp_A_Mult
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/exp_a_mult.h"

using namespace ct::common;

Exp_A_Mult::Exp_A_Mult(void)
  : Exp_A_Binary() {
}

Exp_A_Mult::Exp_A_Mult(const Exp_A_Mult &from)
  : Exp_A_Binary(from) {
}

Exp_A_Mult& Exp_A_Mult::operator = (const Exp_A_Mult &right) {
  Exp_A_Binary::operator=(right);
  return *this;
}

Exp_A_Mult::~Exp_A_Mult(void) {
}

std::string Exp_A_Mult::get_class_name(void) const {
  return Exp_A_Mult::class_name();
}

std::string Exp_A_Mult::class_name(void) {
  return "Exp_A_Mult";
}

int Exp_A_Mult::evaluate_int(int val_1, int val_2) const {
  return val_1 * val_2;
}

double Exp_A_Mult::evaluate_double(double val_1, double val_2) const {
  return val_1 * val_2;
}

std::string Exp_A_Mult::get_op_token(void) const {
  return "*";
}
