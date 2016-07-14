// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_S_CSTRING_H_
#define CT_COMMON_COMMON_EXP_S_CSTRING_H_

#include <string>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_s_atomic.h"

namespace ct_common {
// Base class for constant string expression.
class DLL_EXPORT Exp_S_CString : public Exp_S_Atomic {
 public:
  Exp_S_CString();
  ~Exp_S_CString() override;

  void dump(
      std::ostream& os,
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs)
      const override;

  /** Setting the value */
  void set_value(const std::string& value) { value_ = value; }
  /** Setting the value */
  void set_value(const char* value) { value_ = value; }

  /** Getting the value */
  const std::string& get_value() const { return value_; }
  const std::string& get_str_value() const override;

  optional<std::string> Evaluate(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const Assignment& assignment) const override;

 private:
  std::string value_;

  DISALLOW_COPY_AND_ASSIGN(Exp_S_CString);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_S_CSTRING_H_
