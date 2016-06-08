//===----- ct_common/common/assignment.h ------------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the base class for assignments, which is inherited
// by tuples and test cases
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_ASSIGNMENT_H_
#define CT_COMMON_ASSIGNMENT_H_

#include <vector>
#include <memory>
#include <ct_common/common/utils.h>

namespace ct {
namespace common {

/** Base class for parameter assignments */
class DLL_EXPORT Assignment
{
public:
  Assignment(void);
  Assignment(const Assignment &from);
  Assignment &operator =(const Assignment &right);
  virtual ~Assignment(void) = 0;

  /** whether the assignment contains a parameter */
  virtual bool IsContainParam(std::size_t pid) const = 0;
  /** return the value for the given pid */
  virtual std::size_t GetValue(std::size_t pid) const = 0;
  /** check the assignment is a sub-assignment of another one */
  virtual bool IsSubAssignmentOf(const Assignment &assignment) const = 0;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_ASSIGNMENT_H_
