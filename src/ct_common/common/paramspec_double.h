// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_PARAMSPEC_DOUBLE_H_
#define CT_COMMON_COMMON_PARAMSPEC_DOUBLE_H_

#include <string>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/paramspec.h"

namespace ct_common {

// The class for double parameter specifications
class DLL_EXPORT ParamSpec_Double : public ParamSpec {
 public:
  ParamSpec_Double(void);
  ParamSpec_Double(const ParamSpec_Double &from);
  ParamSpec_Double &operator=(const ParamSpec_Double &right);
  virtual ~ParamSpec_Double(void);

  virtual void set_values(const std::vector<std::string> &values);
  const std::vector<double> &get_double_values(void) const {
    return this->double_values_;
  }

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);

 private:
  // The double values of the parameter. Should be consistent with
  // string values.
  std::vector<double> double_values_;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_PARAMSPEC_DOUBLE_H_
