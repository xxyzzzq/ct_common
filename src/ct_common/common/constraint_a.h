// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_CONSTRAINT_A_H_
#define CT_COMMON_COMMON_CONSTRAINT_A_H_

#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint.h"

namespace ct_common {

// Base class for arithmetic constraints
class DLL_EXPORT Constraint_A : public Constraint {
 public:
  Constraint_A(void);
  Constraint_A(const Constraint_A &from);
  Constraint_A &operator=(const Constraint_A &right);
  virtual ~Constraint_A(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_CONSTRAINT_A_H_
