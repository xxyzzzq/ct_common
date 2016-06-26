//===----- ct_common/common/constraint_l_iff.h ------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for atomic logical constraints
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_CONSTRAINT_L_ATOM_H_
#define CT_COMMON_CONSTRAINT_L_ATOM_H_

#include <memory>
#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint_l.h"
#include "ct_common/common/paramspec.h"

namespace ct {
namespace common {
/**
 * Base class for atom constraints (i.e. no sub-constraints or sub-expressions)
 */
class DLL_EXPORT Constraint_L_Atom : public Constraint_L {
public:
  Constraint_L_Atom(void);
  Constraint_L_Atom(const Constraint_L_Atom &from);
  Constraint_L_Atom &operator = (const Constraint_L_Atom &right);
  virtual ~Constraint_L_Atom(void) = 0;

public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);

};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_L_ATOM_H_
