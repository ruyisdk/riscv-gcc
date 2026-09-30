/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */
/* { dg-additional-options "-fdump-rtl-expand" } */

#include <riscv_ztt.h>

void
ztt_typed_codegen (const signed char *input, signed char *output)
{
  __riscv_ztt_i8_rne_1x1_t lhs
    = __riscv_ztt_mls_rm_i8_rne_1x1 (input);
  __riscv_ztt_i8_rne_1x1_t rhs
    = __riscv_ztt_mzero_2d_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t result
    = __riscv_ztt_madd_ew_i8_rne_1x1 (lhs, rhs);
  __riscv_ztt_mss_rm (output, result);
}

/* The P0 i8_rne descriptor is 0x48000008.  */
/* { dg-final { scan-assembler "li\t\[a-z0-9\]+,1207959552" } } */
/* { dg-final { scan-assembler "addi\t\[a-z0-9\]+,\[a-z0-9\]+,8" } } */
/* { dg-final { scan-assembler-times "msettyp\tm\[0-9\]+," 2 } } */
/* { dg-final { scan-assembler "mzero\\.2d\\.m\tm\[0-9\]+" } } */
/* { dg-final { scan-assembler "mls\\.rm\tm\[0-9\]+," } } */
/* { dg-final { scan-assembler "madd\\.ew\tm\[0-9\]+,m\[0-9\]+,m\[0-9\]+" } } */
/* { dg-final { scan-assembler "mss\\.rm\tm\[0-9\]+," } } */
/* The element pointer guarantees only byte alignment.  */
/* { dg-final { scan-rtl-dump-times "S16384 A8" 2 "expand" } } */
