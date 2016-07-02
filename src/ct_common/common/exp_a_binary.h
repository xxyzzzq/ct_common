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
  Exp_A_Binary(void);
  Exp_A_Binary(const Exp_A_Binary &from);
  Exp_A_Binary &operator=(const Exp_A_Binary &right);
  virtual ~Exp_A_Binary(void) = 0;

 public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual void dump(
      std::ostream &os,
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const;
  /** Get the corresponding string token */
  virtual std::string get_op_token(void) const = 0;

 public:
  std::shared_ptr<const Exp_A> get_loprd(void) const {
    return std::dynamic_pointer_cast<Exp_A>(this->oprds_[0]);
  }
  std::shared_ptr<const Exp_A> get_roprd(void) const {
    return std::dynamic_pointer_cast<Exp_A>(this->oprds_[1]);
  }

  void set_loprd(const std::shared_ptr<TreeNode> &loprd) {
    this->oprds_[0] = loprd;
  }
  void set_roprd(const std::shared_ptr<TreeNode> &roprd) {
    this->oprds_[1] = roprd;
  }

 private:
  virtual EvalType_Double EvaluateDouble_Impl(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      const Assignment &assignment) const;

  virtual EvalType_Int EvaluateInt_Impl(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      const Assignment &assignment) const;

 private:
  /** Inner functions to calculate the resulting value */
  virtual double evaluate_double(double val_1, double val_2) const = 0;
  /** Inner functions to calculate the resulting value */
  virtual int evaluate_int(int val_1, int val_2) const = 0;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_A_BINARY_H_
