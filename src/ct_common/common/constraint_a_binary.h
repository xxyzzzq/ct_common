// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_CONSTRAINT_A_BINARY_H_
#define CT_COMMON_COMMON_CONSTRAINT_A_BINARY_H_

#include <memory>
#include <string>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint_a.h"
#include "ct_common/common/exp_a.h"

namespace ct_common {

// Base class for binary arithmetic constraints
class DLL_EXPORT Constraint_A_Binary : public Constraint_A {
 public:
  Constraint_A_Binary();
  ~Constraint_A_Binary() override;

  void Dump(
      std::ostream& os,
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs)
      const override;

  std::shared_ptr<const Exp_A> get_loprd() const {
    return std::dynamic_pointer_cast<Exp_A>(oprds_[0]);
  }
  std::shared_ptr<const Exp_A> get_roprd() const {
    return std::dynamic_pointer_cast<Exp_A>(oprds_[1]);
  }

  void set_loprd(const std::shared_ptr<TreeNode>& loprd) {
    oprds_[0] = loprd;
  }
  void set_roprd(const std::shared_ptr<TreeNode>& roprd) {
    oprds_[1] = roprd;
  }

  /** Set the floating-point precision (for comparison) */
  void set_precision(double precision) {
    precision_ = (precision >= 0) ? precision : -precision;
  }  // absolute value
  /** Get the floating-point precision */
  double get_precision() const { return precision_; }

  optional<bool> Evaluate(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const Assignment& assignment) const override;

 protected:
  double precision_; /**< Precision for comparing floating-point operands */

 private:
  /** get the string token of the current constraint type */
  virtual std::string GetOpToken() const = 0;
  /** Inner check function for int values */
  virtual bool EvaluateIntInternal(int val_1, int val_2) const = 0;
  /** Inner check function for double values */
  virtual bool EvaluateDoubleInternal(double val_1, double val_2) const = 0;

  DISALLOW_COPY_AND_ASSIGN(Constraint_A_Binary);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_CONSTRAINT_A_BINARY_H_
