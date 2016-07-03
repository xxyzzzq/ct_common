// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/exp_a.h"

#include "ct_common/base/class_name_utils.h"

namespace ct_common {

REGISTER_CLASS_NAME(Exp_A)

Exp_A::Exp_A() : Exp(), type_(EAT_INT) {}

Exp_A::~Exp_A() = default;

optional<double> Exp_A::EvaluateDouble(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  if (type_ != EAT_DOUBLE) {
    CT_EXCEPTION("warning: implicit casting non-double to double");
  }
  return EvaluateDouble_Impl(param_specs, assignment);
}

optional<int> Exp_A::EvaluateInt(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  if (type_ != EAT_INT) {
    CT_EXCEPTION("warning: implicit casting non-int to int");
  }
  return EvaluateInt_Impl(param_specs, assignment);
}

}  // namespace ct_common
