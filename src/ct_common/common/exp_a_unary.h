// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_A_UNARY_H_
#define CT_COMMON_COMMON_EXP_A_UNARY_H_

#include <memory>
#include <string>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_a.h"

namespace ct_common {

// The base class for unary expressions.
class DLL_EXPORT Exp_A_Unary : public Exp_A {
 public:
  Exp_A_Unary();
  ~Exp_A_Unary() override;

  void Dump(
      std::ostream& os,
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs)
      const override;
  std::shared_ptr<const Exp_A> get_oprd() const {
    return std::dynamic_pointer_cast<Exp_A>(oprds_[0]);
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

  /** Get the corresponding string token */
  virtual std::string get_op_token() const = 0;
  /** Inner function for determing the resulting value */
  virtual optional<double> evaluate_double(
      const optional<double>& val) const = 0;
  /** Inner function for determing the resulting value */
  virtual optional<int> evaluate_int(
      const optional<int>& val) const = 0;

  DISALLOW_COPY_AND_ASSIGN(Exp_A_Unary);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_A_UNARY_H_
