//===----- ct_common/common/exp_a_atom.cpp ----------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Exp_A_Atom
//
//===----------------------------------------------------------------------===//

#include <ct_common/common/exp_a_atom.h>

using namespace ct::common;

Exp_A_Atom::Exp_A_Atom(void)
  : Exp_A() {
}

Exp_A_Atom::Exp_A_Atom(const Exp_A_Atom &from)
  : Exp_A(from) {
}

Exp_A_Atom& Exp_A_Atom::operator = (const Exp_A_Atom &right) {
  Exp_A::operator=(right);
  return *this;
}

Exp_A_Atom::~Exp_A_Atom(void) {
}

std::string Exp_A_Atom::get_class_name(void) const {
  return Exp_A_Atom::class_name();
}

std::string Exp_A_Atom::class_name(void) {
  return "Exp_A_Atom";
}
