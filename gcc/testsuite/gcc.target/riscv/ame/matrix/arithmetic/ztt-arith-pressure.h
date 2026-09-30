/* integer arithmetic.  */
#include <stdint.h>
#include <stddef.h>
#include <riscv_ztt.h>

void
pressure_madd (int8_t *out, int32_t *ac, uint16_t *bc,
                const int32_t *ap, const uint16_t *bp, size_t stride)
{
  __riscv_ztt_i32_rod_1x4_t a0 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 0 * stride);
  __riscv_ztt_u16_rne_1x4_t b0 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 0 * stride);
  __riscv_ztt_i32_rod_1x4_t a1 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 1 * stride);
  __riscv_ztt_u16_rne_1x4_t b1 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 1 * stride);
  __riscv_ztt_i32_rod_1x4_t a2 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 2 * stride);
  __riscv_ztt_u16_rne_1x4_t b2 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 2 * stride);
  __riscv_ztt_i32_rod_1x4_t a3 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 3 * stride);
  __riscv_ztt_u16_rne_1x4_t b3 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 3 * stride);
  __riscv_ztt_i32_rod_1x4_t a4 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 4 * stride);
  __riscv_ztt_u16_rne_1x4_t b4 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 4 * stride);
  __riscv_ztt_i32_rod_1x4_t a5 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 5 * stride);
  __riscv_ztt_u16_rne_1x4_t b5 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 5 * stride);
  __riscv_ztt_i32_rod_1x4_t a6 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 6 * stride);
  __riscv_ztt_u16_rne_1x4_t b6 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 6 * stride);
  __riscv_ztt_i32_rod_1x4_t a7 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 7 * stride);
  __riscv_ztt_u16_rne_1x4_t b7 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 7 * stride);
  __riscv_ztt_i8_rdn_1x4_t d0 = __riscv_ztt_madd_ew_i8_rdn_1x4 (a0, b0);
  __riscv_ztt_i8_rdn_1x4_t d1 = __riscv_ztt_madd_ew_i8_rdn_1x4 (a1, b1);
  __riscv_ztt_i8_rdn_1x4_t d2 = __riscv_ztt_madd_ew_i8_rdn_1x4 (a2, b2);
  __riscv_ztt_i8_rdn_1x4_t d3 = __riscv_ztt_madd_ew_i8_rdn_1x4 (a3, b3);
  __riscv_ztt_i8_rdn_1x4_t d4 = __riscv_ztt_madd_ew_i8_rdn_1x4 (a4, b4);
  __riscv_ztt_i8_rdn_1x4_t d5 = __riscv_ztt_madd_ew_i8_rdn_1x4 (a5, b5);
  __riscv_ztt_i8_rdn_1x4_t d6 = __riscv_ztt_madd_ew_i8_rdn_1x4 (a6, b6);
  __riscv_ztt_i8_rdn_1x4_t d7 = __riscv_ztt_madd_ew_i8_rdn_1x4 (a7, b7);
  a0 = __riscv_ztt_mzero_m_i32_rod_1x4 ();
  b0 = __riscv_ztt_mzero_m_u16_rne_1x4 ();
  __riscv_ztt_mss_rm (out + 0 * stride, d0);
  __riscv_ztt_mss_rm (ac + 0 * stride, a0);
  __riscv_ztt_mss_rm (bc + 0 * stride, b0);
  __riscv_ztt_mss_rm (out + 1 * stride, d1);
  __riscv_ztt_mss_rm (ac + 1 * stride, a1);
  __riscv_ztt_mss_rm (bc + 1 * stride, b1);
  __riscv_ztt_mss_rm (out + 2 * stride, d2);
  __riscv_ztt_mss_rm (ac + 2 * stride, a2);
  __riscv_ztt_mss_rm (bc + 2 * stride, b2);
  __riscv_ztt_mss_rm (out + 3 * stride, d3);
  __riscv_ztt_mss_rm (ac + 3 * stride, a3);
  __riscv_ztt_mss_rm (bc + 3 * stride, b3);
  __riscv_ztt_mss_rm (out + 4 * stride, d4);
  __riscv_ztt_mss_rm (ac + 4 * stride, a4);
  __riscv_ztt_mss_rm (bc + 4 * stride, b4);
  __riscv_ztt_mss_rm (out + 5 * stride, d5);
  __riscv_ztt_mss_rm (ac + 5 * stride, a5);
  __riscv_ztt_mss_rm (bc + 5 * stride, b5);
  __riscv_ztt_mss_rm (out + 6 * stride, d6);
  __riscv_ztt_mss_rm (ac + 6 * stride, a6);
  __riscv_ztt_mss_rm (bc + 6 * stride, b6);
  __riscv_ztt_mss_rm (out + 7 * stride, d7);
  __riscv_ztt_mss_rm (ac + 7 * stride, a7);
  __riscv_ztt_mss_rm (bc + 7 * stride, b7);
}

