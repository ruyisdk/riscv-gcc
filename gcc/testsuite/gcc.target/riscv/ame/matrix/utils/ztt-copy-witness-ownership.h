#include <stdint.h>
#include <riscv_ztt.h>

void copy_witness_unowned (int32_t *out, const int32_t *in)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_i32_rnu_1x2_t p = __riscv_ztt_mls_rm_i32_rnu_1x2 (in);
#ifndef CW_TERMINAL
  __riscv_ztt_ame_release ();
#endif
  __riscv_ztt_i32_rnu_1x2_t q = __riscv_ztt_mcolzip_ew_i32_rnu_1x2 (p);
#ifdef CW_TERMINAL
  __riscv_ztt_ame_release ();
#endif
  (void) __riscv_ztt_mcopy_m2m_i32_rnu_1x2 (q);
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mextract_i32_rnu_1x1 (p, 0);
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mextract_i32_rnu_1x1 (p, 1);
  __riscv_ztt_i32_rnu_1x2_t r = __riscv_ztt_mconcat_m_i32_rnu_1x2 (a, b);
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_mss_rm (out, r);
  __riscv_ztt_ame_release ();
}
