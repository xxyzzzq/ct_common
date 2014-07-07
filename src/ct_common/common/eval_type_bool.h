//===----- ct_common/common/eval_type_bool.h --------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for boolean evaluation type 
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_EVAL_TYPE_BOOL_H_
#define CT_COMMON_EVAL_TYPE_BOOL_H_

#include <ct_common/common/eval_type.h>

namespace ct {
namespace common {
struct EvalType_Bool : public EvalType {
public:
  EvalType_Bool(void);
  EvalType_Bool(bool value, bool is_valid);
  EvalType_Bool(const EvalType_Bool &from);
  virtual ~EvalType_Bool(void);
  EvalType_Bool &operator = (const EvalType_Bool &right);

public:
  bool value_;
};
}
}

#endif  // CT_COMMON_EVAL_TYPE_BOOL_H_