void
pressure_msub (int8_t *out, int32_t *ac, uint16_t *bc,
                const int32_t *ap, const uint16_t *bp, size_t stride)
{
  __riscv_ztt_i32_rod_1x4_t a0 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 0 * stride);
  __riscv_ztt_u16_rne_1x4_t b0 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 0 * stride);
  __riscv_ztt_i32_rod_1x4_t a1 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 1 * stride);
  __riscv_ztt_u16_rne_1x4_t b1 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 1 * stride);
  __riscv_ztt_i32_rod_1x4_t a2 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 2 * stride);
  __riscv_ztt_u16_rne_1x4_t b2 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 2 * stride);
  __riscv_ztt_i32_rod_1x4_t a3 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 3 * stride);
  __riscv_ztt_u16_rne_1x4_t b3 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 3 * stride);
  __riscv_ztt_i32_rod_1x4_t a4 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 4 * stride);
  __riscv_ztt_u16_rne_1x4_t b4 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 4 * stride);
  __riscv_ztt_i32_rod_1x4_t a5 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 5 * stride);
  __riscv_ztt_u16_rne_1x4_t b5 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 5 * stride);
  __riscv_ztt_i32_rod_1x4_t a6 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 6 * stride);
  __riscv_ztt_u16_rne_1x4_t b6 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 6 * stride);
  __riscv_ztt_i32_rod_1x4_t a7 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 7 * stride);
  __riscv_ztt_u16_rne_1x4_t b7 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 7 * stride);
  __riscv_ztt_i8_rdn_1x4_t d0 = __riscv_ztt_msub_ew_i8_rdn_1x4 (a0, b0);
  __riscv_ztt_i8_rdn_1x4_t d1 = __riscv_ztt_msub_ew_i8_rdn_1x4 (a1, b1);
  __riscv_ztt_i8_rdn_1x4_t d2 = __riscv_ztt_msub_ew_i8_rdn_1x4 (a2, b2);
  __riscv_ztt_i8_rdn_1x4_t d3 = __riscv_ztt_msub_ew_i8_rdn_1x4 (a3, b3);
  __riscv_ztt_i8_rdn_1x4_t d4 = __riscv_ztt_msub_ew_i8_rdn_1x4 (a4, b4);
  __riscv_ztt_i8_rdn_1x4_t d5 = __riscv_ztt_msub_ew_i8_rdn_1x4 (a5, b5);
  __riscv_ztt_i8_rdn_1x4_t d6 = __riscv_ztt_msub_ew_i8_rdn_1x4 (a6, b6);
  __riscv_ztt_i8_rdn_1x4_t d7 = __riscv_ztt_msub_ew_i8_rdn_1x4 (a7, b7);
  a0 = __riscv_ztt_mzero_m_i32_rod_1x4 ();
  b0 = __riscv_ztt_mzero_m_u16_rne_1x4 ();
  __riscv_ztt_mss_rm (out + 0 * stride, d0);
  __riscv_ztt_mss_rm (ac + 0 * stride, a0);
  __riscv_ztt_mss_rm (bc + 0 * stride, b0);
  __riscv_ztt_mss_rm (out + 1 * stride, d1);
  __riscv_ztt_mss_rm (ac + 1 * stride, a1);
  __riscv_ztt_mss_rm (bc + 1 * stride, b1);
  __riscv_ztt_mss_rm (out + 2 * stride, d2);
  __riscv_ztt_mss_rm (ac + 2 * stride, a2);
  __riscv_ztt_mss_rm (bc + 2 * stride, b2);
  __riscv_ztt_mss_rm (out + 3 * stride, d3);
  __riscv_ztt_mss_rm (ac + 3 * stride, a3);
  __riscv_ztt_mss_rm (bc + 3 * stride, b3);
  __riscv_ztt_mss_rm (out + 4 * stride, d4);
  __riscv_ztt_mss_rm (ac + 4 * stride, a4);
  __riscv_ztt_mss_rm (bc + 4 * stride, b4);
  __riscv_ztt_mss_rm (out + 5 * stride, d5);
  __riscv_ztt_mss_rm (ac + 5 * stride, a5);
  __riscv_ztt_mss_rm (bc + 5 * stride, b5);
  __riscv_ztt_mss_rm (out + 6 * stride, d6);
  __riscv_ztt_mss_rm (ac + 6 * stride, a6);
  __riscv_ztt_mss_rm (bc + 6 * stride, b6);
  __riscv_ztt_mss_rm (out + 7 * stride, d7);
  __riscv_ztt_mss_rm (ac + 7 * stride, a7);
  __riscv_ztt_mss_rm (bc + 7 * stride, b7);
}

