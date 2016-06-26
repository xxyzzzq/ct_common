//===----- ct_common/common/constraint_s.cpp --------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Constraint_S
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/constraint_s.h"

using namespace ct::common;

Constraint_S::Constraint_S(void) : Constraint() {}

Constraint_S::Constraint_S(const Constraint_S &from) : Constraint(from) {}

Constraint_S &Constraint_S::operator=(const Constraint_S &right) {
  Constraint::operator=(right);
  return *this;
}

Constraint_S::~Constraint_S(void) {}

std::string Constraint_S::get_class_name(void) const {
  return Constraint_S::class_name();
}

std::string Constraint_S::class_name(void) { return "Constraint_S"; }
