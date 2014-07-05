#ifndef CT_COMMON_PARAMSPEC_H_
#define CT_COMMON_PARAMSPEC_H_

#include <vector>
#include <string>
#include <set>
#include <map>
#include <ct_common/common/utils.h>
#include <ct_common/common/tree_node.h>
#include <boost/shared_ptr.hpp>

namespace ct {
namespace common {
class DLL_EXPORT ParamSpec
{
public:
  ParamSpec(void);  
  ParamSpec(const ParamSpec &from);
  ParamSpec &operator = (const ParamSpec &right);
  virtual ~ParamSpec(void) = 0;
  
  void set_param_name(const std::string &param_name) { this->param_name_ = param_name; }
  const std::string &get_param_name(void) const { return this->param_name_; }

  // now a invalid value is automatically added to the back
  virtual void set_values(const std::vector<std::string> &string_values);

  const std::vector<std::string> &get_string_values(void) const { return this->string_values_; }
  std::size_t get_level(void) const { return this->get_num_values(); }
  const std::map<std::string, std::size_t> &get_map_string_values_2_vid(void) const { return this->map_string_values_2_vid_; }
  std::size_t query_value_id(const std::string &str) const;
  
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  
  std::vector<std::pair<boost::shared_ptr<TreeNode>, boost::shared_ptr<TreeNode> > > &auto_value_specs(void) { return this->auto_value_specs_; }
  const std::vector<std::pair<boost::shared_ptr<TreeNode>, boost::shared_ptr<TreeNode> > > &get_auto_value_specs(void) const { return this->auto_value_specs_; }

  void touch_pids(const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                  std::set<std::size_t> &pids_to_touch) const;
  
  void set_aux(bool flag) { this->is_aux_ = flag; }
  bool is_aux(void) const { return this->is_aux_; }
  void set_auto(bool flag) { this->is_auto_ = flag; }
  bool is_auto(void) const { return this->is_auto_; }

  std::size_t get_invalid_vid(void) const { return this->get_num_values(); }
  std::size_t get_width(void) const;
  std::size_t get_num_values(void) const { return this->map_string_values_2_vid_.size(); }
  
  bool is_vid_invalid(std::size_t vid) const {   return (vid >= this->get_num_values()); }

private:
  void init(const ParamSpec &from);
private:
  std::string param_name_;
  std::vector<std::string> string_values_;
  std::map<std::string, std::size_t> map_string_values_2_vid_;
  // each element contain a condition and an expression, when some condition is true, the value takes the expresion value
  std::vector<std::pair<boost::shared_ptr<TreeNode>, boost::shared_ptr<TreeNode> > > auto_value_specs_;
  bool is_aux_;
  bool is_auto_;  // auto parameters should not be recursive
};

std::size_t find_param_id(const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                  const std::string &param_name);
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_PARAMSPEC_H_
