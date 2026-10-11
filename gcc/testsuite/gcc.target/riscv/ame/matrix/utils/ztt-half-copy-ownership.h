#include <stdint.h>
#include <riscv_ztt.h>

#define HC_COPY(X) __riscv_ztt_mcopy_m2m_i32_rnu_1x1 (X)
#define HC_CHAIN(X) HC_COPY (HC_COPY (HC_COPY (HC_COPY (X))))

void half_copy_unowned (int32_t *out, const int32_t *in)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_i32_rnu_1x2_t p = __riscv_ztt_mls_rm_i32_rnu_1x2 (in);
#ifndef HC_ONLY_COPY
  __riscv_ztt_ame_release ();
#endif
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mextract_i32_rnu_1x1 (p, 0);
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mextract_i32_rnu_1x1 (p, 1);
#ifdef HC_ONLY_COPY
  __riscv_ztt_ame_release ();
#endif
  __riscv_ztt_i32_rnu_1x1_t x = HC_CHAIN (a);
  __riscv_ztt_i32_rnu_1x1_t y = HC_CHAIN (b);
  __riscv_ztt_i32_rnu_1x2_t q = __riscv_ztt_mconcat_m_i32_rnu_1x2 (x, y);
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_mss_rm (out, q);
  __riscv_ztt_ame_release ();
}
