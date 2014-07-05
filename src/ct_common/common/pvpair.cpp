#include <ct_common/common/pvpair.h>

using namespace ct::common;

PVPair::PVPair(std::size_t pid, std::size_t vid)
    : pid_(pid), vid_(vid) {
}

PVPair::PVPair(const PVPair &from)
    : pid_(from.pid_), vid_(from.vid_) {
}

PVPair &PVPair::operator = (const PVPair &right) {
  this->pid_ = right.pid_;
  this->vid_ = right.vid_;
  return *this;
}

PVPair::~PVPair(void) {
}

bool PVPair::operator < (const PVPair &right) const {
  return (this->pid_ < right.pid_ ||
          (this->pid_ == right.pid_ && this->vid_ < right.vid_));
}

bool PVPair::operator == (const PVPair &right) const {
  return (this->pid_ == right.pid_ && this->vid_ == right.vid_);
}

bool PVPair::operator != (const PVPair &right) const {
  return !this->operator==(right);
}
