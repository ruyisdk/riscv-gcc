/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a16" { target rv64 } } */
#include <riscv_ztt.h>
#define SAME(A, B) __builtin_types_compatible_p(A, B)
#define CHECK(C) typedef char check_##__LINE__[(C) ? 1 : -1]
CHECK((SAME(__riscv_ztt_i8_sat_1x4_t, __riscv_ztt_i8_rnu_sat_1x4_t)));
CHECK((!SAME(__riscv_ztt_i8_sat_1x4_t, __riscv_ztt_i8_1x4_t)));
CHECK((!SAME(__riscv_ztt_i8_sat_1x4_t, __riscv_ztt_i8_rne_sat_1x4_t)));
CHECK((!SAME(__riscv_ztt_i4_1x8_t, __riscv_ztt_i4_sat_1x8_t)));
CHECK((!SAME(__riscv_ztt_i4_1x8_t, __riscv_ztt_u4_1x8_t)));
