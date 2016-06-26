//===----- ct_common/common/strength.h --------------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the type definitions of RawStrengths and Strengths
//
//===----------------------------------------------------------------------===//

#ifndef STRENGTH_H_
#define STRENGTH_H_
#include <utility>
#include <vector>

namespace ct {
namespace common {
typedef std::vector<std::size_t> RawStrength; /** Decomposed strengths */
typedef std::pair<std::vector<std::size_t>, std::size_t>
    Strength; /** Original form of strengths */

/** Decomposing strengths to raw strengths */
void attach_2_raw_strength(const Strength &strength,
                           std::vector<RawStrength> &raw_strengths);
}
}  // namespace ct

#endif  // STRENGTH_H_
