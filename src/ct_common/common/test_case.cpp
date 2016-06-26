//===----- ct_common/common/test_case.cpp -----------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class TestCase
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/test_case.h"

#include "ct_common/base/defs.h"

using namespace ct::common;

TestCase::TestCase(void)
  : Assignment(), std::vector<std::size_t>() {
}

TestCase::TestCase(const TestCase &from)
  : Assignment(from), std::vector<std::size_t>(from) {
}

TestCase::~TestCase(void) {
}

TestCase &TestCase::operator =(const TestCase &right) {
  Assignment::operator =(right);
  std::vector<std::size_t>::operator =(right);
  return *this;
}

bool TestCase::IsContainParam(std::size_t pid) const {
  return pid < this->size();
}

std::size_t TestCase::GetValue(std::size_t pid) const {
  if (this->IsContainParam(pid)) {
    return (*this)[pid];
  }
  return PID_BOUND;
}

bool TestCase::IsSubAssignmentOf(const Assignment &assignment) const {
  for (std::size_t i = 0; i < this->size(); ++i) {
    if (!assignment.IsContainParam(i) || assignment.GetValue(i) != (*this)[i]) {
      return false;
    }
  }
  return true;
}
