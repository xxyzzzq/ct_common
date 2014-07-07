//===----- ct_common/common/exp_a_sub.cpp -----------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Exp_A_Sub
//
//===----------------------------------------------------------------------===//

#include <ct_common/common/exp_a_sub.h>

using namespace ct::common;

Exp_A_Sub::Exp_A_Sub(void)
  : Exp_A_Binary() {
}

Exp_A_Sub::Exp_A_Sub(const Exp_A_Sub &from)
  : Exp_A_Binary(from) {
}

Exp_A_Sub& Exp_A_Sub::operator = (const Exp_A_Sub &right) {
  Exp_A_Binary::operator=(right);
  return *this;
}

Exp_A_Sub::~Exp_A_Sub(void) {
}

std::string Exp_A_Sub::get_class_name(void) const {
  return Exp_A_Sub::class_name();
}

std::string Exp_A_Sub::class_name(void) {
  return "Exp_A_Sub";
}

int Exp_A_Sub::evaluate_int(int val_1, int val_2) const {
  return val_1 - val_2;
}

double Exp_A_Sub::evaluate_double(double val_1, double val_2) const {
  return val_1 - val_2;
}

std::string Exp_A_Sub::get_op_token(void) const {
  return "-";
}
