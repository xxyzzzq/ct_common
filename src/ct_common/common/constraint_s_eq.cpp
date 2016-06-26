//===----- ct_common/common/constraint_s_eq.cpp -----------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Constraint_S_EQ
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/constraint_s_eq.h"

using namespace ct::common;

Constraint_S_EQ::Constraint_S_EQ(void)
  : Constraint_S_Binary() {
}

Constraint_S_EQ::Constraint_S_EQ(const Constraint_S_EQ &from)
  : Constraint_S_Binary(from) {
}

Constraint_S_EQ &Constraint_S_EQ::operator = (
    const Constraint_S_EQ &right) {
  Constraint_S_Binary::operator=(right);
  return *this;
}

Constraint_S_EQ::~Constraint_S_EQ(void) {
}

std::string Constraint_S_EQ::get_class_name(void) const {
  return Constraint_S_EQ::class_name();
}

std::string Constraint_S_EQ::class_name(void) {
  return "Constraint_S_EQ";
}

bool Constraint_S_EQ::evaluate_func(const std::string &val_1, const std::string &val_2) const {
  return val_1 ==  val_2;
}

std::string Constraint_S_EQ::get_op_token(void) const {
  return "==";
}
