/* { dg-do compile } */
/* { dg-options "-mriscv-attribute -march=rv64i_ssqosid1p0 -mabi=lp64" { target { rv64 } } } */
/* { dg-options "-mriscv-attribute -march=rv32i_ssqosid1p0 -mabi=ilp32" { target { rv32 } } } */

#ifndef __riscv_ssqosid
#error "Feature macro for 'ssqosid' not defined"
#endif

int
foo (void)
{
  return 0;
}

/* { dg-final { scan-assembler ".attribute arch, .*ssqosid1p0" } } */
