// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/constraint_l_binary_instances.h"

#include "ct_common/base/class_name_utils.h"

namespace ct_common {

namespace {

auto kFuncAnd = [](const optional<bool>& a, const optional<bool>& b)
    -> optional<bool> {
  if (a && b)
    return a.value() && b.value();
  return nullopt;
};
auto kFuncIff = [](const optional<bool>& a, const optional<bool>& b)
    -> optional<bool> {
  if (a && b)
    return a.value() == b.value();
  return nullopt;
};
auto kFuncImply = [](const optional<bool>& a, const optional<bool>& b)
    -> optional<bool> {
  if (a && !a.value())
    return true;
  if (b && b.value())
    return true;
  if (a && b && a.value() && !b.value())
    return false;
  return nullopt;
};
auto kFuncOr = [](const optional<bool>& a, const optional<bool>& b)
    -> optional<bool>{
  if (a && a.value())
    return true;
  if (b && b.value())
    return true;
  if (a && b && !a.value() && !b.value())
    return false;
  return nullopt;
};
auto kFuncXor = [](const optional<bool>& a, const optional<bool>& b)
    -> optional<bool> {
  if (a && b)
    return a.value() != b.value();
  return nullopt;
};

}  // anonymous namespace

#define CONSTRAINT_L_BINARY_SKELETON(CLASS_NAME, OP_TOKEN, EVAL_FUNC)   \
  REGISTER_CLASS_NAME(CLASS_NAME)                                       \
                                                                        \
  CLASS_NAME::CLASS_NAME() = default;                                   \
                                                                        \
  CLASS_NAME::~CLASS_NAME() = default;                                  \
                                                                        \
  optional<bool> CLASS_NAME::EvaluateInternal(                          \
      const optional<bool>& val_l, const optional<bool>& val_r) const { \
    return EVAL_FUNC(val_l, val_r);                                     \
  }                                                                     \
                                                                        \
  std::string CLASS_NAME::GetOpToken() const {                          \
    return OP_TOKEN;                                                    \
  }

#include "ct_common/common/constraint_l_binary_instances.inc"

#undef CONSTRAINT_L_BINARY_SKELETON

}  // namespace ct_common
