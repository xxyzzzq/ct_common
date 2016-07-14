// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/constraint_a_binary_instances.h"

#include "ct_common/base/arithmetic_utils.h"

namespace ct_common {

#define CONSTRAINT_A_BINARY_SKELETON(CLASS_NAME, OP_TOKEN, EVAL_FUNC)   \
  REGISTER_CLASS_NAME(CLASS_NAME);                                      \
                                                                        \
  CLASS_NAME::CLASS_NAME() = default;                                   \
                                                                        \
  CLASS_NAME::~CLASS_NAME() = default;                                  \
                                                                        \
  bool CLASS_NAME::EvaluateIntInternal(                                 \
      int loprd_val, int roprd_val) const {                             \
    return EVAL_FUNC(loprd_val, roprd_val, precision_);                 \
  }                                                                     \
                                                                        \
  bool CLASS_NAME::EvaluateDoubleInternal(                              \
      double loprd_val, double roprd_val) const {                       \
    return EVAL_FUNC(loprd_val, roprd_val, precision_);                 \
  }                                                                     \
                                                                        \
  std::string CLASS_NAME::GetOpToken() const {                          \
    return OP_TOKEN;                                                    \
  }

#include "ct_common/common/constraint_a_binary_instances.inc"

#undef CONSTRAINT_A_BINARY_SKELETON

}  // namespace ct_common
