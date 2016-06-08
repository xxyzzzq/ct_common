//===----- ct_common/common/seed.cpp ----------------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Seed
//
//===----------------------------------------------------------------------===//

#include <ct_common/common/seed.h>

using namespace ct::common;

Seed::Seed(std::size_t sid, bool is_starter)
    : id_(sid), is_starter_(is_starter) {
}

Seed::Seed(const Seed &from)
    : id_(from.id_), is_starter_(from.is_starter_) {
}

Seed::~Seed(void) {
}

Seed &Seed::operator = (const Seed &right) {
  this->id_ = right.id_;
  this->is_starter_ = right.is_starter_;
  return (*this);
}

EvalType_Bool Seed::IsMatch(const Assignment &assignment, const std::vector<std::shared_ptr<ParamSpec> > &paramspecs) {
  return EvalType_Bool(false, false);
}
