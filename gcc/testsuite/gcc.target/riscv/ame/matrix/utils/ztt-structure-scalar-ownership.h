#include <riscv_ztt.h>

unsigned unowned_scalar_projection (__INT32_TYPE__ *out,
                                    const __INT32_TYPE__ *in, unsigned index)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return index;
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  __riscv_ztt_i32_1x1_t b = __riscv_ztt_mls_rm_i32_1x1 (in);
  __riscv_ztt_ame_release ();
  __riscv_ztt_i32_1x2_t p = __riscv_ztt_mconcat_m_i32_1x2 (a, b);
  unsigned result = index * 7 + 5;
  __riscv_ztt_i32_1x1_t x = __riscv_ztt_mextract_i32_1x1 (p, 1);
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return result;
  __riscv_ztt_mss_rm (out, x);
  __riscv_ztt_ame_release ();
  return result;
}
