//===----- ct_common/common/paramspec.h -------------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the base class for parameter specifications
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_PARAMSPEC_H_
#define CT_COMMON_PARAMSPEC_H_

#include <vector>
#include <string>
#include <set>
#include <map>
#include "ct_common/base/utils.h"
#include "ct_common/common/tree_node.h"
#include <memory>

namespace ct {
namespace common {
/**
 * The base class for parameter specifications
 */
class DLL_EXPORT ParamSpec
{
public:
  ParamSpec(void);
  ParamSpec(const ParamSpec &from);
  ParamSpec &operator = (const ParamSpec &right);
  virtual ~ParamSpec(void) = 0;

  /** Setting the parameter name */
  void set_param_name(const std::string &param_name) { this->param_name_ = param_name; }
  /** Getting the parameter name */
  const std::string &get_param_name(void) const { return this->param_name_; }

  /**
   * Setting the values by their string representations
   * An invalid value is automatically added in the back
   * A copy of the original string values is preserved
   */
  virtual void set_values(const std::vector<std::string> &string_values);

  /**
   * Get the preserved string values
   */
  const std::vector<std::string> &get_string_values(void) const { return this->string_values_; }
  /**
   * Get the level (number of values) of the parameter
   */
  std::size_t get_level(void) const { return this->get_num_values(); }
  /**
   * Get the map from strings to their ids by looking up the preserved string copies
   */
  const std::map<std::string, std::size_t> &get_map_string_values_2_vid(void) const { return this->map_string_values_2_vid_; }
  /**
   * Query the value id by looking up the preserved string copies.
   * Value ids start from zero.
   */
  std::size_t query_value_id(const std::string &str) const;

  /** TODO: to be replaced by typeid */
  virtual std::string get_class_name(void) const;
  /** TODO: to be replaced by typeid */
  static std::string class_name(void);

  /** The specification for auto parameters */
  std::vector<std::pair<std::shared_ptr<TreeNode>, std::shared_ptr<TreeNode> > > &auto_value_specs(void) { return this->auto_value_specs_; }
  /** The constant reference for auto parameter specifications */
  const std::vector<std::pair<std::shared_ptr<TreeNode>, std::shared_ptr<TreeNode> > > &get_auto_value_specs(void) const { return this->auto_value_specs_; }

  /** Get the set of all related parameters */
  void touch_pids(const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
                  std::set<std::size_t> &pids_to_touch) const;

  /** Setting the aux flag */
  void set_aux(bool flag) { this->is_aux_ = flag; }
  /** Whether the parameter is auxiliary */
  bool is_aux(void) const { return this->is_aux_; }
  /** Setting the auto flag */
  void set_auto(bool flag) { this->is_auto_ = flag; }
  /** Whether the parameter is automatic */
  bool is_auto(void) const { return this->is_auto_; }

  /** Get the vid for invalid values, which is level */
  std::size_t get_invalid_vid(void) const { return this->get_num_values(); }
  /** Get the width of the values (for output padding) */
  std::size_t get_width(void) const;
  /** Get the number of values (same with get_level) */
  std::size_t get_num_values(void) const { return this->map_string_values_2_vid_.size(); }
  /** Check whether the given vid is invalid (>=level) */
  bool is_vid_invalid(std::size_t vid) const {   return (vid >= this->get_num_values()); }

private:
  /** Inner init function, for copying */
  void init(const ParamSpec &from);
private:
  std::string param_name_;  /**< The parameter name */
  std::vector<std::string> string_values_;  /**< The preserved string values */
  std::map<std::string, std::size_t> map_string_values_2_vid_;  /** The map from string values to vids */
  std::vector<std::pair<std::shared_ptr<TreeNode>, std::shared_ptr<TreeNode> > > auto_value_specs_;  /**< each element contain a condition and an expression,
                                                                                                            when some condition is true,
                                                                                                            the value takes the expresion value */

  bool is_aux_;  /**< Whether the parameter is auxilliary */
  bool is_auto_;  /**< Whether the parameter is automatic. P.S.: auto parameters should not be recursive */
};

/**
 * Utility function for finding parameter id from a vector of paramspecs
 */
std::size_t find_param_id(const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
                  const std::string &param_name);
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_PARAMSPEC_H_
