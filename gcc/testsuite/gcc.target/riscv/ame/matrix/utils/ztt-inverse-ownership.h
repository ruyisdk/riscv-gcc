#include <stdint.h>
#include <riscv_ztt.h>

void inverse_unowned (int32_t *out, const int32_t *in)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_i32_rnu_1x2_t p = __riscv_ztt_mls_rm_i32_rnu_1x2 (in);
  __riscv_ztt_ame_release ();
  __riscv_ztt_i32_rnu_1x2_t q = __riscv_ztt_mcolzip_ew_i32_rnu_1x2 (p);
  __riscv_ztt_i32_rnu_1x2_t r = __riscv_ztt_mcolunzip_ew_i32_rnu_1x2 (q);
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_mss_rm (out, r);
  __riscv_ztt_ame_release ();
}
