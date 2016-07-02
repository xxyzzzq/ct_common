// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_S_CSTRING_H_
#define CT_COMMON_COMMON_EXP_S_CSTRING_H_

#include <string>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_s_atom.h"

namespace ct_common {
// Base class for constant string expression.
class DLL_EXPORT Exp_S_CString : public Exp_S_Atom {
 public:
  Exp_S_CString(void);
  Exp_S_CString(const Exp_S_CString &from);
  Exp_S_CString &operator=(const Exp_S_CString &right);
  virtual ~Exp_S_CString(void);

 public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual void dump(
      std::ostream &os,
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const;

 public:
  /** Setting the value */
  void set_value(const std::string &value) { this->value_ = value; }
  /** Setting the value */
  void set_value(const char *value) { this->value_ = value; }

  /** Getting the value */
  const std::string &get_value(void) const { return this->value_; }
  virtual const std::string &get_str_value(void) const;

  virtual EvalType_String Evaluate(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      const Assignment &assignment) const;

 private:
  std::string value_;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_S_CSTRING_H_
