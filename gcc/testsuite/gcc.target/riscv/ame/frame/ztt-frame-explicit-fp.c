/* Function-local frame policy.  */
/* { dg-do compile } */
/* { dg-options "-O2 -g -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a16 -fno-omit-frame-pointer" { target rv32 } } */
/* { dg-options "-O2 -g -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a16 -fno-omit-frame-pointer" { target rv64 } } */

int explicit_fp (int x) { return x + 1; }

/* { dg-final { scan-assembler-not "s11" } } */
/* { dg-final { scan-assembler-not "amenlen" } } */
/* { dg-final { scan-assembler "\\.cfi_offset 8," } } */
/* { dg-final { scan-assembler "\\.cfi_restore 8" } } */
