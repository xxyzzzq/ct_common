// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/tuplepool.h"

namespace ct_common {

namespace {

template <class T>
inline void hash_combine(std::size_t seed, const T& v) {
  std::hash<T> hasher;
  seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

}  // anonymous namespace

TuplePool::TuplePool() = default;

TuplePool::TuplePool(const TuplePool& from) = default;

TuplePool& TuplePool::operator=(const TuplePool& right) = default;

TuplePool::~TuplePool() = default;

std::size_t TupleHasher::operator()(const Tuple& tuple) const {
  std::size_t result = 0;
  for (const PVPair& pv : tuple) {
    hash_combine(result, pv.pid);
    hash_combine(result, pv.vid);
  }
  return result;
}

}  // namespace ct_common
