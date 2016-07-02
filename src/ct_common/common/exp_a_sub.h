// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_A_SUB_H_
#define CT_COMMON_COMMON_EXP_A_SUB_H_

#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_a_binary.h"

namespace ct_common {

// The class for arithematic expression "-" (binary).
class DLL_EXPORT Exp_A_Sub : public Exp_A_Binary {
 public:
  Exp_A_Sub(void);
  Exp_A_Sub(const Exp_A_Sub &from);
  Exp_A_Sub &operator=(const Exp_A_Sub &right);
  virtual ~Exp_A_Sub(void);

 public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual std::string get_op_token(void) const;

 private:
  virtual double evaluate_double(double val_1, double val_2) const;
  virtual int evaluate_int(int val_1, int val_2) const;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_A_SUB_H_
