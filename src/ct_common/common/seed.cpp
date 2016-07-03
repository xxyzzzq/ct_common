// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/seed.h"

namespace ct_common {

Seed::Seed(std::size_t sid, bool is_starter)
    : id_(sid), is_starter_(is_starter) {}

Seed& Seed::operator=(const Seed& right) = default;

Seed::Seed(const Seed& from) = default;

Seed::~Seed() = default;

optional<bool> Seed::IsMatch(
    const Assignment& assignment,
    const std::vector<std::shared_ptr<ParamSpec> >& paramspecs) {
  return nullopt;
}

}  // namespace ct_common
