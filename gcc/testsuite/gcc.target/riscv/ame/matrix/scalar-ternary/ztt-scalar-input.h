#include <riscv_ztt.h>
#ifndef WC_TYPE
#define WC_TYPE i128_rnu
#define WC_CARRIER __riscv_ztt_i128_storage_t
#endif
#ifndef WC_TC
#define WC_TC i8_rnu
#endif
#define WC_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define WC_NAME(f, t) WC_NAME_(f, t)
#define WC_T_(t) __riscv_ztt_##t##_1x1_t
#define WC_T(t) WC_T_(t)
#define WC_OP_(f, t, c) __riscv_ztt_##f##_ew_x_##t##_1x1_##c
#define WC_OP(f, t, c) WC_OP_(f, t, c)
#ifdef WC_BITS
#define WC_MAKE_(t, x) __riscv_ztt_scalar_from_bits_##t (x)
#else
#define WC_MAKE_(t, x) __riscv_ztt_scalar_make_##t (x)
#endif
#define WC_MAKE(t, x) WC_MAKE_(t, x)
typedef WC_CARRIER element_t;
#define WC_ARGS const element_t *in, element_t *out, element_t *saved, long e
#define WC_LOAD WC_T(WC_TYPE) a = WC_NAME(mls_rm, WC_TYPE) (in)
#define WC_COPY(x) WC_NAME(mcopy_m2m, WC_TYPE) (x)
#define WC_CALC(f, a, b) WC_OP(f, WC_TYPE, WC_TC) (a, b, WC_MAKE(WC_TC, (unsigned long) e))
#define WC_SAVE(d, b) __riscv_ztt_mss_rm (out, d); __riscv_ztt_mss_rm (saved, b)
#ifdef __cplusplus
extern "C" {
#endif
extern void wc_callee (void);
void wc_acc_same (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) d = WC_CALC(mmulacc, a, a);
  WC_SAVE(d, a);
}
void wc_acc_copy (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b = WC_COPY(a);
  WC_T(WC_TYPE) d = WC_CALC(mmulacc, b, a);
  WC_SAVE(d, b);
}
void wc_acc_call (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b = WC_COPY(a);
  wc_callee ();
  WC_T(WC_TYPE) d = WC_CALC(mmulacc, a, b);
  WC_SAVE(d, b);
}
void wc_accneg (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b = WC_COPY(a);
  WC_T(WC_TYPE) d = WC_CALC(mmulaccneg, a, b);
  WC_SAVE(d, b);
}
void wc_add (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b = WC_COPY(a);
  WC_T(WC_TYPE) d = WC_CALC(mmuladd, b, a);
  WC_SAVE(d, b);
}
void wc_sub (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b = WC_COPY(a);
  WC_T(WC_TYPE) d = WC_CALC(mmulsub, a, b);
  WC_SAVE(d, b);
}
void wc_chain (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b = WC_COPY(a), c = WC_COPY(b), d = WC_COPY(c), z = WC_COPY(d);
  WC_T(WC_TYPE) result = WC_CALC(mmulacc, z, a);
  WC_SAVE(result, z);
}
#ifdef __cplusplus
}
#endif
