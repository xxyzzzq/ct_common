#ifndef CT_COMMON_EVAL_TYPE_DOUBLE_H_
#define CT_COMMON_EVAL_TYPE_DOUBLE_H_

#include "eval_type.h"

namespace ct {
namespace common {
class EvalType_Int;
class EvalType_Double : public EvalType {
public:
  EvalType_Double(void);
  EvalType_Double(double value, bool is_valid);
  EvalType_Double(const EvalType_Double &from);
  EvalType_Double(const EvalType_Int &from);
  virtual ~EvalType_Double(void);
  EvalType_Double &operator = (const EvalType_Double &right);
  EvalType_Double &operator = (const EvalType_Int &right);

public:
  double value_;
};
}
}

#endif  // CT_COMMON_EVAL_TYPE_DOUBLE_H_
