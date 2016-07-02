// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_SEED_TUPLE_H_
#define CT_COMMON_COMMON_SEED_TUPLE_H_

#include <vector>

#include "ct_common/common/seed.h"
#include "ct_common/common/tuple.h"

namespace ct_common {

class DLL_EXPORT Seed_Tuple : public Seed {
 public:
  Seed_Tuple(void);
  Seed_Tuple(const Seed_Tuple &);
  Seed_Tuple &operator=(const Seed_Tuple &right);
  virtual ~Seed_Tuple(void);

 public:
  const Tuple &get_tuple(void) const { return this->tuple_; }
  Tuple &the_tuple(void) { return this->tuple_; }
  virtual EvalType_Bool IsMatch(
      const Assignment &assignment,
      const std::vector<std::shared_ptr<ParamSpec> > &paramspecs);

 private:
  Tuple tuple_; /**< The inner tuple */
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_SEED_TUPLE_H_
