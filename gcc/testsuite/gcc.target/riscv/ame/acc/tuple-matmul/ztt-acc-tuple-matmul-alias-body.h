/* RNU tuple matmul aliases.  */
#include <stdint.h>
#include <riscv_ztt.h>
#define OP(T, C, K, NAME) \
  __riscv_ztt_mss_rm (p, __riscv_ztt_mcopy_a2m_##T##_1x##K ( \
    __riscv_ztt_##NAME##_2d_##T##_accx##K (a, m, m)));
#define CHECK(T, C, K) \
void alias_##T##_##K (C *p) \
{ \
  __riscv_ztt_##T##_accx##K##_t a = __riscv_ztt_mzero_acc_##T##_accx##K (); \
  __riscv_ztt_##T##_1x1_t m = __riscv_ztt_mls_rm_##T##_1x1 (p); \
  OP (T, C, K, mmulacc) OP (T, C, K, mmulaccneg) \
  OP (T, C, K, mmulatacc) OP (T, C, K, mmulataccneg) \
  OP (T, C, K, mmulbtacc) OP (T, C, K, mmulbtaccneg) \
}
#ifdef __riscv_ztt_i8_u8_accx2_irm
CHECK (i8, int8_t, 2)
CHECK (u8, uint8_t, 2)
#endif
#ifdef __riscv_ztt_i8_u8_accx4_irm
CHECK (i8, int8_t, 4)
CHECK (u8, uint8_t, 4)
#endif
#ifdef __riscv_ztt_i16_u16_accx2_irm
CHECK (i16, int16_t, 2)
CHECK (u16, uint16_t, 2)
#endif
#ifdef __riscv_ztt_i16_u16_accx4_irm
CHECK (i16, int16_t, 4)
CHECK (u16, uint16_t, 4)
#endif
#ifdef __riscv_ztt_i32_u32_accx2_irm
CHECK (i32, int32_t, 2)
CHECK (u32, uint32_t, 2)
#endif
#ifdef __riscv_ztt_i32_u32_accx4_irm
CHECK (i32, int32_t, 4)
CHECK (u32, uint32_t, 4)
#endif
#undef CHECK
#undef OP
