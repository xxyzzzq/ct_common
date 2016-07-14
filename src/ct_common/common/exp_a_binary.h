// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_A_BINARY_H_
#define CT_COMMON_COMMON_EXP_A_BINARY_H_

#include <memory>
#include <string>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_a.h"

namespace ct_common {

// Base class for binary arithmetic expressions
class DLL_EXPORT Exp_A_Binary : public Exp_A {
 public:
  Exp_A_Binary();
  ~Exp_A_Binary();

  void dump(
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

 private:
  friend class ExpABinary_InternalEvaluator;

  /** Get the corresponding string token */
  virtual std::string GetOpToken() const = 0;

  optional<double> EvaluateDouble_Impl(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const Assignment& assignment) const override;

  optional<int> EvaluateInt_Impl(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const Assignment& assignment) const override;

  /** Inner functions to calculate the resulting value */
  virtual optional<double> EvaluateDoubleInternal(
      const optional<double>& val_1, const optional<double>& val_2) const = 0;
  /** Inner functions to calculate the resulting value */
  virtual optional<int> EvaluateIntInternal(
      const optional<int>& val_1, const optional<int>& val_2) const = 0;

  DISALLOW_COPY_AND_ASSIGN(Exp_A_Binary);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_A_BINARY_H_
