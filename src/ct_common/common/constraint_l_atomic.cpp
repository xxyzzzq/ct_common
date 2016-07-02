//===----- ct_common/common/constraint_l_atom.cpp ---------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Constraint_L_Atom
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/constraint_l_atom.h"

using namespace ct::common;

Constraint_L_Atom::Constraint_L_Atom(void) : Constraint_L() {}

Constraint_L_Atom::Constraint_L_Atom(const Constraint_L_Atom &from)
    : Constraint_L(from) {}

Constraint_L_Atom::~Constraint_L_Atom(void) {}

Constraint_L_Atom &Constraint_L_Atom::operator=(
    const Constraint_L_Atom &right) {
  Constraint_L::operator=(right);
  return *this;
}

std::string Constraint_L_Atom::get_class_name(void) const {
  return Constraint_L_Atom::class_name();
}

std::string Constraint_L_Atom::class_name(void) { return "Constraint_L_Atom"; }
