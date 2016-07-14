// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/seed_constraint.h"

namespace ct_common {

Seed_Constraint::Seed_Constraint() = default;

Seed_Constraint::Seed_Constraint(const Seed_Constraint& from) = default;

Seed_Constraint& Seed_Constraint::operator=(
    const Seed_Constraint& right) = default;

Seed_Constraint::~Seed_Constraint() = default;

optional<bool> Seed_Constraint::IsMatch(
    const Assignment& assignment,
    const std::vector<std::shared_ptr<ParamSpec> >& paramspecs) {
  return constraint_->Evaluate(paramspecs, assignment);
}

}  // namespace ct_common
