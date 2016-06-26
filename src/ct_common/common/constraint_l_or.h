//===----- ct_common/common/constraint_l_or.h -------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for logical constraint "||"
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_CONSTRAINT_L_OR_H_
#define CT_COMMON_CONSTRAINT_L_OR_H_

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint_l_binary.h"

namespace ct {
namespace common {
/**
 * The class for logical constraint "||"
 */
class DLL_EXPORT Constraint_L_Or : public Constraint_L_Binary {
public:
  Constraint_L_Or(void);
  Constraint_L_Or(const Constraint_L_Or &from);
  Constraint_L_Or &operator = (const Constraint_L_Or &right);
  virtual ~Constraint_L_Or(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual std::string get_op_token(void) const;

private:
  virtual EvalType_Bool evaluate_func(EvalType_Bool val_l, EvalType_Bool val_r) const;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_L_OR_H_
