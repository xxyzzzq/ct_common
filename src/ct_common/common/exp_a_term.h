#ifndef CT_COMMON_EXP_A_TERM_H_
#define CT_COMMON_EXP_A_TERM_H_

#include <ct_common/common/utils.h>
#include <ct_common/common/exp_a.h>
#include <ct_common/common/paramspec.h>

namespace ct {
namespace common {
class DLL_EXPORT Exp_A_Term : public Exp_A {
public:
  Exp_A_Term(void);
  Exp_A_Term(const Exp_A_Term &from);
  Exp_A_Term &operator = (const Exp_A_Term &right);
  virtual ~Exp_A_Term(void) = 0;

public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_EXP_A_TERM_H_
