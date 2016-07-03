// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/exp_a_cdouble.h"

namespace ct_common {

REGISTER_CLASS_NAME(Exp_A_CDouble)

Exp_A_CDouble::Exp_A_CDouble() : Exp_A_Atomic(), value_(0), str_value_() {}

Exp_A_CDouble::~Exp_A_CDouble() = default;

void Exp_A_CDouble::set_value(int value) { value_ = value; }

void Exp_A_CDouble::set_value(double value) { value_ = value; }

optional<double> Exp_A_CDouble::EvaluateDouble_Impl(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  return value_;
}

optional<int> Exp_A_CDouble::EvaluateInt_Impl(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  return static_cast<int>(value_);
}

void Exp_A_CDouble::set_str_value(const std::string& str_value) {
  str_value_ = str_value;
}

const std::string& Exp_A_CDouble::get_str_value() const {
  return str_value_;
}

void Exp_A_CDouble::dump(
    std::ostream& os,
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs) const {
  os << get_str_value();
}

}  // namespace ct_common
