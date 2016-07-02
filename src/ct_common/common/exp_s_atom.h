// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_S_ATOM_H_
#define CT_COMMON_COMMON_EXP_S_ATOM_H_

#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_s.h"
#include "ct_common/common/paramspec.h"

namespace ct_common {

// The base class for atomic string expressions.
class DLL_EXPORT Exp_S_Atom : public Exp_S {
 public:
  Exp_S_Atom(void);
  Exp_S_Atom(const Exp_S_Atom &from);
  Exp_S_Atom &operator=(const Exp_S_Atom &right);
  virtual ~Exp_S_Atom(void) = 0;

 public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_S_ATOM_H_
