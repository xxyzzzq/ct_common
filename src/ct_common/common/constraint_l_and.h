// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_CONSTRAINT_L_AND_H_
#define CT_COMMON_COMMON_CONSTRAINT_L_AND_H_

#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint_l_binary.h"

namespace ct_common {

// Class for constraint "&&"
class DLL_EXPORT Constraint_L_And : public Constraint_L_Binary {
 public:
  Constraint_L_And(void);
  Constraint_L_And(const Constraint_L_And &from);
  Constraint_L_And &operator=(const Constraint_L_And &right);
  virtual ~Constraint_L_And(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual std::string get_op_token(void) const;

 private:
  virtual EvalType_Bool evaluate_func(EvalType_Bool l_val,
                                      EvalType_Bool r_val) const;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_CONSTRAINT_L_AND_H_
