#include "ztt-wide-copy.h"

#ifdef __cplusplus
extern "C" {
#endif

void
wc_exp_dead (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b = WC_COPY (a);
  wc_callee ();
  WC_T(WC_TYPE) d = WC_NAME (mldexpacc_ew_x, WC_TYPE) (a, b, e);
  __riscv_ztt_mss_rm (out, d);
}

void
wc_exp_distinct (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b = WC_NAME (mls_rm, WC_TYPE) (saved);
  wc_callee ();
  WC_T(WC_TYPE) d = WC_NAME (mldexpacc_ew_x, WC_TYPE) (a, b, e);
  __riscv_ztt_mss_rm (out, d);
}

void
wc_exp_modified (WC_ARGS)
{
  WC_LOAD;
  WC_T(WC_TYPE) b = WC_COPY (a);
  __asm__ volatile ("" : "+Wmr" (b));
  wc_callee ();
  WC_T(WC_TYPE) d = WC_NAME (mldexpacc_ew_x, WC_TYPE) (a, b, e);
  __riscv_ztt_mss_rm (out, d);
}

#ifdef __cplusplus
}
#endif
