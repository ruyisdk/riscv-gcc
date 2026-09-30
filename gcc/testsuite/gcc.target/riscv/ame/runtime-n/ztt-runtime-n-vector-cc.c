/* { dg-do compile } */
/* { dg-options "-O0 -g -march=rv32gcv_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O0 -g -march=rv64gcv_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>
#include <riscv_vector.h>

__attribute__((riscv_vector_cc)) void
independent_vector_sizes (const signed char *mi, signed char *mo,
                          const int32_t *vi, int32_t *vo, unsigned long vl)
{
  vint32m1_t v = __riscv_vle32_v_i32m1 (vi, vl);
  __riscv_ztt_i8_rne_1x1_t m = __riscv_ztt_mls_rm_i8_rne_1x1 (mi);
  __riscv_ztt_mss_rm (mo, m);
  __riscv_vse32_v_i32m1 (vo, v, vl);
}

/* After restoring s0, CFA must not include the popped vector save area.  */
/* { dg-final { scan-assembler "csrr\ts11,amenlen" } } */
/* { dg-final { scan-assembler "mss\\.1r" } } */
/* { dg-final { scan-assembler "vs1r\\.v\tv1," } } */
/* { dg-final { scan-assembler "\\.cfi_restore 97" } } */
/* { dg-final { scan-assembler "\\.cfi_restore 8\n\[ \t\]*\\.cfi_def_cfa 2, \[0-9\]+" } } */
