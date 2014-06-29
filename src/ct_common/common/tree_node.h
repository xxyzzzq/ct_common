#ifndef CT_COMMON_TREE_NODE_H_
#define CT_COMMON_TREE_NODE_H_

#include <vector>
#include <set>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <ct_common/common/utils.h>

namespace ct {
namespace common {
class ParamSpec;
class DLL_EXPORT TreeNode {
public:
  TreeNode(void);
  // This class is not supposed to be copied and assigned
  // only the reference is copied
  TreeNode(const TreeNode &from);
  TreeNode &operator = (const TreeNode &right);
  virtual ~TreeNode(void) = 0;
  
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  bool is_leaf(void) const { return this->oprds_.empty(); }

  // get all related parameters EXCEPT for auto parameters
  // param_specs are used to determine related pids of auto parameters
  void touch_pids(const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                  std::set<std::size_t> &pids_to_touch) const;
  
  virtual void inner_touch_leaf_pids( const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                                      std::set<std::size_t> &pids_to_touch) const;
  const std::vector<boost::shared_ptr<TreeNode> > &get_oprds() const { return this->oprds_; }

  virtual const std::string &get_str_value(void) const;
  
  virtual void dump(std::ostream &os, const std::vector<boost::shared_ptr<ParamSpec> > &param_specs) const = 0;

protected:
  std::vector<boost::shared_ptr<TreeNode> > oprds_;
};
}  // namespace common
}  // namespace ct

#endif // CT_COMMON_TREE_NODE_H_
