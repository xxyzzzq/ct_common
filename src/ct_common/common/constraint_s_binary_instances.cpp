// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/constraint_s_binary_instances.h"

#include "ct_common/base/class_name_utils.h"

namespace ct_common {

namespace {

auto kFuncEqual = [](
    const optional<std::string>& a, const optional<std::string>& b)
    -> optional<bool> {
  if (a && b)
    return a.value() == b.value();
  return nullopt;
};

auto kFuncUnequal = [](
    const optional<std::string>& a, const optional<std::string>& b)
    -> optional<bool> {
  if (a && b)
    return a.value() != b.value();
  return nullopt;
};

}  // anonymous namespace

#define CONSTRAINT_S_BINARY_SKELETON(CLASS_NAME, OP_NAME, EVAL_FUNC) \
  REGISTER_CLASS_NAME(CLASS_NAME)                                    \
                                                                     \
  CLASS_NAME::CLASS_NAME() = default;                                \
                                                                     \
  CLASS_NAME::~CLASS_NAME() = default;                               \
                                                                     \
  optional<bool> CLASS_NAME::EvaluateInternal(                       \
      const optional<std::string>& val_1,                            \
      const optional<std::string>& val_2) const {                    \
    return EVAL_FUNC(val_1, val_2);                                  \
  }                                                                  \
                                                                     \
  std::string CLASS_NAME::GetOpToken() const {                       \
    return OP_NAME;                                                  \
  }

#include "ct_common/common/constraint_s_binary_instances.inc"

#undef CONSTRAINT_S_BINARY_SKELETON

}  // namespace ct_common
