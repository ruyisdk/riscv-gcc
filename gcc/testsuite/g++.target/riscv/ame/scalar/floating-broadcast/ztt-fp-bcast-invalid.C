/* Floating/mixed broadcast contracts, not numerical execution.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
#include "../../../../../gcc.target/riscv/ame/fixtures/ztt-scalar-construct.h"
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
void invalid (float c, double d, int i, __bf16 b)
{
  __riscv_ztt_mbcast_m_x_f16_1x1_f16 ( __riscv_ztt_scalar_make_f16_rne (c)); /* { dg-error "exact C floating format" } */
  __riscv_ztt_mbcast_m_x_f16_1x1_f32 ( __riscv_ztt_scalar_make_f32_rne (d)); /* { dg-error "exact C floating format" } */
  __riscv_ztt_mbcast_m_x_f16_1x1_f32 ( __riscv_ztt_scalar_make_f32_rne (i)); /* { dg-error "exact C floating format" } */
  __riscv_ztt_mbcast_m_x_f16_1x1_f16 ( __riscv_ztt_scalar_make_f16_rne (b)); /* { dg-error "exact C floating format" } */
  __riscv_ztt_mbcast_m_x_f16_1x1_i16 ( __riscv_ztt_scalar_make_i16_rnu (c)); /* { dg-error "Scalar constructor requires an integer carrier" } */
#if __riscv_xlen == 32
  __riscv_ztt_mbcast_m_x_f16_1x1_f64 (__riscv_ztt_scalar_from_bits_f64_rne (d)); /* { dg-error "Scalar constructor requires an integer carrier" "" { target rv32 } } */
  __riscv_ztt_mbcast_m_x_f16_1x1_f64 (__riscv_ztt_scalar_from_bits_f64_rne ((uint64_t) 0)); /* { dg-error "XLEN-bit carrier" "" { target rv32 } } */
#endif
}
