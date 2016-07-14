// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_A_CAST_H_
#define CT_COMMON_COMMON_EXP_A_CAST_H_

#include <string>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_a_unary.h"

namespace ct_common {

// Class for casting between int/double expressions
class DLL_EXPORT Exp_A_Cast : public Exp_A_Unary {
 public:
  Exp_A_Cast();
  ~Exp_A_Cast() override;

  void Dump(
      std::ostream& os,
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs)
      const override;
  std::string get_op_token() const override;

 private:
  optional<double> evaluate_double(
      const optional<double>& val) const override;
  optional<int> evaluate_int(
      const optional<int>& val) const override;

  DISALLOW_COPY_AND_ASSIGN(Exp_A_Cast);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_A_CAST_H_
