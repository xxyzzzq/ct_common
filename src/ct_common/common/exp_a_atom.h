//===----- ct_common/common/exp_a_atom.h ------------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the base class for atomic arithmetic expressions
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_EXP_A_ATOM_H_
#define CT_COMMON_EXP_A_ATOM_H_

#include <ct_common/common/utils.h>
#include <ct_common/common/exp_a.h>
#include <ct_common/common/paramspec.h>

namespace ct {
namespace common {
/**
 * Base class for atomic arithmetical expressions, i.e. no contained sub-expressions
 */
class DLL_EXPORT Exp_A_Atom : public Exp_A {
public:
  Exp_A_Atom(void);
  Exp_A_Atom(const Exp_A_Atom &from);
  Exp_A_Atom &operator = (const Exp_A_Atom &right);
  virtual ~Exp_A_Atom(void) = 0;

public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_EXP_A_ATOM_H_
