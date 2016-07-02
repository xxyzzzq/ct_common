// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_S_H_
#define CT_COMMON_COMMON_EXP_S_H_

#include <memory>
#include <string>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/eval_type_string.h"
#include "ct_common/common/exp.h"
#include "ct_common/common/paramspec.h"

namespace ct_common {

// The base class for string expressions.
class DLL_EXPORT Exp_S : public Exp {
 public:
  Exp_S(void);
  Exp_S(const Exp_S &from);
  Exp_S &operator=(const Exp_S &right);
  virtual ~Exp_S(void) = 0;

 public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);

 public:
  // Function for evaluating the expression.
  virtual EvalType_String Evaluate(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      const Assignment &assignment) const = 0;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_S_H_
