// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/constraint_l_param.h"

#include "ct_common/common/paramspec_bool.h"

namespace ct_common {

REGISTER_CLASS_NAME(Constraint_L_Param)

Constraint_L_Param::Constraint_L_Param()
    : Constraint_L_Atomic(), pid_(PID_BOUND) {}

Constraint_L_Param::~Constraint_L_Param() = default;

optional<bool> Constraint_L_Param::Evaluate(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  std::shared_ptr<ParamSpec_Bool> ptr =
      std::dynamic_pointer_cast<ParamSpec_Bool>(param_specs[pid_]);
  if (!ptr.get()) {
    CT_EXCEPTION(
        "Error: evaluating a boolean value from a non-boolean parameter!");
    return nullopt;
  }
  // FIXME: need to reconsider the logic here
  if (ptr->is_auto()) {
    for (std::size_t i = 0; i < ptr->get_auto_value_specs().size(); ++i) {
      std::shared_ptr<Constraint> cond = std::dynamic_pointer_cast<Constraint>(
          ptr->auto_value_specs()[i].first);
      if (cond) {
        optional<bool> cond_value;
        cond_value = cond->Evaluate(param_specs, assignment);
        if (cond_value && cond_value.value()) {
          // condition met, taking the value
          std::shared_ptr<Constraint> val_exp =
              std::dynamic_pointer_cast<Constraint>(
                  ptr->auto_value_specs()[i].second);
          if (val_exp) {
            return val_exp->Evaluate(param_specs, assignment);
          } else {
            CT_EXCEPTION("Error: encountering invalid auto value expression");
            return nullopt;
          }
        }
      } else {
        CT_EXCEPTION("Error: encountering invalid auto value condition");
        return nullopt;
      }
    }
    // FIXME: suppressing error
    // CT_EXCEPTION(std::string("Error: encountering unhandled auto value
    // condition for parameter ")+ptr->get_param_name());
    return nullopt;  // no conditions match
  }
  std::size_t vid = assignment.GetValue(pid_);
  if (!ptr->IsVidInvalid(vid)) {
    return ptr->get_bool_values()[vid];
  }
  return nullopt;
}

void Constraint_L_Param::inner_touch_leaf_pids(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    std::set<std::size_t>* pids_to_touch) const {
  if (!param_specs[pid_]) {
    CT_EXCEPTION("encountered invalid parameter spec");
    return;
  }
  if (param_specs[pid_]->is_auto()) {
    param_specs[pid_]->TouchPids(param_specs, pids_to_touch);
  } else {
    pids_to_touch->insert(pid_);
  }
}

void Constraint_L_Param::dump(
    std::ostream& os,
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs) const {
  os << param_specs[pid_]->get_param_name();
}

}  // namespace ct_common
