// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EVAL_TYPE_DOUBLE_H_
#define CT_COMMON_COMMON_EVAL_TYPE_DOUBLE_H_

#include "ct_common/common/eval_type.h"

namespace ct_common {

class EvalType_Int;

class EvalType_Double : public EvalType {
 public:
  EvalType_Double(void);
  EvalType_Double(double value, bool is_valid);
  EvalType_Double(const EvalType_Double &from);
  explicit EvalType_Double(const EvalType_Int &from);
  virtual ~EvalType_Double(void);

  EvalType_Double &operator=(const EvalType_Double &right);
  EvalType_Double &operator=(const EvalType_Int &right);

 public:
  double value_;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EVAL_TYPE_DOUBLE_H_
