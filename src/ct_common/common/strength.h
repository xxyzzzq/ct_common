#ifndef STRENGTH_H_
#define STRENGTH_H_
#include <utility>
#include <vector>

namespace ct {
namespace common {
  typedef std::vector<std::size_t> RawStrength;
  typedef std::pair<std::vector<std::size_t>, std::size_t> Strength;

  void attach_2_raw_strength(const Strength &strength, std::vector<RawStrength> &raw_strengths);
}
}  // namespace ct

#endif  // STRENGTH_H_
