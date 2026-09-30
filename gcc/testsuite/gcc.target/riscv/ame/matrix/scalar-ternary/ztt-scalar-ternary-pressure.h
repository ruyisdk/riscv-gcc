#include <stdint.h>
#include <stddef.h>
#include <riscv_ztt.h>
#define LOAD(I) \
  __riscv_ztt_u32_rod_1x4_t d##I = __riscv_ztt_mls_rm_u32_rod_1x4 (old + I * stride); \
  __riscv_ztt_i16_rne_1x4_t b##I = __riscv_ztt_mls_rm_i16_rne_1x4 (b + I * stride);
#define COMPUTE(I, F, TC, RM) \
  __riscv_ztt_u32_rod_1x4_t r##I \
    = __riscv_ztt_##F##_ew_x_u32_rod_1x4_##TC##_##RM \
        (d##I, b##I, __riscv_ztt_scalar_make_##TC##_##RM (scalar));
#define STORE(I) \
  __riscv_ztt_mss_rm (out + I * stride, r##I); \
  __riscv_ztt_mss_rm (dcopy + I * stride, d##I); \
  __riscv_ztt_mss_rm (bcopy + I * stride, b##I);
void pressure (uint32_t *out, const uint32_t *old, const int16_t *b,
               uint32_t *dcopy, int16_t *bcopy, size_t stride, uint32_t scalar, int clear)
{
  LOAD(0) LOAD(1) LOAD(2) LOAD(3) LOAD(4) LOAD(5) LOAD(6) LOAD(7) LOAD(8)
  COMPUTE(0, mmulacc, u32, rne) COMPUTE(1, mmulaccneg, i8, rdn)
  COMPUTE(2, mmuladd, u16, rod) COMPUTE(3, mmulsub, u32, rnu)
  COMPUTE(4, mmulacc, u16, rdn) COMPUTE(5, mmulaccneg, u32, rod)
  COMPUTE(6, mmuladd, i8, rne) COMPUTE(7, mmulsub, u16, rnu)
  COMPUTE(8, mmulacc, u32, rne)
  if (clear)
    {
      d0 = __riscv_ztt_mzero_m_u32_rod_1x4 ();
      b0 = __riscv_ztt_mzero_m_i16_rne_1x4 ();
    }
  STORE(0) STORE(1) STORE(2) STORE(3) STORE(4) STORE(5) STORE(6) STORE(7) STORE(8)
}
