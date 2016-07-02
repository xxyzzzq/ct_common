// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_S_PARAM_H_
#define CT_COMMON_COMMON_EXP_S_PARAM_H_

#include <set>
#include <string>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_s_atom.h"

namespace ct_common {

class DLL_EXPORT Exp_S_Param : public Exp_S_Atom {
 public:
  Exp_S_Param(void);
  Exp_S_Param(const Exp_S_Param &from);
  Exp_S_Param &operator=(const Exp_S_Param &right);
  virtual ~Exp_S_Param(void);

 public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual void dump(
      std::ostream &os,
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const;

  virtual void inner_touch_leaf_pids(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      std::set<std::size_t>* pids_to_touch) const;

 public:
  void set_pid(std::size_t pid) { this->pid_ = pid; }
  std::size_t get_pid(void) const { return this->pid_; }

  virtual EvalType_String Evaluate(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      const Assignment &assignment) const;

 private:
  // The parameter id.
  std::size_t pid_;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_S_PARAM_H_
