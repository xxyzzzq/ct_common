// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/paramspec_string.h"

namespace ct_common {

REGISTER_CLASS_NAME(ParamSpec_String)

ParamSpec_String::ParamSpec_String() = default;

ParamSpec_String::ParamSpec_String(const ParamSpec_String& from) = default;

ParamSpec_String& ParamSpec_String::operator=(
    const ParamSpec_String& right) = default;

ParamSpec_String::~ParamSpec_String() = default;

}  // namespace ct_common
