/* Q32.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
typedef char alias_i8_1x32[__builtin_types_compatible_p (__riscv_ztt_i8_1x32_t, __riscv_ztt_i8_rnu_1x32_t) ? 1 : -1];
typedef char alias_i8_32x1[__builtin_types_compatible_p (__riscv_ztt_i8_32x1_t, __riscv_ztt_i8_rnu_32x1_t) ? 1 : -1];
typedef char alias_u8_1x32[__builtin_types_compatible_p (__riscv_ztt_u8_1x32_t, __riscv_ztt_u8_rnu_1x32_t) ? 1 : -1];
typedef char alias_u8_32x1[__builtin_types_compatible_p (__riscv_ztt_u8_32x1_t, __riscv_ztt_u8_rnu_32x1_t) ? 1 : -1];
typedef char alias_i16_1x32[__builtin_types_compatible_p (__riscv_ztt_i16_1x32_t, __riscv_ztt_i16_rnu_1x32_t) ? 1 : -1];
typedef char alias_i16_32x1[__builtin_types_compatible_p (__riscv_ztt_i16_32x1_t, __riscv_ztt_i16_rnu_32x1_t) ? 1 : -1];
typedef char alias_u16_1x32[__builtin_types_compatible_p (__riscv_ztt_u16_1x32_t, __riscv_ztt_u16_rnu_1x32_t) ? 1 : -1];
typedef char alias_u16_32x1[__builtin_types_compatible_p (__riscv_ztt_u16_32x1_t, __riscv_ztt_u16_rnu_32x1_t) ? 1 : -1];
