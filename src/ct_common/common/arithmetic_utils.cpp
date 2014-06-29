#include <algorithm>
#include <ct_common/common/arithmetic_utils.h>

std::vector<std::size_t> ct::common::utils::sort_and_uniquefy(const std::vector<std::size_t> &vec) {
  std::vector<std::size_t> tmp_return = vec;
  std::sort(tmp_return.begin(), tmp_return.end());
  std::size_t new_size = 0;
  for (std::size_t i = 0; i < tmp_return.size(); ++i) {
    if (new_size > 0 && tmp_return[i] == tmp_return[new_size-1]) {
      continue;
    }
    tmp_return[new_size] = tmp_return[i];
    ++new_size;
  }
  tmp_return.resize(new_size);
  return tmp_return;
}
