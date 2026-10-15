#include <riscv_ztt.h>
void unowned (const __INT32_TYPE__ *in, const __INT32_TYPE__ *other,
              __INT32_TYPE__ *out, __INT32_TYPE__ *saved)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mls_rm_i32_rnu_1x1 (other);
  __riscv_ztt_i32_rnu_1x1_t t = __riscv_ztt_mxor_ew_i32_rnu_1x1 (a, b);
  __riscv_ztt_ame_release ();
  __riscv_ztt_i32_rnu_1x1_t v = __riscv_ztt_mxor_ew_i32_rnu_1x1 (t, b);
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_mss_rm (saved, b);
  __riscv_ztt_mss_rm (out, v);
  __riscv_ztt_ame_release ();
}
