#include <riscv_ztt.h>
#ifndef WC_TYPE
#define WC_TYPE i128_rnu
#define WC_CARRIER __riscv_ztt_i128_storage_t
#endif
#define WC_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define WC_NAME(f, t) WC_NAME_(f, t)
#define WC_T_(t) __riscv_ztt_##t##_1x1_t
#define WC_T(t) WC_T_(t)
typedef WC_CARRIER element_t;
#define WC_ARGS const element_t *in, element_t *out, element_t *saved, long e
#define WC_LOAD WC_T(WC_TYPE) a = WC_NAME(mls_rm, WC_TYPE) (in)
#define WC_COPY(x) WC_NAME(mcopy_m2m, WC_TYPE) (x)
#define WC_SAVE(d, b) __riscv_ztt_mss_rm(out, d); __riscv_ztt_mss_rm(saved, b)
#ifdef __cplusplus
extern "C" {
#endif
extern void wc_callee (void);
void wc_add_one (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b=WC_COPY(a);
  WC_T(WC_TYPE) d=WC_NAME(madd_ew, WC_TYPE)(a,b);
  WC_SAVE(d,b);
}
void wc_add_chain (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b=WC_COPY(a), c=WC_COPY(b), d=WC_COPY(c), z=WC_COPY(d);
  WC_T(WC_TYPE) result=WC_NAME(madd_ew, WC_TYPE)(a,z);
  WC_SAVE(result,z);
}
void wc_add_call (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b=WC_COPY(a);
  wc_callee();
  WC_T(WC_TYPE) d=WC_NAME(madd_ew, WC_TYPE)(a,b);
  WC_SAVE(d,b);
}
void wc_mul (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b=WC_COPY(a);
  WC_T(WC_TYPE) d=WC_NAME(mmul_ew, WC_TYPE)(a,b);
  WC_SAVE(d,b);
}
void wc_exp_old (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b=WC_COPY(a);
  WC_T(WC_TYPE) d=WC_NAME(mldexpacc_ew_x, WC_TYPE)(b,a,e);
  WC_SAVE(d,b);
}
void wc_exp_data (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b=WC_COPY(a);
  WC_T(WC_TYPE) d=WC_NAME(mldexpacc_ew_x, WC_TYPE)(a,b,e);
  WC_SAVE(d,b);
}
void wc_exp_call (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b=WC_COPY(a);
  wc_callee();
  WC_T(WC_TYPE) d=WC_NAME(mldexpacc_ew_x, WC_TYPE)(b,a,e);
  WC_SAVE(d,b);
}
#ifdef __cplusplus
}
#endif
