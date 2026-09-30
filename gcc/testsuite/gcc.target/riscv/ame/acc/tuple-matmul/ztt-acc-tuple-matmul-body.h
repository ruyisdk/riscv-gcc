/* Tuple matmul old-tail liveness.  */
#include <stdint.h>
#include <riscv_ztt.h>
#if __riscv_ztt_acc_tuple_matmul_1x1 != 63
#error all six same-type 1x1 tuple matmul variants required
#endif
#define TYPES(M, D, C, U, K, A, B, E, F, G, H, I, J) \
  M (i##D##_rnu, C, K, A) M (i##D##_rne, C, K, B) \
  M (i##D##_rdn, C, K, E) M (i##D##_rod, C, K, F) \
  M (u##D##_rnu, U, K, G) M (u##D##_rne, U, K, H) \
  M (u##D##_rdn, U, K, I) M (u##D##_rod, U, K, J)
#if __riscv_ztt_uds == 8
#define PRIMARY(M, K, A, B, E, F, G, H, I, J) \
  TYPES (M, 8, int8_t, uint8_t, K, A, B, E, F, G, H, I, J)
#define SECONDARY(M, A, B, E, F, G, H, I, J) \
  TYPES (M, 16, int16_t, uint16_t, 2, A, B, E, F, G, H, I, J)
#elif __riscv_ztt_uds == 16
#define PRIMARY(M, K, A, B, E, F, G, H, I, J) \
  TYPES (M, 16, int16_t, uint16_t, K, A, B, E, F, G, H, I, J)
#define SECONDARY(M, A, B, E, F, G, H, I, J) \
  TYPES (M, 32, int32_t, uint32_t, 2, A, B, E, F, G, H, I, J)
#else
#define PRIMARY(M, K, A, B, E, F, G, H, I, J) \
  TYPES (M, 32, int32_t, uint32_t, K, A, B, E, F, G, H, I, J)
#define SECONDARY(M, A, B, E, F, G, H, I, J)
#endif
#if __riscv_ztt_accregs >= 4
#define EACH(M) \
  PRIMARY (M, 2, 0, 1, 2, 3, 4, 5, 6, 7) \
  PRIMARY (M, 4, 8, 9, 10, 11, 12, 13, 14, 15) \
  SECONDARY (M, 16, 17, 18, 19, 20, 21, 22, 23)
#define COUNT (__riscv_ztt_uds == 32 ? 16 : 24)
#else
#define EACH(M) \
  PRIMARY (M, 2, 0, 1, 2, 3, 4, 5, 6, 7) \
  SECONDARY (M, 8, 9, 10, 11, 12, 13, 14, 15)
#define COUNT (__riscv_ztt_uds == 32 ? 8 : 16)
#endif
#ifdef SINGLE_I8
#undef EACH
#undef COUNT
#define EACH(M) M (i8_rnu, int8_t, 2, 0)
#define COUNT 1
#endif
#define INIT(T, C, K, I) \
  __riscv_ztt_##T##_accx##K##_t a##I \
    = __riscv_ztt_mcopy_m2a_##T##_accx##K ( \
      __riscv_ztt_mls_rm_##T##_1x##K ((const C *) in[I])); \
  __riscv_ztt_##T##_1x1_t l##I \
    = __riscv_ztt_mls_rm_##T##_1x1 ((const C *) in[COUNT + I]); \
  __riscv_ztt_##T##_1x1_t r##I \
    = __riscv_ztt_mls_rm_##T##_1x1 ((const C *) in[2 * COUNT + I]); \
  __riscv_ztt_##T##_accx1_t one##I \
    = __riscv_ztt_mcopy_m2a_##T##_accx1 (l##I);
#define OP(T, C, K, I, NAME, J) \
  __riscv_ztt_mss_rm ((C *) out[COUNT * J + I], \
    __riscv_ztt_mcopy_a2m_##T##_1x##K ( \
      __riscv_ztt_##NAME##_2d_##T##_accx##K (a##I, \
        branch ? r##I : l##I, branch ? l##I : r##I)));
#define RUN(T, C, K, I) \
  OP (T, C, K, I, mmulacc, 0) OP (T, C, K, I, mmulaccneg, 1) \
  OP (T, C, K, I, mmulatacc, 2) OP (T, C, K, I, mmulataccneg, 3) \
  OP (T, C, K, I, mmulbtacc, 4) OP (T, C, K, I, mmulbtaccneg, 5)
#define OLD(T, C, K, I) \
  __riscv_ztt_mss_rm ((C *) out[6 * COUNT + I], \
    __riscv_ztt_mcopy_a2m_##T##_1x##K (a##I)); \
  __riscv_ztt_mss_rm ((C *) out[7 * COUNT + I], l##I); \
  __riscv_ztt_mss_rm ((C *) out[8 * COUNT + I], r##I); \
  __riscv_ztt_mss_rm ((C *) out[9 * COUNT + I], \
    __riscv_ztt_mcopy_a2m_##T##_1x1 (one##I));
#ifdef __cplusplus
extern "C"
#endif
void acc_tuple_matmul_kernel (const void **in, void **out, int branch)
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
#undef COUNT
#undef SECONDARY
#undef PRIMARY
#undef TYPES
