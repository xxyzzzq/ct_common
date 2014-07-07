//===----- ct_common/common/paramspec.cpp -----------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class ParamSpec
//
//===----------------------------------------------------------------------===//

#include <ct_common/common/paramspec.h>
#include <ct_common/common/pvpair.h>

using namespace ct::common;

ParamSpec::ParamSpec(void)
    : is_aux_(false), is_auto_(false) {
}

ParamSpec::ParamSpec(const ParamSpec &from) {
  this->init(from);
}

ParamSpec &ParamSpec::operator = (const ParamSpec &right) {
  this->init(right);
  return *this;
}

void ParamSpec::init(const ParamSpec &from) {
  this->param_name_ = from.param_name_;
  this->string_values_ = from.string_values_;
  this->map_string_values_2_vid_ = from.map_string_values_2_vid_;
  this->is_aux_ = from.is_aux_;
  this->is_auto_ = from.is_auto_;
}

ParamSpec::~ParamSpec(void) {
}

void ParamSpec::set_values(const std::vector<std::string> &values) {
  if (values.size() == 0) {
    CT_EXCEPTION(std::string("no values for ") + this->get_param_name());
  }
  this->map_string_values_2_vid_.clear();
  this->string_values_ = values;
  this->string_values_.push_back("#");
  for (std::size_t i = 0; i < values.size(); i++) {
    if (values[i].size() <= 0) {
      CT_EXCEPTION("empty value found");
    }
    if (this->map_string_values_2_vid_.find(values[i]) !=
        this->map_string_values_2_vid_.end()) {
      CT_EXCEPTION(std::string("value ") + values[i] + " is already registered for " + this->get_param_name());
    }
    map_string_values_2_vid_.insert(std::pair<std::string, std::size_t>(values[i], i));
  }
}

std::string ParamSpec::get_class_name(void) const {
  return ParamSpec::class_name();
}

std::string ParamSpec::class_name(void) {
  return "ParamSpec";
}

std::size_t ParamSpec::query_value_id(const std::string &str) const {
  std::map<std::string, std::size_t>::const_iterator iter =
      this->map_string_values_2_vid_.find(str);
  if (iter != this->map_string_values_2_vid_.end()) {
    return iter->second;
  }
  return VID_BOUND;
}

std::size_t ParamSpec::get_width(void) const {
  std::size_t width = this->param_name_.size();
  for (std::size_t i = 0; i < this->string_values_.size(); ++i) {
    if (width < this->string_values_[i].size()) {
      width = this->string_values_[i].size();
    }
  }
  return std::max(width + 2, std::size_t(5));
}

std::size_t ct::common::find_param_id(const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
    const std::string &param_name) {
  for (std::size_t i = 0; i < param_specs.size(); ++i) {
    if (param_specs[i]->get_param_name() == param_name) {
      return i;
    }
  }
  return PID_BOUND;
}

void ParamSpec::touch_pids( const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                            std::set<std::size_t> &pids_to_touch) const {
  for (std::size_t i = 0; i < this->auto_value_specs_.size(); ++i) {
    if (!this->auto_value_specs_[i].first) {
      CT_EXCEPTION("encountered invalid auto value condition");
      return;
    }
    if (!this->auto_value_specs_[i].second) {
      CT_EXCEPTION("encountered invalid auto value expression");
      return;
    }
    this->auto_value_specs_[i].first->touch_pids(param_specs, pids_to_touch);
    this->auto_value_specs_[i].second->touch_pids(param_specs, pids_to_touch);        
  }
}
