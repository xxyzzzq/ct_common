// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EVAL_TYPE_BOOL_H_
#define CT_COMMON_COMMON_EVAL_TYPE_BOOL_H_

#include "ct_common/common/eval_type.h"

namespace ct_common {

struct EvalType_Bool : public EvalType {
 public:
  EvalType_Bool(void);
  EvalType_Bool(bool value, bool is_valid);
  EvalType_Bool(const EvalType_Bool &from);
  virtual ~EvalType_Bool(void);
  EvalType_Bool &operator=(const EvalType_Bool &right);

 public:
  bool value_;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EVAL_TYPE_BOOL_H_
