#include <riscv_ztt.h>
#ifndef TC_TYPE
#define TC_TYPE i64_rnu
#define TC_CARRIER __INT64_TYPE__
#endif
#define TC_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define TC_NAME(f, t) TC_NAME_(f, t)
#define TC_T_(t) __riscv_ztt_##t##_1x1_t
#define TC_T(t) TC_T_(t)
typedef TC_CARRIER tc_element;
#define TC_ARGS const tc_element *in, const tc_element *other, \
  tc_element *out, tc_element *saved, tc_element *extra, long e
#define TC_LOAD TC_T(TC_TYPE) a = TC_NAME(mls_rm, TC_TYPE) (in); \
  TC_T(TC_TYPE) b = TC_NAME(mls_rm, TC_TYPE) (other)
#define TC_ACC(a, b, e) TC_NAME(mldexpacc_ew_x, TC_TYPE) (a, b, e)
#define TC_STORE(p, a) __riscv_ztt_mss_rm (p, a)
#ifdef __cplusplus
extern "C" {
#endif
extern void tc_callee (void);

void tc_acc (TC_ARGS)
{
  TC_LOAD;
  TC_STORE (out, TC_ACC (a, b, e));
  TC_STORE (saved, a);
  TC_STORE (extra, b);
}

void tc_input_dead (TC_ARGS)
{
  TC_LOAD;
  TC_STORE (out, TC_ACC (a, b, e));
  TC_STORE (saved, a);
}

void tc_call (TC_ARGS)
{
  TC_LOAD;
  tc_callee ();
  TC_STORE (out, TC_ACC (a, b, e));
  TC_STORE (saved, a);
  TC_STORE (extra, b);
}

void tc_after (TC_ARGS)
{
  TC_LOAD;
  TC_STORE (out, TC_ACC (a, b, e));
  tc_callee ();
  TC_STORE (saved, a);
  TC_STORE (extra, b);
}

void tc_dead (TC_ARGS)
{
  TC_LOAD;
  TC_STORE (out, TC_ACC (a, b, e));
  TC_STORE (extra, b);
}

void tc_shared (TC_ARGS)
{
  TC_T(TC_TYPE) a = TC_NAME(mls_rm, TC_TYPE) (in);
  TC_STORE (out, TC_ACC (a, a, e));
  TC_STORE (saved, a);
}

void tc_pressure (TC_ARGS)
{
  TC_LOAD;
  TC_T(TC_TYPE) c = TC_NAME(mls_rm, TC_TYPE) (in + 64);
  b = TC_NAME(madd_ew, TC_TYPE) (b, c);
  TC_STORE (out, TC_ACC (a, b, e));
  TC_STORE (saved, a);
  TC_STORE (extra, TC_NAME(madd_ew, TC_TYPE) (b, c));
}

void tc_shared_pressure (TC_ARGS)
{
  TC_LOAD;
  a = TC_NAME(madd_ew, TC_TYPE) (a, b);
  TC_STORE (out, TC_ACC (a, a, e));
  TC_STORE (saved, a);
  TC_STORE (extra, b);
}

void tc_chain (TC_ARGS)
{
  TC_LOAD;
  a = TC_ACC (b, a, e);
  TC_STORE (out, TC_ACC (a, a, e));
  TC_STORE (saved, a);
  TC_STORE (extra, b);
}

void tc_zero (TC_ARGS)
{
  TC_LOAD;
  TC_STORE (out, TC_ACC (a, b, 0));
  TC_STORE (saved, a);
  TC_STORE (extra, b);
}

void tc_constant (TC_ARGS)
{
  TC_LOAD;
  TC_STORE (out, TC_ACC (a, b, 3));
  TC_STORE (saved, a);
  TC_STORE (extra, b);
}

void tc_copy (TC_ARGS)
{
  TC_LOAD;
  a = TC_NAME(mcopy_m2m, TC_TYPE) (a);
  TC_STORE (out, TC_ACC (a, b, e));
  TC_STORE (saved, a);
  TC_STORE (extra, b);
}
#ifdef __cplusplus
}
#endif
