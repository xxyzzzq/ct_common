//===----- ct_common/common/constraint_l_param.cpp --------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Constraint_L_Param
//
//===----------------------------------------------------------------------===//

#include <ct_common/common/constraint_l_param.h>
#include <ct_common/common/paramspec_bool.h>

using namespace ct::common;

Constraint_L_Param::Constraint_L_Param(void)
    : Constraint_L_Atom(), pid_(PID_BOUND) {
}

Constraint_L_Param::Constraint_L_Param(const Constraint_L_Param &from)
    : Constraint_L_Atom(from), pid_(from.pid_) {
}

Constraint_L_Param::~Constraint_L_Param(void) {
}

Constraint_L_Param &Constraint_L_Param::operator = (const Constraint_L_Param &right) {
  Constraint_L_Atom::operator =(right);
  this->pid_ = right.pid_;
  return *this;
}

std::string Constraint_L_Param::get_class_name(void) const {
  return Constraint_L_Param::class_name();
}

std::string Constraint_L_Param::class_name(void) {
  return "Constraint_L_Param";
}

EvalType_Bool Constraint_L_Param::Evaluate(const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                                  const Assignment &assignment) const {
  boost::shared_ptr<ParamSpec_Bool> ptr = boost::dynamic_pointer_cast<ParamSpec_Bool>(param_specs[this->pid_]);
  if (!ptr.get()) {
    CT_EXCEPTION("Error: evaluating a boolean value from a non-boolean parameter!");
    return EvalType_Bool(false, false);
  }
  // FIXME: need to reconsider the logic here
  if (ptr->is_auto()) {
    for (std::size_t i = 0; i < ptr->get_auto_value_specs().size(); ++i) {
      boost::shared_ptr<Constraint> cond = boost::dynamic_pointer_cast<Constraint>(ptr->auto_value_specs()[i].first);
      if (cond) {
        EvalType_Bool cond_value;
        cond_value = cond->Evaluate(param_specs, assignment);
        if (cond_value.is_valid_ && cond_value.value_) {
          // condition met, taking the value
          boost::shared_ptr<Constraint> val_exp = boost::dynamic_pointer_cast<Constraint>(ptr->auto_value_specs()[i].second);
          if (val_exp) {
            return val_exp->Evaluate(param_specs, assignment);
          } else {
            CT_EXCEPTION("Error: encountering invalid auto value expression");
            return EvalType_Bool(false, false);
          }
        }
      } else {
        CT_EXCEPTION("Error: encountering invalid auto value condition");
        return EvalType_Bool(false, false);
      }
    }
    // FIXME: suppressing error
    //CT_EXCEPTION(std::string("Error: encountering unhandled auto value condition for parameter ")+ptr->get_param_name());
    return EvalType_Bool(false, false); // no conditions match
  }
  EvalType_Bool tmp_return;
  std::size_t vid = assignment.GetValue(this->pid_);
  tmp_return.is_valid_ = !ptr->is_vid_invalid(vid);
  if (tmp_return.is_valid_) {
    tmp_return.value_ = ptr->get_bool_values()[vid];
  }
  return tmp_return;
}

void Constraint_L_Param::inner_touch_leaf_pids( const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
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

void Constraint_L_Param::dump(std::ostream &os, const std::vector<boost::shared_ptr<ParamSpec> > &param_specs) const {
  os << param_specs[this->pid_]->get_param_name();
}
