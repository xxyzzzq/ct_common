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
  bool is_valid_;  
};
}
}

#endif  // CT_COMMON_EVAL_TYPE_H_
