//===----- ct_common/common/constraint_a_binary.cpp -------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Constraint_A_Binary
//
//===----------------------------------------------------------------------===//

#include <ct_common/common/constraint_a_binary.h>
#include <ct_common/common/arithmetic_utils.h>

using namespace ct::common;

Constraint_A_Binary::Constraint_A_Binary(void)
    : Constraint_A(), precision_(0) {
  this->oprds_.resize(2);
}

Constraint_A_Binary::Constraint_A_Binary(const Constraint_A_Binary &from)
    : Constraint_A(from), precision_(from.precision_) {
}

Constraint_A_Binary &Constraint_A_Binary::operator = (
    const Constraint_A_Binary &right) {
  Constraint_A::operator=(right);
  this->precision_ = right.precision_;
  return *this;
}

Constraint_A_Binary::~Constraint_A_Binary(void) {
}

std::string Constraint_A_Binary::get_class_name(void) const {
  return Constraint_A_Binary::class_name();
}

std::string Constraint_A_Binary::class_name(void) {
  return "Constraint_A_Binary";
}

EvalType_Bool Constraint_A_Binary::Evaluate( const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                                const Assignment &assignment) const {
  EvalType_Bool tmp_return;
  if (this->get_loprd()->get_type() == EAT_INT &&
      this->get_roprd()->get_type() == EAT_INT) {
    GET_EXP_VAL(EvalType_Int, loprd_val, this->get_loprd(), param_specs, assignment);
    GET_EXP_VAL(EvalType_Int, roprd_val, this->get_roprd(), param_specs, assignment);
    tmp_return.is_valid_ = loprd_val.is_valid_ && roprd_val.is_valid_;
    if (tmp_return.is_valid_) {
      tmp_return.value_ = this->evaluate_func_int(loprd_val.value_, roprd_val.value_);
    }
  } else {
    GET_EXP_VAL(EvalType_Int, loprd_val, this->get_loprd(), param_specs, assignment);
    GET_EXP_VAL(EvalType_Int, roprd_val, this->get_roprd(), param_specs, assignment);
    tmp_return.is_valid_ = loprd_val.is_valid_ && roprd_val.is_valid_;
    if (tmp_return.is_valid_) {
      tmp_return.value_ = this->evaluate_func_int(loprd_val.value_, roprd_val.value_);
    }
  }
  return tmp_return;
}

void Constraint_A_Binary::dump(std::ostream &os, const std::vector<boost::shared_ptr<ParamSpec> > &param_specs) const {
  os << "(";
  this->get_loprd()->dump(os, param_specs);
  os << this->get_op_token();
  this->get_roprd()->dump(os, param_specs);
  os << ")";
}
