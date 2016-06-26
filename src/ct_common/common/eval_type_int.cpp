//===----- ct_common/common/eval_type_int.cpp -------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class EvalType_Int
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/eval_type_int.h"
#include "ct_common/common/eval_type_double.h"

using namespace ct::common;

EvalType_Int::EvalType_Int(void) : EvalType(), value_(0) {}

EvalType_Int::EvalType_Int(int value, bool is_valid)
    : EvalType(is_valid), value_(value) {}

EvalType_Int::EvalType_Int(const EvalType_Int &from)
    : EvalType(from), value_(from.value_) {}

EvalType_Int::EvalType_Int(const EvalType_Double &from)
    : EvalType(from), value_((int)from.value_) {}

EvalType_Int::~EvalType_Int(void) {}

EvalType_Int &EvalType_Int::operator=(const EvalType_Int &right) {
  EvalType::operator=(right);
  this->value_ = right.value_;
  return *this;
}

EvalType_Int &EvalType_Int::operator=(const EvalType_Double &right) {
  EvalType::operator=(right);
  this->value_ = (int)right.value_;
  return *this;
}
