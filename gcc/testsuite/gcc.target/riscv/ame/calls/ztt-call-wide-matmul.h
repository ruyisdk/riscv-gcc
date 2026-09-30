/* One full M bank and a wide ACC survive a call, then feed matmul.
   No inline-asm register constraints are used in this fixture.  */
#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
extern int call_boundary (int);

int wide_after_call (const __riscv_ztt_i128_storage_t *in,
                     __riscv_ztt_i128_storage_t *out)
{
  __riscv_ztt_i128_rod_1x1_t m = __riscv_ztt_mls_rm_i128_rod_1x1 (in);
  __riscv_ztt_i128_rod_accx1_t a = __riscv_ztt_mcopy_m2a_i128_rod_accx1 (m);
  int result = call_boundary (1);
  a = __riscv_ztt_mmulacc_2d_i128_rod_accx1 (a, m, m);
  __riscv_ztt_mss_rm_i128_rod_1x1
    (out, __riscv_ztt_mcopy_a2m_i128_rod_1x1 (a));
  return result;
}

#define MATMUL_VARIANT(NAME, OP) \
int NAME (const __riscv_ztt_i128_storage_t *in, \
          __riscv_ztt_i128_storage_t *out) \
{ \
  __riscv_ztt_i128_rod_1x1_t m = __riscv_ztt_mls_rm_i128_rod_1x1 (in); \
  __riscv_ztt_i128_rod_accx1_t a = __riscv_ztt_mcopy_m2a_i128_rod_accx1 (m); \
  int result = call_boundary (1); \
  a = __riscv_ztt_##OP##_i128_rod_accx1 (a, m, m); \
  __riscv_ztt_mss_rm_i128_rod_1x1 \
    (out, __riscv_ztt_mcopy_a2m_i128_rod_1x1 (a)); \
  return result; \
}
MATMUL_VARIANT (wide_negative, mmulaccneg_2d)
MATMUL_VARIANT (wide_at, mmulatacc_2d)
MATMUL_VARIANT (wide_at_negative, mmulataccneg_2d)
MATMUL_VARIANT (wide_bt, mmulbtacc_2d)
MATMUL_VARIANT (wide_bt_negative, mmulbtaccneg_2d)
#undef MATMUL_VARIANT

#ifdef __cplusplus
}
#endif
