//===----- ct_common/common/eval_type_double.h ------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for double evaluation type
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_EVAL_TYPE_DOUBLE_H_
#define CT_COMMON_EVAL_TYPE_DOUBLE_H_

#include <ct_common/common/eval_type.h>

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
