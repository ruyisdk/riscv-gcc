#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
extern void descriptor_callee (void);

#define CHAIN(NAME, T, C, OP, GAP) \
void NAME (const C *in, C *out, int index, int other, int flag) \
{ \
  __riscv_ztt_##T##_1x1_t a = __riscv_ztt_mls_rm_##T##_1x1 (in); \
  a = __riscv_ztt_##OP##_##T##_1x1 (a, index); \
  GAP; \
  if (flag) \
    { \
      a = __riscv_ztt_madd_ew_##T##_1x1 (a, a); \
      a = __riscv_ztt_##OP##_##T##_1x1 (a, other); \
      __riscv_ztt_mss_rm (out, a); \
    } \
}
CHAIN (row, i32_rnu, __INT32_TYPE__, mrowbcast_ew_x, (void) 0)
CHAIN (fp_row, f32_rne, float, mrowbcast_ew_x, (void) 0)
CHAIN (shift, i32_rnu, __INT32_TYPE__, mcolshift_ew_x, (void) 0)
CHAIN (fp_call, f32_rne, float, mrowbcast_ew_x, descriptor_callee ())
CHAIN (fp_asm, f32_rne, float, mrowbcast_ew_x,
       __asm__ volatile ("" ::: "memory"))
CHAIN (fp_join, f32_rne, float, mrowbcast_ew_x,
       if (index) descriptor_callee ())
#undef CHAIN

void scalar (const __INT32_TYPE__ *in, __INT32_TYPE__ *out,
             __UINTPTR_TYPE__ x, __UINTPTR_TYPE__ y, int flag)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  a = __riscv_ztt_madd_ew_x_i32_rnu_1x1_i32_rne
    (a, __riscv_ztt_scalar_from_bits_i32_rne (x));
  if (flag)
    {
      a = __riscv_ztt_mmul_ew_x_i32_rnu_1x1_i32_rne
        (a, __riscv_ztt_scalar_from_bits_i32_rne (y));
      __riscv_ztt_mss_rm (out, a);
    }
}

void old_dest (const __INT32_TYPE__ *in, __INT32_TYPE__ *out,
               __UINTPTR_TYPE__ x, __UINTPTR_TYPE__ y, int flag)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  __riscv_ztt_i32_1x1_t d = __riscv_ztt_mls_rm_i32_1x1 (out);
  d = __riscv_ztt_mmulacc_ew_x_i32_rnu_1x1_i32_rne
    (d, a, __riscv_ztt_scalar_from_bits_i32_rne (x));
  if (flag)
    {
      d = __riscv_ztt_mmulsub_ew_x_i32_rnu_1x1_i32_rne
        (d, a, __riscv_ztt_scalar_from_bits_i32_rne (y));
      __riscv_ztt_mss_rm (out, d);
    }
}
#ifdef __cplusplus
}
#endif
