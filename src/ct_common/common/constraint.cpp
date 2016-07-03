// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/constraint.h"

#include "ct_common/base/class_name_utils.h"

namespace ct_common {

REGISTER_CLASS_NAME(Constraint)

Constraint::Constraint() = default;

Constraint::~Constraint() = default;

optional<bool> Constraint::Evaluate(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  // never called
  return nullopt;
}

}  // namespace ct_common
