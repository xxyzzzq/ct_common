//===----- ct_common/common/constraint_a.cpp --------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Constraint_A
//
//===----------------------------------------------------------------------===//

#include <ct_common/common/constraint_a.h>

using namespace ct::common;

Constraint_A::Constraint_A(void)
  : Constraint() {
}

Constraint_A::Constraint_A(const Constraint_A &from)
  : Constraint(from) {
}

Constraint_A &Constraint_A::operator = (const Constraint_A &right) {
  Constraint::operator=(right);
  return *this;
}

Constraint_A::~Constraint_A(void) {
}

std::string Constraint_A::get_class_name(void) const {
  return Constraint_A::class_name();
}

std::string Constraint_A::class_name(void) {
  return "Constraint_A";
}
