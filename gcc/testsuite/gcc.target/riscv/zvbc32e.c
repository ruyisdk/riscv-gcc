/* { dg-do compile { target { ! riscv_abi_e } } } */
/* { dg-options "-march=rv64gc_zvbc32e" { target { rv64 } } } */
/* { dg-options "-march=rv32gc_zvbc32e" { target { rv32 } } } */

#ifndef __riscv_zvbc32e
#error "Feature macro not defined"
#endif

#ifndef __riscv_zve32x
#error "Zve32x dependency macro not defined"
#endif

#ifdef __riscv_zvbc
#error "Zvbc32e must not imply Zvbc"
#endif

int
foo (int a)
{
  return a;
}