void
pressure_mabsdiff (int8_t *out, int32_t *ac, uint16_t *bc,
                const int32_t *ap, const uint16_t *bp, size_t stride)
{
  __riscv_ztt_i32_rod_1x4_t a0 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 0 * stride);
  __riscv_ztt_u16_rne_1x4_t b0 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 0 * stride);
  __riscv_ztt_i32_rod_1x4_t a1 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 1 * stride);
  __riscv_ztt_u16_rne_1x4_t b1 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 1 * stride);
  __riscv_ztt_i32_rod_1x4_t a2 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 2 * stride);
  __riscv_ztt_u16_rne_1x4_t b2 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 2 * stride);
  __riscv_ztt_i32_rod_1x4_t a3 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 3 * stride);
  __riscv_ztt_u16_rne_1x4_t b3 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 3 * stride);
  __riscv_ztt_i32_rod_1x4_t a4 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 4 * stride);
  __riscv_ztt_u16_rne_1x4_t b4 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 4 * stride);
  __riscv_ztt_i32_rod_1x4_t a5 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 5 * stride);
  __riscv_ztt_u16_rne_1x4_t b5 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 5 * stride);
  __riscv_ztt_i32_rod_1x4_t a6 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 6 * stride);
  __riscv_ztt_u16_rne_1x4_t b6 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 6 * stride);
  __riscv_ztt_i32_rod_1x4_t a7 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 7 * stride);
  __riscv_ztt_u16_rne_1x4_t b7 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 7 * stride);
  __riscv_ztt_i8_rdn_1x4_t d0 = __riscv_ztt_mabsdiff_ew_i8_rdn_1x4 (a0, b0);
  __riscv_ztt_i8_rdn_1x4_t d1 = __riscv_ztt_mabsdiff_ew_i8_rdn_1x4 (a1, b1);
  __riscv_ztt_i8_rdn_1x4_t d2 = __riscv_ztt_mabsdiff_ew_i8_rdn_1x4 (a2, b2);
  __riscv_ztt_i8_rdn_1x4_t d3 = __riscv_ztt_mabsdiff_ew_i8_rdn_1x4 (a3, b3);
  __riscv_ztt_i8_rdn_1x4_t d4 = __riscv_ztt_mabsdiff_ew_i8_rdn_1x4 (a4, b4);
  __riscv_ztt_i8_rdn_1x4_t d5 = __riscv_ztt_mabsdiff_ew_i8_rdn_1x4 (a5, b5);
  __riscv_ztt_i8_rdn_1x4_t d6 = __riscv_ztt_mabsdiff_ew_i8_rdn_1x4 (a6, b6);
  __riscv_ztt_i8_rdn_1x4_t d7 = __riscv_ztt_mabsdiff_ew_i8_rdn_1x4 (a7, b7);
  a0 = __riscv_ztt_mzero_m_i32_rod_1x4 ();
  b0 = __riscv_ztt_mzero_m_u16_rne_1x4 ();
  __riscv_ztt_mss_rm (out + 0 * stride, d0);
  __riscv_ztt_mss_rm (ac + 0 * stride, a0);
  __riscv_ztt_mss_rm (bc + 0 * stride, b0);
  __riscv_ztt_mss_rm (out + 1 * stride, d1);
  __riscv_ztt_mss_rm (ac + 1 * stride, a1);
  __riscv_ztt_mss_rm (bc + 1 * stride, b1);
  __riscv_ztt_mss_rm (out + 2 * stride, d2);
  __riscv_ztt_mss_rm (ac + 2 * stride, a2);
  __riscv_ztt_mss_rm (bc + 2 * stride, b2);
  __riscv_ztt_mss_rm (out + 3 * stride, d3);
  __riscv_ztt_mss_rm (ac + 3 * stride, a3);
  __riscv_ztt_mss_rm (bc + 3 * stride, b3);
  __riscv_ztt_mss_rm (out + 4 * stride, d4);
  __riscv_ztt_mss_rm (ac + 4 * stride, a4);
  __riscv_ztt_mss_rm (bc + 4 * stride, b4);
  __riscv_ztt_mss_rm (out + 5 * stride, d5);
  __riscv_ztt_mss_rm (ac + 5 * stride, a5);
  __riscv_ztt_mss_rm (bc + 5 * stride, b5);
  __riscv_ztt_mss_rm (out + 6 * stride, d6);
  __riscv_ztt_mss_rm (ac + 6 * stride, a6);
  __riscv_ztt_mss_rm (bc + 6 * stride, b6);
  __riscv_ztt_mss_rm (out + 7 * stride, d7);
  __riscv_ztt_mss_rm (ac + 7 * stride, a7);
  __riscv_ztt_mss_rm (bc + 7 * stride, b7);
}

