// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_S_H_
#define CT_COMMON_COMMON_EXP_S_H_

#include <memory>
#include <string>
#include <vector>

#include "ct_common/base/optional.h"
#include "ct_common/base/utils.h"
#include "ct_common/common/exp.h"
#include "ct_common/common/paramspec.h"

namespace ct_common {

// The base class for string expressions.
class DLL_EXPORT Exp_S : public Exp {
 public:
  Exp_S();
  ~Exp_S() override;

 public:
  // Function for evaluating the expression.
  virtual optional<std::string> Evaluate(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const Assignment& assignment) const = 0;

 private:
  DISALLOW_COPY_AND_ASSIGN(Exp_S);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_S_H_
