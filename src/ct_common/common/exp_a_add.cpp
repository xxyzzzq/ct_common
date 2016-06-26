//===----- ct_common/common/exp_a_add.cpp -----------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Exp_A_Add
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/exp_a_add.h"

using namespace ct::common;

Exp_A_Add::Exp_A_Add(void) : Exp_A_Binary() {}

Exp_A_Add::Exp_A_Add(const Exp_A_Add &from) : Exp_A_Binary(from) {}

Exp_A_Add &Exp_A_Add::operator=(const Exp_A_Add &right) {
  Exp_A_Binary::operator=(right);
  return *this;
}

Exp_A_Add::~Exp_A_Add(void) {}

std::string Exp_A_Add::get_class_name(void) const {
  return Exp_A_Add::class_name();
}

std::string Exp_A_Add::class_name(void) { return "Exp_A_Add"; }

int Exp_A_Add::evaluate_int(int val_1, int val_2) const {
  return val_1 + val_2;
}

double Exp_A_Add::evaluate_double(double val_1, double val_2) const {
  return val_1 + val_2;
}

std::string Exp_A_Add::get_op_token(void) const { return "+"; }
