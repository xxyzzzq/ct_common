//===----- ct_common/common/constraint_a_ge.h -------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for arithmetic constraint ">="
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_CONSTRAINT_A_GE_H_
#define CT_COMMON_CONSTRAINT_A_GE_H_

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint_a_binary.h"

namespace ct {
namespace common {
/**
 * The class for constraint ">="
 */
class DLL_EXPORT Constraint_A_GE : public Constraint_A_Binary {
public:
  Constraint_A_GE(void);
  Constraint_A_GE(const Constraint_A_GE &from);
  Constraint_A_GE &operator = (const Constraint_A_GE &right);
  ~Constraint_A_GE(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual std::string get_op_token(void) const;

private:
  virtual bool evaluate_func_int(int loprd_val, int roprd_val) const;
  virtual bool evaluate_func_double(double loprd_val, double roprd_val) const;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_A_GE_H_
