// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_A_ATOM_H_
#define CT_COMMON_COMMON_EXP_A_ATOM_H_

#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_a.h"
#include "ct_common/common/paramspec.h"

namespace ct_common {

// Base class for atomic arithmetical expressions, i.e. no contained
// sub-expressions.
class DLL_EXPORT Exp_A_Atom : public Exp_A {
 public:
  Exp_A_Atom(void);
  Exp_A_Atom(const Exp_A_Atom &from);
  Exp_A_Atom &operator=(const Exp_A_Atom &right);
  virtual ~Exp_A_Atom(void) = 0;

 public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_A_ATOM_H_
