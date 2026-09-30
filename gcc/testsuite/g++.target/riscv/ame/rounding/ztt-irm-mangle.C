/* single-M
   i8 integer rounding-mode subset.  */
/* { dg-do compile } */
/* { dg-options "-O0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */


#include <riscv_ztt.h>

template<typename T> __attribute__ ((noinline)) void identity () {}
template void identity<__riscv_ztt_i8_rnu_1x1_t> ();
/* { dg-final { scan-assembler "_Z8identityIu24__riscv_ztt_i8_rnu_1x1_tEvv" } } */
template void identity<__riscv_ztt_i8_rne_1x1_t> ();
/* { dg-final { scan-assembler "_Z8identityIu24__riscv_ztt_i8_rne_1x1_tEvv" } } */
template void identity<__riscv_ztt_i8_rdn_1x1_t> ();
/* { dg-final { scan-assembler "_Z8identityIu24__riscv_ztt_i8_rdn_1x1_tEvv" } } */
template void identity<__riscv_ztt_i8_rod_1x1_t> ();
/* { dg-final { scan-assembler "_Z8identityIu24__riscv_ztt_i8_rod_1x1_tEvv" } } */
