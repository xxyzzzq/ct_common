// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_CONSTRAINT_L_NOT_H_
#define CT_COMMON_COMMON_CONSTRAINT_L_NOT_H_

#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint_l_unary.h"

namespace ct_common {

// Class for logical constraint "!"
class DLL_EXPORT Constraint_L_Not : public Constraint_L_Unary {
 public:
  Constraint_L_Not(void);
  Constraint_L_Not(const Constraint_L_Not &from);
  Constraint_L_Not &operator=(const Constraint_L_Not &right);
  virtual ~Constraint_L_Not(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual std::string get_op_token(void) const;

 private:
  virtual bool evaluate_func(bool val) const;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_CONSTRAINT_L_NOT_H_
