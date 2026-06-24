/* { dg-do compile } */
/* { dg-options "-mriscv-attribute -march=rv64i_svrsw60t59b1p0 -mabi=lp64" { target { rv64 } } } */
/* { dg-options "-mriscv-attribute -march=rv32i_svrsw60t59b1p0 -mabi=ilp32" { target { rv32 } } } */

#ifndef __riscv_svrsw60t59b
#error "Feature macro for 'svrsw60t59b' not defined"
#endif

int
foo (void)
{
  return 0;
}

/* { dg-final { scan-assembler ".attribute arch, .*svrsw60t59b1p0" } } */
