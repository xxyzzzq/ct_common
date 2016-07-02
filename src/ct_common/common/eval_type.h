// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EVAL_TYPE_H_
#define CT_COMMON_COMMON_EVAL_TYPE_H_

namespace ct_common {

// Base class for TreeNode evaluation return type
class EvalType {
 public:
  EvalType(void);
  explicit EvalType(bool is_valid);
  EvalType(const EvalType &from);
  virtual ~EvalType(void) = 0;

  EvalType &operator=(const EvalType &right);

 public:
  bool is_valid_; /**< Whether the value is valid */
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EVAL_TYPE_H_
