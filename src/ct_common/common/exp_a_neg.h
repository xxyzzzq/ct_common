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
  Exp_A_Neg(void);
  Exp_A_Neg(const Exp_A_Neg &from);
  Exp_A_Neg &operator=(const Exp_A_Neg &right);
  virtual ~Exp_A_Neg(void);

 public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual std::string get_op_token(void) const;

 private:
  virtual double evaluate_double(double val) const;
  virtual int evaluate_int(int val) const;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_A_NEG_H_
