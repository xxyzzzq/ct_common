//===----- ct_common/common/constraint_s_binary.cpp -------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Constraint_S_Binary
//
//===----------------------------------------------------------------------===//

#include <ct_common/common/constraint_s_binary.h>
#include <ct_common/common/arithmetic_utils.h>
#include <ct_common/common/eval_type_string.h>

using namespace ct::common;

Constraint_S_Binary::Constraint_S_Binary(void)
    : Constraint_S() {
  this->oprds_.resize(2);
}

Constraint_S_Binary::Constraint_S_Binary(const Constraint_S_Binary &from)
  : Constraint_S(from) {
}

Constraint_S_Binary &Constraint_S_Binary::operator = (
    const Constraint_S_Binary &right) {
  Constraint_S::operator=(right);
  return *this;
}

Constraint_S_Binary::~Constraint_S_Binary(void) {
}

std::string Constraint_S_Binary::get_class_name(void) const {
  return Constraint_S_Binary::class_name();
}

std::string Constraint_S_Binary::class_name(void) {
  return "Constraint_S_Binary";
}

EvalType_Bool Constraint_S_Binary::Evaluate( const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                                const Assignment &assignment) const {
  EvalType_Bool tmp_return;
  EvalType_String val_l = this->get_loprd()->Evaluate(param_specs, assignment);
  EvalType_String val_r = this->get_roprd()->Evaluate(param_specs, assignment);
  tmp_return.is_valid_ = val_l.is_valid_ && val_r.is_valid_;
  if (tmp_return.is_valid_) {
    tmp_return.value_ = this->evaluate_func(val_l.value_, val_r.value_);
  }
  return tmp_return;
}

void Constraint_S_Binary::dump(std::ostream &os, const std::vector<boost::shared_ptr<ParamSpec> > &param_specs) const {
  os << "(";
  this->get_loprd()->dump(os, param_specs);
  os << this->get_op_token();
  this->get_roprd()->dump(os, param_specs);
  os << ")";
}
