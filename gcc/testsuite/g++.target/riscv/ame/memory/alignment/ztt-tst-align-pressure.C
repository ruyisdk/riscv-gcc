/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u64-m16-a16 " { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u64-m16-a16 " { target rv64 } } */
#include <stdint.h>
#include <stddef.h>
#include <riscv_ztt.h>
void pressure (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_1x4_t v0 = __riscv_ztt_mls_tst_f64_rno_1x4 (in + 0, stride);
  __asm__ volatile ("" : : : "memory");
  __riscv_ztt_f64_rno_1x4_t v1 = __riscv_ztt_mls_tst_f64_rno_1x4 (in + 64, stride);
  __asm__ volatile ("" : : : "memory");
  __riscv_ztt_f64_rno_1x4_t v2 = __riscv_ztt_mls_tst_f64_rno_1x4 (in + 128, stride);
  __asm__ volatile ("" : : : "memory");
  __riscv_ztt_f64_rno_1x4_t v3 = __riscv_ztt_mls_tst_f64_rno_1x4 (in + 192, stride);
  __asm__ volatile ("" : : : "memory");
  __riscv_ztt_f64_rno_1x4_t v4 = __riscv_ztt_mls_tst_f64_rno_1x4 (in + 256, stride);
  __asm__ volatile ("" : : : "memory");
  __riscv_ztt_f64_rno_1x4_t v5 = __riscv_ztt_mls_tst_f64_rno_1x4 (in + 320, stride);
  __asm__ volatile ("" : : : "memory");
  __riscv_ztt_mss_tst (out + 0, stride, v0);
  __asm__ volatile ("" : : : "memory");
  __riscv_ztt_mss_tst (out + 64, stride, v1);
  __asm__ volatile ("" : : : "memory");
  __riscv_ztt_mss_tst (out + 128, stride, v2);
  __asm__ volatile ("" : : : "memory");
  __riscv_ztt_mss_tst (out + 192, stride, v3);
  __asm__ volatile ("" : : : "memory");
  __riscv_ztt_mss_tst (out + 256, stride, v4);
  __asm__ volatile ("" : : : "memory");
  __riscv_ztt_mss_tst (out + 320, stride, v5);
  __asm__ volatile ("" : : : "memory");
}
/* { dg-final { scan-assembler-not {\tcall\t} } } */
