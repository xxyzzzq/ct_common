#ifndef CT_COMMON_UTILS_H_
#define CT_COMMON_UTILS_H_

#ifdef USE_ASSERT
#include <cassert>
#else  // USE_ASSERT
#include <exception>
#include <string>

namespace ct {
namespace common {
class CT_Exception : public std::exception {
public:
  CT_Exception(void) throw(): std::exception() {}
  CT_Exception(const CT_Exception &from) throw(): std::exception(from) {
    this->what_ = from.what_;
  }
  CT_Exception(std::string what) throw() { this->what_ = what; }
  virtual ~CT_Exception(void) throw() {} ;
  
  virtual const char *what() const throw() { return this->what_.c_str(); }

private:
  std::string what_;
};
}  // namespace common
}  // namespace ct
#endif  // USE_ASSERT

// for exporting shared library
#ifndef DLL_EXPORT
#ifdef _WIN32
#pragma warning(disable:4251)
#endif  // _WIN32
#ifdef _DLL_EXPORT
  #define DLL_EXPORT __declspec(dllexport)
#else  // _DLL_EXPORT
#ifdef _DLL_IMPORT
  #define DLL_EXPORT __declspec(dllimport)
#else  // _DLL_IMPORT
  #define DLL_EXPORT
#endif  // _DLL_IMPORT
#endif  // _DLL_EXPORT
#endif

#ifdef USE_ASSERT
#define CT_EXCEPTION(x) do { assert(!x); } while (false)
#else  // USE_ASSERT
#define CT_EXCEPTION(x) do { throw (ct::common::CT_Exception(x)); } while (false)
#endif  // USE_ASSERT

#define TYPE_CHECK(x, T) ((dynamic_cast<T>(x) != 0) ? true:false)
#define TYPE_ASSERT(x, T) do { if (!TYPE_CHECK(x,T)) { CT_EXCEPTION(std::string("the object is not of type ") + #T); } } while (false)

#endif  // CT_COMMON_UTILS_H_
