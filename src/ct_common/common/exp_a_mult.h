//===----- ct_common/common/exp_a_mult.h ------------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for arithmetic expression "*"
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_EXP_A_MULT_H_
#define CT_COMMON_EXP_A_MULT_H_

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_a_binary.h"

namespace ct {
namespace common {
/**
 * The class for arithmectic expression "*"
 */
class DLL_EXPORT Exp_A_Mult : public Exp_A_Binary {
 public:
  Exp_A_Mult(void);
  Exp_A_Mult(const Exp_A_Mult &from);
  Exp_A_Mult &operator=(const Exp_A_Mult &right);
  virtual ~Exp_A_Mult(void);

 public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual std::string get_op_token(void) const;

 private:
  virtual double evaluate_double(double val_1, double val_2) const;
  virtual int evaluate_int(int val_1, int val_2) const;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_EXP_A_MULT_H_
