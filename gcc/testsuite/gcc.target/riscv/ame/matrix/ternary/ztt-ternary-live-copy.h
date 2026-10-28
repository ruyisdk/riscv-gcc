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
#define TC_LIVE(name, op) \
void __attribute__((noipa)) name (TC_ARGS) \
{ \
  tc_matrix a = TC_LOAD (in); \
  TC_STORE (out, TC_NAME(op) (a, a, a)); \
  TC_STORE (saved, a); \
}
TC_LIVE (tc_acc, mmulacc_ew)
TC_LIVE (tc_add, mmuladd_ew)
TC_LIVE (tc_sub, mmulsub_ew)
TC_LIVE (tc_neg, mmulaccneg_ew)
#undef TC_LIVE
void __attribute__((noipa)) tc_call (TC_ARGS)
{
  tc_matrix a = TC_LOAD (in);
  tc_callee ();
  TC_STORE (out, TC_NAME(mmulacc_ew) (a, a, a));
  TC_STORE (saved, a);
}
void __attribute__((noipa)) tc_after (TC_ARGS)
{
  tc_matrix a = TC_LOAD (in);
  TC_STORE (out, TC_NAME(mmulacc_ew) (a, a, a));
  tc_callee ();
  TC_STORE (saved, a);
}
void __attribute__((noipa)) tc_distinct (TC_ARGS)
{
  tc_matrix a = TC_LOAD (in), b = TC_LOAD (other);
  TC_STORE (out, TC_NAME(mmulacc_ew) (b, a, b));
  TC_STORE (saved, b);
}
void __attribute__((noipa)) tc_pressure (TC_ARGS)
{
  tc_matrix a = TC_LOAD (in), b = TC_LOAD (other);
  TC_STORE (out, TC_NAME(mmulacc_ew) (a, a, a));
  TC_STORE (saved, a);
  TC_STORE (extra, b);
}
void __attribute__((noipa)) tc_asm (TC_ARGS)
{
  tc_matrix a = TC_LOAD (in);
  asm volatile ("" ::: "memory");
  TC_STORE (out, TC_NAME(mmulacc_ew) (a, a, a));
  TC_STORE (saved, a);
}
void __attribute__((noipa)) tc_dead (TC_ARGS)
{
  tc_matrix a = TC_LOAD (in);
  TC_STORE (out, TC_NAME(mmulacc_ew) (a, a, a));
}
void __attribute__((noipa)) tc_bank (TC_ARGS)
{
  tc_matrix a = TC_LOAD (in), b = TC_LOAD (other);
  a = TC_NAME(mmulacc_ew) (b, a, b);
  TC_STORE (out, TC_NAME(mmulacc_ew) (a, a, a));
  TC_STORE (saved, a);
  TC_STORE (extra, b);
}
#ifdef __cplusplus
}
#endif
