#include <riscv_ztt.h>
#ifndef CM_TYPE
#define CM_TYPE i32
#define CM_CARRIER __INT32_TYPE__
#endif
#define CM_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define CM_NAME(f, t) CM_NAME_(f, t)
#define CM_T_(t) __riscv_ztt_##t##_1x1_t
#define CM_T(t) CM_T_(t)
typedef CM_CARRIER element_t;
#define HIGH ((unsigned long) 0xabcdef1200000002ULL)
#define LARGE ((unsigned long) 0xabcdef1212345678ULL)
#define DO_OP(op, value) \
  CM_T(CM_TYPE) a = CM_NAME(mls_rm, CM_TYPE) (in); \
  CM_T(CM_TYPE) b = CM_NAME(op, CM_TYPE) (a, value); \
  __riscv_ztt_mss_rm (out, b)
#define DO(value) DO_OP(mrowbcast_ew_x, value)
#define ARGS const element_t *in, element_t *out, volatile unsigned long *full
#ifdef __cplusplus
extern "C" {
#endif
unsigned long cm_single (ARGS) { DO(HIGH); return 0; }
unsigned long cm_return (ARGS) { DO(HIGH); return HIGH; }
unsigned long cm_store (ARGS) { DO(HIGH); *full = HIGH; return 0; }
unsigned long cm_store_before (ARGS) { *full = HIGH; DO(HIGH); return 0; }
unsigned long cm_asm (ARGS) { DO(HIGH); asm volatile ("" :: "r" (HIGH)); return 0; }
unsigned long cm_small (ARGS) { DO(2); return 0; }
unsigned long cm_zero (ARGS) { DO((unsigned long) 0xabcdef1200000000ULL); return 0; }
unsigned long cm_bit31 (ARGS) { DO((unsigned long) 0xabcdef1280000000ULL); return 0; }
unsigned long cm_bit31_return (ARGS) { DO((unsigned long) 0xabcdef1280000000ULL); return (unsigned long) 0xabcdef1280000000ULL; }
unsigned long cm_large (ARGS) { DO(LARGE); return 0; }
unsigned long cm_large_return (ARGS) { DO(LARGE); return LARGE; }
unsigned long cm_dynamic (ARGS) { unsigned long k = *full; DO(k); return k; }
unsigned long cm_col (ARGS) { DO_OP(mcolbcast_ew_x, HIGH); return 0; }
unsigned long cm_negative (ARGS) { DO((unsigned long) 0xabcdef12ffffffffULL); return 0; }
unsigned long cm_shift_plus (ARGS) { DO_OP(mrowshift_ew_x, 2); return 0; }
unsigned long cm_shift_minus (ARGS) { DO_OP(mcolshift_ew_x, -2); return 0; }
unsigned long cm_unused (ARGS)
{
  CM_T(CM_TYPE) a = CM_NAME(mls_rm, CM_TYPE) (in);
  CM_NAME(mrowbcast_ew_x, CM_TYPE) (a, HIGH);
  return 0;
}
unsigned long cm_two (ARGS)
{
  DO(HIGH);
  CM_T(CM_TYPE) d = CM_NAME(mcolbcast_ew_x, CM_TYPE) (a, HIGH);
  __riscv_ztt_mss_rm (out, d);
  return 0;
}
#ifdef __cplusplus
}
#endif
