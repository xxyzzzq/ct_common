//===----- ct_common/common/exp_a_neg.h -------------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for arithmetic expression "-" (unary)
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_EXP_A_NEG_H_
#define CT_COMMON_EXP_A_NEG_H_

#include <ct_common/common/utils.h>
#include <ct_common/common/exp_a_unary.h>

namespace ct {
namespace common {
class DLL_EXPORT Exp_A_Neg : public Exp_A_Unary {
public:
  Exp_A_Neg(void);
  Exp_A_Neg(const Exp_A_Neg &from);
  Exp_A_Neg &operator = (const Exp_A_Neg &right);
  virtual ~Exp_A_Neg(void);

public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual std::string get_op_token(void) const;

private:
  virtual double evaluate_double(double val) const;
  virtual int evaluate_int(int val) const;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_EXP_A_NEG_H_
