// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_BASE_DEFS_H_
#define CT_COMMON_BASE_DEFS_H_

#include <cstdlib>

namespace ct_common {

// Upper bound for parameter ids, also for not-found parameter id's
const std::size_t PID_BOUND = std::size_t(-1);

// Upper bound for value ids, also for not-found value id's
const std::size_t VID_BOUND = std::size_t(-1);

}  // namespace ct_common

#endif  // CT_COMMON_BASE_DEFS_H_
