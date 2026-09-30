/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a16" { target rv64 } } */
#include <riscv_ztt.h>
template <typename A, typename B> struct same { static const bool value = false; };
template <typename A> struct same<A, A> { static const bool value = true; };
#define SAME(A, B) same<A, B>::value
#define CHECK(C) static_assert(C, "type identity")
CHECK((SAME(__riscv_ztt_i8_sat_1x4_t, __riscv_ztt_i8_rnu_sat_1x4_t)));
CHECK((!SAME(__riscv_ztt_i8_sat_1x4_t, __riscv_ztt_i8_1x4_t)));
CHECK((!SAME(__riscv_ztt_i8_sat_1x4_t, __riscv_ztt_i8_rne_sat_1x4_t)));
CHECK((!SAME(__riscv_ztt_i4_1x8_t, __riscv_ztt_i4_sat_1x8_t)));
CHECK((!SAME(__riscv_ztt_i4_1x8_t, __riscv_ztt_u4_1x8_t)));