void
pressure_mhdiff (int8_t *out, int32_t *ac, uint16_t *bc,
                const int32_t *ap, const uint16_t *bp, size_t stride)
{
  __riscv_ztt_i32_rod_1x4_t a0 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 0 * stride);
  __riscv_ztt_u16_rne_1x4_t b0 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 0 * stride);
  __riscv_ztt_i32_rod_1x4_t a1 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 1 * stride);
  __riscv_ztt_u16_rne_1x4_t b1 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 1 * stride);
  __riscv_ztt_i32_rod_1x4_t a2 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 2 * stride);
  __riscv_ztt_u16_rne_1x4_t b2 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 2 * stride);
  __riscv_ztt_i32_rod_1x4_t a3 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 3 * stride);
  __riscv_ztt_u16_rne_1x4_t b3 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 3 * stride);
  __riscv_ztt_i32_rod_1x4_t a4 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 4 * stride);
  __riscv_ztt_u16_rne_1x4_t b4 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 4 * stride);
  __riscv_ztt_i32_rod_1x4_t a5 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 5 * stride);
  __riscv_ztt_u16_rne_1x4_t b5 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 5 * stride);
  __riscv_ztt_i32_rod_1x4_t a6 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 6 * stride);
  __riscv_ztt_u16_rne_1x4_t b6 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 6 * stride);
  __riscv_ztt_i32_rod_1x4_t a7 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 7 * stride);
  __riscv_ztt_u16_rne_1x4_t b7 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 7 * stride);
  __riscv_ztt_i8_rdn_1x4_t d0 = __riscv_ztt_mhdiff_ew_i8_rdn_1x4 (a0, b0);
  __riscv_ztt_i8_rdn_1x4_t d1 = __riscv_ztt_mhdiff_ew_i8_rdn_1x4 (a1, b1);
  __riscv_ztt_i8_rdn_1x4_t d2 = __riscv_ztt_mhdiff_ew_i8_rdn_1x4 (a2, b2);
  __riscv_ztt_i8_rdn_1x4_t d3 = __riscv_ztt_mhdiff_ew_i8_rdn_1x4 (a3, b3);
  __riscv_ztt_i8_rdn_1x4_t d4 = __riscv_ztt_mhdiff_ew_i8_rdn_1x4 (a4, b4);
  __riscv_ztt_i8_rdn_1x4_t d5 = __riscv_ztt_mhdiff_ew_i8_rdn_1x4 (a5, b5);
  __riscv_ztt_i8_rdn_1x4_t d6 = __riscv_ztt_mhdiff_ew_i8_rdn_1x4 (a6, b6);
  __riscv_ztt_i8_rdn_1x4_t d7 = __riscv_ztt_mhdiff_ew_i8_rdn_1x4 (a7, b7);
  a0 = __riscv_ztt_mzero_m_i32_rod_1x4 ();
  b0 = __riscv_ztt_mzero_m_u16_rne_1x4 ();
  __riscv_ztt_mss_rm (out + 0 * stride, d0);
  __riscv_ztt_mss_rm (ac + 0 * stride, a0);
  __riscv_ztt_mss_rm (bc + 0 * stride, b0);
  __riscv_ztt_mss_rm (out + 1 * stride, d1);
  __riscv_ztt_mss_rm (ac + 1 * stride, a1);
  __riscv_ztt_mss_rm (bc + 1 * stride, b1);
  __riscv_ztt_mss_rm (out + 2 * stride, d2);
  __riscv_ztt_mss_rm (ac + 2 * stride, a2);
  __riscv_ztt_mss_rm (bc + 2 * stride, b2);
  __riscv_ztt_mss_rm (out + 3 * stride, d3);
  __riscv_ztt_mss_rm (ac + 3 * stride, a3);
  __riscv_ztt_mss_rm (bc + 3 * stride, b3);
  __riscv_ztt_mss_rm (out + 4 * stride, d4);
  __riscv_ztt_mss_rm (ac + 4 * stride, a4);
  __riscv_ztt_mss_rm (bc + 4 * stride, b4);
  __riscv_ztt_mss_rm (out + 5 * stride, d5);
  __riscv_ztt_mss_rm (ac + 5 * stride, a5);
  __riscv_ztt_mss_rm (bc + 5 * stride, b5);
  __riscv_ztt_mss_rm (out + 6 * stride, d6);
  __riscv_ztt_mss_rm (ac + 6 * stride, a6);
  __riscv_ztt_mss_rm (bc + 6 * stride, b6);
  __riscv_ztt_mss_rm (out + 7 * stride, d7);
  __riscv_ztt_mss_rm (ac + 7 * stride, a7);
  __riscv_ztt_mss_rm (bc + 7 * stride, b7);
}

