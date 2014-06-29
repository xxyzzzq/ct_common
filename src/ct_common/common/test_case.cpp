#include <ct_common/common/defs.h>
#include "test_case.h"

using namespace ct::common;

TestCase::TestCase(void)
    : Assignment(), values_() {
}

TestCase::TestCase(const TestCase &from)
    : Assignment(from), values_(from.values_) {
}

TestCase::~TestCase(void) {
}

TestCase &TestCase::operator =(const TestCase &right) {
  Assignment::operator =(right);
  this->values_ = right.values_;
  return *this;
}

bool TestCase::IsContainParam(std::size_t pid) const {
  return pid < this->values_.size();
}

std::size_t TestCase::GetValue(std::size_t pid) const {
  if (this->IsContainParam(pid)) {
    return (*this)[pid];
  }
  return PID_BOUND;
}

bool TestCase::IsSubAssignmentOf(const Assignment &assignment) const {
  for (std::size_t i = 0; i < this->values_.size(); ++i) {
    if (!assignment.IsContainParam(i) || assignment.GetValue(i) != (*this)[i]) {
      return false;
    }
  }
  return true;
}
