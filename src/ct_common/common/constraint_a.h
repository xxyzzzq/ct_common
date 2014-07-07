//===----- ct_common/common/constraint_a.h ----------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the base class for arithmetic constraints
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_CONSTRAINT_A_H_
#define CT_COMMON_CONSTRAINT_A_H_

#include <ct_common/common/utils.h>
#include <ct_common/common/constraint.h>

namespace ct {
namespace common {
class DLL_EXPORT Constraint_A : public Constraint {
public:
  Constraint_A(void);
  Constraint_A(const Constraint_A &from);
  Constraint_A &operator = (const Constraint_A &right);
  virtual ~Constraint_A(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_A_H_
