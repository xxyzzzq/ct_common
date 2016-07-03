// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/paramspec.h"

#include <algorithm>

#include "ct_common/common/pvpair.h"

namespace ct_common {

REGISTER_CLASS_NAME(ParamSpec)

ParamSpec::ParamSpec() : is_aux_(false), is_auto_(false) {}

ParamSpec::ParamSpec(const ParamSpec& from) = default;

ParamSpec& ParamSpec::operator=(const ParamSpec& right) = default;

ParamSpec::~ParamSpec() = default;

void ParamSpec::set_values(const std::vector<std::string>& values) {
  if (values.size() == 0) {
    CT_EXCEPTION(std::string("no values for ") + get_param_name());
  }
  map_string_values_2_vid_.clear();
  string_values_ = values;
  string_values_.push_back("#");
  for (std::size_t i = 0; i < values.size(); i++) {
    if (values[i].size() <= 0) {
      CT_EXCEPTION("empty value found");
    }
    if (map_string_values_2_vid_.find(values[i]) !=
        map_string_values_2_vid_.end()) {
      CT_EXCEPTION(std::string("value ") + values[i] +
                   " is already registered for " + get_param_name());
    }
    map_string_values_2_vid_.insert(
        std::pair<std::string, std::size_t>(values[i], i));
  }
}

std::size_t ParamSpec::query_value_id(const std::string& str) const {
  std::map<std::string, std::size_t>::const_iterator iter =
      map_string_values_2_vid_.find(str);
  if (iter != map_string_values_2_vid_.end()) {
    return iter->second;
  }
  return VID_BOUND;
}

std::size_t ParamSpec::get_width() const {
  std::size_t width = param_name_.size();
  for (std::size_t i = 0; i < string_values_.size(); ++i) {
    if (width < string_values_[i].size()) {
      width = string_values_[i].size();
    }
  }
  return std::max(width + 2, std::size_t(5));
}

std::size_t find_param_id(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const std::string& param_name) {
  for (std::size_t i = 0; i < param_specs.size(); ++i) {
    if (param_specs[i]->get_param_name() == param_name) {
      return i;
    }
  }
  return PID_BOUND;
}

void ParamSpec::touch_pids(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    std::set<std::size_t>* pids_to_touch) const {
  for (std::size_t i = 0; i < auto_value_specs_.size(); ++i) {
    if (!auto_value_specs_[i].first) {
      CT_EXCEPTION("encountered invalid auto value condition");
      return;
    }
    if (!auto_value_specs_[i].second) {
      CT_EXCEPTION("encountered invalid auto value expression");
      return;
    }
    auto_value_specs_[i].first->touch_pids(param_specs, pids_to_touch);
    auto_value_specs_[i].second->touch_pids(param_specs, pids_to_touch);
  }
}

}  // namespace ct_common
