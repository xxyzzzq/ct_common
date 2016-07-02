// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_PRETTY_PRINTER_H_
#define CT_COMMON_COMMON_PRETTY_PRINTER_H_

#include <iostream>

namespace ct_common {

class PVPair;
class Tuple;
class TestCase;

}  // namespace ct_common

std::ostream &operator<<(std::ostream &os, const ct::common::PVPair &pvpair);
std::ostream &operator<<(std::ostream &os, const ct::common::Tuple &tuple);
std::ostream &operator<<(std::ostream &os,
                         const ct::common::TestCase &test_case);

#endif  // CT_COMMON_COMMON_PRETTY_PRINTER_H_
