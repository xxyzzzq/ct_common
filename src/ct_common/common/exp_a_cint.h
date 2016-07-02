// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_A_CINT_H_
#define CT_COMMON_COMMON_EXP_A_CINT_H_

#include <string>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_a_atom.h"

namespace ct_common {

// Class for constant int arithmetic expressions
class DLL_EXPORT Exp_A_CInt : public Exp_A_Atom {
 public:
  Exp_A_CInt(void);
  Exp_A_CInt(const Exp_A_CInt &from);
  Exp_A_CInt &operator=(const Exp_A_CInt &right);
  virtual ~Exp_A_CInt(void);

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
  /** Setting the string value (preserve a copy of the original string
   * representation) */
  void set_str_value(const std::string &str_value);

  /** Getting the value */
  int get_value(void) const { return this->value_; }
  virtual const std::string &get_str_value(void) const;

 private:
  virtual EvalType_Double EvaluateDouble_Impl(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      const Assignment &assignment) const;

  virtual EvalType_Int EvaluateInt_Impl(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      const Assignment &assignment) const;

 private:
  int value_;
  std::string str_value_; /**< The preserved original string representation */
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_A_CINT_H_
