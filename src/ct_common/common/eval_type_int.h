//===----- ct_common/common/eval_type_int.h ---------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for int evaluation type
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_EVAL_TYPE_INT_H_
#define CT_COMMON_EVAL_TYPE_INT_H_

#include <ct_common/common/eval_type.h>

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
