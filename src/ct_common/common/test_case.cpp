// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/test_case.h"

#include "ct_common/base/defs.h"

namespace ct_common {

TestCase::TestCase() = default;

TestCase::TestCase(const TestCase& from) = default;

TestCase& TestCase::operator=(const TestCase& right) = default;

TestCase::~TestCase() = default;

bool TestCase::IsContainParam(std::size_t pid) const {
  return pid < size();
}

std::size_t TestCase::GetValue(std::size_t pid) const {
  if (IsContainParam(pid)) {
    return (*this)[pid];
  }
  return PID_BOUND;
}

bool TestCase::IsSubAssignmentOf(const Assignment& assignment) const {
  for (std::size_t i = 0; i < size(); ++i) {
    if (!assignment.IsContainParam(i) || assignment.GetValue(i) != (*this)[i]) {
      return false;
    }
  }
  return true;
}

}  // namespace ct_common
