/* Matmul variants.  */
#include <stdint.h>
#include <riscv_ztt.h>
#if __riscv_ztt_acc_matmul_variants != 63
#error six same-type accumulator matmul variants required
#endif
#define EACH(M) \
  M (i32_rnu, int32_t, 0) \
  M (i32_rne, int32_t, 1) \
  M (i32_rdn, int32_t, 2) \
  M (i32_rod, int32_t, 3) \
  M (u32_rnu, uint32_t, 4) \
  M (u32_rne, uint32_t, 5) \
  M (u32_rdn, uint32_t, 6) \
  M (u32_rod, uint32_t, 7)
#define INIT(T, C, I) \
  __riscv_ztt_##T##_1x1_t v##I \
    = __riscv_ztt_mls_rm_##T##_1x1 ((const C *) in[I]); \
  __riscv_ztt_##T##_accx1_t a##I \
    = __riscv_ztt_mcopy_m2a_##T##_accx1 (v##I); \
  __riscv_ztt_##T##_1x1_t l##I \
    = __riscv_ztt_mls_rm_##T##_1x1 ((const C *) in[8 + I]); \
  __riscv_ztt_##T##_1x1_t r##I \
    = __riscv_ztt_mls_rm_##T##_1x1 ((const C *) in[16 + I]);
#define OP(T, C, I, NAME, J) \
  __riscv_ztt_mss_rm ((C *) out[8 * J + I], \
    __riscv_ztt_mcopy_a2m_##T##_1x1 ( \
      __riscv_ztt_##NAME##_2d_##T##_accx1 (a##I, \
        branch ? r##I : l##I, branch ? l##I : r##I)));
#define RUN(T, C, I) \
  OP (T, C, I, mmulacc, 0) \
  OP (T, C, I, mmulaccneg, 1) \
  OP (T, C, I, mmulatacc, 2) \
  OP (T, C, I, mmulataccneg, 3) \
  OP (T, C, I, mmulbtacc, 4) \
  OP (T, C, I, mmulbtaccneg, 5)
#define OLD(T, C, I) \
  __riscv_ztt_mss_rm ((C *) out[48 + I], \
    __riscv_ztt_mcopy_a2m_##T##_1x1 (a##I)); \
  __riscv_ztt_mss_rm ((C *) out[56 + I], l##I); \
  __riscv_ztt_mss_rm ((C *) out[64 + I], r##I);
#ifdef __cplusplus
extern "C"
#endif
void acc_matmul_kernel (const uint32_t **in, uint32_t **out, int branch)
{
  EACH (INIT)
  EACH (RUN)
  EACH (OLD)
}
#undef OLD
#undef RUN
#undef OP
#undef INIT
#undef EACH
