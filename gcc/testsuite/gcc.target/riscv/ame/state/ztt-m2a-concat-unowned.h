#include <riscv_ztt.h>
void unowned(const __INT32_TYPE__ *in,const __INT32_TYPE__ *other,
             __INT32_TYPE__ *out)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  __riscv_ztt_i32_1x1_t b = __riscv_ztt_mls_rm_i32_1x1 (other);
  __riscv_ztt_ame_release ();
  __riscv_ztt_i32_1x2_t p = __riscv_ztt_mconcat_m_i32_1x2 (a,b);
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_i32_accx2_t v = __riscv_ztt_mcopy_m2a_i32_accx2 (p);
  __riscv_ztt_mss_rm (out,__riscv_ztt_mcopy_a2m_i32_1x2 (v));
  __riscv_ztt_ame_release ();
}
