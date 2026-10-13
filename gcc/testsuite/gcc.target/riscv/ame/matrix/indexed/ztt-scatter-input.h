#include <riscv_ztt.h>
#ifndef WC_TYPE
#define WC_TYPE u128_rnu
#define WC_CARRIER __riscv_ztt_u128_storage_t
#endif
#define WC_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define WC_NAME(f, t) WC_NAME_(f, t)
#define WC_T_(t) __riscv_ztt_##t##_1x1_t
#define WC_T(t) WC_T_(t)
typedef WC_CARRIER element_t;
#define WC_ARGS const element_t *in, const element_t *old, element_t *out, element_t *saved, element_t *old_saved
#define WC_LOAD WC_T(WC_TYPE) a = WC_NAME(mls_rm, WC_TYPE) (in); \
  WC_T(WC_TYPE) d = WC_NAME(mls_rm, WC_TYPE) (old)
#define WC_COPY(x) WC_NAME(mcopy_m2m, WC_TYPE) (x)
#define WC_SAVE(result, b) __riscv_ztt_mss_rm (out, result); \
  __riscv_ztt_mss_rm (saved, b); __riscv_ztt_mss_rm (old_saved, d)
#ifdef __cplusplus
extern "C" {
#endif
extern void wc_callee (void);

void wc_col_add (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) result = WC_NAME(mcolscatadd_ew, WC_TYPE) (d, a, a);
  WC_SAVE(result, a);
}
void wc_row_add (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b = WC_COPY(a);
  WC_T(WC_TYPE) result = WC_NAME(mrowscatadd_ew, WC_TYPE) (d, a, b);
  WC_SAVE(result, b);
}
void wc_col_max (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b = WC_COPY(a);
  WC_T(WC_TYPE) result = WC_NAME(mcolscatmax_ew, WC_TYPE) (d, b, a);
  WC_SAVE(result, a);
}
void wc_row_max (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) result = WC_NAME(mrowscatmax_ew, WC_TYPE) (d, a, a);
  WC_SAVE(result, a);
}
void wc_chain (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b = WC_COPY(a), c = WC_COPY(b), e = WC_COPY(c), z = WC_COPY(e);
  WC_T(WC_TYPE) result = WC_NAME(mcolscatadd_ew, WC_TYPE) (d, a, z);
  WC_SAVE(result, z);
}
void wc_call (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b = WC_COPY(a);
  wc_callee ();
  WC_T(WC_TYPE) result = WC_NAME(mrowscatmax_ew, WC_TYPE) (d, a, b);
  WC_SAVE(result, b);
}
#ifdef __cplusplus
}
#endif
