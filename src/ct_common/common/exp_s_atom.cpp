//===----- ct_common/common/exp_s_atom.cpp ----------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Exp_S_Atom
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/exp_s_atom.h"

using namespace ct::common;

Exp_S_Atom::Exp_S_Atom(void) : Exp_S() {}

Exp_S_Atom::Exp_S_Atom(const Exp_S_Atom &from) : Exp_S(from) {}

Exp_S_Atom &Exp_S_Atom::operator=(const Exp_S_Atom &right) {
  Exp_S::operator=(right);
  return *this;
}

Exp_S_Atom::~Exp_S_Atom(void) {}

std::string Exp_S_Atom::get_class_name(void) const {
  return Exp_S_Atom::class_name();
}

std::string Exp_S_Atom::class_name(void) { return "Exp_S_Atom"; }
