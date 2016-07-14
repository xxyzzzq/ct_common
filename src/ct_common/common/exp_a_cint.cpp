// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/exp_a_cint.h"

#include "ct_common/base/class_name_utils.h"

namespace ct_common {

REGISTER_CLASS_NAME(Exp_A_CInt)

Exp_A_CInt::Exp_A_CInt() : Exp_A_Atomic(), value_(0) {}

Exp_A_CInt::~Exp_A_CInt() = default;

void Exp_A_CInt::set_value(int value) { value_ = value; }

void Exp_A_CInt::set_value(double value) {
  value_ = static_cast<int>(value);
}

optional<double> Exp_A_CInt::EvaluateDouble_Impl(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  return value_;
}

optional<int> Exp_A_CInt::EvaluateInt_Impl(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  return value_;
}

void Exp_A_CInt::set_str_value(const std::string& str_value) {
  str_value_ = str_value;
}

const std::string& Exp_A_CInt::get_str_value() const {
  return str_value_;
}

void Exp_A_CInt::Dump(
    std::ostream& os,
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs) const {
  os << get_str_value();
}

}  // namespace ct_common
