#ifndef CT_COMMON_ARITHMETIC_UTILS_H_
#define CT_COMMON_ARITHMETIC_UTILS_H_

#include <cmath>
#include <vector>

namespace ct {
namespace common {
namespace utils{

const double EPSILON = 1e-6;

inline bool cmp_eq(int a, int b) {
  return a == b;
}

inline bool cmp_ge(int a, int b) {
  return a >= b;
}

inline bool cmp_gt(int a, int b) {
  return a > b;
}

inline bool cmp_le(int a, int b) {
  return a <= b;
}

inline bool cmp_lt(int a, int b) {
  return a < b;
}

inline bool cmp_ne(int a, int b) {
  return a != b;
}

inline bool cmp_eq(double a, double b, double prec = 0) {
  return fabs(a - b) <= prec;
}

inline bool cmp_ge(double a, double b, double prec = 0) {
  return (a - b) >= -prec;
}

inline bool cmp_gt(double a, double b, double prec = 0) {
  return (a - b) > prec;
}

inline bool cmp_le(double a, double b, double prec = 0) {
  return (a - b) <= prec;
}

inline bool cmp_lt(double a, double b, double prec = 0) {
  return (a - b) < -prec;
}

inline bool cmp_ne(double a, double b, double prec = 0) {
  return fabs(a - b) > prec;
}

std::vector<std::size_t> sort_and_uniquefy(const std::vector<std::size_t> &vec);
}  // namespace utils
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_ARITHMETIC_UTILS_H_
