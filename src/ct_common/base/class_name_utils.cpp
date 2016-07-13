// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/base/class_name_utils.h"

#include <cassert>

namespace ct_common {

ClassNameMap& ClassNameMap::GetInstance() {
  static ClassNameMap sInstance;

  return sInstance;
}

const std::string& ClassNameMap::GetClassNameInternal(
    const std::type_index& idx) const {
  static std::string empty_string;
  if (!name_map_.count(idx))
    return empty_string;
  return name_map_.find(idx)->second;
}

void ClassNameMap::RegisterInternal(const std::type_index& idx,
                                    const std::string& name) {
  assert(!name_map_.count(idx));
  name_map_[idx] = name;
}

}  // namespace ct_common
