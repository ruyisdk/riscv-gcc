/* Existing RNU aliases overload.  */
#include <stdint.h>
#include <riscv_ztt.h>
#define CASE(T, C, Q, K) \
  void alias_##T##_q##Q##_k##K (const C *old, const C *in, C *out) \
  { \
    __riscv_ztt_##T##_accx##K##_t a = __riscv_ztt_mcopy_m2a_##T##_accx##K ( \
      __riscv_ztt_mls_rm_##T##_1x##K (old)); \
    __riscv_ztt_##T##_1x##Q##_t r = __riscv_ztt_mls_rm_##T##_1x##Q (in); \
    __riscv_ztt_##T##_##Q##x1_t c = __riscv_ztt_mls_rm_##T##_##Q##x1 (in); \
    a = __riscv_ztt_mmulacc_2d_##T##_accx##K (a, r, c); \
    a = __riscv_ztt_mmulaccneg_2d_##T##_accx##K (a, r, c); \
    a = __riscv_ztt_mmulatacc_2d_##T##_accx##K (a, r, r); \
    a = __riscv_ztt_mmulatacc_2d_##T##_accx##K (a, c, c); \
    a = __riscv_ztt_mmulataccneg_2d_##T##_accx##K (a, r, r); \
    a = __riscv_ztt_mmulataccneg_2d_##T##_accx##K (a, c, c); \
    a = __riscv_ztt_mmulbtacc_2d_##T##_accx##K (a, r, r); \
    a = __riscv_ztt_mmulbtacc_2d_##T##_accx##K (a, c, c); \
    a = __riscv_ztt_mmulbtaccneg_2d_##T##_accx##K (a, r, r); \
    a = __riscv_ztt_mmulbtaccneg_2d_##T##_accx##K (a, c, c); \
    __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_##T##_1x##K (a)); \
  }
#define PRIMARY(T, C) \
  CASE (T, C, 2, 1) CASE (T, C, 4, 1) CASE (T, C, 2, 2) CASE (T, C, 4, 2) \
  CASE (T, C, 2, 4) CASE (T, C, 4, 4)
#define SECONDARY(T, C) CASE (T, C, 2, 1) CASE (T, C, 2, 2)
#if __riscv_ztt_uds == 8
PRIMARY (i8, int8_t) PRIMARY (u8, uint8_t)
SECONDARY (i16, int16_t) SECONDARY (u16, uint16_t)
#elif __riscv_ztt_uds == 16
PRIMARY (i16, int16_t) PRIMARY (u16, uint16_t)
SECONDARY (i32, int32_t) SECONDARY (u32, uint32_t)
#else
PRIMARY (i32, int32_t) PRIMARY (u32, uint32_t)
#endif
#undef SECONDARY
#undef PRIMARY
#undef CASE
