//===----- ct_common/common/pvpair.h ----------------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for parameter-value pairs
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_PVPAIR_H_
#define CT_COMMON_PVPAIR_H_

#include <ct_common/common/utils.h>
#include <ct_common/common/defs.h>

namespace ct {
namespace common {

class DLL_EXPORT PVPair
{
public:
  PVPair(std::size_t pid = PID_BOUND, std::size_t vid = VID_BOUND);
  PVPair(const PVPair&);
  PVPair &operator = (const PVPair &right);
  ~PVPair(void);  // non-virtual for performance

  bool operator < (const PVPair &right) const;
  bool operator == (const PVPair &right) const;
  bool operator != (const PVPair &right) const;
	
public:
  std::size_t pid_;  // parameter index
  std::size_t vid_;  // value index
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_PVPAIR_H_
