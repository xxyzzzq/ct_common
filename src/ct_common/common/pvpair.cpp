// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/pvpair.h"

namespace ct_common {

PVPair::PVPair(std::size_t pid, std::size_t vid)
    : pid(pid), vid(vid) {}

PVPair::PVPair(const PVPair& from) = default;

PVPair& PVPair::operator=(const PVPair& right) = default;

PVPair::~PVPair() = default;

bool PVPair::operator<(const PVPair& right) const {
  return (pid < right.pid ||
          (pid == right.pid && vid < right.vid));
}

bool PVPair::operator==(const PVPair& right) const {
  return (pid == right.pid && vid == right.vid);
}

bool PVPair::operator!=(const PVPair& right) const {
  return !operator==(right);
}

}  // namespace ct_common
