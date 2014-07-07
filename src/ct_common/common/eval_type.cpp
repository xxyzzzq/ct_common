//===----- ct_common/common/eval_type.cpp -----------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class EvalType
//
//===----------------------------------------------------------------------===//

#include <ct_common/common/eval_type.h>

using namespace ct::common;

EvalType::EvalType(void)
    : is_valid_(false) {
}

EvalType::EvalType(bool is_valid)
    : is_valid_(is_valid) {
}

EvalType::EvalType(const EvalType &from)
    : is_valid_(from.is_valid_) {
}

EvalType::~EvalType(void) {
}

EvalType &EvalType::operator =(const EvalType &right) {
  this->is_valid_ = right.is_valid_;
  return *this;
}
