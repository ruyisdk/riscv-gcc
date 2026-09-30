/* Floating memory keeps full native elements on both XLENs.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m32-a16 " { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m32-a16 " { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>
void mem_rm_f16_rne_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_1x8_t value = __riscv_ztt_mls_rm_f16_rne_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rne_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_1x8_t value = __riscv_ztt_mls_cm_f16_rne_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rne_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_1x8_t value = __riscv_ztt_mls_st_f16_rne_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rne_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_1x8_t value = __riscv_ztt_mls_tst_f16_rne_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rne_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_8x1_t value = __riscv_ztt_mls_rm_f16_rne_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rne_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_8x1_t value = __riscv_ztt_mls_cm_f16_rne_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rne_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_8x1_t value = __riscv_ztt_mls_st_f16_rne_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rne_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_8x1_t value = __riscv_ztt_mls_tst_f16_rne_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rne_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_1x16_t value = __riscv_ztt_mls_rm_f16_rne_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rne_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_1x16_t value = __riscv_ztt_mls_cm_f16_rne_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rne_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_1x16_t value = __riscv_ztt_mls_st_f16_rne_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rne_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_1x16_t value = __riscv_ztt_mls_tst_f16_rne_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rne_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_16x1_t value = __riscv_ztt_mls_rm_f16_rne_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rne_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_16x1_t value = __riscv_ztt_mls_cm_f16_rne_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rne_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_16x1_t value = __riscv_ztt_mls_st_f16_rne_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rne_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_16x1_t value = __riscv_ztt_mls_tst_f16_rne_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rne_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_1x32_t value = __riscv_ztt_mls_rm_f16_rne_1x32 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rne_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_1x32_t value = __riscv_ztt_mls_cm_f16_rne_1x32 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rne_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_1x32_t value = __riscv_ztt_mls_st_f16_rne_1x32 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rne_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_1x32_t value = __riscv_ztt_mls_tst_f16_rne_1x32 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rne_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_32x1_t value = __riscv_ztt_mls_rm_f16_rne_32x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rne_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_32x1_t value = __riscv_ztt_mls_cm_f16_rne_32x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rne_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_32x1_t value = __riscv_ztt_mls_st_f16_rne_32x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rne_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_32x1_t value = __riscv_ztt_mls_tst_f16_rne_32x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rtz_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_1x8_t value = __riscv_ztt_mls_rm_f16_rtz_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rtz_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_1x8_t value = __riscv_ztt_mls_cm_f16_rtz_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rtz_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_1x8_t value = __riscv_ztt_mls_st_f16_rtz_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rtz_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_1x8_t value = __riscv_ztt_mls_tst_f16_rtz_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rtz_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_8x1_t value = __riscv_ztt_mls_rm_f16_rtz_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rtz_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_8x1_t value = __riscv_ztt_mls_cm_f16_rtz_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rtz_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_8x1_t value = __riscv_ztt_mls_st_f16_rtz_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rtz_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_8x1_t value = __riscv_ztt_mls_tst_f16_rtz_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rtz_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_1x16_t value = __riscv_ztt_mls_rm_f16_rtz_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rtz_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_1x16_t value = __riscv_ztt_mls_cm_f16_rtz_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rtz_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_1x16_t value = __riscv_ztt_mls_st_f16_rtz_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rtz_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_1x16_t value = __riscv_ztt_mls_tst_f16_rtz_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rtz_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_16x1_t value = __riscv_ztt_mls_rm_f16_rtz_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rtz_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_16x1_t value = __riscv_ztt_mls_cm_f16_rtz_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rtz_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_16x1_t value = __riscv_ztt_mls_st_f16_rtz_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rtz_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_16x1_t value = __riscv_ztt_mls_tst_f16_rtz_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rtz_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_1x32_t value = __riscv_ztt_mls_rm_f16_rtz_1x32 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rtz_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_1x32_t value = __riscv_ztt_mls_cm_f16_rtz_1x32 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rtz_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_1x32_t value = __riscv_ztt_mls_st_f16_rtz_1x32 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rtz_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_1x32_t value = __riscv_ztt_mls_tst_f16_rtz_1x32 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rtz_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_32x1_t value = __riscv_ztt_mls_rm_f16_rtz_32x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rtz_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_32x1_t value = __riscv_ztt_mls_cm_f16_rtz_32x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rtz_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_32x1_t value = __riscv_ztt_mls_st_f16_rtz_32x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rtz_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_32x1_t value = __riscv_ztt_mls_tst_f16_rtz_32x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rdn_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_1x8_t value = __riscv_ztt_mls_rm_f16_rdn_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rdn_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_1x8_t value = __riscv_ztt_mls_cm_f16_rdn_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rdn_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_1x8_t value = __riscv_ztt_mls_st_f16_rdn_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rdn_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_1x8_t value = __riscv_ztt_mls_tst_f16_rdn_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rdn_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_8x1_t value = __riscv_ztt_mls_rm_f16_rdn_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rdn_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_8x1_t value = __riscv_ztt_mls_cm_f16_rdn_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rdn_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_8x1_t value = __riscv_ztt_mls_st_f16_rdn_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rdn_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_8x1_t value = __riscv_ztt_mls_tst_f16_rdn_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rdn_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_1x16_t value = __riscv_ztt_mls_rm_f16_rdn_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rdn_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_1x16_t value = __riscv_ztt_mls_cm_f16_rdn_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rdn_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_1x16_t value = __riscv_ztt_mls_st_f16_rdn_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rdn_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_1x16_t value = __riscv_ztt_mls_tst_f16_rdn_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rdn_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_16x1_t value = __riscv_ztt_mls_rm_f16_rdn_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rdn_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_16x1_t value = __riscv_ztt_mls_cm_f16_rdn_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rdn_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_16x1_t value = __riscv_ztt_mls_st_f16_rdn_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rdn_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_16x1_t value = __riscv_ztt_mls_tst_f16_rdn_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rdn_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_1x32_t value = __riscv_ztt_mls_rm_f16_rdn_1x32 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rdn_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_1x32_t value = __riscv_ztt_mls_cm_f16_rdn_1x32 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rdn_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_1x32_t value = __riscv_ztt_mls_st_f16_rdn_1x32 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rdn_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_1x32_t value = __riscv_ztt_mls_tst_f16_rdn_1x32 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rdn_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_32x1_t value = __riscv_ztt_mls_rm_f16_rdn_32x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rdn_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_32x1_t value = __riscv_ztt_mls_cm_f16_rdn_32x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rdn_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_32x1_t value = __riscv_ztt_mls_st_f16_rdn_32x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rdn_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_32x1_t value = __riscv_ztt_mls_tst_f16_rdn_32x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rup_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_1x8_t value = __riscv_ztt_mls_rm_f16_rup_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rup_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_1x8_t value = __riscv_ztt_mls_cm_f16_rup_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rup_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_1x8_t value = __riscv_ztt_mls_st_f16_rup_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rup_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_1x8_t value = __riscv_ztt_mls_tst_f16_rup_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rup_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_8x1_t value = __riscv_ztt_mls_rm_f16_rup_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rup_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_8x1_t value = __riscv_ztt_mls_cm_f16_rup_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rup_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_8x1_t value = __riscv_ztt_mls_st_f16_rup_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rup_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_8x1_t value = __riscv_ztt_mls_tst_f16_rup_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rup_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_1x16_t value = __riscv_ztt_mls_rm_f16_rup_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rup_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_1x16_t value = __riscv_ztt_mls_cm_f16_rup_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rup_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_1x16_t value = __riscv_ztt_mls_st_f16_rup_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rup_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_1x16_t value = __riscv_ztt_mls_tst_f16_rup_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rup_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_16x1_t value = __riscv_ztt_mls_rm_f16_rup_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rup_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_16x1_t value = __riscv_ztt_mls_cm_f16_rup_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rup_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_16x1_t value = __riscv_ztt_mls_st_f16_rup_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rup_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_16x1_t value = __riscv_ztt_mls_tst_f16_rup_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rup_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_1x32_t value = __riscv_ztt_mls_rm_f16_rup_1x32 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rup_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_1x32_t value = __riscv_ztt_mls_cm_f16_rup_1x32 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rup_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_1x32_t value = __riscv_ztt_mls_st_f16_rup_1x32 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rup_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_1x32_t value = __riscv_ztt_mls_tst_f16_rup_1x32 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rup_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_32x1_t value = __riscv_ztt_mls_rm_f16_rup_32x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rup_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_32x1_t value = __riscv_ztt_mls_cm_f16_rup_32x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rup_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_32x1_t value = __riscv_ztt_mls_st_f16_rup_32x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rup_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_32x1_t value = __riscv_ztt_mls_tst_f16_rup_32x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rmm_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_1x8_t value = __riscv_ztt_mls_rm_f16_rmm_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rmm_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_1x8_t value = __riscv_ztt_mls_cm_f16_rmm_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rmm_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_1x8_t value = __riscv_ztt_mls_st_f16_rmm_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rmm_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_1x8_t value = __riscv_ztt_mls_tst_f16_rmm_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rmm_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_8x1_t value = __riscv_ztt_mls_rm_f16_rmm_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rmm_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_8x1_t value = __riscv_ztt_mls_cm_f16_rmm_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rmm_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_8x1_t value = __riscv_ztt_mls_st_f16_rmm_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rmm_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_8x1_t value = __riscv_ztt_mls_tst_f16_rmm_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rmm_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_1x16_t value = __riscv_ztt_mls_rm_f16_rmm_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rmm_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_1x16_t value = __riscv_ztt_mls_cm_f16_rmm_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rmm_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_1x16_t value = __riscv_ztt_mls_st_f16_rmm_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rmm_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_1x16_t value = __riscv_ztt_mls_tst_f16_rmm_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rmm_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_16x1_t value = __riscv_ztt_mls_rm_f16_rmm_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rmm_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_16x1_t value = __riscv_ztt_mls_cm_f16_rmm_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rmm_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_16x1_t value = __riscv_ztt_mls_st_f16_rmm_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rmm_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_16x1_t value = __riscv_ztt_mls_tst_f16_rmm_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rmm_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_1x32_t value = __riscv_ztt_mls_rm_f16_rmm_1x32 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rmm_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_1x32_t value = __riscv_ztt_mls_cm_f16_rmm_1x32 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rmm_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_1x32_t value = __riscv_ztt_mls_st_f16_rmm_1x32 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rmm_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_1x32_t value = __riscv_ztt_mls_tst_f16_rmm_1x32 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rmm_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_32x1_t value = __riscv_ztt_mls_rm_f16_rmm_32x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rmm_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_32x1_t value = __riscv_ztt_mls_cm_f16_rmm_32x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rmm_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_32x1_t value = __riscv_ztt_mls_st_f16_rmm_32x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rmm_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_32x1_t value = __riscv_ztt_mls_tst_f16_rmm_32x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rno_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_1x8_t value = __riscv_ztt_mls_rm_f16_rno_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rno_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_1x8_t value = __riscv_ztt_mls_cm_f16_rno_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rno_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_1x8_t value = __riscv_ztt_mls_st_f16_rno_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rno_1x8 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_1x8_t value = __riscv_ztt_mls_tst_f16_rno_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rno_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_8x1_t value = __riscv_ztt_mls_rm_f16_rno_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rno_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_8x1_t value = __riscv_ztt_mls_cm_f16_rno_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rno_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_8x1_t value = __riscv_ztt_mls_st_f16_rno_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rno_8x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_8x1_t value = __riscv_ztt_mls_tst_f16_rno_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rno_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_1x16_t value = __riscv_ztt_mls_rm_f16_rno_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rno_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_1x16_t value = __riscv_ztt_mls_cm_f16_rno_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rno_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_1x16_t value = __riscv_ztt_mls_st_f16_rno_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rno_1x16 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_1x16_t value = __riscv_ztt_mls_tst_f16_rno_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rno_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_16x1_t value = __riscv_ztt_mls_rm_f16_rno_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rno_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_16x1_t value = __riscv_ztt_mls_cm_f16_rno_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rno_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_16x1_t value = __riscv_ztt_mls_st_f16_rno_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rno_16x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_16x1_t value = __riscv_ztt_mls_tst_f16_rno_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rno_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_1x32_t value = __riscv_ztt_mls_rm_f16_rno_1x32 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rno_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_1x32_t value = __riscv_ztt_mls_cm_f16_rno_1x32 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rno_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_1x32_t value = __riscv_ztt_mls_st_f16_rno_1x32 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rno_1x32 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_1x32_t value = __riscv_ztt_mls_tst_f16_rno_1x32 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rno_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_32x1_t value = __riscv_ztt_mls_rm_f16_rno_32x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rno_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_32x1_t value = __riscv_ztt_mls_cm_f16_rno_32x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rno_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_32x1_t value = __riscv_ztt_mls_st_f16_rno_32x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rno_32x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_32x1_t value = __riscv_ztt_mls_tst_f16_rno_32x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rne_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_1x8_t value = __riscv_ztt_mls_rm_bf16_rne_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rne_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_1x8_t value = __riscv_ztt_mls_cm_bf16_rne_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rne_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_1x8_t value = __riscv_ztt_mls_st_bf16_rne_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rne_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_1x8_t value = __riscv_ztt_mls_tst_bf16_rne_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rne_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_8x1_t value = __riscv_ztt_mls_rm_bf16_rne_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rne_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_8x1_t value = __riscv_ztt_mls_cm_bf16_rne_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rne_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_8x1_t value = __riscv_ztt_mls_st_bf16_rne_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rne_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_8x1_t value = __riscv_ztt_mls_tst_bf16_rne_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rne_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_1x16_t value = __riscv_ztt_mls_rm_bf16_rne_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rne_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_1x16_t value = __riscv_ztt_mls_cm_bf16_rne_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rne_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_1x16_t value = __riscv_ztt_mls_st_bf16_rne_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rne_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_1x16_t value = __riscv_ztt_mls_tst_bf16_rne_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rne_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_16x1_t value = __riscv_ztt_mls_rm_bf16_rne_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rne_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_16x1_t value = __riscv_ztt_mls_cm_bf16_rne_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rne_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_16x1_t value = __riscv_ztt_mls_st_bf16_rne_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rne_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_16x1_t value = __riscv_ztt_mls_tst_bf16_rne_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rne_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_1x32_t value = __riscv_ztt_mls_rm_bf16_rne_1x32 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rne_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_1x32_t value = __riscv_ztt_mls_cm_bf16_rne_1x32 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rne_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_1x32_t value = __riscv_ztt_mls_st_bf16_rne_1x32 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rne_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_1x32_t value = __riscv_ztt_mls_tst_bf16_rne_1x32 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rne_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_32x1_t value = __riscv_ztt_mls_rm_bf16_rne_32x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rne_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_32x1_t value = __riscv_ztt_mls_cm_bf16_rne_32x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rne_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_32x1_t value = __riscv_ztt_mls_st_bf16_rne_32x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rne_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_32x1_t value = __riscv_ztt_mls_tst_bf16_rne_32x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rtz_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_1x8_t value = __riscv_ztt_mls_rm_bf16_rtz_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rtz_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_1x8_t value = __riscv_ztt_mls_cm_bf16_rtz_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rtz_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_1x8_t value = __riscv_ztt_mls_st_bf16_rtz_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rtz_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_1x8_t value = __riscv_ztt_mls_tst_bf16_rtz_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rtz_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_8x1_t value = __riscv_ztt_mls_rm_bf16_rtz_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rtz_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_8x1_t value = __riscv_ztt_mls_cm_bf16_rtz_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rtz_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_8x1_t value = __riscv_ztt_mls_st_bf16_rtz_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rtz_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_8x1_t value = __riscv_ztt_mls_tst_bf16_rtz_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rtz_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_1x16_t value = __riscv_ztt_mls_rm_bf16_rtz_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rtz_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_1x16_t value = __riscv_ztt_mls_cm_bf16_rtz_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rtz_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_1x16_t value = __riscv_ztt_mls_st_bf16_rtz_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rtz_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_1x16_t value = __riscv_ztt_mls_tst_bf16_rtz_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rtz_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_16x1_t value = __riscv_ztt_mls_rm_bf16_rtz_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rtz_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_16x1_t value = __riscv_ztt_mls_cm_bf16_rtz_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rtz_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_16x1_t value = __riscv_ztt_mls_st_bf16_rtz_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rtz_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_16x1_t value = __riscv_ztt_mls_tst_bf16_rtz_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rtz_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_1x32_t value = __riscv_ztt_mls_rm_bf16_rtz_1x32 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rtz_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_1x32_t value = __riscv_ztt_mls_cm_bf16_rtz_1x32 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rtz_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_1x32_t value = __riscv_ztt_mls_st_bf16_rtz_1x32 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rtz_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_1x32_t value = __riscv_ztt_mls_tst_bf16_rtz_1x32 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rtz_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_32x1_t value = __riscv_ztt_mls_rm_bf16_rtz_32x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rtz_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_32x1_t value = __riscv_ztt_mls_cm_bf16_rtz_32x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rtz_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_32x1_t value = __riscv_ztt_mls_st_bf16_rtz_32x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rtz_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_32x1_t value = __riscv_ztt_mls_tst_bf16_rtz_32x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rdn_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_1x8_t value = __riscv_ztt_mls_rm_bf16_rdn_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rdn_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_1x8_t value = __riscv_ztt_mls_cm_bf16_rdn_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rdn_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_1x8_t value = __riscv_ztt_mls_st_bf16_rdn_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rdn_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_1x8_t value = __riscv_ztt_mls_tst_bf16_rdn_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rdn_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_8x1_t value = __riscv_ztt_mls_rm_bf16_rdn_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rdn_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_8x1_t value = __riscv_ztt_mls_cm_bf16_rdn_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rdn_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_8x1_t value = __riscv_ztt_mls_st_bf16_rdn_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rdn_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_8x1_t value = __riscv_ztt_mls_tst_bf16_rdn_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rdn_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_1x16_t value = __riscv_ztt_mls_rm_bf16_rdn_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rdn_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_1x16_t value = __riscv_ztt_mls_cm_bf16_rdn_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rdn_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_1x16_t value = __riscv_ztt_mls_st_bf16_rdn_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rdn_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_1x16_t value = __riscv_ztt_mls_tst_bf16_rdn_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rdn_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_16x1_t value = __riscv_ztt_mls_rm_bf16_rdn_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rdn_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_16x1_t value = __riscv_ztt_mls_cm_bf16_rdn_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rdn_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_16x1_t value = __riscv_ztt_mls_st_bf16_rdn_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rdn_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_16x1_t value = __riscv_ztt_mls_tst_bf16_rdn_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rdn_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_1x32_t value = __riscv_ztt_mls_rm_bf16_rdn_1x32 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rdn_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_1x32_t value = __riscv_ztt_mls_cm_bf16_rdn_1x32 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rdn_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_1x32_t value = __riscv_ztt_mls_st_bf16_rdn_1x32 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rdn_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_1x32_t value = __riscv_ztt_mls_tst_bf16_rdn_1x32 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rdn_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_32x1_t value = __riscv_ztt_mls_rm_bf16_rdn_32x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rdn_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_32x1_t value = __riscv_ztt_mls_cm_bf16_rdn_32x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rdn_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_32x1_t value = __riscv_ztt_mls_st_bf16_rdn_32x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rdn_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_32x1_t value = __riscv_ztt_mls_tst_bf16_rdn_32x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rup_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_1x8_t value = __riscv_ztt_mls_rm_bf16_rup_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rup_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_1x8_t value = __riscv_ztt_mls_cm_bf16_rup_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rup_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_1x8_t value = __riscv_ztt_mls_st_bf16_rup_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rup_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_1x8_t value = __riscv_ztt_mls_tst_bf16_rup_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rup_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_8x1_t value = __riscv_ztt_mls_rm_bf16_rup_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rup_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_8x1_t value = __riscv_ztt_mls_cm_bf16_rup_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rup_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_8x1_t value = __riscv_ztt_mls_st_bf16_rup_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rup_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_8x1_t value = __riscv_ztt_mls_tst_bf16_rup_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rup_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_1x16_t value = __riscv_ztt_mls_rm_bf16_rup_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rup_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_1x16_t value = __riscv_ztt_mls_cm_bf16_rup_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rup_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_1x16_t value = __riscv_ztt_mls_st_bf16_rup_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rup_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_1x16_t value = __riscv_ztt_mls_tst_bf16_rup_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rup_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_16x1_t value = __riscv_ztt_mls_rm_bf16_rup_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rup_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_16x1_t value = __riscv_ztt_mls_cm_bf16_rup_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rup_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_16x1_t value = __riscv_ztt_mls_st_bf16_rup_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rup_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_16x1_t value = __riscv_ztt_mls_tst_bf16_rup_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rup_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_1x32_t value = __riscv_ztt_mls_rm_bf16_rup_1x32 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rup_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_1x32_t value = __riscv_ztt_mls_cm_bf16_rup_1x32 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rup_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_1x32_t value = __riscv_ztt_mls_st_bf16_rup_1x32 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rup_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_1x32_t value = __riscv_ztt_mls_tst_bf16_rup_1x32 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rup_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_32x1_t value = __riscv_ztt_mls_rm_bf16_rup_32x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rup_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_32x1_t value = __riscv_ztt_mls_cm_bf16_rup_32x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rup_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_32x1_t value = __riscv_ztt_mls_st_bf16_rup_32x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rup_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_32x1_t value = __riscv_ztt_mls_tst_bf16_rup_32x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rmm_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_1x8_t value = __riscv_ztt_mls_rm_bf16_rmm_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rmm_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_1x8_t value = __riscv_ztt_mls_cm_bf16_rmm_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rmm_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_1x8_t value = __riscv_ztt_mls_st_bf16_rmm_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rmm_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_1x8_t value = __riscv_ztt_mls_tst_bf16_rmm_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rmm_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_8x1_t value = __riscv_ztt_mls_rm_bf16_rmm_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rmm_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_8x1_t value = __riscv_ztt_mls_cm_bf16_rmm_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rmm_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_8x1_t value = __riscv_ztt_mls_st_bf16_rmm_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rmm_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_8x1_t value = __riscv_ztt_mls_tst_bf16_rmm_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rmm_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_1x16_t value = __riscv_ztt_mls_rm_bf16_rmm_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rmm_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_1x16_t value = __riscv_ztt_mls_cm_bf16_rmm_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rmm_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_1x16_t value = __riscv_ztt_mls_st_bf16_rmm_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rmm_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_1x16_t value = __riscv_ztt_mls_tst_bf16_rmm_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rmm_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_16x1_t value = __riscv_ztt_mls_rm_bf16_rmm_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rmm_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_16x1_t value = __riscv_ztt_mls_cm_bf16_rmm_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rmm_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_16x1_t value = __riscv_ztt_mls_st_bf16_rmm_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rmm_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_16x1_t value = __riscv_ztt_mls_tst_bf16_rmm_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rmm_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_1x32_t value = __riscv_ztt_mls_rm_bf16_rmm_1x32 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rmm_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_1x32_t value = __riscv_ztt_mls_cm_bf16_rmm_1x32 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rmm_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_1x32_t value = __riscv_ztt_mls_st_bf16_rmm_1x32 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rmm_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_1x32_t value = __riscv_ztt_mls_tst_bf16_rmm_1x32 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rmm_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_32x1_t value = __riscv_ztt_mls_rm_bf16_rmm_32x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rmm_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_32x1_t value = __riscv_ztt_mls_cm_bf16_rmm_32x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rmm_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_32x1_t value = __riscv_ztt_mls_st_bf16_rmm_32x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rmm_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_32x1_t value = __riscv_ztt_mls_tst_bf16_rmm_32x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rno_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_1x8_t value = __riscv_ztt_mls_rm_bf16_rno_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rno_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_1x8_t value = __riscv_ztt_mls_cm_bf16_rno_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rno_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_1x8_t value = __riscv_ztt_mls_st_bf16_rno_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rno_1x8 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_1x8_t value = __riscv_ztt_mls_tst_bf16_rno_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rno_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_8x1_t value = __riscv_ztt_mls_rm_bf16_rno_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rno_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_8x1_t value = __riscv_ztt_mls_cm_bf16_rno_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rno_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_8x1_t value = __riscv_ztt_mls_st_bf16_rno_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rno_8x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_8x1_t value = __riscv_ztt_mls_tst_bf16_rno_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rno_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_1x16_t value = __riscv_ztt_mls_rm_bf16_rno_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rno_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_1x16_t value = __riscv_ztt_mls_cm_bf16_rno_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rno_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_1x16_t value = __riscv_ztt_mls_st_bf16_rno_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rno_1x16 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_1x16_t value = __riscv_ztt_mls_tst_bf16_rno_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rno_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_16x1_t value = __riscv_ztt_mls_rm_bf16_rno_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rno_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_16x1_t value = __riscv_ztt_mls_cm_bf16_rno_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rno_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_16x1_t value = __riscv_ztt_mls_st_bf16_rno_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rno_16x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_16x1_t value = __riscv_ztt_mls_tst_bf16_rno_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rno_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_1x32_t value = __riscv_ztt_mls_rm_bf16_rno_1x32 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rno_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_1x32_t value = __riscv_ztt_mls_cm_bf16_rno_1x32 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rno_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_1x32_t value = __riscv_ztt_mls_st_bf16_rno_1x32 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rno_1x32 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_1x32_t value = __riscv_ztt_mls_tst_bf16_rno_1x32 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rno_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_32x1_t value = __riscv_ztt_mls_rm_bf16_rno_32x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rno_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_32x1_t value = __riscv_ztt_mls_cm_bf16_rno_32x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rno_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_32x1_t value = __riscv_ztt_mls_st_bf16_rno_32x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rno_32x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_32x1_t value = __riscv_ztt_mls_tst_bf16_rno_32x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rne_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_1x4_t value = __riscv_ztt_mls_rm_f32_rne_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rne_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_1x4_t value = __riscv_ztt_mls_cm_f32_rne_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rne_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_1x4_t value = __riscv_ztt_mls_st_f32_rne_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rne_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_1x4_t value = __riscv_ztt_mls_tst_f32_rne_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rne_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_4x1_t value = __riscv_ztt_mls_rm_f32_rne_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rne_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_4x1_t value = __riscv_ztt_mls_cm_f32_rne_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rne_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_4x1_t value = __riscv_ztt_mls_st_f32_rne_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rne_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_4x1_t value = __riscv_ztt_mls_tst_f32_rne_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rne_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_1x8_t value = __riscv_ztt_mls_rm_f32_rne_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rne_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_1x8_t value = __riscv_ztt_mls_cm_f32_rne_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rne_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_1x8_t value = __riscv_ztt_mls_st_f32_rne_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rne_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_1x8_t value = __riscv_ztt_mls_tst_f32_rne_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rne_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_8x1_t value = __riscv_ztt_mls_rm_f32_rne_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rne_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_8x1_t value = __riscv_ztt_mls_cm_f32_rne_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rne_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_8x1_t value = __riscv_ztt_mls_st_f32_rne_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rne_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_8x1_t value = __riscv_ztt_mls_tst_f32_rne_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rne_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_1x16_t value = __riscv_ztt_mls_rm_f32_rne_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rne_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_1x16_t value = __riscv_ztt_mls_cm_f32_rne_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rne_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_1x16_t value = __riscv_ztt_mls_st_f32_rne_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rne_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_1x16_t value = __riscv_ztt_mls_tst_f32_rne_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rne_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_16x1_t value = __riscv_ztt_mls_rm_f32_rne_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rne_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_16x1_t value = __riscv_ztt_mls_cm_f32_rne_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rne_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_16x1_t value = __riscv_ztt_mls_st_f32_rne_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rne_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_16x1_t value = __riscv_ztt_mls_tst_f32_rne_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rtz_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_1x4_t value = __riscv_ztt_mls_rm_f32_rtz_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rtz_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_1x4_t value = __riscv_ztt_mls_cm_f32_rtz_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rtz_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_1x4_t value = __riscv_ztt_mls_st_f32_rtz_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rtz_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_1x4_t value = __riscv_ztt_mls_tst_f32_rtz_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rtz_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_4x1_t value = __riscv_ztt_mls_rm_f32_rtz_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rtz_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_4x1_t value = __riscv_ztt_mls_cm_f32_rtz_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rtz_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_4x1_t value = __riscv_ztt_mls_st_f32_rtz_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rtz_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_4x1_t value = __riscv_ztt_mls_tst_f32_rtz_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rtz_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_1x8_t value = __riscv_ztt_mls_rm_f32_rtz_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rtz_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_1x8_t value = __riscv_ztt_mls_cm_f32_rtz_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rtz_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_1x8_t value = __riscv_ztt_mls_st_f32_rtz_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rtz_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_1x8_t value = __riscv_ztt_mls_tst_f32_rtz_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rtz_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_8x1_t value = __riscv_ztt_mls_rm_f32_rtz_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rtz_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_8x1_t value = __riscv_ztt_mls_cm_f32_rtz_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rtz_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_8x1_t value = __riscv_ztt_mls_st_f32_rtz_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rtz_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_8x1_t value = __riscv_ztt_mls_tst_f32_rtz_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rtz_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_1x16_t value = __riscv_ztt_mls_rm_f32_rtz_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rtz_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_1x16_t value = __riscv_ztt_mls_cm_f32_rtz_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rtz_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_1x16_t value = __riscv_ztt_mls_st_f32_rtz_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rtz_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_1x16_t value = __riscv_ztt_mls_tst_f32_rtz_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rtz_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_16x1_t value = __riscv_ztt_mls_rm_f32_rtz_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rtz_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_16x1_t value = __riscv_ztt_mls_cm_f32_rtz_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rtz_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_16x1_t value = __riscv_ztt_mls_st_f32_rtz_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rtz_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_16x1_t value = __riscv_ztt_mls_tst_f32_rtz_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rdn_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_1x4_t value = __riscv_ztt_mls_rm_f32_rdn_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rdn_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_1x4_t value = __riscv_ztt_mls_cm_f32_rdn_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rdn_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_1x4_t value = __riscv_ztt_mls_st_f32_rdn_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rdn_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_1x4_t value = __riscv_ztt_mls_tst_f32_rdn_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rdn_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_4x1_t value = __riscv_ztt_mls_rm_f32_rdn_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rdn_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_4x1_t value = __riscv_ztt_mls_cm_f32_rdn_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rdn_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_4x1_t value = __riscv_ztt_mls_st_f32_rdn_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rdn_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_4x1_t value = __riscv_ztt_mls_tst_f32_rdn_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rdn_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_1x8_t value = __riscv_ztt_mls_rm_f32_rdn_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rdn_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_1x8_t value = __riscv_ztt_mls_cm_f32_rdn_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rdn_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_1x8_t value = __riscv_ztt_mls_st_f32_rdn_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rdn_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_1x8_t value = __riscv_ztt_mls_tst_f32_rdn_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rdn_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_8x1_t value = __riscv_ztt_mls_rm_f32_rdn_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rdn_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_8x1_t value = __riscv_ztt_mls_cm_f32_rdn_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rdn_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_8x1_t value = __riscv_ztt_mls_st_f32_rdn_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rdn_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_8x1_t value = __riscv_ztt_mls_tst_f32_rdn_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rdn_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_1x16_t value = __riscv_ztt_mls_rm_f32_rdn_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rdn_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_1x16_t value = __riscv_ztt_mls_cm_f32_rdn_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rdn_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_1x16_t value = __riscv_ztt_mls_st_f32_rdn_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rdn_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_1x16_t value = __riscv_ztt_mls_tst_f32_rdn_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rdn_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_16x1_t value = __riscv_ztt_mls_rm_f32_rdn_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rdn_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_16x1_t value = __riscv_ztt_mls_cm_f32_rdn_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rdn_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_16x1_t value = __riscv_ztt_mls_st_f32_rdn_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rdn_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_16x1_t value = __riscv_ztt_mls_tst_f32_rdn_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rup_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_1x4_t value = __riscv_ztt_mls_rm_f32_rup_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rup_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_1x4_t value = __riscv_ztt_mls_cm_f32_rup_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rup_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_1x4_t value = __riscv_ztt_mls_st_f32_rup_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rup_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_1x4_t value = __riscv_ztt_mls_tst_f32_rup_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rup_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_4x1_t value = __riscv_ztt_mls_rm_f32_rup_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rup_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_4x1_t value = __riscv_ztt_mls_cm_f32_rup_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rup_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_4x1_t value = __riscv_ztt_mls_st_f32_rup_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rup_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_4x1_t value = __riscv_ztt_mls_tst_f32_rup_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rup_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_1x8_t value = __riscv_ztt_mls_rm_f32_rup_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rup_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_1x8_t value = __riscv_ztt_mls_cm_f32_rup_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rup_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_1x8_t value = __riscv_ztt_mls_st_f32_rup_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rup_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_1x8_t value = __riscv_ztt_mls_tst_f32_rup_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rup_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_8x1_t value = __riscv_ztt_mls_rm_f32_rup_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rup_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_8x1_t value = __riscv_ztt_mls_cm_f32_rup_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rup_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_8x1_t value = __riscv_ztt_mls_st_f32_rup_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rup_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_8x1_t value = __riscv_ztt_mls_tst_f32_rup_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rup_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_1x16_t value = __riscv_ztt_mls_rm_f32_rup_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rup_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_1x16_t value = __riscv_ztt_mls_cm_f32_rup_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rup_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_1x16_t value = __riscv_ztt_mls_st_f32_rup_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rup_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_1x16_t value = __riscv_ztt_mls_tst_f32_rup_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rup_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_16x1_t value = __riscv_ztt_mls_rm_f32_rup_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rup_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_16x1_t value = __riscv_ztt_mls_cm_f32_rup_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rup_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_16x1_t value = __riscv_ztt_mls_st_f32_rup_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rup_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_16x1_t value = __riscv_ztt_mls_tst_f32_rup_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rmm_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_1x4_t value = __riscv_ztt_mls_rm_f32_rmm_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rmm_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_1x4_t value = __riscv_ztt_mls_cm_f32_rmm_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rmm_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_1x4_t value = __riscv_ztt_mls_st_f32_rmm_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rmm_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_1x4_t value = __riscv_ztt_mls_tst_f32_rmm_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rmm_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_4x1_t value = __riscv_ztt_mls_rm_f32_rmm_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rmm_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_4x1_t value = __riscv_ztt_mls_cm_f32_rmm_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rmm_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_4x1_t value = __riscv_ztt_mls_st_f32_rmm_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rmm_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_4x1_t value = __riscv_ztt_mls_tst_f32_rmm_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rmm_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_1x8_t value = __riscv_ztt_mls_rm_f32_rmm_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rmm_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_1x8_t value = __riscv_ztt_mls_cm_f32_rmm_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rmm_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_1x8_t value = __riscv_ztt_mls_st_f32_rmm_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rmm_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_1x8_t value = __riscv_ztt_mls_tst_f32_rmm_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rmm_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_8x1_t value = __riscv_ztt_mls_rm_f32_rmm_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rmm_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_8x1_t value = __riscv_ztt_mls_cm_f32_rmm_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rmm_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_8x1_t value = __riscv_ztt_mls_st_f32_rmm_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rmm_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_8x1_t value = __riscv_ztt_mls_tst_f32_rmm_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rmm_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_1x16_t value = __riscv_ztt_mls_rm_f32_rmm_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rmm_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_1x16_t value = __riscv_ztt_mls_cm_f32_rmm_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rmm_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_1x16_t value = __riscv_ztt_mls_st_f32_rmm_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rmm_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_1x16_t value = __riscv_ztt_mls_tst_f32_rmm_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rmm_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_16x1_t value = __riscv_ztt_mls_rm_f32_rmm_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rmm_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_16x1_t value = __riscv_ztt_mls_cm_f32_rmm_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rmm_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_16x1_t value = __riscv_ztt_mls_st_f32_rmm_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rmm_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_16x1_t value = __riscv_ztt_mls_tst_f32_rmm_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rno_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_1x4_t value = __riscv_ztt_mls_rm_f32_rno_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rno_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_1x4_t value = __riscv_ztt_mls_cm_f32_rno_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rno_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_1x4_t value = __riscv_ztt_mls_st_f32_rno_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rno_1x4 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_1x4_t value = __riscv_ztt_mls_tst_f32_rno_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rno_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_4x1_t value = __riscv_ztt_mls_rm_f32_rno_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rno_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_4x1_t value = __riscv_ztt_mls_cm_f32_rno_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rno_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_4x1_t value = __riscv_ztt_mls_st_f32_rno_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rno_4x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_4x1_t value = __riscv_ztt_mls_tst_f32_rno_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rno_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_1x8_t value = __riscv_ztt_mls_rm_f32_rno_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rno_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_1x8_t value = __riscv_ztt_mls_cm_f32_rno_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rno_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_1x8_t value = __riscv_ztt_mls_st_f32_rno_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rno_1x8 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_1x8_t value = __riscv_ztt_mls_tst_f32_rno_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rno_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_8x1_t value = __riscv_ztt_mls_rm_f32_rno_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rno_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_8x1_t value = __riscv_ztt_mls_cm_f32_rno_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rno_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_8x1_t value = __riscv_ztt_mls_st_f32_rno_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rno_8x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_8x1_t value = __riscv_ztt_mls_tst_f32_rno_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rno_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_1x16_t value = __riscv_ztt_mls_rm_f32_rno_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rno_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_1x16_t value = __riscv_ztt_mls_cm_f32_rno_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rno_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_1x16_t value = __riscv_ztt_mls_st_f32_rno_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rno_1x16 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_1x16_t value = __riscv_ztt_mls_tst_f32_rno_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rno_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_16x1_t value = __riscv_ztt_mls_rm_f32_rno_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rno_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_16x1_t value = __riscv_ztt_mls_cm_f32_rno_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rno_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_16x1_t value = __riscv_ztt_mls_st_f32_rno_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rno_16x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_16x1_t value = __riscv_ztt_mls_tst_f32_rno_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rne_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_1x2_t value = __riscv_ztt_mls_rm_f64_rne_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rne_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_1x2_t value = __riscv_ztt_mls_cm_f64_rne_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rne_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_1x2_t value = __riscv_ztt_mls_st_f64_rne_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rne_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_1x2_t value = __riscv_ztt_mls_tst_f64_rne_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rne_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_2x1_t value = __riscv_ztt_mls_rm_f64_rne_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rne_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_2x1_t value = __riscv_ztt_mls_cm_f64_rne_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rne_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_2x1_t value = __riscv_ztt_mls_st_f64_rne_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rne_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_2x1_t value = __riscv_ztt_mls_tst_f64_rne_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rne_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_1x4_t value = __riscv_ztt_mls_rm_f64_rne_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rne_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_1x4_t value = __riscv_ztt_mls_cm_f64_rne_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rne_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_1x4_t value = __riscv_ztt_mls_st_f64_rne_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rne_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_1x4_t value = __riscv_ztt_mls_tst_f64_rne_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rne_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_4x1_t value = __riscv_ztt_mls_rm_f64_rne_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rne_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_4x1_t value = __riscv_ztt_mls_cm_f64_rne_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rne_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_4x1_t value = __riscv_ztt_mls_st_f64_rne_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rne_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_4x1_t value = __riscv_ztt_mls_tst_f64_rne_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rne_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_1x8_t value = __riscv_ztt_mls_rm_f64_rne_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rne_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_1x8_t value = __riscv_ztt_mls_cm_f64_rne_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rne_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_1x8_t value = __riscv_ztt_mls_st_f64_rne_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rne_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_1x8_t value = __riscv_ztt_mls_tst_f64_rne_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rne_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_8x1_t value = __riscv_ztt_mls_rm_f64_rne_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rne_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_8x1_t value = __riscv_ztt_mls_cm_f64_rne_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rne_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_8x1_t value = __riscv_ztt_mls_st_f64_rne_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rne_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_8x1_t value = __riscv_ztt_mls_tst_f64_rne_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rtz_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_1x2_t value = __riscv_ztt_mls_rm_f64_rtz_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rtz_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_1x2_t value = __riscv_ztt_mls_cm_f64_rtz_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rtz_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_1x2_t value = __riscv_ztt_mls_st_f64_rtz_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rtz_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_1x2_t value = __riscv_ztt_mls_tst_f64_rtz_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rtz_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_2x1_t value = __riscv_ztt_mls_rm_f64_rtz_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rtz_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_2x1_t value = __riscv_ztt_mls_cm_f64_rtz_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rtz_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_2x1_t value = __riscv_ztt_mls_st_f64_rtz_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rtz_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_2x1_t value = __riscv_ztt_mls_tst_f64_rtz_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rtz_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_1x4_t value = __riscv_ztt_mls_rm_f64_rtz_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rtz_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_1x4_t value = __riscv_ztt_mls_cm_f64_rtz_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rtz_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_1x4_t value = __riscv_ztt_mls_st_f64_rtz_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rtz_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_1x4_t value = __riscv_ztt_mls_tst_f64_rtz_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rtz_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_4x1_t value = __riscv_ztt_mls_rm_f64_rtz_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rtz_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_4x1_t value = __riscv_ztt_mls_cm_f64_rtz_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rtz_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_4x1_t value = __riscv_ztt_mls_st_f64_rtz_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rtz_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_4x1_t value = __riscv_ztt_mls_tst_f64_rtz_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rtz_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_1x8_t value = __riscv_ztt_mls_rm_f64_rtz_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rtz_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_1x8_t value = __riscv_ztt_mls_cm_f64_rtz_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rtz_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_1x8_t value = __riscv_ztt_mls_st_f64_rtz_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rtz_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_1x8_t value = __riscv_ztt_mls_tst_f64_rtz_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rtz_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_8x1_t value = __riscv_ztt_mls_rm_f64_rtz_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rtz_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_8x1_t value = __riscv_ztt_mls_cm_f64_rtz_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rtz_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_8x1_t value = __riscv_ztt_mls_st_f64_rtz_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rtz_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_8x1_t value = __riscv_ztt_mls_tst_f64_rtz_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rdn_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_1x2_t value = __riscv_ztt_mls_rm_f64_rdn_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rdn_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_1x2_t value = __riscv_ztt_mls_cm_f64_rdn_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rdn_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_1x2_t value = __riscv_ztt_mls_st_f64_rdn_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rdn_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_1x2_t value = __riscv_ztt_mls_tst_f64_rdn_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rdn_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_2x1_t value = __riscv_ztt_mls_rm_f64_rdn_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rdn_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_2x1_t value = __riscv_ztt_mls_cm_f64_rdn_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rdn_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_2x1_t value = __riscv_ztt_mls_st_f64_rdn_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rdn_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_2x1_t value = __riscv_ztt_mls_tst_f64_rdn_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rdn_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_1x4_t value = __riscv_ztt_mls_rm_f64_rdn_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rdn_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_1x4_t value = __riscv_ztt_mls_cm_f64_rdn_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rdn_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_1x4_t value = __riscv_ztt_mls_st_f64_rdn_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rdn_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_1x4_t value = __riscv_ztt_mls_tst_f64_rdn_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rdn_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_4x1_t value = __riscv_ztt_mls_rm_f64_rdn_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rdn_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_4x1_t value = __riscv_ztt_mls_cm_f64_rdn_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rdn_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_4x1_t value = __riscv_ztt_mls_st_f64_rdn_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rdn_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_4x1_t value = __riscv_ztt_mls_tst_f64_rdn_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rdn_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_1x8_t value = __riscv_ztt_mls_rm_f64_rdn_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rdn_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_1x8_t value = __riscv_ztt_mls_cm_f64_rdn_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rdn_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_1x8_t value = __riscv_ztt_mls_st_f64_rdn_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rdn_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_1x8_t value = __riscv_ztt_mls_tst_f64_rdn_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rdn_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_8x1_t value = __riscv_ztt_mls_rm_f64_rdn_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rdn_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_8x1_t value = __riscv_ztt_mls_cm_f64_rdn_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rdn_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_8x1_t value = __riscv_ztt_mls_st_f64_rdn_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rdn_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_8x1_t value = __riscv_ztt_mls_tst_f64_rdn_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rup_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_1x2_t value = __riscv_ztt_mls_rm_f64_rup_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rup_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_1x2_t value = __riscv_ztt_mls_cm_f64_rup_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rup_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_1x2_t value = __riscv_ztt_mls_st_f64_rup_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rup_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_1x2_t value = __riscv_ztt_mls_tst_f64_rup_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rup_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_2x1_t value = __riscv_ztt_mls_rm_f64_rup_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rup_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_2x1_t value = __riscv_ztt_mls_cm_f64_rup_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rup_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_2x1_t value = __riscv_ztt_mls_st_f64_rup_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rup_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_2x1_t value = __riscv_ztt_mls_tst_f64_rup_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rup_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_1x4_t value = __riscv_ztt_mls_rm_f64_rup_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rup_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_1x4_t value = __riscv_ztt_mls_cm_f64_rup_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rup_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_1x4_t value = __riscv_ztt_mls_st_f64_rup_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rup_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_1x4_t value = __riscv_ztt_mls_tst_f64_rup_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rup_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_4x1_t value = __riscv_ztt_mls_rm_f64_rup_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rup_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_4x1_t value = __riscv_ztt_mls_cm_f64_rup_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rup_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_4x1_t value = __riscv_ztt_mls_st_f64_rup_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rup_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_4x1_t value = __riscv_ztt_mls_tst_f64_rup_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rup_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_1x8_t value = __riscv_ztt_mls_rm_f64_rup_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rup_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_1x8_t value = __riscv_ztt_mls_cm_f64_rup_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rup_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_1x8_t value = __riscv_ztt_mls_st_f64_rup_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rup_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_1x8_t value = __riscv_ztt_mls_tst_f64_rup_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rup_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_8x1_t value = __riscv_ztt_mls_rm_f64_rup_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rup_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_8x1_t value = __riscv_ztt_mls_cm_f64_rup_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rup_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_8x1_t value = __riscv_ztt_mls_st_f64_rup_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rup_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_8x1_t value = __riscv_ztt_mls_tst_f64_rup_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rmm_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_1x2_t value = __riscv_ztt_mls_rm_f64_rmm_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rmm_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_1x2_t value = __riscv_ztt_mls_cm_f64_rmm_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rmm_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_1x2_t value = __riscv_ztt_mls_st_f64_rmm_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rmm_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_1x2_t value = __riscv_ztt_mls_tst_f64_rmm_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rmm_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_2x1_t value = __riscv_ztt_mls_rm_f64_rmm_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rmm_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_2x1_t value = __riscv_ztt_mls_cm_f64_rmm_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rmm_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_2x1_t value = __riscv_ztt_mls_st_f64_rmm_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rmm_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_2x1_t value = __riscv_ztt_mls_tst_f64_rmm_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rmm_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_1x4_t value = __riscv_ztt_mls_rm_f64_rmm_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rmm_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_1x4_t value = __riscv_ztt_mls_cm_f64_rmm_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rmm_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_1x4_t value = __riscv_ztt_mls_st_f64_rmm_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rmm_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_1x4_t value = __riscv_ztt_mls_tst_f64_rmm_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rmm_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_4x1_t value = __riscv_ztt_mls_rm_f64_rmm_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rmm_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_4x1_t value = __riscv_ztt_mls_cm_f64_rmm_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rmm_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_4x1_t value = __riscv_ztt_mls_st_f64_rmm_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rmm_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_4x1_t value = __riscv_ztt_mls_tst_f64_rmm_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rmm_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_1x8_t value = __riscv_ztt_mls_rm_f64_rmm_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rmm_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_1x8_t value = __riscv_ztt_mls_cm_f64_rmm_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rmm_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_1x8_t value = __riscv_ztt_mls_st_f64_rmm_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rmm_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_1x8_t value = __riscv_ztt_mls_tst_f64_rmm_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rmm_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_8x1_t value = __riscv_ztt_mls_rm_f64_rmm_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rmm_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_8x1_t value = __riscv_ztt_mls_cm_f64_rmm_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rmm_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_8x1_t value = __riscv_ztt_mls_st_f64_rmm_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rmm_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_8x1_t value = __riscv_ztt_mls_tst_f64_rmm_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rno_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_1x2_t value = __riscv_ztt_mls_rm_f64_rno_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rno_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_1x2_t value = __riscv_ztt_mls_cm_f64_rno_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rno_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_1x2_t value = __riscv_ztt_mls_st_f64_rno_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rno_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_1x2_t value = __riscv_ztt_mls_tst_f64_rno_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rno_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_2x1_t value = __riscv_ztt_mls_rm_f64_rno_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rno_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_2x1_t value = __riscv_ztt_mls_cm_f64_rno_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rno_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_2x1_t value = __riscv_ztt_mls_st_f64_rno_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rno_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_2x1_t value = __riscv_ztt_mls_tst_f64_rno_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rno_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_1x4_t value = __riscv_ztt_mls_rm_f64_rno_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rno_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_1x4_t value = __riscv_ztt_mls_cm_f64_rno_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rno_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_1x4_t value = __riscv_ztt_mls_st_f64_rno_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rno_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_1x4_t value = __riscv_ztt_mls_tst_f64_rno_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rno_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_4x1_t value = __riscv_ztt_mls_rm_f64_rno_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rno_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_4x1_t value = __riscv_ztt_mls_cm_f64_rno_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rno_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_4x1_t value = __riscv_ztt_mls_st_f64_rno_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rno_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_4x1_t value = __riscv_ztt_mls_tst_f64_rno_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rno_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_1x8_t value = __riscv_ztt_mls_rm_f64_rno_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rno_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_1x8_t value = __riscv_ztt_mls_cm_f64_rno_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rno_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_1x8_t value = __riscv_ztt_mls_st_f64_rno_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rno_1x8 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_1x8_t value = __riscv_ztt_mls_tst_f64_rno_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f64_rno_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_8x1_t value = __riscv_ztt_mls_rm_f64_rno_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f64_rno_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_8x1_t value = __riscv_ztt_mls_cm_f64_rno_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f64_rno_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_8x1_t value = __riscv_ztt_mls_st_f64_rno_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f64_rno_8x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_8x1_t value = __riscv_ztt_mls_tst_f64_rno_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
