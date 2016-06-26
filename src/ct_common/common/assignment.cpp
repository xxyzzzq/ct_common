//===----- ct_common/common/assignment.cpp ----------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Assignment
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/assignment.h"

using namespace ct::common;

Assignment::Assignment(void) = default;

Assignment::Assignment(const Assignment &from) = default;

Assignment::~Assignment(void) = default;

Assignment &Assignment::operator=(const Assignment &right) { return *this; }
