// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_PARAMSPEC_H_
#define CT_COMMON_COMMON_PARAMSPEC_H_

#include <map>
#include <memory>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/tree_node.h"

namespace ct_common {

// The base class for parameter specifications
class DLL_EXPORT ParamSpec {
 public:
  ParamSpec();
  ParamSpec(const ParamSpec& from);
  ParamSpec& operator=(const ParamSpec& right);
  virtual ~ParamSpec() = 0;

  /** Setting the parameter name */
  void set_param_name(const std::string& param_name) {
    param_name_ = param_name;
  }
  /** Getting the parameter name */
  const std::string& get_param_name() const { return param_name_; }

  /**
   * Setting the values by their string representations
   * An invalid value is automatically added in the back
   * A copy of the original string values is preserved
   */
  virtual void set_values(const std::vector<std::string>& string_values);

  /**
   * Get the preserved string values
   */
  const std::vector<std::string>& get_string_values() const {
    return string_values_;
  }
  /**
   * Get the level (number of values) of the parameter
   */
  std::size_t get_level() const { return get_num_values(); }
  /**
   * Get the map from strings to their ids by looking up the preserved string
   * copies
   */
  const std::map<std::string, std::size_t>& get_map_string_values_2_vid(
      void) const {
    return map_string_values_2_vid_;
  }
  /**
   * Query the value id by looking up the preserved string copies.
   * Value ids start from zero.
   */
  std::size_t query_value_id(const std::string& str) const;

  /** The specification for auto parameters */
  std::vector<std::pair<std::shared_ptr<TreeNode>, std::shared_ptr<TreeNode> > >&
     auto_value_specs() {
    return auto_value_specs_;
  }
  /** The constant reference for auto parameter specifications */
  const std::vector<std::pair<std::shared_ptr<TreeNode>,
                              std::shared_ptr<TreeNode> > >&
      get_auto_value_specs() const {
    return auto_value_specs_;
  }

  /** Get the set of all related parameters */
  void touch_pids(const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
                  std::set<std::size_t>* pids_to_touch) const;

  /** Setting the aux flag */
  void set_aux(bool flag) { is_aux_ = flag; }
  /** Whether the parameter is auxiliary */
  bool is_aux() const { return is_aux_; }
  /** Setting the auto flag */
  void set_auto(bool flag) { is_auto_ = flag; }
  /** Whether the parameter is automatic */
  bool is_auto() const { return is_auto_; }

  /** Get the vid for invalid values, which is level */
  std::size_t get_invalid_vid() const { return get_num_values(); }
  /** Get the width of the values (for output padding) */
  std::size_t get_width() const;
  /** Get the number of values (same with get_level) */
  std::size_t get_num_values() const {
    return map_string_values_2_vid_.size();
  }
  /** Check whether the given vid is invalid (>=level) */
  bool is_vid_invalid(std::size_t vid) const {
    return (vid >= get_num_values());
  }

 private:
  // Inner init function, for copying.
  void init(const ParamSpec& from);

 private:
  // The parameter name.
  std::string param_name_;
  // The preserved string values, used for printing generated covering arrays.
  std::vector<std::string> string_values_;
  // The map from string values to vids
  std::map<std::string, std::size_t>
      map_string_values_2_vid_;
  // Each element contain a condition and an expression, when some
  // condition is true, the value takes the expresion value.
  std::vector<std::pair<std::shared_ptr<TreeNode>,
                        std::shared_ptr<TreeNode> > >
      auto_value_specs_;

  // Whether the parameter is auxilliary.
  bool is_aux_;
  // Whether the parameter is automatic. P.S.: auto parameters should not be
  // circular.
  bool is_auto_;
};

// Utility function for finding parameter id from a vector of paramspecs.
std::size_t find_param_id(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    const std::string& param_name);
}  // namespace ct_common

#endif  // CT_COMMON_COMMON_PARAMSPEC_H_
