/* Function-local frame policy.  */
/* { dg-do compile } */
/* { dg-options "-O2 -g -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -g -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */

unsigned long query (void)
{
  return __builtin_riscv_ztt_read_amenlen () + __builtin_riscv_ztt_read_ameudsz ();
}

/* { dg-final { scan-assembler-not "s11" } } */
/* { dg-final { scan-assembler-not "s0" } } */
/* { dg-final { scan-assembler-times {csrr\t[^,]+,amenlen} 1 } } */
/* { dg-final { scan-assembler-times {csrr\t[^,]+,ameudsz} 1 } } */
