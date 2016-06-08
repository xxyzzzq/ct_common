//===----- ct_common/common/exp_a_cint.cpp ----------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Exp_A_CInt
//
//===----------------------------------------------------------------------===//

#include <ct_common/common/exp_a_cint.h>

using namespace ct::common;

Exp_A_CInt::Exp_A_CInt(void)
    : Exp_A_Atom(), value_(0) {
}

Exp_A_CInt::Exp_A_CInt(const Exp_A_CInt &from)
  : Exp_A_Atom(from), value_(from.value_), str_value_(from.str_value_) {
}

Exp_A_CInt &Exp_A_CInt::operator = (const Exp_A_CInt &right) {
  Exp_A_Atom::operator=(right);
  this->value_ = right.value_;
  this->str_value_ = right.str_value_;
  return *this;
}

Exp_A_CInt::~Exp_A_CInt(void) {
}

void Exp_A_CInt::set_value(int value) {
  this->value_ = value;
}

void Exp_A_CInt::set_value(double value) {
  this->value_ = (int)value;
}

EvalType_Double Exp_A_CInt::EvaluateDouble_Impl( const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
                                        const Assignment &assignment) const {
  return EvalType_Double(this->value_, true);
}

EvalType_Int Exp_A_CInt::EvaluateInt_Impl( const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
                                  const Assignment &assignment) const {
  return EvalType_Int(this->value_, true);
}

std::string Exp_A_CInt::get_class_name(void) const {
  return Exp_A_CInt::class_name();
}

std::string Exp_A_CInt::class_name(void) {
  return "Exp_A_CInt";
}

void Exp_A_CInt::set_str_value(const std::string &str_value) {
  this->str_value_ = str_value;
}

const std::string &Exp_A_CInt::get_str_value(void) const {
  return this->str_value_;
}

void Exp_A_CInt::dump(std::ostream &os, const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const {
  os << this->get_str_value();
}
