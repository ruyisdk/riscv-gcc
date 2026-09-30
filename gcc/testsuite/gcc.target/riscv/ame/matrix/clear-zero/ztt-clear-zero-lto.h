/* Experimental single-M clear/zero names from intrinsic draft v0.2.4.  */

#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C"
#endif
void
clear_zero_lto (signed char *out)
{
  __riscv_ztt_i8_rne_1x1_t cleared = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t new_zero = __riscv_ztt_mzero_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t old_zero = __riscv_ztt_mzero_2d_m_i8_rne_1x1 ();
  __riscv_ztt_mss_rm (out, __riscv_ztt_madd_ew_i8_rne_1x1
                          (cleared, new_zero));
  __riscv_ztt_mss_rm (out, old_zero);
}
