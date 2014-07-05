#ifndef CT_COMMON_PARAMSPEC_STRING_H_
#define CT_COMMON_PARAMSPEC_STRING_H_

#include <ct_common/common/utils.h>
#include <ct_common/common/paramspec.h>

namespace ct {
namespace common {
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
