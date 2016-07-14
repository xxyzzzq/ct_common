// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_CONSTRAINT_L_UNARY_H_
#define CT_COMMON_COMMON_CONSTRAINT_L_UNARY_H_

#include <memory>
#include <string>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint_l.h"

namespace ct_common {

// Base class for unary logical constraints
class DLL_EXPORT Constraint_L_Unary : public Constraint_L {
 public:
  Constraint_L_Unary();
  ~Constraint_L_Unary() override;

  void dump(
      std::ostream& os,
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs)
      const override;

  std::shared_ptr<const Constraint> get_oprd() const {
    return std::dynamic_pointer_cast<Constraint>(oprds_[0]);
  }

  void set_oprd(const std::shared_ptr<TreeNode>& oprd) {
    oprds_[0] = oprd;
  }

  optional<bool> Evaluate(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const Assignment& assignment) const override;

 private:
  /** Get the corresponding string token */
  virtual std::string GetOpToken() const = 0;
  /** Inner function for evaluating the value */
  virtual optional<bool> EvaluateInternal(const optional<bool>& val) const = 0;

  DISALLOW_COPY_AND_ASSIGN(Constraint_L_Unary);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_CONSTRAINT_L_UNARY_H_
