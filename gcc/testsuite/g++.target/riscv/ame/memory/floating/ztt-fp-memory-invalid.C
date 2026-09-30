/* Floating memory keeps full native elements on both XLENs.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16 " { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16 " { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>
void invalid (const float *cf, volatile float *vf,
              float *f, double *d, uint32_t *u, _Float16 *h, __bf16 *b)
{
  __riscv_ztt_f32_1x1_t a = __riscv_ztt_mzero_m_f32_1x1 ();
  __riscv_ztt_bf16_1x1_t bf = __riscv_ztt_mzero_m_bf16_1x1 ();
  __riscv_ztt_mls_rm_f32_1x1 (u); /* { dg-error "requires a pointer to" } */
  __riscv_ztt_mls_cm_f64_1x1 (f); /* { dg-error "requires a pointer to" } */
  __riscv_ztt_mls_st_f16_1x1 (b, 2); /* { dg-error "requires a pointer to" } */
  __riscv_ztt_mls_tst_bf16_1x1 (h, 2); /* { dg-error "requires a pointer to" } */
  __riscv_ztt_mss_rm (cf, a); /* { dg-error "requires a pointer to writable" } */
  __riscv_ztt_mss_cm (d, a); /* { dg-error "requires a pointer to writable" } */
  __riscv_ztt_mss_st (h, 2, bf); /* { dg-error "requires a pointer to writable" } */
  __riscv_ztt_mss_tst (u, 4, a); /* { dg-error "requires a pointer to writable" } */
  __riscv_ztt_mls_rm_f32_1x1 (vf); /* { dg-error "cannot access volatile or atomic" } */
  __riscv_ztt_mss_rm (vf, a); /* { dg-error "cannot access volatile or atomic" } */
  __riscv_ztt_mls_st_f32_1x1 (f, 2.0); /* { dg-error "stride must be an integer" } */
  __riscv_ztt_mss_tst (f, 2.0, a); /* { dg-error "stride must be an integer" } */
  __riscv_ztt_f32_accx1_t acc = __riscv_ztt_mzero_acc_f32_accx1 ();
  __riscv_ztt_mss_rm (f, acc); /* { dg-error "accumulator values require an M copy" } */
}
