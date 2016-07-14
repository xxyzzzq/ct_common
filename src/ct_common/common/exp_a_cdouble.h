// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_A_CDOUBLE_H_
#define CT_COMMON_COMMON_EXP_A_CDOUBLE_H_

#include <vector>
#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_a_atomic.h"

namespace ct_common {

// Class for constant double arithmetic expressions
class DLL_EXPORT Exp_A_CDouble : public Exp_A_Atomic {
 public:
  Exp_A_CDouble();
  ~Exp_A_CDouble() override;

  void dump(
      std::ostream& os,
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs)
      const override;

  /** Setting the value */
  void set_value(int value);
  /** Setting the value */
  void set_value(double value);
  void set_str_value(const std::string& str_value);

  /** Getting the value */
  double get_value() const { return value_; }
  /** Getting the string value */
  const std::string& get_str_value() const override;

 private:
  optional<double> EvaluateDouble_Impl(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const Assignment& assignment) const override;

  optional<int> EvaluateInt_Impl(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const Assignment& assignment) const override;

  double value_;
  std::string str_value_; /**< The preserved original string representation */

  DISALLOW_COPY_AND_ASSIGN(Exp_A_CDouble);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_A_CDOUBLE_H_
