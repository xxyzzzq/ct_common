//===----- ct_common/common/exp_s_atom.h ------------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the base class for atom string expressions
//
//===----------------------------------------------------------------------===//


#ifndef CT_COMMON_EXP_S_ATOM_H_
#define CT_COMMON_EXP_S_ATOM_H_

#include <ct_common/common/utils.h>
#include <ct_common/common/exp_s.h>
#include <ct_common/common/paramspec.h>

namespace ct {
namespace common {
class DLL_EXPORT Exp_S_Atom : public Exp_S {
public:
  Exp_S_Atom(void);
  Exp_S_Atom(const Exp_S_Atom &from);
  Exp_S_Atom &operator = (const Exp_S_Atom &right);
  virtual ~Exp_S_Atom(void) = 0;

public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_EXP_S_ATOM_H_
