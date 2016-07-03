// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/exp_s_cstring.h"

namespace ct_common {

REGISTER_CLASS_NAME(Exp_S_CString)

Exp_S_CString::Exp_S_CString() = default;

Exp_S_CString::~Exp_S_CString() = default;

const std::string& Exp_S_CString::get_str_value() const {
  return value_;
}

optional<std::string> Exp_S_CString::Evaluate(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  return value_;
}

void Exp_S_CString::dump(
    std::ostream& os,
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs) const {
  os << get_str_value();
}

}  // namespace ct_common
