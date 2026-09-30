/* Floating memory keeps full native elements on both XLENs.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a16 " { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a16 " { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>
void pressure (float *out, const float *in)
{
  __riscv_ztt_f32_rno_1x4_t v0 = __riscv_ztt_mls_rm_f32_rno_1x4 (in);
  __asm__ volatile ("" : : : "memory");
  __riscv_ztt_f32_rno_1x4_t v1 = __riscv_ztt_mls_rm_f32_rno_1x4 (in);
  __asm__ volatile ("" : : : "memory");
  __riscv_ztt_f32_rno_1x4_t v2 = __riscv_ztt_mls_rm_f32_rno_1x4 (in);
  __asm__ volatile ("" : : : "memory");
  __riscv_ztt_f32_rno_1x4_t v3 = __riscv_ztt_mls_rm_f32_rno_1x4 (in);
  __asm__ volatile ("" : : : "memory");
  __riscv_ztt_f32_rno_1x4_t v4 = __riscv_ztt_mls_rm_f32_rno_1x4 (in);
  __asm__ volatile ("" : : : "memory");
  __riscv_ztt_f32_rno_1x4_t v5 = __riscv_ztt_mls_rm_f32_rno_1x4 (in);
  __asm__ volatile ("" : : : "memory");
  __riscv_ztt_mss_rm (out, v0);
  __asm__ volatile ("" : : : "memory");
  __riscv_ztt_mss_rm (out, v1);
  __asm__ volatile ("" : : : "memory");
  __riscv_ztt_mss_rm (out, v2);
  __asm__ volatile ("" : : : "memory");
  __riscv_ztt_mss_rm (out, v3);
  __asm__ volatile ("" : : : "memory");
  __riscv_ztt_mss_rm (out, v4);
  __asm__ volatile ("" : : : "memory");
  __riscv_ztt_mss_rm (out, v5);
  __asm__ volatile ("" : : : "memory");
}
