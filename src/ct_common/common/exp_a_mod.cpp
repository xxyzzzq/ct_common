//===----- ct_common/common/exp_a_mod.cpp -----------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Exp_A_Mod
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/exp_a_mod.h"

using namespace ct::common;

Exp_A_Mod::Exp_A_Mod(void)
  : Exp_A_Binary() {
}

Exp_A_Mod::Exp_A_Mod(const Exp_A_Mod &from)
  : Exp_A_Binary(from) {
}

Exp_A_Mod& Exp_A_Mod::operator = (const Exp_A_Mod &right) {
  Exp_A_Binary::operator=(right);
  return *this;
}

Exp_A_Mod::~Exp_A_Mod(void) {
}

std::string Exp_A_Mod::get_class_name(void) const {
  return Exp_A_Mod::class_name();
}

std::string Exp_A_Mod::class_name(void) {
  return "Exp_A_Mod";
}

int Exp_A_Mod::evaluate_int(int val_1, int val_2) const {
  if (val_2 == 0) {
    CT_EXCEPTION("can not take the mod of zero");
  }
  return val_1 % val_2;
}

double Exp_A_Mod::evaluate_double(double val_1, double val_2) const {
  CT_EXCEPTION("both the two operands of % must be integer");
  return (int)val_1 % (int)val_2;
}

std::string Exp_A_Mod::get_op_token(void) const {
  return "%";
}
