// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EVAL_TYPE_INT_H_
#define CT_COMMON_COMMON_EVAL_TYPE_INT_H_

#include "ct_common/common/eval_type.h"

namespace ct_common {

class EvalType_Double;

class EvalType_Int : public EvalType {
 public:
  EvalType_Int();
  EvalType_Int(int value, bool is_valid);
  EvalType_Int(const EvalType_Int &from);
  explicit EvalType_Int(const EvalType_Double &from);
  virtual ~EvalType_Int(void);

  EvalType_Int &operator=(const EvalType_Int &right);
  EvalType_Int &operator=(const EvalType_Double &right);

 public:
  int value_;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EVAL_TYPE_INT_H_
