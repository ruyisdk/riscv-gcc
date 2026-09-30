/* Default-RNU tuple aliases.  */
#include <stdint.h>
#include <riscv_ztt.h>
#define CHECK(T, C, K) \
void alias_##T##_##K (C *p) \
{ \
  __riscv_ztt_##T##_accx##K##_t a = __riscv_ztt_mclear_acc_##T##_accx##K (); \
  __riscv_ztt_mss_rm (p, __riscv_ztt_mcopy_a2m_##T##_1x##K (a)); \
  a = __riscv_ztt_mzero_acc_##T##_accx##K (); \
  __riscv_ztt_mss_rm (p, __riscv_ztt_mcopy_a2m_##T##_##K##x1 (a)); \
  a = __riscv_ztt_mcopy_m2a_##T##_accx##K ( \
    __riscv_ztt_mls_rm_##T##_##K##x1 (p)); \
  __riscv_ztt_mss_rm (p, __riscv_ztt_mcopy_a2m_##T##_1x##K (a)); \
}
#ifdef __riscv_ztt_i8_u8_accx2_irm
#if __riscv_ztt_i8_u8_accx2_irm != 15
#error all four RMs must be available
#endif
CHECK (i8, int8_t, 2)
CHECK (u8, uint8_t, 2)
#endif
#ifdef __riscv_ztt_i8_u8_accx4_irm
#if __riscv_ztt_i8_u8_accx4_irm != 15
#error all four RMs must be available
#endif
CHECK (i8, int8_t, 4)
CHECK (u8, uint8_t, 4)
#endif
#ifdef __riscv_ztt_i16_u16_accx2_irm
#if __riscv_ztt_i16_u16_accx2_irm != 15
#error all four RMs must be available
#endif
CHECK (i16, int16_t, 2)
CHECK (u16, uint16_t, 2)
#endif
#ifdef __riscv_ztt_i16_u16_accx4_irm
#if __riscv_ztt_i16_u16_accx4_irm != 15
#error all four RMs must be available
#endif
CHECK (i16, int16_t, 4)
CHECK (u16, uint16_t, 4)
#endif
#ifdef __riscv_ztt_i32_u32_accx2_irm
#if __riscv_ztt_i32_u32_accx2_irm != 15
#error all four RMs must be available
#endif
CHECK (i32, int32_t, 2)
CHECK (u32, uint32_t, 2)
#endif
#ifdef __riscv_ztt_i32_u32_accx4_irm
#if __riscv_ztt_i32_u32_accx4_irm != 15
#error all four RMs must be available
#endif
CHECK (i32, int32_t, 4)
CHECK (u32, uint32_t, 4)
#endif
#undef CHECK
