//===----- ct_common/common/strength.cpp ------------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the utility functions for Strength and RawStrength
//
//===----------------------------------------------------------------------===//

#include <algorithm>
#include "ct_common/base/utils.h"
#include "ct_common/common/strength.h"

using namespace ct::common;

static void gen_strengths_core(
    const std::vector<std::size_t> &pid_list,
    std::vector<RawStrength> &raw_strengths,
    std::vector<std::size_t> &stack,
    std::size_t strength,
    std::size_t depth) {
  if (depth == strength) {
    std::vector<std::size_t> new_strength;
    for (std::size_t i = 0; i < stack.size(); ++i) {
      new_strength.push_back(pid_list[stack[i]]);
    }
    raw_strengths.push_back(new_strength);
    return;
  }
  std::size_t start_point = 0;
  if (depth > 0) {
    start_point = stack[depth-1]+1;
  }
  for (std::size_t i = start_point; i < pid_list.size(); ++i) {
    stack[depth] = i;
    gen_strengths_core(pid_list, raw_strengths, stack, strength, depth+1);
  }
}

void ct::common::attach_2_raw_strength(const Strength &strength, std::vector<RawStrength> & raw_strengths) {
  std::vector<std::size_t> pid_list = strength.first;
  std::sort(pid_list.begin(), pid_list.end());
  std::vector<std::size_t> unique_pid_list;
  for (std::size_t i = 0; i < pid_list.size(); i++) {
    if (unique_pid_list.size() == 0 ||
        pid_list[i] > unique_pid_list.back()) {
      unique_pid_list.push_back(pid_list[i]);
    }
  }
  // generate the strengths
  if (unique_pid_list.size() == 0) {
    CT_EXCEPTION("the parameter list is empty");
  }

  if (unique_pid_list.size() < strength.second) {
    CT_EXCEPTION("the parameter list is smaller than the strength");
  }
  if (strength.second == 0) {
    return;
  }
  std::vector<std::size_t> stack(strength.second, 0);
  gen_strengths_core(unique_pid_list, raw_strengths, stack , strength.second, 0);
}
