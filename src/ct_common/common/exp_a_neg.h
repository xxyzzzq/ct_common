// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_A_NEG_H_
#define CT_COMMON_COMMON_EXP_A_NEG_H_

#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_a_unary.h"

namespace ct_common {

// class for arithemetic expression "-" (unary).
class DLL_EXPORT Exp_A_Neg : public Exp_A_Unary {
 public:
  Exp_A_Neg();
  ~Exp_A_Neg() override;

 private:
  std::string get_op_token() const override;

  optional<double> evaluate_double(
      const optional<double>& val) const override;
  optional<int> evaluate_int(
      const optional<int>& val) const override;

  DISALLOW_COPY_AND_ASSIGN(Exp_A_Neg);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_A_NEG_H_
