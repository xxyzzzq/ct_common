//===----- ct_common/common/paramspec_double.h ------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for double parameter specifiations
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_PARAMSPEC_DOUBLE_H_
#define CT_COMMON_PARAMSPEC_DOUBLE_H_

#include <ct_common/common/utils.h>
#include <ct_common/common/paramspec.h>

namespace ct {
namespace common {
/**
 * The class for double parameter specifications
 */
class DLL_EXPORT ParamSpec_Double : public ParamSpec
{
public:
  ParamSpec_Double(void);
  ParamSpec_Double(const ParamSpec_Double &from);
  ParamSpec_Double &operator = (const ParamSpec_Double &right);
  virtual ~ParamSpec_Double(void);

  virtual void set_values(const std::vector<std::string> &values);
  const std::vector<double> &get_double_values(void) const { return this->double_values_; }

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);

private:
  std::vector<double> double_values_;  /**< The double values of the parameter.
                                        * Should be consistent with string values */
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_PARAMSPEC_DOUBLE_H_
