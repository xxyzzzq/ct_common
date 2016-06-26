//===----- ct_common/common/eval_type_string.h ------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for string evaluation type
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_EVAL_TYPE_STRING_H_
#define CT_COMMON_EVAL_TYPE_STRING_H_

#include <string>

#include "ct_common/common/eval_type.h"

namespace ct {
namespace common {
class EvalType_String : public EvalType {
 public:
  EvalType_String(void);
  EvalType_String(const std::string &value, bool is_valid);
  EvalType_String(const EvalType_String &from);
  virtual ~EvalType_String(void);
  EvalType_String &operator=(const EvalType_String &right);

 public:
  std::string value_;
};
}
}

#endif  // CT_COMMON_EVAL_TYPE_STRING_H_
