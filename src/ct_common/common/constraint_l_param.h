#ifndef CT_COMMON_CONSTRAINT_L_PARAM_H_
#define CT_COMMON_CONSTRAINT_L_PARAM_H_

#include <ct_common/common/constraint_l_term.h>

namespace ct {
namespace common {
class Constraint_L_Param : public Constraint_L_Term {
public:
  Constraint_L_Param(void);
  Constraint_L_Param(const Constraint_L_Param &from);
  virtual ~Constraint_L_Param(void);
  Constraint_L_Param &operator = (const Constraint_L_Param &right);
  
public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual void dump(std::ostream &os, const std::vector<boost::shared_ptr<ParamSpec> > &param_specs) const;

  void set_pid(std::size_t pid) { this->pid_ = pid; }
  std::size_t get_pid(void) const { return this->pid_; }
  
  virtual void inner_touch_leaf_pids( const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                                      std::set<std::size_t> &pids_to_touch) const;

public:
  virtual EvalType_Bool Evaluate( const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                                  const Assignment &assignment) const;

private:
  std::size_t pid_;  
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_L_PARAM_H_
