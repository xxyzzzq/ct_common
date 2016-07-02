// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_CONSTRAINT_L_ATOMIC_H_
#define CT_COMMON_COMMON_CONSTRAINT_L_ATOMIC_H_

#include <memory>
#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint_l.h"
#include "ct_common/common/paramspec.h"

namespace ct_common {

// Base class for atomic constraints (i.e. no sub-constraints or
// sub-expressions)
class DLL_EXPORT Constraint_L_Atom : public Constraint_L {
 public:
  Constraint_L_Atom(void);
  Constraint_L_Atom(const Constraint_L_Atom &from);
  Constraint_L_Atom &operator=(const Constraint_L_Atom &right);
  virtual ~Constraint_L_Atom(void) = 0;

 public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_CONSTRAINT_L_ATOMIC_H_
