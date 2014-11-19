#include <ct_common/common/pvpair.h>
#include <ct_common/common/tuple.h>
#include <ct_common/common/test_case.h>
#include "pretty_printer.h"

using namespace ct::common;

std::ostream &operator << (std::ostream &os, const PVPair &pvpair) {
  os << "<" << pvpair.pid_ << "," << pvpair.vid_ << ">";
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
    os << test_case[i];
  }
  os << ")";
  return os;
}
