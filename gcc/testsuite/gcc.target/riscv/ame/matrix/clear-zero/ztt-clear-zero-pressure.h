/* Experimental single-M clear/zero names from intrinsic draft v0.2.4.  */

#include <riscv_ztt.h>

void
clear_pressure (signed char *out)
{
  __riscv_ztt_i8_rne_1x1_t v0 = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t v1 = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t v2 = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t v3 = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t v4 = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t v5 = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t v6 = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t v7 = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t v8 = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t v9 = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t v10 = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t v11 = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t v12 = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t v13 = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t v14 = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t v15 = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t v16 = __riscv_ztt_mclear_m_i8_rne_1x1 ();

  __asm__ volatile ("" ::: "memory");

  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v1);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v2);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v3);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v4);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v5);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v6);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v7);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v8);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v9);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v10);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v11);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v12);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v13);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v14);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v15);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v16);
  __riscv_ztt_mss_rm (out, v0);
}
