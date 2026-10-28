#include <riscv_ztt.h>

typedef __INT32_TYPE__ i32;

extern void stack_raw_call (void);
extern i32 stack_raw_limit (i32);

void
stack_raw_offset (i32 *out, const i32 *in)
{
  __riscv_ztt_i32_rnu_1x1_t value = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  stack_raw_call ();
  __riscv_ztt_mss_rm (out, value);
}

void
stack_raw_base (i32 *out, const i32 *in, const i32 *bias, i32 upper)
{
  __riscv_ztt_i32_rnu_1x1_t x = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mls_st_i32_rnu_1x1 (bias, 0);
  __riscv_ztt_i32_rnu_1x1_t y = __riscv_ztt_madd_ew_i32_rnu_1x1 (x, b);
  upper = stack_raw_limit (upper);
  y = __riscv_ztt_mmax_ew_x_i32_rnu_1x1_i32_rnu
    (y, __riscv_ztt_scalar_make_i32_rnu (0));
  y = __riscv_ztt_mmin_ew_x_i32_rnu_1x1_i32_rnu
    (y, __riscv_ztt_scalar_make_i32_rnu (upper));
  __riscv_ztt_mss_rm (out, y);
}
