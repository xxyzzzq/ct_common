// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/exp_a_param.h"

#include <exception>
#include <type_traits>

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint.h"
#include "ct_common/common/paramspec_double.h"
#include "ct_common/common/paramspec_int.h"

namespace ct_common {

namespace {

template <typename T>
optional<T> EvaluateAutoValue(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment, std::size_t pid) {
  assert(param_specs[pid]->is_auto());

  if (!TYPE_CHECK(param_specs[pid].get(), ParamSpec_Int*) &&
      !TYPE_CHECK(param_specs[pid].get(), ParamSpec_Double*)) {
    CT_EXCEPTION(
        "Evaluating numeric values from non-numeric auto value parameter");
    return nullopt;
  }
  for (std::size_t i = 0;
       i < param_specs[pid]->get_auto_value_specs().size(); ++i) {
    std::shared_ptr<Constraint> cond = std::dynamic_pointer_cast<Constraint>(
        param_specs[pid]->auto_value_specs()[i].first);
    if (cond) {
      optional<bool> cond_value;
      cond_value = cond->Evaluate(param_specs, assignment);
      if (cond_value && cond_value.value()) {
        // condition met, taking the value
        std::shared_ptr<Exp_A> val_exp = std::dynamic_pointer_cast<Exp_A>(
            param_specs[pid]->auto_value_specs()[i].second);
        if (val_exp) {
          if (std::is_same<T, double>::value)
            return cast_optional<T>(val_exp->EvaluateDouble(
                param_specs, assignment));
          else
            return cast_optional<T>(val_exp->EvaluateInt(
                param_specs, assignment));
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

}  // anonymous namespace

REGISTER_CLASS_NAME(Exp_A_Param)

Exp_A_Param::Exp_A_Param() : Exp_A_Atomic(), pid_(PID_BOUND) {}

Exp_A_Param::~Exp_A_Param() = default;

optional<double> Exp_A_Param::EvaluateDouble_Impl(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  // FIXME: need to reconsider the logic
  if (param_specs[pid_]->is_auto()) {
    return EvaluateAutoValue<double>(param_specs, assignment, pid_);
  }
  std::size_t vid = assignment.GetValue(pid_);
  if (param_specs[pid_]->IsVidInvalid(vid))
    return nullopt;

  if (TYPE_CHECK(param_specs[pid_].get(), ParamSpec_Int*)) {
    return dynamic_cast<ParamSpec_Int*>(param_specs[pid_].get())
        ->get_int_values()[vid];
  } else if (TYPE_CHECK(param_specs[pid_].get(), ParamSpec_Double*)) {
    return dynamic_cast<ParamSpec_Double*>(param_specs[pid_].get())
        ->get_double_values()[vid];
  } else {
    CT_EXCEPTION(
        "cannot evaluate numerical value of a non-numerical parameter");
    return nullopt;
  }
}

optional<int> Exp_A_Param::EvaluateInt_Impl(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const Assignment& assignment) const {
  // FIXME: need to reconsider the logic
  if (param_specs[pid_]->is_auto()) {
    return EvaluateAutoValue<int>(param_specs, assignment, pid_);
  }
  std::size_t vid = assignment.GetValue(pid_);
  if (param_specs[pid_]->IsVidInvalid(vid))
    return nullopt;

  if (TYPE_CHECK(param_specs[pid_].get(), ParamSpec_Int*)) {
    return dynamic_cast<ParamSpec_Int*>(param_specs[pid_].get())
        ->get_int_values()[vid];
  } else if (TYPE_CHECK(param_specs[pid_].get(), ParamSpec_Double*)) {
    return static_cast<int>(
            dynamic_cast<ParamSpec_Double*>(param_specs[pid_].get())
            ->get_double_values()[vid]);
  } else {
    CT_EXCEPTION(
        "cannot evaluate numerical value of a non-numerical parameter");
    return nullopt;
  }
}

void Exp_A_Param::InnerTouchLeafPids(
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

void Exp_A_Param::Dump(
    std::ostream& os,
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs) const {
  os << param_specs[pid_]->get_param_name();
}

}  // namespace ct_common
