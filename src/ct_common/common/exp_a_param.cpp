//===----- ct_common/common/exp_a_param.cpp ---------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Exp_A_Param
//
//===----------------------------------------------------------------------===//

#include <exception>
#include <ct_common/common/utils.h>
#include <ct_common/common/exp_a_param.h>
#include <ct_common/common/paramspec_double.h>
#include <ct_common/common/paramspec_int.h>
#include <ct_common/common/constraint.h>

using namespace ct::common;

Exp_A_Param::Exp_A_Param(void)
    : Exp_A_Atom(), pid_(PID_BOUND) {
}

Exp_A_Param::Exp_A_Param(const Exp_A_Param &from)
  : Exp_A_Atom(from), pid_(from.pid_) {
}

Exp_A_Param &Exp_A_Param::operator = (const Exp_A_Param &right) {
  Exp_A_Atom::operator=(right);
  this->pid_ = right.pid_;
  return *this;
}

Exp_A_Param::~Exp_A_Param(void) {
}

EvalType_Double Exp_A_Param::EvaluateDouble_Impl(const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
                                        const Assignment &assignment) const {
  EvalType_Double tmp_return;
  // FIXME: need to reconsider the logic
  if (param_specs[this->pid_]->is_auto()) {
    if (!TYPE_CHECK(param_specs[this->pid_].get(), ParamSpec_Int*) &&
        !TYPE_CHECK(param_specs[this->pid_].get(), ParamSpec_Double*)) {
      CT_EXCEPTION("Evaluating numeric values from non-numeric auto value parameter");
      return tmp_return;
    }
    for (std::size_t i = 0; i < param_specs[this->pid_]->get_auto_value_specs().size(); ++i) {
      std::shared_ptr<Constraint> cond = std::dynamic_pointer_cast<Constraint>(param_specs[this->pid_]->auto_value_specs()[i].first);
      if (cond) {
        EvalType_Bool cond_value;
        cond_value = cond->Evaluate(param_specs, assignment);
        if (cond_value.is_valid_ && cond_value.value_) {
          // condition met, taking the value
          std::shared_ptr<Exp_A> val_exp = std::dynamic_pointer_cast<Exp_A>(param_specs[this->pid_]->auto_value_specs()[i].second);
          if (val_exp) {
            return val_exp->EvaluateDouble(param_specs, assignment);
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
    if (TYPE_CHECK(param_specs[this->pid_].get(), ParamSpec_Int*)) {
      tmp_return.value_ = dynamic_cast<ParamSpec_Int *>(param_specs[this->pid_].get())
                ->get_int_values()[vid];
    } else if (TYPE_CHECK(param_specs[this->pid_].get(), ParamSpec_Double*)) {
      tmp_return.value_ = dynamic_cast<ParamSpec_Double *>(param_specs[this->pid_].get())
                ->get_double_values()[vid];
    } else {
      CT_EXCEPTION("cannot evaluate numerical value of a non-numerical parameter");
      tmp_return.is_valid_ = false;
    }
  }
  return tmp_return;
}

EvalType_Int Exp_A_Param::EvaluateInt_Impl(const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
                                  const Assignment &assignment) const {
  EvalType_Int tmp_return;
  // FIXME: need to reconsider the logic
  if (param_specs[this->pid_]->is_auto()) {
    if (!TYPE_CHECK(param_specs[this->pid_].get(), ParamSpec_Int*) &&
        !TYPE_CHECK(param_specs[this->pid_].get(), ParamSpec_Double*)) {
      CT_EXCEPTION("Evaluating numeric values from non-numeric auto value parameter");
      return tmp_return;
    }
    for (std::size_t i = 0; i < param_specs[this->pid_]->get_auto_value_specs().size(); ++i) {
      std::shared_ptr<Constraint> cond = std::dynamic_pointer_cast<Constraint>(param_specs[this->pid_]->auto_value_specs()[i].first);
      if (cond) {
        EvalType_Bool cond_value;
        cond_value = cond->Evaluate(param_specs, assignment);
        if (cond_value.is_valid_ && cond_value.value_) {
          // condition met, taking the value
          std::shared_ptr<Exp_A> val_exp = std::dynamic_pointer_cast<Exp_A>(param_specs[this->pid_]->auto_value_specs()[i].second);
          if (val_exp) {
            return val_exp->EvaluateInt(param_specs, assignment);
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
    if (TYPE_CHECK(param_specs[this->pid_].get(), ParamSpec_Int*)) {
      tmp_return.value_ = dynamic_cast<ParamSpec_Int *>(param_specs[this->pid_].get())
                ->get_int_values()[vid];
    } else if (TYPE_CHECK(param_specs[this->pid_].get(), ParamSpec_Double*)) {
      tmp_return.value_ = (int)dynamic_cast<ParamSpec_Double *>(param_specs[this->pid_].get())
                ->get_double_values()[vid];
    } else {
      CT_EXCEPTION("cannot evaluate numerical value of a non-numerical parameter");
      tmp_return.is_valid_ = false;
    }
  }
  return tmp_return;
}

std::string Exp_A_Param::get_class_name(void) const {
  return Exp_A_Param::class_name();
}

std::string Exp_A_Param::class_name(void) {
  return "Exp_A_Param";
}

void Exp_A_Param::inner_touch_leaf_pids(const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
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

void Exp_A_Param::dump(std::ostream &os, const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const {
  os << param_specs[this->pid_]->get_param_name();
}
