//===----- ct_common/common/constraints.h -----------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file includes the header files of all constraint classes 
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_CONSTRAINTS_H_
#define CT_COMMON_CONSTRAINTS_H_

#include <ct_common/common/constraint.h>

#include <ct_common/common/constraint_a.h>
#include <ct_common/common/constraint_a_binary.h>
#include <ct_common/common/constraint_a_eq.h>
#include <ct_common/common/constraint_a_ge.h>
#include <ct_common/common/constraint_a_gt.h>
#include <ct_common/common/constraint_a_le.h>
#include <ct_common/common/constraint_a_lt.h>
#include <ct_common/common/constraint_a_ne.h>

#include <ct_common/common/constraint_l.h>
#include <ct_common/common/constraint_l_and.h>
#include <ct_common/common/constraint_l_binary.h>
#include <ct_common/common/constraint_l_cbool.h>
#include <ct_common/common/constraint_l_imply.h>
#include <ct_common/common/constraint_l_iff.h>
#include <ct_common/common/constraint_l_not.h>
#include <ct_common/common/constraint_l_or.h>
#include <ct_common/common/constraint_l_param.h>
#include <ct_common/common/constraint_l_atom.h>
#include <ct_common/common/constraint_l_unary.h>
#include <ct_common/common/constraint_l_xor.h>
#include <ct_common/common/constraint_l_ivld.h>

#include <ct_common/common/constraint_s.h>
#include <ct_common/common/constraint_s_binary.h>
#include <ct_common/common/constraint_s_eq.h>
#include <ct_common/common/constraint_s_ne.h>

#endif  // CT_COMMON_CONSTRAINTS_H_
