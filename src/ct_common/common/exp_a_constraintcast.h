// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_A_CONSTRAINTCAST_H_
#define CT_COMMON_COMMON_EXP_A_CONSTRAINTCAST_H_

#include <memory>
#include <string>
#include <vector>

#include "ct_common/common/constraint.h"
#include "ct_common/common/exp_a_atomic.h"

namespace ct_common {

// Class for arithmetic expressions casted from constraints
class DLL_EXPORT Exp_A_ConstraintCast : public Exp_A_Atomic {
 public:
  Exp_A_ConstraintCast();
  ~Exp_A_ConstraintCast() override;

  void Dump(
      std::ostream& os,
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs)
      const override;

  std::shared_ptr<Constraint> get_oprd() const {
    return std::dynamic_pointer_cast<Constraint>(oprds_[0]);
  }

  void set_oprd(const std::shared_ptr<TreeNode>& oprd) {
    oprds_[0] = oprd;
  }

 private:
  optional<double> EvaluateDouble_Impl(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const Assignment& assignment) const override;

  optional<int> EvaluateInt_Impl(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const Assignment& assignment) const override;

  DISALLOW_COPY_AND_ASSIGN(Exp_A_ConstraintCast);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_A_CONSTRAINTCAST_H_
