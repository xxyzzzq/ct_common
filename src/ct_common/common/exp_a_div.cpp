//===----- ct_common/common/exp_a_div.cpp -----------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Exp_A_Div
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/exp_a_div.h"

#include "ct_common/base/arithmetic_utils.h"

using namespace ct::common;

Exp_A_Div::Exp_A_Div(void)
  : Exp_A_Binary() {
}

Exp_A_Div::Exp_A_Div(const Exp_A_Div &from)
  : Exp_A_Binary(from) {
}

Exp_A_Div& Exp_A_Div::operator = (const Exp_A_Div &right) {
  Exp_A_Binary::operator=(right);
  return *this;
}

Exp_A_Div::~Exp_A_Div(void) {
}

std::string Exp_A_Div::get_class_name(void) const {
  return Exp_A_Div::class_name();
}

std::string Exp_A_Div::class_name(void) {
  return "Exp_A_Div";
}

int Exp_A_Div::evaluate_int(int val_1, int val_2) const {
  if (val_2 == 0) {
    CT_EXCEPTION("dividing by zero is not allowed");
  }
  return val_1 / val_2;
}

double Exp_A_Div::evaluate_double(double val_1, double val_2) const {
  return val_1 / val_2;
}

std::string Exp_A_Div::get_op_token(void) const {
  return "/";
}
