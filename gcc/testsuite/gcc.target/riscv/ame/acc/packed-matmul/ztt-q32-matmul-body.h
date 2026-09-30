/* Q32.  */
#include <stdint.h>
#include <riscv_ztt.h>
#if __riscv_ztt_uds == 128
#define RIGHT u16
#define RIGHT_C uint16_t
#else
#define RIGHT u8
#define RIGHT_C uint8_t
#endif
#define Q32_MM_I(OP, L, R, B) \
void test_##OP##_##L##_##R (uint32_t *out, const uint32_t *old, \
                           const int8_t *p, const RIGHT_C *q) \
{ \
  __riscv_ztt_i8_rne_##L##_t a = __riscv_ztt_mls_rm_i8_rne_##L (p); \
  __riscv_ztt_##B##_rod_##R##_t b = __riscv_ztt_mls_rm_##B##_rod_##R (q); \
  __riscv_ztt_u32_rdn_accx4_t acc = __riscv_ztt_mcopy_m2a_u32_rdn_accx4 \
    (__riscv_ztt_mls_rm_u32_rdn_1x4 (old)); \
  acc = __riscv_ztt_##OP##_2d_u32_rdn_accx4 (acc, a, b); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_u32_rdn_1x4 (acc)); \
}
#define Q32_MM(OP, L, R, B) Q32_MM_I (OP, L, R, B)
Q32_MM (mmulacc, 1x32, 32x1, RIGHT)
Q32_MM (mmulaccneg, 1x32, 32x1, RIGHT)
Q32_MM (mmulatacc, 1x32, 1x32, RIGHT)
Q32_MM (mmulatacc, 32x1, 32x1, RIGHT)
Q32_MM (mmulataccneg, 1x32, 1x32, RIGHT)
Q32_MM (mmulataccneg, 32x1, 32x1, RIGHT)
Q32_MM (mmulbtacc, 1x32, 1x32, RIGHT)
Q32_MM (mmulbtacc, 32x1, 32x1, RIGHT)
Q32_MM (mmulbtaccneg, 1x32, 1x32, RIGHT)
Q32_MM (mmulbtaccneg, 32x1, 32x1, RIGHT)
