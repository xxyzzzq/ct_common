//===----- ct_common/common/constraint_l.h ----------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the base class for logical constraints,
// i.e. constraints taking logical expressions as operands
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_CONSTRAINT_L_H_
#define CT_COMMON_CONSTRAINT_L_H_

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint.h"

namespace ct {
namespace common {
/**
 * Base class for logical constraints
 */
class DLL_EXPORT Constraint_L : public Constraint {
 public:
  Constraint_L(void);
  Constraint_L(const Constraint_L &from);
  Constraint_L &operator=(const Constraint_L &right);
  virtual ~Constraint_L(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_L_H_
