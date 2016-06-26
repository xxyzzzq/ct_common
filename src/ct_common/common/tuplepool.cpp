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

#include "ct_common/common/tuplepool.h"

using namespace ct::common;

namespace {
template <class T>
inline void hash_combine(std::size_t& seed, const T& v) {
  std::hash<T> hasher;
  seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
}

TuplePool::TuplePool(void) : std::unordered_set<Tuple, TupleHasher>() {}

TuplePool::TuplePool(const TuplePool& from)
    : std::unordered_set<Tuple, TupleHasher>(from) {}

TuplePool& TuplePool::operator=(const TuplePool& right) {
  std::unordered_set<Tuple, TupleHasher>::operator=(right);
  return *this;
}

TuplePool::~TuplePool(void) {}

std::size_t TupleHasher::operator()(const ct::common::Tuple& tuple) const {
  std::size_t result = 0;
  for (Tuple::const_iterator it = tuple.begin(), ie = tuple.end(); it != ie;
       ++it) {
    hash_combine(result, it->pid_);
    hash_combine(result, it->vid_);
  }
  return result;
}
