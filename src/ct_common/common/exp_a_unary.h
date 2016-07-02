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
  Exp_A_Unary(void);
  Exp_A_Unary(const Exp_A_Unary &from);
  Exp_A_Unary &operator=(const Exp_A_Unary &right);
  virtual ~Exp_A_Unary(void) = 0;

 public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual void dump(
      std::ostream &os,
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const;
  /** Get the corresponding string token */
  virtual std::string get_op_token(void) const = 0;

 public:
  std::shared_ptr<const Exp_A> get_oprd(void) const {
    return std::dynamic_pointer_cast<Exp_A>(this->oprds_[0]);
  }

  void set_oprd(const std::shared_ptr<TreeNode> &oprd) {
    this->oprds_[0] = oprd;
  }

 private:
  virtual EvalType_Double EvaluateDouble_Impl(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      const Assignment &assignment) const;

  virtual EvalType_Int EvaluateInt_Impl(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      const Assignment &assignment) const;

 private:
  /** Inner function for determing the resulting value */
  virtual double evaluate_double(double val) const = 0;
  /** Inner function for determing the resulting value */
  virtual int evaluate_int(int val) const = 0;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_A_UNARY_H_
