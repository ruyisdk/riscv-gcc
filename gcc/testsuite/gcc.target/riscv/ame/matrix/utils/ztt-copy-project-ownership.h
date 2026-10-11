#include <stdint.h>
#include <riscv_ztt.h>

#ifndef CP_COPY
#define CP_COPY(X) __riscv_ztt_mcopy_m2m_i32_rnu_1x2 (X)
#endif

void copy_project_unowned (int32_t *out, const int32_t *in)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
#ifndef CP_ONLY_COPY
  __riscv_ztt_ame_release ();
#endif
  __riscv_ztt_i32_rnu_1x2_t p = __riscv_ztt_mconcat_m_i32_rnu_1x2 (a, b);
#ifdef CP_ONLY_COPY
  __riscv_ztt_ame_release ();
#endif
  __riscv_ztt_i32_rnu_1x2_t q = CP_COPY (p);
  __riscv_ztt_i32_rnu_1x1_t r = __riscv_ztt_mextract_i32_rnu_1x1 (q, 0);
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_mss_rm (out, r);
  __riscv_ztt_ame_release ();
}
