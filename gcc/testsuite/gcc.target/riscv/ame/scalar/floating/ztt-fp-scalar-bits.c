/* Floating data scalar contracts, not numerical execution.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -ffast-math -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -ffast-math -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
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
void bits_f16 (void)
{
  _Float16 c;
  const uint16_t payload = 0x8000U;
  __builtin_memcpy (&c, &payload, sizeof (c));
  __riscv_ztt_i16_1x1_t b = __riscv_ztt_mzero_m_i16_1x1 ();
  __riscv_ztt_i16_1x1_t d = __riscv_ztt_madd_ew_x_i16_1x1_f16 (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr"(d));
}
void bits_bf16 (void)
{
  __bf16 c;
  const uint16_t payload = 0x7f81U;
  __builtin_memcpy (&c, &payload, sizeof (c));
  __riscv_ztt_i16_1x1_t b = __riscv_ztt_mzero_m_i16_1x1 ();
  __riscv_ztt_i16_1x1_t d = __riscv_ztt_madd_ew_x_i16_1x1_bf16 (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr"(d));
}
void bits_f32 (void)
{
  float c;
  const uint32_t payload = 0x7fa12345U;
  __builtin_memcpy (&c, &payload, sizeof (c));
  __riscv_ztt_i16_1x1_t b = __riscv_ztt_mzero_m_i16_1x1 ();
  __riscv_ztt_i16_1x1_t d = __riscv_ztt_madd_ew_x_i16_1x1_f32 (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr"(d));
}
void bits_f64 (void)
{
  ztt_test_f64_carrier_t c;
#if __riscv_xlen == 32
  c = 0x89abcdefU;
#else
  const uint64_t payload = 0x8000000000000000ULL;
  __builtin_memcpy (&c, &payload, sizeof (c));
#endif
  __riscv_ztt_i16_1x1_t b = __riscv_ztt_mzero_m_i16_1x1 ();
  __riscv_ztt_i16_1x1_t d = __riscv_ztt_madd_ew_x_i16_1x1_f64 (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr"(d));
}
