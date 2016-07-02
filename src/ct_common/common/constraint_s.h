// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_CONSTRAINT_S_H_
#define CT_COMMON_COMMON_CONSTRAINT_S_H_

#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint.h"

namespace ct_common {

// Base class for string constraints, i.e. constraints taking strings as
// operands
class DLL_EXPORT Constraint_S : public Constraint {
 public:
  Constraint_S(void);
  Constraint_S(const Constraint_S &from);
  Constraint_S &operator=(const Constraint_S &right);
  virtual ~Constraint_S(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_CONSTRAINT_S_H_
