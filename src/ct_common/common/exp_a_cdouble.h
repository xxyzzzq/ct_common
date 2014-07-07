//===----- ct_common/common/exp_a_cdouble.h ---------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for constant double expressions
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_EXP_A_CDOUBLE_H
#define CT_COMMON_EXP_A_CDOUBLE_H

#include <ct_common/common/utils.h>
#include <ct_common/common/exp_a_atom.h>

namespace ct {
namespace common {
/**
 * The class for constant double arithmetic expressions
 */
class DLL_EXPORT Exp_A_CDouble : public Exp_A_Atom {
public:
  Exp_A_CDouble(void);
  Exp_A_CDouble(const Exp_A_CDouble &from);
  Exp_A_CDouble &operator = (const Exp_A_CDouble &right);
  virtual ~Exp_A_CDouble(void);

public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual void dump(std::ostream &os, const std::vector<boost::shared_ptr<ParamSpec> > &param_specs) const;

public:
  /** Setting the value */
  virtual void set_value(int value);
  /** Setting the value */
  virtual void set_value(double value);
  void set_str_value(const std::string &str_value);

  /** Getting the value */
  double get_value(void) const { return this->value_; }
  /** Getting the string value */
  virtual const std::string &get_str_value(void) const;

private:
  virtual EvalType_Double EvaluateDouble_Impl( const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                                      const Assignment &assignment) const;

  virtual EvalType_Int EvaluateInt_Impl( const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                                const Assignment &assignment) const;

private:
  double value_;
  std::string str_value_;  /**< The preserved original string representation */
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_EXP_A_CDOUBLE_H
