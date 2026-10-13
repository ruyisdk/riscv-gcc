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
#define WC_ARGS const element_t *in, element_t *out, element_t *saved, long e
#define WC_LOAD WC_T(WC_TYPE) a = WC_NAME(mls_rm, WC_TYPE) (in)
#define WC_COPY(x) WC_NAME(mcopy_m2m, WC_TYPE) (x)
#define WC_SAVE(d, b) __riscv_ztt_mss_rm (out, d); __riscv_ztt_mss_rm (saved, b)
#ifdef __cplusplus
extern "C" {
#endif
extern void wc_callee (void);

void wc_col_same (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) d = WC_NAME(mcolgather_ew, WC_TYPE) (a, a);
  WC_SAVE(d, a);
}

void wc_row_same (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) d = WC_NAME(mrowgather_ew, WC_TYPE) (a, a);
  WC_SAVE(d, a);
}

void wc_col_copy (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b = WC_COPY(a);
  WC_T(WC_TYPE) d = WC_NAME(mcolgather_ew, WC_TYPE) (a, b);
  WC_SAVE(d, b);
}

void wc_row_copy (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b = WC_COPY(a);
  WC_T(WC_TYPE) d = WC_NAME(mrowgather_ew, WC_TYPE) (a, b);
  WC_SAVE(d, b);
}

void wc_chain (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b = WC_COPY(a), c = WC_COPY(b), d = WC_COPY(c), z = WC_COPY(d);
  WC_T(WC_TYPE) result = WC_NAME(mcolgather_ew, WC_TYPE) (a, z);
  WC_SAVE(result, z);
}

void wc_call (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b = WC_COPY(a);
  wc_callee ();
  WC_T(WC_TYPE) d = WC_NAME(mrowgather_ew, WC_TYPE) (a, b);
  WC_SAVE(d, b);
}

void wc_swapped (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b = WC_COPY(a);
  WC_T(WC_TYPE) d = WC_NAME(mcolgather_ew, WC_TYPE) (b, a);
  WC_SAVE(d, a);
}
#ifdef __cplusplus
}
#endif
