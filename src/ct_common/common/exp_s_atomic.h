// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_S_ATOMIC_H_
#define CT_COMMON_COMMON_EXP_S_ATOMIC_H_

#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_s.h"
#include "ct_common/common/paramspec.h"

namespace ct_common {

// The base class for atomic string expressions.
class DLL_EXPORT Exp_S_Atomic : public Exp_S {
 public:
  Exp_S_Atomic();
  ~Exp_S_Atomic() override;

 private:
  DISALLOW_COPY_AND_ASSIGN(Exp_S_Atomic);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_S_ATOMIC_H_
