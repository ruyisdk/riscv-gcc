#include <riscv_ztt.h>
typedef __riscv_ztt_i64_rnu_1x1_t wide;
typedef __riscv_ztt_i32_rnu_1x1_t narrow;
#define INPUT wide a = __riscv_ztt_mls_rm_i64_rnu_1x1 (in); \
  a = __riscv_ztt_mrowbcast_ew_x_i64_rnu_1x1 (a, k); \
  narrow b = __riscv_ztt_mconv_ew_i32_rnu_1x1 (a)
void ul_extremum (unsigned long k, const __INT64_TYPE__ *in, __INT32_TYPE__ *out)
{
  INPUT;
  __riscv_ztt_mss_rm (out, __riscv_ztt_mreducemax_col_i32_rnu_1x1 (b));
}
void ul_other_axis (unsigned long k, const __INT64_TYPE__ *in, __INT32_TYPE__ *out)
{
  INPUT;
  __riscv_ztt_mss_rm (out, __riscv_ztt_mreducemax_row_i32_rnu_1x1 (b));
}
void ul_two_conversions (unsigned long k, const __INT64_TYPE__ *in,
                        const __INT32_TYPE__ *index, __INT64_TYPE__ *out,
                        __INT32_TYPE__ *saved)
{
  narrow i = __riscv_ztt_mls_rm_i32_rnu_1x1 (index);
  INPUT;
  wide c = __riscv_ztt_mconv_ew_i64_rnu_1x1 (b);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mrowgather_ew_i64_rnu_1x1 (c, i));
  __riscv_ztt_mss_rm (saved, i);
}
