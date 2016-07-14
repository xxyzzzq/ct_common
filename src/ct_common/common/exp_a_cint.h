// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_A_CINT_H_
#define CT_COMMON_COMMON_EXP_A_CINT_H_

#include <string>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_a_atomic.h"

namespace ct_common {

// Class for constant int arithmetic expressions
class DLL_EXPORT Exp_A_CInt : public Exp_A_Atomic {
 public:
  Exp_A_CInt();
  ~Exp_A_CInt() override;

  void Dump(
      std::ostream& os,
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs)
      const override;

  /** Setting the value */
  void set_value(int value);
  /** Setting the value */
  void set_value(double value);
  /** Setting the string value (preserve a copy of the original string
   * representation) */
  void set_str_value(const std::string& str_value);

  /** Getting the value */
  int get_value() const { return value_; }
  const std::string& get_str_value() const override;

 private:
  optional<double> EvaluateDouble_Impl(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const Assignment& assignment) const override;

  optional<int> EvaluateInt_Impl(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const Assignment& assignment) const override;

  int value_;
  std::string str_value_; /**< The preserved original string representation */

  DISALLOW_COPY_AND_ASSIGN(Exp_A_CInt);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_A_CINT_H_
