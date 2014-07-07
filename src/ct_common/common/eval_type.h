//===----- ct_common/common/eval_type.h -------------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for evaluation type of constraints and
// expressions
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_EVAL_TYPE_H_
#define CT_COMMON_EVAL_TYPE_H_

namespace ct {
namespace common {
// Base class for TreeNode evaluation return type
class EvalType {
public:
  EvalType(void);
  EvalType(bool is_valid);
  EvalType(const EvalType &from);
  virtual ~EvalType(void) = 0;
  EvalType &operator = (const EvalType &right);

public:
  bool is_valid_; /**< Whether the value is valid */
};
}
}

#endif  // CT_COMMON_EVAL_TYPE_H_
