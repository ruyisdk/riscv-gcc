/* 128-bit storage elements, not ordinary C integer arithmetic.  */
/* { dg-do assemble } */
/* { dg-options "-O0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a16" { target rv32 } } */
/* { dg-options "-O0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a16" { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>
void mem128_rm_i128_rnu_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_1x1_t value = __riscv_ztt_mls_rm_i128_rnu_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rnu_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_1x1_t value = __riscv_ztt_mls_cm_i128_rnu_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rnu_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_1x1_t value = __riscv_ztt_mls_st_i128_rnu_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rnu_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_1x1_t value = __riscv_ztt_mls_tst_i128_rnu_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rnu_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_1x2_t value = __riscv_ztt_mls_rm_i128_rnu_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rnu_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_1x2_t value = __riscv_ztt_mls_cm_i128_rnu_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rnu_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_1x2_t value = __riscv_ztt_mls_st_i128_rnu_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rnu_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_1x2_t value = __riscv_ztt_mls_tst_i128_rnu_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rnu_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_2x1_t value = __riscv_ztt_mls_rm_i128_rnu_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rnu_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_2x1_t value = __riscv_ztt_mls_cm_i128_rnu_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rnu_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_2x1_t value = __riscv_ztt_mls_st_i128_rnu_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rnu_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_2x1_t value = __riscv_ztt_mls_tst_i128_rnu_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rnu_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_1x4_t value = __riscv_ztt_mls_rm_i128_rnu_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rnu_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_1x4_t value = __riscv_ztt_mls_cm_i128_rnu_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rnu_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_1x4_t value = __riscv_ztt_mls_st_i128_rnu_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rnu_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_1x4_t value = __riscv_ztt_mls_tst_i128_rnu_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rnu_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_4x1_t value = __riscv_ztt_mls_rm_i128_rnu_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rnu_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_4x1_t value = __riscv_ztt_mls_cm_i128_rnu_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rnu_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_4x1_t value = __riscv_ztt_mls_st_i128_rnu_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rnu_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_4x1_t value = __riscv_ztt_mls_tst_i128_rnu_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rnu_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_1x8_t value = __riscv_ztt_mls_rm_i128_rnu_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rnu_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_1x8_t value = __riscv_ztt_mls_cm_i128_rnu_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rnu_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_1x8_t value = __riscv_ztt_mls_st_i128_rnu_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rnu_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_1x8_t value = __riscv_ztt_mls_tst_i128_rnu_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rnu_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_8x1_t value = __riscv_ztt_mls_rm_i128_rnu_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rnu_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_8x1_t value = __riscv_ztt_mls_cm_i128_rnu_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rnu_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_8x1_t value = __riscv_ztt_mls_st_i128_rnu_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rnu_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_8x1_t value = __riscv_ztt_mls_tst_i128_rnu_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rnu_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_1x16_t value = __riscv_ztt_mls_rm_i128_rnu_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rnu_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_1x16_t value = __riscv_ztt_mls_cm_i128_rnu_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rnu_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_1x16_t value = __riscv_ztt_mls_st_i128_rnu_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rnu_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_1x16_t value = __riscv_ztt_mls_tst_i128_rnu_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rnu_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_16x1_t value = __riscv_ztt_mls_rm_i128_rnu_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rnu_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_16x1_t value = __riscv_ztt_mls_cm_i128_rnu_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rnu_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_16x1_t value = __riscv_ztt_mls_st_i128_rnu_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rnu_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_16x1_t value = __riscv_ztt_mls_tst_i128_rnu_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rne_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_1x1_t value = __riscv_ztt_mls_rm_i128_rne_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rne_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_1x1_t value = __riscv_ztt_mls_cm_i128_rne_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rne_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_1x1_t value = __riscv_ztt_mls_st_i128_rne_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rne_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_1x1_t value = __riscv_ztt_mls_tst_i128_rne_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rne_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_1x2_t value = __riscv_ztt_mls_rm_i128_rne_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rne_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_1x2_t value = __riscv_ztt_mls_cm_i128_rne_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rne_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_1x2_t value = __riscv_ztt_mls_st_i128_rne_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rne_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_1x2_t value = __riscv_ztt_mls_tst_i128_rne_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rne_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_2x1_t value = __riscv_ztt_mls_rm_i128_rne_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rne_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_2x1_t value = __riscv_ztt_mls_cm_i128_rne_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rne_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_2x1_t value = __riscv_ztt_mls_st_i128_rne_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rne_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_2x1_t value = __riscv_ztt_mls_tst_i128_rne_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rne_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_1x4_t value = __riscv_ztt_mls_rm_i128_rne_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rne_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_1x4_t value = __riscv_ztt_mls_cm_i128_rne_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rne_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_1x4_t value = __riscv_ztt_mls_st_i128_rne_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rne_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_1x4_t value = __riscv_ztt_mls_tst_i128_rne_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rne_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_4x1_t value = __riscv_ztt_mls_rm_i128_rne_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rne_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_4x1_t value = __riscv_ztt_mls_cm_i128_rne_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rne_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_4x1_t value = __riscv_ztt_mls_st_i128_rne_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rne_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_4x1_t value = __riscv_ztt_mls_tst_i128_rne_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rne_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_1x8_t value = __riscv_ztt_mls_rm_i128_rne_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rne_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_1x8_t value = __riscv_ztt_mls_cm_i128_rne_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rne_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_1x8_t value = __riscv_ztt_mls_st_i128_rne_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rne_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_1x8_t value = __riscv_ztt_mls_tst_i128_rne_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rne_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_8x1_t value = __riscv_ztt_mls_rm_i128_rne_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rne_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_8x1_t value = __riscv_ztt_mls_cm_i128_rne_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rne_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_8x1_t value = __riscv_ztt_mls_st_i128_rne_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rne_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_8x1_t value = __riscv_ztt_mls_tst_i128_rne_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rne_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_1x16_t value = __riscv_ztt_mls_rm_i128_rne_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rne_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_1x16_t value = __riscv_ztt_mls_cm_i128_rne_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rne_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_1x16_t value = __riscv_ztt_mls_st_i128_rne_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rne_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_1x16_t value = __riscv_ztt_mls_tst_i128_rne_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rne_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_16x1_t value = __riscv_ztt_mls_rm_i128_rne_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rne_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_16x1_t value = __riscv_ztt_mls_cm_i128_rne_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rne_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_16x1_t value = __riscv_ztt_mls_st_i128_rne_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rne_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_16x1_t value = __riscv_ztt_mls_tst_i128_rne_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rdn_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_1x1_t value = __riscv_ztt_mls_rm_i128_rdn_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rdn_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_1x1_t value = __riscv_ztt_mls_cm_i128_rdn_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rdn_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_1x1_t value = __riscv_ztt_mls_st_i128_rdn_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rdn_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_1x1_t value = __riscv_ztt_mls_tst_i128_rdn_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rdn_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_1x2_t value = __riscv_ztt_mls_rm_i128_rdn_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rdn_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_1x2_t value = __riscv_ztt_mls_cm_i128_rdn_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rdn_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_1x2_t value = __riscv_ztt_mls_st_i128_rdn_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rdn_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_1x2_t value = __riscv_ztt_mls_tst_i128_rdn_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rdn_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_2x1_t value = __riscv_ztt_mls_rm_i128_rdn_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rdn_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_2x1_t value = __riscv_ztt_mls_cm_i128_rdn_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rdn_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_2x1_t value = __riscv_ztt_mls_st_i128_rdn_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rdn_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_2x1_t value = __riscv_ztt_mls_tst_i128_rdn_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rdn_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_1x4_t value = __riscv_ztt_mls_rm_i128_rdn_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rdn_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_1x4_t value = __riscv_ztt_mls_cm_i128_rdn_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rdn_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_1x4_t value = __riscv_ztt_mls_st_i128_rdn_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rdn_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_1x4_t value = __riscv_ztt_mls_tst_i128_rdn_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rdn_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_4x1_t value = __riscv_ztt_mls_rm_i128_rdn_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rdn_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_4x1_t value = __riscv_ztt_mls_cm_i128_rdn_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rdn_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_4x1_t value = __riscv_ztt_mls_st_i128_rdn_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rdn_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_4x1_t value = __riscv_ztt_mls_tst_i128_rdn_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rdn_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_1x8_t value = __riscv_ztt_mls_rm_i128_rdn_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rdn_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_1x8_t value = __riscv_ztt_mls_cm_i128_rdn_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rdn_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_1x8_t value = __riscv_ztt_mls_st_i128_rdn_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rdn_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_1x8_t value = __riscv_ztt_mls_tst_i128_rdn_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rdn_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_8x1_t value = __riscv_ztt_mls_rm_i128_rdn_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rdn_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_8x1_t value = __riscv_ztt_mls_cm_i128_rdn_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rdn_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_8x1_t value = __riscv_ztt_mls_st_i128_rdn_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rdn_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_8x1_t value = __riscv_ztt_mls_tst_i128_rdn_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rdn_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_1x16_t value = __riscv_ztt_mls_rm_i128_rdn_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rdn_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_1x16_t value = __riscv_ztt_mls_cm_i128_rdn_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rdn_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_1x16_t value = __riscv_ztt_mls_st_i128_rdn_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rdn_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_1x16_t value = __riscv_ztt_mls_tst_i128_rdn_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rdn_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_16x1_t value = __riscv_ztt_mls_rm_i128_rdn_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rdn_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_16x1_t value = __riscv_ztt_mls_cm_i128_rdn_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rdn_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_16x1_t value = __riscv_ztt_mls_st_i128_rdn_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rdn_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_16x1_t value = __riscv_ztt_mls_tst_i128_rdn_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rod_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_1x1_t value = __riscv_ztt_mls_rm_i128_rod_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rod_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_1x1_t value = __riscv_ztt_mls_cm_i128_rod_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rod_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_1x1_t value = __riscv_ztt_mls_st_i128_rod_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rod_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_1x1_t value = __riscv_ztt_mls_tst_i128_rod_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rod_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_1x2_t value = __riscv_ztt_mls_rm_i128_rod_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rod_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_1x2_t value = __riscv_ztt_mls_cm_i128_rod_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rod_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_1x2_t value = __riscv_ztt_mls_st_i128_rod_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rod_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_1x2_t value = __riscv_ztt_mls_tst_i128_rod_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rod_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_2x1_t value = __riscv_ztt_mls_rm_i128_rod_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rod_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_2x1_t value = __riscv_ztt_mls_cm_i128_rod_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rod_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_2x1_t value = __riscv_ztt_mls_st_i128_rod_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rod_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_2x1_t value = __riscv_ztt_mls_tst_i128_rod_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rod_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_1x4_t value = __riscv_ztt_mls_rm_i128_rod_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rod_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_1x4_t value = __riscv_ztt_mls_cm_i128_rod_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rod_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_1x4_t value = __riscv_ztt_mls_st_i128_rod_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rod_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_1x4_t value = __riscv_ztt_mls_tst_i128_rod_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rod_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_4x1_t value = __riscv_ztt_mls_rm_i128_rod_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rod_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_4x1_t value = __riscv_ztt_mls_cm_i128_rod_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rod_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_4x1_t value = __riscv_ztt_mls_st_i128_rod_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rod_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_4x1_t value = __riscv_ztt_mls_tst_i128_rod_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rod_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_1x8_t value = __riscv_ztt_mls_rm_i128_rod_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rod_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_1x8_t value = __riscv_ztt_mls_cm_i128_rod_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rod_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_1x8_t value = __riscv_ztt_mls_st_i128_rod_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rod_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_1x8_t value = __riscv_ztt_mls_tst_i128_rod_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rod_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_8x1_t value = __riscv_ztt_mls_rm_i128_rod_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rod_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_8x1_t value = __riscv_ztt_mls_cm_i128_rod_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rod_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_8x1_t value = __riscv_ztt_mls_st_i128_rod_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rod_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_8x1_t value = __riscv_ztt_mls_tst_i128_rod_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rod_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_1x16_t value = __riscv_ztt_mls_rm_i128_rod_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rod_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_1x16_t value = __riscv_ztt_mls_cm_i128_rod_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rod_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_1x16_t value = __riscv_ztt_mls_st_i128_rod_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rod_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_1x16_t value = __riscv_ztt_mls_tst_i128_rod_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rod_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_16x1_t value = __riscv_ztt_mls_rm_i128_rod_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rod_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_16x1_t value = __riscv_ztt_mls_cm_i128_rod_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rod_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_16x1_t value = __riscv_ztt_mls_st_i128_rod_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rod_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_16x1_t value = __riscv_ztt_mls_tst_i128_rod_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rnu_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_1x1_t value = __riscv_ztt_mls_rm_u128_rnu_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rnu_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_1x1_t value = __riscv_ztt_mls_cm_u128_rnu_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rnu_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_1x1_t value = __riscv_ztt_mls_st_u128_rnu_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rnu_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_1x1_t value = __riscv_ztt_mls_tst_u128_rnu_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rnu_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_1x2_t value = __riscv_ztt_mls_rm_u128_rnu_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rnu_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_1x2_t value = __riscv_ztt_mls_cm_u128_rnu_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rnu_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_1x2_t value = __riscv_ztt_mls_st_u128_rnu_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rnu_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_1x2_t value = __riscv_ztt_mls_tst_u128_rnu_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rnu_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_2x1_t value = __riscv_ztt_mls_rm_u128_rnu_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rnu_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_2x1_t value = __riscv_ztt_mls_cm_u128_rnu_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rnu_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_2x1_t value = __riscv_ztt_mls_st_u128_rnu_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rnu_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_2x1_t value = __riscv_ztt_mls_tst_u128_rnu_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rnu_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_1x4_t value = __riscv_ztt_mls_rm_u128_rnu_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rnu_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_1x4_t value = __riscv_ztt_mls_cm_u128_rnu_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rnu_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_1x4_t value = __riscv_ztt_mls_st_u128_rnu_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rnu_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_1x4_t value = __riscv_ztt_mls_tst_u128_rnu_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rnu_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_4x1_t value = __riscv_ztt_mls_rm_u128_rnu_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rnu_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_4x1_t value = __riscv_ztt_mls_cm_u128_rnu_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rnu_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_4x1_t value = __riscv_ztt_mls_st_u128_rnu_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rnu_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_4x1_t value = __riscv_ztt_mls_tst_u128_rnu_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rnu_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_1x8_t value = __riscv_ztt_mls_rm_u128_rnu_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rnu_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_1x8_t value = __riscv_ztt_mls_cm_u128_rnu_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rnu_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_1x8_t value = __riscv_ztt_mls_st_u128_rnu_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rnu_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_1x8_t value = __riscv_ztt_mls_tst_u128_rnu_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rnu_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_8x1_t value = __riscv_ztt_mls_rm_u128_rnu_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rnu_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_8x1_t value = __riscv_ztt_mls_cm_u128_rnu_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rnu_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_8x1_t value = __riscv_ztt_mls_st_u128_rnu_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rnu_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_8x1_t value = __riscv_ztt_mls_tst_u128_rnu_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rnu_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_1x16_t value = __riscv_ztt_mls_rm_u128_rnu_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rnu_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_1x16_t value = __riscv_ztt_mls_cm_u128_rnu_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rnu_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_1x16_t value = __riscv_ztt_mls_st_u128_rnu_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rnu_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_1x16_t value = __riscv_ztt_mls_tst_u128_rnu_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rnu_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_16x1_t value = __riscv_ztt_mls_rm_u128_rnu_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rnu_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_16x1_t value = __riscv_ztt_mls_cm_u128_rnu_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rnu_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_16x1_t value = __riscv_ztt_mls_st_u128_rnu_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rnu_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_16x1_t value = __riscv_ztt_mls_tst_u128_rnu_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rne_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_1x1_t value = __riscv_ztt_mls_rm_u128_rne_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rne_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_1x1_t value = __riscv_ztt_mls_cm_u128_rne_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rne_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_1x1_t value = __riscv_ztt_mls_st_u128_rne_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rne_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_1x1_t value = __riscv_ztt_mls_tst_u128_rne_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rne_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_1x2_t value = __riscv_ztt_mls_rm_u128_rne_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rne_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_1x2_t value = __riscv_ztt_mls_cm_u128_rne_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rne_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_1x2_t value = __riscv_ztt_mls_st_u128_rne_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rne_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_1x2_t value = __riscv_ztt_mls_tst_u128_rne_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rne_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_2x1_t value = __riscv_ztt_mls_rm_u128_rne_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rne_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_2x1_t value = __riscv_ztt_mls_cm_u128_rne_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rne_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_2x1_t value = __riscv_ztt_mls_st_u128_rne_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rne_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_2x1_t value = __riscv_ztt_mls_tst_u128_rne_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rne_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_1x4_t value = __riscv_ztt_mls_rm_u128_rne_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rne_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_1x4_t value = __riscv_ztt_mls_cm_u128_rne_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rne_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_1x4_t value = __riscv_ztt_mls_st_u128_rne_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rne_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_1x4_t value = __riscv_ztt_mls_tst_u128_rne_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rne_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_4x1_t value = __riscv_ztt_mls_rm_u128_rne_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rne_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_4x1_t value = __riscv_ztt_mls_cm_u128_rne_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rne_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_4x1_t value = __riscv_ztt_mls_st_u128_rne_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rne_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_4x1_t value = __riscv_ztt_mls_tst_u128_rne_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rne_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_1x8_t value = __riscv_ztt_mls_rm_u128_rne_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rne_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_1x8_t value = __riscv_ztt_mls_cm_u128_rne_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rne_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_1x8_t value = __riscv_ztt_mls_st_u128_rne_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rne_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_1x8_t value = __riscv_ztt_mls_tst_u128_rne_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rne_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_8x1_t value = __riscv_ztt_mls_rm_u128_rne_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rne_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_8x1_t value = __riscv_ztt_mls_cm_u128_rne_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rne_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_8x1_t value = __riscv_ztt_mls_st_u128_rne_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rne_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_8x1_t value = __riscv_ztt_mls_tst_u128_rne_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rne_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_1x16_t value = __riscv_ztt_mls_rm_u128_rne_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rne_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_1x16_t value = __riscv_ztt_mls_cm_u128_rne_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rne_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_1x16_t value = __riscv_ztt_mls_st_u128_rne_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rne_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_1x16_t value = __riscv_ztt_mls_tst_u128_rne_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rne_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_16x1_t value = __riscv_ztt_mls_rm_u128_rne_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rne_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_16x1_t value = __riscv_ztt_mls_cm_u128_rne_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rne_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_16x1_t value = __riscv_ztt_mls_st_u128_rne_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rne_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_16x1_t value = __riscv_ztt_mls_tst_u128_rne_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rdn_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_1x1_t value = __riscv_ztt_mls_rm_u128_rdn_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rdn_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_1x1_t value = __riscv_ztt_mls_cm_u128_rdn_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rdn_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_1x1_t value = __riscv_ztt_mls_st_u128_rdn_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rdn_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_1x1_t value = __riscv_ztt_mls_tst_u128_rdn_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rdn_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_1x2_t value = __riscv_ztt_mls_rm_u128_rdn_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rdn_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_1x2_t value = __riscv_ztt_mls_cm_u128_rdn_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rdn_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_1x2_t value = __riscv_ztt_mls_st_u128_rdn_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rdn_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_1x2_t value = __riscv_ztt_mls_tst_u128_rdn_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rdn_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_2x1_t value = __riscv_ztt_mls_rm_u128_rdn_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rdn_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_2x1_t value = __riscv_ztt_mls_cm_u128_rdn_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rdn_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_2x1_t value = __riscv_ztt_mls_st_u128_rdn_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rdn_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_2x1_t value = __riscv_ztt_mls_tst_u128_rdn_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rdn_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_1x4_t value = __riscv_ztt_mls_rm_u128_rdn_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rdn_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_1x4_t value = __riscv_ztt_mls_cm_u128_rdn_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rdn_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_1x4_t value = __riscv_ztt_mls_st_u128_rdn_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rdn_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_1x4_t value = __riscv_ztt_mls_tst_u128_rdn_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rdn_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_4x1_t value = __riscv_ztt_mls_rm_u128_rdn_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rdn_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_4x1_t value = __riscv_ztt_mls_cm_u128_rdn_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rdn_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_4x1_t value = __riscv_ztt_mls_st_u128_rdn_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rdn_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_4x1_t value = __riscv_ztt_mls_tst_u128_rdn_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rdn_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_1x8_t value = __riscv_ztt_mls_rm_u128_rdn_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rdn_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_1x8_t value = __riscv_ztt_mls_cm_u128_rdn_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rdn_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_1x8_t value = __riscv_ztt_mls_st_u128_rdn_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rdn_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_1x8_t value = __riscv_ztt_mls_tst_u128_rdn_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rdn_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_8x1_t value = __riscv_ztt_mls_rm_u128_rdn_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rdn_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_8x1_t value = __riscv_ztt_mls_cm_u128_rdn_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rdn_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_8x1_t value = __riscv_ztt_mls_st_u128_rdn_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rdn_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_8x1_t value = __riscv_ztt_mls_tst_u128_rdn_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rdn_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_1x16_t value = __riscv_ztt_mls_rm_u128_rdn_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rdn_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_1x16_t value = __riscv_ztt_mls_cm_u128_rdn_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rdn_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_1x16_t value = __riscv_ztt_mls_st_u128_rdn_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rdn_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_1x16_t value = __riscv_ztt_mls_tst_u128_rdn_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rdn_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_16x1_t value = __riscv_ztt_mls_rm_u128_rdn_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rdn_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_16x1_t value = __riscv_ztt_mls_cm_u128_rdn_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rdn_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_16x1_t value = __riscv_ztt_mls_st_u128_rdn_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rdn_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_16x1_t value = __riscv_ztt_mls_tst_u128_rdn_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rod_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_1x1_t value = __riscv_ztt_mls_rm_u128_rod_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rod_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_1x1_t value = __riscv_ztt_mls_cm_u128_rod_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rod_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_1x1_t value = __riscv_ztt_mls_st_u128_rod_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rod_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_1x1_t value = __riscv_ztt_mls_tst_u128_rod_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rod_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_1x2_t value = __riscv_ztt_mls_rm_u128_rod_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rod_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_1x2_t value = __riscv_ztt_mls_cm_u128_rod_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rod_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_1x2_t value = __riscv_ztt_mls_st_u128_rod_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rod_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_1x2_t value = __riscv_ztt_mls_tst_u128_rod_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rod_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_2x1_t value = __riscv_ztt_mls_rm_u128_rod_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rod_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_2x1_t value = __riscv_ztt_mls_cm_u128_rod_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rod_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_2x1_t value = __riscv_ztt_mls_st_u128_rod_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rod_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_2x1_t value = __riscv_ztt_mls_tst_u128_rod_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rod_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_1x4_t value = __riscv_ztt_mls_rm_u128_rod_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rod_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_1x4_t value = __riscv_ztt_mls_cm_u128_rod_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rod_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_1x4_t value = __riscv_ztt_mls_st_u128_rod_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rod_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_1x4_t value = __riscv_ztt_mls_tst_u128_rod_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rod_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_4x1_t value = __riscv_ztt_mls_rm_u128_rod_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rod_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_4x1_t value = __riscv_ztt_mls_cm_u128_rod_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rod_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_4x1_t value = __riscv_ztt_mls_st_u128_rod_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rod_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_4x1_t value = __riscv_ztt_mls_tst_u128_rod_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rod_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_1x8_t value = __riscv_ztt_mls_rm_u128_rod_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rod_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_1x8_t value = __riscv_ztt_mls_cm_u128_rod_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rod_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_1x8_t value = __riscv_ztt_mls_st_u128_rod_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rod_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_1x8_t value = __riscv_ztt_mls_tst_u128_rod_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rod_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_8x1_t value = __riscv_ztt_mls_rm_u128_rod_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rod_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_8x1_t value = __riscv_ztt_mls_cm_u128_rod_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rod_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_8x1_t value = __riscv_ztt_mls_st_u128_rod_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rod_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_8x1_t value = __riscv_ztt_mls_tst_u128_rod_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rod_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_1x16_t value = __riscv_ztt_mls_rm_u128_rod_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rod_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_1x16_t value = __riscv_ztt_mls_cm_u128_rod_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rod_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_1x16_t value = __riscv_ztt_mls_st_u128_rod_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rod_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_1x16_t value = __riscv_ztt_mls_tst_u128_rod_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rod_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_16x1_t value = __riscv_ztt_mls_rm_u128_rod_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rod_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_16x1_t value = __riscv_ztt_mls_cm_u128_rod_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rod_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_16x1_t value = __riscv_ztt_mls_st_u128_rod_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rod_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_16x1_t value = __riscv_ztt_mls_tst_u128_rod_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rnu_sat_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_1x1_t value = __riscv_ztt_mls_rm_i128_rnu_sat_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rnu_sat_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_1x1_t value = __riscv_ztt_mls_cm_i128_rnu_sat_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rnu_sat_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_1x1_t value = __riscv_ztt_mls_st_i128_rnu_sat_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rnu_sat_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_1x1_t value = __riscv_ztt_mls_tst_i128_rnu_sat_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rnu_sat_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_1x2_t value = __riscv_ztt_mls_rm_i128_rnu_sat_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rnu_sat_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_1x2_t value = __riscv_ztt_mls_cm_i128_rnu_sat_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rnu_sat_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_1x2_t value = __riscv_ztt_mls_st_i128_rnu_sat_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rnu_sat_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_1x2_t value = __riscv_ztt_mls_tst_i128_rnu_sat_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rnu_sat_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_2x1_t value = __riscv_ztt_mls_rm_i128_rnu_sat_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rnu_sat_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_2x1_t value = __riscv_ztt_mls_cm_i128_rnu_sat_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rnu_sat_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_2x1_t value = __riscv_ztt_mls_st_i128_rnu_sat_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rnu_sat_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_2x1_t value = __riscv_ztt_mls_tst_i128_rnu_sat_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rnu_sat_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_1x4_t value = __riscv_ztt_mls_rm_i128_rnu_sat_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rnu_sat_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_1x4_t value = __riscv_ztt_mls_cm_i128_rnu_sat_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rnu_sat_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_1x4_t value = __riscv_ztt_mls_st_i128_rnu_sat_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rnu_sat_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_1x4_t value = __riscv_ztt_mls_tst_i128_rnu_sat_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rnu_sat_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_4x1_t value = __riscv_ztt_mls_rm_i128_rnu_sat_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rnu_sat_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_4x1_t value = __riscv_ztt_mls_cm_i128_rnu_sat_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rnu_sat_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_4x1_t value = __riscv_ztt_mls_st_i128_rnu_sat_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rnu_sat_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_4x1_t value = __riscv_ztt_mls_tst_i128_rnu_sat_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rnu_sat_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_1x8_t value = __riscv_ztt_mls_rm_i128_rnu_sat_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rnu_sat_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_1x8_t value = __riscv_ztt_mls_cm_i128_rnu_sat_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rnu_sat_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_1x8_t value = __riscv_ztt_mls_st_i128_rnu_sat_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rnu_sat_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_1x8_t value = __riscv_ztt_mls_tst_i128_rnu_sat_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rnu_sat_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_8x1_t value = __riscv_ztt_mls_rm_i128_rnu_sat_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rnu_sat_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_8x1_t value = __riscv_ztt_mls_cm_i128_rnu_sat_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rnu_sat_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_8x1_t value = __riscv_ztt_mls_st_i128_rnu_sat_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rnu_sat_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_8x1_t value = __riscv_ztt_mls_tst_i128_rnu_sat_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rnu_sat_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_1x16_t value = __riscv_ztt_mls_rm_i128_rnu_sat_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rnu_sat_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_1x16_t value = __riscv_ztt_mls_cm_i128_rnu_sat_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rnu_sat_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_1x16_t value = __riscv_ztt_mls_st_i128_rnu_sat_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rnu_sat_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_1x16_t value = __riscv_ztt_mls_tst_i128_rnu_sat_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rnu_sat_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_16x1_t value = __riscv_ztt_mls_rm_i128_rnu_sat_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rnu_sat_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_16x1_t value = __riscv_ztt_mls_cm_i128_rnu_sat_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rnu_sat_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_16x1_t value = __riscv_ztt_mls_st_i128_rnu_sat_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rnu_sat_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rnu_sat_16x1_t value = __riscv_ztt_mls_tst_i128_rnu_sat_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rne_sat_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_1x1_t value = __riscv_ztt_mls_rm_i128_rne_sat_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rne_sat_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_1x1_t value = __riscv_ztt_mls_cm_i128_rne_sat_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rne_sat_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_1x1_t value = __riscv_ztt_mls_st_i128_rne_sat_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rne_sat_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_1x1_t value = __riscv_ztt_mls_tst_i128_rne_sat_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rne_sat_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_1x2_t value = __riscv_ztt_mls_rm_i128_rne_sat_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rne_sat_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_1x2_t value = __riscv_ztt_mls_cm_i128_rne_sat_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rne_sat_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_1x2_t value = __riscv_ztt_mls_st_i128_rne_sat_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rne_sat_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_1x2_t value = __riscv_ztt_mls_tst_i128_rne_sat_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rne_sat_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_2x1_t value = __riscv_ztt_mls_rm_i128_rne_sat_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rne_sat_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_2x1_t value = __riscv_ztt_mls_cm_i128_rne_sat_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rne_sat_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_2x1_t value = __riscv_ztt_mls_st_i128_rne_sat_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rne_sat_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_2x1_t value = __riscv_ztt_mls_tst_i128_rne_sat_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rne_sat_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_1x4_t value = __riscv_ztt_mls_rm_i128_rne_sat_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rne_sat_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_1x4_t value = __riscv_ztt_mls_cm_i128_rne_sat_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rne_sat_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_1x4_t value = __riscv_ztt_mls_st_i128_rne_sat_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rne_sat_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_1x4_t value = __riscv_ztt_mls_tst_i128_rne_sat_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rne_sat_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_4x1_t value = __riscv_ztt_mls_rm_i128_rne_sat_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rne_sat_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_4x1_t value = __riscv_ztt_mls_cm_i128_rne_sat_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rne_sat_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_4x1_t value = __riscv_ztt_mls_st_i128_rne_sat_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rne_sat_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_4x1_t value = __riscv_ztt_mls_tst_i128_rne_sat_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rne_sat_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_1x8_t value = __riscv_ztt_mls_rm_i128_rne_sat_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rne_sat_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_1x8_t value = __riscv_ztt_mls_cm_i128_rne_sat_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rne_sat_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_1x8_t value = __riscv_ztt_mls_st_i128_rne_sat_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rne_sat_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_1x8_t value = __riscv_ztt_mls_tst_i128_rne_sat_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rne_sat_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_8x1_t value = __riscv_ztt_mls_rm_i128_rne_sat_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rne_sat_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_8x1_t value = __riscv_ztt_mls_cm_i128_rne_sat_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rne_sat_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_8x1_t value = __riscv_ztt_mls_st_i128_rne_sat_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rne_sat_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_8x1_t value = __riscv_ztt_mls_tst_i128_rne_sat_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rne_sat_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_1x16_t value = __riscv_ztt_mls_rm_i128_rne_sat_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rne_sat_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_1x16_t value = __riscv_ztt_mls_cm_i128_rne_sat_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rne_sat_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_1x16_t value = __riscv_ztt_mls_st_i128_rne_sat_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rne_sat_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_1x16_t value = __riscv_ztt_mls_tst_i128_rne_sat_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rne_sat_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_16x1_t value = __riscv_ztt_mls_rm_i128_rne_sat_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rne_sat_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_16x1_t value = __riscv_ztt_mls_cm_i128_rne_sat_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rne_sat_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_16x1_t value = __riscv_ztt_mls_st_i128_rne_sat_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rne_sat_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rne_sat_16x1_t value = __riscv_ztt_mls_tst_i128_rne_sat_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rdn_sat_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_1x1_t value = __riscv_ztt_mls_rm_i128_rdn_sat_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rdn_sat_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_1x1_t value = __riscv_ztt_mls_cm_i128_rdn_sat_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rdn_sat_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_1x1_t value = __riscv_ztt_mls_st_i128_rdn_sat_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rdn_sat_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_1x1_t value = __riscv_ztt_mls_tst_i128_rdn_sat_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rdn_sat_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_1x2_t value = __riscv_ztt_mls_rm_i128_rdn_sat_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rdn_sat_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_1x2_t value = __riscv_ztt_mls_cm_i128_rdn_sat_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rdn_sat_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_1x2_t value = __riscv_ztt_mls_st_i128_rdn_sat_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rdn_sat_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_1x2_t value = __riscv_ztt_mls_tst_i128_rdn_sat_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rdn_sat_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_2x1_t value = __riscv_ztt_mls_rm_i128_rdn_sat_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rdn_sat_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_2x1_t value = __riscv_ztt_mls_cm_i128_rdn_sat_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rdn_sat_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_2x1_t value = __riscv_ztt_mls_st_i128_rdn_sat_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rdn_sat_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_2x1_t value = __riscv_ztt_mls_tst_i128_rdn_sat_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rdn_sat_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_1x4_t value = __riscv_ztt_mls_rm_i128_rdn_sat_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rdn_sat_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_1x4_t value = __riscv_ztt_mls_cm_i128_rdn_sat_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rdn_sat_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_1x4_t value = __riscv_ztt_mls_st_i128_rdn_sat_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rdn_sat_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_1x4_t value = __riscv_ztt_mls_tst_i128_rdn_sat_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rdn_sat_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_4x1_t value = __riscv_ztt_mls_rm_i128_rdn_sat_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rdn_sat_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_4x1_t value = __riscv_ztt_mls_cm_i128_rdn_sat_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rdn_sat_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_4x1_t value = __riscv_ztt_mls_st_i128_rdn_sat_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rdn_sat_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_4x1_t value = __riscv_ztt_mls_tst_i128_rdn_sat_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rdn_sat_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_1x8_t value = __riscv_ztt_mls_rm_i128_rdn_sat_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rdn_sat_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_1x8_t value = __riscv_ztt_mls_cm_i128_rdn_sat_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rdn_sat_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_1x8_t value = __riscv_ztt_mls_st_i128_rdn_sat_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rdn_sat_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_1x8_t value = __riscv_ztt_mls_tst_i128_rdn_sat_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rdn_sat_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_8x1_t value = __riscv_ztt_mls_rm_i128_rdn_sat_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rdn_sat_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_8x1_t value = __riscv_ztt_mls_cm_i128_rdn_sat_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rdn_sat_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_8x1_t value = __riscv_ztt_mls_st_i128_rdn_sat_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rdn_sat_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_8x1_t value = __riscv_ztt_mls_tst_i128_rdn_sat_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rdn_sat_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_1x16_t value = __riscv_ztt_mls_rm_i128_rdn_sat_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rdn_sat_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_1x16_t value = __riscv_ztt_mls_cm_i128_rdn_sat_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rdn_sat_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_1x16_t value = __riscv_ztt_mls_st_i128_rdn_sat_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rdn_sat_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_1x16_t value = __riscv_ztt_mls_tst_i128_rdn_sat_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rdn_sat_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_16x1_t value = __riscv_ztt_mls_rm_i128_rdn_sat_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rdn_sat_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_16x1_t value = __riscv_ztt_mls_cm_i128_rdn_sat_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rdn_sat_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_16x1_t value = __riscv_ztt_mls_st_i128_rdn_sat_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rdn_sat_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rdn_sat_16x1_t value = __riscv_ztt_mls_tst_i128_rdn_sat_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rod_sat_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_1x1_t value = __riscv_ztt_mls_rm_i128_rod_sat_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rod_sat_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_1x1_t value = __riscv_ztt_mls_cm_i128_rod_sat_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rod_sat_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_1x1_t value = __riscv_ztt_mls_st_i128_rod_sat_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rod_sat_1x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_1x1_t value = __riscv_ztt_mls_tst_i128_rod_sat_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rod_sat_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_1x2_t value = __riscv_ztt_mls_rm_i128_rod_sat_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rod_sat_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_1x2_t value = __riscv_ztt_mls_cm_i128_rod_sat_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rod_sat_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_1x2_t value = __riscv_ztt_mls_st_i128_rod_sat_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rod_sat_1x2 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_1x2_t value = __riscv_ztt_mls_tst_i128_rod_sat_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rod_sat_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_2x1_t value = __riscv_ztt_mls_rm_i128_rod_sat_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rod_sat_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_2x1_t value = __riscv_ztt_mls_cm_i128_rod_sat_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rod_sat_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_2x1_t value = __riscv_ztt_mls_st_i128_rod_sat_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rod_sat_2x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_2x1_t value = __riscv_ztt_mls_tst_i128_rod_sat_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rod_sat_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_1x4_t value = __riscv_ztt_mls_rm_i128_rod_sat_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rod_sat_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_1x4_t value = __riscv_ztt_mls_cm_i128_rod_sat_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rod_sat_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_1x4_t value = __riscv_ztt_mls_st_i128_rod_sat_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rod_sat_1x4 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_1x4_t value = __riscv_ztt_mls_tst_i128_rod_sat_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rod_sat_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_4x1_t value = __riscv_ztt_mls_rm_i128_rod_sat_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rod_sat_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_4x1_t value = __riscv_ztt_mls_cm_i128_rod_sat_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rod_sat_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_4x1_t value = __riscv_ztt_mls_st_i128_rod_sat_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rod_sat_4x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_4x1_t value = __riscv_ztt_mls_tst_i128_rod_sat_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rod_sat_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_1x8_t value = __riscv_ztt_mls_rm_i128_rod_sat_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rod_sat_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_1x8_t value = __riscv_ztt_mls_cm_i128_rod_sat_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rod_sat_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_1x8_t value = __riscv_ztt_mls_st_i128_rod_sat_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rod_sat_1x8 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_1x8_t value = __riscv_ztt_mls_tst_i128_rod_sat_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rod_sat_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_8x1_t value = __riscv_ztt_mls_rm_i128_rod_sat_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rod_sat_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_8x1_t value = __riscv_ztt_mls_cm_i128_rod_sat_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rod_sat_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_8x1_t value = __riscv_ztt_mls_st_i128_rod_sat_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rod_sat_8x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_8x1_t value = __riscv_ztt_mls_tst_i128_rod_sat_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rod_sat_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_1x16_t value = __riscv_ztt_mls_rm_i128_rod_sat_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rod_sat_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_1x16_t value = __riscv_ztt_mls_cm_i128_rod_sat_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rod_sat_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_1x16_t value = __riscv_ztt_mls_st_i128_rod_sat_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rod_sat_1x16 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_1x16_t value = __riscv_ztt_mls_tst_i128_rod_sat_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_i128_rod_sat_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_16x1_t value = __riscv_ztt_mls_rm_i128_rod_sat_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_i128_rod_sat_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_16x1_t value = __riscv_ztt_mls_cm_i128_rod_sat_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_i128_rod_sat_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_16x1_t value = __riscv_ztt_mls_st_i128_rod_sat_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_i128_rod_sat_16x1 (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, size_t stride)
{
  __riscv_ztt_i128_rod_sat_16x1_t value = __riscv_ztt_mls_tst_i128_rod_sat_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rnu_sat_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_1x1_t value = __riscv_ztt_mls_rm_u128_rnu_sat_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rnu_sat_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_1x1_t value = __riscv_ztt_mls_cm_u128_rnu_sat_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rnu_sat_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_1x1_t value = __riscv_ztt_mls_st_u128_rnu_sat_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rnu_sat_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_1x1_t value = __riscv_ztt_mls_tst_u128_rnu_sat_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rnu_sat_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_1x2_t value = __riscv_ztt_mls_rm_u128_rnu_sat_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rnu_sat_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_1x2_t value = __riscv_ztt_mls_cm_u128_rnu_sat_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rnu_sat_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_1x2_t value = __riscv_ztt_mls_st_u128_rnu_sat_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rnu_sat_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_1x2_t value = __riscv_ztt_mls_tst_u128_rnu_sat_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rnu_sat_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_2x1_t value = __riscv_ztt_mls_rm_u128_rnu_sat_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rnu_sat_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_2x1_t value = __riscv_ztt_mls_cm_u128_rnu_sat_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rnu_sat_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_2x1_t value = __riscv_ztt_mls_st_u128_rnu_sat_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rnu_sat_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_2x1_t value = __riscv_ztt_mls_tst_u128_rnu_sat_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rnu_sat_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_1x4_t value = __riscv_ztt_mls_rm_u128_rnu_sat_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rnu_sat_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_1x4_t value = __riscv_ztt_mls_cm_u128_rnu_sat_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rnu_sat_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_1x4_t value = __riscv_ztt_mls_st_u128_rnu_sat_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rnu_sat_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_1x4_t value = __riscv_ztt_mls_tst_u128_rnu_sat_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rnu_sat_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_4x1_t value = __riscv_ztt_mls_rm_u128_rnu_sat_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rnu_sat_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_4x1_t value = __riscv_ztt_mls_cm_u128_rnu_sat_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rnu_sat_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_4x1_t value = __riscv_ztt_mls_st_u128_rnu_sat_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rnu_sat_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_4x1_t value = __riscv_ztt_mls_tst_u128_rnu_sat_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rnu_sat_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_1x8_t value = __riscv_ztt_mls_rm_u128_rnu_sat_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rnu_sat_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_1x8_t value = __riscv_ztt_mls_cm_u128_rnu_sat_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rnu_sat_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_1x8_t value = __riscv_ztt_mls_st_u128_rnu_sat_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rnu_sat_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_1x8_t value = __riscv_ztt_mls_tst_u128_rnu_sat_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rnu_sat_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_8x1_t value = __riscv_ztt_mls_rm_u128_rnu_sat_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rnu_sat_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_8x1_t value = __riscv_ztt_mls_cm_u128_rnu_sat_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rnu_sat_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_8x1_t value = __riscv_ztt_mls_st_u128_rnu_sat_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rnu_sat_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_8x1_t value = __riscv_ztt_mls_tst_u128_rnu_sat_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rnu_sat_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_1x16_t value = __riscv_ztt_mls_rm_u128_rnu_sat_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rnu_sat_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_1x16_t value = __riscv_ztt_mls_cm_u128_rnu_sat_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rnu_sat_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_1x16_t value = __riscv_ztt_mls_st_u128_rnu_sat_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rnu_sat_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_1x16_t value = __riscv_ztt_mls_tst_u128_rnu_sat_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rnu_sat_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_16x1_t value = __riscv_ztt_mls_rm_u128_rnu_sat_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rnu_sat_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_16x1_t value = __riscv_ztt_mls_cm_u128_rnu_sat_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rnu_sat_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_16x1_t value = __riscv_ztt_mls_st_u128_rnu_sat_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rnu_sat_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rnu_sat_16x1_t value = __riscv_ztt_mls_tst_u128_rnu_sat_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rne_sat_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_1x1_t value = __riscv_ztt_mls_rm_u128_rne_sat_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rne_sat_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_1x1_t value = __riscv_ztt_mls_cm_u128_rne_sat_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rne_sat_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_1x1_t value = __riscv_ztt_mls_st_u128_rne_sat_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rne_sat_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_1x1_t value = __riscv_ztt_mls_tst_u128_rne_sat_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rne_sat_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_1x2_t value = __riscv_ztt_mls_rm_u128_rne_sat_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rne_sat_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_1x2_t value = __riscv_ztt_mls_cm_u128_rne_sat_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rne_sat_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_1x2_t value = __riscv_ztt_mls_st_u128_rne_sat_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rne_sat_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_1x2_t value = __riscv_ztt_mls_tst_u128_rne_sat_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rne_sat_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_2x1_t value = __riscv_ztt_mls_rm_u128_rne_sat_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rne_sat_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_2x1_t value = __riscv_ztt_mls_cm_u128_rne_sat_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rne_sat_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_2x1_t value = __riscv_ztt_mls_st_u128_rne_sat_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rne_sat_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_2x1_t value = __riscv_ztt_mls_tst_u128_rne_sat_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rne_sat_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_1x4_t value = __riscv_ztt_mls_rm_u128_rne_sat_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rne_sat_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_1x4_t value = __riscv_ztt_mls_cm_u128_rne_sat_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rne_sat_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_1x4_t value = __riscv_ztt_mls_st_u128_rne_sat_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rne_sat_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_1x4_t value = __riscv_ztt_mls_tst_u128_rne_sat_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rne_sat_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_4x1_t value = __riscv_ztt_mls_rm_u128_rne_sat_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rne_sat_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_4x1_t value = __riscv_ztt_mls_cm_u128_rne_sat_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rne_sat_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_4x1_t value = __riscv_ztt_mls_st_u128_rne_sat_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rne_sat_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_4x1_t value = __riscv_ztt_mls_tst_u128_rne_sat_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rne_sat_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_1x8_t value = __riscv_ztt_mls_rm_u128_rne_sat_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rne_sat_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_1x8_t value = __riscv_ztt_mls_cm_u128_rne_sat_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rne_sat_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_1x8_t value = __riscv_ztt_mls_st_u128_rne_sat_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rne_sat_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_1x8_t value = __riscv_ztt_mls_tst_u128_rne_sat_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rne_sat_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_8x1_t value = __riscv_ztt_mls_rm_u128_rne_sat_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rne_sat_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_8x1_t value = __riscv_ztt_mls_cm_u128_rne_sat_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rne_sat_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_8x1_t value = __riscv_ztt_mls_st_u128_rne_sat_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rne_sat_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_8x1_t value = __riscv_ztt_mls_tst_u128_rne_sat_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rne_sat_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_1x16_t value = __riscv_ztt_mls_rm_u128_rne_sat_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rne_sat_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_1x16_t value = __riscv_ztt_mls_cm_u128_rne_sat_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rne_sat_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_1x16_t value = __riscv_ztt_mls_st_u128_rne_sat_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rne_sat_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_1x16_t value = __riscv_ztt_mls_tst_u128_rne_sat_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rne_sat_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_16x1_t value = __riscv_ztt_mls_rm_u128_rne_sat_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rne_sat_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_16x1_t value = __riscv_ztt_mls_cm_u128_rne_sat_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rne_sat_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_16x1_t value = __riscv_ztt_mls_st_u128_rne_sat_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rne_sat_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rne_sat_16x1_t value = __riscv_ztt_mls_tst_u128_rne_sat_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rdn_sat_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_1x1_t value = __riscv_ztt_mls_rm_u128_rdn_sat_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rdn_sat_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_1x1_t value = __riscv_ztt_mls_cm_u128_rdn_sat_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rdn_sat_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_1x1_t value = __riscv_ztt_mls_st_u128_rdn_sat_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rdn_sat_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_1x1_t value = __riscv_ztt_mls_tst_u128_rdn_sat_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rdn_sat_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_1x2_t value = __riscv_ztt_mls_rm_u128_rdn_sat_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rdn_sat_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_1x2_t value = __riscv_ztt_mls_cm_u128_rdn_sat_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rdn_sat_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_1x2_t value = __riscv_ztt_mls_st_u128_rdn_sat_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rdn_sat_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_1x2_t value = __riscv_ztt_mls_tst_u128_rdn_sat_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rdn_sat_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_2x1_t value = __riscv_ztt_mls_rm_u128_rdn_sat_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rdn_sat_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_2x1_t value = __riscv_ztt_mls_cm_u128_rdn_sat_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rdn_sat_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_2x1_t value = __riscv_ztt_mls_st_u128_rdn_sat_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rdn_sat_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_2x1_t value = __riscv_ztt_mls_tst_u128_rdn_sat_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rdn_sat_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_1x4_t value = __riscv_ztt_mls_rm_u128_rdn_sat_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rdn_sat_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_1x4_t value = __riscv_ztt_mls_cm_u128_rdn_sat_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rdn_sat_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_1x4_t value = __riscv_ztt_mls_st_u128_rdn_sat_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rdn_sat_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_1x4_t value = __riscv_ztt_mls_tst_u128_rdn_sat_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rdn_sat_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_4x1_t value = __riscv_ztt_mls_rm_u128_rdn_sat_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rdn_sat_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_4x1_t value = __riscv_ztt_mls_cm_u128_rdn_sat_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rdn_sat_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_4x1_t value = __riscv_ztt_mls_st_u128_rdn_sat_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rdn_sat_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_4x1_t value = __riscv_ztt_mls_tst_u128_rdn_sat_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rdn_sat_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_1x8_t value = __riscv_ztt_mls_rm_u128_rdn_sat_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rdn_sat_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_1x8_t value = __riscv_ztt_mls_cm_u128_rdn_sat_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rdn_sat_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_1x8_t value = __riscv_ztt_mls_st_u128_rdn_sat_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rdn_sat_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_1x8_t value = __riscv_ztt_mls_tst_u128_rdn_sat_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rdn_sat_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_8x1_t value = __riscv_ztt_mls_rm_u128_rdn_sat_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rdn_sat_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_8x1_t value = __riscv_ztt_mls_cm_u128_rdn_sat_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rdn_sat_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_8x1_t value = __riscv_ztt_mls_st_u128_rdn_sat_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rdn_sat_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_8x1_t value = __riscv_ztt_mls_tst_u128_rdn_sat_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rdn_sat_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_1x16_t value = __riscv_ztt_mls_rm_u128_rdn_sat_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rdn_sat_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_1x16_t value = __riscv_ztt_mls_cm_u128_rdn_sat_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rdn_sat_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_1x16_t value = __riscv_ztt_mls_st_u128_rdn_sat_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rdn_sat_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_1x16_t value = __riscv_ztt_mls_tst_u128_rdn_sat_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rdn_sat_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_16x1_t value = __riscv_ztt_mls_rm_u128_rdn_sat_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rdn_sat_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_16x1_t value = __riscv_ztt_mls_cm_u128_rdn_sat_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rdn_sat_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_16x1_t value = __riscv_ztt_mls_st_u128_rdn_sat_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rdn_sat_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rdn_sat_16x1_t value = __riscv_ztt_mls_tst_u128_rdn_sat_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rod_sat_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_1x1_t value = __riscv_ztt_mls_rm_u128_rod_sat_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rod_sat_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_1x1_t value = __riscv_ztt_mls_cm_u128_rod_sat_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rod_sat_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_1x1_t value = __riscv_ztt_mls_st_u128_rod_sat_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rod_sat_1x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_1x1_t value = __riscv_ztt_mls_tst_u128_rod_sat_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rod_sat_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_1x2_t value = __riscv_ztt_mls_rm_u128_rod_sat_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rod_sat_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_1x2_t value = __riscv_ztt_mls_cm_u128_rod_sat_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rod_sat_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_1x2_t value = __riscv_ztt_mls_st_u128_rod_sat_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rod_sat_1x2 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_1x2_t value = __riscv_ztt_mls_tst_u128_rod_sat_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rod_sat_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_2x1_t value = __riscv_ztt_mls_rm_u128_rod_sat_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rod_sat_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_2x1_t value = __riscv_ztt_mls_cm_u128_rod_sat_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rod_sat_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_2x1_t value = __riscv_ztt_mls_st_u128_rod_sat_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rod_sat_2x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_2x1_t value = __riscv_ztt_mls_tst_u128_rod_sat_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rod_sat_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_1x4_t value = __riscv_ztt_mls_rm_u128_rod_sat_1x4 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rod_sat_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_1x4_t value = __riscv_ztt_mls_cm_u128_rod_sat_1x4 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rod_sat_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_1x4_t value = __riscv_ztt_mls_st_u128_rod_sat_1x4 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rod_sat_1x4 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_1x4_t value = __riscv_ztt_mls_tst_u128_rod_sat_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rod_sat_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_4x1_t value = __riscv_ztt_mls_rm_u128_rod_sat_4x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rod_sat_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_4x1_t value = __riscv_ztt_mls_cm_u128_rod_sat_4x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rod_sat_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_4x1_t value = __riscv_ztt_mls_st_u128_rod_sat_4x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rod_sat_4x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_4x1_t value = __riscv_ztt_mls_tst_u128_rod_sat_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rod_sat_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_1x8_t value = __riscv_ztt_mls_rm_u128_rod_sat_1x8 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rod_sat_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_1x8_t value = __riscv_ztt_mls_cm_u128_rod_sat_1x8 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rod_sat_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_1x8_t value = __riscv_ztt_mls_st_u128_rod_sat_1x8 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rod_sat_1x8 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_1x8_t value = __riscv_ztt_mls_tst_u128_rod_sat_1x8 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rod_sat_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_8x1_t value = __riscv_ztt_mls_rm_u128_rod_sat_8x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rod_sat_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_8x1_t value = __riscv_ztt_mls_cm_u128_rod_sat_8x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rod_sat_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_8x1_t value = __riscv_ztt_mls_st_u128_rod_sat_8x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rod_sat_8x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_8x1_t value = __riscv_ztt_mls_tst_u128_rod_sat_8x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rod_sat_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_1x16_t value = __riscv_ztt_mls_rm_u128_rod_sat_1x16 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rod_sat_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_1x16_t value = __riscv_ztt_mls_cm_u128_rod_sat_1x16 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rod_sat_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_1x16_t value = __riscv_ztt_mls_st_u128_rod_sat_1x16 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rod_sat_1x16 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_1x16_t value = __riscv_ztt_mls_tst_u128_rod_sat_1x16 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
void mem128_rm_u128_rod_sat_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_16x1_t value = __riscv_ztt_mls_rm_u128_rod_sat_16x1 (in);
  __riscv_ztt_mss_rm (out, value);
}
void mem128_cm_u128_rod_sat_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_16x1_t value = __riscv_ztt_mls_cm_u128_rod_sat_16x1 (in);
  __riscv_ztt_mss_cm (out, value);
}
void mem128_st_u128_rod_sat_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_16x1_t value = __riscv_ztt_mls_st_u128_rod_sat_16x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}
void mem128_tst_u128_rod_sat_16x1 (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, size_t stride)
{
  __riscv_ztt_u128_rod_sat_16x1_t value = __riscv_ztt_mls_tst_u128_rod_sat_16x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
