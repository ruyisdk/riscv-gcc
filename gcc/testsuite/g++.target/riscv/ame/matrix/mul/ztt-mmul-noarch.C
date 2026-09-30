/* mmul.ew.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr -mabi=ilp32" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr -mabi=lp64" { target rv64 } } */
#ifdef __riscv_ztt_mmul_ew_int_mixed
#error unexpected typed multiplication capability
#endif
#pragma riscv intrinsic "ztt" /* { dg-error "requires the .*ztt0p6.* ISA extension" } */
