/* Function-local frame policy.  */
/* { dg-do compile } */
/* { dg-options "-O2 -g -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -g -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */

void clobber_s11 (void)
{
  __asm__ volatile ("li s11,7" : : : "s11");
}

/* { dg-final { scan-assembler "\\.cfi_offset 27," } } */
/* { dg-final { scan-assembler "\\.cfi_restore 27" } } */
/* { dg-final { scan-assembler-not "amenlen" } } */
/* { dg-final { scan-assembler-not "s0" } } */
