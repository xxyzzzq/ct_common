// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_SEED_CONSTRAINT_H_
#define CT_COMMON_COMMON_SEED_CONSTRAINT_H_

#include <vector>

#include "ct_common/common/constraint.h"
#include "ct_common/common/seed.h"

namespace ct_common {

class DLL_EXPORT Seed_Constraint : public Seed {
 public:
  Seed_Constraint(void);
  Seed_Constraint(const Seed_Constraint &);
  Seed_Constraint &operator=(const Seed_Constraint &right);
  virtual ~Seed_Constraint(void);

 public:
  const std::shared_ptr<Constraint> &get_constraint(void) const {
    return this->constraint_;
  }
  std::shared_ptr<Constraint> &the_constraint(void) {
    return this->constraint_;
  }
  virtual EvalType_Bool IsMatch(
      const Assignment &assignment,
      const std::vector<std::shared_ptr<ParamSpec> > &paramspecs);

 private:
  std::shared_ptr<Constraint> constraint_; /**< The inner constraint */
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_SEED_CONSTRAINT_H_
