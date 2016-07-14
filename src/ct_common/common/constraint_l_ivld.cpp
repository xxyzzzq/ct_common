// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/constraint_l_ivld.h"

#include "ct_common/base/class_name_utils.h"

#include "ct_common/common/exp_a.h"
#include "ct_common/common/exp_s.h"

namespace ct_common {

REGISTER_CLASS_NAME(Constraint_L_IVLD)

Constraint_L_IVLD::Constraint_L_IVLD()
    : Constraint_L_Atomic(), pid_(PID_BOUND) {}

Constraint_L_IVLD::~Constraint_L_IVLD() = default;

optional<bool> Constraint_L_IVLD::Evaluate(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  if (!assignment.IsContainParam(pid_)) {
    CT_EXCEPTION("parameter not found in the test case");
    return nullopt;
  }
  if (param_specs[pid_]->is_auto()) {
    CT_EXCEPTION("Error: auto value cannot be invalidated");
    return nullopt;
  }
  return param_specs[pid_]->IsVidInvalid(
      assignment.GetValue(pid_));
}

void Constraint_L_IVLD::InnerTouchLeafPids(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    std::set<std::size_t>* pids_to_touch) const {
  // auto and aux parameters cannot be invalidated, so no need to check
  pids_to_touch->insert(pid_);
}

void Constraint_L_IVLD::Dump(
    std::ostream& os,
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs) const {
  os << "#";
  os << "(";
  os << param_specs[pid_]->get_param_name();
  os << ")";
}

}  // namespace ct_common
