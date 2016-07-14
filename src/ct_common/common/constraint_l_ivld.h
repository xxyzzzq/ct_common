// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_CONSTRAINT_L_IVLD_H_
#define CT_COMMON_COMMON_CONSTRAINT_L_IVLD_H_

#include <set>
#include <string>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint_l_atomic.h"

namespace ct_common {

// Class for parameter invalidation constraints which is atomic
class DLL_EXPORT Constraint_L_IVLD : public Constraint_L_Atomic {
 public:
  Constraint_L_IVLD();
  ~Constraint_L_IVLD() override;

  void Dump(
      std::ostream& os,
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs)
      const override;

  void InnerTouchLeafPids(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      std::set<std::size_t>* pids_to_touch) const override;

  void set_pid(std::size_t pid) { pid_ = pid; }
  std::size_t get_pid() const { return pid_; }

  optional<bool> Evaluate(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const Assignment& assignment) const override;

 private:
  std::size_t pid_; /**< parameter id */

  DISALLOW_COPY_AND_ASSIGN(Constraint_L_IVLD);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_CONSTRAINT_L_IVLD_H_
