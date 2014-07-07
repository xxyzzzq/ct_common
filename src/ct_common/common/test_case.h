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

// class for TestCase
class DLL_EXPORT TestCase : public Assignment
{
public:
  TestCase(void);
  TestCase(const TestCase &from);
  TestCase &operator =(const TestCase &right);
  virtual ~TestCase(void);

  virtual bool IsContainParam(std::size_t pid) const;
  virtual std::size_t GetValue(std::size_t pid) const;
  virtual bool IsSubAssignmentOf(const Assignment &assignment) const;
  
  const std::vector<std::size_t> &getValues(void) const { return this->values_; }
  std::vector<std::size_t> &theValues(void) { return this->values_; }
  
  std::size_t size(void) const { return this->values_.size(); }
  const std::size_t &operator [] (std::size_t index) const { return this->values_[index]; }
  std::size_t &operator [] (std::size_t index) {return this->values_[index]; }
  
private:
  std::vector<std::size_t> values_;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_TEST_CASE_H_
