#ifndef CT_COMMON_EXP_S_TERM_H_
#define CT_COMMON_EXP_S_TERM_H_

#include <ct_common/common/utils.h>
#include <ct_common/common/exp_s.h>
#include <ct_common/common/paramspec.h>

namespace ct {
namespace common {
class DLL_EXPORT Exp_S_Term : public Exp_S {
public:
  Exp_S_Term(void);
  Exp_S_Term(const Exp_S_Term &from);
  Exp_S_Term &operator = (const Exp_S_Term &right);
  virtual ~Exp_S_Term(void) = 0;

public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_EXP_S_TERM_H_
