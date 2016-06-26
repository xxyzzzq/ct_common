//===----- ct_common/common/tuple.cpp ---------------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Tuple
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/tuple.h"
#include <algorithm>
#include "ct_common/common/paramspec.h"

using namespace ct::common;

Tuple::Tuple(void) : Assignment(), std::vector<PVPair>() {}

Tuple::Tuple(const Tuple &from) : Assignment(from), std::vector<PVPair>(from) {}

Tuple::Tuple(const std::vector<PVPair> &from)
    : Assignment(), std::vector<PVPair>(from) {}

Tuple &Tuple::operator=(const Tuple &right) {
  Assignment::operator=(right);
  std::vector<PVPair>::operator=(right);
  return *this;
}

Tuple::~Tuple(void) {}

std::vector<std::size_t> Tuple::get_rel_pids(void) const {
  std::vector<std::size_t> tmp_return;
  for (std::size_t i = 0; i < this->size(); ++i) {
    tmp_return.push_back((*this)[i].pid_);
  }
  return tmp_return;
}

bool Tuple::operator<(const Tuple &right) const {
  if (this->size() < right.size()) {
    return true;
  }
  if (this->size() == right.size()) {
    for (std::size_t i = 0; i < this->size(); ++i) {
      if ((*this)[i] < right[i]) {
        return true;
      }
      if (right[i] < (*this)[i]) {
        return false;
      }
    }
  }
  return false;
}

bool Tuple::operator==(const Tuple &right) const {
  if (this->size() != right.size()) {
    return false;
  }
  for (std::size_t i = 0; i < this->size(); ++i) {
    if ((*this)[i] != right[i]) {
      return false;
    }
  }
  return true;
}

void Tuple::Sort(void) { std::sort(this->begin(), this->end()); }

bool Tuple::IsSubAssignmentOf(const Assignment &assignment) const {
  for (std::size_t i = 0; i < this->size(); ++i) {
    PVPair pvpair = (*this)[i];
    if (!assignment.IsContainParam(pvpair.pid_) ||
        assignment.GetValue(pvpair.pid_) != pvpair.vid_) {
      return false;
    }
  }
  return true;
}

const PVPair *Tuple::Search(std::size_t pid) const {
  if (this->size() == 0 || pid == PID_BOUND) {
    return 0;
  }
  std::size_t low = 0;
  std::size_t high = this->size() - 1;
  while (low + 1 < high) {
    std::size_t mid = low + (high - low) / 2;
    if ((*this)[mid].pid_ > pid) {
      high = mid;
    } else {
      low = mid;
    }
  }
  if ((*this)[low].pid_ == pid) {
    return &(*this)[low];
  }
  if ((*this)[high].pid_ == pid) {
    return &(*this)[high];
  }
  return 0;
}

bool Tuple::to_the_next_tuple(
    std::vector<std::shared_ptr<ParamSpec> > param_specs) {
  if (this->size() == 0) {
    return false;
  }
  this->back().vid_++;
  for (std::size_t i = this->size() - 1; i > 0; i--) {
    if ((*this)[i].vid_ >= param_specs[(*this)[i].pid_]->get_level()) {
      (*this)[i].vid_ = 0;
      (*this)[i - 1].vid_++;
    } else {
      break;
    }
  }
  if ((*this)[0].vid_ >= param_specs[(*this)[0].pid_]->get_level()) {
    (*this)[0].vid_ = 0;
    return false;
  }
  return true;
}

bool Tuple::to_the_next_tuple_with_ivld(
    std::vector<std::shared_ptr<ParamSpec> > param_specs) {
  if (this->size() == 0) {
    return false;
  }
  this->back().vid_++;
  for (std::size_t i = this->size() - 1; i > 0; i--) {
    if ((*this)[i].vid_ >= param_specs[(*this)[i].pid_]->get_level() + 1) {
      (*this)[i].vid_ = 0;
      (*this)[i - 1].vid_++;
    } else {
      break;
    }
  }
  if ((*this)[0].vid_ >= param_specs[(*this)[0].pid_]->get_level() + 1) {
    (*this)[0].vid_ = 0;
    return false;
  }
  return true;
}

bool Tuple::IsContainParam(std::size_t pid) const {
  return (this->Search(pid) != 0);
}

std::size_t Tuple::GetValue(std::size_t pid) const {
  const PVPair *pvpair = this->Search(pid);
  if (pvpair != 0) {
    return pvpair->vid_;
  }
  return VID_BOUND;
}
