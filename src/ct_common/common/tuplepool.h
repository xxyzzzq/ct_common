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

#include <set>
#include <vector>
#include <ct_common/common/tuple.h>

namespace ct {
namespace common {
class TuplePool {
  public:
    TuplePool(void);
    TuplePool(const TuplePool& from);
    TuplePool& operator = (const TuplePool& right);
    ~TuplePool(void);
    
    bool query(const Tuple &tuple);  // return true if the tuple is in the set
    void add(const Tuple &tuple);  // add the tuple into the set
    void remove(const Tuple &tuple);  // put tuple out the set
    std::size_t size(void) const;
        
    const std::set<Tuple> &getTuples(void) const;
    
  private:
    std::set<Tuple> tuple_set_;  // tuple in the set <-> tuple in the map
                                      // the int value has no use
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_TUPLEPOOL_H_
