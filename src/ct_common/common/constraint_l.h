// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_CONSTRAINT_L_H_
#define CT_COMMON_COMMON_CONSTRAINT_L_H_

#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint.h"

namespace ct_common {

// Base class for logical constraints
class DLL_EXPORT Constraint_L : public Constraint {
 public:
  Constraint_L();
  ~Constraint_L() override;

 private:
  DISALLOW_COPY_AND_ASSIGN(Constraint_L);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_CONSTRAINT_L_H_