void
pressure_mmean (int8_t *out, int32_t *ac, uint16_t *bc,
                const int32_t *ap, const uint16_t *bp, size_t stride)
{
  __riscv_ztt_i32_rod_1x4_t a0 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 0 * stride);
  __riscv_ztt_u16_rne_1x4_t b0 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 0 * stride);
  __riscv_ztt_i32_rod_1x4_t a1 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 1 * stride);
  __riscv_ztt_u16_rne_1x4_t b1 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 1 * stride);
  __riscv_ztt_i32_rod_1x4_t a2 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 2 * stride);
  __riscv_ztt_u16_rne_1x4_t b2 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 2 * stride);
  __riscv_ztt_i32_rod_1x4_t a3 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 3 * stride);
  __riscv_ztt_u16_rne_1x4_t b3 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 3 * stride);
  __riscv_ztt_i32_rod_1x4_t a4 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 4 * stride);
  __riscv_ztt_u16_rne_1x4_t b4 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 4 * stride);
  __riscv_ztt_i32_rod_1x4_t a5 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 5 * stride);
  __riscv_ztt_u16_rne_1x4_t b5 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 5 * stride);
  __riscv_ztt_i32_rod_1x4_t a6 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 6 * stride);
  __riscv_ztt_u16_rne_1x4_t b6 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 6 * stride);
  __riscv_ztt_i32_rod_1x4_t a7 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 7 * stride);
  __riscv_ztt_u16_rne_1x4_t b7 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 7 * stride);
  __riscv_ztt_i8_rdn_1x4_t d0 = __riscv_ztt_mmean_ew_i8_rdn_1x4 (a0, b0);
  __riscv_ztt_i8_rdn_1x4_t d1 = __riscv_ztt_mmean_ew_i8_rdn_1x4 (a1, b1);
  __riscv_ztt_i8_rdn_1x4_t d2 = __riscv_ztt_mmean_ew_i8_rdn_1x4 (a2, b2);
  __riscv_ztt_i8_rdn_1x4_t d3 = __riscv_ztt_mmean_ew_i8_rdn_1x4 (a3, b3);
  __riscv_ztt_i8_rdn_1x4_t d4 = __riscv_ztt_mmean_ew_i8_rdn_1x4 (a4, b4);
  __riscv_ztt_i8_rdn_1x4_t d5 = __riscv_ztt_mmean_ew_i8_rdn_1x4 (a5, b5);
  __riscv_ztt_i8_rdn_1x4_t d6 = __riscv_ztt_mmean_ew_i8_rdn_1x4 (a6, b6);
  __riscv_ztt_i8_rdn_1x4_t d7 = __riscv_ztt_mmean_ew_i8_rdn_1x4 (a7, b7);
  a0 = __riscv_ztt_mzero_m_i32_rod_1x4 ();
  b0 = __riscv_ztt_mzero_m_u16_rne_1x4 ();
  __riscv_ztt_mss_rm (out + 0 * stride, d0);
  __riscv_ztt_mss_rm (ac + 0 * stride, a0);
  __riscv_ztt_mss_rm (bc + 0 * stride, b0);
  __riscv_ztt_mss_rm (out + 1 * stride, d1);
  __riscv_ztt_mss_rm (ac + 1 * stride, a1);
  __riscv_ztt_mss_rm (bc + 1 * stride, b1);
  __riscv_ztt_mss_rm (out + 2 * stride, d2);
  __riscv_ztt_mss_rm (ac + 2 * stride, a2);
  __riscv_ztt_mss_rm (bc + 2 * stride, b2);
  __riscv_ztt_mss_rm (out + 3 * stride, d3);
  __riscv_ztt_mss_rm (ac + 3 * stride, a3);
  __riscv_ztt_mss_rm (bc + 3 * stride, b3);
  __riscv_ztt_mss_rm (out + 4 * stride, d4);
  __riscv_ztt_mss_rm (ac + 4 * stride, a4);
  __riscv_ztt_mss_rm (bc + 4 * stride, b4);
  __riscv_ztt_mss_rm (out + 5 * stride, d5);
  __riscv_ztt_mss_rm (ac + 5 * stride, a5);
  __riscv_ztt_mss_rm (bc + 5 * stride, b5);
  __riscv_ztt_mss_rm (out + 6 * stride, d6);
  __riscv_ztt_mss_rm (ac + 6 * stride, a6);
  __riscv_ztt_mss_rm (bc + 6 * stride, b6);
  __riscv_ztt_mss_rm (out + 7 * stride, d7);
  __riscv_ztt_mss_rm (ac + 7 * stride, a7);
  __riscv_ztt_mss_rm (bc + 7 * stride, b7);
}

