//===----- ct_common/common/exp_s_param.cpp ---------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Exp_S_Param
//
//===----------------------------------------------------------------------===//

#include <ct_common/common/utils.h>
#include <ct_common/common/exp_s_param.h>
#include <ct_common/common/paramspec_string.h>
#include <ct_common/common/constraint.h>

using namespace ct::common;

Exp_S_Param::Exp_S_Param(void)
    : Exp_S_Atom(), pid_(PID_BOUND) {
}

Exp_S_Param::Exp_S_Param(const Exp_S_Param &from)
    : Exp_S_Atom(from), pid_(from.pid_) {
}

Exp_S_Param &Exp_S_Param::operator = (const Exp_S_Param &right) {
  Exp_S_Atom::operator=(right);
  this->pid_ = right.pid_;
  return *this;
}

Exp_S_Param::~Exp_S_Param(void) {
}

EvalType_String Exp_S_Param::Evaluate(const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
                                  const Assignment &assignment) const {
  EvalType_String tmp_return;
  if (!TYPE_CHECK(param_specs[this->pid_].get(), ParamSpec_String*)) {
    CT_EXCEPTION("cannot evaluate string value of a non-string parameter");
    return tmp_return;
  }
  // FIXME: need to reconsider the logic
  if (param_specs[this->pid_]->is_auto()) {
    for (std::size_t i = 0; i < param_specs[this->pid_]->get_auto_value_specs().size(); ++i) {
      std::shared_ptr<Constraint> cond = std::dynamic_pointer_cast<Constraint>(param_specs[this->pid_]->auto_value_specs()[i].first);
      if (cond) {
        EvalType_Bool cond_value = cond->Evaluate(param_specs, assignment);
        if (cond_value.is_valid_ && cond_value.value_) {
          // condition met, taking the value
          std::shared_ptr<Exp_S> val_exp = std::dynamic_pointer_cast<Exp_S>(param_specs[this->pid_]->auto_value_specs()[i].second);
          if (val_exp) {
            return val_exp->Evaluate(param_specs, assignment);
          } else {
            CT_EXCEPTION("Error: encountering invalid auto value expression");
            return tmp_return;
          }
        }
      } else {
        CT_EXCEPTION("Error: encountering invalid auto value condition");
        return tmp_return;
      }
    }
    // FIXME: suppressing error
    //CT_EXCEPTION(std::string("Error: encountering unhandled auto value condition for parameter ")+param_specs[this->pid_]->get_param_name());
    return tmp_return;
  }
  std::size_t vid = assignment.GetValue(this->pid_);
  tmp_return.is_valid_ = !param_specs[this->pid_]->is_vid_invalid(vid);
  if (tmp_return.is_valid_) {
    tmp_return.value_ = dynamic_cast<ParamSpec_String *>(param_specs[this->pid_].get())
              ->get_string_values()[vid];
  }
  return tmp_return;
}

std::string Exp_S_Param::get_class_name(void) const {
  return Exp_S_Param::class_name();
}

std::string Exp_S_Param::class_name(void) {
  return "Exp_S_Param";
}

void Exp_S_Param::inner_touch_leaf_pids(const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
                                  std::set<std::size_t> &pids_to_touch) const {
  if (!param_specs[this->pid_]) {
    CT_EXCEPTION("encountered invalid parameter spec");
    return;
  }
  if (param_specs[this->pid_]->is_auto()) {
    param_specs[this->pid_]->touch_pids(param_specs, pids_to_touch);
  } else {
    pids_to_touch.insert(this->pid_);
  }
}

void Exp_S_Param::dump(std::ostream &os, const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const {
  os << param_specs[this->pid_]->get_param_name();
}
