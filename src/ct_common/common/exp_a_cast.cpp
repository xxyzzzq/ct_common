// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/exp_a_cast.h"

#include "ct_common/base/class_name_utils.h"

namespace ct_common {

REGISTER_CLASS_NAME(Exp_A_Cast)

Exp_A_Cast::Exp_A_Cast() = default;

Exp_A_Cast::~Exp_A_Cast() = default;

optional<double> Exp_A_Cast::evaluate_double(
    const optional<double>& val) const {
  return val;
}

optional<int> Exp_A_Cast::evaluate_int(
    const optional<int>& val) const {
  return val;
}

std::string Exp_A_Cast::get_op_token() const {
  switch (type_) {
    case EAT_INT:
      return "int";
      break;
    case EAT_DOUBLE:
      return "double";
      break;
    default:
      CT_EXCEPTION("unknown cast type");
      break;
  }
  return "";
}

void Exp_A_Cast::dump(
    std::ostream& os,
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs) const {
  os << get_op_token();
  os << "(";
  get_oprd()->dump(os, param_specs);
  os << ")";
}

}  // namespace ct_common
