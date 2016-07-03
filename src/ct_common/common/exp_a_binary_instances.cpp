// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/exp_a_binary_instances.h"

namespace ct_common {

namespace {

auto kFuncAdd_Int = [](
    const optional<int>& a, const optional<int>& b)
    -> optional<int> {
  if (!a || !b)
    return nullopt;
  return a.value() + b.value();
};
auto kFuncDiv_Int = [](
    const optional<int>& a, const optional<int>& b)
    -> optional<int> {
  if (!a || !b)
    return nullopt;
  if (b.value() == 0) {
    CT_EXCEPTION("cannot divide by zero");
  }
  return a.value() / b.value();
};
auto kFuncMod_Int = [](
    const optional<int>& a, const optional<int>& b)
    -> optional<int> {
  if (!a || !b)
    return nullopt;
  if (b.value() == 0) {
    CT_EXCEPTION("cannot mod by zero");
  }
  return a.value() % b.value();
};
auto kFuncMult_Int = [](
    const optional<int>& a, const optional<int>& b)
    -> optional<int> {
  if (!a || !b)
    return nullopt;
  return a.value() * b.value();
};
auto kFuncSub_Int = [](
    const optional<int>& a, const optional<int>& b)
    -> optional<int> {
  if (!a || !b)
    return nullopt;
  return a.value() - b.value();
};

auto kFuncAdd_Double = [](
    const optional<double>& a, const optional<double>& b)
    -> optional<double> {
  if (!a || !b)
    return nullopt;
  return a.value() + b.value();
};
auto kFuncDiv_Double = [](
    const optional<double>& a, const optional<double>& b)
    -> optional<double> {
  if (!a || !b)
    return nullopt;
  return a.value() / b.value();
};
auto kFuncMod_Double = [](
    const optional<double>& a, const optional<double>& b)
    -> optional<double> {
  if (!a || !b)
    return nullopt;
  CT_EXCEPTION("both the two operands of % must be integer");
  return static_cast<int>(a.value()) % static_cast<int>(b.value());
};
auto kFuncMult_Double = [](
    const optional<double>& a, const optional<double>& b)
    -> optional<double> {
  if (!a || !b)
    return nullopt;
  return a.value() * b.value();
};
auto kFuncSub_Double = [](
    const optional<double>& a, const optional<double>& b)
    -> optional<double> {
  if (!a || !b)
    return nullopt;
  return a.value() - b.value();
};

}  // anonymous namespace

#define EXP_A_BINARY_SKELETON(                                          \
    CLASS_NAME, OP_TOKEN, EVAL_FUNC_INT, EVAL_FUNC_DOUBLE)              \
  REGISTER_CLASS_NAME(CLASS_NAME)                                       \
                                                                        \
  CLASS_NAME::CLASS_NAME() = default;                                   \
                                                                        \
  CLASS_NAME::~CLASS_NAME() = default;                                  \
                                                                        \
  optional<int> CLASS_NAME::EvaluateIntInternal(                        \
      const optional<int>& val_1,                                       \
      const optional<int>& val_2) const {                               \
    return EVAL_FUNC_INT(val_1, val_2);                                 \
  }                                                                     \
                                                                        \
  optional<double> CLASS_NAME::EvaluateDoubleInternal(                  \
      const optional<double>& val_1,                                    \
      const optional<double>& val_2) const {                            \
    return EVAL_FUNC_DOUBLE(val_1, val_2);                              \
  }                                                                     \
                                                                        \
  std::string CLASS_NAME::GetOpToken() const {                          \
    return OP_TOKEN;                                                    \
  }

#include "ct_common/common/exp_a_binary_instances.inc"

#undef EXP_A_BINARY_SKELETON

}  // namespace ct_common
