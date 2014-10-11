//===----- ct_common/common/tuplepool.cpp -----------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class TuplePool
//
//===----------------------------------------------------------------------===//


#include <ct_common/common/tuplepool.h>

using namespace ct::common;

TuplePool::TuplePool(void)
    : tuple_set_() {
}

TuplePool::TuplePool(const TuplePool& from)
    : tuple_set_(from.tuple_set_) {
}

TuplePool& TuplePool::operator = (const TuplePool& right) {
  this->tuple_set_ = right.tuple_set_;
  return *this;
}

TuplePool::~TuplePool(void) {
}

bool TuplePool::query(const Tuple &tuple) const {
  std::set<Tuple>::const_iterator iter = this->tuple_set_.find(tuple);
  if (iter == this->tuple_set_.end()) {
    return false;
  }
  return true;
}

void TuplePool::add(const Tuple &tuple) {
  this->tuple_set_.insert(tuple);
}

void TuplePool::remove(const Tuple &tuple) {
  this->tuple_set_.erase(tuple);
}

std::size_t TuplePool::size(void) const {
  return this->tuple_set_.size();
}

const std::set<Tuple> &TuplePool::getTuples(void) const {
  return this->tuple_set_;
}

