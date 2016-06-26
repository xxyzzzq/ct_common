//===----- ct_common/common/constraint_l_binary.cpp -------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Constraint_L_Binary
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/constraint_l_binary.h"

#include "ct_common/base/arithmetic_utils.h"

using namespace ct::common;

Constraint_L_Binary::Constraint_L_Binary(void) : Constraint_L() {
  this->oprds_.resize(2);
}

Constraint_L_Binary::Constraint_L_Binary(const Constraint_L_Binary &from)
    : Constraint_L(from) {}

Constraint_L_Binary &Constraint_L_Binary::operator=(
    const Constraint_L_Binary &right) {
  Constraint_L::operator=(right);
  return *this;
}

Constraint_L_Binary::~Constraint_L_Binary(void) {}

std::string Constraint_L_Binary::get_class_name(void) const {
  return Constraint_L_Binary::class_name();
}

std::string Constraint_L_Binary::class_name(void) {
  return "Constraint_L_Binary";
}

EvalType_Bool Constraint_L_Binary::Evaluate(
    const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
    const Assignment &assignment) const {
  EvalType_Bool l_val, r_val;
  l_val = this->get_loprd()->Evaluate(param_specs, assignment);
  r_val = this->get_roprd()->Evaluate(param_specs, assignment);
  return this->evaluate_func(l_val, r_val);
}

void Constraint_L_Binary::dump(
    std::ostream &os,
    const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const {
  os << "(";
  this->get_loprd()->dump(os, param_specs);
  os << this->get_op_token();
  this->get_roprd()->dump(os, param_specs);
  os << ")";
}
