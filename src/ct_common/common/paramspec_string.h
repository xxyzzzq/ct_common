// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_PARAMSPEC_STRING_H_
#define CT_COMMON_COMMON_PARAMSPEC_STRING_H_

#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/paramspec.h"

namespace ct_common {

// String parameter specifications
class DLL_EXPORT ParamSpec_String : public ParamSpec {
 public:
  ParamSpec_String();
  ParamSpec_String(const ParamSpec_String& from);
  ParamSpec_String& operator=(const ParamSpec_String& right);
  ~ParamSpec_String() override;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_PARAMSPEC_STRING_H_
