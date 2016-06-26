//===----- ct_common/common/test_case.h -------------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for test cases
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_TEST_CASE_H_
#define CT_COMMON_TEST_CASE_H_

#include <vector>
#include <memory>

#include "ct_common/base/utils.h"
#include "ct_common/common/assignment.h"

namespace ct {
namespace common {
class ParamSpec;

/**
 * The class for test cases
 */
class DLL_EXPORT TestCase : public Assignment, private std::vector<size_t>
{
private:
  typedef std::vector<size_t> impl_type;
public:
  TestCase(void);
  TestCase(const TestCase &from);
  TestCase &operator =(const TestCase &right);
  virtual ~TestCase(void);

  virtual bool IsContainParam(std::size_t pid) const;
  virtual std::size_t GetValue(std::size_t pid) const;
  virtual bool IsSubAssignmentOf(const Assignment &assignment) const;

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
  using impl_type::operator [];
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_TEST_CASE_H_
