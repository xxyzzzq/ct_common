#ifndef CT_COMMON_PARAMSPEC_BOOL_H_
#define CT_COMMON_PARAMSPEC_BOOL_H_

#include <ct_common/common/utils.h>
#include <ct_common/common/paramspec.h>

namespace ct {
namespace common {
class DLL_EXPORT ParamSpec_Bool: public ParamSpec
{
public:
  ParamSpec_Bool(void);
  ParamSpec_Bool(const ParamSpec_Bool &from);
  ParamSpec_Bool &operator = (const ParamSpec_Bool &right);
  virtual ~ParamSpec_Bool(void);

  // the string values is neglected
  // setting values as "false", "true", "#"
  virtual void set_values(const std::vector<std::string> &string_values);
  const std::vector<bool> &get_bool_values(void) const { return this->bool_values_; }

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);

private:
  std::vector<bool> bool_values_;  // The bool values of the parameter
                                   // 0 for false, 1 for true, 2 for invalid
                                   // should be consistent with string values
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_PARAMSPEC_BOOL_H_
