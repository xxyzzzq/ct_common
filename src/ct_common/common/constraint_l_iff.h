//===----- ct_common/common/constraint_l_iff.h ------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for logical constraint "<->"
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_CONSTRAINT_L_IFF_H_
#define CT_COMMON_CONSTRAINT_L_IFF_H_

#include <ct_common/common/utils.h>
#include <ct_common/common/constraint_l_binary.h>

namespace ct {
namespace common {
class DLL_EXPORT Constraint_L_Iff : public Constraint_L_Binary {
public:
  Constraint_L_Iff(void);
  Constraint_L_Iff(const Constraint_L_Iff &from);
  Constraint_L_Iff &operator = (const Constraint_L_Iff &right);
  virtual ~Constraint_L_Iff(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual std::string get_op_token(void) const;

private:
  virtual EvalType_Bool evaluate_func(EvalType_Bool val_l, EvalType_Bool val_r) const;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_L_IFF_H_
