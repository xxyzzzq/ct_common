// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/assignment.h"

namespace ct_common {

Assignment::Assignment() = default;

Assignment::Assignment(const Assignment& from) = default;

Assignment::~Assignment() = default;

Assignment& Assignment::operator=(const Assignment& right) { return *this; }

}  // namespace ct_common
