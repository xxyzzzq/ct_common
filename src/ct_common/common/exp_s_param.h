// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_S_PARAM_H_
#define CT_COMMON_COMMON_EXP_S_PARAM_H_

#include <set>
#include <string>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_s_atomic.h"

namespace ct_common {

class DLL_EXPORT Exp_S_Param : public Exp_S_Atomic {
 public:
  Exp_S_Param();
  ~Exp_S_Param() override;

  void dump(
      std::ostream& os,
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs)
      const override;

  void inner_touch_leaf_pids(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      std::set<std::size_t>* pids_to_touch) const override;

  void set_pid(std::size_t pid) { pid_ = pid; }
  std::size_t get_pid() const { return pid_; }

  optional<std::string> Evaluate(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const Assignment& assignment) const override;

 private:
  // The parameter id.
  std::size_t pid_;

  DISALLOW_COPY_AND_ASSIGN(Exp_S_Param);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_S_PARAM_H_
