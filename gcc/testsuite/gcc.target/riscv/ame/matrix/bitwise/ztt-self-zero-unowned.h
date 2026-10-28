#include <riscv_ztt.h>
void unowned (const __INT16_TYPE__ *in, __INT16_TYPE__ *out,
              __INT16_TYPE__ *saved)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_i16_rnu_2x1_t a = __riscv_ztt_mls_rm_i16_rnu_2x1 (in);
  __riscv_ztt_ame_release ();
  __riscv_ztt_i16_rnu_2x1_t v = __riscv_ztt_mxor_ew_i16_rnu_2x1 (a, a);
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_mss_rm (saved, a);
  __riscv_ztt_mss_rm (out, v);
  __riscv_ztt_ame_release ();
}
