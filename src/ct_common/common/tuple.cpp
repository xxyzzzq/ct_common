// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/tuple.h"

#include <algorithm>

#include "ct_common/common/paramspec.h"

namespace ct_common {

Tuple::Tuple() = default;

Tuple::Tuple(const Tuple& from)  = default;

Tuple::Tuple(const std::vector<PVPair>& from)
    : impl_type(from) {
}

Tuple& Tuple::operator=(const Tuple& right) = default;

Tuple::~Tuple() = default;

std::vector<std::size_t> Tuple::get_rel_pids() const {
  std::vector<std::size_t> tmp_return;
  for (std::size_t i = 0; i < size(); ++i) {
    tmp_return.push_back((*this)[i].pid);
  }
  return tmp_return;
}

bool Tuple::operator<(const Tuple& right) const {
  if (size() < right.size()) {
    return true;
  }
  if (size() == right.size()) {
    for (std::size_t i = 0; i < size(); ++i) {
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

bool Tuple::operator==(const Tuple& right) const {
  if (size() != right.size()) {
    return false;
  }
  for (std::size_t i = 0; i < size(); ++i) {
    if ((*this)[i] != right[i]) {
      return false;
    }
  }
  return true;
}

void Tuple::Sort() { std::sort(begin(), end()); }

bool Tuple::IsSubAssignmentOf(const Assignment& assignment) const {
  for (std::size_t i = 0; i < size(); ++i) {
    PVPair pvpair = (*this)[i];
    if (!assignment.IsContainParam(pvpair.pid) ||
        assignment.GetValue(pvpair.pid) != pvpair.vid) {
      return false;
    }
  }
  return true;
}

const PVPair* Tuple::Search(std::size_t pid) const {
  if (size() == 0 || pid == PID_BOUND) {
    return 0;
  }
  std::size_t low = 0;
  std::size_t high = size() - 1;
  while (low + 1 < high) {
    std::size_t mid = low + (high - low) / 2;
    if ((*this)[mid].pid > pid) {
      high = mid;
    } else {
      low = mid;
    }
  }
  if ((*this)[low].pid == pid) {
    return &(*this)[low];
  }
  if ((*this)[high].pid == pid) {
    return &(*this)[high];
  }
  return 0;
}

bool Tuple::ToTheNextTuple(
    std::vector<std::shared_ptr<ParamSpec> > param_specs) {
  if (size() == 0) {
    return false;
  }
  back().vid++;
  for (std::size_t i = size() - 1; i > 0; i--) {
    if ((*this)[i].vid >= param_specs[(*this)[i].pid]->get_level()) {
      (*this)[i].vid = 0;
      (*this)[i - 1].vid++;
    } else {
      break;
    }
  }
  if ((*this)[0].vid >= param_specs[(*this)[0].pid]->get_level()) {
    (*this)[0].vid = 0;
    return false;
  }
  return true;
}

bool Tuple::ToTheNextTupleWithIvld(
    std::vector<std::shared_ptr<ParamSpec> > param_specs) {
  if (size() == 0) {
    return false;
  }
  back().vid++;
  for (std::size_t i = size() - 1; i > 0; i--) {
    if ((*this)[i].vid >= param_specs[(*this)[i].pid]->get_level() + 1) {
      (*this)[i].vid = 0;
      (*this)[i - 1].vid++;
    } else {
      break;
    }
  }
  if ((*this)[0].vid >= param_specs[(*this)[0].pid]->get_level() + 1) {
    (*this)[0].vid = 0;
    return false;
  }
  return true;
}

bool Tuple::IsContainParam(std::size_t pid) const {
  return (Search(pid) != 0);
}

std::size_t Tuple::GetValue(std::size_t pid) const {
  const PVPair* pvpair = Search(pid);
  if (pvpair != 0) {
    return pvpair->vid;
  }
  return VID_BOUND;
}

}  // namespace ct_common
