/* Mixed-width ACC values.  */
#include <stdint.h>
#include <riscv_ztt.h>
#if __riscv_ztt_acc_matmul_variants != 63
#error six same-type accumulator matmul variants required
#endif
#define EACH32(M) \
  M (i32_rnu, int32_t, 0) M (i32_rne, int32_t, 1) \
  M (i32_rdn, int32_t, 2) M (i32_rod, int32_t, 3) \
  M (u32_rnu, uint32_t, 4) M (u32_rne, uint32_t, 5) \
  M (u32_rdn, uint32_t, 6) M (u32_rod, uint32_t, 7)
#if __riscv_ztt_uds <= 16
#if __riscv_ztt_i16_u16_accx1_irm != 15
#error i16 ACC capability required
#endif
#define EACH16(M) \
  M (i16_rnu, int16_t, 8) M (i16_rne, int16_t, 9) \
  M (i16_rdn, int16_t, 10) M (i16_rod, int16_t, 11) \
  M (u16_rnu, uint16_t, 12) M (u16_rne, uint16_t, 13) \
  M (u16_rdn, uint16_t, 14) M (u16_rod, uint16_t, 15)
#else
#define EACH16(M)
#ifdef __riscv_ztt_i16_u16_accx1_irm
#error packed i16 ACC capability must be absent
#endif
#endif
#if __riscv_ztt_uds == 8
#if __riscv_ztt_i8_u8_accx1_irm != 15
#error i8 ACC capability required
#endif
#define EACH8(M) \
  M (i8_rnu, int8_t, 16) M (i8_rne, int8_t, 17) \
  M (i8_rdn, int8_t, 18) M (i8_rod, int8_t, 19) \
  M (u8_rnu, uint8_t, 20) M (u8_rne, uint8_t, 21) \
  M (u8_rdn, uint8_t, 22) M (u8_rod, uint8_t, 23)
#define COUNT 24
#else
#define EACH8(M)
#define COUNT (__riscv_ztt_uds == 16 ? 16 : 8)
#ifdef __riscv_ztt_i8_u8_accx1_irm
#error packed i8 ACC capability must be absent
#endif
#endif
#define EACH(M) EACH32(M) EACH16(M) EACH8(M)
#ifdef SINGLE_I8
#undef EACH
#undef COUNT
#define EACH(M) M (i8_rnu, int8_t, 0)
#define COUNT 1
#endif
#define INIT(T, C, I) \
  __riscv_ztt_##T##_1x1_t v##I \
    = __riscv_ztt_mls_rm_##T##_1x1 ((const C *) in[I]); \
  __riscv_ztt_##T##_accx1_t a##I \
    = __riscv_ztt_mcopy_m2a_##T##_accx1 (v##I); \
  __riscv_ztt_##T##_1x1_t l##I \
    = __riscv_ztt_mls_rm_##T##_1x1 ((const C *) in[COUNT + I]); \
  __riscv_ztt_##T##_1x1_t r##I \
    = __riscv_ztt_mls_rm_##T##_1x1 ((const C *) in[2 * COUNT + I]);
#define OP(T, C, I, NAME, J) \
  __riscv_ztt_mss_rm ((C *) out[COUNT * J + I], \
    __riscv_ztt_mcopy_a2m_##T##_1x1 ( \
      __riscv_ztt_##NAME##_2d_##T##_accx1 (a##I, \
        branch ? r##I : l##I, branch ? l##I : r##I)));
#define RUN(T, C, I) \
  OP (T, C, I, mmulacc, 0) OP (T, C, I, mmulaccneg, 1) \
  OP (T, C, I, mmulatacc, 2) OP (T, C, I, mmulataccneg, 3) \
  OP (T, C, I, mmulbtacc, 4) OP (T, C, I, mmulbtaccneg, 5)
#define OLD(T, C, I) \
  __riscv_ztt_mss_rm ((C *) out[6 * COUNT + I], \
    __riscv_ztt_mcopy_a2m_##T##_1x1 (a##I)); \
  __riscv_ztt_mss_rm ((C *) out[7 * COUNT + I], l##I); \
  __riscv_ztt_mss_rm ((C *) out[8 * COUNT + I], r##I); \
  __riscv_ztt_mss_rm ((C *) out[9 * COUNT + I], \
    __riscv_ztt_mcopy_a2m_##T##_1x1 (__riscv_ztt_mclear_acc_##T##_accx1 ())); \
  __riscv_ztt_mss_rm ((C *) out[10 * COUNT + I], \
    __riscv_ztt_mcopy_a2m_##T##_1x1 (__riscv_ztt_mzero_acc_##T##_accx1 ()));
#ifdef __cplusplus
extern "C"
#endif
void acc_width_kernel (const void **in, void **out, int branch)
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
#undef EACH8
#undef EACH16
#undef EACH32
#undef COUNT
