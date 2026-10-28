#include <riscv_ztt.h>
#ifndef TC_TYPE
#define TC_TYPE i64_rnu
#define TC_CARRIER __INT64_TYPE__
#endif
#define TC_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define TC_NAME_T(f, t) TC_NAME_(f, t)
#define TC_NAME(f) TC_NAME_T(f, TC_TYPE)
#define TC_T_(t) __riscv_ztt_##t##_1x1_t
#define TC_T(t) TC_T_(t)
typedef TC_CARRIER tc_element;
typedef TC_T(TC_TYPE) tc_matrix;
#define TC_ARGS const tc_element *in, const tc_element *other, \
  tc_element *out, tc_element *saved, tc_element *extra
#define TC_LOAD(p) TC_NAME(mls_rm) (p)
#define TC_STORE(p, v) TC_NAME(mss_rm) (p, v)
#ifdef __cplusplus
extern "C" {
#endif
extern void tc_callee (void);
#define TC_LIVE(name, op, l, r) \
void __attribute__((noipa)) name (TC_ARGS) \
{ \
  tc_matrix a = TC_LOAD (in), b = TC_LOAD (other); \
  TC_STORE (out, TC_NAME(op) (a, l, r)); \
  TC_STORE (saved, a); \
  TC_STORE (extra, b); \
}
TC_LIVE (tc_left_acc, mmulacc_ew, a, b)
TC_LIVE (tc_right_acc, mmulacc_ew, b, a)
TC_LIVE (tc_left_add, mmuladd_ew, a, b)
TC_LIVE (tc_right_add, mmuladd_ew, b, a)
TC_LIVE (tc_left_sub, mmulsub_ew, a, b)
TC_LIVE (tc_right_sub, mmulsub_ew, b, a)
TC_LIVE (tc_left_neg, mmulaccneg_ew, a, b)
TC_LIVE (tc_right_neg, mmulaccneg_ew, b, a)
#undef TC_LIVE
void __attribute__((noipa)) tc_call (TC_ARGS)
{
  tc_matrix a = TC_LOAD (in), b = TC_LOAD (other);
  tc_callee ();
  TC_STORE (out, TC_NAME(mmulacc_ew) (a, a, b));
  TC_STORE (saved, a);
  TC_STORE (extra, b);
}
void __attribute__((noipa)) tc_after (TC_ARGS)
{
  tc_matrix a = TC_LOAD (in), b = TC_LOAD (other);
  TC_STORE (out, TC_NAME(mmulacc_ew) (a, a, b));
  tc_callee ();
  TC_STORE (saved, a);
  TC_STORE (extra, b);
}
void __attribute__((noipa)) tc_dead_other (TC_ARGS)
{
  tc_matrix a = TC_LOAD (in), b = TC_LOAD (other);
  TC_STORE (out, TC_NAME(mmulacc_ew) (a, a, b));
  TC_STORE (saved, a);
}
void __attribute__((noipa)) tc_dead_old (TC_ARGS)
{
  tc_matrix a = TC_LOAD (in), b = TC_LOAD (other);
  TC_STORE (out, TC_NAME(mmulacc_ew) (a, a, b));
  TC_STORE (extra, b);
}
void __attribute__((noipa)) tc_same (TC_ARGS)
{
  tc_matrix a = TC_LOAD (in);
  TC_STORE (out, TC_NAME(mmulacc_ew) (a, a, a));
  TC_STORE (saved, a);
}
void __attribute__((noipa)) tc_pressure (TC_ARGS)
{
  tc_matrix a = TC_LOAD (in), b = TC_LOAD (other);
  tc_matrix c = TC_LOAD (in + 64);
  b = TC_NAME(mmulacc_ew) (b, c, b);
  TC_STORE (out, TC_NAME(mmulacc_ew) (a, a, b));
  TC_STORE (saved, a);
  TC_STORE (extra, TC_NAME(madd_ew) (b, c));
}
#ifdef __cplusplus
}
#endif
