// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_A_DIV_H_
#define CT_COMMON_COMMON_EXP_A_DIV_H_

#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_a_binary.h"

namespace ct_common {

// Class for arithmetic expression "/"
class DLL_EXPORT Exp_A_Div : public Exp_A_Binary {
 public:
  Exp_A_Div(void);
  Exp_A_Div(const Exp_A_Div &from);
  Exp_A_Div &operator=(const Exp_A_Div &right);
  virtual ~Exp_A_Div(void);

 public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual std::string get_op_token(void) const;

 private:
  virtual double evaluate_double(double val_1, double val_2) const;
  virtual int evaluate_int(int val_1, int val_2) const;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_A_DIV_H_
