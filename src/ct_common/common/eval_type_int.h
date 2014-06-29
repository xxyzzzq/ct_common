#ifndef CT_COMMON_EVAL_TYPE_INT_H_
#define CT_COMMON_EVAL_TYPE_INT_H_

#include "eval_type.h"

namespace ct {
namespace common {
class EvalType_Double;

class EvalType_Int : public EvalType {
public:
  EvalType_Int(void);
  EvalType_Int(int value, bool is_valid);
  EvalType_Int(const EvalType_Int &from);
  EvalType_Int(const EvalType_Double &from);

  virtual ~EvalType_Int(void);
  EvalType_Int &operator = (const EvalType_Int &right);
  EvalType_Int &operator = (const EvalType_Double &right);

public:
  int value_;
};
}
}

#endif  // CT_COMMON_EVAL_TYPE_INT_H_
