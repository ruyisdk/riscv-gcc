#include "ztt-scalar-type.h"

#ifdef __cplusplus
extern "C" {
#endif

void
tc_old_switch (__INT32_TYPE__ *out, const __INT32_TYPE__ *in,
               __UINTPTR_TYPE__ x, __UINTPTR_TYPE__ y)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  __riscv_ztt_i32_1x1_t d = __riscv_ztt_mls_rm_i32_1x1 (out);
  d = __riscv_ztt_mmulacc_ew_x_i32_rnu_1x1_i32_rne
    (d, a, __riscv_ztt_scalar_from_bits_i32_rne (x));
  d = __riscv_ztt_mmulsub_ew_x_i32_rnu_1x1_i32_rdn
    (d, a, __riscv_ztt_scalar_from_bits_i32_rdn (y));
  d = __riscv_ztt_mmulacc_ew_x_i32_rnu_1x1_i32_rne
    (d, a, __riscv_ztt_scalar_from_bits_i32_rne (x));
  __riscv_ztt_mss_rm (out, d);
}

#ifdef __cplusplus
}
#endif
