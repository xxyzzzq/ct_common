// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_PVPAIR_H_
#define CT_COMMON_COMMON_PVPAIR_H_

#include "ct_common/base/defs.h"
#include "ct_common/base/utils.h"

namespace ct_common {

// Parameter-value pair, representing an assignment to a parameter
class DLL_EXPORT PVPair final {
 public:
  explicit PVPair(std::size_t pid = PID_BOUND, std::size_t vid = VID_BOUND);
  PVPair(const PVPair& );
  PVPair& operator=(const PVPair& right);
  ~PVPair();

  bool operator<(const PVPair& right) const;
  bool operator==(const PVPair& right) const;
  bool operator!=(const PVPair& right) const;

 public:
  std::size_t pid_; /**< parameter id */
  std::size_t vid_; /**< value id */
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_PVPAIR_H_
