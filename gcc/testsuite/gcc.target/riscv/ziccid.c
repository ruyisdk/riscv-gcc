/* { dg-do compile { target { ! riscv_abi_e } } } */
/* { dg-options "-mriscv-attribute -march=rv64i_ziccid -mabi=lp64" { target { rv64 } } } */
/* { dg-options "-mriscv-attribute -march=rv32i_ziccid -mabi=ilp32" { target { rv32 } } } */

#ifndef __riscv_ziccid
#error "Feature macro for 'ziccid' not defined"
#endif

#ifndef __riscv_ziccif
#error "Feature macro for 'ziccif' not defined"
#endif

int
foo (void)
{
  return 0;
}

/* { dg-final { scan-assembler ".attribute arch, \"rv64i2p1_ziccid1p0_ziccif1p0\"" { target { rv64 } } } } */
/* { dg-final { scan-assembler ".attribute arch, \"rv32i2p1_ziccid1p0_ziccif1p0\"" { target { rv32 } } } } */
