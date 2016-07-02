// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_ASSIGNMENT_H_
#define CT_COMMON_COMMON_ASSIGNMENT_H_

#include <memory>
#include <vector>

#include "ct_common/base/utils.h"

namespace ct_common {

// Base class for parameter assignments
class DLL_EXPORT Assignment {
 public:
  Assignment(void);
  Assignment(const Assignment &from);
  Assignment &operator=(const Assignment &right);
  virtual ~Assignment(void) = 0;

  /** whether the assignment contains a parameter */
  virtual bool IsContainParam(std::size_t pid) const = 0;
  /** return the value for the given pid */
  virtual std::size_t GetValue(std::size_t pid) const = 0;
  /** check the assignment is a sub-assignment of another one */
  virtual bool IsSubAssignmentOf(const Assignment &assignment) const = 0;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_ASSIGNMENT_H_
