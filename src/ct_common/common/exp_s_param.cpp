// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/exp_s_param.h"

#include "ct_common/base/utils.h"
#include "ct_common/base/class_name_utils.h"
#include "ct_common/common/constraint.h"
#include "ct_common/common/paramspec_string.h"

namespace ct_common {

REGISTER_CLASS_NAME(Exp_S_Param)

Exp_S_Param::Exp_S_Param() : Exp_S_Atomic(), pid_(PID_BOUND) {}

Exp_S_Param::~Exp_S_Param() = default;

optional<std::string> Exp_S_Param::Evaluate(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  if (!TYPE_CHECK(param_specs[pid_].get(), ParamSpec_String* )) {
    CT_EXCEPTION("cannot evaluate string value of a non-string parameter");
    return nullopt;
  }
  // FIXME: need to reconsider the logic
  if (param_specs[pid_]->is_auto()) {
    for (std::size_t i = 0;
         i < param_specs[pid_]->get_auto_value_specs().size(); ++i) {
      std::shared_ptr<Constraint> cond = std::dynamic_pointer_cast<Constraint>(
          param_specs[pid_]->auto_value_specs()[i].first);
      if (cond) {
        optional<bool> cond_value = cond->Evaluate(param_specs, assignment);
        if (cond_value && cond_value.value()) {
          // condition met, taking the value
          std::shared_ptr<Exp_S> val_exp = std::dynamic_pointer_cast<Exp_S>(
              param_specs[pid_]->auto_value_specs()[i].second);
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
    // condition for parameter ")+param_specs[pid_]->get_param_name());
    return nullopt;
  }
  std::size_t vid = assignment.GetValue(pid_);
  if (param_specs[pid_]->IsVidInvalid(vid))
    return nullopt;

  return dynamic_cast<ParamSpec_String*>(param_specs[pid_].get())
      ->get_string_values()[vid];
}

void Exp_S_Param::InnerTouchLeafPids(
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

void Exp_S_Param::Dump(
    std::ostream& os,
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs) const {
  os << param_specs[pid_]->get_param_name();
}

}  // namespace ct_common
