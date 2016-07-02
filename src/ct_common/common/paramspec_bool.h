// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_PARAMSPEC_BOOL_H_
#define CT_COMMON_COMMON_PARAMSPEC_BOOL_H_

#include <string>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/paramspec.h"

namespace ct_common {

// The class for Boolean parameter specifications
class DLL_EXPORT ParamSpec_Bool : public ParamSpec {
 public:
  ParamSpec_Bool(void);
  ParamSpec_Bool(const ParamSpec_Bool &from);
  ParamSpec_Bool &operator=(const ParamSpec_Bool &right);
  virtual ~ParamSpec_Bool(void);

  // The string values is neglected.  Setting values as "false", "true", "#".
  virtual void set_values(const std::vector<std::string> &string_values);
  const std::vector<bool> &get_bool_values(void) const {
    return this->bool_values_;
  }

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);

 private:
  // The bool values of the parameter: 0 for false, 1 for true, 2 for invalid.
  // should be consistent with string values.
  std::vector<bool> bool_values_;
};
}  // namespace ct_common

#endif  // CT_COMMON_COMMON_PARAMSPEC_BOOL_H_
