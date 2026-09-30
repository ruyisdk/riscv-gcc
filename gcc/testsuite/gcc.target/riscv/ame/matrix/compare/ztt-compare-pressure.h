#include <stdint.h>
#include <stddef.h>
#include <riscv_ztt.h>
#define LOAD(I) \
  __riscv_ztt_i32_rod_1x4_t d##I = __riscv_ztt_mls_rm_i32_rod_1x4 (old + I * stride); \
  __riscv_ztt_i32_rod_1x4_t b##I = __riscv_ztt_mls_rm_i32_rod_1x4 (data + I * stride); \
  __riscv_ztt_i8_rne_1x4_t p##I = __riscv_ztt_mls_rm_i8_rne_1x4 (pred + I * stride);
#define STORE(I) \
  __riscv_ztt_mss_rm (out + I * stride, r##I); \
  __riscv_ztt_mss_rm (dcopy + I * stride, d##I); \
  __riscv_ztt_mss_rm (bcopy + I * stride, b##I); \
  __riscv_ztt_mss_rm (pcopy + I * stride, p##I);
void pressure (int32_t *out, const int32_t *old, const int32_t *data,
               const int8_t *pred, int32_t *dcopy, int32_t *bcopy, int8_t *pcopy,
               size_t stride, uint32_t scalar, int clear)
{
  LOAD(0) LOAD(1) LOAD(2) LOAD(3) LOAD(4) LOAD(5) LOAD(6) LOAD(7)
  __riscv_ztt_i32_rod_1x4_t r0 = __riscv_ztt_mcmovge_ew_i32_rod_1x4 (d0, p0, b0);
  __riscv_ztt_i32_rod_1x4_t r1 = __riscv_ztt_mcmovlt_ew_i32_rod_1x4 (d1, p1, b1);
  __riscv_ztt_i32_rod_1x4_t r2 = __riscv_ztt_mselge_ew_i32_rod_1x4 (p2, b2);
  __riscv_ztt_i32_rod_1x4_t r3 = __riscv_ztt_msellt_ew_i32_rod_1x4 (p3, b3);
  __riscv_ztt_i32_rod_1x4_t r4 = __riscv_ztt_mcmpge_ew_i32_rod_1x4 (p4, b4);
  __riscv_ztt_i32_rod_1x4_t r5 = __riscv_ztt_mcmplt_ew_i32_rod_1x4 (p5, b5);
  __riscv_ztt_i32_rod_1x4_t r6 = __riscv_ztt_mcmpge_ew_x_i32_rod_1x4_i16_rne (p6, __riscv_ztt_scalar_make_i16_rne (scalar));
  __riscv_ztt_i32_rod_1x4_t r7 = __riscv_ztt_mcmplt_ew_x_i32_rod_1x4_u32_rdn (p7, __riscv_ztt_scalar_make_u32_rdn (scalar));
  if (clear)
    {
      d0 = __riscv_ztt_mzero_m_i32_rod_1x4 ();
      p0 = __riscv_ztt_mzero_m_i8_rne_1x4 ();
      b0 = __riscv_ztt_mzero_m_i32_rod_1x4 ();
    }
  STORE(0) STORE(1) STORE(2) STORE(3) STORE(4) STORE(5) STORE(6) STORE(7)
}
