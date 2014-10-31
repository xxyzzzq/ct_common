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
    : boost::unordered_set<Tuple, TupleHasher>() {
}

TuplePool::TuplePool(const TuplePool& from)
    : boost::unordered_set<Tuple, TupleHasher>(from) {
}

TuplePool& TuplePool::operator = (const TuplePool& right) {
  boost::unordered_set<Tuple, TupleHasher>::operator = (right);
  return *this;
}

TuplePool::~TuplePool(void) {
}

std::size_t TupleHasher::operator ()(const ct::common::Tuple &tuple) const {
  std::size_t result = 0;
  for (Tuple::const_iterator it = tuple.begin(), ie = tuple.end(); it != ie; ++it) {
    boost::hash_combine(result, it->pid_);
    boost::hash_combine(result, it->vid_);
  }
  return result;
}
