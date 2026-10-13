#include <riscv_ztt.h>
#ifndef EO_TYPE
#define EO_TYPE i32
#define EO_CARRIER __INT32_TYPE__
#endif
#define EO_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define EO_NAME(f, t) EO_NAME_(f, t)
#define EO_T_(t) __riscv_ztt_##t##_1x1_t
#define EO_T(t) EO_T_(t)
typedef EO_CARRIER eo_element;
#define EO_ARGS const eo_element *in, const eo_element *old, \
  eo_element *out, eo_element *saved, long e
#define EO_LOAD EO_T(EO_TYPE) a = EO_NAME(mls_rm, EO_TYPE) (in)
#define EO_ACC(a, b) EO_NAME(mldexpacc_ew_x, EO_TYPE) (a, b, e)
#ifdef __cplusplus
extern "C" {
#endif
extern void eo_callee (void);

void eo_same (EO_ARGS)
{
  EO_LOAD;
  EO_T(EO_TYPE) d = EO_ACC (a, a);
  __riscv_ztt_mss_rm (out, d);
}

void eo_live (EO_ARGS)
{
  EO_LOAD;
  EO_T(EO_TYPE) d = EO_ACC (a, a);
  __riscv_ztt_mss_rm (out, d);
  __riscv_ztt_mss_rm (saved, a);
}

void eo_distinct (EO_ARGS)
{
  EO_LOAD;
  EO_T(EO_TYPE) b = EO_NAME(mls_rm, EO_TYPE) (old);
  EO_T(EO_TYPE) d = EO_ACC (b, a);
  __riscv_ztt_mss_rm (out, d);
}

void eo_chain (EO_ARGS)
{
  EO_LOAD;
  EO_T(EO_TYPE) b = EO_ACC (a, a);
  EO_T(EO_TYPE) d = EO_ACC (b, b);
  __riscv_ztt_mss_rm (out, d);
}

void eo_call (EO_ARGS)
{
  EO_LOAD;
  eo_callee ();
  EO_T(EO_TYPE) d = EO_ACC (a, a);
  __riscv_ztt_mss_rm (out, d);
}

void eo_asm (EO_ARGS)
{
  EO_LOAD;
  __asm__ volatile ("" : : : "memory");
  EO_T(EO_TYPE) d = EO_ACC (a, a);
  __riscv_ztt_mss_rm (out, d);
}

void eo_reference (EO_ARGS)
{
  EO_LOAD;
  __riscv_ztt_mss_rm (out, a);
}
#ifdef __cplusplus
}
#endif
