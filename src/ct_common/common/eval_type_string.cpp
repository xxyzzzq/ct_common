//===----- ct_common/common/eval_type_string.cpp ----------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class EvalType_String
//
//===----------------------------------------------------------------------===//

#include <ct_common/common/eval_type_string.h>

using namespace ct::common;

EvalType_String::EvalType_String(void)
  : EvalType(), value_() {
}

EvalType_String::EvalType_String(const std::string &value, bool is_valid)
  : EvalType(is_valid), value_(value) {
}

EvalType_String::EvalType_String(const EvalType_String &from)
  : EvalType(from), value_(from.value_) {
}

EvalType_String::~EvalType_String(void) {
}

EvalType_String &EvalType_String::operator =(const EvalType_String &right) {
  EvalType::operator =(right);
  this->value_ = right.value_;
  return *this;
}
