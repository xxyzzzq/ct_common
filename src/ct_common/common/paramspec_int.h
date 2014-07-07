//===----- ct_common/common/paramspec_int.h ---------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for int parameter specifications
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_PARAMSPEC_INT_H_
#define CT_COMMON_PARAMSPEC_INT_H_

#include <ct_common/common/utils.h>
#include <ct_common/common/paramspec.h>

namespace ct {
namespace common {
// specification class for integer parameters
class DLL_EXPORT ParamSpec_Int : public ParamSpec
{
public:
  ParamSpec_Int(void);
  ParamSpec_Int(const ParamSpec_Int &from);
  ParamSpec_Int &operator = (const ParamSpec_Int &right);
  virtual ~ParamSpec_Int(void);

  virtual void set_values(const std::vector<std::string> &string_values);
  const std::vector<int> &get_int_values(void) const { return this->int_values_; }

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);

private:
  std::vector<int> int_values_;   // The integer values of the parameter
                                  // should be consistent with string values
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_PARAMSPEC_INT_H_
