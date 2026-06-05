/* { dg-do compile { target { ! riscv_abi_e } } } */
/* { dg-options "-march=rv64gc_zvkgs" { target { rv64 } } } */
/* { dg-options "-march=rv32gc_zvkgs" { target { rv32 } } } */

#ifndef __riscv_zvkgs
#error "Feature macro not defined"
#endif

#ifndef __riscv_zvkg
#error "Zvkg dependency macro not defined"
#endif

#ifndef __riscv_zve32x
#error "Zve32x dependency macro not defined"
#endif

int
foo (int a)
{
  return a;
}
