/* Floating/mixed broadcast contracts, not numerical execution.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
#include "../../fixtures/ztt-scalar-construct.h"
#if __riscv_xlen >= 8
typedef int8_t carrier_i8;
typedef uint8_t carrier_u8;
#else
typedef __UINTPTR_TYPE__ carrier_i8;
typedef __UINTPTR_TYPE__ carrier_u8;
#endif
#if __riscv_xlen >= 16
typedef int16_t carrier_i16;
typedef uint16_t carrier_u16;
#else
typedef __UINTPTR_TYPE__ carrier_i16;
typedef __UINTPTR_TYPE__ carrier_u16;
#endif
#if __riscv_xlen >= 32
typedef int32_t carrier_i32;
typedef uint32_t carrier_u32;
#else
typedef __UINTPTR_TYPE__ carrier_i32;
typedef __UINTPTR_TYPE__ carrier_u32;
#endif
#if __riscv_xlen >= 64
typedef int64_t carrier_i64;
typedef uint64_t carrier_u64;
#else
typedef __UINTPTR_TYPE__ carrier_i64;
typedef __UINTPTR_TYPE__ carrier_u64;
#endif
#if __riscv_xlen >= 128
typedef int128_t carrier_i128;
typedef uint128_t carrier_u128;
#else
typedef __UINTPTR_TYPE__ carrier_i128;
typedef __UINTPTR_TYPE__ carrier_u128;
#endif
void hard_0 (_Float16 c)
{
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rno_1x1_f16_rup ( __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void hard_1 (__bf16 c)
{
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rno_1x1_bf16_rno ( __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void hard_2 (float c)
{
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rno_1x1_f32_rtz ( __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void hard_3 (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rno_1x1_f64_rmm ( ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
