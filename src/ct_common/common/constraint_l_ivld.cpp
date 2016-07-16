// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/constraint_l_ivld.h"

#include "ct_common/base/class_name_utils.h"
#include "ct_common/common/exp_a.h"
#include "ct_common/common/exp_s.h"

namespace ct_common {

namespace {

bool IsTreeNodeValid(
    const std::vector<std::shared_ptr<ParamSpec> > & param_specs,
    const Assignment& assignment,
    const std::shared_ptr<TreeNode>& node) {
  if (std::dynamic_pointer_cast<Constraint>(node)) {
    std::shared_ptr<Constraint> c_node =
        std::dynamic_pointer_cast<Constraint>(node);
    return static_cast<bool>(c_node->Evaluate(param_specs, assignment));
  } else if (std::dynamic_pointer_cast<Exp_A>(node).get()) {
    std::shared_ptr<Exp_A> c_node = std::dynamic_pointer_cast<Exp_A>(node);
    if (c_node->get_type() == EAT_INT) {
      return static_cast<bool>(c_node->EvaluateInt(param_specs, assignment));
    } else if (c_node->get_type() == EAT_DOUBLE) {
      return static_cast<bool>(c_node->EvaluateDouble(param_specs, assignment));
    } else {
      CT_EXCEPTION("unrecognized arithmetic expression type");
    }
  } else if (std::dynamic_pointer_cast<Exp_S>(node)) {
    std::shared_ptr<Exp_S> c_node = std::dynamic_pointer_cast<Exp_S>(node);
    return static_cast<bool>(c_node->Evaluate(param_specs, assignment));
  } else {
    CT_EXCEPTION("unknown expression type");
  }
  return false;
}

}  // anonymous namespace

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
    for (const auto& auto_value_spec
             : param_specs[this->pid_]->auto_value_specs()) {
      std::shared_ptr<Constraint> cond =
          std::dynamic_pointer_cast<Constraint>(auto_value_spec.first);
      if (cond) {
        optional<bool> cond_value = cond->Evaluate(param_specs, assignment);
        if (cond_value && cond_value.value()) {
          // condition met, taking the value
          if (IsTreeNodeValid(
                  param_specs, assignment, auto_value_spec.second)) {
            return false;
          }
          return true;
        }
      } else {
        CT_EXCEPTION("Error: encountering invalid auto value condition");
        return nullopt;
      }
    }
    // FIXME: suppressing error
    // CT_EXCEPTION(std::string(
    //     "Error: encountering unhandled auto value condition for parameter ")+
    //     ptr->get_param_name());
    return true;  // no conditions match
  }
  return param_specs[pid_]->IsVidInvalid(assignment.GetValue(pid_));
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
