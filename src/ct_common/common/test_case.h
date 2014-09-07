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
#include <boost/shared_ptr.hpp>
#include <ct_common/common/utils.h>
#include <ct_common/common/assignment.h>

namespace ct {
namespace common {
class ParamSpec;

/**
 * The class for test cases
 */
class DLL_EXPORT TestCase : public Assignment, private std::vector<size_t>
{
public:
  TestCase(void);
  TestCase(const TestCase &from);
  TestCase &operator =(const TestCase &right);
  virtual ~TestCase(void);

  virtual bool IsContainParam(std::size_t pid) const;
  virtual std::size_t GetValue(std::size_t pid) const;
  virtual bool IsSubAssignmentOf(const Assignment &assignment) const;

  using std::vector<size_t>::iterator;
  using std::vector<size_t>::const_iterator;
  using std::vector<size_t>::assign;
  using std::vector<size_t>::push_back;
  using std::vector<size_t>::pop_back;
  using std::vector<size_t>::resize;
  using std::vector<size_t>::size;
  using std::vector<size_t>::empty;
  using std::vector<size_t>::operator [];
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_TEST_CASE_H_
