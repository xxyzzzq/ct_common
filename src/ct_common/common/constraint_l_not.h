// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_CONSTRAINT_L_NOT_H_
#define CT_COMMON_COMMON_CONSTRAINT_L_NOT_H_

#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint_l_unary.h"

namespace ct_common {

// Class for logical constraint "!"
class DLL_EXPORT Constraint_L_Not : public Constraint_L_Unary {
 public:
  Constraint_L_Not();
  ~Constraint_L_Not() override;

 private:
  std::string GetOpToken() const override;

  optional<bool> EvaluateInternal(const optional<bool>& val) const override;

  DISALLOW_COPY_AND_ASSIGN(Constraint_L_Not);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_CONSTRAINT_L_NOT_H_
