//===----- ct_common/common/constraint_l_cbool.cpp -------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Constraint_L_CBool
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/constraint_l_cbool.h"

using namespace ct::common;

Constraint_L_CBool::Constraint_L_CBool(void)
    : Constraint_L_Atom(), value_(false) {}

Constraint_L_CBool::Constraint_L_CBool(const Constraint_L_CBool &from)
    : Constraint_L_Atom(from), value_(from.value_) {}

Constraint_L_CBool::~Constraint_L_CBool(void) {}

Constraint_L_CBool &Constraint_L_CBool::operator=(
    const Constraint_L_CBool &right) {
  Constraint_L_Atom::operator=(right);
  this->value_ = right.value_;
  return *this;
}

std::string Constraint_L_CBool::get_class_name(void) const {
  return Constraint_L_CBool::class_name();
}

std::string Constraint_L_CBool::class_name(void) {
  return "Constraint_L_CBool";
}

const std::string &Constraint_L_CBool::get_str_value(void) const {
  static std::string str_true = "true";
  static std::string str_false = "false";
  if (this->value_) {
    return str_true;
  }
  return str_false;
}

EvalType_Bool Constraint_L_CBool::Evaluate(
    const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
    const Assignment &assignment) const {
  return EvalType_Bool(this->value_, true);
}

void Constraint_L_CBool::dump(
    std::ostream &os,
    const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const {
  os << this->get_str_value();
}
