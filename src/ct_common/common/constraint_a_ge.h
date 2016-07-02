// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_CONSTRAINT_A_GE_H_
#define CT_COMMON_COMMON_CONSTRAINT_A_GE_H_

#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint_a_binary.h"

namespace ct_common {

// Class for constraint ">="
class DLL_EXPORT Constraint_A_GE : public Constraint_A_Binary {
 public:
  Constraint_A_GE(void);
  Constraint_A_GE(const Constraint_A_GE &from);
  Constraint_A_GE &operator=(const Constraint_A_GE &right);
  ~Constraint_A_GE(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual std::string get_op_token(void) const;

 private:
  virtual bool evaluate_func_int(int loprd_val, int roprd_val) const;
  virtual bool evaluate_func_double(double loprd_val, double roprd_val) const;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_CONSTRAINT_A_GE_H_
