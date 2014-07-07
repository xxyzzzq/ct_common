//===----- ct_common/common/constraint_l_and.h ------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for logical constraint "&&"
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_CONSTRAINT_L_AND_H_
#define CT_COMMON_CONSTRAINT_L_AND_H_

#include <ct_common/common/utils.h>
#include <ct_common/common/constraint_l_binary.h>

namespace ct {
namespace common {
/**
 * The class for constraint "&&"
 */
class DLL_EXPORT Constraint_L_And : public Constraint_L_Binary {
public:
  Constraint_L_And(void);
  Constraint_L_And(const Constraint_L_And &from);
  Constraint_L_And &operator = (const Constraint_L_And &right);
  virtual ~Constraint_L_And(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual std::string get_op_token(void) const;

private:
  virtual EvalType_Bool evaluate_func(EvalType_Bool l_val, EvalType_Bool r_val) const;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_L_AND_H_
