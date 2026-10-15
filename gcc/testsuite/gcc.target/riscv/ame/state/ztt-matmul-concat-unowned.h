#include <riscv_ztt.h>
void unowned (const __INT32_TYPE__ *in, const __INT32_TYPE__ *other,
              __INT32_TYPE__ *out)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  __riscv_ztt_i32_1x1_t b = __riscv_ztt_mls_rm_i32_1x1 (other);
  __riscv_ztt_i32_2x1_t q = __riscv_ztt_mls_rm_i32_2x1 (in);
  __riscv_ztt_i32_accx1_t old = __riscv_ztt_mzero_acc_i32_accx1 ();
  __riscv_ztt_ame_release ();
  __riscv_ztt_i32_1x2_t p = __riscv_ztt_mconcat_m_i32_1x2 (a,b);
  __riscv_ztt_i32_accx1_t d = __riscv_ztt_mmulacc_2d_i32_accx1 (old,p,q);
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_mss_rm (out,__riscv_ztt_mcopy_a2m_i32_1x1 (d));
  __riscv_ztt_ame_release ();
}
