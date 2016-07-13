// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_BASE_CLASS_NAME_UTILS_H_
#define CT_COMMON_BASE_CLASS_NAME_UTILS_H_

#include <functional>
#include <string>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>

namespace ct_common {

// Class mapping typeid to class name.
class ClassNameMap final {
 public:
  ClassNameMap() = default;
  ~ClassNameMap() = default;

  template <typename T>
  static const std::string& GetClassName(const T& obj) {
    return GetInstance().GetClassNameInternal(typeid(obj));
  }

  static void Register(const std::type_index& info, const std::string& name) {
    GetInstance().RegisterInternal(info, name);
  }

 private:
  static ClassNameMap& GetInstance();

  const std::string& GetClassNameInternal(const std::type_index& idx) const;
  void RegisterInternal(const std::type_index& info, const std::string& name);

  using NameMap = std::unordered_map<std::type_index, std::string>;
  NameMap name_map_;
};

class GlobalInitializer {
 public:
  using FuncType = std::function<void()>;
  explicit GlobalInitializer(FuncType func) {
    func();
  }
};

}  // namespace ct_common

#define REGISTER_CLASS_NAME(name)                                       \
  namespace {                                                           \
  const ct_common::GlobalInitializer sClassNameRegisterer##name(        \
      std::bind(ClassNameMap::Register,                                 \
                std::type_index(typeid(name)), #name));                 \
  }

#endif  // CT_COMMON_BASE_CLASS_NAME_UTILS_H_
