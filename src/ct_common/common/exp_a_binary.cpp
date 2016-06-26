//===----- ct_common/common/exp_a_binary.cpp --------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Exp_A_Binary
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/exp_a_binary.h"

#include "ct_common/base/arithmetic_utils.h"

using namespace ct::common;

Exp_A_Binary::Exp_A_Binary(void)
    : Exp_A() {
  this->oprds_.resize(2);
}

Exp_A_Binary::Exp_A_Binary(const Exp_A_Binary &from)
  : Exp_A(from) {
}

Exp_A_Binary &Exp_A_Binary::operator = (const Exp_A_Binary &right) {
  Exp_A::operator=(right);
  return *this;
}

Exp_A_Binary::~Exp_A_Binary(void) {
}

std::string Exp_A_Binary::get_class_name(void) const {
  return Exp_A_Binary::class_name();
}

std::string Exp_A_Binary::class_name(void) {
  return "Exp_A_Binary";
}

EvalType_Double Exp_A_Binary::EvaluateDouble_Impl(const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
                                      const Assignment &assignment) const {
  EvalType_Double tmp_return;
  if (this->get_loprd()->get_type() == EAT_INT &&
      this->get_roprd()->get_type() == EAT_INT) {
    GET_EXP_VAL(EvalType_Int, val_l, this->get_loprd(), param_specs, assignment);
    GET_EXP_VAL(EvalType_Int, val_r, this->get_roprd(), param_specs, assignment);
    tmp_return.is_valid_ = val_l.is_valid_ && val_r.is_valid_;
    if (tmp_return.is_valid_) {
      tmp_return.value_ = this->evaluate_int(val_l.value_, val_r.value_);
    }
  } else if (this->get_loprd()->get_type() == EAT_DOUBLE ||
      this->get_roprd()->get_type() == EAT_DOUBLE) {
    GET_EXP_VAL(EvalType_Double, val_l, this->get_loprd(), param_specs, assignment);
    GET_EXP_VAL(EvalType_Double, val_r, this->get_roprd(), param_specs, assignment);
    tmp_return.is_valid_ = val_l.is_valid_ && val_r.is_valid_;
    if (tmp_return.is_valid_) {
      tmp_return.value_ = this->evaluate_double(val_l.value_, val_r.value_);
    }
  } else {
    CT_EXCEPTION("cannot evaluate this expression");
  }
  return tmp_return;
}

EvalType_Int Exp_A_Binary::EvaluateInt_Impl(const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
                                const Assignment &assignment) const {
  EvalType_Int tmp_return;
  if (this->get_loprd()->get_type() == EAT_INT &&
      this->get_roprd()->get_type() == EAT_INT) {
    GET_EXP_VAL(EvalType_Int, val_l, this->get_loprd(), param_specs, assignment);
    GET_EXP_VAL(EvalType_Int, val_r, this->get_roprd(), param_specs, assignment);
    tmp_return.is_valid_ = val_l.is_valid_ && val_r.is_valid_;
    if (tmp_return.is_valid_) {
      tmp_return.value_ = this->evaluate_int(val_l.value_, val_r.value_);
    }
  } else if (this->get_loprd()->get_type() == EAT_DOUBLE ||
      this->get_roprd()->get_type() == EAT_DOUBLE) {
    GET_EXP_VAL(EvalType_Double, val_l, this->get_loprd(), param_specs, assignment);
    GET_EXP_VAL(EvalType_Double, val_r, this->get_roprd(), param_specs, assignment);
    tmp_return.is_valid_ = val_l.is_valid_ && val_r.is_valid_;
    if (tmp_return.is_valid_) {
      tmp_return.value_ = (int)this->evaluate_double(val_l.value_, val_r.value_);
    }
  } else {
    CT_EXCEPTION("cannot evaluate this expression");
  }
  return tmp_return;
}

void Exp_A_Binary::dump(std::ostream &os, const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const {
  os << "(";
  this->get_loprd()->dump(os, param_specs);
  os << this->get_op_token();
  this->get_roprd()->dump(os, param_specs);
  os << ")";
}
