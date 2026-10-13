#include <riscv_ztt.h>
#ifndef ST_TYPE
#define ST_TYPE i32_rnu
#define ST_CARRIER __INT32_TYPE__
#define ST_SCALAR i32_rnu
#define ST_SCALAR_CARRIER __INT32_TYPE__
#endif
#define ST_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define ST_NAME(f, t) ST_NAME_(f, t)
#define ST_OP_(f, t, c) __riscv_ztt_##f##_ew_x_##t##_1x1_##c
#define ST_OP(f, t, c) ST_OP_(f, t, c)
#define ST_MAKE_(c) __riscv_ztt_scalar_make_##c
#define ST_MAKE(c) ST_MAKE_(c)
#define ST_T_(t) __riscv_ztt_##t##_1x1_t
#define ST_T(t) ST_T_(t)
typedef ST_CARRIER st_element;
typedef ST_SCALAR_CARRIER st_scalar;
#define ST_ARGS const st_element *in, const st_element *old, \
  st_element *out, st_element *saved, st_scalar x
#define ST_LOAD ST_T(ST_TYPE) a = ST_NAME(mls_rm, ST_TYPE) (in)
#define ST_DO(f, a, b) ST_OP(f, ST_TYPE, ST_SCALAR) (a, b, ST_MAKE(ST_SCALAR) (x))
#ifdef __cplusplus
extern "C" {
#endif
extern void st_callee (void);

#define ST_SAME(n, f) \
void st_##n (ST_ARGS) \
{ \
  ST_LOAD; \
  ST_T(ST_TYPE) d = ST_DO (f, a, a); \
  __riscv_ztt_mss_rm (out, d); \
}
ST_SAME (acc, mmulacc)
ST_SAME (neg, mmulaccneg)
ST_SAME (add, mmuladd)
ST_SAME (sub, mmulsub)
#undef ST_SAME

void st_live (ST_ARGS)
{
  ST_LOAD;
  ST_T(ST_TYPE) d = ST_DO (mmulacc, a, a);
  __riscv_ztt_mss_rm (out, d);
  __riscv_ztt_mss_rm (saved, a);
}

void st_distinct (ST_ARGS)
{
  ST_LOAD;
  ST_T(ST_TYPE) b = ST_NAME(mls_rm, ST_TYPE) (old);
  ST_T(ST_TYPE) d = ST_DO (mmulacc, b, a);
  __riscv_ztt_mss_rm (out, d);
}

void st_chain (ST_ARGS)
{
  ST_LOAD;
  ST_T(ST_TYPE) b = ST_DO (mmulacc, a, a);
  ST_T(ST_TYPE) d = ST_DO (mmulacc, b, b);
  __riscv_ztt_mss_rm (out, d);
}

void st_call (ST_ARGS)
{
  ST_LOAD;
  st_callee ();
  ST_T(ST_TYPE) d = ST_DO (mmulacc, a, a);
  __riscv_ztt_mss_rm (out, d);
}

void st_asm (ST_ARGS)
{
  ST_LOAD;
  __asm__ volatile ("" : : : "memory");
  ST_T(ST_TYPE) d = ST_DO (mmulacc, a, a);
  __riscv_ztt_mss_rm (out, d);
}

void st_reference (ST_ARGS)
{
  ST_LOAD;
  __riscv_ztt_mss_rm (out, a);
}
#ifdef ST_INGRESS
void st_discard (ST_ARGS)
{
  ST_LOAD;
  (void) ST_DO (mmulacc, a, a);
}
#endif
#ifdef __cplusplus
}
#endif
