#include <riscv_ztt.h>
void unowned (__INT32_TYPE__ *out)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_ame_release ();
  __riscv_ztt_i32_accx2_t a = __riscv_ztt_mzero_acc_i32_accx2 ();
  __riscv_ztt_i32_1x2_t m = __riscv_ztt_mcopy_a2m_i32_1x2 (a);
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_mss_rm (out,m);
  __riscv_ztt_ame_release ();
}
