/* Floating/mixed broadcast contracts, not numerical execution.  */
/* { dg-do compile } */
/* { dg-options "-O2 -ffast-math -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -ffast-math -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
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
unsigned long dead (float c)
{
  unsigned long before = __riscv_ztt_get_amefflags ();
  __riscv_ztt_mbcast_m_x_f16_rno_1x1_f32_rup ( __riscv_ztt_scalar_make_f32_rup (c));
  __riscv_ztt_mbcast_m_x_i16_rne_sat_1x1_f32_rtz ( __riscv_ztt_scalar_make_f32_rtz (c));
  __riscv_ztt_mbcast_m_x_bf16_rmm_1x1_i64_rod ( __riscv_ztt_scalar_from_bits_i64_rod ((__UINTPTR_TYPE__) 1));
  return __riscv_ztt_get_amefflags () - before;
}
/* { dg-final { scan-assembler-times {mbcast\.m\.x} 3 } } */
/* { dg-final { scan-assembler-times {amefflags} 2 } } */
/* { dg-final { scan-assembler-not {amestype|fcvt\.} } } */
