#include "ct_common/common/pvpair.h"
#include "ct_common/common/tuple.h"
#include "ct_common/common/test_case.h"
#include "pretty_printer.h"

using namespace ct::common;

std::ostream &operator << (std::ostream &os, const PVPair &pvpair) {
  os << "<" << pvpair.pid_ << ",";
  if (pvpair.vid_ == VID_BOUND) {
    os << "-";
  } else {
    os << pvpair.vid_;
  }
  os << ">";
  return os;
}

std::ostream &operator << (std::ostream &os, const Tuple &tuple) {
  os << "(";
  for (std::size_t i = 0; i < tuple.size(); ++i) {
    os << tuple[i];
  }
  os << ")";
  return os;
}

std::ostream &operator << (std::ostream &os, const TestCase &test_case) {
  os << "(";
  for (std::size_t i = 0; i < test_case.size(); ++i) {
    if (i != 0) {
      os << ",";
    }
    if (test_case[i] == VID_BOUND) {
      os << "-";
    } else {
      os << test_case[i];
    }
  }
  os << ")";
  return os;
}
