#ifndef PRETTY_PRINTER_H_
#define PRETTY_PRINTER_H_
#include <iostream>

namespace ct {
namespace common {
class PVPair;
class Tuple;
class TestCase;
}
}

std::ostream &operator<<(std::ostream &os, const ct::common::PVPair &pvpair);
std::ostream &operator<<(std::ostream &os, const ct::common::Tuple &tuple);
std::ostream &operator<<(std::ostream &os,
                         const ct::common::TestCase &test_case);

#endif  // PRETTY_PRINTER_H_
