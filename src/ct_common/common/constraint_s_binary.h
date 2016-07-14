// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_CONSTRAINT_S_BINARY_H_
#define CT_COMMON_COMMON_CONSTRAINT_S_BINARY_H_

#include <memory>
#include <string>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint_s.h"
#include "ct_common/common/exp_s.h"

namespace ct_common {

// Base class for binary string constraints
class DLL_EXPORT Constraint_S_Binary : public Constraint_S {
 public:
  Constraint_S_Binary();
  ~Constraint_S_Binary() override;

  void dump(
      std::ostream& os,
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs)
      const override;

  std::shared_ptr<const Exp_S> get_loprd() const {
    return std::dynamic_pointer_cast<Exp_S>(oprds_[0]);
  }
  std::shared_ptr<const Exp_S> get_roprd() const {
    return std::dynamic_pointer_cast<Exp_S>(oprds_[1]);
  }

  void set_loprd(const std::shared_ptr<TreeNode>& loprd) {
    oprds_[0] = loprd;
  }
  void set_roprd(const std::shared_ptr<TreeNode>& roprd) {
    oprds_[1] = roprd;
  }

  optional<bool> Evaluate(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const Assignment& assignment) const override;

 private:
  /** Get the corresponding string token */
  virtual std::string GetOpToken() const = 0;
  /** Inner function for determining the return value */
  virtual optional<bool> EvaluateInternal(
      const optional<std::string>& val_1,
      const optional<std::string>& val_2) const = 0;

  DISALLOW_COPY_AND_ASSIGN(Constraint_S_Binary);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_CONSTRAINT_S_BINARY_H_
