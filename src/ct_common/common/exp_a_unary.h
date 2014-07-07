//===----- ct_common/common/exp_a_unary.h -=---------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the base class for unary expressions
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_EXP_A_UNARY_H_
#define CT_COMMON_EXP_A_UNARY_H_

#include <boost/shared_ptr.hpp>
#include <ct_common/common/utils.h>
#include <ct_common/common/exp_a.h>

namespace ct {
namespace common {
class DLL_EXPORT Exp_A_Unary : public Exp_A {
public:
  Exp_A_Unary(void);
  Exp_A_Unary(const Exp_A_Unary &from);
  Exp_A_Unary &operator = (const Exp_A_Unary &right);
  virtual ~Exp_A_Unary(void) = 0;

public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual void dump(std::ostream &os, const std::vector<boost::shared_ptr<ParamSpec> > &param_specs) const;
  virtual std::string get_op_token(void) const = 0;

public:
  boost::shared_ptr<const Exp_A> get_oprd(void) const { return boost::dynamic_pointer_cast<Exp_A>(this->oprds_[0]); }

  void set_oprd(const boost::shared_ptr<TreeNode> &oprd) { this->oprds_[0] = oprd; }

private:
  virtual EvalType_Double EvaluateDouble_Impl( const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                                      const Assignment &assignment) const;

  virtual EvalType_Int EvaluateInt_Impl( const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                                const Assignment &assignment) const;

private:
  // whether the result is valid is controlled by Evaluate functions
  virtual double evaluate_double(double val) const = 0;
  virtual int evaluate_int(int val) const = 0;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_EXP_A_UNARY_H_
