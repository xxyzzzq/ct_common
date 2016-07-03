// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_CONSTRAINT_A_BINARY_INSTANCES_H_
#define CT_COMMON_COMMON_CONSTRAINT_A_BINARY_INSTANCES_H_

#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint_a_binary.h"

namespace ct_common {

#define CONSTRAINT_A_BINARY_SKELETON(CLASS_NAME, OP_TOKEN, EVAL_FUNC) \
  class DLL_EXPORT CLASS_NAME : public Constraint_A_Binary {          \
   public:                                                            \
    CLASS_NAME();                                                     \
    ~CLASS_NAME() override;                                           \
                                                                      \
   private:                                                           \
    std::string GetOpToken() const override;                          \
                                                                      \
    bool EvaluateIntInternal(                                         \
        int loprd_val, int roprd_val) const override;                 \
    bool EvaluateDoubleInternal(                                      \
        double loprd_val, double roprd_val) const override;           \
                                                                      \
    DISALLOW_COPY_AND_ASSIGN(CLASS_NAME);                             \
  };

#include "ct_common/common/constraint_a_binary_instances.inc"

#undef CONSTRAINT_A_BINARY_SKELETON

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_CONSTRAINT_A_BINARY_INSTANCES_H_
