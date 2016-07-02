// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_STRENGTH_H_
#define CT_COMMON_COMMON_STRENGTH_H_

#include <utility>
#include <vector>

namespace ct_common {

// Decomposed strength.
using RawStrength = std::vector<std::size_t>;

// User-understandable strength.
using Strength = std::pair<std::vector<std::size_t>, std::size_t>;

/** Decomposing strengths to raw strengths */
void attach_2_raw_strength(const Strength &strength,
                           std::vector<RawStrength>* raw_strengths);

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_STRENGTH_H_
