// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_A_ATOMIC_H_
#define CT_COMMON_COMMON_EXP_A_ATOMIC_H_

#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_a.h"
#include "ct_common/common/paramspec.h"

namespace ct_common {

// Base class for atomic arithmetical expressions, i.e. no contained
// sub-expressions.
class DLL_EXPORT Exp_A_Atomic : public Exp_A {
 public:
  Exp_A_Atomic();
  ~Exp_A_Atomic() override;

 private:
  DISALLOW_COPY_AND_ASSIGN(Exp_A_Atomic);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_A_ATOMIC_H_
