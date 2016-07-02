// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_CONSTRAINT_L_IFF_H_
#define CT_COMMON_COMMON_CONSTRAINT_L_IFF_H_

#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint_l_binary.h"

namespace ct_common {

// Class for logical constraing "<->"
class DLL_EXPORT Constraint_L_Iff : public Constraint_L_Binary {
 public:
  Constraint_L_Iff(void);
  Constraint_L_Iff(const Constraint_L_Iff &from);
  Constraint_L_Iff &operator=(const Constraint_L_Iff &right);
  virtual ~Constraint_L_Iff(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual std::string get_op_token(void) const;

 private:
  virtual EvalType_Bool evaluate_func(EvalType_Bool val_l,
                                      EvalType_Bool val_r) const;
};
}  // namespace ct_common

#endif  // CT_COMMON_COMMON_CONSTRAINT_L_IFF_H_
