// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_A_BINARY_INSTANCES_H_
#define CT_COMMON_COMMON_EXP_A_BINARY_INSTANCES_H_

#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_a_binary.h"

namespace ct_common {

#define EXP_A_BINARY_SKELETON(                                         \
    CLASS_NAME, OP_TOKEN, EVAL_FUNC_INT, EVAL_FUNC_DOUBLE)             \
  class DLL_EXPORT CLASS_NAME : public Exp_A_Binary {                  \
   public:                                                             \
    CLASS_NAME();                                                      \
    ~CLASS_NAME() override;                                            \
                                                                       \
   private:                                                            \
    std::string GetOpToken() const override;                           \
                                                                       \
    optional<double> EvaluateDoubleInternal(                           \
        const optional<double>& val_1,                                 \
        const optional<double>& val_2) const override;                 \
    optional<int> EvaluateIntInternal(                                 \
        const optional<int>& val_1,                                    \
        const optional<int>& val_2) const override;                    \
                                                                       \
    DISALLOW_COPY_AND_ASSIGN(CLASS_NAME);                              \
  };

#include "ct_common/common/exp_a_binary_instances.inc"

#undef EXP_A_BINARY_SKELETON

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_A_BINARY_INSTANCES_H_
