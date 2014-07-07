//===----- ct_common/common/paramspec_string.h ------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for string parameter specifications
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_PARAMSPEC_STRING_H_
#define CT_COMMON_PARAMSPEC_STRING_H_

#include <ct_common/common/utils.h>
#include <ct_common/common/paramspec.h>

namespace ct {
namespace common {
/**
 * The class for string parameter specifications
 */
class DLL_EXPORT ParamSpec_String: public ParamSpec
{
public:
  ParamSpec_String(void);
  ParamSpec_String(const ParamSpec_String &from);
  ParamSpec_String& operator =(const ParamSpec_String &right);
  virtual ~ParamSpec_String(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_PARAMSPEC_STRING_H_
