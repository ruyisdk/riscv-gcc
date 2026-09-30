/* { dg-do compile } */
/* { dg-options "-O0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
template<typename T> __attribute__ ((noinline)) void identity () {}
template void identity<__riscv_ztt_i64_rnu_1x1_t> ();
/* { dg-final { scan-assembler "_Z8identityIu25__riscv_ztt_i64_rnu_1x1_tEvv" } } */
template void identity<__riscv_ztt_i64_rne_1x1_t> ();
/* { dg-final { scan-assembler "_Z8identityIu25__riscv_ztt_i64_rne_1x1_tEvv" } } */
template void identity<__riscv_ztt_u64_rnu_1x1_t> ();
/* { dg-final { scan-assembler "_Z8identityIu25__riscv_ztt_u64_rnu_1x1_tEvv" } } */
template void identity<__riscv_ztt_i128_rnu_1x1_t> ();
/* { dg-final { scan-assembler "_Z8identityIu26__riscv_ztt_i128_rnu_1x1_tEvv" } } */
template void identity<__riscv_ztt_u128_rod_accx1_t> ();
/* { dg-final { scan-assembler "_Z8identityIu28__riscv_ztt_u128_rod_accx1_tEvv" } } */
