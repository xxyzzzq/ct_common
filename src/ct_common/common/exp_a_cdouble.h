// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_A_CDOUBLE_H_
#define CT_COMMON_COMMON_EXP_A_CDOUBLE_H_

#include <vector>
#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_a_atom.h"

namespace ct_common {

// Class for constant double arithmetic expressions
class DLL_EXPORT Exp_A_CDouble : public Exp_A_Atom {
 public:
  Exp_A_CDouble(void);
  Exp_A_CDouble(const Exp_A_CDouble &from);
  Exp_A_CDouble &operator=(const Exp_A_CDouble &right);
  virtual ~Exp_A_CDouble(void);

 public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual void dump(
      std::ostream &os,
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const;

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
  virtual EvalType_Double EvaluateDouble_Impl(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      const Assignment &assignment) const;

  virtual EvalType_Int EvaluateInt_Impl(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      const Assignment &assignment) const;

 private:
  double value_;
  std::string str_value_; /**< The preserved original string representation */
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_A_CDOUBLE_H_
