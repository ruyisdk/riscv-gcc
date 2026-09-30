/* mmul.ew.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#ifdef __riscv_ztt_mmul_ew_int_mixed
#error unexpected typed multiplication capability
#endif
#pragma riscv intrinsic "ztt" /* { dg-error "requires .*-mztt-profile=gcc-p0-n128-u8-m16-a4.*" } */
