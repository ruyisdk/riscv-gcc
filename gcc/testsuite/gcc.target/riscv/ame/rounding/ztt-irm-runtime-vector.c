/* single-M
   integer RM state with independent RVV/AME stack storage.  */
/* { dg-do compile } */
/* { dg-options "-O0 -g -fstack-clash-protection -march=rv32gcv_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O0 -g -fstack-clash-protection -march=rv64gcv_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */

#include <riscv_vector.h>
#include <riscv_ztt.h>

void
mixed_vector (const int32_t *vin, int32_t *vout, const signed char *in,
              signed char *out0, signed char *out1, unsigned long vl)
{
  vint32m1_t v = __riscv_vle32_v_i32m1 (vin, vl);
  __riscv_ztt_i8_rnu_1x1_t a = __riscv_ztt_mls_rm_i8_rnu_1x1 (in);
  __riscv_ztt_i8_rod_1x1_t b = __riscv_ztt_mls_rm_i8_rod_1x1 (in);
  __asm__ volatile ("" : "+vr" (v), "+Wmr" (a), "+Wmr" (b));
  a = __riscv_ztt_madd_ew_i8_rnu_1x1 (a, a);
  b = __riscv_ztt_madd_ew_i8_rod_1x1 (b, b);
  __riscv_vse32_v_i32m1 (vout, v, vl);
  __riscv_ztt_mss_rm (out0, a);
  __riscv_ztt_mss_rm (out1, b);
}

/* { dg-final { scan-assembler "vlenb" } } */
/* { dg-final { scan-assembler "vs1r\\.v" } } */
/* { dg-final { scan-assembler "mss\\.1r" } } */
/* { dg-final { scan-assembler "amenlen" } } */
/* { dg-final { scan-assembler-not "mmov\\.m\\.m" } } */
