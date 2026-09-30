/* controls.  */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>

void discarded (const int32_t *in, size_t control)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  __riscv_ztt_mcolbcast_ew_x_i32_1x1 (a, control);
  __riscv_ztt_mrowbcast_ew_x_i32_1x1 (a, control);
}

void signed_extremes (int32_t *a, int32_t *b, const int32_t *in)
{
  __riscv_ztt_i32_1x1_t src = __riscv_ztt_mls_rm_i32_1x1 (in);
  __riscv_ztt_mss_rm (a, __riscv_ztt_mcolshift_ew_x_i32_1x1 (src, INT32_MIN));
  __riscv_ztt_mss_rm (b, __riscv_ztt_mrowshift_ew_x_i32_1x1 (src, INT32_MAX));
}

void negative (int32_t *out, const int32_t *in)
{
  __riscv_ztt_i32_1x1_t src = __riscv_ztt_mls_rm_i32_1x1 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcolshift_ew_x_i32_1x1 (src, -1));
}

void side_effect (int32_t *out, const int32_t *in, volatile int *count)
{
  __riscv_ztt_i32_1x1_t src = __riscv_ztt_mls_rm_i32_1x1 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mrowshift_ew_x_i32_1x1 (src, (*count)++));
}

#if __riscv_xlen == 64
void high_word (int32_t *out, const int32_t *in)
{
  __riscv_ztt_i32_1x1_t src = __riscv_ztt_mls_rm_i32_1x1 (in);
  __riscv_ztt_mss_rm
    (out, __riscv_ztt_mcolbcast_ew_x_i32_1x1 (src, ((size_t) 1 << 32) + 1));
}
#endif
