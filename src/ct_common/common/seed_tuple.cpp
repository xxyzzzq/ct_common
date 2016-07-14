// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/seed_tuple.h"

namespace ct_common {

Seed_Tuple::Seed_Tuple() = default;

Seed_Tuple::Seed_Tuple(const Seed_Tuple& from) = default;

Seed_Tuple& Seed_Tuple::operator=(
    const Seed_Tuple& right) = default;

Seed_Tuple::~Seed_Tuple() = default;

optional<bool> Seed_Tuple::IsMatch(
    const Assignment& assignment,
    const std::vector<std::shared_ptr<ParamSpec> >& paramspecs) {
  return tuple_.IsSubAssignmentOf(assignment);
}

}  // namespace ct_common
