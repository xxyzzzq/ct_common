#include <ct_common/common/paramspec_string.h>

using namespace ct::common;

ParamSpec_String::ParamSpec_String(void)
  : ParamSpec() {
}

ParamSpec_String::ParamSpec_String(const ParamSpec_String &from)
  : ParamSpec(from) {
}

ParamSpec_String &ParamSpec_String::operator = (
    const ParamSpec_String &right) {
  ParamSpec::operator=(right);
  return *this;
}

ParamSpec_String::~ParamSpec_String(void) {
}

std::string ParamSpec_String::get_class_name(void) const {
  return ParamSpec_String::class_name();
}

std::string ParamSpec_String::class_name(void) {
  return "ParamSpec_String";
}
