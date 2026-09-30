/* Nonpacked ACC tuples.  */
/* { dg-do compile } */
/* { dg-options "-O0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
template<typename T> __attribute__ ((noinline)) void identity () {}
template void identity<__riscv_ztt_i8_rnu_accx1_t> ();
/* { dg-final { scan-assembler "_Z8identityIu26__riscv_ztt_i8_rnu_accx1_tEvv" } } */
template void identity<__riscv_ztt_i8_rnu_accx2_t> ();
/* { dg-final { scan-assembler "_Z8identityIu26__riscv_ztt_i8_rnu_accx2_tEvv" } } */
template void identity<__riscv_ztt_i8_rnu_accx4_t> ();
/* { dg-final { scan-assembler "_Z8identityIu26__riscv_ztt_i8_rnu_accx4_tEvv" } } */
template void identity<__riscv_ztt_u8_rod_accx2_t> ();
/* { dg-final { scan-assembler "_Z8identityIu26__riscv_ztt_u8_rod_accx2_tEvv" } } */
template void identity<__riscv_ztt_i16_rdn_accx2_t> ();
/* { dg-final { scan-assembler "_Z8identityIu27__riscv_ztt_i16_rdn_accx2_tEvv" } } */
template void identity<__riscv_ztt_u16_rne_accx2_t> ();
/* { dg-final { scan-assembler "_Z8identityIu27__riscv_ztt_u16_rne_accx2_tEvv" } } */
