// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_A_H_
#define CT_COMMON_COMMON_EXP_A_H_

#include <memory>
#include <string>
#include <vector>

#include "ct_common/base/optional.h"
#include "ct_common/base/utils.h"
#include "ct_common/common/assignment.h"
#include "ct_common/common/exp.h"
#include "ct_common/common/paramspec.h"

namespace ct_common {

// Arithmetic expression types
enum eEXP_A_TYPE {
  EAT_INT,    /**< Integer type */
  EAT_DOUBLE, /**< Floating-point type */
};

// Utility macro for getting the resulting value of some arithmetic expression,
// which is converted into the given type.
#define GET_EXP_VAL(type, identifier, exp, param_specs, assignment) \
  optional<type> identifier;                                        \
  switch (exp->get_type()) {                                        \
    case EAT_INT:                                                   \
      identifier = cast_optional<type>(                             \
          exp->EvaluateInt(param_specs, assignment));               \
      break;                                                        \
    case EAT_DOUBLE:                                                \
      identifier = cast_optional<type>(                             \
          exp->EvaluateDouble(param_specs, assignment));            \
      break;                                                        \
    default:                                                        \
      CT_EXCEPTION("unrecognized expression type when evaluating"); \
  }

/**
 * Base class of arithmetic expressions
 */
class DLL_EXPORT Exp_A : public Exp {
 public:
  Exp_A();
  ~Exp_A() override;

  /** Evaluate the double value of the expression. Checks whether the expression
   * is of double type. */
  optional<double> EvaluateDouble(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const Assignment& assignment) const;
  /** Evaluate the int value of the expression. Checks whether the expression is
   * of int type. */
  optional<int> EvaluateInt(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const Assignment& assignment) const;

  eEXP_A_TYPE get_type() const { return type_; }
  void set_type(eEXP_A_TYPE type) { type_ = type; }

 protected:
  eEXP_A_TYPE type_; /**< whether the expression is int or double */

 private:
  /** Inner evaluating the double value of the expression, no type checking
   * here, just return the desired value. */
  virtual optional<double> EvaluateDouble_Impl(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const Assignment& assignment) const = 0;
  /** Inner evaluating the int value of the expression, no type checking here,
   * just return the desired value. */
  virtual optional<int> EvaluateInt_Impl(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const Assignment& assignment) const = 0;

  DISALLOW_COPY_AND_ASSIGN(Exp_A);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_A_H_
