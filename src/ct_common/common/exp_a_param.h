// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_A_PARAM_H_
#define CT_COMMON_COMMON_EXP_A_PARAM_H_

#include <set>
#include <string>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_a_atomic.h"

namespace ct_common {

// The class for arithemetic expressions w.r.t. a parameter.
class DLL_EXPORT Exp_A_Param : public Exp_A_Atomic {
 public:
  Exp_A_Param();
  ~Exp_A_Param() override;

  void dump(
      std::ostream& os,
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs)
      const override;

  void set_pid(std::size_t pid) { pid_ = pid; }
  std::size_t get_pid() const { return pid_; }

 private:
  optional<double> EvaluateDouble_Impl(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const Assignment& assignment) const override;

  optional<int> EvaluateInt_Impl(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const Assignment& assignment) const override;

  void inner_touch_leaf_pids(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      std::set<std::size_t>* pids_to_touch) const override;

  std::size_t pid_; /**< The parameter id */

  DISALLOW_COPY_AND_ASSIGN(Exp_A_Param);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_A_PARAM_H_
