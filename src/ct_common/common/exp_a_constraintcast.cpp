//===----- ct_common/common/exp_a_constraintcast.cpp ------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Exp_A_ConstraintCast
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/exp_a_constraintcast.h"

using namespace ct::common;

Exp_A_ConstraintCast::Exp_A_ConstraintCast(void) : Exp_A_Atom() {
  oprds_.resize(1);
}

Exp_A_ConstraintCast::Exp_A_ConstraintCast(const Exp_A_ConstraintCast &from)
    : Exp_A_Atom(from) {}

Exp_A_ConstraintCast &Exp_A_ConstraintCast::operator=(
    const Exp_A_ConstraintCast &right) {
  Exp_A_Atom::operator=(right);
  return *this;
}

Exp_A_ConstraintCast::~Exp_A_ConstraintCast(void) {}

std::string Exp_A_ConstraintCast::get_class_name(void) const {
  return Exp_A_ConstraintCast::class_name();
}

std::string Exp_A_ConstraintCast::class_name(void) {
  return "Exp_A_ConstraintCast";
}

EvalType_Double Exp_A_ConstraintCast::EvaluateDouble_Impl(
    const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
    const Assignment &assignment) const {
  EvalType_Bool val = this->get_oprd()->Evaluate(param_specs, assignment);
  return EvalType_Double(val.value_ ? 1.0 : 0.0, val.is_valid_);
}

EvalType_Int Exp_A_ConstraintCast::EvaluateInt_Impl(
    const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
    const Assignment &assignment) const {
  EvalType_Bool val = this->get_oprd()->Evaluate(param_specs, assignment);
  return EvalType_Int(val.value_ ? 1 : 0, val.is_valid_);
}

void Exp_A_ConstraintCast::dump(
    std::ostream &os,
    const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const {
  switch (this->type_) {
    case EAT_INT:
      os << "int";
      break;
    case EAT_DOUBLE:
      os << "double";
      break;
    default:
      CT_EXCEPTION("unknown cast type");
      break;
  }
  this->get_oprd()->dump(os, param_specs);
}
