// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_CONSTRAINT_L_ATOMIC_H_
#define CT_COMMON_COMMON_CONSTRAINT_L_ATOMIC_H_

#include <memory>
#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint_l.h"
#include "ct_common/common/paramspec.h"

namespace ct_common {

// Base class for atomic constraints (i.e. no sub-constraints or
// sub-expressions)
class DLL_EXPORT Constraint_L_Atomic : public Constraint_L {
 public:
  Constraint_L_Atomic();
  ~Constraint_L_Atomic() override;

 private:
  DISALLOW_COPY_AND_ASSIGN(Constraint_L_Atomic);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_CONSTRAINT_L_ATOMIC_H_
