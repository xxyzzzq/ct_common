// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_SEED_CONSTRAINT_H_
#define CT_COMMON_COMMON_SEED_CONSTRAINT_H_

#include <vector>

#include "ct_common/common/constraint.h"
#include "ct_common/common/seed.h"

namespace ct_common {

class DLL_EXPORT Seed_Constraint : public Seed {
 public:
  Seed_Constraint();
  Seed_Constraint(const Seed_Constraint& from);
  Seed_Constraint& operator=(const Seed_Constraint& right);
  ~Seed_Constraint() override;

 public:
  const std::shared_ptr<Constraint>& get_constraint() const {
    return constraint_;
  }
  std::shared_ptr<Constraint>& the_constraint() {
    return constraint_;
  }
  optional<bool> IsMatch(
      const Assignment& assignment,
      const std::vector<std::shared_ptr<ParamSpec> >& paramspecs) override;

 private:
  std::shared_ptr<Constraint> constraint_; /**< The inner constraint */
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_SEED_CONSTRAINT_H_
