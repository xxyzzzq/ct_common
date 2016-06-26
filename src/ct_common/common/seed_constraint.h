//===----- ct_common/common/seed_constraint.h -------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for constraint seeds
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_SEED_CONSTRAINT_H_
#define CT_COMMON_SEED_CONSTRAINT_H_

#include "ct_common/common/constraint.h"
#include "ct_common/common/seed.h"

namespace ct {
namespace common {
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
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_SEED_CONSTRAINT_H_
