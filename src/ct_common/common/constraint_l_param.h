//===----- ct_common/common/constraint_l_param.h ----------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for constraints w.r.t.
// a boolean parameter
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_CONSTRAINT_L_PARAM_H_
#define CT_COMMON_CONSTRAINT_L_PARAM_H_

#include "ct_common/common/constraint_l_atom.h"

namespace ct {
namespace common {
/**
 * The class for parameter logical constraints, which is atomic
 */
class Constraint_L_Param : public Constraint_L_Atom {
 public:
  Constraint_L_Param(void);
  Constraint_L_Param(const Constraint_L_Param &from);
  virtual ~Constraint_L_Param(void);
  Constraint_L_Param &operator=(const Constraint_L_Param &right);

 public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual void dump(
      std::ostream &os,
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const;

  void set_pid(std::size_t pid) { this->pid_ = pid; }
  std::size_t get_pid(void) const { return this->pid_; }

  virtual void inner_touch_leaf_pids(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      std::set<std::size_t> &pids_to_touch) const;

 public:
  virtual EvalType_Bool Evaluate(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      const Assignment &assignment) const;

 private:
  std::size_t pid_; /**< parameter id */
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_L_PARAM_H_
