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

#include <ct_common/common/constraint_l_unary.h>

using namespace ct::common;

Constraint_L_Unary::Constraint_L_Unary(void)
    : Constraint_L() {
  this->oprds_.resize(1);
}

Constraint_L_Unary::Constraint_L_Unary(const Constraint_L_Unary &from)
  : Constraint_L(from) {
}

Constraint_L_Unary &Constraint_L_Unary::operator = (const Constraint_L_Unary &right) {
  Constraint_L::operator=(right);
  return *this;
}

Constraint_L_Unary::~Constraint_L_Unary(void) {
}

std::string Constraint_L_Unary::get_class_name(void) const {
  return Constraint_L_Unary::class_name();
}

std::string Constraint_L_Unary::class_name(void) {
  return "Constraint_L_Unary";
}

EvalType_Bool Constraint_L_Unary::Evaluate(const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
                                  const Assignment &assignment) const {
  EvalType_Bool tmp_return = this->get_oprd()->Evaluate(param_specs, assignment);
  tmp_return.value_ = this->evaluate_func(tmp_return.value_);
  return tmp_return;
}

void Constraint_L_Unary::dump(std::ostream &os, const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const {
  os << this->get_op_token();
  this->get_oprd()->dump(os, param_specs);
}
