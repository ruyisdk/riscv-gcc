/* { dg-do compile } */
/* { dg-options "-march=rv32gc_ztt -mabi=ilp32" { target rv32 } } */
/* { dg-options "-march=rv64gc_ztt -mabi=lp64" { target rv64 } } */

#if !defined (__riscv_ztt)
#error "__riscv_ztt is not defined"
#endif

#if __riscv_ztt != 6000
#error "unexpected __riscv_ztt version"
#endif
