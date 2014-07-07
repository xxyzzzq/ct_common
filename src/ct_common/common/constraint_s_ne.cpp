//===----- ct_common/common/constraint_s_ne.cpp -----------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Constraint_S_NE
//
//===----------------------------------------------------------------------===//

#include <cstring>
#include <ct_common/common/constraint_s_ne.h>

using namespace ct::common;

Constraint_S_NE::Constraint_S_NE(void)
  : Constraint_S_Binary() {
}

Constraint_S_NE::Constraint_S_NE(const Constraint_S_NE &from)
  : Constraint_S_Binary(from) {
}

Constraint_S_NE &Constraint_S_NE::operator = (
    const Constraint_S_NE &right) {
  Constraint_S_Binary::operator=(right);
  return *this;
}

Constraint_S_NE::~Constraint_S_NE(void) {
}

std::string Constraint_S_NE::get_class_name(void) const {
  return Constraint_S_NE::class_name();
}

std::string Constraint_S_NE::class_name(void) {
  return "Constraint_S_NE";
}

bool Constraint_S_NE::evaluate_func(const std::string &val_1, const std::string &val_2) const {
  return val_1 !=  val_2;
}

std::string Constraint_S_NE::get_op_token(void) const {
  return "!=";
}
