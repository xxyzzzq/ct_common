//===----- ct_common/common/constraint_a_binary.h ---------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the base class for binary arithmetic constraints
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_CONSTRAINT_A_BINARY_H_
#define CT_COMMON_CONSTRAINT_A_BINARY_H_

#include <boost/shared_ptr.hpp>
#include <ct_common/common/utils.h>
#include <ct_common/common/constraint_a.h>
#include <ct_common/common/exp_a.h>

namespace ct {
namespace common {
class DLL_EXPORT Constraint_A_Binary : public Constraint_A {
public:
  Constraint_A_Binary(void);
  Constraint_A_Binary(const Constraint_A_Binary &from);
  Constraint_A_Binary &operator = (const Constraint_A_Binary &right);
  virtual ~Constraint_A_Binary(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual void dump(std::ostream &os, const std::vector<boost::shared_ptr<ParamSpec> > &param_specs) const;
  virtual std::string get_op_token(void) const = 0;

  boost::shared_ptr<const Exp_A> get_loprd(void) const { return boost::dynamic_pointer_cast<Exp_A>(this->oprds_[0]); }
  boost::shared_ptr<const Exp_A> get_roprd(void) const { return boost::dynamic_pointer_cast<Exp_A>(this->oprds_[1]); }

  void set_loprd(const boost::shared_ptr<TreeNode> &loprd) { this->oprds_[0] = loprd; }
  void set_roprd(const boost::shared_ptr<TreeNode> &roprd) { this->oprds_[1] = roprd; }
  
  void set_precision(double precision) { this->precision_ = (precision>=0) ? precision : -precision; } // absolute value
  double get_precision(void) const { return this->precision_; }

  virtual EvalType_Bool Evaluate(const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                        const Assignment &assignment) const;

private:
  // whether the result is valid is handled in the Evaluate function, since the result is invalid if any operand is invalid
  virtual bool evaluate_func_int(int val_1, int val_2) const = 0;
  virtual bool evaluate_func_double(double val_1, double val_2) const = 0;

protected:
  double precision_;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_A_BINARY_H_
