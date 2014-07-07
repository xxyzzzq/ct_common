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
/**
 * The class for a set of tuples
 */
class TuplePool {
public:
	TuplePool(void);
	TuplePool(const TuplePool& from);
	TuplePool& operator = (const TuplePool& right);
	~TuplePool(void);

	/** Whether the tuple is in the set */
	bool query(const Tuple &tuple);
	/** Add tuple */
	void add(const Tuple &tuple);
	/** Remove tuple */
	void remove(const Tuple &tuple);
	std::size_t size(void) const;
        
	const std::set<Tuple> &getTuples(void) const;
    
private:
	std::set<Tuple> tuple_set_;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_TUPLEPOOL_H_
