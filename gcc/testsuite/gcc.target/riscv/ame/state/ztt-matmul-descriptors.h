#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
extern void matmul_descriptor_callee (void);
#ifndef ACC_COUNT
#define ACC_COUNT 1
#endif

#define MATMUL_CHAIN_(NAME, OP, TYPE, CTYPE, K, GAP) \
__attribute__((noipa)) void NAME \
  (const CTYPE *in, CTYPE *out, CTYPE *last, int index, int flag) \
{ \
  __riscv_ztt_##TYPE##_1x1_t a = __riscv_ztt_mls_rm_##TYPE##_1x1 (in); \
  a = __riscv_ztt_mrowbcast_ew_x_##TYPE##_1x1 (a, index); \
  __riscv_ztt_##TYPE##_accx##K##_t b = __riscv_ztt_mzero_acc_##TYPE##_accx##K (); \
  b = __riscv_ztt_##OP##_2d_##TYPE##_accx##K (b, a, a); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_##TYPE##_1x##K (b)); \
  GAP; \
  __riscv_ztt_mss_rm (last, __riscv_ztt_madd_ew_##TYPE##_1x1 (a, a)); \
}
#define MATMUL_CHAIN_EXPAND(NAME, OP, TYPE, CTYPE, K, GAP) \
  MATMUL_CHAIN_ (NAME, OP, TYPE, CTYPE, K, GAP)
#define MATMUL_CHAIN(NAME, OP, TYPE, CTYPE, GAP) \
  MATMUL_CHAIN_EXPAND (NAME, OP, TYPE, CTYPE, ACC_COUNT, GAP)
MATMUL_CHAIN (descriptor_mul, mmulacc, f32_rne, float, (void) 0)
MATMUL_CHAIN (descriptor_neg, mmulaccneg, f32_rne, float, (void) 0)
MATMUL_CHAIN (descriptor_at, mmulatacc, f32_rne, float, (void) 0)
MATMUL_CHAIN (descriptor_atneg, mmulataccneg, f32_rne, float, (void) 0)
MATMUL_CHAIN (descriptor_bt, mmulbtacc, f32_rne, float, (void) 0)
MATMUL_CHAIN (descriptor_btneg, mmulbtaccneg, f32_rne, float, (void) 0)
MATMUL_CHAIN (descriptor_integer, mmulacc, i32_rnu, __INT32_TYPE__, (void) 0)
MATMUL_CHAIN (descriptor_asm, mmulacc, f32_rne, float,
              __asm__ volatile ("" ::: "memory"))
MATMUL_CHAIN (descriptor_call, mmulacc, f32_rne, float,
              matmul_descriptor_callee ())
MATMUL_CHAIN (descriptor_join, mmulacc, f32_rne, float,
              if (flag) matmul_descriptor_callee ())
#undef MATMUL_CHAIN
#undef MATMUL_CHAIN_EXPAND
#undef MATMUL_CHAIN_
#ifdef __cplusplus
}
#endif
