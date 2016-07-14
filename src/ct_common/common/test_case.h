// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_TEST_CASE_H_
#define CT_COMMON_COMMON_TEST_CASE_H_

#include <memory>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/assignment.h"

namespace ct_common {

class ParamSpec;

// The class for test cases
class DLL_EXPORT TestCase : public Assignment, private std::vector<size_t> {
 private:
  typedef std::vector<size_t> impl_type;

 public:
  TestCase();
  TestCase(const TestCase& from);
  TestCase& operator=(const TestCase& right);
  ~TestCase() override;

  bool IsContainParam(std::size_t pid) const override;
  std::size_t GetValue(std::size_t pid) const override;
  bool IsSubAssignmentOf(const Assignment& assignment) const override;

  using impl_type::iterator;
  using impl_type::const_iterator;
  using impl_type::begin;
  using impl_type::rbegin;
  using impl_type::end;
  using impl_type::rend;
  using impl_type::assign;
  using impl_type::push_back;
  using impl_type::pop_back;
  using impl_type::resize;
  using impl_type::size;
  using impl_type::empty;
  using impl_type::operator[];
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_TEST_CASE_H_
