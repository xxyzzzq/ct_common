//===----- ct_common/common/defs.h ------------------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains some basic definitions
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_DEFS_H_
#define CT_COMMON_DEFS_H_

#include <cstdlib>

namespace ct {
namespace common {
const std::size_t PID_BOUND = std::size_t(-1); /**< Upper bound for parameter
                                                  ids, also for not-found
                                                  parameter id's */
const std::size_t VID_BOUND = std::size_t(
    -1); /**< Upper bound for value ids, also for not-found value id's */
}
}

#endif  // CT_COMMON_DEFS_H_
