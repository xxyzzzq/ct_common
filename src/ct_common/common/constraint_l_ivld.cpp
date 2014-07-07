//===----- ct_common/common/constraint_l_ivld.cpp ---------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Constraint_L_IVLD
//
//===----------------------------------------------------------------------===//

#include <ct_common/common/constraint_l_ivld.h>
#include <ct_common/common/exp_a.h>
#include <ct_common/common/exp_s.h>

using namespace ct::common;

Constraint_L_IVLD::Constraint_L_IVLD(void)
    : Constraint_L_Atom(), pid_(PID_BOUND) {
}

Constraint_L_IVLD::Constraint_L_IVLD(const Constraint_L_IVLD &from)
    : Constraint_L_Atom(from), pid_(from.pid_) {
}

Constraint_L_IVLD::~Constraint_L_IVLD(void) {
}

Constraint_L_IVLD &Constraint_L_IVLD::operator = (const Constraint_L_IVLD &right) {
  Constraint_L_Atom::operator =(right);
  this->pid_ = right.pid_;
  return *this;
}

std::string Constraint_L_IVLD::get_class_name(void) const {
  return Constraint_L_IVLD::class_name();
}

std::string Constraint_L_IVLD::class_name(void) {
  return "Constraint_L_IVLD";
}

// ERROR HERE!!!!
EvalType_Bool Constraint_L_IVLD::Evaluate( const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                                const Assignment &assignment) const {
  if (!assignment.IsContainParam(this->pid_)) {
    CT_EXCEPTION("parameter not found in the test case");
    return EvalType_Bool(false, false);
  }
  if (param_specs[this->pid_]->is_auto()) {
    for (std::size_t i = 0; i < param_specs[this->pid_]->auto_value_specs().size(); ++i) {
      boost::shared_ptr<Constraint> cond = boost::dynamic_pointer_cast<Constraint>(param_specs[this->pid_]->auto_value_specs()[i].first);
      if (cond) {
        EvalType_Bool cond_value;
        cond_value = cond->Evaluate(param_specs, assignment);
        if (cond_value.is_valid_ && cond_value.value_) {
          // condition met, taking the value
          boost::shared_ptr<EvalType> result = this->EvaluateAutoCaseExp(param_specs, assignment, param_specs[this->pid_]->auto_value_specs()[i].second);
          if (result->is_valid_) {
            return EvalType_Bool(false, true);
          }
          return EvalType_Bool(true, true);
        }
      } else {
        CT_EXCEPTION("Error: encountering invalid auto value condition");
        return EvalType_Bool(false, false);
      }
    }
    // suppressing error
    //CT_EXCEPTION(std::string("Error: encountering unhandled auto value condition for parameter ")+ptr->get_param_name());
    return EvalType_Bool(true, true); // no conditions match
  }
  return EvalType_Bool(param_specs[this->pid_]->is_vid_invalid(assignment.GetValue(this->pid_)), true);
}


boost::shared_ptr<EvalType> Constraint_L_IVLD::EvaluateAutoCaseExp(
                      const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                      const Assignment &assignment,
                      const boost::shared_ptr<TreeNode> &exp) const {
  if (boost::dynamic_pointer_cast<Constraint>(exp)) {
    boost::shared_ptr<Constraint> c_exp = boost::dynamic_pointer_cast<Constraint>(exp);
    return boost::shared_ptr<EvalType>(new EvalType_Bool(c_exp->Evaluate(param_specs, assignment)));
  } else if (boost::dynamic_pointer_cast<Exp_A>(exp)) {
    boost::shared_ptr<Exp_A> c_exp = boost::dynamic_pointer_cast<Exp_A>(exp);
    if (c_exp->get_type() == EAT_INT) {
      return boost::shared_ptr<EvalType>(new EvalType_Int(c_exp->EvaluateInt(param_specs, assignment)));
    } else if (c_exp->get_type() == EAT_DOUBLE) {
      return boost::shared_ptr<EvalType>(new EvalType_Double(c_exp->EvaluateDouble(param_specs, assignment)));
    } else {
      CT_EXCEPTION("unrecognized arithmetic expression type");
    }
  } else if (boost::dynamic_pointer_cast<Exp_S>(exp)) {
    boost::shared_ptr<Exp_S> c_exp = boost::dynamic_pointer_cast<Exp_S>(exp);
    return boost::shared_ptr<EvalType>(new EvalType_String(c_exp->Evaluate(param_specs, assignment)));
  } else {
    CT_EXCEPTION("unknown expression type");
    return boost::shared_ptr<EvalType>(new EvalType_Bool(false, false));
  }  
}

void Constraint_L_IVLD::inner_touch_leaf_pids(const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                                              std::set<std::size_t> &pids_to_touch) const {
  // auto and aux parameters cannot be invalidated, so no need to check
  pids_to_touch.insert(this->pid_);
}

void Constraint_L_IVLD::dump(std::ostream &os, const std::vector<boost::shared_ptr<ParamSpec> > &param_specs) const {
  os << "#";
  os << "(";
  os << param_specs[this->pid_]->get_param_name();
  os << ")";
}
