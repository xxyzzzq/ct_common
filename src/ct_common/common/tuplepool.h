//===----- ct_common/common/tuplepool.h -------------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for tuple pools
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_TUPLEPOOL_H_
#define CT_COMMON_TUPLEPOOL_H_

#include <unordered_set>
#include <vector>
#include "ct_common/base/utils.h"
#include "ct_common/common/tuple.h"

namespace ct {
namespace common {
/**
 * The class for a set of tuples
 */
struct DLL_EXPORT TupleHasher : public std::unary_function<Tuple, std::size_t> {
  std::size_t operator()(const Tuple& tuple) const;
};

class DLL_EXPORT TuplePool : private std::unordered_set<Tuple, TupleHasher> {
 private:
  typedef std::unordered_set<Tuple, TupleHasher> impl_type;

 public:
  TuplePool(void);
  TuplePool(const TuplePool& from);
  TuplePool& operator=(const TuplePool& right);
  ~TuplePool(void);

  using impl_type::begin;
  using impl_type::end;
  using impl_type::const_iterator;
  using impl_type::iterator;
  using impl_type::size;
  using impl_type::empty;
  using impl_type::clear;
  using impl_type::count;
  using impl_type::insert;
  using impl_type::erase;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_TUPLEPOOL_H_
