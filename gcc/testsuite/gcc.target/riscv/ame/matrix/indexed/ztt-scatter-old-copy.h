#include <riscv_ztt.h>
#ifndef TC_TYPE
#define TC_TYPE u64_rnu
#define TC_CARRIER __UINT64_TYPE__
#endif
#ifndef TC_DISTINCT
#define TC_DISTINCT 1
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
#if TC_DISTINCT
#define TC_THIRD TC_LOAD (in + 64)
#else
#define TC_THIRD b
#endif
#ifdef __cplusplus
extern "C" {
#endif
extern void tc_callee (void);
#define TC_LIVE(name, op, rhs) \
void __attribute__((noipa)) name (TC_ARGS) \
{ \
  tc_matrix a = TC_LOAD (in), b = TC_LOAD (other), c = rhs; \
  TC_STORE (out, TC_NAME(op) (a, b, c)); \
  TC_STORE (saved, a); \
  TC_STORE (extra, TC_NAME(madd_ew) (b, c)); \
}
TC_LIVE (tc_col_add_pair, mcolscatadd_ew, b)
TC_LIVE (tc_col_add_full, mcolscatadd_ew, TC_THIRD)
TC_LIVE (tc_row_add_pair, mrowscatadd_ew, b)
TC_LIVE (tc_row_add_full, mrowscatadd_ew, TC_THIRD)
TC_LIVE (tc_col_max_pair, mcolscatmax_ew, b)
TC_LIVE (tc_col_max_full, mcolscatmax_ew, TC_THIRD)
TC_LIVE (tc_row_max_pair, mrowscatmax_ew, b)
TC_LIVE (tc_row_max_full, mrowscatmax_ew, TC_THIRD)
#undef TC_LIVE
void __attribute__((noipa)) tc_call (TC_ARGS)
{
  tc_matrix a = TC_LOAD (in), b = TC_LOAD (other);
  tc_callee ();
  TC_STORE (out, TC_NAME(mcolscatadd_ew) (a, b, b));
  TC_STORE (saved, a);
  TC_STORE (extra, b);
}
void __attribute__((noipa)) tc_after (TC_ARGS)
{
  tc_matrix a = TC_LOAD (in), b = TC_LOAD (other);
  TC_STORE (out, TC_NAME(mrowscatadd_ew) (a, b, b));
  tc_callee ();
  TC_STORE (saved, a);
  TC_STORE (extra, b);
}
void __attribute__((noipa)) tc_dead_other (TC_ARGS)
{
  tc_matrix a = TC_LOAD (in), b = TC_LOAD (other);
  TC_STORE (out, TC_NAME(mcolscatadd_ew) (a, b, b));
  TC_STORE (saved, a);
}
void __attribute__((noipa)) tc_dead_old (TC_ARGS)
{
  tc_matrix a = TC_LOAD (in), b = TC_LOAD (other);
  TC_STORE (out, TC_NAME(mcolscatadd_ew) (a, b, b));
  TC_STORE (extra, b);
}
void __attribute__((noipa)) tc_shared (TC_ARGS)
{
  tc_matrix a = TC_LOAD (in), b = TC_LOAD (other);
  TC_STORE (out, TC_NAME(mcolscatadd_ew) (a, a, a));
  TC_STORE (saved, a);
}
void __attribute__((noipa)) tc_pressure (TC_ARGS)
{
  tc_matrix a = TC_LOAD (in), b = TC_LOAD (other);
  tc_matrix c = TC_LOAD (in + 64), d = TC_LOAD (other + 64);
  b = TC_NAME(madd_ew) (b, TC_NAME(madd_ew) (c, d));
  TC_STORE (out, TC_NAME(mcolscatadd_ew) (a, b, b));
  TC_STORE (saved, a);
  TC_STORE (extra, TC_NAME(madd_ew) (TC_NAME(madd_ew) (b, c), d));
}
#ifdef __cplusplus
}
#endif
