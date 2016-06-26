//===----- ct_common/common/exp_a_binary.h ----------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the base class for binary arithmetic expressions
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_EXP_A_BINARY_H_
#define CT_COMMON_EXP_A_BINARY_H_

#include <memory>

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_a.h"

namespace ct {
namespace common {
/**
 * Base class for binary arithmetic expressions
 */
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
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_EXP_A_BINARY_H_
