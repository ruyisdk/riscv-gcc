/* Floating memory keeps full native elements on both XLENs.  */
/* { dg-do assemble } */
/* { dg-options "-O0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a16 " { target rv32 } } */
/* { dg-options "-O0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a16 " { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>
void mem_rm_f16_rne_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_1x1_t value = __riscv_ztt_mls_rm_f16_rne_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rne_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_1x1_t value = __riscv_ztt_mls_cm_f16_rne_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rne_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_1x1_t value = __riscv_ztt_mls_st_f16_rne_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rne_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_1x1_t value = __riscv_ztt_mls_tst_f16_rne_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rne_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_1x2_t value = __riscv_ztt_mls_rm_f16_rne_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rne_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_1x2_t value = __riscv_ztt_mls_cm_f16_rne_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rne_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_1x2_t value = __riscv_ztt_mls_st_f16_rne_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rne_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_1x2_t value = __riscv_ztt_mls_tst_f16_rne_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rne_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_2x1_t value = __riscv_ztt_mls_rm_f16_rne_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rne_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_2x1_t value = __riscv_ztt_mls_cm_f16_rne_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rne_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_2x1_t value = __riscv_ztt_mls_st_f16_rne_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rne_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rne_2x1_t value = __riscv_ztt_mls_tst_f16_rne_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rtz_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_1x1_t value = __riscv_ztt_mls_rm_f16_rtz_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rtz_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_1x1_t value = __riscv_ztt_mls_cm_f16_rtz_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rtz_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_1x1_t value = __riscv_ztt_mls_st_f16_rtz_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rtz_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_1x1_t value = __riscv_ztt_mls_tst_f16_rtz_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rtz_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_1x2_t value = __riscv_ztt_mls_rm_f16_rtz_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rtz_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_1x2_t value = __riscv_ztt_mls_cm_f16_rtz_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rtz_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_1x2_t value = __riscv_ztt_mls_st_f16_rtz_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rtz_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_1x2_t value = __riscv_ztt_mls_tst_f16_rtz_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rtz_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_2x1_t value = __riscv_ztt_mls_rm_f16_rtz_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rtz_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_2x1_t value = __riscv_ztt_mls_cm_f16_rtz_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rtz_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_2x1_t value = __riscv_ztt_mls_st_f16_rtz_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rtz_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rtz_2x1_t value = __riscv_ztt_mls_tst_f16_rtz_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rdn_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_1x1_t value = __riscv_ztt_mls_rm_f16_rdn_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rdn_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_1x1_t value = __riscv_ztt_mls_cm_f16_rdn_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rdn_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_1x1_t value = __riscv_ztt_mls_st_f16_rdn_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rdn_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_1x1_t value = __riscv_ztt_mls_tst_f16_rdn_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rdn_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_1x2_t value = __riscv_ztt_mls_rm_f16_rdn_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rdn_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_1x2_t value = __riscv_ztt_mls_cm_f16_rdn_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rdn_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_1x2_t value = __riscv_ztt_mls_st_f16_rdn_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rdn_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_1x2_t value = __riscv_ztt_mls_tst_f16_rdn_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rdn_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_2x1_t value = __riscv_ztt_mls_rm_f16_rdn_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rdn_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_2x1_t value = __riscv_ztt_mls_cm_f16_rdn_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rdn_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_2x1_t value = __riscv_ztt_mls_st_f16_rdn_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rdn_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rdn_2x1_t value = __riscv_ztt_mls_tst_f16_rdn_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rup_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_1x1_t value = __riscv_ztt_mls_rm_f16_rup_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rup_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_1x1_t value = __riscv_ztt_mls_cm_f16_rup_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rup_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_1x1_t value = __riscv_ztt_mls_st_f16_rup_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rup_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_1x1_t value = __riscv_ztt_mls_tst_f16_rup_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rup_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_1x2_t value = __riscv_ztt_mls_rm_f16_rup_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rup_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_1x2_t value = __riscv_ztt_mls_cm_f16_rup_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rup_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_1x2_t value = __riscv_ztt_mls_st_f16_rup_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rup_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_1x2_t value = __riscv_ztt_mls_tst_f16_rup_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rup_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_2x1_t value = __riscv_ztt_mls_rm_f16_rup_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rup_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_2x1_t value = __riscv_ztt_mls_cm_f16_rup_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rup_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_2x1_t value = __riscv_ztt_mls_st_f16_rup_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rup_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rup_2x1_t value = __riscv_ztt_mls_tst_f16_rup_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rmm_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_1x1_t value = __riscv_ztt_mls_rm_f16_rmm_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rmm_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_1x1_t value = __riscv_ztt_mls_cm_f16_rmm_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rmm_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_1x1_t value = __riscv_ztt_mls_st_f16_rmm_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rmm_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_1x1_t value = __riscv_ztt_mls_tst_f16_rmm_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rmm_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_1x2_t value = __riscv_ztt_mls_rm_f16_rmm_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rmm_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_1x2_t value = __riscv_ztt_mls_cm_f16_rmm_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rmm_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_1x2_t value = __riscv_ztt_mls_st_f16_rmm_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rmm_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_1x2_t value = __riscv_ztt_mls_tst_f16_rmm_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rmm_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_2x1_t value = __riscv_ztt_mls_rm_f16_rmm_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rmm_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_2x1_t value = __riscv_ztt_mls_cm_f16_rmm_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rmm_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_2x1_t value = __riscv_ztt_mls_st_f16_rmm_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rmm_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rmm_2x1_t value = __riscv_ztt_mls_tst_f16_rmm_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rno_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_1x1_t value = __riscv_ztt_mls_rm_f16_rno_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rno_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_1x1_t value = __riscv_ztt_mls_cm_f16_rno_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rno_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_1x1_t value = __riscv_ztt_mls_st_f16_rno_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rno_1x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_1x1_t value = __riscv_ztt_mls_tst_f16_rno_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rno_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_1x2_t value = __riscv_ztt_mls_rm_f16_rno_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rno_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_1x2_t value = __riscv_ztt_mls_cm_f16_rno_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rno_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_1x2_t value = __riscv_ztt_mls_st_f16_rno_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rno_1x2 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_1x2_t value = __riscv_ztt_mls_tst_f16_rno_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f16_rno_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_2x1_t value = __riscv_ztt_mls_rm_f16_rno_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f16_rno_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_2x1_t value = __riscv_ztt_mls_cm_f16_rno_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f16_rno_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_2x1_t value = __riscv_ztt_mls_st_f16_rno_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f16_rno_2x1 (_Float16 *out, const _Float16 *in, size_t stride)
{
  __riscv_ztt_f16_rno_2x1_t value = __riscv_ztt_mls_tst_f16_rno_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rne_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_1x1_t value = __riscv_ztt_mls_rm_bf16_rne_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rne_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_1x1_t value = __riscv_ztt_mls_cm_bf16_rne_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rne_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_1x1_t value = __riscv_ztt_mls_st_bf16_rne_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rne_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_1x1_t value = __riscv_ztt_mls_tst_bf16_rne_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rne_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_1x2_t value = __riscv_ztt_mls_rm_bf16_rne_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rne_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_1x2_t value = __riscv_ztt_mls_cm_bf16_rne_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rne_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_1x2_t value = __riscv_ztt_mls_st_bf16_rne_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rne_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_1x2_t value = __riscv_ztt_mls_tst_bf16_rne_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rne_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_2x1_t value = __riscv_ztt_mls_rm_bf16_rne_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rne_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_2x1_t value = __riscv_ztt_mls_cm_bf16_rne_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rne_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_2x1_t value = __riscv_ztt_mls_st_bf16_rne_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rne_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rne_2x1_t value = __riscv_ztt_mls_tst_bf16_rne_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rtz_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_1x1_t value = __riscv_ztt_mls_rm_bf16_rtz_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rtz_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_1x1_t value = __riscv_ztt_mls_cm_bf16_rtz_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rtz_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_1x1_t value = __riscv_ztt_mls_st_bf16_rtz_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rtz_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_1x1_t value = __riscv_ztt_mls_tst_bf16_rtz_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rtz_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_1x2_t value = __riscv_ztt_mls_rm_bf16_rtz_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rtz_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_1x2_t value = __riscv_ztt_mls_cm_bf16_rtz_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rtz_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_1x2_t value = __riscv_ztt_mls_st_bf16_rtz_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rtz_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_1x2_t value = __riscv_ztt_mls_tst_bf16_rtz_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rtz_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_2x1_t value = __riscv_ztt_mls_rm_bf16_rtz_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rtz_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_2x1_t value = __riscv_ztt_mls_cm_bf16_rtz_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rtz_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_2x1_t value = __riscv_ztt_mls_st_bf16_rtz_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rtz_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rtz_2x1_t value = __riscv_ztt_mls_tst_bf16_rtz_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rdn_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_1x1_t value = __riscv_ztt_mls_rm_bf16_rdn_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rdn_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_1x1_t value = __riscv_ztt_mls_cm_bf16_rdn_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rdn_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_1x1_t value = __riscv_ztt_mls_st_bf16_rdn_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rdn_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_1x1_t value = __riscv_ztt_mls_tst_bf16_rdn_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rdn_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_1x2_t value = __riscv_ztt_mls_rm_bf16_rdn_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rdn_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_1x2_t value = __riscv_ztt_mls_cm_bf16_rdn_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rdn_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_1x2_t value = __riscv_ztt_mls_st_bf16_rdn_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rdn_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_1x2_t value = __riscv_ztt_mls_tst_bf16_rdn_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rdn_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_2x1_t value = __riscv_ztt_mls_rm_bf16_rdn_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rdn_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_2x1_t value = __riscv_ztt_mls_cm_bf16_rdn_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rdn_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_2x1_t value = __riscv_ztt_mls_st_bf16_rdn_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rdn_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rdn_2x1_t value = __riscv_ztt_mls_tst_bf16_rdn_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rup_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_1x1_t value = __riscv_ztt_mls_rm_bf16_rup_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rup_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_1x1_t value = __riscv_ztt_mls_cm_bf16_rup_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rup_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_1x1_t value = __riscv_ztt_mls_st_bf16_rup_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rup_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_1x1_t value = __riscv_ztt_mls_tst_bf16_rup_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rup_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_1x2_t value = __riscv_ztt_mls_rm_bf16_rup_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rup_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_1x2_t value = __riscv_ztt_mls_cm_bf16_rup_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rup_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_1x2_t value = __riscv_ztt_mls_st_bf16_rup_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rup_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_1x2_t value = __riscv_ztt_mls_tst_bf16_rup_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rup_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_2x1_t value = __riscv_ztt_mls_rm_bf16_rup_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rup_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_2x1_t value = __riscv_ztt_mls_cm_bf16_rup_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rup_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_2x1_t value = __riscv_ztt_mls_st_bf16_rup_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rup_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rup_2x1_t value = __riscv_ztt_mls_tst_bf16_rup_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rmm_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_1x1_t value = __riscv_ztt_mls_rm_bf16_rmm_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rmm_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_1x1_t value = __riscv_ztt_mls_cm_bf16_rmm_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rmm_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_1x1_t value = __riscv_ztt_mls_st_bf16_rmm_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rmm_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_1x1_t value = __riscv_ztt_mls_tst_bf16_rmm_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rmm_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_1x2_t value = __riscv_ztt_mls_rm_bf16_rmm_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rmm_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_1x2_t value = __riscv_ztt_mls_cm_bf16_rmm_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rmm_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_1x2_t value = __riscv_ztt_mls_st_bf16_rmm_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rmm_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_1x2_t value = __riscv_ztt_mls_tst_bf16_rmm_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rmm_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_2x1_t value = __riscv_ztt_mls_rm_bf16_rmm_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rmm_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_2x1_t value = __riscv_ztt_mls_cm_bf16_rmm_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rmm_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_2x1_t value = __riscv_ztt_mls_st_bf16_rmm_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rmm_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rmm_2x1_t value = __riscv_ztt_mls_tst_bf16_rmm_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rno_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_1x1_t value = __riscv_ztt_mls_rm_bf16_rno_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rno_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_1x1_t value = __riscv_ztt_mls_cm_bf16_rno_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rno_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_1x1_t value = __riscv_ztt_mls_st_bf16_rno_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rno_1x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_1x1_t value = __riscv_ztt_mls_tst_bf16_rno_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rno_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_1x2_t value = __riscv_ztt_mls_rm_bf16_rno_1x2 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rno_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_1x2_t value = __riscv_ztt_mls_cm_bf16_rno_1x2 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rno_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_1x2_t value = __riscv_ztt_mls_st_bf16_rno_1x2 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rno_1x2 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_1x2_t value = __riscv_ztt_mls_tst_bf16_rno_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_bf16_rno_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_2x1_t value = __riscv_ztt_mls_rm_bf16_rno_2x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_bf16_rno_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_2x1_t value = __riscv_ztt_mls_cm_bf16_rno_2x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_bf16_rno_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_2x1_t value = __riscv_ztt_mls_st_bf16_rno_2x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_bf16_rno_2x1 (__bf16 *out, const __bf16 *in, size_t stride)
{
  __riscv_ztt_bf16_rno_2x1_t value = __riscv_ztt_mls_tst_bf16_rno_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rne_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_1x1_t value = __riscv_ztt_mls_rm_f32_rne_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rne_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_1x1_t value = __riscv_ztt_mls_cm_f32_rne_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rne_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_1x1_t value = __riscv_ztt_mls_st_f32_rne_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rne_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rne_1x1_t value = __riscv_ztt_mls_tst_f32_rne_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rtz_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_1x1_t value = __riscv_ztt_mls_rm_f32_rtz_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rtz_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_1x1_t value = __riscv_ztt_mls_cm_f32_rtz_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rtz_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_1x1_t value = __riscv_ztt_mls_st_f32_rtz_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rtz_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rtz_1x1_t value = __riscv_ztt_mls_tst_f32_rtz_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rdn_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_1x1_t value = __riscv_ztt_mls_rm_f32_rdn_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rdn_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_1x1_t value = __riscv_ztt_mls_cm_f32_rdn_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rdn_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_1x1_t value = __riscv_ztt_mls_st_f32_rdn_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rdn_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rdn_1x1_t value = __riscv_ztt_mls_tst_f32_rdn_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rup_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_1x1_t value = __riscv_ztt_mls_rm_f32_rup_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rup_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_1x1_t value = __riscv_ztt_mls_cm_f32_rup_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rup_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_1x1_t value = __riscv_ztt_mls_st_f32_rup_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rup_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rup_1x1_t value = __riscv_ztt_mls_tst_f32_rup_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rmm_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_1x1_t value = __riscv_ztt_mls_rm_f32_rmm_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rmm_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_1x1_t value = __riscv_ztt_mls_cm_f32_rmm_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rmm_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_1x1_t value = __riscv_ztt_mls_st_f32_rmm_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rmm_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rmm_1x1_t value = __riscv_ztt_mls_tst_f32_rmm_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void mem_rm_f32_rno_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_1x1_t value = __riscv_ztt_mls_rm_f32_rno_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void mem_cm_f32_rno_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_1x1_t value = __riscv_ztt_mls_cm_f32_rno_1x1 (in);
  __riscv_ztt_mss_cm (out, value);
}

void mem_st_f32_rno_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_1x1_t value = __riscv_ztt_mls_st_f32_rno_1x1 (in, stride);
  __riscv_ztt_mss_st (out, stride, value);
}

void mem_tst_f32_rno_1x1 (float *out, const float *in, size_t stride)
{
  __riscv_ztt_f32_rno_1x1_t value = __riscv_ztt_mls_tst_f32_rno_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
