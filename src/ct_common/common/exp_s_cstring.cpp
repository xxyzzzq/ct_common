//===----- ct_common/common/exp_s_cstring.cpp -------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Exp_S_CString
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/exp_s_cstring.h"

using namespace ct::common;

Exp_S_CString::Exp_S_CString(void)
    : Exp_S_Atom(), value_() {
}

Exp_S_CString::Exp_S_CString(const Exp_S_CString &from)
  : Exp_S_Atom(from), value_(from.value_) {
}

Exp_S_CString &Exp_S_CString::operator = (const Exp_S_CString &right) {
  Exp_S_Atom::operator=(right);
  this->value_ = right.value_;
  return *this;
}

Exp_S_CString::~Exp_S_CString(void) {
}

const std::string &Exp_S_CString::get_str_value(void) const {
  return this->value_;
}

EvalType_String Exp_S_CString::Evaluate(const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
                                    const Assignment &assignment) const {
  return EvalType_String(this->value_, true);
}

std::string Exp_S_CString::get_class_name(void) const {
  return Exp_S_CString::class_name();
}

std::string Exp_S_CString::class_name(void) {
  return "Exp_S_CString";
}

void Exp_S_CString::dump(std::ostream &os, const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const {
  os << this->get_str_value();
}
