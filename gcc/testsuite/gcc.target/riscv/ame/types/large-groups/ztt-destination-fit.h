#include <riscv_ztt.h>
typedef __UINT64_TYPE__ df_wide;
typedef __UINT32_TYPE__ df_narrow;
#ifdef __cplusplus
extern "C" {
#endif
#define DF_CASE(N, OP, LHS, RHS) \
void df_##N (const df_wide *left, const df_narrow *right, df_wide *out, \
            df_wide *saved, df_narrow *saved_other) \
{ \
  __riscv_ztt_u64_rnu_1x1_t a = __riscv_ztt_mls_rm_u64_rnu_1x1 (left); \
  __riscv_ztt_u32_rnu_1x1_t b = __riscv_ztt_mls_rm_u32_rnu_1x1 (right); \
  __riscv_ztt_u64_rnu_1x1_t c = __riscv_ztt_##OP##_u64_rnu_1x1 (LHS, RHS); \
  __riscv_ztt_mss_rm (out, c); \
  __riscv_ztt_mss_rm (saved, a); \
  __riscv_ztt_mss_rm (saved_other, b); \
}
DF_CASE(left, madd_ew, a, b)
DF_CASE(right, msub_ew, b, a)
DF_CASE(same, mmul_ew, a, a)

void df_shared (const df_wide *in, df_wide *out, df_wide *saved)
{
  __riscv_ztt_u64_rnu_1x1_t a = __riscv_ztt_mls_rm_u64_rnu_1x1 (in);
  __riscv_ztt_u64_rod_1x1_t b = __riscv_ztt_madd_ew_u64_rod_1x1 (a, a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (saved, a);
}
#ifdef __cplusplus
}
#endif
