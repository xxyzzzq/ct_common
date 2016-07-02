// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_PARAMSPEC_INT_H_
#define CT_COMMON_COMMON_PARAMSPEC_INT_H_

#include <string>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/paramspec.h"

namespace ct_common {

// Integer parameter specifications.
class DLL_EXPORT ParamSpec_Int : public ParamSpec {
 public:
  ParamSpec_Int(void);
  ParamSpec_Int(const ParamSpec_Int &from);
  ParamSpec_Int &operator=(const ParamSpec_Int &right);
  virtual ~ParamSpec_Int(void);

  virtual void set_values(const std::vector<std::string> &string_values);
  const std::vector<int> &get_int_values(void) const {
    return this->int_values_;
  }

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);

 private:
  // The integer values of the parameter. Should be consistent with
  // string values.
  std::vector<int> int_values_;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_PARAMSPEC_INT_H_
