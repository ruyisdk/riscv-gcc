#include <stdint.h>
#include <riscv_ztt.h>

extern void may_throw ();

void probe (int32_t *out, const int32_t *in)
{
#if ZTT_SHIFT_CASE <= 1
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
#endif
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
#if ZTT_SHIFT_CASE <= 1
  __riscv_ztt_ame_release ();
#else
  (void) __riscv_ztt_get_ameown ();
  try { may_throw (); }
  catch (...) { }
#if ZTT_SHIFT_CASE == 5
  if (!__riscv_ztt_get_ameown ())
    return;
#endif
#endif
#if ZTT_SHIFT_CASE == 1
  __riscv_ztt_i32_rnu_1x1_t b =
    __riscv_ztt_mcolshift_ew_x_i32_rnu_1x1 (a, 0);
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_ame_release ();
#else
  (void) __riscv_ztt_mrowshift_ew_x_i32_rnu_1x1 (a, 0);
#endif
}
