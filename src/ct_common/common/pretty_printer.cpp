// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/pretty_printer.h"

#include "ct_common/common/pvpair.h"
#include "ct_common/common/test_case.h"
#include "ct_common/common/tuple.h"

std::ostream& operator<<(std::ostream& os, const ct_common::PVPair& pvpair) {
  os << "<" << pvpair.pid << ",";
  if (pvpair.vid == ct_common::VID_BOUND) {
    os << "-";
  } else {
    os << pvpair.vid;
  }
  os << ">";
  return os;
}

std::ostream& operator<<(std::ostream& os, const ct_common::Tuple& tuple) {
  os << "(";
  for (std::size_t i = 0; i < tuple.size(); ++i) {
    os << tuple[i];
  }
  os << ")";
  return os;
}

std::ostream& operator<<(std::ostream& os, const ct_common::TestCase& test_case) {
  os << "(";
  for (std::size_t i = 0; i < test_case.size(); ++i) {
    if (i != 0) {
      os << ",";
    }
    if (test_case[i] == ct_common::VID_BOUND) {
      os << "-";
    } else {
      os << test_case[i];
    }
  }
  os << ")";
  return os;
}