void
pressure_mmulneg (int8_t *out, int32_t *ac, uint16_t *bc,
                const int32_t *ap, const uint16_t *bp, size_t stride)
{
  __riscv_ztt_i32_rod_1x4_t a0 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 0 * stride);
  __riscv_ztt_u16_rne_1x4_t b0 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 0 * stride);
  __riscv_ztt_i32_rod_1x4_t a1 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 1 * stride);
  __riscv_ztt_u16_rne_1x4_t b1 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 1 * stride);
  __riscv_ztt_i32_rod_1x4_t a2 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 2 * stride);
  __riscv_ztt_u16_rne_1x4_t b2 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 2 * stride);
  __riscv_ztt_i32_rod_1x4_t a3 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 3 * stride);
  __riscv_ztt_u16_rne_1x4_t b3 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 3 * stride);
  __riscv_ztt_i32_rod_1x4_t a4 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 4 * stride);
  __riscv_ztt_u16_rne_1x4_t b4 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 4 * stride);
  __riscv_ztt_i32_rod_1x4_t a5 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 5 * stride);
  __riscv_ztt_u16_rne_1x4_t b5 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 5 * stride);
  __riscv_ztt_i32_rod_1x4_t a6 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 6 * stride);
  __riscv_ztt_u16_rne_1x4_t b6 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 6 * stride);
  __riscv_ztt_i32_rod_1x4_t a7 = __riscv_ztt_mls_rm_i32_rod_1x4 (ap + 7 * stride);
  __riscv_ztt_u16_rne_1x4_t b7 = __riscv_ztt_mls_rm_u16_rne_1x4 (bp + 7 * stride);
  __riscv_ztt_i8_rdn_1x4_t d0 = __riscv_ztt_mmulneg_ew_i8_rdn_1x4 (a0, b0);
  __riscv_ztt_i8_rdn_1x4_t d1 = __riscv_ztt_mmulneg_ew_i8_rdn_1x4 (a1, b1);
  __riscv_ztt_i8_rdn_1x4_t d2 = __riscv_ztt_mmulneg_ew_i8_rdn_1x4 (a2, b2);
  __riscv_ztt_i8_rdn_1x4_t d3 = __riscv_ztt_mmulneg_ew_i8_rdn_1x4 (a3, b3);
  __riscv_ztt_i8_rdn_1x4_t d4 = __riscv_ztt_mmulneg_ew_i8_rdn_1x4 (a4, b4);
  __riscv_ztt_i8_rdn_1x4_t d5 = __riscv_ztt_mmulneg_ew_i8_rdn_1x4 (a5, b5);
  __riscv_ztt_i8_rdn_1x4_t d6 = __riscv_ztt_mmulneg_ew_i8_rdn_1x4 (a6, b6);
  __riscv_ztt_i8_rdn_1x4_t d7 = __riscv_ztt_mmulneg_ew_i8_rdn_1x4 (a7, b7);
  a0 = __riscv_ztt_mzero_m_i32_rod_1x4 ();
  b0 = __riscv_ztt_mzero_m_u16_rne_1x4 ();
  __riscv_ztt_mss_rm (out + 0 * stride, d0);
  __riscv_ztt_mss_rm (ac + 0 * stride, a0);
  __riscv_ztt_mss_rm (bc + 0 * stride, b0);
  __riscv_ztt_mss_rm (out + 1 * stride, d1);
  __riscv_ztt_mss_rm (ac + 1 * stride, a1);
  __riscv_ztt_mss_rm (bc + 1 * stride, b1);
  __riscv_ztt_mss_rm (out + 2 * stride, d2);
  __riscv_ztt_mss_rm (ac + 2 * stride, a2);
  __riscv_ztt_mss_rm (bc + 2 * stride, b2);
  __riscv_ztt_mss_rm (out + 3 * stride, d3);
  __riscv_ztt_mss_rm (ac + 3 * stride, a3);
  __riscv_ztt_mss_rm (bc + 3 * stride, b3);
  __riscv_ztt_mss_rm (out + 4 * stride, d4);
  __riscv_ztt_mss_rm (ac + 4 * stride, a4);
  __riscv_ztt_mss_rm (bc + 4 * stride, b4);
  __riscv_ztt_mss_rm (out + 5 * stride, d5);
  __riscv_ztt_mss_rm (ac + 5 * stride, a5);
  __riscv_ztt_mss_rm (bc + 5 * stride, b5);
  __riscv_ztt_mss_rm (out + 6 * stride, d6);
  __riscv_ztt_mss_rm (ac + 6 * stride, a6);
  __riscv_ztt_mss_rm (bc + 6 * stride, b6);
  __riscv_ztt_mss_rm (out + 7 * stride, d7);
  __riscv_ztt_mss_rm (ac + 7 * stride, a7);
  __riscv_ztt_mss_rm (bc + 7 * stride, b7);
}
