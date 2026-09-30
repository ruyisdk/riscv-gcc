/* Floating data scalar contracts, not numerical execution.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
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
#if __riscv_ztt_floating_scalar != 1
#error missing capability
#endif
void scalar_madd_i4_rnu (carrier_i8 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i4_rnu_2x1_t d = __riscv_ztt_madd_ew_x_i4_rnu_2x1_i8_rnu (b, __riscv_ztt_scalar_make_i8_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i4_rne (__bf16 c)
{
  __riscv_ztt_i4_rne_1x4_t b = __riscv_ztt_mzero_m_i4_rne_1x4 ();
  __riscv_ztt_i4_rne_1x4_t d = __riscv_ztt_madd_ew_x_i4_rne_1x4_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i4_rdn (carrier_u16 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_i4_rdn_2x1_t d = __riscv_ztt_madd_ew_x_i4_rdn_2x1_u16_rdn (b, __riscv_ztt_scalar_make_u16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i4_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rod_1x2_t b = __riscv_ztt_mzero_m_i4_rod_1x2 ();
  __riscv_ztt_i4_rod_1x2_t d = __riscv_ztt_madd_ew_x_i4_rod_1x2_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u4_rnu (carrier_u64 c)
{
  __riscv_ztt_f16_rmm_2x1_t b = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_u4_rnu_2x1_t d = __riscv_ztt_madd_ew_x_u4_rnu_2x1_u64_rnu (b, __riscv_ztt_scalar_from_bits_u64_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u4_rne (__bf16 c)
{
  __riscv_ztt_u4_rne_1x8_t b = __riscv_ztt_mzero_m_u4_rne_1x8 ();
  __riscv_ztt_u4_rne_1x8_t d = __riscv_ztt_madd_ew_x_u4_rne_1x8_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u4_rdn (carrier_i8 c)
{
  __riscv_ztt_bf16_rne_2x1_t b = __riscv_ztt_mzero_m_bf16_rne_2x1 ();
  __riscv_ztt_u4_rdn_2x1_t d = __riscv_ztt_madd_ew_x_u4_rdn_2x1_i8_rdn_sat (b, __riscv_ztt_scalar_make_i8_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u4_rod (_Float16 c)
{
  __riscv_ztt_u4_rod_1x4_t b = __riscv_ztt_mzero_m_u4_rod_1x4 ();
  __riscv_ztt_u4_rod_1x4_t d = __riscv_ztt_madd_ew_x_u4_rod_1x4_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i8_rnu (carrier_i32 c)
{
  __riscv_ztt_bf16_rdn_2x1_t b = __riscv_ztt_mzero_m_bf16_rdn_2x1 ();
  __riscv_ztt_i8_rnu_2x1_t d = __riscv_ztt_madd_ew_x_i8_rnu_2x1_i32_rnu_sat (b, __riscv_ztt_scalar_make_i32_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i8_rne (float c)
{
  __riscv_ztt_i8_rne_1x1_t b = __riscv_ztt_mzero_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t d = __riscv_ztt_madd_ew_x_i8_rne_1x1_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i8_rdn (carrier_u64 c)
{
  __riscv_ztt_bf16_rmm_2x1_t b = __riscv_ztt_mzero_m_bf16_rmm_2x1 ();
  __riscv_ztt_i8_rdn_2x1_t d = __riscv_ztt_madd_ew_x_i8_rdn_2x1_u64_rdn_sat (b, __riscv_ztt_scalar_from_bits_u64_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i8_rod (_Float16 c)
{
  __riscv_ztt_i8_rod_1x4_t b = __riscv_ztt_mzero_m_i8_rod_1x4 ();
  __riscv_ztt_i8_rod_1x4_t d = __riscv_ztt_madd_ew_x_i8_rod_1x4_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u8_rnu (_Float16 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t d = __riscv_ztt_madd_ew_x_u8_rnu_1x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u8_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rne_1x2_t b = __riscv_ztt_mzero_m_u8_rne_1x2 ();
  __riscv_ztt_u8_rne_1x2_t d = __riscv_ztt_madd_ew_x_u8_rne_1x2_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u8_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t d = __riscv_ztt_madd_ew_x_u8_rdn_1x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u8_rod (__bf16 c)
{
  __riscv_ztt_u8_rod_1x1_t b = __riscv_ztt_mzero_m_u8_rod_1x1 ();
  __riscv_ztt_u8_rod_1x1_t d = __riscv_ztt_madd_ew_x_u8_rod_1x1_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i16_rnu (carrier_i16 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t d = __riscv_ztt_madd_ew_x_i16_rnu_1x1_i16_rnu (b, __riscv_ztt_scalar_make_i16_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i16_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rne_1x2_t b = __riscv_ztt_mzero_m_i16_rne_1x2 ();
  __riscv_ztt_i16_rne_1x2_t d = __riscv_ztt_madd_ew_x_i16_rne_1x2_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i16_rdn (carrier_u32 c)
{
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_i16_rdn_1x1_t d = __riscv_ztt_madd_ew_x_i16_rdn_1x1_u32_rdn (b, __riscv_ztt_scalar_make_u32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i16_rod (float c)
{
  __riscv_ztt_i16_rod_1x2_t b = __riscv_ztt_mzero_m_i16_rod_1x2 ();
  __riscv_ztt_i16_rod_1x2_t d = __riscv_ztt_madd_ew_x_i16_rod_1x2_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u16_rnu (carrier_u128 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_u16_rnu_2x1_t d = __riscv_ztt_madd_ew_x_u16_rnu_2x1_u128_rnu (b, __riscv_ztt_scalar_from_bits_u128_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u16_rne (_Float16 c)
{
  __riscv_ztt_u16_rne_1x1_t b = __riscv_ztt_mzero_m_u16_rne_1x1 ();
  __riscv_ztt_u16_rne_1x1_t d = __riscv_ztt_madd_ew_x_u16_rne_1x1_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u16_rdn (carrier_i16 c)
{
  __riscv_ztt_f16_rmm_2x1_t b = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_u16_rdn_2x1_t d = __riscv_ztt_madd_ew_x_u16_rdn_2x1_i16_rdn_sat (b, __riscv_ztt_scalar_make_i16_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u16_rod (float c)
{
  __riscv_ztt_u16_rod_1x2_t b = __riscv_ztt_mzero_m_u16_rod_1x2 ();
  __riscv_ztt_u16_rod_1x2_t d = __riscv_ztt_madd_ew_x_u16_rod_1x2_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i32_rnu (carrier_i64 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_madd_ew_x_i32_rnu_1x1_i64_rnu_sat (b, __riscv_ztt_scalar_from_bits_i64_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i32_rne (__bf16 c)
{
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_madd_ew_x_i32_rne_1x1_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i32_rdn (carrier_u128 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_madd_ew_x_i32_rdn_1x1_u128_rdn_sat (b, __riscv_ztt_scalar_from_bits_u128_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i32_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_madd_ew_x_i32_rod_1x1_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u32_rnu (float c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_madd_ew_x_u32_rnu_1x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u32_rne (__bf16 c)
{
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_madd_ew_x_u32_rne_1x1_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u32_rdn (carrier_i8 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_madd_ew_x_u32_rdn_1x1_i8_rdn (b, __riscv_ztt_scalar_make_i8_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u32_rod (_Float16 c)
{
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_madd_ew_x_u32_rod_1x1_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i4_rnu_sat (carrier_i32 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i4_rnu_sat_2x1_t d = __riscv_ztt_madd_ew_x_i4_rnu_sat_2x1_i32_rnu (b, __riscv_ztt_scalar_make_i32_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i4_rne_sat (float c)
{
  __riscv_ztt_i4_rne_sat_1x2_t b = __riscv_ztt_mzero_m_i4_rne_sat_1x2 ();
  __riscv_ztt_i4_rne_sat_1x2_t d = __riscv_ztt_madd_ew_x_i4_rne_sat_1x2_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i4_rdn_sat (carrier_u64 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i4_rdn_sat_2x1_t d = __riscv_ztt_madd_ew_x_i4_rdn_sat_2x1_u64_rdn (b, __riscv_ztt_scalar_from_bits_u64_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i4_rod_sat (_Float16 c)
{
  __riscv_ztt_i4_rod_sat_1x8_t b = __riscv_ztt_mzero_m_i4_rod_sat_1x8 ();
  __riscv_ztt_i4_rod_sat_1x8_t d = __riscv_ztt_madd_ew_x_i4_rod_sat_1x8_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u4_rnu_sat (carrier_u8 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_u4_rnu_sat_2x1_t d = __riscv_ztt_madd_ew_x_u4_rnu_sat_2x1_u8_rnu_sat (b, __riscv_ztt_scalar_make_u8_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u4_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rne_sat_1x4_t b = __riscv_ztt_mzero_m_u4_rne_sat_1x4 ();
  __riscv_ztt_u4_rne_sat_1x4_t d = __riscv_ztt_madd_ew_x_u4_rne_sat_1x4_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u4_rdn_sat (carrier_i32 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_u4_rdn_sat_2x1_t d = __riscv_ztt_madd_ew_x_u4_rdn_sat_2x1_i32_rdn_sat (b, __riscv_ztt_scalar_make_i32_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u4_rod_sat (__bf16 c)
{
  __riscv_ztt_u4_rod_sat_1x2_t b = __riscv_ztt_mzero_m_u4_rod_sat_1x2 ();
  __riscv_ztt_u4_rod_sat_1x2_t d = __riscv_ztt_madd_ew_x_u4_rod_sat_1x2_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i8_rnu_sat (carrier_i128 c)
{
  __riscv_ztt_f16_rmm_2x1_t b = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_i8_rnu_sat_2x1_t d = __riscv_ztt_madd_ew_x_i8_rnu_sat_2x1_i128_rnu_sat (b, __riscv_ztt_scalar_from_bits_i128_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i8_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rne_sat_1x4_t b = __riscv_ztt_mzero_m_i8_rne_sat_1x4 ();
  __riscv_ztt_i8_rne_sat_1x4_t d = __riscv_ztt_madd_ew_x_i8_rne_sat_1x4_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i8_rdn_sat (__bf16 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_i8_rdn_sat_1x1_t d = __riscv_ztt_madd_ew_x_i8_rdn_sat_1x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i8_rod_sat (float c)
{
  __riscv_ztt_i8_rod_sat_1x2_t b = __riscv_ztt_mzero_m_i8_rod_sat_1x2 ();
  __riscv_ztt_i8_rod_sat_1x2_t d = __riscv_ztt_madd_ew_x_i8_rod_sat_1x2_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u8_rnu_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rdn_2x1_t b = __riscv_ztt_mzero_m_bf16_rdn_2x1 ();
  __riscv_ztt_u8_rnu_sat_2x1_t d = __riscv_ztt_madd_ew_x_u8_rnu_sat_2x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u8_rne_sat (_Float16 c)
{
  __riscv_ztt_u8_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rne_sat_1x1 ();
  __riscv_ztt_u8_rne_sat_1x1_t d = __riscv_ztt_madd_ew_x_u8_rne_sat_1x1_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u8_rdn_sat (carrier_i16 c)
{
  __riscv_ztt_bf16_rmm_2x1_t b = __riscv_ztt_mzero_m_bf16_rmm_2x1 ();
  __riscv_ztt_u8_rdn_sat_2x1_t d = __riscv_ztt_madd_ew_x_u8_rdn_sat_2x1_i16_rdn (b, __riscv_ztt_scalar_make_i16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u8_rod_sat (float c)
{
  __riscv_ztt_u8_rod_sat_1x4_t b = __riscv_ztt_mzero_m_u8_rod_sat_1x4 ();
  __riscv_ztt_u8_rod_sat_1x4_t d = __riscv_ztt_madd_ew_x_u8_rod_sat_1x4_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i16_rnu_sat (carrier_i64 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t d = __riscv_ztt_madd_ew_x_i16_rnu_sat_1x1_i64_rnu (b, __riscv_ztt_scalar_from_bits_i64_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i16_rne_sat (__bf16 c)
{
  __riscv_ztt_i16_rne_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rne_sat_1x2 ();
  __riscv_ztt_i16_rne_sat_1x2_t d = __riscv_ztt_madd_ew_x_i16_rne_sat_1x2_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i16_rdn_sat (carrier_u128 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t d = __riscv_ztt_madd_ew_x_i16_rdn_sat_1x1_u128_rdn (b, __riscv_ztt_scalar_from_bits_u128_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i16_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rod_sat_1x1 ();
  __riscv_ztt_i16_rod_sat_1x1_t d = __riscv_ztt_madd_ew_x_i16_rod_sat_1x1_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u16_rnu_sat (carrier_u16 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t d = __riscv_ztt_madd_ew_x_u16_rnu_sat_1x1_u16_rnu_sat (b, __riscv_ztt_scalar_make_u16_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u16_rne_sat (__bf16 c)
{
  __riscv_ztt_u16_rne_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rne_sat_1x2 ();
  __riscv_ztt_u16_rne_sat_1x2_t d = __riscv_ztt_madd_ew_x_u16_rne_sat_1x2_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u16_rdn_sat (carrier_i64 c)
{
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_u16_rdn_sat_1x1_t d = __riscv_ztt_madd_ew_x_u16_rdn_sat_1x1_i64_rdn_sat (b, __riscv_ztt_scalar_from_bits_i64_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u16_rod_sat (_Float16 c)
{
  __riscv_ztt_u16_rod_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rod_sat_1x2 ();
  __riscv_ztt_u16_rod_sat_1x2_t d = __riscv_ztt_madd_ew_x_u16_rod_sat_1x2_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i32_rnu_sat (_Float16 c)
{
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_madd_ew_x_i32_rnu_sat_1x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i32_rne_sat (float c)
{
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_madd_ew_x_i32_rne_sat_1x1_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i32_rdn_sat (float c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_madd_ew_x_i32_rdn_sat_1x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_i32_rod_sat (_Float16 c)
{
  __riscv_ztt_i32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_madd_ew_x_i32_rod_sat_1x1_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u32_rnu_sat (carrier_u8 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_madd_ew_x_u32_rnu_sat_1x1_u8_rnu (b, __riscv_ztt_scalar_make_u8_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u32_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_madd_ew_x_u32_rne_sat_1x1_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u32_rdn_sat (carrier_i32 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_madd_ew_x_u32_rdn_sat_1x1_i32_rdn (b, __riscv_ztt_scalar_make_i32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_u32_rod_sat (__bf16 c)
{
  __riscv_ztt_u32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_madd_ew_x_u32_rod_sat_1x1_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_f16_rne (carrier_i128 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_f16_rne_2x1_t d = __riscv_ztt_madd_ew_x_f16_rne_2x1_i128_rnu (b, __riscv_ztt_scalar_from_bits_i128_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_f16_rtz (carrier_u128 c)
{
  __riscv_ztt_f16_rtz_1x2_t b = __riscv_ztt_mzero_m_f16_rtz_1x2 ();
  __riscv_ztt_f16_rtz_1x2_t d = __riscv_ztt_madd_ew_x_f16_rtz_1x2_u128_rod (b, __riscv_ztt_scalar_from_bits_u128_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_f16_rdn (carrier_u8 c)
{
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_madd_ew_x_f16_rdn_1x1_u8_rdn_sat (b, __riscv_ztt_scalar_make_u8_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_f16_rup (carrier_u16 c)
{
  __riscv_ztt_f16_rup_1x2_t b = __riscv_ztt_mzero_m_f16_rup_1x2 ();
  __riscv_ztt_f16_rup_1x2_t d = __riscv_ztt_madd_ew_x_f16_rup_1x2_u16_rne_sat (b, __riscv_ztt_scalar_make_u16_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_f16_rmm (carrier_u32 c)
{
  __riscv_ztt_f16_rmm_2x1_t b = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_f16_rmm_2x1_t d = __riscv_ztt_madd_ew_x_f16_rmm_2x1_u32_rnu_sat (b, __riscv_ztt_scalar_make_u32_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_f16_rno (carrier_i64 c)
{
  __riscv_ztt_f16_rno_1x1_t b = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_madd_ew_x_f16_rno_1x1_i64_rod_sat (b, __riscv_ztt_scalar_from_bits_i64_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_bf16_rne (carrier_i128 c)
{
  __riscv_ztt_bf16_rne_2x1_t b = __riscv_ztt_mzero_m_bf16_rne_2x1 ();
  __riscv_ztt_bf16_rne_2x1_t d = __riscv_ztt_madd_ew_x_bf16_rne_2x1_i128_rdn_sat (b, __riscv_ztt_scalar_from_bits_i128_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_bf16_rtz (_Float16 c)
{
  __riscv_ztt_bf16_rtz_1x2_t b = __riscv_ztt_mzero_m_bf16_rtz_1x2 ();
  __riscv_ztt_bf16_rtz_1x2_t d = __riscv_ztt_madd_ew_x_bf16_rtz_1x2_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_bf16_rdn (__bf16 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t d = __riscv_ztt_madd_ew_x_bf16_rdn_1x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_bf16_rup (float c)
{
  __riscv_ztt_bf16_rup_1x2_t b = __riscv_ztt_mzero_m_bf16_rup_1x2 ();
  __riscv_ztt_bf16_rup_1x2_t d = __riscv_ztt_madd_ew_x_bf16_rup_1x2_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_bf16_rmm (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rmm_2x1_t b = __riscv_ztt_mzero_m_bf16_rmm_2x1 ();
  __riscv_ztt_bf16_rmm_2x1_t d = __riscv_ztt_madd_ew_x_bf16_rmm_2x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_bf16_rno (carrier_u8 c)
{
  __riscv_ztt_bf16_rno_1x1_t b = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t d = __riscv_ztt_madd_ew_x_bf16_rno_1x1_u8_rne (b, __riscv_ztt_scalar_make_u8_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_f32_rne (carrier_u16 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_madd_ew_x_f32_rne_1x1_u16_rnu (b, __riscv_ztt_scalar_make_u16_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_f32_rtz (carrier_i32 c)
{
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_madd_ew_x_f32_rtz_1x1_i32_rod (b, __riscv_ztt_scalar_make_i32_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_f32_rdn (carrier_i64 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_madd_ew_x_f32_rdn_1x1_i64_rdn (b, __riscv_ztt_scalar_from_bits_i64_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_f32_rup (carrier_i128 c)
{
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_madd_ew_x_f32_rup_1x1_i128_rne (b, __riscv_ztt_scalar_from_bits_i128_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_f32_rmm (carrier_i8 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_madd_ew_x_f32_rmm_1x1_i8_rnu_sat (b, __riscv_ztt_scalar_make_i8_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_madd_f32_rno (carrier_u8 c)
{
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_madd_ew_x_f32_rno_1x1_u8_rod_sat (b, __riscv_ztt_scalar_make_u8_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i4_rnu (carrier_u8 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i4_rnu_1x2_t d = __riscv_ztt_msub_ew_x_i4_rnu_1x2_u8_rne (b, __riscv_ztt_scalar_make_u8_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i4_rne (float c)
{
  __riscv_ztt_i4_rne_8x1_t b = __riscv_ztt_mzero_m_i4_rne_8x1 ();
  __riscv_ztt_i4_rne_8x1_t d = __riscv_ztt_msub_ew_x_i4_rne_8x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i4_rdn (carrier_i32 c)
{
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_i4_rdn_1x2_t d = __riscv_ztt_msub_ew_x_i4_rdn_1x2_i32_rod (b, __riscv_ztt_scalar_make_i32_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i4_rod (_Float16 c)
{
  __riscv_ztt_i4_rod_4x1_t b = __riscv_ztt_mzero_m_i4_rod_4x1 ();
  __riscv_ztt_i4_rod_4x1_t d = __riscv_ztt_msub_ew_x_i4_rod_4x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u4_rnu (carrier_i128 c)
{
  __riscv_ztt_f16_rmm_1x2_t b = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_u4_rnu_1x2_t d = __riscv_ztt_msub_ew_x_u4_rnu_1x2_i128_rne (b, __riscv_ztt_scalar_from_bits_i128_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u4_rne (float c)
{
  __riscv_ztt_u4_rne_2x1_t b = __riscv_ztt_mzero_m_u4_rne_2x1 ();
  __riscv_ztt_u4_rne_2x1_t d = __riscv_ztt_msub_ew_x_u4_rne_2x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u4_rdn (carrier_u8 c)
{
  __riscv_ztt_bf16_rne_1x2_t b = __riscv_ztt_mzero_m_bf16_rne_1x2 ();
  __riscv_ztt_u4_rdn_1x2_t d = __riscv_ztt_msub_ew_x_u4_rdn_1x2_u8_rod_sat (b, __riscv_ztt_scalar_make_u8_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u4_rod (__bf16 c)
{
  __riscv_ztt_u4_rod_8x1_t b = __riscv_ztt_mzero_m_u4_rod_8x1 ();
  __riscv_ztt_u4_rod_8x1_t d = __riscv_ztt_msub_ew_x_u4_rod_8x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i8_rnu (carrier_u32 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t d = __riscv_ztt_msub_ew_x_i8_rnu_1x1_u32_rne_sat (b, __riscv_ztt_scalar_make_u32_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i8_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rne_2x1_t b = __riscv_ztt_mzero_m_i8_rne_2x1 ();
  __riscv_ztt_i8_rne_2x1_t d = __riscv_ztt_msub_ew_x_i8_rne_2x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i8_rdn (carrier_i128 c)
{
  __riscv_ztt_bf16_rmm_1x2_t b = __riscv_ztt_mzero_m_bf16_rmm_1x2 ();
  __riscv_ztt_i8_rdn_1x2_t d = __riscv_ztt_msub_ew_x_i8_rdn_1x2_i128_rod_sat (b, __riscv_ztt_scalar_from_bits_i128_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i8_rod (__bf16 c)
{
  __riscv_ztt_i8_rod_1x1_t b = __riscv_ztt_mzero_m_i8_rod_1x1 ();
  __riscv_ztt_i8_rod_1x1_t d = __riscv_ztt_msub_ew_x_i8_rod_1x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u8_rnu (__bf16 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t d = __riscv_ztt_msub_ew_x_u8_rnu_1x1_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u8_rne (_Float16 c)
{
  __riscv_ztt_u8_rne_4x1_t b = __riscv_ztt_mzero_m_u8_rne_4x1 ();
  __riscv_ztt_u8_rne_4x1_t d = __riscv_ztt_msub_ew_x_u8_rne_4x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u8_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t d = __riscv_ztt_msub_ew_x_u8_rdn_1x1_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u8_rod (float c)
{
  __riscv_ztt_u8_rod_2x1_t b = __riscv_ztt_mzero_m_u8_rod_2x1 ();
  __riscv_ztt_u8_rod_2x1_t d = __riscv_ztt_msub_ew_x_u8_rod_2x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i16_rnu (carrier_u16 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t d = __riscv_ztt_msub_ew_x_i16_rnu_1x1_u16_rne (b, __riscv_ztt_scalar_make_u16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i16_rne (_Float16 c)
{
  __riscv_ztt_i16_rne_1x1_t b = __riscv_ztt_mzero_m_i16_rne_1x1 ();
  __riscv_ztt_i16_rne_1x1_t d = __riscv_ztt_msub_ew_x_i16_rne_1x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i16_rdn (carrier_i64 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i16_rdn_1x2_t d = __riscv_ztt_msub_ew_x_i16_rdn_1x2_i64_rod (b, __riscv_ztt_scalar_from_bits_i64_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i16_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rod_2x1_t b = __riscv_ztt_mzero_m_i16_rod_2x1 ();
  __riscv_ztt_i16_rod_2x1_t d = __riscv_ztt_msub_ew_x_i16_rod_2x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u16_rnu (carrier_i8 c)
{
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_u16_rnu_1x1_t d = __riscv_ztt_msub_ew_x_u16_rnu_1x1_i8_rne_sat (b, __riscv_ztt_scalar_make_i8_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u16_rne (__bf16 c)
{
  __riscv_ztt_u16_rne_2x1_t b = __riscv_ztt_mzero_m_u16_rne_2x1 ();
  __riscv_ztt_u16_rne_2x1_t d = __riscv_ztt_msub_ew_x_u16_rne_2x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u16_rdn (carrier_u16 c)
{
  __riscv_ztt_f16_rmm_1x2_t b = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_u16_rdn_1x2_t d = __riscv_ztt_msub_ew_x_u16_rdn_1x2_u16_rod_sat (b, __riscv_ztt_scalar_make_u16_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u16_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rod_1x1_t b = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_u16_rod_1x1_t d = __riscv_ztt_msub_ew_x_u16_rod_1x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i32_rnu (carrier_u64 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_msub_ew_x_i32_rnu_1x1_u64_rne_sat (b, __riscv_ztt_scalar_from_bits_u64_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i32_rne (float c)
{
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_msub_ew_x_i32_rne_1x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i32_rdn (_Float16 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_msub_ew_x_i32_rdn_1x1_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i32_rod (_Float16 c)
{
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_msub_ew_x_i32_rod_1x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u32_rnu (float c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_msub_ew_x_u32_rnu_1x1_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u32_rne (float c)
{
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_msub_ew_x_u32_rne_1x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u32_rdn (carrier_u8 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_msub_ew_x_u32_rdn_1x1_u8_rod (b, __riscv_ztt_scalar_make_u8_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u32_rod (__bf16 c)
{
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_msub_ew_x_u32_rod_1x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i4_rnu_sat (carrier_u32 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i4_rnu_sat_1x2_t d = __riscv_ztt_msub_ew_x_i4_rnu_sat_1x2_u32_rne (b, __riscv_ztt_scalar_make_u32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i4_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rne_sat_4x1_t b = __riscv_ztt_mzero_m_i4_rne_sat_4x1 ();
  __riscv_ztt_i4_rne_sat_4x1_t d = __riscv_ztt_msub_ew_x_i4_rne_sat_4x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i4_rdn_sat (carrier_i128 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i4_rdn_sat_1x2_t d = __riscv_ztt_msub_ew_x_i4_rdn_sat_1x2_i128_rod (b, __riscv_ztt_scalar_from_bits_i128_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i4_rod_sat (__bf16 c)
{
  __riscv_ztt_i4_rod_sat_2x1_t b = __riscv_ztt_mzero_m_i4_rod_sat_2x1 ();
  __riscv_ztt_i4_rod_sat_2x1_t d = __riscv_ztt_msub_ew_x_i4_rod_sat_2x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u4_rnu_sat (carrier_i16 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_u4_rnu_sat_1x2_t d = __riscv_ztt_msub_ew_x_u4_rnu_sat_1x2_i16_rne_sat (b, __riscv_ztt_scalar_make_i16_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u4_rne_sat (_Float16 c)
{
  __riscv_ztt_u4_rne_sat_8x1_t b = __riscv_ztt_mzero_m_u4_rne_sat_8x1 ();
  __riscv_ztt_u4_rne_sat_8x1_t d = __riscv_ztt_msub_ew_x_u4_rne_sat_8x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u4_rdn_sat (carrier_u32 c)
{
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_u4_rdn_sat_1x2_t d = __riscv_ztt_msub_ew_x_u4_rdn_sat_1x2_u32_rod_sat (b, __riscv_ztt_scalar_make_u32_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u4_rod_sat (float c)
{
  __riscv_ztt_u4_rod_sat_4x1_t b = __riscv_ztt_mzero_m_u4_rod_sat_4x1 ();
  __riscv_ztt_u4_rod_sat_4x1_t d = __riscv_ztt_msub_ew_x_u4_rod_sat_4x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i8_rnu_sat (carrier_u128 c)
{
  __riscv_ztt_f16_rmm_1x2_t b = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_i8_rnu_sat_1x2_t d = __riscv_ztt_msub_ew_x_i8_rnu_sat_1x2_u128_rne_sat (b, __riscv_ztt_scalar_from_bits_u128_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i8_rne_sat (_Float16 c)
{
  __riscv_ztt_i8_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rne_sat_1x1 ();
  __riscv_ztt_i8_rne_sat_1x1_t d = __riscv_ztt_msub_ew_x_i8_rne_sat_1x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i8_rdn_sat (__bf16 c)
{
  __riscv_ztt_bf16_rne_1x2_t b = __riscv_ztt_mzero_m_bf16_rne_1x2 ();
  __riscv_ztt_i8_rdn_sat_1x2_t d = __riscv_ztt_msub_ew_x_i8_rdn_sat_1x2_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i8_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rod_sat_4x1_t b = __riscv_ztt_mzero_m_i8_rod_sat_4x1 ();
  __riscv_ztt_i8_rod_sat_4x1_t d = __riscv_ztt_msub_ew_x_i8_rod_sat_4x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u8_rnu_sat (carrier_i8 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_u8_rnu_sat_1x1_t d = __riscv_ztt_msub_ew_x_u8_rnu_sat_1x1_i8_rne (b, __riscv_ztt_scalar_make_i8_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u8_rne_sat (__bf16 c)
{
  __riscv_ztt_u8_rne_sat_2x1_t b = __riscv_ztt_mzero_m_u8_rne_sat_2x1 ();
  __riscv_ztt_u8_rne_sat_2x1_t d = __riscv_ztt_msub_ew_x_u8_rne_sat_2x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u8_rdn_sat (carrier_u16 c)
{
  __riscv_ztt_bf16_rmm_1x2_t b = __riscv_ztt_mzero_m_bf16_rmm_1x2 ();
  __riscv_ztt_u8_rdn_sat_1x2_t d = __riscv_ztt_msub_ew_x_u8_rdn_sat_1x2_u16_rod (b, __riscv_ztt_scalar_make_u16_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u8_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rod_sat_1x1 ();
  __riscv_ztt_u8_rod_sat_1x1_t d = __riscv_ztt_msub_ew_x_u8_rod_sat_1x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i16_rnu_sat (carrier_u64 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t d = __riscv_ztt_msub_ew_x_i16_rnu_sat_1x1_u64_rne (b, __riscv_ztt_scalar_from_bits_u64_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i16_rne_sat (float c)
{
  __riscv_ztt_i16_rne_sat_2x1_t b = __riscv_ztt_mzero_m_i16_rne_sat_2x1 ();
  __riscv_ztt_i16_rne_sat_2x1_t d = __riscv_ztt_msub_ew_x_i16_rne_sat_2x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i16_rdn_sat (carrier_i8 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t d = __riscv_ztt_msub_ew_x_i16_rdn_sat_1x1_i8_rod_sat (b, __riscv_ztt_scalar_make_i8_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i16_rod_sat (_Float16 c)
{
  __riscv_ztt_i16_rod_sat_2x1_t b = __riscv_ztt_mzero_m_i16_rod_sat_2x1 ();
  __riscv_ztt_i16_rod_sat_2x1_t d = __riscv_ztt_msub_ew_x_i16_rod_sat_2x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u16_rnu_sat (carrier_i32 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t d = __riscv_ztt_msub_ew_x_u16_rnu_sat_1x1_i32_rne_sat (b, __riscv_ztt_scalar_make_i32_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u16_rne_sat (float c)
{
  __riscv_ztt_u16_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rne_sat_1x1 ();
  __riscv_ztt_u16_rne_sat_1x1_t d = __riscv_ztt_msub_ew_x_u16_rne_sat_1x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u16_rdn_sat (carrier_u64 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_u16_rdn_sat_1x2_t d = __riscv_ztt_msub_ew_x_u16_rdn_sat_1x2_u64_rod_sat (b, __riscv_ztt_scalar_from_bits_u64_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u16_rod_sat (__bf16 c)
{
  __riscv_ztt_u16_rod_sat_2x1_t b = __riscv_ztt_mzero_m_u16_rod_sat_2x1 ();
  __riscv_ztt_u16_rod_sat_2x1_t d = __riscv_ztt_msub_ew_x_u16_rod_sat_2x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i32_rnu_sat (_Float16 c)
{
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_msub_ew_x_i32_rnu_sat_1x1_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i32_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_msub_ew_x_i32_rne_sat_1x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i32_rdn_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_msub_ew_x_i32_rdn_sat_1x1_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_i32_rod_sat (__bf16 c)
{
  __riscv_ztt_i32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_msub_ew_x_i32_rod_sat_1x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u32_rnu_sat (carrier_i16 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_msub_ew_x_u32_rnu_sat_1x1_i16_rne (b, __riscv_ztt_scalar_make_i16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u32_rne_sat (_Float16 c)
{
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_msub_ew_x_u32_rne_sat_1x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u32_rdn_sat (carrier_u32 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_msub_ew_x_u32_rdn_sat_1x1_u32_rod (b, __riscv_ztt_scalar_make_u32_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_u32_rod_sat (float c)
{
  __riscv_ztt_u32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_msub_ew_x_u32_rod_sat_1x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_f16_rne (carrier_u128 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_f16_rne_1x2_t d = __riscv_ztt_msub_ew_x_f16_rne_1x2_u128_rne (b, __riscv_ztt_scalar_from_bits_u128_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_f16_rtz (carrier_u8 c)
{
  __riscv_ztt_f16_rtz_1x1_t b = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_msub_ew_x_f16_rtz_1x1_u8_rnu_sat (b, __riscv_ztt_scalar_make_u8_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_f16_rdn (carrier_i16 c)
{
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_f16_rdn_1x2_t d = __riscv_ztt_msub_ew_x_f16_rdn_1x2_i16_rod_sat (b, __riscv_ztt_scalar_make_i16_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_f16_rup (carrier_i32 c)
{
  __riscv_ztt_f16_rup_2x1_t b = __riscv_ztt_mzero_m_f16_rup_2x1 ();
  __riscv_ztt_f16_rup_2x1_t d = __riscv_ztt_msub_ew_x_f16_rup_2x1_i32_rdn_sat (b, __riscv_ztt_scalar_make_i32_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_f16_rmm (carrier_i64 c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_msub_ew_x_f16_rmm_1x1_i64_rne_sat (b, __riscv_ztt_scalar_from_bits_i64_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_f16_rno (carrier_i128 c)
{
  __riscv_ztt_f16_rno_2x1_t b = __riscv_ztt_mzero_m_f16_rno_2x1 ();
  __riscv_ztt_f16_rno_2x1_t d = __riscv_ztt_msub_ew_x_f16_rno_2x1_i128_rnu_sat (b, __riscv_ztt_scalar_from_bits_i128_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_bf16_rne (carrier_u128 c)
{
  __riscv_ztt_bf16_rne_1x2_t b = __riscv_ztt_mzero_m_bf16_rne_1x2 ();
  __riscv_ztt_bf16_rne_1x2_t d = __riscv_ztt_msub_ew_x_bf16_rne_1x2_u128_rod_sat (b, __riscv_ztt_scalar_from_bits_u128_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_bf16_rtz (__bf16 c)
{
  __riscv_ztt_bf16_rtz_1x1_t b = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t d = __riscv_ztt_msub_ew_x_bf16_rtz_1x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_bf16_rdn (float c)
{
  __riscv_ztt_bf16_rdn_1x2_t b = __riscv_ztt_mzero_m_bf16_rdn_1x2 ();
  __riscv_ztt_bf16_rdn_1x2_t d = __riscv_ztt_msub_ew_x_bf16_rdn_1x2_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_bf16_rup (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rup_2x1_t b = __riscv_ztt_mzero_m_bf16_rup_2x1 ();
  __riscv_ztt_bf16_rup_2x1_t d = __riscv_ztt_msub_ew_x_bf16_rup_2x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_bf16_rmm (carrier_i8 c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_bf16_rmm_1x1_t d = __riscv_ztt_msub_ew_x_bf16_rmm_1x1_i8_rod (b, __riscv_ztt_scalar_make_i8_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_bf16_rno (carrier_i16 c)
{
  __riscv_ztt_bf16_rno_2x1_t b = __riscv_ztt_mzero_m_bf16_rno_2x1 ();
  __riscv_ztt_bf16_rno_2x1_t d = __riscv_ztt_msub_ew_x_bf16_rno_2x1_i16_rdn (b, __riscv_ztt_scalar_make_i16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_f32_rne (carrier_i32 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_msub_ew_x_f32_rne_1x1_i32_rne (b, __riscv_ztt_scalar_make_i32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_f32_rtz (carrier_i64 c)
{
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_msub_ew_x_f32_rtz_1x1_i64_rnu (b, __riscv_ztt_scalar_from_bits_i64_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_f32_rdn (carrier_u64 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_msub_ew_x_f32_rdn_1x1_u64_rod (b, __riscv_ztt_scalar_from_bits_u64_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_f32_rup (carrier_u128 c)
{
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_msub_ew_x_f32_rup_1x1_u128_rdn (b, __riscv_ztt_scalar_from_bits_u128_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_f32_rmm (carrier_u8 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_msub_ew_x_f32_rmm_1x1_u8_rne_sat (b, __riscv_ztt_scalar_make_u8_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msub_f32_rno (carrier_u16 c)
{
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_msub_ew_x_f32_rno_1x1_u16_rnu_sat (b, __riscv_ztt_scalar_make_u16_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i4_rnu (carrier_i16 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i4_rnu_2x1_t d = __riscv_ztt_mmul_ew_x_i4_rnu_2x1_i16_rdn (b, __riscv_ztt_scalar_make_i16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i4_rne (float c)
{
  __riscv_ztt_i4_rne_1x2_t b = __riscv_ztt_mzero_m_i4_rne_1x2 ();
  __riscv_ztt_i4_rne_1x2_t d = __riscv_ztt_mmul_ew_x_i4_rne_1x2_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i4_rdn (carrier_i64 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_i4_rdn_2x1_t d = __riscv_ztt_mmul_ew_x_i4_rdn_2x1_i64_rnu (b, __riscv_ztt_scalar_from_bits_i64_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i4_rod (__bf16 c)
{
  __riscv_ztt_i4_rod_1x8_t b = __riscv_ztt_mzero_m_i4_rod_1x8 ();
  __riscv_ztt_i4_rod_1x8_t d = __riscv_ztt_mmul_ew_x_i4_rod_1x8_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u4_rnu (carrier_u128 c)
{
  __riscv_ztt_f16_rmm_2x1_t b = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_u4_rnu_2x1_t d = __riscv_ztt_mmul_ew_x_u4_rnu_2x1_u128_rdn (b, __riscv_ztt_scalar_from_bits_u128_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u4_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rne_1x4_t b = __riscv_ztt_mzero_m_u4_rne_1x4 ();
  __riscv_ztt_u4_rne_1x4_t d = __riscv_ztt_mmul_ew_x_u4_rne_1x4_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u4_rdn (carrier_u16 c)
{
  __riscv_ztt_bf16_rne_2x1_t b = __riscv_ztt_mzero_m_bf16_rne_2x1 ();
  __riscv_ztt_u4_rdn_2x1_t d = __riscv_ztt_mmul_ew_x_u4_rdn_2x1_u16_rnu_sat (b, __riscv_ztt_scalar_make_u16_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u4_rod (__bf16 c)
{
  __riscv_ztt_u4_rod_1x2_t b = __riscv_ztt_mzero_m_u4_rod_1x2 ();
  __riscv_ztt_u4_rod_1x2_t d = __riscv_ztt_mmul_ew_x_u4_rod_1x2_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i8_rnu (carrier_i64 c)
{
  __riscv_ztt_bf16_rdn_2x1_t b = __riscv_ztt_mzero_m_bf16_rdn_2x1 ();
  __riscv_ztt_i8_rnu_2x1_t d = __riscv_ztt_mmul_ew_x_i8_rnu_2x1_i64_rdn_sat (b, __riscv_ztt_scalar_from_bits_i64_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i8_rne (_Float16 c)
{
  __riscv_ztt_i8_rne_1x4_t b = __riscv_ztt_mzero_m_i8_rne_1x4 ();
  __riscv_ztt_i8_rne_1x4_t d = __riscv_ztt_mmul_ew_x_i8_rne_1x4_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i8_rdn (_Float16 c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_i8_rdn_1x1_t d = __riscv_ztt_mmul_ew_x_i8_rdn_1x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i8_rod (float c)
{
  __riscv_ztt_i8_rod_1x2_t b = __riscv_ztt_mzero_m_i8_rod_1x2 ();
  __riscv_ztt_i8_rod_1x2_t d = __riscv_ztt_mmul_ew_x_i8_rod_1x2_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u8_rnu (float c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t d = __riscv_ztt_mmul_ew_x_u8_rnu_1x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u8_rne (_Float16 c)
{
  __riscv_ztt_u8_rne_1x1_t b = __riscv_ztt_mzero_m_u8_rne_1x1 ();
  __riscv_ztt_u8_rne_1x1_t d = __riscv_ztt_mmul_ew_x_u8_rne_1x1_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u8_rdn (carrier_u8 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t d = __riscv_ztt_mmul_ew_x_u8_rdn_1x1_u8_rnu (b, __riscv_ztt_scalar_make_u8_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u8_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rod_1x4_t b = __riscv_ztt_mzero_m_u8_rod_1x4 ();
  __riscv_ztt_u8_rod_1x4_t d = __riscv_ztt_mmul_ew_x_u8_rod_1x4_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i16_rnu (carrier_i32 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t d = __riscv_ztt_mmul_ew_x_i16_rnu_1x1_i32_rdn (b, __riscv_ztt_scalar_make_i32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i16_rne (__bf16 c)
{
  __riscv_ztt_i16_rne_1x2_t b = __riscv_ztt_mzero_m_i16_rne_1x2 ();
  __riscv_ztt_i16_rne_1x2_t d = __riscv_ztt_mmul_ew_x_i16_rne_1x2_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i16_rdn (carrier_i128 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i16_rdn_2x1_t d = __riscv_ztt_mmul_ew_x_i16_rdn_2x1_i128_rnu (b, __riscv_ztt_scalar_from_bits_i128_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i16_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rod_1x1_t b = __riscv_ztt_mzero_m_i16_rod_1x1 ();
  __riscv_ztt_i16_rod_1x1_t d = __riscv_ztt_mmul_ew_x_i16_rod_1x1_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u16_rnu (carrier_u8 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_u16_rnu_2x1_t d = __riscv_ztt_mmul_ew_x_u16_rnu_2x1_u8_rdn_sat (b, __riscv_ztt_scalar_make_u8_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u16_rne (float c)
{
  __riscv_ztt_u16_rne_1x2_t b = __riscv_ztt_mzero_m_u16_rne_1x2 ();
  __riscv_ztt_u16_rne_1x2_t d = __riscv_ztt_mmul_ew_x_u16_rne_1x2_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u16_rdn (carrier_u32 c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_u16_rdn_1x1_t d = __riscv_ztt_mmul_ew_x_u16_rdn_1x1_u32_rnu_sat (b, __riscv_ztt_scalar_make_u32_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u16_rod (_Float16 c)
{
  __riscv_ztt_u16_rod_1x2_t b = __riscv_ztt_mzero_m_u16_rod_1x2 ();
  __riscv_ztt_u16_rod_1x2_t d = __riscv_ztt_mmul_ew_x_u16_rod_1x2_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i32_rnu (carrier_i128 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mmul_ew_x_i32_rnu_1x1_i128_rdn_sat (b, __riscv_ztt_scalar_from_bits_i128_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i32_rne (float c)
{
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_mmul_ew_x_i32_rne_1x1_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i32_rdn (__bf16 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_mmul_ew_x_i32_rdn_1x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i32_rod (__bf16 c)
{
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mmul_ew_x_i32_rod_1x1_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u32_rnu (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mmul_ew_x_u32_rnu_1x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u32_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_mmul_ew_x_u32_rne_1x1_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u32_rdn (carrier_u16 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mmul_ew_x_u32_rdn_1x1_u16_rnu (b, __riscv_ztt_scalar_make_u16_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u32_rod (__bf16 c)
{
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_mmul_ew_x_u32_rod_1x1_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i4_rnu_sat (carrier_i64 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i4_rnu_sat_2x1_t d = __riscv_ztt_mmul_ew_x_i4_rnu_sat_2x1_i64_rdn (b, __riscv_ztt_scalar_from_bits_i64_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i4_rne_sat (_Float16 c)
{
  __riscv_ztt_i4_rne_sat_1x8_t b = __riscv_ztt_mzero_m_i4_rne_sat_1x8 ();
  __riscv_ztt_i4_rne_sat_1x8_t d = __riscv_ztt_mmul_ew_x_i4_rne_sat_1x8_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i4_rdn_sat (carrier_i8 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i4_rdn_sat_2x1_t d = __riscv_ztt_mmul_ew_x_i4_rdn_sat_2x1_i8_rnu_sat (b, __riscv_ztt_scalar_make_i8_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i4_rod_sat (float c)
{
  __riscv_ztt_i4_rod_sat_1x4_t b = __riscv_ztt_mzero_m_i4_rod_sat_1x4 ();
  __riscv_ztt_i4_rod_sat_1x4_t d = __riscv_ztt_mmul_ew_x_i4_rod_sat_1x4_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u4_rnu_sat (carrier_u16 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_u4_rnu_sat_2x1_t d = __riscv_ztt_mmul_ew_x_u4_rnu_sat_2x1_u16_rdn_sat (b, __riscv_ztt_scalar_make_u16_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u4_rne_sat (_Float16 c)
{
  __riscv_ztt_u4_rne_sat_1x2_t b = __riscv_ztt_mzero_m_u4_rne_sat_1x2 ();
  __riscv_ztt_u4_rne_sat_1x2_t d = __riscv_ztt_mmul_ew_x_u4_rne_sat_1x2_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u4_rdn_sat (carrier_u64 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_u4_rdn_sat_2x1_t d = __riscv_ztt_mmul_ew_x_u4_rdn_sat_2x1_u64_rnu_sat (b, __riscv_ztt_scalar_from_bits_u64_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u4_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rod_sat_1x8_t b = __riscv_ztt_mzero_m_u4_rod_sat_1x8 ();
  __riscv_ztt_u4_rod_sat_1x8_t d = __riscv_ztt_mmul_ew_x_u4_rod_sat_1x8_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i8_rnu_sat (_Float16 c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t d = __riscv_ztt_mmul_ew_x_i8_rnu_sat_1x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i8_rne_sat (__bf16 c)
{
  __riscv_ztt_i8_rne_sat_1x2_t b = __riscv_ztt_mzero_m_i8_rne_sat_1x2 ();
  __riscv_ztt_i8_rne_sat_1x2_t d = __riscv_ztt_mmul_ew_x_i8_rne_sat_1x2_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i8_rdn_sat (float c)
{
  __riscv_ztt_bf16_rne_2x1_t b = __riscv_ztt_mzero_m_bf16_rne_2x1 ();
  __riscv_ztt_i8_rdn_sat_2x1_t d = __riscv_ztt_mmul_ew_x_i8_rdn_sat_2x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i8_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rod_sat_1x1 ();
  __riscv_ztt_i8_rod_sat_1x1_t d = __riscv_ztt_mmul_ew_x_i8_rod_sat_1x1_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u8_rnu_sat (carrier_u8 c)
{
  __riscv_ztt_bf16_rdn_2x1_t b = __riscv_ztt_mzero_m_bf16_rdn_2x1 ();
  __riscv_ztt_u8_rnu_sat_2x1_t d = __riscv_ztt_mmul_ew_x_u8_rnu_sat_2x1_u8_rdn (b, __riscv_ztt_scalar_make_u8_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u8_rne_sat (float c)
{
  __riscv_ztt_u8_rne_sat_1x4_t b = __riscv_ztt_mzero_m_u8_rne_sat_1x4 ();
  __riscv_ztt_u8_rne_sat_1x4_t d = __riscv_ztt_mmul_ew_x_u8_rne_sat_1x4_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u8_rdn_sat (carrier_u32 c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_u8_rdn_sat_1x1_t d = __riscv_ztt_mmul_ew_x_u8_rdn_sat_1x1_u32_rnu (b, __riscv_ztt_scalar_make_u32_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u8_rod_sat (_Float16 c)
{
  __riscv_ztt_u8_rod_sat_1x2_t b = __riscv_ztt_mzero_m_u8_rod_sat_1x2 ();
  __riscv_ztt_u8_rod_sat_1x2_t d = __riscv_ztt_mmul_ew_x_u8_rod_sat_1x2_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i16_rnu_sat (carrier_i128 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t d = __riscv_ztt_mmul_ew_x_i16_rnu_sat_1x1_i128_rdn (b, __riscv_ztt_scalar_from_bits_i128_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i16_rne_sat (float c)
{
  __riscv_ztt_i16_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rne_sat_1x1 ();
  __riscv_ztt_i16_rne_sat_1x1_t d = __riscv_ztt_mmul_ew_x_i16_rne_sat_1x1_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i16_rdn_sat (carrier_i16 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t d = __riscv_ztt_mmul_ew_x_i16_rdn_sat_1x1_i16_rnu_sat (b, __riscv_ztt_scalar_make_i16_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i16_rod_sat (__bf16 c)
{
  __riscv_ztt_i16_rod_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rod_sat_1x2 ();
  __riscv_ztt_i16_rod_sat_1x2_t d = __riscv_ztt_mmul_ew_x_i16_rod_sat_1x2_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u16_rnu_sat (carrier_u32 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t d = __riscv_ztt_mmul_ew_x_u16_rnu_sat_1x1_u32_rdn_sat (b, __riscv_ztt_scalar_make_u32_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u16_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rne_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rne_sat_1x2 ();
  __riscv_ztt_u16_rne_sat_1x2_t d = __riscv_ztt_mmul_ew_x_u16_rne_sat_1x2_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u16_rdn_sat (carrier_u128 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_u16_rdn_sat_2x1_t d = __riscv_ztt_mmul_ew_x_u16_rdn_sat_2x1_u128_rnu_sat (b, __riscv_ztt_scalar_from_bits_u128_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u16_rod_sat (__bf16 c)
{
  __riscv_ztt_u16_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rod_sat_1x1 ();
  __riscv_ztt_u16_rod_sat_1x1_t d = __riscv_ztt_mmul_ew_x_u16_rod_sat_1x1_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i32_rnu_sat (__bf16 c)
{
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_mmul_ew_x_i32_rnu_sat_1x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i32_rne_sat (_Float16 c)
{
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_mmul_ew_x_i32_rne_sat_1x1_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i32_rdn_sat (carrier_i8 c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mmul_ew_x_i32_rdn_sat_1x1_i8_rnu (b, __riscv_ztt_scalar_make_i8_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_i32_rod_sat (float c)
{
  __riscv_ztt_i32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_mmul_ew_x_i32_rod_sat_1x1_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u32_rnu_sat (carrier_u16 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_mmul_ew_x_u32_rnu_sat_1x1_u16_rdn (b, __riscv_ztt_scalar_make_u16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u32_rne_sat (_Float16 c)
{
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mmul_ew_x_u32_rne_sat_1x1_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u32_rdn_sat (carrier_u64 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_mmul_ew_x_u32_rdn_sat_1x1_u64_rnu (b, __riscv_ztt_scalar_from_bits_u64_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_u32_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_mmul_ew_x_u32_rod_sat_1x1_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_f16_rne (carrier_i8 c)
{
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_f16_rne_1x1_t d = __riscv_ztt_mmul_ew_x_f16_rne_1x1_i8_rdn_sat (b, __riscv_ztt_scalar_make_i8_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_f16_rtz (carrier_i16 c)
{
  __riscv_ztt_f16_rtz_1x2_t b = __riscv_ztt_mzero_m_f16_rtz_1x2 ();
  __riscv_ztt_f16_rtz_1x2_t d = __riscv_ztt_mmul_ew_x_f16_rtz_1x2_i16_rne_sat (b, __riscv_ztt_scalar_make_i16_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_f16_rdn (carrier_i32 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_f16_rdn_2x1_t d = __riscv_ztt_mmul_ew_x_f16_rdn_2x1_i32_rnu_sat (b, __riscv_ztt_scalar_make_i32_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_f16_rup (carrier_u32 c)
{
  __riscv_ztt_f16_rup_1x1_t b = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_f16_rup_1x1_t d = __riscv_ztt_mmul_ew_x_f16_rup_1x1_u32_rod_sat (b, __riscv_ztt_scalar_make_u32_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_f16_rmm (carrier_u64 c)
{
  __riscv_ztt_f16_rmm_2x1_t b = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_f16_rmm_2x1_t d = __riscv_ztt_mmul_ew_x_f16_rmm_2x1_u64_rdn_sat (b, __riscv_ztt_scalar_from_bits_u64_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_f16_rno (carrier_u128 c)
{
  __riscv_ztt_f16_rno_1x2_t b = __riscv_ztt_mzero_m_f16_rno_1x2 ();
  __riscv_ztt_f16_rno_1x2_t d = __riscv_ztt_mmul_ew_x_f16_rno_1x2_u128_rne_sat (b, __riscv_ztt_scalar_from_bits_u128_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_bf16_rne (_Float16 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t d = __riscv_ztt_mmul_ew_x_bf16_rne_1x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_bf16_rtz (__bf16 c)
{
  __riscv_ztt_bf16_rtz_1x2_t b = __riscv_ztt_mzero_m_bf16_rtz_1x2 ();
  __riscv_ztt_bf16_rtz_1x2_t d = __riscv_ztt_mmul_ew_x_bf16_rtz_1x2_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_bf16_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rdn_2x1_t b = __riscv_ztt_mzero_m_bf16_rdn_2x1 ();
  __riscv_ztt_bf16_rdn_2x1_t d = __riscv_ztt_mmul_ew_x_bf16_rdn_2x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_bf16_rup (carrier_i8 c)
{
  __riscv_ztt_bf16_rup_1x1_t b = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_bf16_rup_1x1_t d = __riscv_ztt_mmul_ew_x_bf16_rup_1x1_i8_rne (b, __riscv_ztt_scalar_make_i8_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_bf16_rmm (carrier_i16 c)
{
  __riscv_ztt_bf16_rmm_2x1_t b = __riscv_ztt_mzero_m_bf16_rmm_2x1 ();
  __riscv_ztt_bf16_rmm_2x1_t d = __riscv_ztt_mmul_ew_x_bf16_rmm_2x1_i16_rnu (b, __riscv_ztt_scalar_make_i16_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_bf16_rno (carrier_u16 c)
{
  __riscv_ztt_bf16_rno_1x2_t b = __riscv_ztt_mzero_m_bf16_rno_1x2 ();
  __riscv_ztt_bf16_rno_1x2_t d = __riscv_ztt_mmul_ew_x_bf16_rno_1x2_u16_rod (b, __riscv_ztt_scalar_make_u16_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_f32_rne (carrier_u32 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mmul_ew_x_f32_rne_1x1_u32_rdn (b, __riscv_ztt_scalar_make_u32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_f32_rtz (carrier_u64 c)
{
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mmul_ew_x_f32_rtz_1x1_u64_rne (b, __riscv_ztt_scalar_from_bits_u64_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_f32_rdn (carrier_u128 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mmul_ew_x_f32_rdn_1x1_u128_rnu (b, __riscv_ztt_scalar_from_bits_u128_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_f32_rup (carrier_i8 c)
{
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mmul_ew_x_f32_rup_1x1_i8_rod_sat (b, __riscv_ztt_scalar_make_i8_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_f32_rmm (carrier_i16 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mmul_ew_x_f32_rmm_1x1_i16_rdn_sat (b, __riscv_ztt_scalar_make_i16_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmul_f32_rno (carrier_i32 c)
{
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mmul_ew_x_f32_rno_1x1_i32_rne_sat (b, __riscv_ztt_scalar_make_i32_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i4_rnu (carrier_u16 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i4_rnu_1x2_t d = __riscv_ztt_mabsdiff_ew_x_i4_rnu_1x2_u16_rod (b, __riscv_ztt_scalar_make_u16_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i4_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rne_4x1_t b = __riscv_ztt_mzero_m_i4_rne_4x1 ();
  __riscv_ztt_i4_rne_4x1_t d = __riscv_ztt_mabsdiff_ew_x_i4_rne_4x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i4_rdn (carrier_u64 c)
{
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_i4_rdn_1x2_t d = __riscv_ztt_mabsdiff_ew_x_i4_rdn_1x2_u64_rne (b, __riscv_ztt_scalar_from_bits_u64_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i4_rod (float c)
{
  __riscv_ztt_i4_rod_2x1_t b = __riscv_ztt_mzero_m_i4_rod_2x1 ();
  __riscv_ztt_i4_rod_2x1_t d = __riscv_ztt_mabsdiff_ew_x_i4_rod_2x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u4_rnu (carrier_i8 c)
{
  __riscv_ztt_f16_rmm_1x2_t b = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_u4_rnu_1x2_t d = __riscv_ztt_mabsdiff_ew_x_u4_rnu_1x2_i8_rod_sat (b, __riscv_ztt_scalar_make_i8_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u4_rne (_Float16 c)
{
  __riscv_ztt_u4_rne_8x1_t b = __riscv_ztt_mzero_m_u4_rne_8x1 ();
  __riscv_ztt_u4_rne_8x1_t d = __riscv_ztt_mabsdiff_ew_x_u4_rne_8x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u4_rdn (carrier_i32 c)
{
  __riscv_ztt_bf16_rne_1x2_t b = __riscv_ztt_mzero_m_bf16_rne_1x2 ();
  __riscv_ztt_u4_rdn_1x2_t d = __riscv_ztt_mabsdiff_ew_x_u4_rdn_1x2_i32_rne_sat (b, __riscv_ztt_scalar_make_i32_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u4_rod (float c)
{
  __riscv_ztt_u4_rod_4x1_t b = __riscv_ztt_mzero_m_u4_rod_4x1 ();
  __riscv_ztt_u4_rod_4x1_t d = __riscv_ztt_mabsdiff_ew_x_u4_rod_4x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i8_rnu (carrier_u64 c)
{
  __riscv_ztt_bf16_rdn_1x2_t b = __riscv_ztt_mzero_m_bf16_rdn_1x2 ();
  __riscv_ztt_i8_rnu_1x2_t d = __riscv_ztt_mabsdiff_ew_x_i8_rnu_1x2_u64_rod_sat (b, __riscv_ztt_scalar_from_bits_u64_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i8_rne (__bf16 c)
{
  __riscv_ztt_i8_rne_1x1_t b = __riscv_ztt_mzero_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t d = __riscv_ztt_mabsdiff_ew_x_i8_rne_1x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i8_rdn (_Float16 c)
{
  __riscv_ztt_bf16_rmm_1x2_t b = __riscv_ztt_mzero_m_bf16_rmm_1x2 ();
  __riscv_ztt_i8_rdn_1x2_t d = __riscv_ztt_mabsdiff_ew_x_i8_rdn_1x2_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i8_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rod_4x1_t b = __riscv_ztt_mzero_m_i8_rod_4x1 ();
  __riscv_ztt_i8_rod_4x1_t d = __riscv_ztt_mabsdiff_ew_x_i8_rod_4x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u8_rnu (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t d = __riscv_ztt_mabsdiff_ew_x_u8_rnu_1x1_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u8_rne (__bf16 c)
{
  __riscv_ztt_u8_rne_2x1_t b = __riscv_ztt_mzero_m_u8_rne_2x1 ();
  __riscv_ztt_u8_rne_2x1_t d = __riscv_ztt_mabsdiff_ew_x_u8_rne_2x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u8_rdn (carrier_i16 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t d = __riscv_ztt_mabsdiff_ew_x_u8_rdn_1x1_i16_rne (b, __riscv_ztt_scalar_make_i16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u8_rod (_Float16 c)
{
  __riscv_ztt_u8_rod_1x1_t b = __riscv_ztt_mzero_m_u8_rod_1x1 ();
  __riscv_ztt_u8_rod_1x1_t d = __riscv_ztt_mabsdiff_ew_x_u8_rod_1x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i16_rnu (carrier_u32 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t d = __riscv_ztt_mabsdiff_ew_x_i16_rnu_1x1_u32_rod (b, __riscv_ztt_scalar_make_u32_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i16_rne (float c)
{
  __riscv_ztt_i16_rne_2x1_t b = __riscv_ztt_mzero_m_i16_rne_2x1 ();
  __riscv_ztt_i16_rne_2x1_t d = __riscv_ztt_mabsdiff_ew_x_i16_rne_2x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i16_rdn (carrier_u128 c)
{
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_i16_rdn_1x1_t d = __riscv_ztt_mabsdiff_ew_x_i16_rdn_1x1_u128_rne (b, __riscv_ztt_scalar_from_bits_u128_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i16_rod (_Float16 c)
{
  __riscv_ztt_i16_rod_2x1_t b = __riscv_ztt_mzero_m_i16_rod_2x1 ();
  __riscv_ztt_i16_rod_2x1_t d = __riscv_ztt_mabsdiff_ew_x_i16_rod_2x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u16_rnu (carrier_i16 c)
{
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_u16_rnu_1x2_t d = __riscv_ztt_mabsdiff_ew_x_u16_rnu_1x2_i16_rod_sat (b, __riscv_ztt_scalar_make_i16_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u16_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rne_1x1_t b = __riscv_ztt_mzero_m_u16_rne_1x1 ();
  __riscv_ztt_u16_rne_1x1_t d = __riscv_ztt_mabsdiff_ew_x_u16_rne_1x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u16_rdn (carrier_i64 c)
{
  __riscv_ztt_f16_rmm_1x2_t b = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_u16_rdn_1x2_t d = __riscv_ztt_mabsdiff_ew_x_u16_rdn_1x2_i64_rne_sat (b, __riscv_ztt_scalar_from_bits_i64_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u16_rod (__bf16 c)
{
  __riscv_ztt_u16_rod_2x1_t b = __riscv_ztt_mzero_m_u16_rod_2x1 ();
  __riscv_ztt_u16_rod_2x1_t d = __riscv_ztt_mabsdiff_ew_x_u16_rod_2x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i32_rnu (carrier_u128 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mabsdiff_ew_x_i32_rnu_1x1_u128_rod_sat (b, __riscv_ztt_scalar_from_bits_u128_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i32_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_mabsdiff_ew_x_i32_rne_1x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i32_rdn (float c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_mabsdiff_ew_x_i32_rdn_1x1_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i32_rod (float c)
{
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mabsdiff_ew_x_i32_rod_1x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u32_rnu (carrier_i8 c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mabsdiff_ew_x_u32_rnu_1x1_i8_rod (b, __riscv_ztt_scalar_make_i8_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u32_rne (_Float16 c)
{
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_mabsdiff_ew_x_u32_rne_1x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u32_rdn (carrier_i32 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mabsdiff_ew_x_u32_rdn_1x1_i32_rne (b, __riscv_ztt_scalar_make_i32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u32_rod (float c)
{
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_mabsdiff_ew_x_u32_rod_1x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i4_rnu_sat (carrier_u64 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i4_rnu_sat_1x2_t d = __riscv_ztt_mabsdiff_ew_x_i4_rnu_sat_1x2_u64_rod (b, __riscv_ztt_scalar_from_bits_u64_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i4_rne_sat (__bf16 c)
{
  __riscv_ztt_i4_rne_sat_2x1_t b = __riscv_ztt_mzero_m_i4_rne_sat_2x1 ();
  __riscv_ztt_i4_rne_sat_2x1_t d = __riscv_ztt_mabsdiff_ew_x_i4_rne_sat_2x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i4_rdn_sat (carrier_u8 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i4_rdn_sat_1x2_t d = __riscv_ztt_mabsdiff_ew_x_i4_rdn_sat_1x2_u8_rne_sat (b, __riscv_ztt_scalar_make_u8_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i4_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rod_sat_8x1_t b = __riscv_ztt_mzero_m_i4_rod_sat_8x1 ();
  __riscv_ztt_i4_rod_sat_8x1_t d = __riscv_ztt_mabsdiff_ew_x_i4_rod_sat_8x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u4_rnu_sat (carrier_i32 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_u4_rnu_sat_1x2_t d = __riscv_ztt_mabsdiff_ew_x_u4_rnu_sat_1x2_i32_rod_sat (b, __riscv_ztt_scalar_make_i32_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u4_rne_sat (__bf16 c)
{
  __riscv_ztt_u4_rne_sat_4x1_t b = __riscv_ztt_mzero_m_u4_rne_sat_4x1 ();
  __riscv_ztt_u4_rne_sat_4x1_t d = __riscv_ztt_mabsdiff_ew_x_u4_rne_sat_4x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u4_rdn_sat (carrier_i128 c)
{
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_u4_rdn_sat_1x2_t d = __riscv_ztt_mabsdiff_ew_x_u4_rdn_sat_1x2_i128_rne_sat (b, __riscv_ztt_scalar_from_bits_i128_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u4_rod_sat (_Float16 c)
{
  __riscv_ztt_u4_rod_sat_2x1_t b = __riscv_ztt_mzero_m_u4_rod_sat_2x1 ();
  __riscv_ztt_u4_rod_sat_2x1_t d = __riscv_ztt_mabsdiff_ew_x_u4_rod_sat_2x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i8_rnu_sat (__bf16 c)
{
  __riscv_ztt_f16_rmm_1x2_t b = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_i8_rnu_sat_1x2_t d = __riscv_ztt_mabsdiff_ew_x_i8_rnu_sat_1x2_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i8_rne_sat (float c)
{
  __riscv_ztt_i8_rne_sat_4x1_t b = __riscv_ztt_mzero_m_i8_rne_sat_4x1 ();
  __riscv_ztt_i8_rne_sat_4x1_t d = __riscv_ztt_mabsdiff_ew_x_i8_rne_sat_4x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i8_rdn_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_i8_rdn_sat_1x1_t d = __riscv_ztt_mabsdiff_ew_x_i8_rdn_sat_1x1_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i8_rod_sat (_Float16 c)
{
  __riscv_ztt_i8_rod_sat_2x1_t b = __riscv_ztt_mzero_m_i8_rod_sat_2x1 ();
  __riscv_ztt_i8_rod_sat_2x1_t d = __riscv_ztt_mabsdiff_ew_x_i8_rod_sat_2x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u8_rnu_sat (carrier_i16 c)
{
  __riscv_ztt_bf16_rdn_1x2_t b = __riscv_ztt_mzero_m_bf16_rdn_1x2 ();
  __riscv_ztt_u8_rnu_sat_1x2_t d = __riscv_ztt_mabsdiff_ew_x_u8_rnu_sat_1x2_i16_rod (b, __riscv_ztt_scalar_make_i16_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u8_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rne_sat_1x1 ();
  __riscv_ztt_u8_rne_sat_1x1_t d = __riscv_ztt_mabsdiff_ew_x_u8_rne_sat_1x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u8_rdn_sat (carrier_i64 c)
{
  __riscv_ztt_bf16_rmm_1x2_t b = __riscv_ztt_mzero_m_bf16_rmm_1x2 ();
  __riscv_ztt_u8_rdn_sat_1x2_t d = __riscv_ztt_mabsdiff_ew_x_u8_rdn_sat_1x2_i64_rne (b, __riscv_ztt_scalar_from_bits_i64_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u8_rod_sat (__bf16 c)
{
  __riscv_ztt_u8_rod_sat_4x1_t b = __riscv_ztt_mzero_m_u8_rod_sat_4x1 ();
  __riscv_ztt_u8_rod_sat_4x1_t d = __riscv_ztt_mabsdiff_ew_x_u8_rod_sat_4x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i16_rnu_sat (carrier_u128 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t d = __riscv_ztt_mabsdiff_ew_x_i16_rnu_sat_1x1_u128_rod (b, __riscv_ztt_scalar_from_bits_u128_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i16_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rne_sat_2x1_t b = __riscv_ztt_mzero_m_i16_rne_sat_2x1 ();
  __riscv_ztt_i16_rne_sat_2x1_t d = __riscv_ztt_mabsdiff_ew_x_i16_rne_sat_2x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i16_rdn_sat (carrier_u16 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t d = __riscv_ztt_mabsdiff_ew_x_i16_rdn_sat_1x1_u16_rne_sat (b, __riscv_ztt_scalar_make_u16_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i16_rod_sat (float c)
{
  __riscv_ztt_i16_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rod_sat_1x1 ();
  __riscv_ztt_i16_rod_sat_1x1_t d = __riscv_ztt_mabsdiff_ew_x_i16_rod_sat_1x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u16_rnu_sat (carrier_i64 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t d = __riscv_ztt_mabsdiff_ew_x_u16_rnu_sat_1x1_i64_rod_sat (b, __riscv_ztt_scalar_from_bits_i64_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u16_rne_sat (_Float16 c)
{
  __riscv_ztt_u16_rne_sat_2x1_t b = __riscv_ztt_mzero_m_u16_rne_sat_2x1 ();
  __riscv_ztt_u16_rne_sat_2x1_t d = __riscv_ztt_mabsdiff_ew_x_u16_rne_sat_2x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u16_rdn_sat (_Float16 c)
{
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_u16_rdn_sat_1x1_t d = __riscv_ztt_mabsdiff_ew_x_u16_rdn_sat_1x1_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u16_rod_sat (float c)
{
  __riscv_ztt_u16_rod_sat_2x1_t b = __riscv_ztt_mzero_m_u16_rod_sat_2x1 ();
  __riscv_ztt_u16_rod_sat_2x1_t d = __riscv_ztt_mabsdiff_ew_x_u16_rod_sat_2x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i32_rnu_sat (float c)
{
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_mabsdiff_ew_x_i32_rnu_sat_1x1_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i32_rne_sat (__bf16 c)
{
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_mabsdiff_ew_x_i32_rne_sat_1x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i32_rdn_sat (carrier_u8 c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mabsdiff_ew_x_i32_rdn_sat_1x1_u8_rne (b, __riscv_ztt_scalar_make_u8_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_i32_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_mabsdiff_ew_x_i32_rod_sat_1x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u32_rnu_sat (carrier_i32 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_mabsdiff_ew_x_u32_rnu_sat_1x1_i32_rod (b, __riscv_ztt_scalar_make_i32_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u32_rne_sat (__bf16 c)
{
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mabsdiff_ew_x_u32_rne_sat_1x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u32_rdn_sat (carrier_i128 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_mabsdiff_ew_x_u32_rdn_sat_1x1_i128_rne (b, __riscv_ztt_scalar_from_bits_i128_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_u32_rod_sat (_Float16 c)
{
  __riscv_ztt_u32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_mabsdiff_ew_x_u32_rod_sat_1x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_f16_rne (carrier_u8 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_f16_rne_1x2_t d = __riscv_ztt_mabsdiff_ew_x_f16_rne_1x2_u8_rod_sat (b, __riscv_ztt_scalar_make_u8_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_f16_rtz (carrier_u16 c)
{
  __riscv_ztt_f16_rtz_2x1_t b = __riscv_ztt_mzero_m_f16_rtz_2x1 ();
  __riscv_ztt_f16_rtz_2x1_t d = __riscv_ztt_mabsdiff_ew_x_f16_rtz_2x1_u16_rdn_sat (b, __riscv_ztt_scalar_make_u16_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_f16_rdn (carrier_u32 c)
{
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_mabsdiff_ew_x_f16_rdn_1x1_u32_rne_sat (b, __riscv_ztt_scalar_make_u32_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_f16_rup (carrier_u64 c)
{
  __riscv_ztt_f16_rup_2x1_t b = __riscv_ztt_mzero_m_f16_rup_2x1 ();
  __riscv_ztt_f16_rup_2x1_t d = __riscv_ztt_mabsdiff_ew_x_f16_rup_2x1_u64_rnu_sat (b, __riscv_ztt_scalar_from_bits_u64_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_f16_rmm (carrier_i128 c)
{
  __riscv_ztt_f16_rmm_1x2_t b = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_f16_rmm_1x2_t d = __riscv_ztt_mabsdiff_ew_x_f16_rmm_1x2_i128_rod_sat (b, __riscv_ztt_scalar_from_bits_i128_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_f16_rno (_Float16 c)
{
  __riscv_ztt_f16_rno_1x1_t b = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mabsdiff_ew_x_f16_rno_1x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_bf16_rne (__bf16 c)
{
  __riscv_ztt_bf16_rne_1x2_t b = __riscv_ztt_mzero_m_bf16_rne_1x2 ();
  __riscv_ztt_bf16_rne_1x2_t d = __riscv_ztt_mabsdiff_ew_x_bf16_rne_1x2_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_bf16_rtz (float c)
{
  __riscv_ztt_bf16_rtz_2x1_t b = __riscv_ztt_mzero_m_bf16_rtz_2x1 ();
  __riscv_ztt_bf16_rtz_2x1_t d = __riscv_ztt_mabsdiff_ew_x_bf16_rtz_2x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_bf16_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t d = __riscv_ztt_mabsdiff_ew_x_bf16_rdn_1x1_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_bf16_rup (carrier_u8 c)
{
  __riscv_ztt_bf16_rup_2x1_t b = __riscv_ztt_mzero_m_bf16_rup_2x1 ();
  __riscv_ztt_bf16_rup_2x1_t d = __riscv_ztt_mabsdiff_ew_x_bf16_rup_2x1_u8_rdn (b, __riscv_ztt_scalar_make_u8_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_bf16_rmm (carrier_u16 c)
{
  __riscv_ztt_bf16_rmm_1x2_t b = __riscv_ztt_mzero_m_bf16_rmm_1x2 ();
  __riscv_ztt_bf16_rmm_1x2_t d = __riscv_ztt_mabsdiff_ew_x_bf16_rmm_1x2_u16_rne (b, __riscv_ztt_scalar_make_u16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_bf16_rno (carrier_u32 c)
{
  __riscv_ztt_bf16_rno_1x1_t b = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t d = __riscv_ztt_mabsdiff_ew_x_bf16_rno_1x1_u32_rnu (b, __riscv_ztt_scalar_make_u32_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_f32_rne (carrier_i64 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mabsdiff_ew_x_f32_rne_1x1_i64_rod (b, __riscv_ztt_scalar_from_bits_i64_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_f32_rtz (carrier_i128 c)
{
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mabsdiff_ew_x_f32_rtz_1x1_i128_rdn (b, __riscv_ztt_scalar_from_bits_i128_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_f32_rdn (carrier_i8 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mabsdiff_ew_x_f32_rdn_1x1_i8_rne_sat (b, __riscv_ztt_scalar_make_i8_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_f32_rup (carrier_i16 c)
{
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mabsdiff_ew_x_f32_rup_1x1_i16_rnu_sat (b, __riscv_ztt_scalar_make_i16_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_f32_rmm (carrier_u16 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mabsdiff_ew_x_f32_rmm_1x1_u16_rod_sat (b, __riscv_ztt_scalar_make_u16_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mabsdiff_f32_rno (carrier_u32 c)
{
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mabsdiff_ew_x_f32_rno_1x1_u32_rdn_sat (b, __riscv_ztt_scalar_make_u32_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i4_rnu (carrier_u32 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i4_rnu_2x1_t d = __riscv_ztt_mhdiff_ew_x_i4_rnu_2x1_u32_rnu (b, __riscv_ztt_scalar_make_u32_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i4_rne (_Float16 c)
{
  __riscv_ztt_i4_rne_1x8_t b = __riscv_ztt_mzero_m_i4_rne_1x8 ();
  __riscv_ztt_i4_rne_1x8_t d = __riscv_ztt_mhdiff_ew_x_i4_rne_1x8_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i4_rdn (carrier_i128 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_i4_rdn_2x1_t d = __riscv_ztt_mhdiff_ew_x_i4_rdn_2x1_i128_rdn (b, __riscv_ztt_scalar_from_bits_i128_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i4_rod (float c)
{
  __riscv_ztt_i4_rod_1x4_t b = __riscv_ztt_mzero_m_i4_rod_1x4 ();
  __riscv_ztt_i4_rod_1x4_t d = __riscv_ztt_mhdiff_ew_x_i4_rod_1x4_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u4_rnu (carrier_i16 c)
{
  __riscv_ztt_f16_rmm_2x1_t b = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_u4_rnu_2x1_t d = __riscv_ztt_mhdiff_ew_x_u4_rnu_2x1_i16_rnu_sat (b, __riscv_ztt_scalar_make_i16_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u4_rne (__bf16 c)
{
  __riscv_ztt_u4_rne_1x2_t b = __riscv_ztt_mzero_m_u4_rne_1x2 ();
  __riscv_ztt_u4_rne_1x2_t d = __riscv_ztt_mhdiff_ew_x_u4_rne_1x2_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u4_rdn (carrier_u32 c)
{
  __riscv_ztt_bf16_rne_2x1_t b = __riscv_ztt_mzero_m_bf16_rne_2x1 ();
  __riscv_ztt_u4_rdn_2x1_t d = __riscv_ztt_mhdiff_ew_x_u4_rdn_2x1_u32_rdn_sat (b, __riscv_ztt_scalar_make_u32_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u4_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rod_1x8_t b = __riscv_ztt_mzero_m_u4_rod_1x8 ();
  __riscv_ztt_u4_rod_1x8_t d = __riscv_ztt_mhdiff_ew_x_u4_rod_1x8_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i8_rnu (carrier_u128 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t d = __riscv_ztt_mhdiff_ew_x_i8_rnu_1x1_u128_rnu_sat (b, __riscv_ztt_scalar_from_bits_u128_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i8_rne (__bf16 c)
{
  __riscv_ztt_i8_rne_1x2_t b = __riscv_ztt_mzero_m_i8_rne_1x2 ();
  __riscv_ztt_i8_rne_1x2_t d = __riscv_ztt_mhdiff_ew_x_i8_rne_1x2_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i8_rdn (__bf16 c)
{
  __riscv_ztt_bf16_rmm_2x1_t b = __riscv_ztt_mzero_m_bf16_rmm_2x1 ();
  __riscv_ztt_i8_rdn_2x1_t d = __riscv_ztt_mhdiff_ew_x_i8_rdn_2x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i8_rod (_Float16 c)
{
  __riscv_ztt_i8_rod_1x1_t b = __riscv_ztt_mzero_m_i8_rod_1x1 ();
  __riscv_ztt_i8_rod_1x1_t d = __riscv_ztt_mhdiff_ew_x_i8_rod_1x1_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u8_rnu (carrier_i8 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t d = __riscv_ztt_mhdiff_ew_x_u8_rnu_1x1_i8_rnu (b, __riscv_ztt_scalar_make_i8_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u8_rne (float c)
{
  __riscv_ztt_u8_rne_1x4_t b = __riscv_ztt_mzero_m_u8_rne_1x4 ();
  __riscv_ztt_u8_rne_1x4_t d = __riscv_ztt_mhdiff_ew_x_u8_rne_1x4_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u8_rdn (carrier_u16 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t d = __riscv_ztt_mhdiff_ew_x_u8_rdn_1x1_u16_rdn (b, __riscv_ztt_scalar_make_u16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u8_rod (_Float16 c)
{
  __riscv_ztt_u8_rod_1x2_t b = __riscv_ztt_mzero_m_u8_rod_1x2 ();
  __riscv_ztt_u8_rod_1x2_t d = __riscv_ztt_mhdiff_ew_x_u8_rod_1x2_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i16_rnu (carrier_u64 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t d = __riscv_ztt_mhdiff_ew_x_i16_rnu_1x1_u64_rnu (b, __riscv_ztt_scalar_from_bits_u64_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i16_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rne_1x1_t b = __riscv_ztt_mzero_m_i16_rne_1x1 ();
  __riscv_ztt_i16_rne_1x1_t d = __riscv_ztt_mhdiff_ew_x_i16_rne_1x1_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i16_rdn (carrier_i8 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i16_rdn_2x1_t d = __riscv_ztt_mhdiff_ew_x_i16_rdn_2x1_i8_rdn_sat (b, __riscv_ztt_scalar_make_i8_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i16_rod (__bf16 c)
{
  __riscv_ztt_i16_rod_1x2_t b = __riscv_ztt_mzero_m_i16_rod_1x2 ();
  __riscv_ztt_i16_rod_1x2_t d = __riscv_ztt_mhdiff_ew_x_i16_rod_1x2_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u16_rnu (carrier_i32 c)
{
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_u16_rnu_1x1_t d = __riscv_ztt_mhdiff_ew_x_u16_rnu_1x1_i32_rnu_sat (b, __riscv_ztt_scalar_make_i32_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u16_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rne_1x2_t b = __riscv_ztt_mzero_m_u16_rne_1x2 ();
  __riscv_ztt_u16_rne_1x2_t d = __riscv_ztt_mhdiff_ew_x_u16_rne_1x2_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u16_rdn (carrier_u64 c)
{
  __riscv_ztt_f16_rmm_2x1_t b = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_u16_rdn_2x1_t d = __riscv_ztt_mhdiff_ew_x_u16_rdn_2x1_u64_rdn_sat (b, __riscv_ztt_scalar_from_bits_u64_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u16_rod (float c)
{
  __riscv_ztt_u16_rod_1x1_t b = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_u16_rod_1x1_t d = __riscv_ztt_mhdiff_ew_x_u16_rod_1x1_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i32_rnu (_Float16 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mhdiff_ew_x_i32_rnu_1x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i32_rne (_Float16 c)
{
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_mhdiff_ew_x_i32_rne_1x1_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i32_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_mhdiff_ew_x_i32_rdn_1x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i32_rod (float c)
{
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mhdiff_ew_x_i32_rod_1x1_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u32_rnu (carrier_i16 c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mhdiff_ew_x_u32_rnu_1x1_i16_rnu (b, __riscv_ztt_scalar_make_i16_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u32_rne (__bf16 c)
{
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_mhdiff_ew_x_u32_rne_1x1_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u32_rdn (carrier_u32 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mhdiff_ew_x_u32_rdn_1x1_u32_rdn (b, __riscv_ztt_scalar_make_u32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u32_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_mhdiff_ew_x_u32_rod_1x1_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i4_rnu_sat (carrier_u128 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i4_rnu_sat_2x1_t d = __riscv_ztt_mhdiff_ew_x_i4_rnu_sat_2x1_u128_rnu (b, __riscv_ztt_scalar_from_bits_u128_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i4_rne_sat (__bf16 c)
{
  __riscv_ztt_i4_rne_sat_1x4_t b = __riscv_ztt_mzero_m_i4_rne_sat_1x4 ();
  __riscv_ztt_i4_rne_sat_1x4_t d = __riscv_ztt_mhdiff_ew_x_i4_rne_sat_1x4_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i4_rdn_sat (carrier_i16 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i4_rdn_sat_2x1_t d = __riscv_ztt_mhdiff_ew_x_i4_rdn_sat_2x1_i16_rdn_sat (b, __riscv_ztt_scalar_make_i16_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i4_rod_sat (_Float16 c)
{
  __riscv_ztt_i4_rod_sat_1x2_t b = __riscv_ztt_mzero_m_i4_rod_sat_1x2 ();
  __riscv_ztt_i4_rod_sat_1x2_t d = __riscv_ztt_mhdiff_ew_x_i4_rod_sat_1x2_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u4_rnu_sat (carrier_i64 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_u4_rnu_sat_2x1_t d = __riscv_ztt_mhdiff_ew_x_u4_rnu_sat_2x1_i64_rnu_sat (b, __riscv_ztt_scalar_from_bits_i64_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u4_rne_sat (float c)
{
  __riscv_ztt_u4_rne_sat_1x8_t b = __riscv_ztt_mzero_m_u4_rne_sat_1x8 ();
  __riscv_ztt_u4_rne_sat_1x8_t d = __riscv_ztt_mhdiff_ew_x_u4_rne_sat_1x8_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u4_rdn_sat (carrier_u128 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_u4_rdn_sat_2x1_t d = __riscv_ztt_mhdiff_ew_x_u4_rdn_sat_2x1_u128_rdn_sat (b, __riscv_ztt_scalar_from_bits_u128_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u4_rod_sat (_Float16 c)
{
  __riscv_ztt_u4_rod_sat_1x4_t b = __riscv_ztt_mzero_m_u4_rod_sat_1x4 ();
  __riscv_ztt_u4_rod_sat_1x4_t d = __riscv_ztt_mhdiff_ew_x_u4_rod_sat_1x4_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i8_rnu_sat (float c)
{
  __riscv_ztt_f16_rmm_2x1_t b = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_i8_rnu_sat_2x1_t d = __riscv_ztt_mhdiff_ew_x_i8_rnu_sat_2x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i8_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rne_sat_1x1 ();
  __riscv_ztt_i8_rne_sat_1x1_t d = __riscv_ztt_mhdiff_ew_x_i8_rne_sat_1x1_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i8_rdn_sat (carrier_i8 c)
{
  __riscv_ztt_bf16_rne_2x1_t b = __riscv_ztt_mzero_m_bf16_rne_2x1 ();
  __riscv_ztt_i8_rdn_sat_2x1_t d = __riscv_ztt_mhdiff_ew_x_i8_rdn_sat_2x1_i8_rdn (b, __riscv_ztt_scalar_make_i8_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i8_rod_sat (__bf16 c)
{
  __riscv_ztt_i8_rod_sat_1x4_t b = __riscv_ztt_mzero_m_i8_rod_sat_1x4 ();
  __riscv_ztt_i8_rod_sat_1x4_t d = __riscv_ztt_mhdiff_ew_x_i8_rod_sat_1x4_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u8_rnu_sat (carrier_i32 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_u8_rnu_sat_1x1_t d = __riscv_ztt_mhdiff_ew_x_u8_rnu_sat_1x1_i32_rnu (b, __riscv_ztt_scalar_make_i32_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u8_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rne_sat_1x2_t b = __riscv_ztt_mzero_m_u8_rne_sat_1x2 ();
  __riscv_ztt_u8_rne_sat_1x2_t d = __riscv_ztt_mhdiff_ew_x_u8_rne_sat_1x2_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u8_rdn_sat (carrier_u64 c)
{
  __riscv_ztt_bf16_rmm_2x1_t b = __riscv_ztt_mzero_m_bf16_rmm_2x1 ();
  __riscv_ztt_u8_rdn_sat_2x1_t d = __riscv_ztt_mhdiff_ew_x_u8_rdn_sat_2x1_u64_rdn (b, __riscv_ztt_scalar_from_bits_u64_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u8_rod_sat (float c)
{
  __riscv_ztt_u8_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rod_sat_1x1 ();
  __riscv_ztt_u8_rod_sat_1x1_t d = __riscv_ztt_mhdiff_ew_x_u8_rod_sat_1x1_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i16_rnu_sat (carrier_u8 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t d = __riscv_ztt_mhdiff_ew_x_i16_rnu_sat_1x1_u8_rnu_sat (b, __riscv_ztt_scalar_make_u8_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i16_rne_sat (_Float16 c)
{
  __riscv_ztt_i16_rne_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rne_sat_1x2 ();
  __riscv_ztt_i16_rne_sat_1x2_t d = __riscv_ztt_mhdiff_ew_x_i16_rne_sat_1x2_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i16_rdn_sat (carrier_i32 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t d = __riscv_ztt_mhdiff_ew_x_i16_rdn_sat_1x1_i32_rdn_sat (b, __riscv_ztt_scalar_make_i32_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i16_rod_sat (float c)
{
  __riscv_ztt_i16_rod_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rod_sat_1x2 ();
  __riscv_ztt_i16_rod_sat_1x2_t d = __riscv_ztt_mhdiff_ew_x_i16_rod_sat_1x2_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u16_rnu_sat (carrier_i128 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t d = __riscv_ztt_mhdiff_ew_x_u16_rnu_sat_1x1_i128_rnu_sat (b, __riscv_ztt_scalar_from_bits_i128_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u16_rne_sat (__bf16 c)
{
  __riscv_ztt_u16_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rne_sat_1x1 ();
  __riscv_ztt_u16_rne_sat_1x1_t d = __riscv_ztt_mhdiff_ew_x_u16_rne_sat_1x1_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u16_rdn_sat (__bf16 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_u16_rdn_sat_2x1_t d = __riscv_ztt_mhdiff_ew_x_u16_rdn_sat_2x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u16_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rod_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rod_sat_1x2 ();
  __riscv_ztt_u16_rod_sat_1x2_t d = __riscv_ztt_mhdiff_ew_x_u16_rod_sat_1x2_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i32_rnu_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_mhdiff_ew_x_i32_rnu_sat_1x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i32_rne_sat (__bf16 c)
{
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_mhdiff_ew_x_i32_rne_sat_1x1_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i32_rdn_sat (carrier_i16 c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mhdiff_ew_x_i32_rdn_sat_1x1_i16_rdn (b, __riscv_ztt_scalar_make_i16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_i32_rod_sat (_Float16 c)
{
  __riscv_ztt_i32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_mhdiff_ew_x_i32_rod_sat_1x1_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u32_rnu_sat (carrier_i64 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_mhdiff_ew_x_u32_rnu_sat_1x1_i64_rnu (b, __riscv_ztt_scalar_from_bits_i64_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u32_rne_sat (float c)
{
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mhdiff_ew_x_u32_rne_sat_1x1_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u32_rdn_sat (carrier_u128 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_mhdiff_ew_x_u32_rdn_sat_1x1_u128_rdn (b, __riscv_ztt_scalar_from_bits_u128_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_u32_rod_sat (_Float16 c)
{
  __riscv_ztt_u32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_mhdiff_ew_x_u32_rod_sat_1x1_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_f16_rne (carrier_u16 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_f16_rne_2x1_t d = __riscv_ztt_mhdiff_ew_x_f16_rne_2x1_u16_rnu_sat (b, __riscv_ztt_scalar_make_u16_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_f16_rtz (carrier_i32 c)
{
  __riscv_ztt_f16_rtz_1x1_t b = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_mhdiff_ew_x_f16_rtz_1x1_i32_rod_sat (b, __riscv_ztt_scalar_make_i32_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_f16_rdn (carrier_i64 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_f16_rdn_2x1_t d = __riscv_ztt_mhdiff_ew_x_f16_rdn_2x1_i64_rdn_sat (b, __riscv_ztt_scalar_from_bits_i64_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_f16_rup (carrier_i128 c)
{
  __riscv_ztt_f16_rup_1x2_t b = __riscv_ztt_mzero_m_f16_rup_1x2 ();
  __riscv_ztt_f16_rup_1x2_t d = __riscv_ztt_mhdiff_ew_x_f16_rup_1x2_i128_rne_sat (b, __riscv_ztt_scalar_from_bits_i128_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_f16_rmm (_Float16 c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mhdiff_ew_x_f16_rmm_1x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_f16_rno (__bf16 c)
{
  __riscv_ztt_f16_rno_1x2_t b = __riscv_ztt_mzero_m_f16_rno_1x2 ();
  __riscv_ztt_f16_rno_1x2_t d = __riscv_ztt_mhdiff_ew_x_f16_rno_1x2_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_bf16_rne (float c)
{
  __riscv_ztt_bf16_rne_2x1_t b = __riscv_ztt_mzero_m_bf16_rne_2x1 ();
  __riscv_ztt_bf16_rne_2x1_t d = __riscv_ztt_mhdiff_ew_x_bf16_rne_2x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_bf16_rtz (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rtz_1x1_t b = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t d = __riscv_ztt_mhdiff_ew_x_bf16_rtz_1x1_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_bf16_rdn (carrier_u8 c)
{
  __riscv_ztt_bf16_rdn_2x1_t b = __riscv_ztt_mzero_m_bf16_rdn_2x1 ();
  __riscv_ztt_bf16_rdn_2x1_t d = __riscv_ztt_mhdiff_ew_x_bf16_rdn_2x1_u8_rnu (b, __riscv_ztt_scalar_make_u8_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_bf16_rup (carrier_i16 c)
{
  __riscv_ztt_bf16_rup_1x2_t b = __riscv_ztt_mzero_m_bf16_rup_1x2 ();
  __riscv_ztt_bf16_rup_1x2_t d = __riscv_ztt_mhdiff_ew_x_bf16_rup_1x2_i16_rod (b, __riscv_ztt_scalar_make_i16_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_bf16_rmm (carrier_i32 c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_bf16_rmm_1x1_t d = __riscv_ztt_mhdiff_ew_x_bf16_rmm_1x1_i32_rdn (b, __riscv_ztt_scalar_make_i32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_bf16_rno (carrier_i64 c)
{
  __riscv_ztt_bf16_rno_1x2_t b = __riscv_ztt_mzero_m_bf16_rno_1x2 ();
  __riscv_ztt_bf16_rno_1x2_t d = __riscv_ztt_mhdiff_ew_x_bf16_rno_1x2_i64_rne (b, __riscv_ztt_scalar_from_bits_i64_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_f32_rne (carrier_i128 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mhdiff_ew_x_f32_rne_1x1_i128_rnu (b, __riscv_ztt_scalar_from_bits_i128_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_f32_rtz (carrier_u128 c)
{
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mhdiff_ew_x_f32_rtz_1x1_u128_rod (b, __riscv_ztt_scalar_from_bits_u128_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_f32_rdn (carrier_u8 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mhdiff_ew_x_f32_rdn_1x1_u8_rdn_sat (b, __riscv_ztt_scalar_make_u8_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_f32_rup (carrier_u16 c)
{
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mhdiff_ew_x_f32_rup_1x1_u16_rne_sat (b, __riscv_ztt_scalar_make_u16_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_f32_rmm (carrier_u32 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mhdiff_ew_x_f32_rmm_1x1_u32_rnu_sat (b, __riscv_ztt_scalar_make_u32_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mhdiff_f32_rno (carrier_i64 c)
{
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mhdiff_ew_x_f32_rno_1x1_i64_rod_sat (b, __riscv_ztt_scalar_from_bits_i64_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i4_rnu (carrier_i64 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i4_rnu_1x2_t d = __riscv_ztt_mmean_ew_x_i4_rnu_1x2_i64_rne (b, __riscv_ztt_scalar_from_bits_i64_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i4_rne (__bf16 c)
{
  __riscv_ztt_i4_rne_2x1_t b = __riscv_ztt_mzero_m_i4_rne_2x1 ();
  __riscv_ztt_i4_rne_2x1_t d = __riscv_ztt_mmean_ew_x_i4_rne_2x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i4_rdn (carrier_u128 c)
{
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_i4_rdn_1x2_t d = __riscv_ztt_mmean_ew_x_i4_rdn_1x2_u128_rod (b, __riscv_ztt_scalar_from_bits_u128_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i4_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rod_8x1_t b = __riscv_ztt_mzero_m_i4_rod_8x1 ();
  __riscv_ztt_i4_rod_8x1_t d = __riscv_ztt_mmean_ew_x_i4_rod_8x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u4_rnu (carrier_u16 c)
{
  __riscv_ztt_f16_rmm_1x2_t b = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_u4_rnu_1x2_t d = __riscv_ztt_mmean_ew_x_u4_rnu_1x2_u16_rne_sat (b, __riscv_ztt_scalar_make_u16_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u4_rne (float c)
{
  __riscv_ztt_u4_rne_4x1_t b = __riscv_ztt_mzero_m_u4_rne_4x1 ();
  __riscv_ztt_u4_rne_4x1_t d = __riscv_ztt_mmean_ew_x_u4_rne_4x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u4_rdn (carrier_i64 c)
{
  __riscv_ztt_bf16_rne_1x2_t b = __riscv_ztt_mzero_m_bf16_rne_1x2 ();
  __riscv_ztt_u4_rdn_1x2_t d = __riscv_ztt_mmean_ew_x_u4_rdn_1x2_i64_rod_sat (b, __riscv_ztt_scalar_from_bits_i64_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u4_rod (_Float16 c)
{
  __riscv_ztt_u4_rod_2x1_t b = __riscv_ztt_mzero_m_u4_rod_2x1 ();
  __riscv_ztt_u4_rod_2x1_t d = __riscv_ztt_mmean_ew_x_u4_rod_2x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i8_rnu (_Float16 c)
{
  __riscv_ztt_bf16_rdn_1x2_t b = __riscv_ztt_mzero_m_bf16_rdn_1x2 ();
  __riscv_ztt_i8_rnu_1x2_t d = __riscv_ztt_mmean_ew_x_i8_rnu_1x2_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i8_rne (float c)
{
  __riscv_ztt_i8_rne_4x1_t b = __riscv_ztt_mzero_m_i8_rne_4x1 ();
  __riscv_ztt_i8_rne_4x1_t d = __riscv_ztt_mmean_ew_x_i8_rne_4x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i8_rdn (float c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_i8_rdn_1x1_t d = __riscv_ztt_mmean_ew_x_i8_rdn_1x1_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i8_rod (__bf16 c)
{
  __riscv_ztt_i8_rod_2x1_t b = __riscv_ztt_mzero_m_i8_rod_2x1 ();
  __riscv_ztt_i8_rod_2x1_t d = __riscv_ztt_mmean_ew_x_i8_rod_2x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u8_rnu (carrier_u8 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t d = __riscv_ztt_mmean_ew_x_u8_rnu_1x1_u8_rne (b, __riscv_ztt_scalar_make_u8_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u8_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rne_1x1_t b = __riscv_ztt_mzero_m_u8_rne_1x1 ();
  __riscv_ztt_u8_rne_1x1_t d = __riscv_ztt_mmean_ew_x_u8_rne_1x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u8_rdn (carrier_i32 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t d = __riscv_ztt_mmean_ew_x_u8_rdn_1x1_i32_rod (b, __riscv_ztt_scalar_make_i32_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u8_rod (__bf16 c)
{
  __riscv_ztt_u8_rod_4x1_t b = __riscv_ztt_mzero_m_u8_rod_4x1 ();
  __riscv_ztt_u8_rod_4x1_t d = __riscv_ztt_mmean_ew_x_u8_rod_4x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i16_rnu (carrier_i128 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t d = __riscv_ztt_mmean_ew_x_i16_rnu_1x1_i128_rne (b, __riscv_ztt_scalar_from_bits_i128_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i16_rne (_Float16 c)
{
  __riscv_ztt_i16_rne_2x1_t b = __riscv_ztt_mzero_m_i16_rne_2x1 ();
  __riscv_ztt_i16_rne_2x1_t d = __riscv_ztt_mmean_ew_x_i16_rne_2x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i16_rdn (carrier_u8 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i16_rdn_1x2_t d = __riscv_ztt_mmean_ew_x_i16_rdn_1x2_u8_rod_sat (b, __riscv_ztt_scalar_make_u8_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i16_rod (float c)
{
  __riscv_ztt_i16_rod_1x1_t b = __riscv_ztt_mzero_m_i16_rod_1x1 ();
  __riscv_ztt_i16_rod_1x1_t d = __riscv_ztt_mmean_ew_x_i16_rod_1x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u16_rnu (carrier_u32 c)
{
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_u16_rnu_1x2_t d = __riscv_ztt_mmean_ew_x_u16_rnu_1x2_u32_rne_sat (b, __riscv_ztt_scalar_make_u32_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u16_rne (_Float16 c)
{
  __riscv_ztt_u16_rne_2x1_t b = __riscv_ztt_mzero_m_u16_rne_2x1 ();
  __riscv_ztt_u16_rne_2x1_t d = __riscv_ztt_mmean_ew_x_u16_rne_2x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u16_rdn (carrier_i128 c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_u16_rdn_1x1_t d = __riscv_ztt_mmean_ew_x_u16_rdn_1x1_i128_rod_sat (b, __riscv_ztt_scalar_from_bits_i128_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u16_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rod_2x1_t b = __riscv_ztt_mzero_m_u16_rod_2x1 ();
  __riscv_ztt_u16_rod_2x1_t d = __riscv_ztt_mmean_ew_x_u16_rod_2x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i32_rnu (__bf16 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mmean_ew_x_i32_rnu_1x1_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i32_rne (__bf16 c)
{
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_mmean_ew_x_i32_rne_1x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i32_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_mmean_ew_x_i32_rdn_1x1_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i32_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mmean_ew_x_i32_rod_1x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u32_rnu (carrier_u16 c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mmean_ew_x_u32_rnu_1x1_u16_rne (b, __riscv_ztt_scalar_make_u16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u32_rne (float c)
{
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_mmean_ew_x_u32_rne_1x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u32_rdn (carrier_i64 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mmean_ew_x_u32_rdn_1x1_i64_rod (b, __riscv_ztt_scalar_from_bits_i64_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u32_rod (_Float16 c)
{
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_mmean_ew_x_u32_rod_1x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i4_rnu_sat (carrier_i8 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i4_rnu_sat_1x2_t d = __riscv_ztt_mmean_ew_x_i4_rnu_sat_1x2_i8_rne_sat (b, __riscv_ztt_scalar_make_i8_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i4_rne_sat (float c)
{
  __riscv_ztt_i4_rne_sat_8x1_t b = __riscv_ztt_mzero_m_i4_rne_sat_8x1 ();
  __riscv_ztt_i4_rne_sat_8x1_t d = __riscv_ztt_mmean_ew_x_i4_rne_sat_8x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i4_rdn_sat (carrier_u16 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i4_rdn_sat_1x2_t d = __riscv_ztt_mmean_ew_x_i4_rdn_sat_1x2_u16_rod_sat (b, __riscv_ztt_scalar_make_u16_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i4_rod_sat (__bf16 c)
{
  __riscv_ztt_i4_rod_sat_4x1_t b = __riscv_ztt_mzero_m_i4_rod_sat_4x1 ();
  __riscv_ztt_i4_rod_sat_4x1_t d = __riscv_ztt_mmean_ew_x_i4_rod_sat_4x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u4_rnu_sat (carrier_u64 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_u4_rnu_sat_1x2_t d = __riscv_ztt_mmean_ew_x_u4_rnu_sat_1x2_u64_rne_sat (b, __riscv_ztt_scalar_from_bits_u64_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u4_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rne_sat_2x1_t b = __riscv_ztt_mzero_m_u4_rne_sat_2x1 ();
  __riscv_ztt_u4_rne_sat_2x1_t d = __riscv_ztt_mmean_ew_x_u4_rne_sat_2x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u4_rdn_sat (_Float16 c)
{
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_u4_rdn_sat_1x2_t d = __riscv_ztt_mmean_ew_x_u4_rdn_sat_1x2_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u4_rod_sat (__bf16 c)
{
  __riscv_ztt_u4_rod_sat_8x1_t b = __riscv_ztt_mzero_m_u4_rod_sat_8x1 ();
  __riscv_ztt_u4_rod_sat_8x1_t d = __riscv_ztt_mmean_ew_x_u4_rod_sat_8x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i8_rnu_sat (float c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t d = __riscv_ztt_mmean_ew_x_i8_rnu_sat_1x1_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i8_rne_sat (_Float16 c)
{
  __riscv_ztt_i8_rne_sat_2x1_t b = __riscv_ztt_mzero_m_i8_rne_sat_2x1 ();
  __riscv_ztt_i8_rne_sat_2x1_t d = __riscv_ztt_mmean_ew_x_i8_rne_sat_2x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i8_rdn_sat (carrier_u8 c)
{
  __riscv_ztt_bf16_rne_1x2_t b = __riscv_ztt_mzero_m_bf16_rne_1x2 ();
  __riscv_ztt_i8_rdn_sat_1x2_t d = __riscv_ztt_mmean_ew_x_i8_rdn_sat_1x2_u8_rod (b, __riscv_ztt_scalar_make_u8_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i8_rod_sat (float c)
{
  __riscv_ztt_i8_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rod_sat_1x1 ();
  __riscv_ztt_i8_rod_sat_1x1_t d = __riscv_ztt_mmean_ew_x_i8_rod_sat_1x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u8_rnu_sat (carrier_u32 c)
{
  __riscv_ztt_bf16_rdn_1x2_t b = __riscv_ztt_mzero_m_bf16_rdn_1x2 ();
  __riscv_ztt_u8_rnu_sat_1x2_t d = __riscv_ztt_mmean_ew_x_u8_rnu_sat_1x2_u32_rne (b, __riscv_ztt_scalar_make_u32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u8_rne_sat (_Float16 c)
{
  __riscv_ztt_u8_rne_sat_4x1_t b = __riscv_ztt_mzero_m_u8_rne_sat_4x1 ();
  __riscv_ztt_u8_rne_sat_4x1_t d = __riscv_ztt_mmean_ew_x_u8_rne_sat_4x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u8_rdn_sat (carrier_i128 c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_u8_rdn_sat_1x1_t d = __riscv_ztt_mmean_ew_x_u8_rdn_sat_1x1_i128_rod (b, __riscv_ztt_scalar_from_bits_i128_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u8_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rod_sat_2x1_t b = __riscv_ztt_mzero_m_u8_rod_sat_2x1 ();
  __riscv_ztt_u8_rod_sat_2x1_t d = __riscv_ztt_mmean_ew_x_u8_rod_sat_2x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i16_rnu_sat (carrier_i16 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t d = __riscv_ztt_mmean_ew_x_i16_rnu_sat_1x1_i16_rne_sat (b, __riscv_ztt_scalar_make_i16_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i16_rne_sat (__bf16 c)
{
  __riscv_ztt_i16_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rne_sat_1x1 ();
  __riscv_ztt_i16_rne_sat_1x1_t d = __riscv_ztt_mmean_ew_x_i16_rne_sat_1x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i16_rdn_sat (carrier_u32 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t d = __riscv_ztt_mmean_ew_x_i16_rdn_sat_1x1_u32_rod_sat (b, __riscv_ztt_scalar_make_u32_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i16_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rod_sat_2x1_t b = __riscv_ztt_mzero_m_i16_rod_sat_2x1 ();
  __riscv_ztt_i16_rod_sat_2x1_t d = __riscv_ztt_mmean_ew_x_i16_rod_sat_2x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u16_rnu_sat (carrier_u128 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t d = __riscv_ztt_mmean_ew_x_u16_rnu_sat_1x1_u128_rne_sat (b, __riscv_ztt_scalar_from_bits_u128_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u16_rne_sat (float c)
{
  __riscv_ztt_u16_rne_sat_2x1_t b = __riscv_ztt_mzero_m_u16_rne_sat_2x1 ();
  __riscv_ztt_u16_rne_sat_2x1_t d = __riscv_ztt_mmean_ew_x_u16_rne_sat_2x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u16_rdn_sat (__bf16 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_u16_rdn_sat_1x2_t d = __riscv_ztt_mmean_ew_x_u16_rdn_sat_1x2_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u16_rod_sat (_Float16 c)
{
  __riscv_ztt_u16_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rod_sat_1x1 ();
  __riscv_ztt_u16_rod_sat_1x1_t d = __riscv_ztt_mmean_ew_x_u16_rod_sat_1x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i32_rnu_sat (carrier_i8 c)
{
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_mmean_ew_x_i32_rnu_sat_1x1_i8_rne (b, __riscv_ztt_scalar_make_i8_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i32_rne_sat (float c)
{
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_mmean_ew_x_i32_rne_sat_1x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i32_rdn_sat (carrier_u16 c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mmean_ew_x_i32_rdn_sat_1x1_u16_rod (b, __riscv_ztt_scalar_make_u16_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_i32_rod_sat (__bf16 c)
{
  __riscv_ztt_i32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_mmean_ew_x_i32_rod_sat_1x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u32_rnu_sat (carrier_u64 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_mmean_ew_x_u32_rnu_sat_1x1_u64_rne (b, __riscv_ztt_scalar_from_bits_u64_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u32_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mmean_ew_x_u32_rne_sat_1x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u32_rdn_sat (carrier_i8 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_mmean_ew_x_u32_rdn_sat_1x1_i8_rod_sat (b, __riscv_ztt_scalar_make_i8_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_u32_rod_sat (__bf16 c)
{
  __riscv_ztt_u32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_mmean_ew_x_u32_rod_sat_1x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_f16_rne (carrier_i32 c)
{
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_f16_rne_1x1_t d = __riscv_ztt_mmean_ew_x_f16_rne_1x1_i32_rne_sat (b, __riscv_ztt_scalar_make_i32_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_f16_rtz (carrier_i64 c)
{
  __riscv_ztt_f16_rtz_2x1_t b = __riscv_ztt_mzero_m_f16_rtz_2x1 ();
  __riscv_ztt_f16_rtz_2x1_t d = __riscv_ztt_mmean_ew_x_f16_rtz_2x1_i64_rnu_sat (b, __riscv_ztt_scalar_from_bits_i64_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_f16_rdn (carrier_u64 c)
{
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_f16_rdn_1x2_t d = __riscv_ztt_mmean_ew_x_f16_rdn_1x2_u64_rod_sat (b, __riscv_ztt_scalar_from_bits_u64_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_f16_rup (carrier_u128 c)
{
  __riscv_ztt_f16_rup_1x1_t b = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_f16_rup_1x1_t d = __riscv_ztt_mmean_ew_x_f16_rup_1x1_u128_rdn_sat (b, __riscv_ztt_scalar_from_bits_u128_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_f16_rmm (_Float16 c)
{
  __riscv_ztt_f16_rmm_1x2_t b = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_f16_rmm_1x2_t d = __riscv_ztt_mmean_ew_x_f16_rmm_1x2_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_f16_rno (float c)
{
  __riscv_ztt_f16_rno_2x1_t b = __riscv_ztt_mzero_m_f16_rno_2x1 ();
  __riscv_ztt_f16_rno_2x1_t d = __riscv_ztt_mmean_ew_x_f16_rno_2x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_bf16_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t d = __riscv_ztt_mmean_ew_x_bf16_rne_1x1_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_bf16_rtz (carrier_i8 c)
{
  __riscv_ztt_bf16_rtz_2x1_t b = __riscv_ztt_mzero_m_bf16_rtz_2x1 ();
  __riscv_ztt_bf16_rtz_2x1_t d = __riscv_ztt_mmean_ew_x_bf16_rtz_2x1_i8_rdn (b, __riscv_ztt_scalar_make_i8_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_bf16_rdn (carrier_i16 c)
{
  __riscv_ztt_bf16_rdn_1x2_t b = __riscv_ztt_mzero_m_bf16_rdn_1x2 ();
  __riscv_ztt_bf16_rdn_1x2_t d = __riscv_ztt_mmean_ew_x_bf16_rdn_1x2_i16_rne (b, __riscv_ztt_scalar_make_i16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_bf16_rup (carrier_i32 c)
{
  __riscv_ztt_bf16_rup_1x1_t b = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_bf16_rup_1x1_t d = __riscv_ztt_mmean_ew_x_bf16_rup_1x1_i32_rnu (b, __riscv_ztt_scalar_make_i32_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_bf16_rmm (carrier_u32 c)
{
  __riscv_ztt_bf16_rmm_1x2_t b = __riscv_ztt_mzero_m_bf16_rmm_1x2 ();
  __riscv_ztt_bf16_rmm_1x2_t d = __riscv_ztt_mmean_ew_x_bf16_rmm_1x2_u32_rod (b, __riscv_ztt_scalar_make_u32_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_bf16_rno (carrier_u64 c)
{
  __riscv_ztt_bf16_rno_2x1_t b = __riscv_ztt_mzero_m_bf16_rno_2x1 ();
  __riscv_ztt_bf16_rno_2x1_t d = __riscv_ztt_mmean_ew_x_bf16_rno_2x1_u64_rdn (b, __riscv_ztt_scalar_from_bits_u64_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_f32_rne (carrier_u128 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mmean_ew_x_f32_rne_1x1_u128_rne (b, __riscv_ztt_scalar_from_bits_u128_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_f32_rtz (carrier_u8 c)
{
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mmean_ew_x_f32_rtz_1x1_u8_rnu_sat (b, __riscv_ztt_scalar_make_u8_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_f32_rdn (carrier_i16 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mmean_ew_x_f32_rdn_1x1_i16_rod_sat (b, __riscv_ztt_scalar_make_i16_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_f32_rup (carrier_i32 c)
{
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mmean_ew_x_f32_rup_1x1_i32_rdn_sat (b, __riscv_ztt_scalar_make_i32_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_f32_rmm (carrier_i64 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mmean_ew_x_f32_rmm_1x1_i64_rne_sat (b, __riscv_ztt_scalar_from_bits_i64_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmean_f32_rno (carrier_i128 c)
{
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mmean_ew_x_f32_rno_1x1_i128_rnu_sat (b, __riscv_ztt_scalar_from_bits_i128_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i4_rnu (carrier_u64 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i4_rnu_2x1_t d = __riscv_ztt_mmulneg_ew_x_i4_rnu_2x1_u64_rdn (b, __riscv_ztt_scalar_from_bits_u64_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i4_rne (float c)
{
  __riscv_ztt_i4_rne_1x4_t b = __riscv_ztt_mzero_m_i4_rne_1x4 ();
  __riscv_ztt_i4_rne_1x4_t d = __riscv_ztt_mmulneg_ew_x_i4_rne_1x4_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i4_rdn (carrier_u8 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_i4_rdn_2x1_t d = __riscv_ztt_mmulneg_ew_x_i4_rdn_2x1_u8_rnu_sat (b, __riscv_ztt_scalar_make_u8_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i4_rod (_Float16 c)
{
  __riscv_ztt_i4_rod_1x2_t b = __riscv_ztt_mzero_m_i4_rod_1x2 ();
  __riscv_ztt_i4_rod_1x2_t d = __riscv_ztt_mmulneg_ew_x_i4_rod_1x2_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u4_rnu (carrier_i32 c)
{
  __riscv_ztt_f16_rmm_2x1_t b = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_u4_rnu_2x1_t d = __riscv_ztt_mmulneg_ew_x_u4_rnu_2x1_i32_rdn_sat (b, __riscv_ztt_scalar_make_i32_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u4_rne (float c)
{
  __riscv_ztt_u4_rne_1x8_t b = __riscv_ztt_mzero_m_u4_rne_1x8 ();
  __riscv_ztt_u4_rne_1x8_t d = __riscv_ztt_mmulneg_ew_x_u4_rne_1x8_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u4_rdn (carrier_i128 c)
{
  __riscv_ztt_bf16_rne_2x1_t b = __riscv_ztt_mzero_m_bf16_rne_2x1 ();
  __riscv_ztt_u4_rdn_2x1_t d = __riscv_ztt_mmulneg_ew_x_u4_rdn_2x1_i128_rnu_sat (b, __riscv_ztt_scalar_from_bits_i128_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u4_rod (__bf16 c)
{
  __riscv_ztt_u4_rod_1x4_t b = __riscv_ztt_mzero_m_u4_rod_1x4 ();
  __riscv_ztt_u4_rod_1x4_t d = __riscv_ztt_mmulneg_ew_x_u4_rod_1x4_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i8_rnu (__bf16 c)
{
  __riscv_ztt_bf16_rdn_2x1_t b = __riscv_ztt_mzero_m_bf16_rdn_2x1 ();
  __riscv_ztt_i8_rnu_2x1_t d = __riscv_ztt_mmulneg_ew_x_i8_rnu_2x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i8_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rne_1x1_t b = __riscv_ztt_mzero_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t d = __riscv_ztt_mmulneg_ew_x_i8_rne_1x1_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i8_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rmm_2x1_t b = __riscv_ztt_mzero_m_bf16_rmm_2x1 ();
  __riscv_ztt_i8_rdn_2x1_t d = __riscv_ztt_mmulneg_ew_x_i8_rdn_2x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i8_rod (__bf16 c)
{
  __riscv_ztt_i8_rod_1x4_t b = __riscv_ztt_mzero_m_i8_rod_1x4 ();
  __riscv_ztt_i8_rod_1x4_t d = __riscv_ztt_mmulneg_ew_x_i8_rod_1x4_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u8_rnu (carrier_i16 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t d = __riscv_ztt_mmulneg_ew_x_u8_rnu_1x1_i16_rdn (b, __riscv_ztt_scalar_make_i16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u8_rne (_Float16 c)
{
  __riscv_ztt_u8_rne_1x2_t b = __riscv_ztt_mzero_m_u8_rne_1x2 ();
  __riscv_ztt_u8_rne_1x2_t d = __riscv_ztt_mmulneg_ew_x_u8_rne_1x2_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u8_rdn (carrier_i64 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t d = __riscv_ztt_mmulneg_ew_x_u8_rdn_1x1_i64_rnu (b, __riscv_ztt_scalar_from_bits_i64_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u8_rod (float c)
{
  __riscv_ztt_u8_rod_1x1_t b = __riscv_ztt_mzero_m_u8_rod_1x1 ();
  __riscv_ztt_u8_rod_1x1_t d = __riscv_ztt_mmulneg_ew_x_u8_rod_1x1_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i16_rnu (carrier_u128 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t d = __riscv_ztt_mmulneg_ew_x_i16_rnu_1x1_u128_rdn (b, __riscv_ztt_scalar_from_bits_u128_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i16_rne (_Float16 c)
{
  __riscv_ztt_i16_rne_1x2_t b = __riscv_ztt_mzero_m_i16_rne_1x2 ();
  __riscv_ztt_i16_rne_1x2_t d = __riscv_ztt_mmulneg_ew_x_i16_rne_1x2_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i16_rdn (carrier_u16 c)
{
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_i16_rdn_1x1_t d = __riscv_ztt_mmulneg_ew_x_i16_rdn_1x1_u16_rnu_sat (b, __riscv_ztt_scalar_make_u16_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i16_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rod_1x2_t b = __riscv_ztt_mzero_m_i16_rod_1x2 ();
  __riscv_ztt_i16_rod_1x2_t d = __riscv_ztt_mmulneg_ew_x_i16_rod_1x2_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u16_rnu (carrier_i64 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_u16_rnu_2x1_t d = __riscv_ztt_mmulneg_ew_x_u16_rnu_2x1_i64_rdn_sat (b, __riscv_ztt_scalar_from_bits_i64_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u16_rne (__bf16 c)
{
  __riscv_ztt_u16_rne_1x1_t b = __riscv_ztt_mzero_m_u16_rne_1x1 ();
  __riscv_ztt_u16_rne_1x1_t d = __riscv_ztt_mmulneg_ew_x_u16_rne_1x1_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u16_rdn (_Float16 c)
{
  __riscv_ztt_f16_rmm_2x1_t b = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_u16_rdn_2x1_t d = __riscv_ztt_mmulneg_ew_x_u16_rdn_2x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u16_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rod_1x2_t b = __riscv_ztt_mzero_m_u16_rod_1x2 ();
  __riscv_ztt_u16_rod_1x2_t d = __riscv_ztt_mmulneg_ew_x_u16_rod_1x2_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i32_rnu (float c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mmulneg_ew_x_i32_rnu_1x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i32_rne (float c)
{
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_mmulneg_ew_x_i32_rne_1x1_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i32_rdn (carrier_u8 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_mmulneg_ew_x_i32_rdn_1x1_u8_rnu (b, __riscv_ztt_scalar_make_u8_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i32_rod (_Float16 c)
{
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mmulneg_ew_x_i32_rod_1x1_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u32_rnu (carrier_i32 c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mmulneg_ew_x_u32_rnu_1x1_i32_rdn (b, __riscv_ztt_scalar_make_i32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u32_rne (float c)
{
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_mmulneg_ew_x_u32_rne_1x1_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u32_rdn (carrier_i128 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mmulneg_ew_x_u32_rdn_1x1_i128_rnu (b, __riscv_ztt_scalar_from_bits_i128_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u32_rod (__bf16 c)
{
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_mmulneg_ew_x_u32_rod_1x1_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i4_rnu_sat (carrier_u8 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i4_rnu_sat_2x1_t d = __riscv_ztt_mmulneg_ew_x_i4_rnu_sat_2x1_u8_rdn_sat (b, __riscv_ztt_scalar_make_u8_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i4_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rne_sat_1x2_t b = __riscv_ztt_mzero_m_i4_rne_sat_1x2 ();
  __riscv_ztt_i4_rne_sat_1x2_t d = __riscv_ztt_mmulneg_ew_x_i4_rne_sat_1x2_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i4_rdn_sat (carrier_u32 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i4_rdn_sat_2x1_t d = __riscv_ztt_mmulneg_ew_x_i4_rdn_sat_2x1_u32_rnu_sat (b, __riscv_ztt_scalar_make_u32_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i4_rod_sat (__bf16 c)
{
  __riscv_ztt_i4_rod_sat_1x8_t b = __riscv_ztt_mzero_m_i4_rod_sat_1x8 ();
  __riscv_ztt_i4_rod_sat_1x8_t d = __riscv_ztt_mmulneg_ew_x_i4_rod_sat_1x8_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u4_rnu_sat (carrier_i128 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_u4_rnu_sat_2x1_t d = __riscv_ztt_mmulneg_ew_x_u4_rnu_sat_2x1_i128_rdn_sat (b, __riscv_ztt_scalar_from_bits_i128_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u4_rne_sat (_Float16 c)
{
  __riscv_ztt_u4_rne_sat_1x4_t b = __riscv_ztt_mzero_m_u4_rne_sat_1x4 ();
  __riscv_ztt_u4_rne_sat_1x4_t d = __riscv_ztt_mmulneg_ew_x_u4_rne_sat_1x4_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u4_rdn_sat (__bf16 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_u4_rdn_sat_2x1_t d = __riscv_ztt_mmulneg_ew_x_u4_rdn_sat_2x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u4_rod_sat (float c)
{
  __riscv_ztt_u4_rod_sat_1x2_t b = __riscv_ztt_mzero_m_u4_rod_sat_1x2 ();
  __riscv_ztt_u4_rod_sat_1x2_t d = __riscv_ztt_mmulneg_ew_x_u4_rod_sat_1x2_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i8_rnu_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f16_rmm_2x1_t b = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_i8_rnu_sat_2x1_t d = __riscv_ztt_mmulneg_ew_x_i8_rnu_sat_2x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i8_rne_sat (_Float16 c)
{
  __riscv_ztt_i8_rne_sat_1x4_t b = __riscv_ztt_mzero_m_i8_rne_sat_1x4 ();
  __riscv_ztt_i8_rne_sat_1x4_t d = __riscv_ztt_mmulneg_ew_x_i8_rne_sat_1x4_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i8_rdn_sat (carrier_u16 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_i8_rdn_sat_1x1_t d = __riscv_ztt_mmulneg_ew_x_i8_rdn_sat_1x1_u16_rnu (b, __riscv_ztt_scalar_make_u16_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i8_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rod_sat_1x2_t b = __riscv_ztt_mzero_m_i8_rod_sat_1x2 ();
  __riscv_ztt_i8_rod_sat_1x2_t d = __riscv_ztt_mmulneg_ew_x_i8_rod_sat_1x2_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u8_rnu_sat (carrier_i64 c)
{
  __riscv_ztt_bf16_rdn_2x1_t b = __riscv_ztt_mzero_m_bf16_rdn_2x1 ();
  __riscv_ztt_u8_rnu_sat_2x1_t d = __riscv_ztt_mmulneg_ew_x_u8_rnu_sat_2x1_i64_rdn (b, __riscv_ztt_scalar_from_bits_i64_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u8_rne_sat (__bf16 c)
{
  __riscv_ztt_u8_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rne_sat_1x1 ();
  __riscv_ztt_u8_rne_sat_1x1_t d = __riscv_ztt_mmulneg_ew_x_u8_rne_sat_1x1_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u8_rdn_sat (carrier_i8 c)
{
  __riscv_ztt_bf16_rmm_2x1_t b = __riscv_ztt_mzero_m_bf16_rmm_2x1 ();
  __riscv_ztt_u8_rdn_sat_2x1_t d = __riscv_ztt_mmulneg_ew_x_u8_rdn_sat_2x1_i8_rnu_sat (b, __riscv_ztt_scalar_make_i8_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u8_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rod_sat_1x4_t b = __riscv_ztt_mzero_m_u8_rod_sat_1x4 ();
  __riscv_ztt_u8_rod_sat_1x4_t d = __riscv_ztt_mmulneg_ew_x_u8_rod_sat_1x4_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i16_rnu_sat (carrier_u16 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t d = __riscv_ztt_mmulneg_ew_x_i16_rnu_sat_1x1_u16_rdn_sat (b, __riscv_ztt_scalar_make_u16_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i16_rne_sat (float c)
{
  __riscv_ztt_i16_rne_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rne_sat_1x2 ();
  __riscv_ztt_i16_rne_sat_1x2_t d = __riscv_ztt_mmulneg_ew_x_i16_rne_sat_1x2_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i16_rdn_sat (carrier_u64 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t d = __riscv_ztt_mmulneg_ew_x_i16_rdn_sat_1x1_u64_rnu_sat (b, __riscv_ztt_scalar_from_bits_u64_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i16_rod_sat (_Float16 c)
{
  __riscv_ztt_i16_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rod_sat_1x1 ();
  __riscv_ztt_i16_rod_sat_1x1_t d = __riscv_ztt_mmulneg_ew_x_i16_rod_sat_1x1_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u16_rnu_sat (_Float16 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t d = __riscv_ztt_mmulneg_ew_x_u16_rnu_sat_1x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u16_rne_sat (float c)
{
  __riscv_ztt_u16_rne_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rne_sat_1x2 ();
  __riscv_ztt_u16_rne_sat_1x2_t d = __riscv_ztt_mmulneg_ew_x_u16_rne_sat_1x2_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u16_rdn_sat (float c)
{
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_u16_rdn_sat_1x1_t d = __riscv_ztt_mmulneg_ew_x_u16_rdn_sat_1x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u16_rod_sat (__bf16 c)
{
  __riscv_ztt_u16_rod_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rod_sat_1x2 ();
  __riscv_ztt_u16_rod_sat_1x2_t d = __riscv_ztt_mmulneg_ew_x_u16_rod_sat_1x2_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i32_rnu_sat (carrier_u8 c)
{
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_mmulneg_ew_x_i32_rnu_sat_1x1_u8_rdn (b, __riscv_ztt_scalar_make_u8_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i32_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_mmulneg_ew_x_i32_rne_sat_1x1_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i32_rdn_sat (carrier_u32 c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mmulneg_ew_x_i32_rdn_sat_1x1_u32_rnu (b, __riscv_ztt_scalar_make_u32_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_i32_rod_sat (__bf16 c)
{
  __riscv_ztt_i32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_mmulneg_ew_x_i32_rod_sat_1x1_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u32_rnu_sat (carrier_i128 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_mmulneg_ew_x_u32_rnu_sat_1x1_i128_rdn (b, __riscv_ztt_scalar_from_bits_i128_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u32_rne_sat (_Float16 c)
{
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mmulneg_ew_x_u32_rne_sat_1x1_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u32_rdn_sat (carrier_i16 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_mmulneg_ew_x_u32_rdn_sat_1x1_i16_rnu_sat (b, __riscv_ztt_scalar_make_i16_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_u32_rod_sat (float c)
{
  __riscv_ztt_u32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_mmulneg_ew_x_u32_rod_sat_1x1_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_f16_rne (carrier_u32 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_f16_rne_2x1_t d = __riscv_ztt_mmulneg_ew_x_f16_rne_2x1_u32_rdn_sat (b, __riscv_ztt_scalar_make_u32_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_f16_rtz (carrier_u64 c)
{
  __riscv_ztt_f16_rtz_1x2_t b = __riscv_ztt_mzero_m_f16_rtz_1x2 ();
  __riscv_ztt_f16_rtz_1x2_t d = __riscv_ztt_mmulneg_ew_x_f16_rtz_1x2_u64_rne_sat (b, __riscv_ztt_scalar_from_bits_u64_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_f16_rdn (carrier_u128 c)
{
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_mmulneg_ew_x_f16_rdn_1x1_u128_rnu_sat (b, __riscv_ztt_scalar_from_bits_u128_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_f16_rup (_Float16 c)
{
  __riscv_ztt_f16_rup_1x2_t b = __riscv_ztt_mzero_m_f16_rup_1x2 ();
  __riscv_ztt_f16_rup_1x2_t d = __riscv_ztt_mmulneg_ew_x_f16_rup_1x2_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_f16_rmm (__bf16 c)
{
  __riscv_ztt_f16_rmm_2x1_t b = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_f16_rmm_2x1_t d = __riscv_ztt_mmulneg_ew_x_f16_rmm_2x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_f16_rno (float c)
{
  __riscv_ztt_f16_rno_1x1_t b = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mmulneg_ew_x_f16_rno_1x1_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_bf16_rne (carrier_i8 c)
{
  __riscv_ztt_bf16_rne_2x1_t b = __riscv_ztt_mzero_m_bf16_rne_2x1 ();
  __riscv_ztt_bf16_rne_2x1_t d = __riscv_ztt_mmulneg_ew_x_bf16_rne_2x1_i8_rnu (b, __riscv_ztt_scalar_make_i8_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_bf16_rtz (carrier_u8 c)
{
  __riscv_ztt_bf16_rtz_1x2_t b = __riscv_ztt_mzero_m_bf16_rtz_1x2 ();
  __riscv_ztt_bf16_rtz_1x2_t d = __riscv_ztt_mmulneg_ew_x_bf16_rtz_1x2_u8_rod (b, __riscv_ztt_scalar_make_u8_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_bf16_rdn (carrier_u16 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t d = __riscv_ztt_mmulneg_ew_x_bf16_rdn_1x1_u16_rdn (b, __riscv_ztt_scalar_make_u16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_bf16_rup (carrier_u32 c)
{
  __riscv_ztt_bf16_rup_1x2_t b = __riscv_ztt_mzero_m_bf16_rup_1x2 ();
  __riscv_ztt_bf16_rup_1x2_t d = __riscv_ztt_mmulneg_ew_x_bf16_rup_1x2_u32_rne (b, __riscv_ztt_scalar_make_u32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_bf16_rmm (carrier_u64 c)
{
  __riscv_ztt_bf16_rmm_2x1_t b = __riscv_ztt_mzero_m_bf16_rmm_2x1 ();
  __riscv_ztt_bf16_rmm_2x1_t d = __riscv_ztt_mmulneg_ew_x_bf16_rmm_2x1_u64_rnu (b, __riscv_ztt_scalar_from_bits_u64_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_bf16_rno (carrier_i128 c)
{
  __riscv_ztt_bf16_rno_1x1_t b = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t d = __riscv_ztt_mmulneg_ew_x_bf16_rno_1x1_i128_rod (b, __riscv_ztt_scalar_from_bits_i128_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_f32_rne (carrier_i8 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mmulneg_ew_x_f32_rne_1x1_i8_rdn_sat (b, __riscv_ztt_scalar_make_i8_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_f32_rtz (carrier_i16 c)
{
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mmulneg_ew_x_f32_rtz_1x1_i16_rne_sat (b, __riscv_ztt_scalar_make_i16_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_f32_rdn (carrier_i32 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mmulneg_ew_x_f32_rdn_1x1_i32_rnu_sat (b, __riscv_ztt_scalar_make_i32_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_f32_rup (carrier_u32 c)
{
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mmulneg_ew_x_f32_rup_1x1_u32_rod_sat (b, __riscv_ztt_scalar_make_u32_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_f32_rmm (carrier_u64 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mmulneg_ew_x_f32_rmm_1x1_u64_rdn_sat (b, __riscv_ztt_scalar_from_bits_u64_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulneg_f32_rno (carrier_u128 c)
{
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mmulneg_ew_x_f32_rno_1x1_u128_rne_sat (b, __riscv_ztt_scalar_from_bits_u128_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i4_rnu (__bf16 c)
{
  __riscv_ztt_i4_rnu_1x4_t b = __riscv_ztt_mzero_m_i4_rnu_1x4 ();
  __riscv_ztt_i4_rnu_1x4_t d = __riscv_ztt_mmin_ew_x_i4_rnu_1x4_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i4_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rne_8x1_t b = __riscv_ztt_mzero_m_i4_rne_8x1 ();
  __riscv_ztt_i4_rne_8x1_t d = __riscv_ztt_mmin_ew_x_i4_rne_8x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i4_rdn (_Float16 c)
{
  __riscv_ztt_i4_rdn_1x2_t b = __riscv_ztt_mzero_m_i4_rdn_1x2 ();
  __riscv_ztt_i4_rdn_1x2_t d = __riscv_ztt_mmin_ew_x_i4_rdn_1x2_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i4_rod (__bf16 c)
{
  __riscv_ztt_i4_rod_4x1_t b = __riscv_ztt_mzero_m_i4_rod_4x1 ();
  __riscv_ztt_i4_rod_4x1_t d = __riscv_ztt_mmin_ew_x_i4_rod_4x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u4_rnu (float c)
{
  __riscv_ztt_u4_rnu_1x8_t b = __riscv_ztt_mzero_m_u4_rnu_1x8 ();
  __riscv_ztt_u4_rnu_1x8_t d = __riscv_ztt_mmin_ew_x_u4_rnu_1x8_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u4_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rne_2x1_t b = __riscv_ztt_mzero_m_u4_rne_2x1 ();
  __riscv_ztt_u4_rne_2x1_t d = __riscv_ztt_mmin_ew_x_u4_rne_2x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u4_rdn (_Float16 c)
{
  __riscv_ztt_u4_rdn_1x4_t b = __riscv_ztt_mzero_m_u4_rdn_1x4 ();
  __riscv_ztt_u4_rdn_1x4_t d = __riscv_ztt_mmin_ew_x_u4_rdn_1x4_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u4_rod (float c)
{
  __riscv_ztt_u4_rod_8x1_t b = __riscv_ztt_mzero_m_u4_rod_8x1 ();
  __riscv_ztt_u4_rod_8x1_t d = __riscv_ztt_mmin_ew_x_u4_rod_8x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i8_rnu (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rnu_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t d = __riscv_ztt_mmin_ew_x_i8_rnu_1x1_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i8_rne (_Float16 c)
{
  __riscv_ztt_i8_rne_2x1_t b = __riscv_ztt_mzero_m_i8_rne_2x1 ();
  __riscv_ztt_i8_rne_2x1_t d = __riscv_ztt_mmin_ew_x_i8_rne_2x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i8_rdn (__bf16 c)
{
  __riscv_ztt_i8_rdn_1x4_t b = __riscv_ztt_mzero_m_i8_rdn_1x4 ();
  __riscv_ztt_i8_rdn_1x4_t d = __riscv_ztt_mmin_ew_x_i8_rdn_1x4_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i8_rod (float c)
{
  __riscv_ztt_i8_rod_1x1_t b = __riscv_ztt_mzero_m_i8_rod_1x1 ();
  __riscv_ztt_i8_rod_1x1_t d = __riscv_ztt_mmin_ew_x_i8_rod_1x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u8_rnu (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rnu_1x2_t b = __riscv_ztt_mzero_m_u8_rnu_1x2 ();
  __riscv_ztt_u8_rnu_1x2_t d = __riscv_ztt_mmin_ew_x_u8_rnu_1x2_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u8_rne (__bf16 c)
{
  __riscv_ztt_u8_rne_4x1_t b = __riscv_ztt_mzero_m_u8_rne_4x1 ();
  __riscv_ztt_u8_rne_4x1_t d = __riscv_ztt_mmin_ew_x_u8_rne_4x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u8_rdn (float c)
{
  __riscv_ztt_u8_rdn_1x1_t b = __riscv_ztt_mzero_m_u8_rdn_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t d = __riscv_ztt_mmin_ew_x_u8_rdn_1x1_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u8_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rod_2x1_t b = __riscv_ztt_mzero_m_u8_rod_2x1 ();
  __riscv_ztt_u8_rod_2x1_t d = __riscv_ztt_mmin_ew_x_u8_rod_2x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i16_rnu (_Float16 c)
{
  __riscv_ztt_i16_rnu_1x2_t b = __riscv_ztt_mzero_m_i16_rnu_1x2 ();
  __riscv_ztt_i16_rnu_1x2_t d = __riscv_ztt_mmin_ew_x_i16_rnu_1x2_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i16_rne (__bf16 c)
{
  __riscv_ztt_i16_rne_1x1_t b = __riscv_ztt_mzero_m_i16_rne_1x1 ();
  __riscv_ztt_i16_rne_1x1_t d = __riscv_ztt_mmin_ew_x_i16_rne_1x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i16_rdn (float c)
{
  __riscv_ztt_i16_rdn_1x2_t b = __riscv_ztt_mzero_m_i16_rdn_1x2 ();
  __riscv_ztt_i16_rdn_1x2_t d = __riscv_ztt_mmin_ew_x_i16_rdn_1x2_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i16_rod (_Float16 c)
{
  __riscv_ztt_i16_rod_2x1_t b = __riscv_ztt_mzero_m_i16_rod_2x1 ();
  __riscv_ztt_i16_rod_2x1_t d = __riscv_ztt_mmin_ew_x_i16_rod_2x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u16_rnu (__bf16 c)
{
  __riscv_ztt_u16_rnu_1x1_t b = __riscv_ztt_mzero_m_u16_rnu_1x1 ();
  __riscv_ztt_u16_rnu_1x1_t d = __riscv_ztt_mmin_ew_x_u16_rnu_1x1_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u16_rne (float c)
{
  __riscv_ztt_u16_rne_2x1_t b = __riscv_ztt_mzero_m_u16_rne_2x1 ();
  __riscv_ztt_u16_rne_2x1_t d = __riscv_ztt_mmin_ew_x_u16_rne_2x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u16_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rdn_1x2_t b = __riscv_ztt_mzero_m_u16_rdn_1x2 ();
  __riscv_ztt_u16_rdn_1x2_t d = __riscv_ztt_mmin_ew_x_u16_rdn_1x2_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u16_rod (_Float16 c)
{
  __riscv_ztt_u16_rod_1x1_t b = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_u16_rod_1x1_t d = __riscv_ztt_mmin_ew_x_u16_rod_1x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i32_rnu (__bf16 c)
{
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mmin_ew_x_i32_rnu_1x1_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i32_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_mmin_ew_x_i32_rne_1x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i32_rdn (_Float16 c)
{
  __riscv_ztt_i32_rdn_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_mmin_ew_x_i32_rdn_1x1_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i32_rod (__bf16 c)
{
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mmin_ew_x_i32_rod_1x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u32_rnu (float c)
{
  __riscv_ztt_u32_rnu_1x1_t b = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mmin_ew_x_u32_rnu_1x1_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u32_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_mmin_ew_x_u32_rne_1x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u32_rdn (_Float16 c)
{
  __riscv_ztt_u32_rdn_1x1_t b = __riscv_ztt_mzero_m_u32_rdn_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mmin_ew_x_u32_rdn_1x1_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u32_rod (float c)
{
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_mmin_ew_x_u32_rod_1x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i4_rnu_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rnu_sat_1x2_t b = __riscv_ztt_mzero_m_i4_rnu_sat_1x2 ();
  __riscv_ztt_i4_rnu_sat_1x2_t d = __riscv_ztt_mmin_ew_x_i4_rnu_sat_1x2_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i4_rne_sat (_Float16 c)
{
  __riscv_ztt_i4_rne_sat_4x1_t b = __riscv_ztt_mzero_m_i4_rne_sat_4x1 ();
  __riscv_ztt_i4_rne_sat_4x1_t d = __riscv_ztt_mmin_ew_x_i4_rne_sat_4x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i4_rdn_sat (__bf16 c)
{
  __riscv_ztt_i4_rdn_sat_1x8_t b = __riscv_ztt_mzero_m_i4_rdn_sat_1x8 ();
  __riscv_ztt_i4_rdn_sat_1x8_t d = __riscv_ztt_mmin_ew_x_i4_rdn_sat_1x8_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i4_rod_sat (float c)
{
  __riscv_ztt_i4_rod_sat_2x1_t b = __riscv_ztt_mzero_m_i4_rod_sat_2x1 ();
  __riscv_ztt_i4_rod_sat_2x1_t d = __riscv_ztt_mmin_ew_x_i4_rod_sat_2x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u4_rnu_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rnu_sat_1x4_t b = __riscv_ztt_mzero_m_u4_rnu_sat_1x4 ();
  __riscv_ztt_u4_rnu_sat_1x4_t d = __riscv_ztt_mmin_ew_x_u4_rnu_sat_1x4_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u4_rne_sat (__bf16 c)
{
  __riscv_ztt_u4_rne_sat_8x1_t b = __riscv_ztt_mzero_m_u4_rne_sat_8x1 ();
  __riscv_ztt_u4_rne_sat_8x1_t d = __riscv_ztt_mmin_ew_x_u4_rne_sat_8x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u4_rdn_sat (float c)
{
  __riscv_ztt_u4_rdn_sat_1x2_t b = __riscv_ztt_mzero_m_u4_rdn_sat_1x2 ();
  __riscv_ztt_u4_rdn_sat_1x2_t d = __riscv_ztt_mmin_ew_x_u4_rdn_sat_1x2_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u4_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rod_sat_4x1_t b = __riscv_ztt_mzero_m_u4_rod_sat_4x1 ();
  __riscv_ztt_u4_rod_sat_4x1_t d = __riscv_ztt_mmin_ew_x_u4_rod_sat_4x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i8_rnu_sat (_Float16 c)
{
  __riscv_ztt_i8_rnu_sat_1x4_t b = __riscv_ztt_mzero_m_i8_rnu_sat_1x4 ();
  __riscv_ztt_i8_rnu_sat_1x4_t d = __riscv_ztt_mmin_ew_x_i8_rnu_sat_1x4_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i8_rne_sat (__bf16 c)
{
  __riscv_ztt_i8_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rne_sat_1x1 ();
  __riscv_ztt_i8_rne_sat_1x1_t d = __riscv_ztt_mmin_ew_x_i8_rne_sat_1x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i8_rdn_sat (float c)
{
  __riscv_ztt_i8_rdn_sat_1x2_t b = __riscv_ztt_mzero_m_i8_rdn_sat_1x2 ();
  __riscv_ztt_i8_rdn_sat_1x2_t d = __riscv_ztt_mmin_ew_x_i8_rdn_sat_1x2_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i8_rod_sat (_Float16 c)
{
  __riscv_ztt_i8_rod_sat_4x1_t b = __riscv_ztt_mzero_m_i8_rod_sat_4x1 ();
  __riscv_ztt_i8_rod_sat_4x1_t d = __riscv_ztt_mmin_ew_x_i8_rod_sat_4x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u8_rnu_sat (__bf16 c)
{
  __riscv_ztt_u8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rnu_sat_1x1 ();
  __riscv_ztt_u8_rnu_sat_1x1_t d = __riscv_ztt_mmin_ew_x_u8_rnu_sat_1x1_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u8_rne_sat (float c)
{
  __riscv_ztt_u8_rne_sat_2x1_t b = __riscv_ztt_mzero_m_u8_rne_sat_2x1 ();
  __riscv_ztt_u8_rne_sat_2x1_t d = __riscv_ztt_mmin_ew_x_u8_rne_sat_2x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u8_rdn_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rdn_sat_1x4_t b = __riscv_ztt_mzero_m_u8_rdn_sat_1x4 ();
  __riscv_ztt_u8_rdn_sat_1x4_t d = __riscv_ztt_mmin_ew_x_u8_rdn_sat_1x4_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u8_rod_sat (_Float16 c)
{
  __riscv_ztt_u8_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rod_sat_1x1 ();
  __riscv_ztt_u8_rod_sat_1x1_t d = __riscv_ztt_mmin_ew_x_u8_rod_sat_1x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i16_rnu_sat (__bf16 c)
{
  __riscv_ztt_i16_rnu_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rnu_sat_1x2 ();
  __riscv_ztt_i16_rnu_sat_1x2_t d = __riscv_ztt_mmin_ew_x_i16_rnu_sat_1x2_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i16_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rne_sat_2x1_t b = __riscv_ztt_mzero_m_i16_rne_sat_2x1 ();
  __riscv_ztt_i16_rne_sat_2x1_t d = __riscv_ztt_mmin_ew_x_i16_rne_sat_2x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i16_rdn_sat (_Float16 c)
{
  __riscv_ztt_i16_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rdn_sat_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t d = __riscv_ztt_mmin_ew_x_i16_rdn_sat_1x1_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i16_rod_sat (__bf16 c)
{
  __riscv_ztt_i16_rod_sat_2x1_t b = __riscv_ztt_mzero_m_i16_rod_sat_2x1 ();
  __riscv_ztt_i16_rod_sat_2x1_t d = __riscv_ztt_mmin_ew_x_i16_rod_sat_2x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u16_rnu_sat (float c)
{
  __riscv_ztt_u16_rnu_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rnu_sat_1x2 ();
  __riscv_ztt_u16_rnu_sat_1x2_t d = __riscv_ztt_mmin_ew_x_u16_rnu_sat_1x2_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u16_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rne_sat_1x1 ();
  __riscv_ztt_u16_rne_sat_1x1_t d = __riscv_ztt_mmin_ew_x_u16_rne_sat_1x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u16_rdn_sat (_Float16 c)
{
  __riscv_ztt_u16_rdn_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rdn_sat_1x2 ();
  __riscv_ztt_u16_rdn_sat_1x2_t d = __riscv_ztt_mmin_ew_x_u16_rdn_sat_1x2_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u16_rod_sat (float c)
{
  __riscv_ztt_u16_rod_sat_2x1_t b = __riscv_ztt_mzero_m_u16_rod_sat_2x1 ();
  __riscv_ztt_u16_rod_sat_2x1_t d = __riscv_ztt_mmin_ew_x_u16_rod_sat_2x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i32_rnu_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rnu_sat_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_mmin_ew_x_i32_rnu_sat_1x1_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i32_rne_sat (_Float16 c)
{
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_mmin_ew_x_i32_rne_sat_1x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i32_rdn_sat (__bf16 c)
{
  __riscv_ztt_i32_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_sat_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mmin_ew_x_i32_rdn_sat_1x1_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_i32_rod_sat (float c)
{
  __riscv_ztt_i32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_mmin_ew_x_i32_rod_sat_1x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u32_rnu_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rnu_sat_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_mmin_ew_x_u32_rnu_sat_1x1_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u32_rne_sat (__bf16 c)
{
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mmin_ew_x_u32_rne_sat_1x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u32_rdn_sat (float c)
{
  __riscv_ztt_u32_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rdn_sat_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_mmin_ew_x_u32_rdn_sat_1x1_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_u32_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_mmin_ew_x_u32_rod_sat_1x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_f16_rne (carrier_i64 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_f16_rne_1x2_t d = __riscv_ztt_mmin_ew_x_f16_rne_1x2_i64_rod_sat (b, __riscv_ztt_scalar_from_bits_i64_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_f16_rtz (carrier_i128 c)
{
  __riscv_ztt_f16_rtz_1x1_t b = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_mmin_ew_x_f16_rtz_1x1_i128_rdn_sat (b, __riscv_ztt_scalar_from_bits_i128_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_f16_rdn (_Float16 c)
{
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_f16_rdn_1x2_t d = __riscv_ztt_mmin_ew_x_f16_rdn_1x2_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_f16_rup (__bf16 c)
{
  __riscv_ztt_f16_rup_2x1_t b = __riscv_ztt_mzero_m_f16_rup_2x1 ();
  __riscv_ztt_f16_rup_2x1_t d = __riscv_ztt_mmin_ew_x_f16_rup_2x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_f16_rmm (float c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mmin_ew_x_f16_rmm_1x1_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_f16_rno (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f16_rno_2x1_t b = __riscv_ztt_mzero_m_f16_rno_2x1 ();
  __riscv_ztt_f16_rno_2x1_t d = __riscv_ztt_mmin_ew_x_f16_rno_2x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_bf16_rne (carrier_u8 c)
{
  __riscv_ztt_bf16_rne_1x2_t b = __riscv_ztt_mzero_m_bf16_rne_1x2 ();
  __riscv_ztt_bf16_rne_1x2_t d = __riscv_ztt_mmin_ew_x_bf16_rne_1x2_u8_rne (b, __riscv_ztt_scalar_make_u8_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_bf16_rtz (carrier_u16 c)
{
  __riscv_ztt_bf16_rtz_1x1_t b = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t d = __riscv_ztt_mmin_ew_x_bf16_rtz_1x1_u16_rnu (b, __riscv_ztt_scalar_make_u16_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_bf16_rdn (carrier_i32 c)
{
  __riscv_ztt_bf16_rdn_1x2_t b = __riscv_ztt_mzero_m_bf16_rdn_1x2 ();
  __riscv_ztt_bf16_rdn_1x2_t d = __riscv_ztt_mmin_ew_x_bf16_rdn_1x2_i32_rod (b, __riscv_ztt_scalar_make_i32_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_bf16_rup (carrier_i64 c)
{
  __riscv_ztt_bf16_rup_2x1_t b = __riscv_ztt_mzero_m_bf16_rup_2x1 ();
  __riscv_ztt_bf16_rup_2x1_t d = __riscv_ztt_mmin_ew_x_bf16_rup_2x1_i64_rdn (b, __riscv_ztt_scalar_from_bits_i64_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_bf16_rmm (carrier_i128 c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_bf16_rmm_1x1_t d = __riscv_ztt_mmin_ew_x_bf16_rmm_1x1_i128_rne (b, __riscv_ztt_scalar_from_bits_i128_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_bf16_rno (carrier_i8 c)
{
  __riscv_ztt_bf16_rno_2x1_t b = __riscv_ztt_mzero_m_bf16_rno_2x1 ();
  __riscv_ztt_bf16_rno_2x1_t d = __riscv_ztt_mmin_ew_x_bf16_rno_2x1_i8_rnu_sat (b, __riscv_ztt_scalar_make_i8_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_f32_rne (carrier_u8 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mmin_ew_x_f32_rne_1x1_u8_rod_sat (b, __riscv_ztt_scalar_make_u8_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_f32_rtz (carrier_u16 c)
{
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mmin_ew_x_f32_rtz_1x1_u16_rdn_sat (b, __riscv_ztt_scalar_make_u16_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_f32_rdn (carrier_u32 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mmin_ew_x_f32_rdn_1x1_u32_rne_sat (b, __riscv_ztt_scalar_make_u32_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_f32_rup (carrier_u64 c)
{
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mmin_ew_x_f32_rup_1x1_u64_rnu_sat (b, __riscv_ztt_scalar_from_bits_u64_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_f32_rmm (carrier_i128 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mmin_ew_x_f32_rmm_1x1_i128_rod_sat (b, __riscv_ztt_scalar_from_bits_i128_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmin_f32_rno (_Float16 c)
{
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mmin_ew_x_f32_rno_1x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i4_rnu (float c)
{
  __riscv_ztt_i4_rnu_8x1_t b = __riscv_ztt_mzero_m_i4_rnu_8x1 ();
  __riscv_ztt_i4_rnu_8x1_t d = __riscv_ztt_mmax_ew_x_i4_rnu_8x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i4_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rne_1x2_t b = __riscv_ztt_mzero_m_i4_rne_1x2 ();
  __riscv_ztt_i4_rne_1x2_t d = __riscv_ztt_mmax_ew_x_i4_rne_1x2_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i4_rdn (__bf16 c)
{
  __riscv_ztt_i4_rdn_4x1_t b = __riscv_ztt_mzero_m_i4_rdn_4x1 ();
  __riscv_ztt_i4_rdn_4x1_t d = __riscv_ztt_mmax_ew_x_i4_rdn_4x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i4_rod (float c)
{
  __riscv_ztt_i4_rod_1x8_t b = __riscv_ztt_mzero_m_i4_rod_1x8 ();
  __riscv_ztt_i4_rod_1x8_t d = __riscv_ztt_mmax_ew_x_i4_rod_1x8_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u4_rnu (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rnu_2x1_t b = __riscv_ztt_mzero_m_u4_rnu_2x1 ();
  __riscv_ztt_u4_rnu_2x1_t d = __riscv_ztt_mmax_ew_x_u4_rnu_2x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u4_rne (_Float16 c)
{
  __riscv_ztt_u4_rne_1x4_t b = __riscv_ztt_mzero_m_u4_rne_1x4 ();
  __riscv_ztt_u4_rne_1x4_t d = __riscv_ztt_mmax_ew_x_u4_rne_1x4_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u4_rdn (__bf16 c)
{
  __riscv_ztt_u4_rdn_8x1_t b = __riscv_ztt_mzero_m_u4_rdn_8x1 ();
  __riscv_ztt_u4_rdn_8x1_t d = __riscv_ztt_mmax_ew_x_u4_rdn_8x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u4_rod (float c)
{
  __riscv_ztt_u4_rod_1x2_t b = __riscv_ztt_mzero_m_u4_rod_1x2 ();
  __riscv_ztt_u4_rod_1x2_t d = __riscv_ztt_mmax_ew_x_u4_rod_1x2_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i8_rnu (_Float16 c)
{
  __riscv_ztt_i8_rnu_2x1_t b = __riscv_ztt_mzero_m_i8_rnu_2x1 ();
  __riscv_ztt_i8_rnu_2x1_t d = __riscv_ztt_mmax_ew_x_i8_rnu_2x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i8_rne (__bf16 c)
{
  __riscv_ztt_i8_rne_1x4_t b = __riscv_ztt_mzero_m_i8_rne_1x4 ();
  __riscv_ztt_i8_rne_1x4_t d = __riscv_ztt_mmax_ew_x_i8_rne_1x4_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i8_rdn (float c)
{
  __riscv_ztt_i8_rdn_1x1_t b = __riscv_ztt_mzero_m_i8_rdn_1x1 ();
  __riscv_ztt_i8_rdn_1x1_t d = __riscv_ztt_mmax_ew_x_i8_rdn_1x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i8_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rod_1x2_t b = __riscv_ztt_mzero_m_i8_rod_1x2 ();
  __riscv_ztt_i8_rod_1x2_t d = __riscv_ztt_mmax_ew_x_i8_rod_1x2_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u8_rnu (_Float16 c)
{
  __riscv_ztt_u8_rnu_4x1_t b = __riscv_ztt_mzero_m_u8_rnu_4x1 ();
  __riscv_ztt_u8_rnu_4x1_t d = __riscv_ztt_mmax_ew_x_u8_rnu_4x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u8_rne (__bf16 c)
{
  __riscv_ztt_u8_rne_1x1_t b = __riscv_ztt_mzero_m_u8_rne_1x1 ();
  __riscv_ztt_u8_rne_1x1_t d = __riscv_ztt_mmax_ew_x_u8_rne_1x1_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u8_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rdn_2x1_t b = __riscv_ztt_mzero_m_u8_rdn_2x1 ();
  __riscv_ztt_u8_rdn_2x1_t d = __riscv_ztt_mmax_ew_x_u8_rdn_2x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u8_rod (_Float16 c)
{
  __riscv_ztt_u8_rod_1x4_t b = __riscv_ztt_mzero_m_u8_rod_1x4 ();
  __riscv_ztt_u8_rod_1x4_t d = __riscv_ztt_mmax_ew_x_u8_rod_1x4_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i16_rnu (__bf16 c)
{
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t d = __riscv_ztt_mmax_ew_x_i16_rnu_1x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i16_rne (float c)
{
  __riscv_ztt_i16_rne_1x2_t b = __riscv_ztt_mzero_m_i16_rne_1x2 ();
  __riscv_ztt_i16_rne_1x2_t d = __riscv_ztt_mmax_ew_x_i16_rne_1x2_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i16_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rdn_2x1_t b = __riscv_ztt_mzero_m_i16_rdn_2x1 ();
  __riscv_ztt_i16_rdn_2x1_t d = __riscv_ztt_mmax_ew_x_i16_rdn_2x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i16_rod (_Float16 c)
{
  __riscv_ztt_i16_rod_1x1_t b = __riscv_ztt_mzero_m_i16_rod_1x1 ();
  __riscv_ztt_i16_rod_1x1_t d = __riscv_ztt_mmax_ew_x_i16_rod_1x1_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u16_rnu (float c)
{
  __riscv_ztt_u16_rnu_2x1_t b = __riscv_ztt_mzero_m_u16_rnu_2x1 ();
  __riscv_ztt_u16_rnu_2x1_t d = __riscv_ztt_mmax_ew_x_u16_rnu_2x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u16_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rne_1x2_t b = __riscv_ztt_mzero_m_u16_rne_1x2 ();
  __riscv_ztt_u16_rne_1x2_t d = __riscv_ztt_mmax_ew_x_u16_rne_1x2_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u16_rdn (_Float16 c)
{
  __riscv_ztt_u16_rdn_1x1_t b = __riscv_ztt_mzero_m_u16_rdn_1x1 ();
  __riscv_ztt_u16_rdn_1x1_t d = __riscv_ztt_mmax_ew_x_u16_rdn_1x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u16_rod (__bf16 c)
{
  __riscv_ztt_u16_rod_1x2_t b = __riscv_ztt_mzero_m_u16_rod_1x2 ();
  __riscv_ztt_u16_rod_1x2_t d = __riscv_ztt_mmax_ew_x_u16_rod_1x2_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i32_rnu (float c)
{
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mmax_ew_x_i32_rnu_1x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i32_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_mmax_ew_x_i32_rne_1x1_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i32_rdn (__bf16 c)
{
  __riscv_ztt_i32_rdn_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_mmax_ew_x_i32_rdn_1x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i32_rod (float c)
{
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mmax_ew_x_i32_rod_1x1_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u32_rnu (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rnu_1x1_t b = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mmax_ew_x_u32_rnu_1x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u32_rne (_Float16 c)
{
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_mmax_ew_x_u32_rne_1x1_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u32_rdn (__bf16 c)
{
  __riscv_ztt_u32_rdn_1x1_t b = __riscv_ztt_mzero_m_u32_rdn_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mmax_ew_x_u32_rdn_1x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u32_rod (float c)
{
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_mmax_ew_x_u32_rod_1x1_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i4_rnu_sat (_Float16 c)
{
  __riscv_ztt_i4_rnu_sat_4x1_t b = __riscv_ztt_mzero_m_i4_rnu_sat_4x1 ();
  __riscv_ztt_i4_rnu_sat_4x1_t d = __riscv_ztt_mmax_ew_x_i4_rnu_sat_4x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i4_rne_sat (__bf16 c)
{
  __riscv_ztt_i4_rne_sat_1x8_t b = __riscv_ztt_mzero_m_i4_rne_sat_1x8 ();
  __riscv_ztt_i4_rne_sat_1x8_t d = __riscv_ztt_mmax_ew_x_i4_rne_sat_1x8_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i4_rdn_sat (float c)
{
  __riscv_ztt_i4_rdn_sat_2x1_t b = __riscv_ztt_mzero_m_i4_rdn_sat_2x1 ();
  __riscv_ztt_i4_rdn_sat_2x1_t d = __riscv_ztt_mmax_ew_x_i4_rdn_sat_2x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i4_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rod_sat_1x4_t b = __riscv_ztt_mzero_m_i4_rod_sat_1x4 ();
  __riscv_ztt_i4_rod_sat_1x4_t d = __riscv_ztt_mmax_ew_x_i4_rod_sat_1x4_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u4_rnu_sat (_Float16 c)
{
  __riscv_ztt_u4_rnu_sat_8x1_t b = __riscv_ztt_mzero_m_u4_rnu_sat_8x1 ();
  __riscv_ztt_u4_rnu_sat_8x1_t d = __riscv_ztt_mmax_ew_x_u4_rnu_sat_8x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u4_rne_sat (__bf16 c)
{
  __riscv_ztt_u4_rne_sat_1x2_t b = __riscv_ztt_mzero_m_u4_rne_sat_1x2 ();
  __riscv_ztt_u4_rne_sat_1x2_t d = __riscv_ztt_mmax_ew_x_u4_rne_sat_1x2_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u4_rdn_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rdn_sat_4x1_t b = __riscv_ztt_mzero_m_u4_rdn_sat_4x1 ();
  __riscv_ztt_u4_rdn_sat_4x1_t d = __riscv_ztt_mmax_ew_x_u4_rdn_sat_4x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u4_rod_sat (_Float16 c)
{
  __riscv_ztt_u4_rod_sat_1x8_t b = __riscv_ztt_mzero_m_u4_rod_sat_1x8 ();
  __riscv_ztt_u4_rod_sat_1x8_t d = __riscv_ztt_mmax_ew_x_u4_rod_sat_1x8_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i8_rnu_sat (__bf16 c)
{
  __riscv_ztt_i8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t d = __riscv_ztt_mmax_ew_x_i8_rnu_sat_1x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i8_rne_sat (float c)
{
  __riscv_ztt_i8_rne_sat_1x2_t b = __riscv_ztt_mzero_m_i8_rne_sat_1x2 ();
  __riscv_ztt_i8_rne_sat_1x2_t d = __riscv_ztt_mmax_ew_x_i8_rne_sat_1x2_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i8_rdn_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rdn_sat_4x1_t b = __riscv_ztt_mzero_m_i8_rdn_sat_4x1 ();
  __riscv_ztt_i8_rdn_sat_4x1_t d = __riscv_ztt_mmax_ew_x_i8_rdn_sat_4x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i8_rod_sat (_Float16 c)
{
  __riscv_ztt_i8_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rod_sat_1x1 ();
  __riscv_ztt_i8_rod_sat_1x1_t d = __riscv_ztt_mmax_ew_x_i8_rod_sat_1x1_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u8_rnu_sat (float c)
{
  __riscv_ztt_u8_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_u8_rnu_sat_2x1 ();
  __riscv_ztt_u8_rnu_sat_2x1_t d = __riscv_ztt_mmax_ew_x_u8_rnu_sat_2x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u8_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rne_sat_1x4_t b = __riscv_ztt_mzero_m_u8_rne_sat_1x4 ();
  __riscv_ztt_u8_rne_sat_1x4_t d = __riscv_ztt_mmax_ew_x_u8_rne_sat_1x4_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u8_rdn_sat (_Float16 c)
{
  __riscv_ztt_u8_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rdn_sat_1x1 ();
  __riscv_ztt_u8_rdn_sat_1x1_t d = __riscv_ztt_mmax_ew_x_u8_rdn_sat_1x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u8_rod_sat (__bf16 c)
{
  __riscv_ztt_u8_rod_sat_1x2_t b = __riscv_ztt_mzero_m_u8_rod_sat_1x2 ();
  __riscv_ztt_u8_rod_sat_1x2_t d = __riscv_ztt_mmax_ew_x_u8_rod_sat_1x2_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i16_rnu_sat (float c)
{
  __riscv_ztt_i16_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_i16_rnu_sat_2x1 ();
  __riscv_ztt_i16_rnu_sat_2x1_t d = __riscv_ztt_mmax_ew_x_i16_rnu_sat_2x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i16_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rne_sat_1x1 ();
  __riscv_ztt_i16_rne_sat_1x1_t d = __riscv_ztt_mmax_ew_x_i16_rne_sat_1x1_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i16_rdn_sat (__bf16 c)
{
  __riscv_ztt_i16_rdn_sat_2x1_t b = __riscv_ztt_mzero_m_i16_rdn_sat_2x1 ();
  __riscv_ztt_i16_rdn_sat_2x1_t d = __riscv_ztt_mmax_ew_x_i16_rdn_sat_2x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i16_rod_sat (float c)
{
  __riscv_ztt_i16_rod_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rod_sat_1x2 ();
  __riscv_ztt_i16_rod_sat_1x2_t d = __riscv_ztt_mmax_ew_x_i16_rod_sat_1x2_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u16_rnu_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rnu_sat_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t d = __riscv_ztt_mmax_ew_x_u16_rnu_sat_1x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u16_rne_sat (_Float16 c)
{
  __riscv_ztt_u16_rne_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rne_sat_1x2 ();
  __riscv_ztt_u16_rne_sat_1x2_t d = __riscv_ztt_mmax_ew_x_u16_rne_sat_1x2_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u16_rdn_sat (__bf16 c)
{
  __riscv_ztt_u16_rdn_sat_2x1_t b = __riscv_ztt_mzero_m_u16_rdn_sat_2x1 ();
  __riscv_ztt_u16_rdn_sat_2x1_t d = __riscv_ztt_mmax_ew_x_u16_rdn_sat_2x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u16_rod_sat (float c)
{
  __riscv_ztt_u16_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rod_sat_1x1 ();
  __riscv_ztt_u16_rod_sat_1x1_t d = __riscv_ztt_mmax_ew_x_u16_rod_sat_1x1_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i32_rnu_sat (_Float16 c)
{
  __riscv_ztt_i32_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rnu_sat_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_mmax_ew_x_i32_rnu_sat_1x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i32_rne_sat (__bf16 c)
{
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_mmax_ew_x_i32_rne_sat_1x1_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i32_rdn_sat (float c)
{
  __riscv_ztt_i32_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_sat_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mmax_ew_x_i32_rdn_sat_1x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_i32_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_mmax_ew_x_i32_rod_sat_1x1_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u32_rnu_sat (_Float16 c)
{
  __riscv_ztt_u32_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rnu_sat_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_mmax_ew_x_u32_rnu_sat_1x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u32_rne_sat (__bf16 c)
{
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mmax_ew_x_u32_rne_sat_1x1_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u32_rdn_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rdn_sat_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_mmax_ew_x_u32_rdn_sat_1x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_u32_rod_sat (_Float16 c)
{
  __riscv_ztt_u32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_mmax_ew_x_u32_rod_sat_1x1_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_f16_rne (carrier_i128 c)
{
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_f16_rne_1x1_t d = __riscv_ztt_mmax_ew_x_f16_rne_1x1_i128_rnu_sat (b, __riscv_ztt_scalar_from_bits_i128_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_f16_rtz (carrier_u128 c)
{
  __riscv_ztt_f16_rtz_1x2_t b = __riscv_ztt_mzero_m_f16_rtz_1x2 ();
  __riscv_ztt_f16_rtz_1x2_t d = __riscv_ztt_mmax_ew_x_f16_rtz_1x2_u128_rod_sat (b, __riscv_ztt_scalar_from_bits_u128_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_f16_rdn (__bf16 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_f16_rdn_2x1_t d = __riscv_ztt_mmax_ew_x_f16_rdn_2x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_f16_rup (float c)
{
  __riscv_ztt_f16_rup_1x1_t b = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_f16_rup_1x1_t d = __riscv_ztt_mmax_ew_x_f16_rup_1x1_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_f16_rmm (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f16_rmm_2x1_t b = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_f16_rmm_2x1_t d = __riscv_ztt_mmax_ew_x_f16_rmm_2x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_f16_rno (carrier_i8 c)
{
  __riscv_ztt_f16_rno_1x2_t b = __riscv_ztt_mzero_m_f16_rno_1x2 ();
  __riscv_ztt_f16_rno_1x2_t d = __riscv_ztt_mmax_ew_x_f16_rno_1x2_i8_rod (b, __riscv_ztt_scalar_make_i8_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_bf16_rne (carrier_i16 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t d = __riscv_ztt_mmax_ew_x_bf16_rne_1x1_i16_rdn (b, __riscv_ztt_scalar_make_i16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_bf16_rtz (carrier_i32 c)
{
  __riscv_ztt_bf16_rtz_1x2_t b = __riscv_ztt_mzero_m_bf16_rtz_1x2 ();
  __riscv_ztt_bf16_rtz_1x2_t d = __riscv_ztt_mmax_ew_x_bf16_rtz_1x2_i32_rne (b, __riscv_ztt_scalar_make_i32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_bf16_rdn (carrier_i64 c)
{
  __riscv_ztt_bf16_rdn_2x1_t b = __riscv_ztt_mzero_m_bf16_rdn_2x1 ();
  __riscv_ztt_bf16_rdn_2x1_t d = __riscv_ztt_mmax_ew_x_bf16_rdn_2x1_i64_rnu (b, __riscv_ztt_scalar_from_bits_i64_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_bf16_rup (carrier_u64 c)
{
  __riscv_ztt_bf16_rup_1x1_t b = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_bf16_rup_1x1_t d = __riscv_ztt_mmax_ew_x_bf16_rup_1x1_u64_rod (b, __riscv_ztt_scalar_from_bits_u64_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_bf16_rmm (carrier_u128 c)
{
  __riscv_ztt_bf16_rmm_2x1_t b = __riscv_ztt_mzero_m_bf16_rmm_2x1 ();
  __riscv_ztt_bf16_rmm_2x1_t d = __riscv_ztt_mmax_ew_x_bf16_rmm_2x1_u128_rdn (b, __riscv_ztt_scalar_from_bits_u128_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_bf16_rno (carrier_u8 c)
{
  __riscv_ztt_bf16_rno_1x2_t b = __riscv_ztt_mzero_m_bf16_rno_1x2 ();
  __riscv_ztt_bf16_rno_1x2_t d = __riscv_ztt_mmax_ew_x_bf16_rno_1x2_u8_rne_sat (b, __riscv_ztt_scalar_make_u8_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_f32_rne (carrier_u16 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mmax_ew_x_f32_rne_1x1_u16_rnu_sat (b, __riscv_ztt_scalar_make_u16_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_f32_rtz (carrier_i32 c)
{
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mmax_ew_x_f32_rtz_1x1_i32_rod_sat (b, __riscv_ztt_scalar_make_i32_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_f32_rdn (carrier_i64 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mmax_ew_x_f32_rdn_1x1_i64_rdn_sat (b, __riscv_ztt_scalar_from_bits_i64_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_f32_rup (carrier_i128 c)
{
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mmax_ew_x_f32_rup_1x1_i128_rne_sat (b, __riscv_ztt_scalar_from_bits_i128_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_f32_rmm (_Float16 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mmax_ew_x_f32_rmm_1x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmax_f32_rno (__bf16 c)
{
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mmax_ew_x_f32_rno_1x1_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i4_rnu (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rnu_1x2_t b = __riscv_ztt_mzero_m_i4_rnu_1x2 ();
  __riscv_ztt_i4_rnu_1x2_t d = __riscv_ztt_mand_ew_x_i4_rnu_1x2_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i4_rne (_Float16 c)
{
  __riscv_ztt_i4_rne_4x1_t b = __riscv_ztt_mzero_m_i4_rne_4x1 ();
  __riscv_ztt_i4_rne_4x1_t d = __riscv_ztt_mand_ew_x_i4_rne_4x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i4_rdn (__bf16 c)
{
  __riscv_ztt_i4_rdn_1x8_t b = __riscv_ztt_mzero_m_i4_rdn_1x8 ();
  __riscv_ztt_i4_rdn_1x8_t d = __riscv_ztt_mand_ew_x_i4_rdn_1x8_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i4_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rod_2x1_t b = __riscv_ztt_mzero_m_i4_rod_2x1 ();
  __riscv_ztt_i4_rod_2x1_t d = __riscv_ztt_mand_ew_x_i4_rod_2x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u4_rnu (_Float16 c)
{
  __riscv_ztt_u4_rnu_1x4_t b = __riscv_ztt_mzero_m_u4_rnu_1x4 ();
  __riscv_ztt_u4_rnu_1x4_t d = __riscv_ztt_mand_ew_x_u4_rnu_1x4_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u4_rne (__bf16 c)
{
  __riscv_ztt_u4_rne_8x1_t b = __riscv_ztt_mzero_m_u4_rne_8x1 ();
  __riscv_ztt_u4_rne_8x1_t d = __riscv_ztt_mand_ew_x_u4_rne_8x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u4_rdn (float c)
{
  __riscv_ztt_u4_rdn_1x2_t b = __riscv_ztt_mzero_m_u4_rdn_1x2 ();
  __riscv_ztt_u4_rdn_1x2_t d = __riscv_ztt_mand_ew_x_u4_rdn_1x2_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u4_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rod_4x1_t b = __riscv_ztt_mzero_m_u4_rod_4x1 ();
  __riscv_ztt_u4_rod_4x1_t d = __riscv_ztt_mand_ew_x_u4_rod_4x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i8_rnu (_Float16 c)
{
  __riscv_ztt_i8_rnu_1x4_t b = __riscv_ztt_mzero_m_i8_rnu_1x4 ();
  __riscv_ztt_i8_rnu_1x4_t d = __riscv_ztt_mand_ew_x_i8_rnu_1x4_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i8_rne (float c)
{
  __riscv_ztt_i8_rne_1x1_t b = __riscv_ztt_mzero_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t d = __riscv_ztt_mand_ew_x_i8_rne_1x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i8_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rdn_1x2_t b = __riscv_ztt_mzero_m_i8_rdn_1x2 ();
  __riscv_ztt_i8_rdn_1x2_t d = __riscv_ztt_mand_ew_x_i8_rdn_1x2_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i8_rod (_Float16 c)
{
  __riscv_ztt_i8_rod_4x1_t b = __riscv_ztt_mzero_m_i8_rod_4x1 ();
  __riscv_ztt_i8_rod_4x1_t d = __riscv_ztt_mand_ew_x_i8_rod_4x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u8_rnu (__bf16 c)
{
  __riscv_ztt_u8_rnu_1x1_t b = __riscv_ztt_mzero_m_u8_rnu_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t d = __riscv_ztt_mand_ew_x_u8_rnu_1x1_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u8_rne (float c)
{
  __riscv_ztt_u8_rne_2x1_t b = __riscv_ztt_mzero_m_u8_rne_2x1 ();
  __riscv_ztt_u8_rne_2x1_t d = __riscv_ztt_mand_ew_x_u8_rne_2x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u8_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rdn_1x4_t b = __riscv_ztt_mzero_m_u8_rdn_1x4 ();
  __riscv_ztt_u8_rdn_1x4_t d = __riscv_ztt_mand_ew_x_u8_rdn_1x4_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u8_rod (__bf16 c)
{
  __riscv_ztt_u8_rod_1x1_t b = __riscv_ztt_mzero_m_u8_rod_1x1 ();
  __riscv_ztt_u8_rod_1x1_t d = __riscv_ztt_mand_ew_x_u8_rod_1x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i16_rnu (float c)
{
  __riscv_ztt_i16_rnu_1x2_t b = __riscv_ztt_mzero_m_i16_rnu_1x2 ();
  __riscv_ztt_i16_rnu_1x2_t d = __riscv_ztt_mand_ew_x_i16_rnu_1x2_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i16_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rne_2x1_t b = __riscv_ztt_mzero_m_i16_rne_2x1 ();
  __riscv_ztt_i16_rne_2x1_t d = __riscv_ztt_mand_ew_x_i16_rne_2x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i16_rdn (_Float16 c)
{
  __riscv_ztt_i16_rdn_1x1_t b = __riscv_ztt_mzero_m_i16_rdn_1x1 ();
  __riscv_ztt_i16_rdn_1x1_t d = __riscv_ztt_mand_ew_x_i16_rdn_1x1_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i16_rod (__bf16 c)
{
  __riscv_ztt_i16_rod_2x1_t b = __riscv_ztt_mzero_m_i16_rod_2x1 ();
  __riscv_ztt_i16_rod_2x1_t d = __riscv_ztt_mand_ew_x_i16_rod_2x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u16_rnu (float c)
{
  __riscv_ztt_u16_rnu_1x2_t b = __riscv_ztt_mzero_m_u16_rnu_1x2 ();
  __riscv_ztt_u16_rnu_1x2_t d = __riscv_ztt_mand_ew_x_u16_rnu_1x2_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u16_rne (_Float16 c)
{
  __riscv_ztt_u16_rne_1x1_t b = __riscv_ztt_mzero_m_u16_rne_1x1 ();
  __riscv_ztt_u16_rne_1x1_t d = __riscv_ztt_mand_ew_x_u16_rne_1x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u16_rdn (__bf16 c)
{
  __riscv_ztt_u16_rdn_1x2_t b = __riscv_ztt_mzero_m_u16_rdn_1x2 ();
  __riscv_ztt_u16_rdn_1x2_t d = __riscv_ztt_mand_ew_x_u16_rdn_1x2_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u16_rod (float c)
{
  __riscv_ztt_u16_rod_2x1_t b = __riscv_ztt_mzero_m_u16_rod_2x1 ();
  __riscv_ztt_u16_rod_2x1_t d = __riscv_ztt_mand_ew_x_u16_rod_2x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i32_rnu (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mand_ew_x_i32_rnu_1x1_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i32_rne (_Float16 c)
{
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_mand_ew_x_i32_rne_1x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i32_rdn (__bf16 c)
{
  __riscv_ztt_i32_rdn_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_mand_ew_x_i32_rdn_1x1_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i32_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mand_ew_x_i32_rod_1x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u32_rnu (_Float16 c)
{
  __riscv_ztt_u32_rnu_1x1_t b = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mand_ew_x_u32_rnu_1x1_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u32_rne (__bf16 c)
{
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_mand_ew_x_u32_rne_1x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u32_rdn (float c)
{
  __riscv_ztt_u32_rdn_1x1_t b = __riscv_ztt_mzero_m_u32_rdn_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mand_ew_x_u32_rdn_1x1_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u32_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_mand_ew_x_u32_rod_1x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i4_rnu_sat (_Float16 c)
{
  __riscv_ztt_i4_rnu_sat_1x8_t b = __riscv_ztt_mzero_m_i4_rnu_sat_1x8 ();
  __riscv_ztt_i4_rnu_sat_1x8_t d = __riscv_ztt_mand_ew_x_i4_rnu_sat_1x8_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i4_rne_sat (float c)
{
  __riscv_ztt_i4_rne_sat_2x1_t b = __riscv_ztt_mzero_m_i4_rne_sat_2x1 ();
  __riscv_ztt_i4_rne_sat_2x1_t d = __riscv_ztt_mand_ew_x_i4_rne_sat_2x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i4_rdn_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rdn_sat_1x4_t b = __riscv_ztt_mzero_m_i4_rdn_sat_1x4 ();
  __riscv_ztt_i4_rdn_sat_1x4_t d = __riscv_ztt_mand_ew_x_i4_rdn_sat_1x4_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i4_rod_sat (_Float16 c)
{
  __riscv_ztt_i4_rod_sat_8x1_t b = __riscv_ztt_mzero_m_i4_rod_sat_8x1 ();
  __riscv_ztt_i4_rod_sat_8x1_t d = __riscv_ztt_mand_ew_x_i4_rod_sat_8x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u4_rnu_sat (__bf16 c)
{
  __riscv_ztt_u4_rnu_sat_1x2_t b = __riscv_ztt_mzero_m_u4_rnu_sat_1x2 ();
  __riscv_ztt_u4_rnu_sat_1x2_t d = __riscv_ztt_mand_ew_x_u4_rnu_sat_1x2_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u4_rne_sat (float c)
{
  __riscv_ztt_u4_rne_sat_4x1_t b = __riscv_ztt_mzero_m_u4_rne_sat_4x1 ();
  __riscv_ztt_u4_rne_sat_4x1_t d = __riscv_ztt_mand_ew_x_u4_rne_sat_4x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u4_rdn_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rdn_sat_1x8_t b = __riscv_ztt_mzero_m_u4_rdn_sat_1x8 ();
  __riscv_ztt_u4_rdn_sat_1x8_t d = __riscv_ztt_mand_ew_x_u4_rdn_sat_1x8_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u4_rod_sat (__bf16 c)
{
  __riscv_ztt_u4_rod_sat_2x1_t b = __riscv_ztt_mzero_m_u4_rod_sat_2x1 ();
  __riscv_ztt_u4_rod_sat_2x1_t d = __riscv_ztt_mand_ew_x_u4_rod_sat_2x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i8_rnu_sat (float c)
{
  __riscv_ztt_i8_rnu_sat_1x2_t b = __riscv_ztt_mzero_m_i8_rnu_sat_1x2 ();
  __riscv_ztt_i8_rnu_sat_1x2_t d = __riscv_ztt_mand_ew_x_i8_rnu_sat_1x2_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i8_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rne_sat_4x1_t b = __riscv_ztt_mzero_m_i8_rne_sat_4x1 ();
  __riscv_ztt_i8_rne_sat_4x1_t d = __riscv_ztt_mand_ew_x_i8_rne_sat_4x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i8_rdn_sat (_Float16 c)
{
  __riscv_ztt_i8_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rdn_sat_1x1 ();
  __riscv_ztt_i8_rdn_sat_1x1_t d = __riscv_ztt_mand_ew_x_i8_rdn_sat_1x1_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i8_rod_sat (__bf16 c)
{
  __riscv_ztt_i8_rod_sat_2x1_t b = __riscv_ztt_mzero_m_i8_rod_sat_2x1 ();
  __riscv_ztt_i8_rod_sat_2x1_t d = __riscv_ztt_mand_ew_x_i8_rod_sat_2x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u8_rnu_sat (float c)
{
  __riscv_ztt_u8_rnu_sat_1x4_t b = __riscv_ztt_mzero_m_u8_rnu_sat_1x4 ();
  __riscv_ztt_u8_rnu_sat_1x4_t d = __riscv_ztt_mand_ew_x_u8_rnu_sat_1x4_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u8_rne_sat (_Float16 c)
{
  __riscv_ztt_u8_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rne_sat_1x1 ();
  __riscv_ztt_u8_rne_sat_1x1_t d = __riscv_ztt_mand_ew_x_u8_rne_sat_1x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u8_rdn_sat (__bf16 c)
{
  __riscv_ztt_u8_rdn_sat_1x2_t b = __riscv_ztt_mzero_m_u8_rdn_sat_1x2 ();
  __riscv_ztt_u8_rdn_sat_1x2_t d = __riscv_ztt_mand_ew_x_u8_rdn_sat_1x2_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u8_rod_sat (float c)
{
  __riscv_ztt_u8_rod_sat_4x1_t b = __riscv_ztt_mzero_m_u8_rod_sat_4x1 ();
  __riscv_ztt_u8_rod_sat_4x1_t d = __riscv_ztt_mand_ew_x_u8_rod_sat_4x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i16_rnu_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_sat_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t d = __riscv_ztt_mand_ew_x_i16_rnu_sat_1x1_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i16_rne_sat (_Float16 c)
{
  __riscv_ztt_i16_rne_sat_2x1_t b = __riscv_ztt_mzero_m_i16_rne_sat_2x1 ();
  __riscv_ztt_i16_rne_sat_2x1_t d = __riscv_ztt_mand_ew_x_i16_rne_sat_2x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i16_rdn_sat (__bf16 c)
{
  __riscv_ztt_i16_rdn_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rdn_sat_1x2 ();
  __riscv_ztt_i16_rdn_sat_1x2_t d = __riscv_ztt_mand_ew_x_i16_rdn_sat_1x2_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i16_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rod_sat_1x1 ();
  __riscv_ztt_i16_rod_sat_1x1_t d = __riscv_ztt_mand_ew_x_i16_rod_sat_1x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u16_rnu_sat (_Float16 c)
{
  __riscv_ztt_u16_rnu_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rnu_sat_1x2 ();
  __riscv_ztt_u16_rnu_sat_1x2_t d = __riscv_ztt_mand_ew_x_u16_rnu_sat_1x2_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u16_rne_sat (__bf16 c)
{
  __riscv_ztt_u16_rne_sat_2x1_t b = __riscv_ztt_mzero_m_u16_rne_sat_2x1 ();
  __riscv_ztt_u16_rne_sat_2x1_t d = __riscv_ztt_mand_ew_x_u16_rne_sat_2x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u16_rdn_sat (float c)
{
  __riscv_ztt_u16_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rdn_sat_1x1 ();
  __riscv_ztt_u16_rdn_sat_1x1_t d = __riscv_ztt_mand_ew_x_u16_rdn_sat_1x1_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u16_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rod_sat_2x1_t b = __riscv_ztt_mzero_m_u16_rod_sat_2x1 ();
  __riscv_ztt_u16_rod_sat_2x1_t d = __riscv_ztt_mand_ew_x_u16_rod_sat_2x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i32_rnu_sat (_Float16 c)
{
  __riscv_ztt_i32_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rnu_sat_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_mand_ew_x_i32_rnu_sat_1x1_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i32_rne_sat (float c)
{
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_mand_ew_x_i32_rne_sat_1x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i32_rdn_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_sat_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mand_ew_x_i32_rdn_sat_1x1_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_i32_rod_sat (_Float16 c)
{
  __riscv_ztt_i32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_mand_ew_x_i32_rod_sat_1x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u32_rnu_sat (__bf16 c)
{
  __riscv_ztt_u32_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rnu_sat_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_mand_ew_x_u32_rnu_sat_1x1_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u32_rne_sat (float c)
{
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mand_ew_x_u32_rne_sat_1x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u32_rdn_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rdn_sat_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_mand_ew_x_u32_rdn_sat_1x1_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mand_u32_rod_sat (__bf16 c)
{
  __riscv_ztt_u32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_mand_ew_x_u32_rod_sat_1x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i4_rnu (_Float16 c)
{
  __riscv_ztt_i4_rnu_4x1_t b = __riscv_ztt_mzero_m_i4_rnu_4x1 ();
  __riscv_ztt_i4_rnu_4x1_t d = __riscv_ztt_mandnot_ew_x_i4_rnu_4x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i4_rne (__bf16 c)
{
  __riscv_ztt_i4_rne_1x8_t b = __riscv_ztt_mzero_m_i4_rne_1x8 ();
  __riscv_ztt_i4_rne_1x8_t d = __riscv_ztt_mandnot_ew_x_i4_rne_1x8_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i4_rdn (float c)
{
  __riscv_ztt_i4_rdn_2x1_t b = __riscv_ztt_mzero_m_i4_rdn_2x1 ();
  __riscv_ztt_i4_rdn_2x1_t d = __riscv_ztt_mandnot_ew_x_i4_rdn_2x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i4_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rod_1x4_t b = __riscv_ztt_mzero_m_i4_rod_1x4 ();
  __riscv_ztt_i4_rod_1x4_t d = __riscv_ztt_mandnot_ew_x_i4_rod_1x4_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u4_rnu (__bf16 c)
{
  __riscv_ztt_u4_rnu_8x1_t b = __riscv_ztt_mzero_m_u4_rnu_8x1 ();
  __riscv_ztt_u4_rnu_8x1_t d = __riscv_ztt_mandnot_ew_x_u4_rnu_8x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u4_rne (float c)
{
  __riscv_ztt_u4_rne_1x2_t b = __riscv_ztt_mzero_m_u4_rne_1x2 ();
  __riscv_ztt_u4_rne_1x2_t d = __riscv_ztt_mandnot_ew_x_u4_rne_1x2_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u4_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rdn_4x1_t b = __riscv_ztt_mzero_m_u4_rdn_4x1 ();
  __riscv_ztt_u4_rdn_4x1_t d = __riscv_ztt_mandnot_ew_x_u4_rdn_4x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u4_rod (_Float16 c)
{
  __riscv_ztt_u4_rod_1x8_t b = __riscv_ztt_mzero_m_u4_rod_1x8 ();
  __riscv_ztt_u4_rod_1x8_t d = __riscv_ztt_mandnot_ew_x_u4_rod_1x8_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i8_rnu (__bf16 c)
{
  __riscv_ztt_i8_rnu_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t d = __riscv_ztt_mandnot_ew_x_i8_rnu_1x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i8_rne (float c)
{
  __riscv_ztt_i8_rne_1x2_t b = __riscv_ztt_mzero_m_i8_rne_1x2 ();
  __riscv_ztt_i8_rne_1x2_t d = __riscv_ztt_mandnot_ew_x_i8_rne_1x2_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i8_rdn (_Float16 c)
{
  __riscv_ztt_i8_rdn_4x1_t b = __riscv_ztt_mzero_m_i8_rdn_4x1 ();
  __riscv_ztt_i8_rdn_4x1_t d = __riscv_ztt_mandnot_ew_x_i8_rdn_4x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i8_rod (__bf16 c)
{
  __riscv_ztt_i8_rod_1x1_t b = __riscv_ztt_mzero_m_i8_rod_1x1 ();
  __riscv_ztt_i8_rod_1x1_t d = __riscv_ztt_mandnot_ew_x_i8_rod_1x1_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u8_rnu (float c)
{
  __riscv_ztt_u8_rnu_2x1_t b = __riscv_ztt_mzero_m_u8_rnu_2x1 ();
  __riscv_ztt_u8_rnu_2x1_t d = __riscv_ztt_mandnot_ew_x_u8_rnu_2x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u8_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rne_1x4_t b = __riscv_ztt_mzero_m_u8_rne_1x4 ();
  __riscv_ztt_u8_rne_1x4_t d = __riscv_ztt_mandnot_ew_x_u8_rne_1x4_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u8_rdn (_Float16 c)
{
  __riscv_ztt_u8_rdn_1x1_t b = __riscv_ztt_mzero_m_u8_rdn_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t d = __riscv_ztt_mandnot_ew_x_u8_rdn_1x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u8_rod (__bf16 c)
{
  __riscv_ztt_u8_rod_1x2_t b = __riscv_ztt_mzero_m_u8_rod_1x2 ();
  __riscv_ztt_u8_rod_1x2_t d = __riscv_ztt_mandnot_ew_x_u8_rod_1x2_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i16_rnu (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rnu_2x1_t b = __riscv_ztt_mzero_m_i16_rnu_2x1 ();
  __riscv_ztt_i16_rnu_2x1_t d = __riscv_ztt_mandnot_ew_x_i16_rnu_2x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i16_rne (_Float16 c)
{
  __riscv_ztt_i16_rne_1x1_t b = __riscv_ztt_mzero_m_i16_rne_1x1 ();
  __riscv_ztt_i16_rne_1x1_t d = __riscv_ztt_mandnot_ew_x_i16_rne_1x1_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i16_rdn (__bf16 c)
{
  __riscv_ztt_i16_rdn_2x1_t b = __riscv_ztt_mzero_m_i16_rdn_2x1 ();
  __riscv_ztt_i16_rdn_2x1_t d = __riscv_ztt_mandnot_ew_x_i16_rdn_2x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i16_rod (float c)
{
  __riscv_ztt_i16_rod_1x2_t b = __riscv_ztt_mzero_m_i16_rod_1x2 ();
  __riscv_ztt_i16_rod_1x2_t d = __riscv_ztt_mandnot_ew_x_i16_rod_1x2_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u16_rnu (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rnu_1x1_t b = __riscv_ztt_mzero_m_u16_rnu_1x1 ();
  __riscv_ztt_u16_rnu_1x1_t d = __riscv_ztt_mandnot_ew_x_u16_rnu_1x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u16_rne (_Float16 c)
{
  __riscv_ztt_u16_rne_1x2_t b = __riscv_ztt_mzero_m_u16_rne_1x2 ();
  __riscv_ztt_u16_rne_1x2_t d = __riscv_ztt_mandnot_ew_x_u16_rne_1x2_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u16_rdn (float c)
{
  __riscv_ztt_u16_rdn_2x1_t b = __riscv_ztt_mzero_m_u16_rdn_2x1 ();
  __riscv_ztt_u16_rdn_2x1_t d = __riscv_ztt_mandnot_ew_x_u16_rdn_2x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u16_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rod_1x1_t b = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_u16_rod_1x1_t d = __riscv_ztt_mandnot_ew_x_u16_rod_1x1_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i32_rnu (_Float16 c)
{
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mandnot_ew_x_i32_rnu_1x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i32_rne (__bf16 c)
{
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_mandnot_ew_x_i32_rne_1x1_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i32_rdn (float c)
{
  __riscv_ztt_i32_rdn_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_mandnot_ew_x_i32_rdn_1x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i32_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mandnot_ew_x_i32_rod_1x1_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u32_rnu (__bf16 c)
{
  __riscv_ztt_u32_rnu_1x1_t b = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mandnot_ew_x_u32_rnu_1x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u32_rne (float c)
{
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_mandnot_ew_x_u32_rne_1x1_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u32_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rdn_1x1_t b = __riscv_ztt_mzero_m_u32_rdn_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mandnot_ew_x_u32_rdn_1x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u32_rod (_Float16 c)
{
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_mandnot_ew_x_u32_rod_1x1_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i4_rnu_sat (__bf16 c)
{
  __riscv_ztt_i4_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_i4_rnu_sat_2x1 ();
  __riscv_ztt_i4_rnu_sat_2x1_t d = __riscv_ztt_mandnot_ew_x_i4_rnu_sat_2x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i4_rne_sat (float c)
{
  __riscv_ztt_i4_rne_sat_1x4_t b = __riscv_ztt_mzero_m_i4_rne_sat_1x4 ();
  __riscv_ztt_i4_rne_sat_1x4_t d = __riscv_ztt_mandnot_ew_x_i4_rne_sat_1x4_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i4_rdn_sat (_Float16 c)
{
  __riscv_ztt_i4_rdn_sat_8x1_t b = __riscv_ztt_mzero_m_i4_rdn_sat_8x1 ();
  __riscv_ztt_i4_rdn_sat_8x1_t d = __riscv_ztt_mandnot_ew_x_i4_rdn_sat_8x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i4_rod_sat (__bf16 c)
{
  __riscv_ztt_i4_rod_sat_1x2_t b = __riscv_ztt_mzero_m_i4_rod_sat_1x2 ();
  __riscv_ztt_i4_rod_sat_1x2_t d = __riscv_ztt_mandnot_ew_x_i4_rod_sat_1x2_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u4_rnu_sat (float c)
{
  __riscv_ztt_u4_rnu_sat_4x1_t b = __riscv_ztt_mzero_m_u4_rnu_sat_4x1 ();
  __riscv_ztt_u4_rnu_sat_4x1_t d = __riscv_ztt_mandnot_ew_x_u4_rnu_sat_4x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u4_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rne_sat_1x8_t b = __riscv_ztt_mzero_m_u4_rne_sat_1x8 ();
  __riscv_ztt_u4_rne_sat_1x8_t d = __riscv_ztt_mandnot_ew_x_u4_rne_sat_1x8_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u4_rdn_sat (_Float16 c)
{
  __riscv_ztt_u4_rdn_sat_2x1_t b = __riscv_ztt_mzero_m_u4_rdn_sat_2x1 ();
  __riscv_ztt_u4_rdn_sat_2x1_t d = __riscv_ztt_mandnot_ew_x_u4_rdn_sat_2x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u4_rod_sat (__bf16 c)
{
  __riscv_ztt_u4_rod_sat_1x4_t b = __riscv_ztt_mzero_m_u4_rod_sat_1x4 ();
  __riscv_ztt_u4_rod_sat_1x4_t d = __riscv_ztt_mandnot_ew_x_u4_rod_sat_1x4_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i8_rnu_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rnu_sat_4x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_4x1 ();
  __riscv_ztt_i8_rnu_sat_4x1_t d = __riscv_ztt_mandnot_ew_x_i8_rnu_sat_4x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i8_rne_sat (_Float16 c)
{
  __riscv_ztt_i8_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rne_sat_1x1 ();
  __riscv_ztt_i8_rne_sat_1x1_t d = __riscv_ztt_mandnot_ew_x_i8_rne_sat_1x1_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i8_rdn_sat (__bf16 c)
{
  __riscv_ztt_i8_rdn_sat_2x1_t b = __riscv_ztt_mzero_m_i8_rdn_sat_2x1 ();
  __riscv_ztt_i8_rdn_sat_2x1_t d = __riscv_ztt_mandnot_ew_x_i8_rdn_sat_2x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i8_rod_sat (float c)
{
  __riscv_ztt_i8_rod_sat_1x4_t b = __riscv_ztt_mzero_m_i8_rod_sat_1x4 ();
  __riscv_ztt_i8_rod_sat_1x4_t d = __riscv_ztt_mandnot_ew_x_i8_rod_sat_1x4_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u8_rnu_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rnu_sat_1x1 ();
  __riscv_ztt_u8_rnu_sat_1x1_t d = __riscv_ztt_mandnot_ew_x_u8_rnu_sat_1x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u8_rne_sat (_Float16 c)
{
  __riscv_ztt_u8_rne_sat_1x2_t b = __riscv_ztt_mzero_m_u8_rne_sat_1x2 ();
  __riscv_ztt_u8_rne_sat_1x2_t d = __riscv_ztt_mandnot_ew_x_u8_rne_sat_1x2_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u8_rdn_sat (float c)
{
  __riscv_ztt_u8_rdn_sat_4x1_t b = __riscv_ztt_mzero_m_u8_rdn_sat_4x1 ();
  __riscv_ztt_u8_rdn_sat_4x1_t d = __riscv_ztt_mandnot_ew_x_u8_rdn_sat_4x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u8_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rod_sat_1x1 ();
  __riscv_ztt_u8_rod_sat_1x1_t d = __riscv_ztt_mandnot_ew_x_u8_rod_sat_1x1_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i16_rnu_sat (_Float16 c)
{
  __riscv_ztt_i16_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_i16_rnu_sat_2x1 ();
  __riscv_ztt_i16_rnu_sat_2x1_t d = __riscv_ztt_mandnot_ew_x_i16_rnu_sat_2x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i16_rne_sat (__bf16 c)
{
  __riscv_ztt_i16_rne_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rne_sat_1x2 ();
  __riscv_ztt_i16_rne_sat_1x2_t d = __riscv_ztt_mandnot_ew_x_i16_rne_sat_1x2_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i16_rdn_sat (float c)
{
  __riscv_ztt_i16_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rdn_sat_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t d = __riscv_ztt_mandnot_ew_x_i16_rdn_sat_1x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i16_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rod_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rod_sat_1x2 ();
  __riscv_ztt_i16_rod_sat_1x2_t d = __riscv_ztt_mandnot_ew_x_i16_rod_sat_1x2_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u16_rnu_sat (__bf16 c)
{
  __riscv_ztt_u16_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_u16_rnu_sat_2x1 ();
  __riscv_ztt_u16_rnu_sat_2x1_t d = __riscv_ztt_mandnot_ew_x_u16_rnu_sat_2x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u16_rne_sat (float c)
{
  __riscv_ztt_u16_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rne_sat_1x1 ();
  __riscv_ztt_u16_rne_sat_1x1_t d = __riscv_ztt_mandnot_ew_x_u16_rne_sat_1x1_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u16_rdn_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rdn_sat_2x1_t b = __riscv_ztt_mzero_m_u16_rdn_sat_2x1 ();
  __riscv_ztt_u16_rdn_sat_2x1_t d = __riscv_ztt_mandnot_ew_x_u16_rdn_sat_2x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u16_rod_sat (_Float16 c)
{
  __riscv_ztt_u16_rod_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rod_sat_1x2 ();
  __riscv_ztt_u16_rod_sat_1x2_t d = __riscv_ztt_mandnot_ew_x_u16_rod_sat_1x2_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i32_rnu_sat (__bf16 c)
{
  __riscv_ztt_i32_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rnu_sat_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_mandnot_ew_x_i32_rnu_sat_1x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i32_rne_sat (float c)
{
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_mandnot_ew_x_i32_rne_sat_1x1_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i32_rdn_sat (_Float16 c)
{
  __riscv_ztt_i32_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_sat_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mandnot_ew_x_i32_rdn_sat_1x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_i32_rod_sat (__bf16 c)
{
  __riscv_ztt_i32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_mandnot_ew_x_i32_rod_sat_1x1_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u32_rnu_sat (float c)
{
  __riscv_ztt_u32_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rnu_sat_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_mandnot_ew_x_u32_rnu_sat_1x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u32_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mandnot_ew_x_u32_rne_sat_1x1_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u32_rdn_sat (_Float16 c)
{
  __riscv_ztt_u32_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rdn_sat_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_mandnot_ew_x_u32_rdn_sat_1x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mandnot_u32_rod_sat (__bf16 c)
{
  __riscv_ztt_u32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_mandnot_ew_x_u32_rod_sat_1x1_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i4_rnu (__bf16 c)
{
  __riscv_ztt_i4_rnu_1x8_t b = __riscv_ztt_mzero_m_i4_rnu_1x8 ();
  __riscv_ztt_i4_rnu_1x8_t d = __riscv_ztt_mor_ew_x_i4_rnu_1x8_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i4_rne (float c)
{
  __riscv_ztt_i4_rne_2x1_t b = __riscv_ztt_mzero_m_i4_rne_2x1 ();
  __riscv_ztt_i4_rne_2x1_t d = __riscv_ztt_mor_ew_x_i4_rne_2x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i4_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rdn_1x4_t b = __riscv_ztt_mzero_m_i4_rdn_1x4 ();
  __riscv_ztt_i4_rdn_1x4_t d = __riscv_ztt_mor_ew_x_i4_rdn_1x4_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i4_rod (_Float16 c)
{
  __riscv_ztt_i4_rod_8x1_t b = __riscv_ztt_mzero_m_i4_rod_8x1 ();
  __riscv_ztt_i4_rod_8x1_t d = __riscv_ztt_mor_ew_x_i4_rod_8x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u4_rnu (__bf16 c)
{
  __riscv_ztt_u4_rnu_1x2_t b = __riscv_ztt_mzero_m_u4_rnu_1x2 ();
  __riscv_ztt_u4_rnu_1x2_t d = __riscv_ztt_mor_ew_x_u4_rnu_1x2_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u4_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rne_4x1_t b = __riscv_ztt_mzero_m_u4_rne_4x1 ();
  __riscv_ztt_u4_rne_4x1_t d = __riscv_ztt_mor_ew_x_u4_rne_4x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u4_rdn (_Float16 c)
{
  __riscv_ztt_u4_rdn_1x8_t b = __riscv_ztt_mzero_m_u4_rdn_1x8 ();
  __riscv_ztt_u4_rdn_1x8_t d = __riscv_ztt_mor_ew_x_u4_rdn_1x8_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u4_rod (__bf16 c)
{
  __riscv_ztt_u4_rod_2x1_t b = __riscv_ztt_mzero_m_u4_rod_2x1 ();
  __riscv_ztt_u4_rod_2x1_t d = __riscv_ztt_mor_ew_x_u4_rod_2x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i8_rnu (float c)
{
  __riscv_ztt_i8_rnu_1x2_t b = __riscv_ztt_mzero_m_i8_rnu_1x2 ();
  __riscv_ztt_i8_rnu_1x2_t d = __riscv_ztt_mor_ew_x_i8_rnu_1x2_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i8_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rne_4x1_t b = __riscv_ztt_mzero_m_i8_rne_4x1 ();
  __riscv_ztt_i8_rne_4x1_t d = __riscv_ztt_mor_ew_x_i8_rne_4x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i8_rdn (_Float16 c)
{
  __riscv_ztt_i8_rdn_1x1_t b = __riscv_ztt_mzero_m_i8_rdn_1x1 ();
  __riscv_ztt_i8_rdn_1x1_t d = __riscv_ztt_mor_ew_x_i8_rdn_1x1_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i8_rod (float c)
{
  __riscv_ztt_i8_rod_2x1_t b = __riscv_ztt_mzero_m_i8_rod_2x1 ();
  __riscv_ztt_i8_rod_2x1_t d = __riscv_ztt_mor_ew_x_i8_rod_2x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u8_rnu (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rnu_1x4_t b = __riscv_ztt_mzero_m_u8_rnu_1x4 ();
  __riscv_ztt_u8_rnu_1x4_t d = __riscv_ztt_mor_ew_x_u8_rnu_1x4_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u8_rne (_Float16 c)
{
  __riscv_ztt_u8_rne_1x1_t b = __riscv_ztt_mzero_m_u8_rne_1x1 ();
  __riscv_ztt_u8_rne_1x1_t d = __riscv_ztt_mor_ew_x_u8_rne_1x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u8_rdn (__bf16 c)
{
  __riscv_ztt_u8_rdn_1x2_t b = __riscv_ztt_mzero_m_u8_rdn_1x2 ();
  __riscv_ztt_u8_rdn_1x2_t d = __riscv_ztt_mor_ew_x_u8_rdn_1x2_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u8_rod (float c)
{
  __riscv_ztt_u8_rod_4x1_t b = __riscv_ztt_mzero_m_u8_rod_4x1 ();
  __riscv_ztt_u8_rod_4x1_t d = __riscv_ztt_mor_ew_x_u8_rod_4x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i16_rnu (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t d = __riscv_ztt_mor_ew_x_i16_rnu_1x1_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i16_rne (__bf16 c)
{
  __riscv_ztt_i16_rne_2x1_t b = __riscv_ztt_mzero_m_i16_rne_2x1 ();
  __riscv_ztt_i16_rne_2x1_t d = __riscv_ztt_mor_ew_x_i16_rne_2x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i16_rdn (float c)
{
  __riscv_ztt_i16_rdn_1x2_t b = __riscv_ztt_mzero_m_i16_rdn_1x2 ();
  __riscv_ztt_i16_rdn_1x2_t d = __riscv_ztt_mor_ew_x_i16_rdn_1x2_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i16_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rod_1x1_t b = __riscv_ztt_mzero_m_i16_rod_1x1 ();
  __riscv_ztt_i16_rod_1x1_t d = __riscv_ztt_mor_ew_x_i16_rod_1x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u16_rnu (_Float16 c)
{
  __riscv_ztt_u16_rnu_1x2_t b = __riscv_ztt_mzero_m_u16_rnu_1x2 ();
  __riscv_ztt_u16_rnu_1x2_t d = __riscv_ztt_mor_ew_x_u16_rnu_1x2_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u16_rne (__bf16 c)
{
  __riscv_ztt_u16_rne_2x1_t b = __riscv_ztt_mzero_m_u16_rne_2x1 ();
  __riscv_ztt_u16_rne_2x1_t d = __riscv_ztt_mor_ew_x_u16_rne_2x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u16_rdn (float c)
{
  __riscv_ztt_u16_rdn_1x1_t b = __riscv_ztt_mzero_m_u16_rdn_1x1 ();
  __riscv_ztt_u16_rdn_1x1_t d = __riscv_ztt_mor_ew_x_u16_rdn_1x1_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u16_rod (_Float16 c)
{
  __riscv_ztt_u16_rod_2x1_t b = __riscv_ztt_mzero_m_u16_rod_2x1 ();
  __riscv_ztt_u16_rod_2x1_t d = __riscv_ztt_mor_ew_x_u16_rod_2x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i32_rnu (__bf16 c)
{
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mor_ew_x_i32_rnu_1x1_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i32_rne (float c)
{
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_mor_ew_x_i32_rne_1x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i32_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rdn_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_mor_ew_x_i32_rdn_1x1_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i32_rod (_Float16 c)
{
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mor_ew_x_i32_rod_1x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u32_rnu (__bf16 c)
{
  __riscv_ztt_u32_rnu_1x1_t b = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mor_ew_x_u32_rnu_1x1_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u32_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_mor_ew_x_u32_rne_1x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u32_rdn (_Float16 c)
{
  __riscv_ztt_u32_rdn_1x1_t b = __riscv_ztt_mzero_m_u32_rdn_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mor_ew_x_u32_rdn_1x1_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u32_rod (__bf16 c)
{
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_mor_ew_x_u32_rod_1x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i4_rnu_sat (float c)
{
  __riscv_ztt_i4_rnu_sat_1x4_t b = __riscv_ztt_mzero_m_i4_rnu_sat_1x4 ();
  __riscv_ztt_i4_rnu_sat_1x4_t d = __riscv_ztt_mor_ew_x_i4_rnu_sat_1x4_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i4_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rne_sat_8x1_t b = __riscv_ztt_mzero_m_i4_rne_sat_8x1 ();
  __riscv_ztt_i4_rne_sat_8x1_t d = __riscv_ztt_mor_ew_x_i4_rne_sat_8x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i4_rdn_sat (_Float16 c)
{
  __riscv_ztt_i4_rdn_sat_1x2_t b = __riscv_ztt_mzero_m_i4_rdn_sat_1x2 ();
  __riscv_ztt_i4_rdn_sat_1x2_t d = __riscv_ztt_mor_ew_x_i4_rdn_sat_1x2_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i4_rod_sat (float c)
{
  __riscv_ztt_i4_rod_sat_4x1_t b = __riscv_ztt_mzero_m_i4_rod_sat_4x1 ();
  __riscv_ztt_i4_rod_sat_4x1_t d = __riscv_ztt_mor_ew_x_i4_rod_sat_4x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u4_rnu_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rnu_sat_1x8_t b = __riscv_ztt_mzero_m_u4_rnu_sat_1x8 ();
  __riscv_ztt_u4_rnu_sat_1x8_t d = __riscv_ztt_mor_ew_x_u4_rnu_sat_1x8_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u4_rne_sat (_Float16 c)
{
  __riscv_ztt_u4_rne_sat_2x1_t b = __riscv_ztt_mzero_m_u4_rne_sat_2x1 ();
  __riscv_ztt_u4_rne_sat_2x1_t d = __riscv_ztt_mor_ew_x_u4_rne_sat_2x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u4_rdn_sat (__bf16 c)
{
  __riscv_ztt_u4_rdn_sat_1x4_t b = __riscv_ztt_mzero_m_u4_rdn_sat_1x4 ();
  __riscv_ztt_u4_rdn_sat_1x4_t d = __riscv_ztt_mor_ew_x_u4_rdn_sat_1x4_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u4_rod_sat (float c)
{
  __riscv_ztt_u4_rod_sat_8x1_t b = __riscv_ztt_mzero_m_u4_rod_sat_8x1 ();
  __riscv_ztt_u4_rod_sat_8x1_t d = __riscv_ztt_mor_ew_x_u4_rod_sat_8x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i8_rnu_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t d = __riscv_ztt_mor_ew_x_i8_rnu_sat_1x1_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i8_rne_sat (__bf16 c)
{
  __riscv_ztt_i8_rne_sat_2x1_t b = __riscv_ztt_mzero_m_i8_rne_sat_2x1 ();
  __riscv_ztt_i8_rne_sat_2x1_t d = __riscv_ztt_mor_ew_x_i8_rne_sat_2x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i8_rdn_sat (float c)
{
  __riscv_ztt_i8_rdn_sat_1x4_t b = __riscv_ztt_mzero_m_i8_rdn_sat_1x4 ();
  __riscv_ztt_i8_rdn_sat_1x4_t d = __riscv_ztt_mor_ew_x_i8_rdn_sat_1x4_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i8_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rod_sat_1x1 ();
  __riscv_ztt_i8_rod_sat_1x1_t d = __riscv_ztt_mor_ew_x_i8_rod_sat_1x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u8_rnu_sat (_Float16 c)
{
  __riscv_ztt_u8_rnu_sat_1x2_t b = __riscv_ztt_mzero_m_u8_rnu_sat_1x2 ();
  __riscv_ztt_u8_rnu_sat_1x2_t d = __riscv_ztt_mor_ew_x_u8_rnu_sat_1x2_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u8_rne_sat (__bf16 c)
{
  __riscv_ztt_u8_rne_sat_4x1_t b = __riscv_ztt_mzero_m_u8_rne_sat_4x1 ();
  __riscv_ztt_u8_rne_sat_4x1_t d = __riscv_ztt_mor_ew_x_u8_rne_sat_4x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u8_rdn_sat (float c)
{
  __riscv_ztt_u8_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rdn_sat_1x1 ();
  __riscv_ztt_u8_rdn_sat_1x1_t d = __riscv_ztt_mor_ew_x_u8_rdn_sat_1x1_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u8_rod_sat (_Float16 c)
{
  __riscv_ztt_u8_rod_sat_2x1_t b = __riscv_ztt_mzero_m_u8_rod_sat_2x1 ();
  __riscv_ztt_u8_rod_sat_2x1_t d = __riscv_ztt_mor_ew_x_u8_rod_sat_2x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i16_rnu_sat (__bf16 c)
{
  __riscv_ztt_i16_rnu_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rnu_sat_1x2 ();
  __riscv_ztt_i16_rnu_sat_1x2_t d = __riscv_ztt_mor_ew_x_i16_rnu_sat_1x2_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i16_rne_sat (float c)
{
  __riscv_ztt_i16_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rne_sat_1x1 ();
  __riscv_ztt_i16_rne_sat_1x1_t d = __riscv_ztt_mor_ew_x_i16_rne_sat_1x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i16_rdn_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rdn_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rdn_sat_1x2 ();
  __riscv_ztt_i16_rdn_sat_1x2_t d = __riscv_ztt_mor_ew_x_i16_rdn_sat_1x2_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i16_rod_sat (_Float16 c)
{
  __riscv_ztt_i16_rod_sat_2x1_t b = __riscv_ztt_mzero_m_i16_rod_sat_2x1 ();
  __riscv_ztt_i16_rod_sat_2x1_t d = __riscv_ztt_mor_ew_x_i16_rod_sat_2x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u16_rnu_sat (__bf16 c)
{
  __riscv_ztt_u16_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rnu_sat_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t d = __riscv_ztt_mor_ew_x_u16_rnu_sat_1x1_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u16_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rne_sat_2x1_t b = __riscv_ztt_mzero_m_u16_rne_sat_2x1 ();
  __riscv_ztt_u16_rne_sat_2x1_t d = __riscv_ztt_mor_ew_x_u16_rne_sat_2x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u16_rdn_sat (_Float16 c)
{
  __riscv_ztt_u16_rdn_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rdn_sat_1x2 ();
  __riscv_ztt_u16_rdn_sat_1x2_t d = __riscv_ztt_mor_ew_x_u16_rdn_sat_1x2_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u16_rod_sat (__bf16 c)
{
  __riscv_ztt_u16_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rod_sat_1x1 ();
  __riscv_ztt_u16_rod_sat_1x1_t d = __riscv_ztt_mor_ew_x_u16_rod_sat_1x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i32_rnu_sat (float c)
{
  __riscv_ztt_i32_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rnu_sat_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_mor_ew_x_i32_rnu_sat_1x1_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i32_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_mor_ew_x_i32_rne_sat_1x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i32_rdn_sat (_Float16 c)
{
  __riscv_ztt_i32_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_sat_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mor_ew_x_i32_rdn_sat_1x1_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_i32_rod_sat (float c)
{
  __riscv_ztt_i32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_mor_ew_x_i32_rod_sat_1x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u32_rnu_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rnu_sat_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_mor_ew_x_u32_rnu_sat_1x1_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u32_rne_sat (_Float16 c)
{
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mor_ew_x_u32_rne_sat_1x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u32_rdn_sat (__bf16 c)
{
  __riscv_ztt_u32_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rdn_sat_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_mor_ew_x_u32_rdn_sat_1x1_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mor_u32_rod_sat (float c)
{
  __riscv_ztt_u32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_mor_ew_x_u32_rod_sat_1x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i4_rnu (float c)
{
  __riscv_ztt_i4_rnu_2x1_t b = __riscv_ztt_mzero_m_i4_rnu_2x1 ();
  __riscv_ztt_i4_rnu_2x1_t d = __riscv_ztt_mornot_ew_x_i4_rnu_2x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i4_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rne_1x4_t b = __riscv_ztt_mzero_m_i4_rne_1x4 ();
  __riscv_ztt_i4_rne_1x4_t d = __riscv_ztt_mornot_ew_x_i4_rne_1x4_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i4_rdn (_Float16 c)
{
  __riscv_ztt_i4_rdn_8x1_t b = __riscv_ztt_mzero_m_i4_rdn_8x1 ();
  __riscv_ztt_i4_rdn_8x1_t d = __riscv_ztt_mornot_ew_x_i4_rdn_8x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i4_rod (__bf16 c)
{
  __riscv_ztt_i4_rod_1x2_t b = __riscv_ztt_mzero_m_i4_rod_1x2 ();
  __riscv_ztt_i4_rod_1x2_t d = __riscv_ztt_mornot_ew_x_i4_rod_1x2_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u4_rnu (float c)
{
  __riscv_ztt_u4_rnu_4x1_t b = __riscv_ztt_mzero_m_u4_rnu_4x1 ();
  __riscv_ztt_u4_rnu_4x1_t d = __riscv_ztt_mornot_ew_x_u4_rnu_4x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u4_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rne_1x8_t b = __riscv_ztt_mzero_m_u4_rne_1x8 ();
  __riscv_ztt_u4_rne_1x8_t d = __riscv_ztt_mornot_ew_x_u4_rne_1x8_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u4_rdn (__bf16 c)
{
  __riscv_ztt_u4_rdn_2x1_t b = __riscv_ztt_mzero_m_u4_rdn_2x1 ();
  __riscv_ztt_u4_rdn_2x1_t d = __riscv_ztt_mornot_ew_x_u4_rdn_2x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u4_rod (float c)
{
  __riscv_ztt_u4_rod_1x4_t b = __riscv_ztt_mzero_m_u4_rod_1x4 ();
  __riscv_ztt_u4_rod_1x4_t d = __riscv_ztt_mornot_ew_x_u4_rod_1x4_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i8_rnu (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rnu_4x1_t b = __riscv_ztt_mzero_m_i8_rnu_4x1 ();
  __riscv_ztt_i8_rnu_4x1_t d = __riscv_ztt_mornot_ew_x_i8_rnu_4x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i8_rne (_Float16 c)
{
  __riscv_ztt_i8_rne_1x1_t b = __riscv_ztt_mzero_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t d = __riscv_ztt_mornot_ew_x_i8_rne_1x1_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i8_rdn (__bf16 c)
{
  __riscv_ztt_i8_rdn_2x1_t b = __riscv_ztt_mzero_m_i8_rdn_2x1 ();
  __riscv_ztt_i8_rdn_2x1_t d = __riscv_ztt_mornot_ew_x_i8_rdn_2x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i8_rod (float c)
{
  __riscv_ztt_i8_rod_1x4_t b = __riscv_ztt_mzero_m_i8_rod_1x4 ();
  __riscv_ztt_i8_rod_1x4_t d = __riscv_ztt_mornot_ew_x_i8_rod_1x4_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u8_rnu (_Float16 c)
{
  __riscv_ztt_u8_rnu_1x1_t b = __riscv_ztt_mzero_m_u8_rnu_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t d = __riscv_ztt_mornot_ew_x_u8_rnu_1x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u8_rne (__bf16 c)
{
  __riscv_ztt_u8_rne_1x2_t b = __riscv_ztt_mzero_m_u8_rne_1x2 ();
  __riscv_ztt_u8_rne_1x2_t d = __riscv_ztt_mornot_ew_x_u8_rne_1x2_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u8_rdn (float c)
{
  __riscv_ztt_u8_rdn_4x1_t b = __riscv_ztt_mzero_m_u8_rdn_4x1 ();
  __riscv_ztt_u8_rdn_4x1_t d = __riscv_ztt_mornot_ew_x_u8_rdn_4x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u8_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rod_1x1_t b = __riscv_ztt_mzero_m_u8_rod_1x1 ();
  __riscv_ztt_u8_rod_1x1_t d = __riscv_ztt_mornot_ew_x_u8_rod_1x1_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i16_rnu (_Float16 c)
{
  __riscv_ztt_i16_rnu_2x1_t b = __riscv_ztt_mzero_m_i16_rnu_2x1 ();
  __riscv_ztt_i16_rnu_2x1_t d = __riscv_ztt_mornot_ew_x_i16_rnu_2x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i16_rne (__bf16 c)
{
  __riscv_ztt_i16_rne_1x2_t b = __riscv_ztt_mzero_m_i16_rne_1x2 ();
  __riscv_ztt_i16_rne_1x2_t d = __riscv_ztt_mornot_ew_x_i16_rne_1x2_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i16_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rdn_1x1_t b = __riscv_ztt_mzero_m_i16_rdn_1x1 ();
  __riscv_ztt_i16_rdn_1x1_t d = __riscv_ztt_mornot_ew_x_i16_rdn_1x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i16_rod (_Float16 c)
{
  __riscv_ztt_i16_rod_1x2_t b = __riscv_ztt_mzero_m_i16_rod_1x2 ();
  __riscv_ztt_i16_rod_1x2_t d = __riscv_ztt_mornot_ew_x_i16_rod_1x2_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u16_rnu (__bf16 c)
{
  __riscv_ztt_u16_rnu_2x1_t b = __riscv_ztt_mzero_m_u16_rnu_2x1 ();
  __riscv_ztt_u16_rnu_2x1_t d = __riscv_ztt_mornot_ew_x_u16_rnu_2x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u16_rne (float c)
{
  __riscv_ztt_u16_rne_1x1_t b = __riscv_ztt_mzero_m_u16_rne_1x1 ();
  __riscv_ztt_u16_rne_1x1_t d = __riscv_ztt_mornot_ew_x_u16_rne_1x1_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u16_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rdn_2x1_t b = __riscv_ztt_mzero_m_u16_rdn_2x1 ();
  __riscv_ztt_u16_rdn_2x1_t d = __riscv_ztt_mornot_ew_x_u16_rdn_2x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u16_rod (_Float16 c)
{
  __riscv_ztt_u16_rod_1x2_t b = __riscv_ztt_mzero_m_u16_rod_1x2 ();
  __riscv_ztt_u16_rod_1x2_t d = __riscv_ztt_mornot_ew_x_u16_rod_1x2_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i32_rnu (float c)
{
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mornot_ew_x_i32_rnu_1x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i32_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_mornot_ew_x_i32_rne_1x1_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i32_rdn (_Float16 c)
{
  __riscv_ztt_i32_rdn_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_mornot_ew_x_i32_rdn_1x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i32_rod (__bf16 c)
{
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mornot_ew_x_i32_rod_1x1_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u32_rnu (float c)
{
  __riscv_ztt_u32_rnu_1x1_t b = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mornot_ew_x_u32_rnu_1x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u32_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_mornot_ew_x_u32_rne_1x1_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u32_rdn (__bf16 c)
{
  __riscv_ztt_u32_rdn_1x1_t b = __riscv_ztt_mzero_m_u32_rdn_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mornot_ew_x_u32_rdn_1x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u32_rod (float c)
{
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_mornot_ew_x_u32_rod_1x1_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i4_rnu_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rnu_sat_8x1_t b = __riscv_ztt_mzero_m_i4_rnu_sat_8x1 ();
  __riscv_ztt_i4_rnu_sat_8x1_t d = __riscv_ztt_mornot_ew_x_i4_rnu_sat_8x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i4_rne_sat (_Float16 c)
{
  __riscv_ztt_i4_rne_sat_1x2_t b = __riscv_ztt_mzero_m_i4_rne_sat_1x2 ();
  __riscv_ztt_i4_rne_sat_1x2_t d = __riscv_ztt_mornot_ew_x_i4_rne_sat_1x2_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i4_rdn_sat (__bf16 c)
{
  __riscv_ztt_i4_rdn_sat_4x1_t b = __riscv_ztt_mzero_m_i4_rdn_sat_4x1 ();
  __riscv_ztt_i4_rdn_sat_4x1_t d = __riscv_ztt_mornot_ew_x_i4_rdn_sat_4x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i4_rod_sat (float c)
{
  __riscv_ztt_i4_rod_sat_1x8_t b = __riscv_ztt_mzero_m_i4_rod_sat_1x8 ();
  __riscv_ztt_i4_rod_sat_1x8_t d = __riscv_ztt_mornot_ew_x_i4_rod_sat_1x8_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u4_rnu_sat (_Float16 c)
{
  __riscv_ztt_u4_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_u4_rnu_sat_2x1 ();
  __riscv_ztt_u4_rnu_sat_2x1_t d = __riscv_ztt_mornot_ew_x_u4_rnu_sat_2x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u4_rne_sat (__bf16 c)
{
  __riscv_ztt_u4_rne_sat_1x4_t b = __riscv_ztt_mzero_m_u4_rne_sat_1x4 ();
  __riscv_ztt_u4_rne_sat_1x4_t d = __riscv_ztt_mornot_ew_x_u4_rne_sat_1x4_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u4_rdn_sat (float c)
{
  __riscv_ztt_u4_rdn_sat_8x1_t b = __riscv_ztt_mzero_m_u4_rdn_sat_8x1 ();
  __riscv_ztt_u4_rdn_sat_8x1_t d = __riscv_ztt_mornot_ew_x_u4_rdn_sat_8x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u4_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rod_sat_1x2_t b = __riscv_ztt_mzero_m_u4_rod_sat_1x2 ();
  __riscv_ztt_u4_rod_sat_1x2_t d = __riscv_ztt_mornot_ew_x_u4_rod_sat_1x2_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i8_rnu_sat (_Float16 c)
{
  __riscv_ztt_i8_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_2x1 ();
  __riscv_ztt_i8_rnu_sat_2x1_t d = __riscv_ztt_mornot_ew_x_i8_rnu_sat_2x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i8_rne_sat (__bf16 c)
{
  __riscv_ztt_i8_rne_sat_1x4_t b = __riscv_ztt_mzero_m_i8_rne_sat_1x4 ();
  __riscv_ztt_i8_rne_sat_1x4_t d = __riscv_ztt_mornot_ew_x_i8_rne_sat_1x4_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i8_rdn_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rdn_sat_1x1 ();
  __riscv_ztt_i8_rdn_sat_1x1_t d = __riscv_ztt_mornot_ew_x_i8_rdn_sat_1x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i8_rod_sat (_Float16 c)
{
  __riscv_ztt_i8_rod_sat_1x2_t b = __riscv_ztt_mzero_m_i8_rod_sat_1x2 ();
  __riscv_ztt_i8_rod_sat_1x2_t d = __riscv_ztt_mornot_ew_x_i8_rod_sat_1x2_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u8_rnu_sat (__bf16 c)
{
  __riscv_ztt_u8_rnu_sat_4x1_t b = __riscv_ztt_mzero_m_u8_rnu_sat_4x1 ();
  __riscv_ztt_u8_rnu_sat_4x1_t d = __riscv_ztt_mornot_ew_x_u8_rnu_sat_4x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u8_rne_sat (float c)
{
  __riscv_ztt_u8_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rne_sat_1x1 ();
  __riscv_ztt_u8_rne_sat_1x1_t d = __riscv_ztt_mornot_ew_x_u8_rne_sat_1x1_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u8_rdn_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rdn_sat_2x1_t b = __riscv_ztt_mzero_m_u8_rdn_sat_2x1 ();
  __riscv_ztt_u8_rdn_sat_2x1_t d = __riscv_ztt_mornot_ew_x_u8_rdn_sat_2x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u8_rod_sat (_Float16 c)
{
  __riscv_ztt_u8_rod_sat_1x4_t b = __riscv_ztt_mzero_m_u8_rod_sat_1x4 ();
  __riscv_ztt_u8_rod_sat_1x4_t d = __riscv_ztt_mornot_ew_x_u8_rod_sat_1x4_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i16_rnu_sat (float c)
{
  __riscv_ztt_i16_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_sat_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t d = __riscv_ztt_mornot_ew_x_i16_rnu_sat_1x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i16_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rne_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rne_sat_1x2 ();
  __riscv_ztt_i16_rne_sat_1x2_t d = __riscv_ztt_mornot_ew_x_i16_rne_sat_1x2_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i16_rdn_sat (_Float16 c)
{
  __riscv_ztt_i16_rdn_sat_2x1_t b = __riscv_ztt_mzero_m_i16_rdn_sat_2x1 ();
  __riscv_ztt_i16_rdn_sat_2x1_t d = __riscv_ztt_mornot_ew_x_i16_rdn_sat_2x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i16_rod_sat (__bf16 c)
{
  __riscv_ztt_i16_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rod_sat_1x1 ();
  __riscv_ztt_i16_rod_sat_1x1_t d = __riscv_ztt_mornot_ew_x_i16_rod_sat_1x1_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u16_rnu_sat (float c)
{
  __riscv_ztt_u16_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_u16_rnu_sat_2x1 ();
  __riscv_ztt_u16_rnu_sat_2x1_t d = __riscv_ztt_mornot_ew_x_u16_rnu_sat_2x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u16_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rne_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rne_sat_1x2 ();
  __riscv_ztt_u16_rne_sat_1x2_t d = __riscv_ztt_mornot_ew_x_u16_rne_sat_1x2_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u16_rdn_sat (__bf16 c)
{
  __riscv_ztt_u16_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rdn_sat_1x1 ();
  __riscv_ztt_u16_rdn_sat_1x1_t d = __riscv_ztt_mornot_ew_x_u16_rdn_sat_1x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u16_rod_sat (float c)
{
  __riscv_ztt_u16_rod_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rod_sat_1x2 ();
  __riscv_ztt_u16_rod_sat_1x2_t d = __riscv_ztt_mornot_ew_x_u16_rod_sat_1x2_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i32_rnu_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rnu_sat_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_mornot_ew_x_i32_rnu_sat_1x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i32_rne_sat (_Float16 c)
{
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_mornot_ew_x_i32_rne_sat_1x1_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i32_rdn_sat (__bf16 c)
{
  __riscv_ztt_i32_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_sat_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mornot_ew_x_i32_rdn_sat_1x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_i32_rod_sat (float c)
{
  __riscv_ztt_i32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_mornot_ew_x_i32_rod_sat_1x1_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u32_rnu_sat (_Float16 c)
{
  __riscv_ztt_u32_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rnu_sat_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_mornot_ew_x_u32_rnu_sat_1x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u32_rne_sat (__bf16 c)
{
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mornot_ew_x_u32_rne_sat_1x1_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u32_rdn_sat (float c)
{
  __riscv_ztt_u32_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rdn_sat_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_mornot_ew_x_u32_rdn_sat_1x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mornot_u32_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_mornot_ew_x_u32_rod_sat_1x1_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i4_rnu (float c)
{
  __riscv_ztt_i4_rnu_1x4_t b = __riscv_ztt_mzero_m_i4_rnu_1x4 ();
  __riscv_ztt_i4_rnu_1x4_t d = __riscv_ztt_mxor_ew_x_i4_rnu_1x4_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i4_rne (_Float16 c)
{
  __riscv_ztt_i4_rne_8x1_t b = __riscv_ztt_mzero_m_i4_rne_8x1 ();
  __riscv_ztt_i4_rne_8x1_t d = __riscv_ztt_mxor_ew_x_i4_rne_8x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i4_rdn (__bf16 c)
{
  __riscv_ztt_i4_rdn_1x2_t b = __riscv_ztt_mzero_m_i4_rdn_1x2 ();
  __riscv_ztt_i4_rdn_1x2_t d = __riscv_ztt_mxor_ew_x_i4_rdn_1x2_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i4_rod (float c)
{
  __riscv_ztt_i4_rod_4x1_t b = __riscv_ztt_mzero_m_i4_rod_4x1 ();
  __riscv_ztt_i4_rod_4x1_t d = __riscv_ztt_mxor_ew_x_i4_rod_4x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u4_rnu (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rnu_1x8_t b = __riscv_ztt_mzero_m_u4_rnu_1x8 ();
  __riscv_ztt_u4_rnu_1x8_t d = __riscv_ztt_mxor_ew_x_u4_rnu_1x8_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u4_rne (_Float16 c)
{
  __riscv_ztt_u4_rne_2x1_t b = __riscv_ztt_mzero_m_u4_rne_2x1 ();
  __riscv_ztt_u4_rne_2x1_t d = __riscv_ztt_mxor_ew_x_u4_rne_2x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u4_rdn (__bf16 c)
{
  __riscv_ztt_u4_rdn_1x4_t b = __riscv_ztt_mzero_m_u4_rdn_1x4 ();
  __riscv_ztt_u4_rdn_1x4_t d = __riscv_ztt_mxor_ew_x_u4_rdn_1x4_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u4_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rod_8x1_t b = __riscv_ztt_mzero_m_u4_rod_8x1 ();
  __riscv_ztt_u4_rod_8x1_t d = __riscv_ztt_mxor_ew_x_u4_rod_8x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i8_rnu (_Float16 c)
{
  __riscv_ztt_i8_rnu_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t d = __riscv_ztt_mxor_ew_x_i8_rnu_1x1_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i8_rne (__bf16 c)
{
  __riscv_ztt_i8_rne_2x1_t b = __riscv_ztt_mzero_m_i8_rne_2x1 ();
  __riscv_ztt_i8_rne_2x1_t d = __riscv_ztt_mxor_ew_x_i8_rne_2x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i8_rdn (float c)
{
  __riscv_ztt_i8_rdn_1x4_t b = __riscv_ztt_mzero_m_i8_rdn_1x4 ();
  __riscv_ztt_i8_rdn_1x4_t d = __riscv_ztt_mxor_ew_x_i8_rdn_1x4_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i8_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rod_1x1_t b = __riscv_ztt_mzero_m_i8_rod_1x1 ();
  __riscv_ztt_i8_rod_1x1_t d = __riscv_ztt_mxor_ew_x_i8_rod_1x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u8_rnu (_Float16 c)
{
  __riscv_ztt_u8_rnu_1x2_t b = __riscv_ztt_mzero_m_u8_rnu_1x2 ();
  __riscv_ztt_u8_rnu_1x2_t d = __riscv_ztt_mxor_ew_x_u8_rnu_1x2_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u8_rne (float c)
{
  __riscv_ztt_u8_rne_4x1_t b = __riscv_ztt_mzero_m_u8_rne_4x1 ();
  __riscv_ztt_u8_rne_4x1_t d = __riscv_ztt_mxor_ew_x_u8_rne_4x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u8_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rdn_1x1_t b = __riscv_ztt_mzero_m_u8_rdn_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t d = __riscv_ztt_mxor_ew_x_u8_rdn_1x1_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u8_rod (_Float16 c)
{
  __riscv_ztt_u8_rod_2x1_t b = __riscv_ztt_mzero_m_u8_rod_2x1 ();
  __riscv_ztt_u8_rod_2x1_t d = __riscv_ztt_mxor_ew_x_u8_rod_2x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i16_rnu (__bf16 c)
{
  __riscv_ztt_i16_rnu_1x2_t b = __riscv_ztt_mzero_m_i16_rnu_1x2 ();
  __riscv_ztt_i16_rnu_1x2_t d = __riscv_ztt_mxor_ew_x_i16_rnu_1x2_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i16_rne (float c)
{
  __riscv_ztt_i16_rne_1x1_t b = __riscv_ztt_mzero_m_i16_rne_1x1 ();
  __riscv_ztt_i16_rne_1x1_t d = __riscv_ztt_mxor_ew_x_i16_rne_1x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i16_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rdn_1x2_t b = __riscv_ztt_mzero_m_i16_rdn_1x2 ();
  __riscv_ztt_i16_rdn_1x2_t d = __riscv_ztt_mxor_ew_x_i16_rdn_1x2_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i16_rod (__bf16 c)
{
  __riscv_ztt_i16_rod_2x1_t b = __riscv_ztt_mzero_m_i16_rod_2x1 ();
  __riscv_ztt_i16_rod_2x1_t d = __riscv_ztt_mxor_ew_x_i16_rod_2x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u16_rnu (float c)
{
  __riscv_ztt_u16_rnu_1x1_t b = __riscv_ztt_mzero_m_u16_rnu_1x1 ();
  __riscv_ztt_u16_rnu_1x1_t d = __riscv_ztt_mxor_ew_x_u16_rnu_1x1_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u16_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rne_2x1_t b = __riscv_ztt_mzero_m_u16_rne_2x1 ();
  __riscv_ztt_u16_rne_2x1_t d = __riscv_ztt_mxor_ew_x_u16_rne_2x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u16_rdn (_Float16 c)
{
  __riscv_ztt_u16_rdn_1x2_t b = __riscv_ztt_mzero_m_u16_rdn_1x2 ();
  __riscv_ztt_u16_rdn_1x2_t d = __riscv_ztt_mxor_ew_x_u16_rdn_1x2_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u16_rod (__bf16 c)
{
  __riscv_ztt_u16_rod_1x1_t b = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_u16_rod_1x1_t d = __riscv_ztt_mxor_ew_x_u16_rod_1x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i32_rnu (float c)
{
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mxor_ew_x_i32_rnu_1x1_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i32_rne (_Float16 c)
{
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_mxor_ew_x_i32_rne_1x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i32_rdn (__bf16 c)
{
  __riscv_ztt_i32_rdn_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_mxor_ew_x_i32_rdn_1x1_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i32_rod (float c)
{
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mxor_ew_x_i32_rod_1x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u32_rnu (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rnu_1x1_t b = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mxor_ew_x_u32_rnu_1x1_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u32_rne (_Float16 c)
{
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_mxor_ew_x_u32_rne_1x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u32_rdn (__bf16 c)
{
  __riscv_ztt_u32_rdn_1x1_t b = __riscv_ztt_mzero_m_u32_rdn_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mxor_ew_x_u32_rdn_1x1_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u32_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_mxor_ew_x_u32_rod_1x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i4_rnu_sat (_Float16 c)
{
  __riscv_ztt_i4_rnu_sat_1x2_t b = __riscv_ztt_mzero_m_i4_rnu_sat_1x2 ();
  __riscv_ztt_i4_rnu_sat_1x2_t d = __riscv_ztt_mxor_ew_x_i4_rnu_sat_1x2_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i4_rne_sat (__bf16 c)
{
  __riscv_ztt_i4_rne_sat_4x1_t b = __riscv_ztt_mzero_m_i4_rne_sat_4x1 ();
  __riscv_ztt_i4_rne_sat_4x1_t d = __riscv_ztt_mxor_ew_x_i4_rne_sat_4x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i4_rdn_sat (float c)
{
  __riscv_ztt_i4_rdn_sat_1x8_t b = __riscv_ztt_mzero_m_i4_rdn_sat_1x8 ();
  __riscv_ztt_i4_rdn_sat_1x8_t d = __riscv_ztt_mxor_ew_x_i4_rdn_sat_1x8_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i4_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rod_sat_2x1_t b = __riscv_ztt_mzero_m_i4_rod_sat_2x1 ();
  __riscv_ztt_i4_rod_sat_2x1_t d = __riscv_ztt_mxor_ew_x_i4_rod_sat_2x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u4_rnu_sat (_Float16 c)
{
  __riscv_ztt_u4_rnu_sat_1x4_t b = __riscv_ztt_mzero_m_u4_rnu_sat_1x4 ();
  __riscv_ztt_u4_rnu_sat_1x4_t d = __riscv_ztt_mxor_ew_x_u4_rnu_sat_1x4_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u4_rne_sat (float c)
{
  __riscv_ztt_u4_rne_sat_8x1_t b = __riscv_ztt_mzero_m_u4_rne_sat_8x1 ();
  __riscv_ztt_u4_rne_sat_8x1_t d = __riscv_ztt_mxor_ew_x_u4_rne_sat_8x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u4_rdn_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rdn_sat_1x2_t b = __riscv_ztt_mzero_m_u4_rdn_sat_1x2 ();
  __riscv_ztt_u4_rdn_sat_1x2_t d = __riscv_ztt_mxor_ew_x_u4_rdn_sat_1x2_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u4_rod_sat (_Float16 c)
{
  __riscv_ztt_u4_rod_sat_4x1_t b = __riscv_ztt_mzero_m_u4_rod_sat_4x1 ();
  __riscv_ztt_u4_rod_sat_4x1_t d = __riscv_ztt_mxor_ew_x_u4_rod_sat_4x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i8_rnu_sat (__bf16 c)
{
  __riscv_ztt_i8_rnu_sat_1x4_t b = __riscv_ztt_mzero_m_i8_rnu_sat_1x4 ();
  __riscv_ztt_i8_rnu_sat_1x4_t d = __riscv_ztt_mxor_ew_x_i8_rnu_sat_1x4_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i8_rne_sat (float c)
{
  __riscv_ztt_i8_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rne_sat_1x1 ();
  __riscv_ztt_i8_rne_sat_1x1_t d = __riscv_ztt_mxor_ew_x_i8_rne_sat_1x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i8_rdn_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rdn_sat_1x2_t b = __riscv_ztt_mzero_m_i8_rdn_sat_1x2 ();
  __riscv_ztt_i8_rdn_sat_1x2_t d = __riscv_ztt_mxor_ew_x_i8_rdn_sat_1x2_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i8_rod_sat (__bf16 c)
{
  __riscv_ztt_i8_rod_sat_4x1_t b = __riscv_ztt_mzero_m_i8_rod_sat_4x1 ();
  __riscv_ztt_i8_rod_sat_4x1_t d = __riscv_ztt_mxor_ew_x_i8_rod_sat_4x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u8_rnu_sat (float c)
{
  __riscv_ztt_u8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rnu_sat_1x1 ();
  __riscv_ztt_u8_rnu_sat_1x1_t d = __riscv_ztt_mxor_ew_x_u8_rnu_sat_1x1_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u8_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rne_sat_2x1_t b = __riscv_ztt_mzero_m_u8_rne_sat_2x1 ();
  __riscv_ztt_u8_rne_sat_2x1_t d = __riscv_ztt_mxor_ew_x_u8_rne_sat_2x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u8_rdn_sat (_Float16 c)
{
  __riscv_ztt_u8_rdn_sat_1x4_t b = __riscv_ztt_mzero_m_u8_rdn_sat_1x4 ();
  __riscv_ztt_u8_rdn_sat_1x4_t d = __riscv_ztt_mxor_ew_x_u8_rdn_sat_1x4_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u8_rod_sat (__bf16 c)
{
  __riscv_ztt_u8_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rod_sat_1x1 ();
  __riscv_ztt_u8_rod_sat_1x1_t d = __riscv_ztt_mxor_ew_x_u8_rod_sat_1x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i16_rnu_sat (float c)
{
  __riscv_ztt_i16_rnu_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rnu_sat_1x2 ();
  __riscv_ztt_i16_rnu_sat_1x2_t d = __riscv_ztt_mxor_ew_x_i16_rnu_sat_1x2_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i16_rne_sat (_Float16 c)
{
  __riscv_ztt_i16_rne_sat_2x1_t b = __riscv_ztt_mzero_m_i16_rne_sat_2x1 ();
  __riscv_ztt_i16_rne_sat_2x1_t d = __riscv_ztt_mxor_ew_x_i16_rne_sat_2x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i16_rdn_sat (__bf16 c)
{
  __riscv_ztt_i16_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rdn_sat_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t d = __riscv_ztt_mxor_ew_x_i16_rdn_sat_1x1_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i16_rod_sat (float c)
{
  __riscv_ztt_i16_rod_sat_2x1_t b = __riscv_ztt_mzero_m_i16_rod_sat_2x1 ();
  __riscv_ztt_i16_rod_sat_2x1_t d = __riscv_ztt_mxor_ew_x_i16_rod_sat_2x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u16_rnu_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rnu_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rnu_sat_1x2 ();
  __riscv_ztt_u16_rnu_sat_1x2_t d = __riscv_ztt_mxor_ew_x_u16_rnu_sat_1x2_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u16_rne_sat (_Float16 c)
{
  __riscv_ztt_u16_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rne_sat_1x1 ();
  __riscv_ztt_u16_rne_sat_1x1_t d = __riscv_ztt_mxor_ew_x_u16_rne_sat_1x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u16_rdn_sat (__bf16 c)
{
  __riscv_ztt_u16_rdn_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rdn_sat_1x2 ();
  __riscv_ztt_u16_rdn_sat_1x2_t d = __riscv_ztt_mxor_ew_x_u16_rdn_sat_1x2_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u16_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rod_sat_2x1_t b = __riscv_ztt_mzero_m_u16_rod_sat_2x1 ();
  __riscv_ztt_u16_rod_sat_2x1_t d = __riscv_ztt_mxor_ew_x_u16_rod_sat_2x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i32_rnu_sat (_Float16 c)
{
  __riscv_ztt_i32_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rnu_sat_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_mxor_ew_x_i32_rnu_sat_1x1_f16_rtz (b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i32_rne_sat (__bf16 c)
{
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_mxor_ew_x_i32_rne_sat_1x1_bf16_rdn (b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i32_rdn_sat (float c)
{
  __riscv_ztt_i32_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_sat_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mxor_ew_x_i32_rdn_sat_1x1_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_i32_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_mxor_ew_x_i32_rod_sat_1x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u32_rnu_sat (_Float16 c)
{
  __riscv_ztt_u32_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rnu_sat_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_mxor_ew_x_u32_rnu_sat_1x1_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u32_rne_sat (float c)
{
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mxor_ew_x_u32_rne_sat_1x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u32_rdn_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rdn_sat_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_mxor_ew_x_u32_rdn_sat_1x1_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mxor_u32_rod_sat (_Float16 c)
{
  __riscv_ztt_u32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_mxor_ew_x_u32_rod_sat_1x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mmulacc_i4_rnu (carrier_u64 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i4_rnu_2x1_t old = __riscv_ztt_mzero_m_i4_rnu_2x1 ();
  __riscv_ztt_i4_rnu_2x1_t d = __riscv_ztt_mmulacc_ew_x_i4_rnu_2x1_u64_rdn_sat (old, b, __riscv_ztt_scalar_from_bits_u64_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i4_rne (_Float16 c)
{
  __riscv_ztt_i4_rne_1x2_t b = __riscv_ztt_mzero_m_i4_rne_1x2 ();
  __riscv_ztt_i4_rne_1x2_t old = __riscv_ztt_mzero_m_i4_rne_1x2 ();
  __riscv_ztt_i4_rne_1x2_t d = __riscv_ztt_mmulacc_ew_x_i4_rne_1x2_f16_rno (old, b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i4_rdn (_Float16 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_i4_rdn_2x1_t old = __riscv_ztt_mzero_m_i4_rdn_2x1 ();
  __riscv_ztt_i4_rdn_2x1_t d = __riscv_ztt_mmulacc_ew_x_i4_rdn_2x1_f16_rmm (old, b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i4_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rod_1x8_t b = __riscv_ztt_mzero_m_i4_rod_1x8 ();
  __riscv_ztt_i4_rod_1x8_t old = __riscv_ztt_mzero_m_i4_rod_1x8 ();
  __riscv_ztt_i4_rod_1x8_t d = __riscv_ztt_mmulacc_ew_x_i4_rod_1x8_f64_rtz (old, b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u4_rnu (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f16_rmm_2x1_t b = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_u4_rnu_2x1_t old = __riscv_ztt_mzero_m_u4_rnu_2x1 ();
  __riscv_ztt_u4_rnu_2x1_t d = __riscv_ztt_mmulacc_ew_x_u4_rnu_2x1_f64_rne (old, b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u4_rne (__bf16 c)
{
  __riscv_ztt_u4_rne_1x4_t b = __riscv_ztt_mzero_m_u4_rne_1x4 ();
  __riscv_ztt_u4_rne_1x4_t old = __riscv_ztt_mzero_m_u4_rne_1x4 ();
  __riscv_ztt_u4_rne_1x4_t d = __riscv_ztt_mmulacc_ew_x_u4_rne_1x4_bf16_rup (old, b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u4_rdn (carrier_i16 c)
{
  __riscv_ztt_bf16_rne_2x1_t b = __riscv_ztt_mzero_m_bf16_rne_2x1 ();
  __riscv_ztt_u4_rdn_2x1_t old = __riscv_ztt_mzero_m_u4_rdn_2x1 ();
  __riscv_ztt_u4_rdn_2x1_t d = __riscv_ztt_mmulacc_ew_x_u4_rdn_2x1_i16_rnu (old, b, __riscv_ztt_scalar_make_i16_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u4_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rod_1x2_t b = __riscv_ztt_mzero_m_u4_rod_1x2 ();
  __riscv_ztt_u4_rod_1x2_t old = __riscv_ztt_mzero_m_u4_rod_1x2 ();
  __riscv_ztt_u4_rod_1x2_t d = __riscv_ztt_mmulacc_ew_x_u4_rod_1x2_f64_rno (old, b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i8_rnu (carrier_u32 c)
{
  __riscv_ztt_bf16_rdn_2x1_t b = __riscv_ztt_mzero_m_bf16_rdn_2x1 ();
  __riscv_ztt_i8_rnu_2x1_t old = __riscv_ztt_mzero_m_i8_rnu_2x1 ();
  __riscv_ztt_i8_rnu_2x1_t d = __riscv_ztt_mmulacc_ew_x_i8_rnu_2x1_u32_rdn (old, b, __riscv_ztt_scalar_make_u32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i8_rne (float c)
{
  __riscv_ztt_i8_rne_1x4_t b = __riscv_ztt_mzero_m_i8_rne_1x4 ();
  __riscv_ztt_i8_rne_1x4_t old = __riscv_ztt_mzero_m_i8_rne_1x4 ();
  __riscv_ztt_i8_rne_1x4_t d = __riscv_ztt_mmulacc_ew_x_i8_rne_1x4_f32_rtz (old, b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i8_rdn (carrier_u128 c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_i8_rdn_1x1_t old = __riscv_ztt_mzero_m_i8_rdn_1x1 ();
  __riscv_ztt_i8_rdn_1x1_t d = __riscv_ztt_mmulacc_ew_x_i8_rdn_1x1_u128_rnu (old, b, __riscv_ztt_scalar_from_bits_u128_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i8_rod (_Float16 c)
{
  __riscv_ztt_i8_rod_1x2_t b = __riscv_ztt_mzero_m_i8_rod_1x2 ();
  __riscv_ztt_i8_rod_1x2_t old = __riscv_ztt_mzero_m_i8_rod_1x2 ();
  __riscv_ztt_i8_rod_1x2_t d = __riscv_ztt_mmulacc_ew_x_i8_rod_1x2_f16_rup (old, b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u8_rnu (carrier_i16 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t old = __riscv_ztt_mzero_m_u8_rnu_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t d = __riscv_ztt_mmulacc_ew_x_u8_rnu_1x1_i16_rdn_sat (old, b, __riscv_ztt_scalar_make_i16_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u8_rne (float c)
{
  __riscv_ztt_u8_rne_1x1_t b = __riscv_ztt_mzero_m_u8_rne_1x1 ();
  __riscv_ztt_u8_rne_1x1_t old = __riscv_ztt_mzero_m_u8_rne_1x1 ();
  __riscv_ztt_u8_rne_1x1_t d = __riscv_ztt_mmulacc_ew_x_u8_rne_1x1_f32_rno (old, b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u8_rdn (carrier_i64 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t old = __riscv_ztt_mzero_m_u8_rdn_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t d = __riscv_ztt_mmulacc_ew_x_u8_rdn_1x1_i64_rnu_sat (old, b, __riscv_ztt_scalar_from_bits_i64_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u8_rod (__bf16 c)
{
  __riscv_ztt_u8_rod_1x4_t b = __riscv_ztt_mzero_m_u8_rod_1x4 ();
  __riscv_ztt_u8_rod_1x4_t old = __riscv_ztt_mzero_m_u8_rod_1x4 ();
  __riscv_ztt_u8_rod_1x4_t d = __riscv_ztt_mmulacc_ew_x_u8_rod_1x4_bf16_rtz (old, b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i16_rnu (carrier_u128 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t old = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t d = __riscv_ztt_mmulacc_ew_x_i16_rnu_1x1_u128_rdn_sat (old, b, __riscv_ztt_scalar_from_bits_u128_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i16_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rne_1x2_t b = __riscv_ztt_mzero_m_i16_rne_1x2 ();
  __riscv_ztt_i16_rne_1x2_t old = __riscv_ztt_mzero_m_i16_rne_1x2 ();
  __riscv_ztt_i16_rne_1x2_t d = __riscv_ztt_mmulacc_ew_x_i16_rne_1x2_f64_rup (old, b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i16_rdn (float c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i16_rdn_2x1_t old = __riscv_ztt_mzero_m_i16_rdn_2x1 ();
  __riscv_ztt_i16_rdn_2x1_t d = __riscv_ztt_mmulacc_ew_x_i16_rdn_2x1_f32_rne (old, b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i16_rod (__bf16 c)
{
  __riscv_ztt_i16_rod_1x1_t b = __riscv_ztt_mzero_m_i16_rod_1x1 ();
  __riscv_ztt_i16_rod_1x1_t old = __riscv_ztt_mzero_m_i16_rod_1x1 ();
  __riscv_ztt_i16_rod_1x1_t d = __riscv_ztt_mmulacc_ew_x_i16_rod_1x1_bf16_rno (old, b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u16_rnu (carrier_i8 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_u16_rnu_2x1_t old = __riscv_ztt_mzero_m_u16_rnu_2x1 ();
  __riscv_ztt_u16_rnu_2x1_t d = __riscv_ztt_mmulacc_ew_x_u16_rnu_2x1_i8_rdn (old, b, __riscv_ztt_scalar_make_i8_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u16_rne (_Float16 c)
{
  __riscv_ztt_u16_rne_1x2_t b = __riscv_ztt_mzero_m_u16_rne_1x2 ();
  __riscv_ztt_u16_rne_1x2_t old = __riscv_ztt_mzero_m_u16_rne_1x2 ();
  __riscv_ztt_u16_rne_1x2_t d = __riscv_ztt_mmulacc_ew_x_u16_rne_1x2_f16_rtz (old, b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u16_rdn (carrier_i32 c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_u16_rdn_1x1_t old = __riscv_ztt_mzero_m_u16_rdn_1x1 ();
  __riscv_ztt_u16_rdn_1x1_t d = __riscv_ztt_mmulacc_ew_x_u16_rdn_1x1_i32_rnu (old, b, __riscv_ztt_scalar_make_i32_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u16_rod (float c)
{
  __riscv_ztt_u16_rod_1x2_t b = __riscv_ztt_mzero_m_u16_rod_1x2 ();
  __riscv_ztt_u16_rod_1x2_t old = __riscv_ztt_mzero_m_u16_rod_1x2 ();
  __riscv_ztt_u16_rod_1x2_t d = __riscv_ztt_mmulacc_ew_x_u16_rod_1x2_f32_rup (old, b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i32_rnu (carrier_u64 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t old = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mmulacc_ew_x_i32_rnu_1x1_u64_rdn (old, b, __riscv_ztt_scalar_from_bits_u64_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i32_rne (_Float16 c)
{
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t old = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_mmulacc_ew_x_i32_rne_1x1_f16_rno (old, b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i32_rdn (carrier_u8 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t old = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_mmulacc_ew_x_i32_rdn_1x1_u8_rnu_sat (old, b, __riscv_ztt_scalar_make_u8_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i32_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t old = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mmulacc_ew_x_i32_rod_1x1_f64_rtz (old, b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u32_rnu (carrier_i32 c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t old = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mmulacc_ew_x_u32_rnu_1x1_i32_rdn_sat (old, b, __riscv_ztt_scalar_make_i32_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u32_rne (__bf16 c)
{
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t old = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_mmulacc_ew_x_u32_rne_1x1_bf16_rup (old, b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u32_rdn (carrier_i128 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t old = __riscv_ztt_mzero_m_u32_rdn_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mmulacc_ew_x_u32_rdn_1x1_i128_rnu_sat (old, b, __riscv_ztt_scalar_from_bits_i128_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u32_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t old = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_mmulacc_ew_x_u32_rod_1x1_f64_rno (old, b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i4_rnu_sat (__bf16 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i4_rnu_sat_2x1_t old = __riscv_ztt_mzero_m_i4_rnu_sat_2x1 ();
  __riscv_ztt_i4_rnu_sat_2x1_t d = __riscv_ztt_mmulacc_ew_x_i4_rnu_sat_2x1_bf16_rne (old, b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i4_rne_sat (float c)
{
  __riscv_ztt_i4_rne_sat_1x8_t b = __riscv_ztt_mzero_m_i4_rne_sat_1x8 ();
  __riscv_ztt_i4_rne_sat_1x8_t old = __riscv_ztt_mzero_m_i4_rne_sat_1x8 ();
  __riscv_ztt_i4_rne_sat_1x8_t d = __riscv_ztt_mmulacc_ew_x_i4_rne_sat_1x8_f32_rtz (old, b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i4_rdn_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i4_rdn_sat_2x1_t old = __riscv_ztt_mzero_m_i4_rdn_sat_2x1 ();
  __riscv_ztt_i4_rdn_sat_2x1_t d = __riscv_ztt_mmulacc_ew_x_i4_rdn_sat_2x1_f64_rdn (old, b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i4_rod_sat (_Float16 c)
{
  __riscv_ztt_i4_rod_sat_1x4_t b = __riscv_ztt_mzero_m_i4_rod_sat_1x4 ();
  __riscv_ztt_i4_rod_sat_1x4_t old = __riscv_ztt_mzero_m_i4_rod_sat_1x4 ();
  __riscv_ztt_i4_rod_sat_1x4_t d = __riscv_ztt_mmulacc_ew_x_i4_rod_sat_1x4_f16_rup (old, b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u4_rnu_sat (carrier_i16 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_u4_rnu_sat_2x1_t old = __riscv_ztt_mzero_m_u4_rnu_sat_2x1 ();
  __riscv_ztt_u4_rnu_sat_2x1_t d = __riscv_ztt_mmulacc_ew_x_u4_rnu_sat_2x1_i16_rdn (old, b, __riscv_ztt_scalar_make_i16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u4_rne_sat (float c)
{
  __riscv_ztt_u4_rne_sat_1x2_t b = __riscv_ztt_mzero_m_u4_rne_sat_1x2 ();
  __riscv_ztt_u4_rne_sat_1x2_t old = __riscv_ztt_mzero_m_u4_rne_sat_1x2 ();
  __riscv_ztt_u4_rne_sat_1x2_t d = __riscv_ztt_mmulacc_ew_x_u4_rne_sat_1x2_f32_rno (old, b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u4_rdn_sat (carrier_i64 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_u4_rdn_sat_2x1_t old = __riscv_ztt_mzero_m_u4_rdn_sat_2x1 ();
  __riscv_ztt_u4_rdn_sat_2x1_t d = __riscv_ztt_mmulacc_ew_x_u4_rdn_sat_2x1_i64_rnu (old, b, __riscv_ztt_scalar_from_bits_i64_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u4_rod_sat (__bf16 c)
{
  __riscv_ztt_u4_rod_sat_1x8_t b = __riscv_ztt_mzero_m_u4_rod_sat_1x8 ();
  __riscv_ztt_u4_rod_sat_1x8_t old = __riscv_ztt_mzero_m_u4_rod_sat_1x8 ();
  __riscv_ztt_u4_rod_sat_1x8_t d = __riscv_ztt_mmulacc_ew_x_u4_rod_sat_1x8_bf16_rtz (old, b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i8_rnu_sat (carrier_u128 c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t d = __riscv_ztt_mmulacc_ew_x_i8_rnu_sat_1x1_u128_rdn (old, b, __riscv_ztt_scalar_from_bits_u128_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i8_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rne_sat_1x2_t b = __riscv_ztt_mzero_m_i8_rne_sat_1x2 ();
  __riscv_ztt_i8_rne_sat_1x2_t old = __riscv_ztt_mzero_m_i8_rne_sat_1x2 ();
  __riscv_ztt_i8_rne_sat_1x2_t d = __riscv_ztt_mmulacc_ew_x_i8_rne_sat_1x2_f64_rup (old, b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i8_rdn_sat (carrier_u16 c)
{
  __riscv_ztt_bf16_rne_2x1_t b = __riscv_ztt_mzero_m_bf16_rne_2x1 ();
  __riscv_ztt_i8_rdn_sat_2x1_t old = __riscv_ztt_mzero_m_i8_rdn_sat_2x1 ();
  __riscv_ztt_i8_rdn_sat_2x1_t d = __riscv_ztt_mmulacc_ew_x_i8_rdn_sat_2x1_u16_rnu_sat (old, b, __riscv_ztt_scalar_make_u16_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i8_rod_sat (__bf16 c)
{
  __riscv_ztt_i8_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rod_sat_1x1 ();
  __riscv_ztt_i8_rod_sat_1x1_t old = __riscv_ztt_mzero_m_i8_rod_sat_1x1 ();
  __riscv_ztt_i8_rod_sat_1x1_t d = __riscv_ztt_mmulacc_ew_x_i8_rod_sat_1x1_bf16_rno (old, b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u8_rnu_sat (carrier_i64 c)
{
  __riscv_ztt_bf16_rdn_2x1_t b = __riscv_ztt_mzero_m_bf16_rdn_2x1 ();
  __riscv_ztt_u8_rnu_sat_2x1_t old = __riscv_ztt_mzero_m_u8_rnu_sat_2x1 ();
  __riscv_ztt_u8_rnu_sat_2x1_t d = __riscv_ztt_mmulacc_ew_x_u8_rnu_sat_2x1_i64_rdn_sat (old, b, __riscv_ztt_scalar_from_bits_i64_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u8_rne_sat (_Float16 c)
{
  __riscv_ztt_u8_rne_sat_1x4_t b = __riscv_ztt_mzero_m_u8_rne_sat_1x4 ();
  __riscv_ztt_u8_rne_sat_1x4_t old = __riscv_ztt_mzero_m_u8_rne_sat_1x4 ();
  __riscv_ztt_u8_rne_sat_1x4_t d = __riscv_ztt_mmulacc_ew_x_u8_rne_sat_1x4_f16_rtz (old, b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u8_rdn_sat (_Float16 c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_u8_rdn_sat_1x1_t old = __riscv_ztt_mzero_m_u8_rdn_sat_1x1 ();
  __riscv_ztt_u8_rdn_sat_1x1_t d = __riscv_ztt_mmulacc_ew_x_u8_rdn_sat_1x1_f16_rne (old, b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u8_rod_sat (float c)
{
  __riscv_ztt_u8_rod_sat_1x2_t b = __riscv_ztt_mzero_m_u8_rod_sat_1x2 ();
  __riscv_ztt_u8_rod_sat_1x2_t old = __riscv_ztt_mzero_m_u8_rod_sat_1x2 ();
  __riscv_ztt_u8_rod_sat_1x2_t d = __riscv_ztt_mmulacc_ew_x_u8_rod_sat_1x2_f32_rup (old, b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i16_rnu_sat (float c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_i16_rnu_sat_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t d = __riscv_ztt_mmulacc_ew_x_i16_rnu_sat_1x1_f32_rdn (old, b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i16_rne_sat (_Float16 c)
{
  __riscv_ztt_i16_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rne_sat_1x1 ();
  __riscv_ztt_i16_rne_sat_1x1_t old = __riscv_ztt_mzero_m_i16_rne_sat_1x1 ();
  __riscv_ztt_i16_rne_sat_1x1_t d = __riscv_ztt_mmulacc_ew_x_i16_rne_sat_1x1_f16_rno (old, b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i16_rdn_sat (carrier_u8 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t old = __riscv_ztt_mzero_m_i16_rdn_sat_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t d = __riscv_ztt_mmulacc_ew_x_i16_rdn_sat_1x1_u8_rnu (old, b, __riscv_ztt_scalar_make_u8_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i16_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rod_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rod_sat_1x2 ();
  __riscv_ztt_i16_rod_sat_1x2_t old = __riscv_ztt_mzero_m_i16_rod_sat_1x2 ();
  __riscv_ztt_i16_rod_sat_1x2_t d = __riscv_ztt_mmulacc_ew_x_i16_rod_sat_1x2_f64_rtz (old, b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u16_rnu_sat (carrier_i32 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_u16_rnu_sat_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t d = __riscv_ztt_mmulacc_ew_x_u16_rnu_sat_1x1_i32_rdn (old, b, __riscv_ztt_scalar_make_i32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u16_rne_sat (__bf16 c)
{
  __riscv_ztt_u16_rne_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rne_sat_1x2 ();
  __riscv_ztt_u16_rne_sat_1x2_t old = __riscv_ztt_mzero_m_u16_rne_sat_1x2 ();
  __riscv_ztt_u16_rne_sat_1x2_t d = __riscv_ztt_mmulacc_ew_x_u16_rne_sat_1x2_bf16_rup (old, b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u16_rdn_sat (carrier_i128 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_u16_rdn_sat_2x1_t old = __riscv_ztt_mzero_m_u16_rdn_sat_2x1 ();
  __riscv_ztt_u16_rdn_sat_2x1_t d = __riscv_ztt_mmulacc_ew_x_u16_rdn_sat_2x1_i128_rnu (old, b, __riscv_ztt_scalar_from_bits_i128_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u16_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rod_sat_1x1 ();
  __riscv_ztt_u16_rod_sat_1x1_t old = __riscv_ztt_mzero_m_u16_rod_sat_1x1 ();
  __riscv_ztt_u16_rod_sat_1x1_t d = __riscv_ztt_mmulacc_ew_x_u16_rod_sat_1x1_f64_rno (old, b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i32_rnu_sat (carrier_u8 c)
{
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rnu_sat_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_mmulacc_ew_x_i32_rnu_sat_1x1_u8_rdn_sat (old, b, __riscv_ztt_scalar_make_u8_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i32_rne_sat (float c)
{
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_mmulacc_ew_x_i32_rne_sat_1x1_f32_rtz (old, b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i32_rdn_sat (carrier_u32 c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rdn_sat_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mmulacc_ew_x_i32_rdn_sat_1x1_u32_rnu_sat (old, b, __riscv_ztt_scalar_make_u32_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_i32_rod_sat (_Float16 c)
{
  __riscv_ztt_i32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_mmulacc_ew_x_i32_rod_sat_1x1_f16_rup (old, b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u32_rnu_sat (carrier_i128 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rnu_sat_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_mmulacc_ew_x_u32_rnu_sat_1x1_i128_rdn_sat (old, b, __riscv_ztt_scalar_from_bits_i128_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u32_rne_sat (float c)
{
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mmulacc_ew_x_u32_rne_sat_1x1_f32_rno (old, b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u32_rdn_sat (__bf16 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rdn_sat_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_mmulacc_ew_x_u32_rdn_sat_1x1_bf16_rdn (old, b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_u32_rod_sat (__bf16 c)
{
  __riscv_ztt_u32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_mmulacc_ew_x_u32_rod_sat_1x1_bf16_rtz (old, b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_f16_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_f16_rne_1x1_t old = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_f16_rne_1x1_t d = __riscv_ztt_mmulacc_ew_x_f16_rne_1x1_f64_rmm (old, b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_f16_rtz (carrier_u8 c)
{
  __riscv_ztt_f16_rtz_1x2_t b = __riscv_ztt_mzero_m_f16_rtz_1x2 ();
  __riscv_ztt_f16_rtz_1x2_t old = __riscv_ztt_mzero_m_f16_rtz_1x2 ();
  __riscv_ztt_f16_rtz_1x2_t d = __riscv_ztt_mmulacc_ew_x_f16_rtz_1x2_u8_rne (old, b, __riscv_ztt_scalar_make_u8_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_f16_rdn (carrier_u16 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_f16_rdn_2x1_t old = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_f16_rdn_2x1_t d = __riscv_ztt_mmulacc_ew_x_f16_rdn_2x1_u16_rnu (old, b, __riscv_ztt_scalar_make_u16_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_f16_rup (carrier_i32 c)
{
  __riscv_ztt_f16_rup_1x1_t b = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_f16_rup_1x1_t old = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_f16_rup_1x1_t d = __riscv_ztt_mmulacc_ew_x_f16_rup_1x1_i32_rod (old, b, __riscv_ztt_scalar_make_i32_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_f16_rmm (carrier_i64 c)
{
  __riscv_ztt_f16_rmm_2x1_t b = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_f16_rmm_2x1_t old = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_f16_rmm_2x1_t d = __riscv_ztt_mmulacc_ew_x_f16_rmm_2x1_i64_rdn (old, b, __riscv_ztt_scalar_from_bits_i64_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_f16_rno (carrier_i128 c)
{
  __riscv_ztt_f16_rno_1x2_t b = __riscv_ztt_mzero_m_f16_rno_1x2 ();
  __riscv_ztt_f16_rno_1x2_t old = __riscv_ztt_mzero_m_f16_rno_1x2 ();
  __riscv_ztt_f16_rno_1x2_t d = __riscv_ztt_mmulacc_ew_x_f16_rno_1x2_i128_rne (old, b, __riscv_ztt_scalar_from_bits_i128_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_bf16_rne (carrier_i8 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t old = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t d = __riscv_ztt_mmulacc_ew_x_bf16_rne_1x1_i8_rnu_sat (old, b, __riscv_ztt_scalar_make_i8_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_bf16_rtz (carrier_u8 c)
{
  __riscv_ztt_bf16_rtz_1x2_t b = __riscv_ztt_mzero_m_bf16_rtz_1x2 ();
  __riscv_ztt_bf16_rtz_1x2_t old = __riscv_ztt_mzero_m_bf16_rtz_1x2 ();
  __riscv_ztt_bf16_rtz_1x2_t d = __riscv_ztt_mmulacc_ew_x_bf16_rtz_1x2_u8_rod_sat (old, b, __riscv_ztt_scalar_make_u8_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_bf16_rdn (carrier_u16 c)
{
  __riscv_ztt_bf16_rdn_2x1_t b = __riscv_ztt_mzero_m_bf16_rdn_2x1 ();
  __riscv_ztt_bf16_rdn_2x1_t old = __riscv_ztt_mzero_m_bf16_rdn_2x1 ();
  __riscv_ztt_bf16_rdn_2x1_t d = __riscv_ztt_mmulacc_ew_x_bf16_rdn_2x1_u16_rdn_sat (old, b, __riscv_ztt_scalar_make_u16_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_bf16_rup (carrier_u32 c)
{
  __riscv_ztt_bf16_rup_1x1_t b = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_bf16_rup_1x1_t old = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_bf16_rup_1x1_t d = __riscv_ztt_mmulacc_ew_x_bf16_rup_1x1_u32_rne_sat (old, b, __riscv_ztt_scalar_make_u32_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_bf16_rmm (carrier_u64 c)
{
  __riscv_ztt_bf16_rmm_2x1_t b = __riscv_ztt_mzero_m_bf16_rmm_2x1 ();
  __riscv_ztt_bf16_rmm_2x1_t old = __riscv_ztt_mzero_m_bf16_rmm_2x1 ();
  __riscv_ztt_bf16_rmm_2x1_t d = __riscv_ztt_mmulacc_ew_x_bf16_rmm_2x1_u64_rnu_sat (old, b, __riscv_ztt_scalar_from_bits_u64_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_bf16_rno (carrier_i128 c)
{
  __riscv_ztt_bf16_rno_1x2_t b = __riscv_ztt_mzero_m_bf16_rno_1x2 ();
  __riscv_ztt_bf16_rno_1x2_t old = __riscv_ztt_mzero_m_bf16_rno_1x2 ();
  __riscv_ztt_bf16_rno_1x2_t d = __riscv_ztt_mmulacc_ew_x_bf16_rno_1x2_i128_rod_sat (old, b, __riscv_ztt_scalar_from_bits_i128_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_f32_rne (_Float16 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t old = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mmulacc_ew_x_f32_rne_1x1_f16_rdn (old, b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_f32_rtz (__bf16 c)
{
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t old = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mmulacc_ew_x_f32_rtz_1x1_bf16_rup (old, b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_f32_rdn (float c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t old = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mmulacc_ew_x_f32_rdn_1x1_f32_rmm (old, b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_f32_rup (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t old = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mmulacc_ew_x_f32_rup_1x1_f64_rno (old, b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_f32_rmm (carrier_u8 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t old = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mmulacc_ew_x_f32_rmm_1x1_u8_rdn (old, b, __riscv_ztt_scalar_make_u8_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulacc_f32_rno (carrier_u16 c)
{
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t old = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mmulacc_ew_x_f32_rno_1x1_u16_rne (old, b, __riscv_ztt_scalar_make_u16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i4_rnu (carrier_i128 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i4_rnu_1x2_t old = __riscv_ztt_mzero_m_i4_rnu_1x2 ();
  __riscv_ztt_i4_rnu_1x2_t d = __riscv_ztt_mmulaccneg_ew_x_i4_rnu_1x2_i128_rod_sat (old, b, __riscv_ztt_scalar_from_bits_i128_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i4_rne (__bf16 c)
{
  __riscv_ztt_i4_rne_4x1_t b = __riscv_ztt_mzero_m_i4_rne_4x1 ();
  __riscv_ztt_i4_rne_4x1_t old = __riscv_ztt_mzero_m_i4_rne_4x1 ();
  __riscv_ztt_i4_rne_4x1_t d = __riscv_ztt_mmulaccneg_ew_x_i4_rne_4x1_bf16_rmm (old, b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i4_rdn (__bf16 c)
{
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_i4_rdn_1x2_t old = __riscv_ztt_mzero_m_i4_rdn_1x2 ();
  __riscv_ztt_i4_rdn_1x2_t d = __riscv_ztt_mmulaccneg_ew_x_i4_rdn_1x2_bf16_rup (old, b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i4_rod (_Float16 c)
{
  __riscv_ztt_i4_rod_2x1_t b = __riscv_ztt_mzero_m_i4_rod_2x1 ();
  __riscv_ztt_i4_rod_2x1_t old = __riscv_ztt_mzero_m_i4_rod_2x1 ();
  __riscv_ztt_i4_rod_2x1_t d = __riscv_ztt_mmulaccneg_ew_x_i4_rod_2x1_f16_rne (old, b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u4_rnu (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f16_rmm_1x2_t b = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_u4_rnu_1x2_t old = __riscv_ztt_mzero_m_u4_rnu_1x2 ();
  __riscv_ztt_u4_rnu_1x2_t d = __riscv_ztt_mmulaccneg_ew_x_u4_rnu_1x2_f64_rno (old, b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u4_rne (float c)
{
  __riscv_ztt_u4_rne_8x1_t b = __riscv_ztt_mzero_m_u4_rne_8x1 ();
  __riscv_ztt_u4_rne_8x1_t old = __riscv_ztt_mzero_m_u4_rne_8x1 ();
  __riscv_ztt_u4_rne_8x1_t d = __riscv_ztt_mmulaccneg_ew_x_u4_rne_8x1_f32_rdn (old, b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u4_rdn (carrier_u16 c)
{
  __riscv_ztt_bf16_rne_1x2_t b = __riscv_ztt_mzero_m_bf16_rne_1x2 ();
  __riscv_ztt_u4_rdn_1x2_t old = __riscv_ztt_mzero_m_u4_rdn_1x2 ();
  __riscv_ztt_u4_rdn_1x2_t d = __riscv_ztt_mmulaccneg_ew_x_u4_rdn_1x2_u16_rne (old, b, __riscv_ztt_scalar_make_u16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u4_rod (_Float16 c)
{
  __riscv_ztt_u4_rod_4x1_t b = __riscv_ztt_mzero_m_u4_rod_4x1 ();
  __riscv_ztt_u4_rod_4x1_t old = __riscv_ztt_mzero_m_u4_rod_4x1 ();
  __riscv_ztt_u4_rod_4x1_t d = __riscv_ztt_mmulaccneg_ew_x_u4_rod_4x1_f16_rmm (old, b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i8_rnu (carrier_i64 c)
{
  __riscv_ztt_bf16_rdn_1x2_t b = __riscv_ztt_mzero_m_bf16_rdn_1x2 ();
  __riscv_ztt_i8_rnu_1x2_t old = __riscv_ztt_mzero_m_i8_rnu_1x2 ();
  __riscv_ztt_i8_rnu_1x2_t d = __riscv_ztt_mmulaccneg_ew_x_i8_rnu_1x2_i64_rod (old, b, __riscv_ztt_scalar_from_bits_i64_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i8_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rne_1x1_t b = __riscv_ztt_mzero_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t old = __riscv_ztt_mzero_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_i8_rne_1x1_f64_rne (old, b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i8_rdn (carrier_i8 c)
{
  __riscv_ztt_bf16_rmm_1x2_t b = __riscv_ztt_mzero_m_bf16_rmm_1x2 ();
  __riscv_ztt_i8_rdn_1x2_t old = __riscv_ztt_mzero_m_i8_rdn_1x2 ();
  __riscv_ztt_i8_rdn_1x2_t d = __riscv_ztt_mmulaccneg_ew_x_i8_rdn_1x2_i8_rne_sat (old, b, __riscv_ztt_scalar_make_i8_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i8_rod (__bf16 c)
{
  __riscv_ztt_i8_rod_4x1_t b = __riscv_ztt_mzero_m_i8_rod_4x1 ();
  __riscv_ztt_i8_rod_4x1_t old = __riscv_ztt_mzero_m_i8_rod_4x1 ();
  __riscv_ztt_i8_rod_4x1_t d = __riscv_ztt_mmulaccneg_ew_x_i8_rod_4x1_bf16_rdn (old, b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u8_rnu (carrier_u16 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t old = __riscv_ztt_mzero_m_u8_rnu_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_u8_rnu_1x1_u16_rod_sat (old, b, __riscv_ztt_scalar_make_u16_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u8_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rne_2x1_t b = __riscv_ztt_mzero_m_u8_rne_2x1 ();
  __riscv_ztt_u8_rne_2x1_t old = __riscv_ztt_mzero_m_u8_rne_2x1 ();
  __riscv_ztt_u8_rne_2x1_t d = __riscv_ztt_mmulaccneg_ew_x_u8_rne_2x1_f64_rmm (old, b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u8_rdn (carrier_u64 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t old = __riscv_ztt_mzero_m_u8_rdn_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_u8_rdn_1x1_u64_rne_sat (old, b, __riscv_ztt_scalar_from_bits_u64_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u8_rod (float c)
{
  __riscv_ztt_u8_rod_1x1_t b = __riscv_ztt_mzero_m_u8_rod_1x1 ();
  __riscv_ztt_u8_rod_1x1_t old = __riscv_ztt_mzero_m_u8_rod_1x1 ();
  __riscv_ztt_u8_rod_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_u8_rod_1x1_f32_rne (old, b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i16_rnu (_Float16 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t old = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_i16_rnu_1x1_f16_rup (old, b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i16_rne (_Float16 c)
{
  __riscv_ztt_i16_rne_2x1_t b = __riscv_ztt_mzero_m_i16_rne_2x1 ();
  __riscv_ztt_i16_rne_2x1_t old = __riscv_ztt_mzero_m_i16_rne_2x1 ();
  __riscv_ztt_i16_rne_2x1_t d = __riscv_ztt_mmulaccneg_ew_x_i16_rne_2x1_f16_rdn (old, b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i16_rdn (float c)
{
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_i16_rdn_1x1_t old = __riscv_ztt_mzero_m_i16_rdn_1x1 ();
  __riscv_ztt_i16_rdn_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_i16_rdn_1x1_f32_rno (old, b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i16_rod (float c)
{
  __riscv_ztt_i16_rod_2x1_t b = __riscv_ztt_mzero_m_i16_rod_2x1 ();
  __riscv_ztt_i16_rod_2x1_t old = __riscv_ztt_mzero_m_i16_rod_2x1 ();
  __riscv_ztt_i16_rod_2x1_t d = __riscv_ztt_mmulaccneg_ew_x_i16_rod_2x1_f32_rmm (old, b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u16_rnu (carrier_u8 c)
{
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_u16_rnu_1x2_t old = __riscv_ztt_mzero_m_u16_rnu_1x2 ();
  __riscv_ztt_u16_rnu_1x2_t d = __riscv_ztt_mmulaccneg_ew_x_u16_rnu_1x2_u8_rod (old, b, __riscv_ztt_scalar_make_u8_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u16_rne (__bf16 c)
{
  __riscv_ztt_u16_rne_1x1_t b = __riscv_ztt_mzero_m_u16_rne_1x1 ();
  __riscv_ztt_u16_rne_1x1_t old = __riscv_ztt_mzero_m_u16_rne_1x1 ();
  __riscv_ztt_u16_rne_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_u16_rne_1x1_bf16_rne (old, b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u16_rdn (carrier_u32 c)
{
  __riscv_ztt_f16_rmm_1x2_t b = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_u16_rdn_1x2_t old = __riscv_ztt_mzero_m_u16_rdn_1x2 ();
  __riscv_ztt_u16_rdn_1x2_t d = __riscv_ztt_mmulaccneg_ew_x_u16_rdn_1x2_u32_rne (old, b, __riscv_ztt_scalar_make_u32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u16_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rod_2x1_t b = __riscv_ztt_mzero_m_u16_rod_2x1 ();
  __riscv_ztt_u16_rod_2x1_t old = __riscv_ztt_mzero_m_u16_rod_2x1 ();
  __riscv_ztt_u16_rod_2x1_t d = __riscv_ztt_mmulaccneg_ew_x_u16_rod_2x1_f64_rdn (old, b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i32_rnu (carrier_i128 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t old = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_i32_rnu_1x1_i128_rod (old, b, __riscv_ztt_scalar_from_bits_i128_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i32_rne (__bf16 c)
{
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t old = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_i32_rne_1x1_bf16_rmm (old, b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i32_rdn (carrier_i16 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t old = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_i32_rdn_1x1_i16_rne_sat (old, b, __riscv_ztt_scalar_make_i16_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i32_rod (_Float16 c)
{
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t old = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_i32_rod_1x1_f16_rne (old, b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u32_rnu (carrier_u32 c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t old = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_u32_rnu_1x1_u32_rod_sat (old, b, __riscv_ztt_scalar_make_u32_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u32_rne (float c)
{
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t old = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_u32_rne_1x1_f32_rdn (old, b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u32_rdn (carrier_u128 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t old = __riscv_ztt_mzero_m_u32_rdn_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_u32_rdn_1x1_u128_rne_sat (old, b, __riscv_ztt_scalar_from_bits_u128_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u32_rod (_Float16 c)
{
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t old = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_u32_rod_1x1_f16_rmm (old, b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i4_rnu_sat (__bf16 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i4_rnu_sat_1x2_t old = __riscv_ztt_mzero_m_i4_rnu_sat_1x2 ();
  __riscv_ztt_i4_rnu_sat_1x2_t d = __riscv_ztt_mmulaccneg_ew_x_i4_rnu_sat_1x2_bf16_rno (old, b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i4_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rne_sat_2x1_t b = __riscv_ztt_mzero_m_i4_rne_sat_2x1 ();
  __riscv_ztt_i4_rne_sat_2x1_t old = __riscv_ztt_mzero_m_i4_rne_sat_2x1 ();
  __riscv_ztt_i4_rne_sat_2x1_t d = __riscv_ztt_mmulaccneg_ew_x_i4_rne_sat_2x1_f64_rne (old, b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i4_rdn_sat (carrier_i8 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i4_rdn_sat_1x2_t old = __riscv_ztt_mzero_m_i4_rdn_sat_1x2 ();
  __riscv_ztt_i4_rdn_sat_1x2_t d = __riscv_ztt_mmulaccneg_ew_x_i4_rdn_sat_1x2_i8_rne (old, b, __riscv_ztt_scalar_make_i8_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i4_rod_sat (__bf16 c)
{
  __riscv_ztt_i4_rod_sat_8x1_t b = __riscv_ztt_mzero_m_i4_rod_sat_8x1 ();
  __riscv_ztt_i4_rod_sat_8x1_t old = __riscv_ztt_mzero_m_i4_rod_sat_8x1 ();
  __riscv_ztt_i4_rod_sat_8x1_t d = __riscv_ztt_mmulaccneg_ew_x_i4_rod_sat_8x1_bf16_rdn (old, b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u4_rnu_sat (carrier_u16 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_u4_rnu_sat_1x2_t old = __riscv_ztt_mzero_m_u4_rnu_sat_1x2 ();
  __riscv_ztt_u4_rnu_sat_1x2_t d = __riscv_ztt_mmulaccneg_ew_x_u4_rnu_sat_1x2_u16_rod (old, b, __riscv_ztt_scalar_make_u16_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u4_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rne_sat_4x1_t b = __riscv_ztt_mzero_m_u4_rne_sat_4x1 ();
  __riscv_ztt_u4_rne_sat_4x1_t old = __riscv_ztt_mzero_m_u4_rne_sat_4x1 ();
  __riscv_ztt_u4_rne_sat_4x1_t d = __riscv_ztt_mmulaccneg_ew_x_u4_rne_sat_4x1_f64_rmm (old, b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u4_rdn_sat (carrier_u64 c)
{
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_u4_rdn_sat_1x2_t old = __riscv_ztt_mzero_m_u4_rdn_sat_1x2 ();
  __riscv_ztt_u4_rdn_sat_1x2_t d = __riscv_ztt_mmulaccneg_ew_x_u4_rdn_sat_1x2_u64_rne (old, b, __riscv_ztt_scalar_from_bits_u64_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u4_rod_sat (float c)
{
  __riscv_ztt_u4_rod_sat_2x1_t b = __riscv_ztt_mzero_m_u4_rod_sat_2x1 ();
  __riscv_ztt_u4_rod_sat_2x1_t old = __riscv_ztt_mzero_m_u4_rod_sat_2x1 ();
  __riscv_ztt_u4_rod_sat_2x1_t d = __riscv_ztt_mmulaccneg_ew_x_u4_rod_sat_2x1_f32_rne (old, b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i8_rnu_sat (carrier_i8 c)
{
  __riscv_ztt_f16_rmm_1x2_t b = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_i8_rnu_sat_1x2_t old = __riscv_ztt_mzero_m_i8_rnu_sat_1x2 ();
  __riscv_ztt_i8_rnu_sat_1x2_t d = __riscv_ztt_mmulaccneg_ew_x_i8_rnu_sat_1x2_i8_rod_sat (old, b, __riscv_ztt_scalar_make_i8_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i8_rne_sat (_Float16 c)
{
  __riscv_ztt_i8_rne_sat_4x1_t b = __riscv_ztt_mzero_m_i8_rne_sat_4x1 ();
  __riscv_ztt_i8_rne_sat_4x1_t old = __riscv_ztt_mzero_m_i8_rne_sat_4x1 ();
  __riscv_ztt_i8_rne_sat_4x1_t d = __riscv_ztt_mmulaccneg_ew_x_i8_rne_sat_4x1_f16_rdn (old, b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i8_rdn_sat (carrier_i32 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_i8_rdn_sat_1x1_t old = __riscv_ztt_mzero_m_i8_rdn_sat_1x1 ();
  __riscv_ztt_i8_rdn_sat_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_i8_rdn_sat_1x1_i32_rne_sat (old, b, __riscv_ztt_scalar_make_i32_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i8_rod_sat (float c)
{
  __riscv_ztt_i8_rod_sat_2x1_t b = __riscv_ztt_mzero_m_i8_rod_sat_2x1 ();
  __riscv_ztt_i8_rod_sat_2x1_t old = __riscv_ztt_mzero_m_i8_rod_sat_2x1 ();
  __riscv_ztt_i8_rod_sat_2x1_t d = __riscv_ztt_mmulaccneg_ew_x_i8_rod_sat_2x1_f32_rmm (old, b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u8_rnu_sat (carrier_u64 c)
{
  __riscv_ztt_bf16_rdn_1x2_t b = __riscv_ztt_mzero_m_bf16_rdn_1x2 ();
  __riscv_ztt_u8_rnu_sat_1x2_t old = __riscv_ztt_mzero_m_u8_rnu_sat_1x2 ();
  __riscv_ztt_u8_rnu_sat_1x2_t d = __riscv_ztt_mmulaccneg_ew_x_u8_rnu_sat_1x2_u64_rod_sat (old, b, __riscv_ztt_scalar_from_bits_u64_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u8_rne_sat (__bf16 c)
{
  __riscv_ztt_u8_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rne_sat_1x1 ();
  __riscv_ztt_u8_rne_sat_1x1_t old = __riscv_ztt_mzero_m_u8_rne_sat_1x1 ();
  __riscv_ztt_u8_rne_sat_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_u8_rne_sat_1x1_bf16_rne (old, b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u8_rdn_sat (_Float16 c)
{
  __riscv_ztt_bf16_rmm_1x2_t b = __riscv_ztt_mzero_m_bf16_rmm_1x2 ();
  __riscv_ztt_u8_rdn_sat_1x2_t old = __riscv_ztt_mzero_m_u8_rdn_sat_1x2 ();
  __riscv_ztt_u8_rdn_sat_1x2_t d = __riscv_ztt_mmulaccneg_ew_x_u8_rdn_sat_1x2_f16_rno (old, b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u8_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rod_sat_4x1_t b = __riscv_ztt_mzero_m_u8_rod_sat_4x1 ();
  __riscv_ztt_u8_rod_sat_4x1_t old = __riscv_ztt_mzero_m_u8_rod_sat_4x1 ();
  __riscv_ztt_u8_rod_sat_4x1_t d = __riscv_ztt_mmulaccneg_ew_x_u8_rod_sat_4x1_f64_rdn (old, b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i16_rnu_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_i16_rnu_sat_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_i16_rnu_sat_1x1_f64_rtz (old, b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i16_rne_sat (__bf16 c)
{
  __riscv_ztt_i16_rne_sat_2x1_t b = __riscv_ztt_mzero_m_i16_rne_sat_2x1 ();
  __riscv_ztt_i16_rne_sat_2x1_t old = __riscv_ztt_mzero_m_i16_rne_sat_2x1 ();
  __riscv_ztt_i16_rne_sat_2x1_t d = __riscv_ztt_mmulaccneg_ew_x_i16_rne_sat_2x1_bf16_rmm (old, b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i16_rdn_sat (carrier_i16 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t old = __riscv_ztt_mzero_m_i16_rdn_sat_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_i16_rdn_sat_1x1_i16_rne (old, b, __riscv_ztt_scalar_make_i16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i16_rod_sat (_Float16 c)
{
  __riscv_ztt_i16_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rod_sat_1x1 ();
  __riscv_ztt_i16_rod_sat_1x1_t old = __riscv_ztt_mzero_m_i16_rod_sat_1x1 ();
  __riscv_ztt_i16_rod_sat_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_i16_rod_sat_1x1_f16_rne (old, b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u16_rnu_sat (carrier_u32 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_u16_rnu_sat_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_u16_rnu_sat_1x1_u32_rod (old, b, __riscv_ztt_scalar_make_u32_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u16_rne_sat (float c)
{
  __riscv_ztt_u16_rne_sat_2x1_t b = __riscv_ztt_mzero_m_u16_rne_sat_2x1 ();
  __riscv_ztt_u16_rne_sat_2x1_t old = __riscv_ztt_mzero_m_u16_rne_sat_2x1 ();
  __riscv_ztt_u16_rne_sat_2x1_t d = __riscv_ztt_mmulaccneg_ew_x_u16_rne_sat_2x1_f32_rdn (old, b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u16_rdn_sat (carrier_u128 c)
{
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_u16_rdn_sat_1x1_t old = __riscv_ztt_mzero_m_u16_rdn_sat_1x1 ();
  __riscv_ztt_u16_rdn_sat_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_u16_rdn_sat_1x1_u128_rne (old, b, __riscv_ztt_scalar_from_bits_u128_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u16_rod_sat (_Float16 c)
{
  __riscv_ztt_u16_rod_sat_2x1_t b = __riscv_ztt_mzero_m_u16_rod_sat_2x1 ();
  __riscv_ztt_u16_rod_sat_2x1_t old = __riscv_ztt_mzero_m_u16_rod_sat_2x1 ();
  __riscv_ztt_u16_rod_sat_2x1_t d = __riscv_ztt_mmulaccneg_ew_x_u16_rod_sat_2x1_f16_rmm (old, b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i32_rnu_sat (carrier_i16 c)
{
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rnu_sat_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_i32_rnu_sat_1x1_i16_rod_sat (old, b, __riscv_ztt_scalar_make_i16_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i32_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_i32_rne_sat_1x1_f64_rne (old, b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i32_rdn_sat (carrier_i64 c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rdn_sat_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_i32_rdn_sat_1x1_i64_rne_sat (old, b, __riscv_ztt_scalar_from_bits_i64_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_i32_rod_sat (__bf16 c)
{
  __riscv_ztt_i32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_i32_rod_sat_1x1_bf16_rdn (old, b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u32_rnu_sat (carrier_u128 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rnu_sat_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_u32_rnu_sat_1x1_u128_rod_sat (old, b, __riscv_ztt_scalar_from_bits_u128_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u32_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_u32_rne_sat_1x1_f64_rmm (old, b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u32_rdn_sat (float c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rdn_sat_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_u32_rdn_sat_1x1_f32_rtz (old, b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_u32_rod_sat (float c)
{
  __riscv_ztt_u32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_u32_rod_sat_1x1_f32_rne (old, b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_f16_rne (carrier_i8 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_f16_rne_1x2_t old = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_f16_rne_1x2_t d = __riscv_ztt_mmulaccneg_ew_x_f16_rne_1x2_i8_rod (old, b, __riscv_ztt_scalar_make_i8_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_f16_rtz (carrier_i16 c)
{
  __riscv_ztt_f16_rtz_2x1_t b = __riscv_ztt_mzero_m_f16_rtz_2x1 ();
  __riscv_ztt_f16_rtz_2x1_t old = __riscv_ztt_mzero_m_f16_rtz_2x1 ();
  __riscv_ztt_f16_rtz_2x1_t d = __riscv_ztt_mmulaccneg_ew_x_f16_rtz_2x1_i16_rdn (old, b, __riscv_ztt_scalar_make_i16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_f16_rdn (carrier_i32 c)
{
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t old = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_f16_rdn_1x1_i32_rne (old, b, __riscv_ztt_scalar_make_i32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_f16_rup (carrier_i64 c)
{
  __riscv_ztt_f16_rup_2x1_t b = __riscv_ztt_mzero_m_f16_rup_2x1 ();
  __riscv_ztt_f16_rup_2x1_t old = __riscv_ztt_mzero_m_f16_rup_2x1 ();
  __riscv_ztt_f16_rup_2x1_t d = __riscv_ztt_mmulaccneg_ew_x_f16_rup_2x1_i64_rnu (old, b, __riscv_ztt_scalar_from_bits_i64_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_f16_rmm (carrier_u64 c)
{
  __riscv_ztt_f16_rmm_1x2_t b = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_f16_rmm_1x2_t old = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_f16_rmm_1x2_t d = __riscv_ztt_mmulaccneg_ew_x_f16_rmm_1x2_u64_rod (old, b, __riscv_ztt_scalar_from_bits_u64_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_f16_rno (carrier_u128 c)
{
  __riscv_ztt_f16_rno_1x1_t b = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_f16_rno_1x1_t old = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_f16_rno_1x1_u128_rdn (old, b, __riscv_ztt_scalar_from_bits_u128_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_bf16_rne (carrier_u8 c)
{
  __riscv_ztt_bf16_rne_1x2_t b = __riscv_ztt_mzero_m_bf16_rne_1x2 ();
  __riscv_ztt_bf16_rne_1x2_t old = __riscv_ztt_mzero_m_bf16_rne_1x2 ();
  __riscv_ztt_bf16_rne_1x2_t d = __riscv_ztt_mmulaccneg_ew_x_bf16_rne_1x2_u8_rne_sat (old, b, __riscv_ztt_scalar_make_u8_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_bf16_rtz (carrier_u16 c)
{
  __riscv_ztt_bf16_rtz_2x1_t b = __riscv_ztt_mzero_m_bf16_rtz_2x1 ();
  __riscv_ztt_bf16_rtz_2x1_t old = __riscv_ztt_mzero_m_bf16_rtz_2x1 ();
  __riscv_ztt_bf16_rtz_2x1_t d = __riscv_ztt_mmulaccneg_ew_x_bf16_rtz_2x1_u16_rnu_sat (old, b, __riscv_ztt_scalar_make_u16_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_bf16_rdn (carrier_i32 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t old = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_bf16_rdn_1x1_i32_rod_sat (old, b, __riscv_ztt_scalar_make_i32_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_bf16_rup (carrier_i64 c)
{
  __riscv_ztt_bf16_rup_2x1_t b = __riscv_ztt_mzero_m_bf16_rup_2x1 ();
  __riscv_ztt_bf16_rup_2x1_t old = __riscv_ztt_mzero_m_bf16_rup_2x1 ();
  __riscv_ztt_bf16_rup_2x1_t d = __riscv_ztt_mmulaccneg_ew_x_bf16_rup_2x1_i64_rdn_sat (old, b, __riscv_ztt_scalar_from_bits_i64_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_bf16_rmm (carrier_i128 c)
{
  __riscv_ztt_bf16_rmm_1x2_t b = __riscv_ztt_mzero_m_bf16_rmm_1x2 ();
  __riscv_ztt_bf16_rmm_1x2_t old = __riscv_ztt_mzero_m_bf16_rmm_1x2 ();
  __riscv_ztt_bf16_rmm_1x2_t d = __riscv_ztt_mmulaccneg_ew_x_bf16_rmm_1x2_i128_rne_sat (old, b, __riscv_ztt_scalar_from_bits_i128_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_bf16_rno (_Float16 c)
{
  __riscv_ztt_bf16_rno_1x1_t b = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t old = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_bf16_rno_1x1_f16_rne (old, b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_f32_rne (__bf16 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t old = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_f32_rne_1x1_bf16_rtz (old, b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_f32_rtz (float c)
{
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t old = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_f32_rtz_1x1_f32_rdn (old, b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_f32_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t old = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_f32_rdn_1x1_f64_rup (old, b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_f32_rup (carrier_u8 c)
{
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t old = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_f32_rup_1x1_u8_rnu (old, b, __riscv_ztt_scalar_make_u8_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_f32_rmm (carrier_i16 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t old = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_f32_rmm_1x1_i16_rod (old, b, __riscv_ztt_scalar_make_i16_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulaccneg_f32_rno (carrier_i32 c)
{
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t old = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_f32_rno_1x1_i32_rdn (old, b, __riscv_ztt_scalar_make_i32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i4_rnu (_Float16 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i4_rnu_2x1_t old = __riscv_ztt_mzero_m_i4_rnu_2x1 ();
  __riscv_ztt_i4_rnu_2x1_t d = __riscv_ztt_mmuladd_ew_x_i4_rnu_2x1_f16_rne (old, b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i4_rne (float c)
{
  __riscv_ztt_i4_rne_1x8_t b = __riscv_ztt_mzero_m_i4_rne_1x8 ();
  __riscv_ztt_i4_rne_1x8_t old = __riscv_ztt_mzero_m_i4_rne_1x8 ();
  __riscv_ztt_i4_rne_1x8_t d = __riscv_ztt_mmuladd_ew_x_i4_rne_1x8_f32_rup (old, b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i4_rdn (float c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_i4_rdn_2x1_t old = __riscv_ztt_mzero_m_i4_rdn_2x1 ();
  __riscv_ztt_i4_rdn_2x1_t d = __riscv_ztt_mmuladd_ew_x_i4_rdn_2x1_f32_rdn (old, b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i4_rod (_Float16 c)
{
  __riscv_ztt_i4_rod_1x4_t b = __riscv_ztt_mzero_m_i4_rod_1x4 ();
  __riscv_ztt_i4_rod_1x4_t old = __riscv_ztt_mzero_m_i4_rod_1x4 ();
  __riscv_ztt_i4_rod_1x4_t d = __riscv_ztt_mmuladd_ew_x_i4_rod_1x4_f16_rno (old, b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u4_rnu (carrier_u8 c)
{
  __riscv_ztt_f16_rmm_2x1_t b = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_u4_rnu_2x1_t old = __riscv_ztt_mzero_m_u4_rnu_2x1 ();
  __riscv_ztt_u4_rnu_2x1_t d = __riscv_ztt_mmuladd_ew_x_u4_rnu_2x1_u8_rnu (old, b, __riscv_ztt_scalar_make_u8_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u4_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rne_1x2_t b = __riscv_ztt_mzero_m_u4_rne_1x2 ();
  __riscv_ztt_u4_rne_1x2_t old = __riscv_ztt_mzero_m_u4_rne_1x2 ();
  __riscv_ztt_u4_rne_1x2_t d = __riscv_ztt_mmuladd_ew_x_u4_rne_1x2_f64_rtz (old, b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u4_rdn (carrier_i32 c)
{
  __riscv_ztt_bf16_rne_2x1_t b = __riscv_ztt_mzero_m_bf16_rne_2x1 ();
  __riscv_ztt_u4_rdn_2x1_t old = __riscv_ztt_mzero_m_u4_rdn_2x1 ();
  __riscv_ztt_u4_rdn_2x1_t d = __riscv_ztt_mmuladd_ew_x_u4_rdn_2x1_i32_rdn (old, b, __riscv_ztt_scalar_make_i32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u4_rod (__bf16 c)
{
  __riscv_ztt_u4_rod_1x8_t b = __riscv_ztt_mzero_m_u4_rod_1x8 ();
  __riscv_ztt_u4_rod_1x8_t old = __riscv_ztt_mzero_m_u4_rod_1x8 ();
  __riscv_ztt_u4_rod_1x8_t d = __riscv_ztt_mmuladd_ew_x_u4_rod_1x8_bf16_rup (old, b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i8_rnu (carrier_i128 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t old = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t d = __riscv_ztt_mmuladd_ew_x_i8_rnu_1x1_i128_rnu (old, b, __riscv_ztt_scalar_from_bits_i128_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i8_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rne_1x2_t b = __riscv_ztt_mzero_m_i8_rne_1x2 ();
  __riscv_ztt_i8_rne_1x2_t old = __riscv_ztt_mzero_m_i8_rne_1x2 ();
  __riscv_ztt_i8_rne_1x2_t d = __riscv_ztt_mmuladd_ew_x_i8_rne_1x2_f64_rno (old, b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i8_rdn (carrier_u8 c)
{
  __riscv_ztt_bf16_rmm_2x1_t b = __riscv_ztt_mzero_m_bf16_rmm_2x1 ();
  __riscv_ztt_i8_rdn_2x1_t old = __riscv_ztt_mzero_m_i8_rdn_2x1 ();
  __riscv_ztt_i8_rdn_2x1_t d = __riscv_ztt_mmuladd_ew_x_i8_rdn_2x1_u8_rdn_sat (old, b, __riscv_ztt_scalar_make_u8_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i8_rod (float c)
{
  __riscv_ztt_i8_rod_1x1_t b = __riscv_ztt_mzero_m_i8_rod_1x1 ();
  __riscv_ztt_i8_rod_1x1_t old = __riscv_ztt_mzero_m_i8_rod_1x1 ();
  __riscv_ztt_i8_rod_1x1_t d = __riscv_ztt_mmuladd_ew_x_i8_rod_1x1_f32_rtz (old, b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u8_rnu (carrier_u32 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t old = __riscv_ztt_mzero_m_u8_rnu_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t d = __riscv_ztt_mmuladd_ew_x_u8_rnu_1x1_u32_rnu_sat (old, b, __riscv_ztt_scalar_make_u32_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u8_rne (_Float16 c)
{
  __riscv_ztt_u8_rne_1x4_t b = __riscv_ztt_mzero_m_u8_rne_1x4 ();
  __riscv_ztt_u8_rne_1x4_t old = __riscv_ztt_mzero_m_u8_rne_1x4 ();
  __riscv_ztt_u8_rne_1x4_t d = __riscv_ztt_mmuladd_ew_x_u8_rne_1x4_f16_rup (old, b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u8_rdn (carrier_i128 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t old = __riscv_ztt_mzero_m_u8_rdn_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t d = __riscv_ztt_mmuladd_ew_x_u8_rdn_1x1_i128_rdn_sat (old, b, __riscv_ztt_scalar_from_bits_i128_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u8_rod (float c)
{
  __riscv_ztt_u8_rod_1x2_t b = __riscv_ztt_mzero_m_u8_rod_1x2 ();
  __riscv_ztt_u8_rod_1x2_t old = __riscv_ztt_mzero_m_u8_rod_1x2 ();
  __riscv_ztt_u8_rod_1x2_t d = __riscv_ztt_mmuladd_ew_x_u8_rod_1x2_f32_rno (old, b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i16_rnu (__bf16 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t old = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t d = __riscv_ztt_mmuladd_ew_x_i16_rnu_1x1_bf16_rdn (old, b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i16_rne (__bf16 c)
{
  __riscv_ztt_i16_rne_1x1_t b = __riscv_ztt_mzero_m_i16_rne_1x1 ();
  __riscv_ztt_i16_rne_1x1_t old = __riscv_ztt_mzero_m_i16_rne_1x1 ();
  __riscv_ztt_i16_rne_1x1_t d = __riscv_ztt_mmuladd_ew_x_i16_rne_1x1_bf16_rtz (old, b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i16_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i16_rdn_2x1_t old = __riscv_ztt_mzero_m_i16_rdn_2x1 ();
  __riscv_ztt_i16_rdn_2x1_t d = __riscv_ztt_mmuladd_ew_x_i16_rdn_2x1_f64_rmm (old, b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i16_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rod_1x2_t b = __riscv_ztt_mzero_m_i16_rod_1x2 ();
  __riscv_ztt_i16_rod_1x2_t old = __riscv_ztt_mzero_m_i16_rod_1x2 ();
  __riscv_ztt_i16_rod_1x2_t d = __riscv_ztt_mmuladd_ew_x_i16_rod_1x2_f64_rup (old, b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u16_rnu (carrier_u16 c)
{
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_u16_rnu_1x1_t old = __riscv_ztt_mzero_m_u16_rnu_1x1 ();
  __riscv_ztt_u16_rnu_1x1_t d = __riscv_ztt_mmuladd_ew_x_u16_rnu_1x1_u16_rnu (old, b, __riscv_ztt_scalar_make_u16_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u16_rne (__bf16 c)
{
  __riscv_ztt_u16_rne_1x2_t b = __riscv_ztt_mzero_m_u16_rne_1x2 ();
  __riscv_ztt_u16_rne_1x2_t old = __riscv_ztt_mzero_m_u16_rne_1x2 ();
  __riscv_ztt_u16_rne_1x2_t d = __riscv_ztt_mmuladd_ew_x_u16_rne_1x2_bf16_rno (old, b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u16_rdn (carrier_i64 c)
{
  __riscv_ztt_f16_rmm_2x1_t b = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_u16_rdn_2x1_t old = __riscv_ztt_mzero_m_u16_rdn_2x1 ();
  __riscv_ztt_u16_rdn_2x1_t d = __riscv_ztt_mmuladd_ew_x_u16_rdn_2x1_i64_rdn (old, b, __riscv_ztt_scalar_from_bits_i64_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u16_rod (_Float16 c)
{
  __riscv_ztt_u16_rod_1x1_t b = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_u16_rod_1x1_t old = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_u16_rod_1x1_t d = __riscv_ztt_mmuladd_ew_x_u16_rod_1x1_f16_rtz (old, b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i32_rnu (carrier_i8 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t old = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mmuladd_ew_x_i32_rnu_1x1_i8_rnu_sat (old, b, __riscv_ztt_scalar_make_i8_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i32_rne (float c)
{
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t old = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_mmuladd_ew_x_i32_rne_1x1_f32_rup (old, b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i32_rdn (carrier_u16 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t old = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_mmuladd_ew_x_i32_rdn_1x1_u16_rdn_sat (old, b, __riscv_ztt_scalar_make_u16_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i32_rod (_Float16 c)
{
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t old = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mmuladd_ew_x_i32_rod_1x1_f16_rno (old, b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u32_rnu (carrier_u64 c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t old = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mmuladd_ew_x_u32_rnu_1x1_u64_rnu_sat (old, b, __riscv_ztt_scalar_from_bits_u64_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u32_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t old = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_mmuladd_ew_x_u32_rne_1x1_f64_rtz (old, b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u32_rdn (_Float16 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t old = __riscv_ztt_mzero_m_u32_rdn_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mmuladd_ew_x_u32_rdn_1x1_f16_rdn (old, b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u32_rod (__bf16 c)
{
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t old = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_mmuladd_ew_x_u32_rod_1x1_bf16_rup (old, b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i4_rnu_sat (float c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i4_rnu_sat_2x1_t old = __riscv_ztt_mzero_m_i4_rnu_sat_2x1 ();
  __riscv_ztt_i4_rnu_sat_2x1_t d = __riscv_ztt_mmuladd_ew_x_i4_rnu_sat_2x1_f32_rmm (old, b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i4_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rne_sat_1x4_t b = __riscv_ztt_mzero_m_i4_rne_sat_1x4 ();
  __riscv_ztt_i4_rne_sat_1x4_t old = __riscv_ztt_mzero_m_i4_rne_sat_1x4 ();
  __riscv_ztt_i4_rne_sat_1x4_t d = __riscv_ztt_mmuladd_ew_x_i4_rne_sat_1x4_f64_rno (old, b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i4_rdn_sat (carrier_u8 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i4_rdn_sat_2x1_t old = __riscv_ztt_mzero_m_i4_rdn_sat_2x1 ();
  __riscv_ztt_i4_rdn_sat_2x1_t d = __riscv_ztt_mmuladd_ew_x_i4_rdn_sat_2x1_u8_rdn (old, b, __riscv_ztt_scalar_make_u8_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i4_rod_sat (float c)
{
  __riscv_ztt_i4_rod_sat_1x2_t b = __riscv_ztt_mzero_m_i4_rod_sat_1x2 ();
  __riscv_ztt_i4_rod_sat_1x2_t old = __riscv_ztt_mzero_m_i4_rod_sat_1x2 ();
  __riscv_ztt_i4_rod_sat_1x2_t d = __riscv_ztt_mmuladd_ew_x_i4_rod_sat_1x2_f32_rtz (old, b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u4_rnu_sat (carrier_u32 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_u4_rnu_sat_2x1_t old = __riscv_ztt_mzero_m_u4_rnu_sat_2x1 ();
  __riscv_ztt_u4_rnu_sat_2x1_t d = __riscv_ztt_mmuladd_ew_x_u4_rnu_sat_2x1_u32_rnu (old, b, __riscv_ztt_scalar_make_u32_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u4_rne_sat (_Float16 c)
{
  __riscv_ztt_u4_rne_sat_1x8_t b = __riscv_ztt_mzero_m_u4_rne_sat_1x8 ();
  __riscv_ztt_u4_rne_sat_1x8_t old = __riscv_ztt_mzero_m_u4_rne_sat_1x8 ();
  __riscv_ztt_u4_rne_sat_1x8_t d = __riscv_ztt_mmuladd_ew_x_u4_rne_sat_1x8_f16_rup (old, b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u4_rdn_sat (carrier_i128 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_u4_rdn_sat_2x1_t old = __riscv_ztt_mzero_m_u4_rdn_sat_2x1 ();
  __riscv_ztt_u4_rdn_sat_2x1_t d = __riscv_ztt_mmuladd_ew_x_u4_rdn_sat_2x1_i128_rdn (old, b, __riscv_ztt_scalar_from_bits_i128_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u4_rod_sat (float c)
{
  __riscv_ztt_u4_rod_sat_1x4_t b = __riscv_ztt_mzero_m_u4_rod_sat_1x4 ();
  __riscv_ztt_u4_rod_sat_1x4_t old = __riscv_ztt_mzero_m_u4_rod_sat_1x4 ();
  __riscv_ztt_u4_rod_sat_1x4_t d = __riscv_ztt_mmuladd_ew_x_u4_rod_sat_1x4_f32_rno (old, b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i8_rnu_sat (carrier_i16 c)
{
  __riscv_ztt_f16_rmm_2x1_t b = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_i8_rnu_sat_2x1_t old = __riscv_ztt_mzero_m_i8_rnu_sat_2x1 ();
  __riscv_ztt_i8_rnu_sat_2x1_t d = __riscv_ztt_mmuladd_ew_x_i8_rnu_sat_2x1_i16_rnu_sat (old, b, __riscv_ztt_scalar_make_i16_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i8_rne_sat (__bf16 c)
{
  __riscv_ztt_i8_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rne_sat_1x1 ();
  __riscv_ztt_i8_rne_sat_1x1_t old = __riscv_ztt_mzero_m_i8_rne_sat_1x1 ();
  __riscv_ztt_i8_rne_sat_1x1_t d = __riscv_ztt_mmuladd_ew_x_i8_rne_sat_1x1_bf16_rtz (old, b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i8_rdn_sat (carrier_u32 c)
{
  __riscv_ztt_bf16_rne_2x1_t b = __riscv_ztt_mzero_m_bf16_rne_2x1 ();
  __riscv_ztt_i8_rdn_sat_2x1_t old = __riscv_ztt_mzero_m_i8_rdn_sat_2x1 ();
  __riscv_ztt_i8_rdn_sat_2x1_t d = __riscv_ztt_mmuladd_ew_x_i8_rdn_sat_2x1_u32_rdn_sat (old, b, __riscv_ztt_scalar_make_u32_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i8_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rod_sat_1x4_t b = __riscv_ztt_mzero_m_i8_rod_sat_1x4 ();
  __riscv_ztt_i8_rod_sat_1x4_t old = __riscv_ztt_mzero_m_i8_rod_sat_1x4 ();
  __riscv_ztt_i8_rod_sat_1x4_t d = __riscv_ztt_mmuladd_ew_x_i8_rod_sat_1x4_f64_rup (old, b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u8_rnu_sat (carrier_u128 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_u8_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_u8_rnu_sat_1x1 ();
  __riscv_ztt_u8_rnu_sat_1x1_t d = __riscv_ztt_mmuladd_ew_x_u8_rnu_sat_1x1_u128_rnu_sat (old, b, __riscv_ztt_scalar_from_bits_u128_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u8_rne_sat (__bf16 c)
{
  __riscv_ztt_u8_rne_sat_1x2_t b = __riscv_ztt_mzero_m_u8_rne_sat_1x2 ();
  __riscv_ztt_u8_rne_sat_1x2_t old = __riscv_ztt_mzero_m_u8_rne_sat_1x2 ();
  __riscv_ztt_u8_rne_sat_1x2_t d = __riscv_ztt_mmuladd_ew_x_u8_rne_sat_1x2_bf16_rno (old, b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u8_rdn_sat (__bf16 c)
{
  __riscv_ztt_bf16_rmm_2x1_t b = __riscv_ztt_mzero_m_bf16_rmm_2x1 ();
  __riscv_ztt_u8_rdn_sat_2x1_t old = __riscv_ztt_mzero_m_u8_rdn_sat_2x1 ();
  __riscv_ztt_u8_rdn_sat_2x1_t d = __riscv_ztt_mmuladd_ew_x_u8_rdn_sat_2x1_bf16_rmm (old, b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u8_rod_sat (_Float16 c)
{
  __riscv_ztt_u8_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rod_sat_1x1 ();
  __riscv_ztt_u8_rod_sat_1x1_t old = __riscv_ztt_mzero_m_u8_rod_sat_1x1 ();
  __riscv_ztt_u8_rod_sat_1x1_t d = __riscv_ztt_mmuladd_ew_x_u8_rod_sat_1x1_f16_rtz (old, b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i16_rnu_sat (carrier_i8 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_i16_rnu_sat_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t d = __riscv_ztt_mmuladd_ew_x_i16_rnu_sat_1x1_i8_rnu (old, b, __riscv_ztt_scalar_make_i8_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i16_rne_sat (float c)
{
  __riscv_ztt_i16_rne_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rne_sat_1x2 ();
  __riscv_ztt_i16_rne_sat_1x2_t old = __riscv_ztt_mzero_m_i16_rne_sat_1x2 ();
  __riscv_ztt_i16_rne_sat_1x2_t d = __riscv_ztt_mmuladd_ew_x_i16_rne_sat_1x2_f32_rup (old, b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i16_rdn_sat (carrier_u16 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t old = __riscv_ztt_mzero_m_i16_rdn_sat_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t d = __riscv_ztt_mmuladd_ew_x_i16_rdn_sat_1x1_u16_rdn (old, b, __riscv_ztt_scalar_make_u16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i16_rod_sat (_Float16 c)
{
  __riscv_ztt_i16_rod_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rod_sat_1x2 ();
  __riscv_ztt_i16_rod_sat_1x2_t old = __riscv_ztt_mzero_m_i16_rod_sat_1x2 ();
  __riscv_ztt_i16_rod_sat_1x2_t d = __riscv_ztt_mmuladd_ew_x_i16_rod_sat_1x2_f16_rno (old, b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u16_rnu_sat (carrier_u64 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_u16_rnu_sat_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t d = __riscv_ztt_mmuladd_ew_x_u16_rnu_sat_1x1_u64_rnu (old, b, __riscv_ztt_scalar_from_bits_u64_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u16_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rne_sat_1x1 ();
  __riscv_ztt_u16_rne_sat_1x1_t old = __riscv_ztt_mzero_m_u16_rne_sat_1x1 ();
  __riscv_ztt_u16_rne_sat_1x1_t d = __riscv_ztt_mmuladd_ew_x_u16_rne_sat_1x1_f64_rtz (old, b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u16_rdn_sat (carrier_i8 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_u16_rdn_sat_2x1_t old = __riscv_ztt_mzero_m_u16_rdn_sat_2x1 ();
  __riscv_ztt_u16_rdn_sat_2x1_t d = __riscv_ztt_mmuladd_ew_x_u16_rdn_sat_2x1_i8_rdn_sat (old, b, __riscv_ztt_scalar_make_i8_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u16_rod_sat (__bf16 c)
{
  __riscv_ztt_u16_rod_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rod_sat_1x2 ();
  __riscv_ztt_u16_rod_sat_1x2_t old = __riscv_ztt_mzero_m_u16_rod_sat_1x2 ();
  __riscv_ztt_u16_rod_sat_1x2_t d = __riscv_ztt_mmuladd_ew_x_u16_rod_sat_1x2_bf16_rup (old, b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i32_rnu_sat (carrier_i32 c)
{
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rnu_sat_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_mmuladd_ew_x_i32_rnu_sat_1x1_i32_rnu_sat (old, b, __riscv_ztt_scalar_make_i32_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i32_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_mmuladd_ew_x_i32_rne_sat_1x1_f64_rno (old, b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i32_rdn_sat (carrier_u64 c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rdn_sat_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mmuladd_ew_x_i32_rdn_sat_1x1_u64_rdn_sat (old, b, __riscv_ztt_scalar_from_bits_u64_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_i32_rod_sat (float c)
{
  __riscv_ztt_i32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_mmuladd_ew_x_i32_rod_sat_1x1_f32_rtz (old, b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u32_rnu_sat (_Float16 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rnu_sat_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_mmuladd_ew_x_u32_rnu_sat_1x1_f16_rmm (old, b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u32_rne_sat (_Float16 c)
{
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mmuladd_ew_x_u32_rne_sat_1x1_f16_rup (old, b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u32_rdn_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rdn_sat_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_mmuladd_ew_x_u32_rdn_sat_1x1_f64_rne (old, b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_u32_rod_sat (float c)
{
  __riscv_ztt_u32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_mmuladd_ew_x_u32_rod_sat_1x1_f32_rno (old, b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_f16_rne (carrier_i16 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_f16_rne_2x1_t old = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_f16_rne_2x1_t d = __riscv_ztt_mmuladd_ew_x_f16_rne_2x1_i16_rnu (old, b, __riscv_ztt_scalar_make_i16_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_f16_rtz (carrier_u16 c)
{
  __riscv_ztt_f16_rtz_1x1_t b = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t old = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_mmuladd_ew_x_f16_rtz_1x1_u16_rod (old, b, __riscv_ztt_scalar_make_u16_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_f16_rdn (carrier_u32 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_f16_rdn_2x1_t old = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_f16_rdn_2x1_t d = __riscv_ztt_mmuladd_ew_x_f16_rdn_2x1_u32_rdn (old, b, __riscv_ztt_scalar_make_u32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_f16_rup (carrier_u64 c)
{
  __riscv_ztt_f16_rup_1x2_t b = __riscv_ztt_mzero_m_f16_rup_1x2 ();
  __riscv_ztt_f16_rup_1x2_t old = __riscv_ztt_mzero_m_f16_rup_1x2 ();
  __riscv_ztt_f16_rup_1x2_t d = __riscv_ztt_mmuladd_ew_x_f16_rup_1x2_u64_rne (old, b, __riscv_ztt_scalar_from_bits_u64_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_f16_rmm (carrier_u128 c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t old = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mmuladd_ew_x_f16_rmm_1x1_u128_rnu (old, b, __riscv_ztt_scalar_from_bits_u128_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_f16_rno (carrier_i8 c)
{
  __riscv_ztt_f16_rno_1x2_t b = __riscv_ztt_mzero_m_f16_rno_1x2 ();
  __riscv_ztt_f16_rno_1x2_t old = __riscv_ztt_mzero_m_f16_rno_1x2 ();
  __riscv_ztt_f16_rno_1x2_t d = __riscv_ztt_mmuladd_ew_x_f16_rno_1x2_i8_rod_sat (old, b, __riscv_ztt_scalar_make_i8_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_bf16_rne (carrier_i16 c)
{
  __riscv_ztt_bf16_rne_2x1_t b = __riscv_ztt_mzero_m_bf16_rne_2x1 ();
  __riscv_ztt_bf16_rne_2x1_t old = __riscv_ztt_mzero_m_bf16_rne_2x1 ();
  __riscv_ztt_bf16_rne_2x1_t d = __riscv_ztt_mmuladd_ew_x_bf16_rne_2x1_i16_rdn_sat (old, b, __riscv_ztt_scalar_make_i16_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_bf16_rtz (carrier_i32 c)
{
  __riscv_ztt_bf16_rtz_1x1_t b = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t old = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t d = __riscv_ztt_mmuladd_ew_x_bf16_rtz_1x1_i32_rne_sat (old, b, __riscv_ztt_scalar_make_i32_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_bf16_rdn (carrier_i64 c)
{
  __riscv_ztt_bf16_rdn_2x1_t b = __riscv_ztt_mzero_m_bf16_rdn_2x1 ();
  __riscv_ztt_bf16_rdn_2x1_t old = __riscv_ztt_mzero_m_bf16_rdn_2x1 ();
  __riscv_ztt_bf16_rdn_2x1_t d = __riscv_ztt_mmuladd_ew_x_bf16_rdn_2x1_i64_rnu_sat (old, b, __riscv_ztt_scalar_from_bits_i64_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_bf16_rup (carrier_u64 c)
{
  __riscv_ztt_bf16_rup_1x2_t b = __riscv_ztt_mzero_m_bf16_rup_1x2 ();
  __riscv_ztt_bf16_rup_1x2_t old = __riscv_ztt_mzero_m_bf16_rup_1x2 ();
  __riscv_ztt_bf16_rup_1x2_t d = __riscv_ztt_mmuladd_ew_x_bf16_rup_1x2_u64_rod_sat (old, b, __riscv_ztt_scalar_from_bits_u64_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_bf16_rmm (carrier_u128 c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_bf16_rmm_1x1_t old = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_bf16_rmm_1x1_t d = __riscv_ztt_mmuladd_ew_x_bf16_rmm_1x1_u128_rdn_sat (old, b, __riscv_ztt_scalar_from_bits_u128_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_bf16_rno (_Float16 c)
{
  __riscv_ztt_bf16_rno_1x2_t b = __riscv_ztt_mzero_m_bf16_rno_1x2 ();
  __riscv_ztt_bf16_rno_1x2_t old = __riscv_ztt_mzero_m_bf16_rno_1x2 ();
  __riscv_ztt_bf16_rno_1x2_t d = __riscv_ztt_mmuladd_ew_x_bf16_rno_1x2_f16_rno (old, b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_f32_rne (float c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t old = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mmuladd_ew_x_f32_rne_1x1_f32_rne (old, b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_f32_rtz (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t old = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mmuladd_ew_x_f32_rtz_1x1_f64_rtz (old, b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_f32_rdn (carrier_i8 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t old = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mmuladd_ew_x_f32_rdn_1x1_i8_rdn (old, b, __riscv_ztt_scalar_make_i8_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_f32_rup (carrier_i16 c)
{
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t old = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mmuladd_ew_x_f32_rup_1x1_i16_rne (old, b, __riscv_ztt_scalar_make_i16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_f32_rmm (carrier_i32 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t old = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mmuladd_ew_x_f32_rmm_1x1_i32_rnu (old, b, __riscv_ztt_scalar_make_i32_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmuladd_f32_rno (carrier_u32 c)
{
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t old = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mmuladd_ew_x_f32_rno_1x1_u32_rod (old, b, __riscv_ztt_scalar_make_u32_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i4_rnu (_Float16 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i4_rnu_1x2_t old = __riscv_ztt_mzero_m_i4_rnu_1x2 ();
  __riscv_ztt_i4_rnu_1x2_t d = __riscv_ztt_mmulsub_ew_x_i4_rnu_1x2_f16_rno (old, b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i4_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rne_2x1_t b = __riscv_ztt_mzero_m_i4_rne_2x1 ();
  __riscv_ztt_i4_rne_2x1_t old = __riscv_ztt_mzero_m_i4_rne_2x1 ();
  __riscv_ztt_i4_rne_2x1_t d = __riscv_ztt_mmulsub_ew_x_i4_rne_2x1_f64_rdn (old, b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i4_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_i4_rdn_1x2_t old = __riscv_ztt_mzero_m_i4_rdn_1x2 ();
  __riscv_ztt_i4_rdn_1x2_t d = __riscv_ztt_mmulsub_ew_x_i4_rdn_1x2_f64_rtz (old, b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i4_rod (__bf16 c)
{
  __riscv_ztt_i4_rod_8x1_t b = __riscv_ztt_mzero_m_i4_rod_8x1 ();
  __riscv_ztt_i4_rod_8x1_t old = __riscv_ztt_mzero_m_i4_rod_8x1 ();
  __riscv_ztt_i4_rod_8x1_t d = __riscv_ztt_mmulsub_ew_x_i4_rod_8x1_bf16_rmm (old, b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u4_rnu (carrier_i16 c)
{
  __riscv_ztt_f16_rmm_1x2_t b = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_u4_rnu_1x2_t old = __riscv_ztt_mzero_m_u4_rnu_1x2 ();
  __riscv_ztt_u4_rnu_1x2_t d = __riscv_ztt_mmulsub_ew_x_u4_rnu_1x2_i16_rne (old, b, __riscv_ztt_scalar_make_i16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u4_rne (_Float16 c)
{
  __riscv_ztt_u4_rne_4x1_t b = __riscv_ztt_mzero_m_u4_rne_4x1 ();
  __riscv_ztt_u4_rne_4x1_t old = __riscv_ztt_mzero_m_u4_rne_4x1 ();
  __riscv_ztt_u4_rne_4x1_t d = __riscv_ztt_mmulsub_ew_x_u4_rne_4x1_f16_rne (old, b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u4_rdn (carrier_u32 c)
{
  __riscv_ztt_bf16_rne_1x2_t b = __riscv_ztt_mzero_m_bf16_rne_1x2 ();
  __riscv_ztt_u4_rdn_1x2_t old = __riscv_ztt_mzero_m_u4_rdn_1x2 ();
  __riscv_ztt_u4_rdn_1x2_t d = __riscv_ztt_mmulsub_ew_x_u4_rdn_1x2_u32_rod (old, b, __riscv_ztt_scalar_make_u32_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u4_rod (float c)
{
  __riscv_ztt_u4_rod_2x1_t b = __riscv_ztt_mzero_m_u4_rod_2x1 ();
  __riscv_ztt_u4_rod_2x1_t old = __riscv_ztt_mzero_m_u4_rod_2x1 ();
  __riscv_ztt_u4_rod_2x1_t d = __riscv_ztt_mmulsub_ew_x_u4_rod_2x1_f32_rdn (old, b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i8_rnu (carrier_u128 c)
{
  __riscv_ztt_bf16_rdn_1x2_t b = __riscv_ztt_mzero_m_bf16_rdn_1x2 ();
  __riscv_ztt_i8_rnu_1x2_t old = __riscv_ztt_mzero_m_i8_rnu_1x2 ();
  __riscv_ztt_i8_rnu_1x2_t d = __riscv_ztt_mmulsub_ew_x_i8_rnu_1x2_u128_rne (old, b, __riscv_ztt_scalar_from_bits_u128_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i8_rne (_Float16 c)
{
  __riscv_ztt_i8_rne_4x1_t b = __riscv_ztt_mzero_m_i8_rne_4x1 ();
  __riscv_ztt_i8_rne_4x1_t old = __riscv_ztt_mzero_m_i8_rne_4x1 ();
  __riscv_ztt_i8_rne_4x1_t d = __riscv_ztt_mmulsub_ew_x_i8_rne_4x1_f16_rmm (old, b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i8_rdn (carrier_i16 c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_i8_rdn_1x1_t old = __riscv_ztt_mzero_m_i8_rdn_1x1 ();
  __riscv_ztt_i8_rdn_1x1_t d = __riscv_ztt_mmulsub_ew_x_i8_rdn_1x1_i16_rod_sat (old, b, __riscv_ztt_scalar_make_i16_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i8_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rod_2x1_t b = __riscv_ztt_mzero_m_i8_rod_2x1 ();
  __riscv_ztt_i8_rod_2x1_t old = __riscv_ztt_mzero_m_i8_rod_2x1 ();
  __riscv_ztt_i8_rod_2x1_t d = __riscv_ztt_mmulsub_ew_x_i8_rod_2x1_f64_rne (old, b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u8_rnu (carrier_i64 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t old = __riscv_ztt_mzero_m_u8_rnu_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t d = __riscv_ztt_mmulsub_ew_x_u8_rnu_1x1_i64_rne_sat (old, b, __riscv_ztt_scalar_from_bits_i64_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u8_rne (__bf16 c)
{
  __riscv_ztt_u8_rne_1x1_t b = __riscv_ztt_mzero_m_u8_rne_1x1 ();
  __riscv_ztt_u8_rne_1x1_t old = __riscv_ztt_mzero_m_u8_rne_1x1 ();
  __riscv_ztt_u8_rne_1x1_t d = __riscv_ztt_mmulsub_ew_x_u8_rne_1x1_bf16_rdn (old, b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u8_rdn (carrier_u128 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t old = __riscv_ztt_mzero_m_u8_rdn_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t d = __riscv_ztt_mmulsub_ew_x_u8_rdn_1x1_u128_rod_sat (old, b, __riscv_ztt_scalar_from_bits_u128_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u8_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rod_4x1_t b = __riscv_ztt_mzero_m_u8_rod_4x1 ();
  __riscv_ztt_u8_rod_4x1_t old = __riscv_ztt_mzero_m_u8_rod_4x1 ();
  __riscv_ztt_u8_rod_4x1_t d = __riscv_ztt_mmulsub_ew_x_u8_rod_4x1_f64_rmm (old, b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i16_rnu (float c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t old = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t d = __riscv_ztt_mmulsub_ew_x_i16_rnu_1x1_f32_rtz (old, b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i16_rne (float c)
{
  __riscv_ztt_i16_rne_2x1_t b = __riscv_ztt_mzero_m_i16_rne_2x1 ();
  __riscv_ztt_i16_rne_2x1_t old = __riscv_ztt_mzero_m_i16_rne_2x1 ();
  __riscv_ztt_i16_rne_2x1_t d = __riscv_ztt_mmulsub_ew_x_i16_rne_2x1_f32_rne (old, b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i16_rdn (carrier_i8 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i16_rdn_1x2_t old = __riscv_ztt_mzero_m_i16_rdn_1x2 ();
  __riscv_ztt_i16_rdn_1x2_t d = __riscv_ztt_mmulsub_ew_x_i16_rdn_1x2_i8_rod (old, b, __riscv_ztt_scalar_make_i8_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i16_rod (_Float16 c)
{
  __riscv_ztt_i16_rod_1x1_t b = __riscv_ztt_mzero_m_i16_rod_1x1 ();
  __riscv_ztt_i16_rod_1x1_t old = __riscv_ztt_mzero_m_i16_rod_1x1 ();
  __riscv_ztt_i16_rod_1x1_t d = __riscv_ztt_mmulsub_ew_x_i16_rod_1x1_f16_rdn (old, b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u16_rnu (carrier_i32 c)
{
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_u16_rnu_1x2_t old = __riscv_ztt_mzero_m_u16_rnu_1x2 ();
  __riscv_ztt_u16_rnu_1x2_t d = __riscv_ztt_mmulsub_ew_x_u16_rnu_1x2_i32_rne (old, b, __riscv_ztt_scalar_make_i32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u16_rne (float c)
{
  __riscv_ztt_u16_rne_2x1_t b = __riscv_ztt_mzero_m_u16_rne_2x1 ();
  __riscv_ztt_u16_rne_2x1_t old = __riscv_ztt_mzero_m_u16_rne_2x1 ();
  __riscv_ztt_u16_rne_2x1_t d = __riscv_ztt_mmulsub_ew_x_u16_rne_2x1_f32_rmm (old, b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u16_rdn (carrier_u64 c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_u16_rdn_1x1_t old = __riscv_ztt_mzero_m_u16_rdn_1x1 ();
  __riscv_ztt_u16_rdn_1x1_t d = __riscv_ztt_mmulsub_ew_x_u16_rdn_1x1_u64_rod (old, b, __riscv_ztt_scalar_from_bits_u64_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u16_rod (__bf16 c)
{
  __riscv_ztt_u16_rod_2x1_t b = __riscv_ztt_mzero_m_u16_rod_2x1 ();
  __riscv_ztt_u16_rod_2x1_t old = __riscv_ztt_mzero_m_u16_rod_2x1 ();
  __riscv_ztt_u16_rod_2x1_t d = __riscv_ztt_mmulsub_ew_x_u16_rod_2x1_bf16_rne (old, b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i32_rnu (carrier_u8 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t old = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mmulsub_ew_x_i32_rnu_1x1_u8_rne_sat (old, b, __riscv_ztt_scalar_make_u8_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i32_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t old = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_mmulsub_ew_x_i32_rne_1x1_f64_rdn (old, b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i32_rdn (carrier_i32 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t old = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_mmulsub_ew_x_i32_rdn_1x1_i32_rod_sat (old, b, __riscv_ztt_scalar_make_i32_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i32_rod (__bf16 c)
{
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t old = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mmulsub_ew_x_i32_rod_1x1_bf16_rmm (old, b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u32_rnu (carrier_i128 c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t old = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mmulsub_ew_x_u32_rnu_1x1_i128_rne_sat (old, b, __riscv_ztt_scalar_from_bits_i128_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u32_rne (_Float16 c)
{
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t old = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_mmulsub_ew_x_u32_rne_1x1_f16_rne (old, b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u32_rdn (__bf16 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t old = __riscv_ztt_mzero_m_u32_rdn_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mmulsub_ew_x_u32_rdn_1x1_bf16_rtz (old, b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u32_rod (float c)
{
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t old = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_mmulsub_ew_x_u32_rod_1x1_f32_rdn (old, b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i4_rnu_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i4_rnu_sat_1x2_t old = __riscv_ztt_mzero_m_i4_rnu_sat_1x2 ();
  __riscv_ztt_i4_rnu_sat_1x2_t d = __riscv_ztt_mmulsub_ew_x_i4_rnu_sat_1x2_f64_rup (old, b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i4_rne_sat (_Float16 c)
{
  __riscv_ztt_i4_rne_sat_8x1_t b = __riscv_ztt_mzero_m_i4_rne_sat_8x1 ();
  __riscv_ztt_i4_rne_sat_8x1_t old = __riscv_ztt_mzero_m_i4_rne_sat_8x1 ();
  __riscv_ztt_i4_rne_sat_8x1_t d = __riscv_ztt_mmulsub_ew_x_i4_rne_sat_8x1_f16_rmm (old, b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i4_rdn_sat (carrier_i16 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i4_rdn_sat_1x2_t old = __riscv_ztt_mzero_m_i4_rdn_sat_1x2 ();
  __riscv_ztt_i4_rdn_sat_1x2_t d = __riscv_ztt_mmulsub_ew_x_i4_rdn_sat_1x2_i16_rod (old, b, __riscv_ztt_scalar_make_i16_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i4_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rod_sat_4x1_t b = __riscv_ztt_mzero_m_i4_rod_sat_4x1 ();
  __riscv_ztt_i4_rod_sat_4x1_t old = __riscv_ztt_mzero_m_i4_rod_sat_4x1 ();
  __riscv_ztt_i4_rod_sat_4x1_t d = __riscv_ztt_mmulsub_ew_x_i4_rod_sat_4x1_f64_rne (old, b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u4_rnu_sat (carrier_i64 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_u4_rnu_sat_1x2_t old = __riscv_ztt_mzero_m_u4_rnu_sat_1x2 ();
  __riscv_ztt_u4_rnu_sat_1x2_t d = __riscv_ztt_mmulsub_ew_x_u4_rnu_sat_1x2_i64_rne (old, b, __riscv_ztt_scalar_from_bits_i64_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u4_rne_sat (__bf16 c)
{
  __riscv_ztt_u4_rne_sat_2x1_t b = __riscv_ztt_mzero_m_u4_rne_sat_2x1 ();
  __riscv_ztt_u4_rne_sat_2x1_t old = __riscv_ztt_mzero_m_u4_rne_sat_2x1 ();
  __riscv_ztt_u4_rne_sat_2x1_t d = __riscv_ztt_mmulsub_ew_x_u4_rne_sat_2x1_bf16_rdn (old, b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u4_rdn_sat (carrier_u128 c)
{
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_u4_rdn_sat_1x2_t old = __riscv_ztt_mzero_m_u4_rdn_sat_1x2 ();
  __riscv_ztt_u4_rdn_sat_1x2_t d = __riscv_ztt_mmulsub_ew_x_u4_rdn_sat_1x2_u128_rod (old, b, __riscv_ztt_scalar_from_bits_u128_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u4_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rod_sat_8x1_t b = __riscv_ztt_mzero_m_u4_rod_sat_8x1 ();
  __riscv_ztt_u4_rod_sat_8x1_t old = __riscv_ztt_mzero_m_u4_rod_sat_8x1 ();
  __riscv_ztt_u4_rod_sat_8x1_t d = __riscv_ztt_mmulsub_ew_x_u4_rod_sat_8x1_f64_rmm (old, b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i8_rnu_sat (carrier_u16 c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t d = __riscv_ztt_mmulsub_ew_x_i8_rnu_sat_1x1_u16_rne_sat (old, b, __riscv_ztt_scalar_make_u16_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i8_rne_sat (float c)
{
  __riscv_ztt_i8_rne_sat_2x1_t b = __riscv_ztt_mzero_m_i8_rne_sat_2x1 ();
  __riscv_ztt_i8_rne_sat_2x1_t old = __riscv_ztt_mzero_m_i8_rne_sat_2x1 ();
  __riscv_ztt_i8_rne_sat_2x1_t d = __riscv_ztt_mmulsub_ew_x_i8_rne_sat_2x1_f32_rne (old, b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i8_rdn_sat (carrier_i64 c)
{
  __riscv_ztt_bf16_rne_1x2_t b = __riscv_ztt_mzero_m_bf16_rne_1x2 ();
  __riscv_ztt_i8_rdn_sat_1x2_t old = __riscv_ztt_mzero_m_i8_rdn_sat_1x2 ();
  __riscv_ztt_i8_rdn_sat_1x2_t d = __riscv_ztt_mmulsub_ew_x_i8_rdn_sat_1x2_i64_rod_sat (old, b, __riscv_ztt_scalar_from_bits_i64_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i8_rod_sat (_Float16 c)
{
  __riscv_ztt_i8_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rod_sat_1x1 ();
  __riscv_ztt_i8_rod_sat_1x1_t old = __riscv_ztt_mzero_m_i8_rod_sat_1x1 ();
  __riscv_ztt_i8_rod_sat_1x1_t d = __riscv_ztt_mmulsub_ew_x_i8_rod_sat_1x1_f16_rdn (old, b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u8_rnu_sat (_Float16 c)
{
  __riscv_ztt_bf16_rdn_1x2_t b = __riscv_ztt_mzero_m_bf16_rdn_1x2 ();
  __riscv_ztt_u8_rnu_sat_1x2_t old = __riscv_ztt_mzero_m_u8_rnu_sat_1x2 ();
  __riscv_ztt_u8_rnu_sat_1x2_t d = __riscv_ztt_mmulsub_ew_x_u8_rnu_sat_1x2_f16_rtz (old, b, __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u8_rne_sat (float c)
{
  __riscv_ztt_u8_rne_sat_4x1_t b = __riscv_ztt_mzero_m_u8_rne_sat_4x1 ();
  __riscv_ztt_u8_rne_sat_4x1_t old = __riscv_ztt_mzero_m_u8_rne_sat_4x1 ();
  __riscv_ztt_u8_rne_sat_4x1_t d = __riscv_ztt_mmulsub_ew_x_u8_rne_sat_4x1_f32_rmm (old, b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u8_rdn_sat (float c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_u8_rdn_sat_1x1_t old = __riscv_ztt_mzero_m_u8_rdn_sat_1x1 ();
  __riscv_ztt_u8_rdn_sat_1x1_t d = __riscv_ztt_mmulsub_ew_x_u8_rdn_sat_1x1_f32_rup (old, b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u8_rod_sat (__bf16 c)
{
  __riscv_ztt_u8_rod_sat_2x1_t b = __riscv_ztt_mzero_m_u8_rod_sat_2x1 ();
  __riscv_ztt_u8_rod_sat_2x1_t old = __riscv_ztt_mzero_m_u8_rod_sat_2x1 ();
  __riscv_ztt_u8_rod_sat_2x1_t d = __riscv_ztt_mmulsub_ew_x_u8_rod_sat_2x1_bf16_rne (old, b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i16_rnu_sat (carrier_u8 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_i16_rnu_sat_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t d = __riscv_ztt_mmulsub_ew_x_i16_rnu_sat_1x1_u8_rne (old, b, __riscv_ztt_scalar_make_u8_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i16_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rne_sat_1x1 ();
  __riscv_ztt_i16_rne_sat_1x1_t old = __riscv_ztt_mzero_m_i16_rne_sat_1x1 ();
  __riscv_ztt_i16_rne_sat_1x1_t d = __riscv_ztt_mmulsub_ew_x_i16_rne_sat_1x1_f64_rdn (old, b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i16_rdn_sat (carrier_i32 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t old = __riscv_ztt_mzero_m_i16_rdn_sat_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t d = __riscv_ztt_mmulsub_ew_x_i16_rdn_sat_1x1_i32_rod (old, b, __riscv_ztt_scalar_make_i32_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i16_rod_sat (__bf16 c)
{
  __riscv_ztt_i16_rod_sat_2x1_t b = __riscv_ztt_mzero_m_i16_rod_sat_2x1 ();
  __riscv_ztt_i16_rod_sat_2x1_t old = __riscv_ztt_mzero_m_i16_rod_sat_2x1 ();
  __riscv_ztt_i16_rod_sat_2x1_t d = __riscv_ztt_mmulsub_ew_x_i16_rod_sat_2x1_bf16_rmm (old, b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u16_rnu_sat (carrier_i128 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_u16_rnu_sat_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t d = __riscv_ztt_mmulsub_ew_x_u16_rnu_sat_1x1_i128_rne (old, b, __riscv_ztt_scalar_from_bits_i128_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u16_rne_sat (_Float16 c)
{
  __riscv_ztt_u16_rne_sat_2x1_t b = __riscv_ztt_mzero_m_u16_rne_sat_2x1 ();
  __riscv_ztt_u16_rne_sat_2x1_t old = __riscv_ztt_mzero_m_u16_rne_sat_2x1 ();
  __riscv_ztt_u16_rne_sat_2x1_t d = __riscv_ztt_mmulsub_ew_x_u16_rne_sat_2x1_f16_rne (old, b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u16_rdn_sat (carrier_u8 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_u16_rdn_sat_1x2_t old = __riscv_ztt_mzero_m_u16_rdn_sat_1x2 ();
  __riscv_ztt_u16_rdn_sat_1x2_t d = __riscv_ztt_mmulsub_ew_x_u16_rdn_sat_1x2_u8_rod_sat (old, b, __riscv_ztt_scalar_make_u8_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u16_rod_sat (float c)
{
  __riscv_ztt_u16_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rod_sat_1x1 ();
  __riscv_ztt_u16_rod_sat_1x1_t old = __riscv_ztt_mzero_m_u16_rod_sat_1x1 ();
  __riscv_ztt_u16_rod_sat_1x1_t d = __riscv_ztt_mmulsub_ew_x_u16_rod_sat_1x1_f32_rdn (old, b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i32_rnu_sat (carrier_u32 c)
{
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rnu_sat_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_mmulsub_ew_x_i32_rnu_sat_1x1_u32_rne_sat (old, b, __riscv_ztt_scalar_make_u32_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i32_rne_sat (_Float16 c)
{
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_mmulsub_ew_x_i32_rne_sat_1x1_f16_rmm (old, b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i32_rdn_sat (carrier_i128 c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rdn_sat_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mmulsub_ew_x_i32_rdn_sat_1x1_i128_rod_sat (old, b, __riscv_ztt_scalar_from_bits_i128_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_i32_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_mmulsub_ew_x_i32_rod_sat_1x1_f64_rne (old, b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u32_rnu_sat (__bf16 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rnu_sat_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_mmulsub_ew_x_u32_rnu_sat_1x1_bf16_rup (old, b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u32_rne_sat (__bf16 c)
{
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mmulsub_ew_x_u32_rne_sat_1x1_bf16_rdn (old, b, __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u32_rdn_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rdn_sat_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_mmulsub_ew_x_u32_rdn_sat_1x1_f64_rno (old, b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_u32_rod_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_mmulsub_ew_x_u32_rod_sat_1x1_f64_rmm (old, b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_f16_rne (carrier_u16 c)
{
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_f16_rne_1x1_t old = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_f16_rne_1x1_t d = __riscv_ztt_mmulsub_ew_x_f16_rne_1x1_u16_rne (old, b, __riscv_ztt_scalar_make_u16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_f16_rtz (carrier_u32 c)
{
  __riscv_ztt_f16_rtz_2x1_t b = __riscv_ztt_mzero_m_f16_rtz_2x1 ();
  __riscv_ztt_f16_rtz_2x1_t old = __riscv_ztt_mzero_m_f16_rtz_2x1 ();
  __riscv_ztt_f16_rtz_2x1_t d = __riscv_ztt_mmulsub_ew_x_f16_rtz_2x1_u32_rnu (old, b, __riscv_ztt_scalar_make_u32_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_f16_rdn (carrier_i64 c)
{
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_f16_rdn_1x2_t old = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_f16_rdn_1x2_t d = __riscv_ztt_mmulsub_ew_x_f16_rdn_1x2_i64_rod (old, b, __riscv_ztt_scalar_from_bits_i64_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_f16_rup (carrier_i128 c)
{
  __riscv_ztt_f16_rup_1x1_t b = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_f16_rup_1x1_t old = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_f16_rup_1x1_t d = __riscv_ztt_mmulsub_ew_x_f16_rup_1x1_i128_rdn (old, b, __riscv_ztt_scalar_from_bits_i128_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_f16_rmm (carrier_i8 c)
{
  __riscv_ztt_f16_rmm_1x2_t b = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_f16_rmm_1x2_t old = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_f16_rmm_1x2_t d = __riscv_ztt_mmulsub_ew_x_f16_rmm_1x2_i8_rne_sat (old, b, __riscv_ztt_scalar_make_i8_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_f16_rno (carrier_i16 c)
{
  __riscv_ztt_f16_rno_2x1_t b = __riscv_ztt_mzero_m_f16_rno_2x1 ();
  __riscv_ztt_f16_rno_2x1_t old = __riscv_ztt_mzero_m_f16_rno_2x1 ();
  __riscv_ztt_f16_rno_2x1_t d = __riscv_ztt_mmulsub_ew_x_f16_rno_2x1_i16_rnu_sat (old, b, __riscv_ztt_scalar_make_i16_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_bf16_rne (carrier_u16 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t old = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t d = __riscv_ztt_mmulsub_ew_x_bf16_rne_1x1_u16_rod_sat (old, b, __riscv_ztt_scalar_make_u16_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_bf16_rtz (carrier_u32 c)
{
  __riscv_ztt_bf16_rtz_2x1_t b = __riscv_ztt_mzero_m_bf16_rtz_2x1 ();
  __riscv_ztt_bf16_rtz_2x1_t old = __riscv_ztt_mzero_m_bf16_rtz_2x1 ();
  __riscv_ztt_bf16_rtz_2x1_t d = __riscv_ztt_mmulsub_ew_x_bf16_rtz_2x1_u32_rdn_sat (old, b, __riscv_ztt_scalar_make_u32_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_bf16_rdn (carrier_u64 c)
{
  __riscv_ztt_bf16_rdn_1x2_t b = __riscv_ztt_mzero_m_bf16_rdn_1x2 ();
  __riscv_ztt_bf16_rdn_1x2_t old = __riscv_ztt_mzero_m_bf16_rdn_1x2 ();
  __riscv_ztt_bf16_rdn_1x2_t d = __riscv_ztt_mmulsub_ew_x_bf16_rdn_1x2_u64_rne_sat (old, b, __riscv_ztt_scalar_from_bits_u64_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_bf16_rup (carrier_u128 c)
{
  __riscv_ztt_bf16_rup_1x1_t b = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_bf16_rup_1x1_t old = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_bf16_rup_1x1_t d = __riscv_ztt_mmulsub_ew_x_bf16_rup_1x1_u128_rnu_sat (old, b, __riscv_ztt_scalar_from_bits_u128_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_bf16_rmm (_Float16 c)
{
  __riscv_ztt_bf16_rmm_1x2_t b = __riscv_ztt_mzero_m_bf16_rmm_1x2 ();
  __riscv_ztt_bf16_rmm_1x2_t old = __riscv_ztt_mzero_m_bf16_rmm_1x2 ();
  __riscv_ztt_bf16_rmm_1x2_t d = __riscv_ztt_mmulsub_ew_x_bf16_rmm_1x2_f16_rup (old, b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_bf16_rno (__bf16 c)
{
  __riscv_ztt_bf16_rno_2x1_t b = __riscv_ztt_mzero_m_bf16_rno_2x1 ();
  __riscv_ztt_bf16_rno_2x1_t old = __riscv_ztt_mzero_m_bf16_rno_2x1 ();
  __riscv_ztt_bf16_rno_2x1_t d = __riscv_ztt_mmulsub_ew_x_bf16_rno_2x1_bf16_rmm (old, b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_f32_rne (float c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t old = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mmulsub_ew_x_f32_rne_1x1_f32_rno (old, b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_f32_rtz (carrier_i8 c)
{
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t old = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mmulsub_ew_x_f32_rtz_1x1_i8_rnu (old, b, __riscv_ztt_scalar_make_i8_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_f32_rdn (carrier_u8 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t old = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mmulsub_ew_x_f32_rdn_1x1_u8_rod (old, b, __riscv_ztt_scalar_make_u8_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_f32_rup (carrier_u16 c)
{
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t old = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mmulsub_ew_x_f32_rup_1x1_u16_rdn (old, b, __riscv_ztt_scalar_make_u16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_f32_rmm (carrier_u32 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t old = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mmulsub_ew_x_f32_rmm_1x1_u32_rne (old, b, __riscv_ztt_scalar_make_u32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mmulsub_f32_rno (carrier_u64 c)
{
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t old = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mmulsub_ew_x_f32_rno_1x1_u64_rnu (old, b, __riscv_ztt_scalar_from_bits_u64_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b), "Wmr" (old));
}
void scalar_mcmpge_i4_rnu (__bf16 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i4_rnu_2x1_t d = __riscv_ztt_mcmpge_ew_x_i4_rnu_2x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i4_rne (float c)
{
  __riscv_ztt_f16_rtz_1x2_t b = __riscv_ztt_mzero_m_f16_rtz_1x2 ();
  __riscv_ztt_i4_rne_1x2_t d = __riscv_ztt_mcmpge_ew_x_i4_rne_1x2_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i4_rdn (carrier_i8 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_i4_rdn_2x1_t d = __riscv_ztt_mcmpge_ew_x_i4_rdn_2x1_i8_rnu (b, __riscv_ztt_scalar_make_i8_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i4_rod (carrier_u8 c)
{
  __riscv_ztt_f16_rup_1x2_t b = __riscv_ztt_mzero_m_f16_rup_1x2 ();
  __riscv_ztt_i4_rod_1x2_t d = __riscv_ztt_mcmpge_ew_x_i4_rod_1x2_u8_rod (b, __riscv_ztt_scalar_make_u8_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u4_rnu (carrier_u16 c)
{
  __riscv_ztt_f16_rmm_2x1_t b = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_u4_rnu_2x1_t d = __riscv_ztt_mcmpge_ew_x_u4_rnu_2x1_u16_rdn (b, __riscv_ztt_scalar_make_u16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u4_rne (carrier_u32 c)
{
  __riscv_ztt_f16_rno_1x2_t b = __riscv_ztt_mzero_m_f16_rno_1x2 ();
  __riscv_ztt_u4_rne_1x2_t d = __riscv_ztt_mcmpge_ew_x_u4_rne_1x2_u32_rne (b, __riscv_ztt_scalar_make_u32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u4_rdn (carrier_u64 c)
{
  __riscv_ztt_bf16_rne_2x1_t b = __riscv_ztt_mzero_m_bf16_rne_2x1 ();
  __riscv_ztt_u4_rdn_2x1_t d = __riscv_ztt_mcmpge_ew_x_u4_rdn_2x1_u64_rnu (b, __riscv_ztt_scalar_from_bits_u64_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u4_rod (carrier_i128 c)
{
  __riscv_ztt_bf16_rtz_1x2_t b = __riscv_ztt_mzero_m_bf16_rtz_1x2 ();
  __riscv_ztt_u4_rod_1x2_t d = __riscv_ztt_mcmpge_ew_x_u4_rod_1x2_i128_rod (b, __riscv_ztt_scalar_from_bits_i128_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i8_rnu (carrier_i8 c)
{
  __riscv_ztt_bf16_rdn_2x1_t b = __riscv_ztt_mzero_m_bf16_rdn_2x1 ();
  __riscv_ztt_i8_rnu_2x1_t d = __riscv_ztt_mcmpge_ew_x_i8_rnu_2x1_i8_rdn_sat (b, __riscv_ztt_scalar_make_i8_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i8_rne (carrier_i16 c)
{
  __riscv_ztt_bf16_rup_1x1_t b = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_i8_rne_1x1_t d = __riscv_ztt_mcmpge_ew_x_i8_rne_1x1_i16_rne_sat (b, __riscv_ztt_scalar_make_i16_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i8_rdn (carrier_i32 c)
{
  __riscv_ztt_bf16_rmm_2x1_t b = __riscv_ztt_mzero_m_bf16_rmm_2x1 ();
  __riscv_ztt_i8_rdn_2x1_t d = __riscv_ztt_mcmpge_ew_x_i8_rdn_2x1_i32_rnu_sat (b, __riscv_ztt_scalar_make_i32_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i8_rod (carrier_u32 c)
{
  __riscv_ztt_bf16_rno_1x2_t b = __riscv_ztt_mzero_m_bf16_rno_1x2 ();
  __riscv_ztt_i8_rod_1x2_t d = __riscv_ztt_mcmpge_ew_x_i8_rod_1x2_u32_rod_sat (b, __riscv_ztt_scalar_make_u32_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u8_rnu (carrier_u64 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t d = __riscv_ztt_mcmpge_ew_x_u8_rnu_1x1_u64_rdn_sat (b, __riscv_ztt_scalar_from_bits_u64_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u8_rne (carrier_u128 c)
{
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_u8_rne_1x1_t d = __riscv_ztt_mcmpge_ew_x_u8_rne_1x1_u128_rne_sat (b, __riscv_ztt_scalar_from_bits_u128_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u8_rdn (_Float16 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t d = __riscv_ztt_mcmpge_ew_x_u8_rdn_1x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u8_rod (__bf16 c)
{
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_u8_rod_1x1_t d = __riscv_ztt_mcmpge_ew_x_u8_rod_1x1_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i16_rnu (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t d = __riscv_ztt_mcmpge_ew_x_i16_rnu_1x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i16_rne (carrier_i8 c)
{
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_i16_rne_1x1_t d = __riscv_ztt_mcmpge_ew_x_i16_rne_1x1_i8_rne (b, __riscv_ztt_scalar_make_i8_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i16_rdn (carrier_i16 c)
{
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_i16_rdn_1x1_t d = __riscv_ztt_mcmpge_ew_x_i16_rdn_1x1_i16_rnu (b, __riscv_ztt_scalar_make_i16_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i16_rod (carrier_u16 c)
{
  __riscv_ztt_f16_rtz_1x2_t b = __riscv_ztt_mzero_m_f16_rtz_1x2 ();
  __riscv_ztt_i16_rod_1x2_t d = __riscv_ztt_mcmpge_ew_x_i16_rod_1x2_u16_rod (b, __riscv_ztt_scalar_make_u16_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u16_rnu (carrier_u32 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_u16_rnu_2x1_t d = __riscv_ztt_mcmpge_ew_x_u16_rnu_2x1_u32_rdn (b, __riscv_ztt_scalar_make_u32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u16_rne (carrier_u64 c)
{
  __riscv_ztt_f16_rup_1x1_t b = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_u16_rne_1x1_t d = __riscv_ztt_mcmpge_ew_x_u16_rne_1x1_u64_rne (b, __riscv_ztt_scalar_from_bits_u64_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u16_rdn (carrier_u128 c)
{
  __riscv_ztt_f16_rmm_2x1_t b = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_u16_rdn_2x1_t d = __riscv_ztt_mcmpge_ew_x_u16_rdn_2x1_u128_rnu (b, __riscv_ztt_scalar_from_bits_u128_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u16_rod (carrier_i8 c)
{
  __riscv_ztt_f16_rno_1x2_t b = __riscv_ztt_mzero_m_f16_rno_1x2 ();
  __riscv_ztt_u16_rod_1x2_t d = __riscv_ztt_mcmpge_ew_x_u16_rod_1x2_i8_rod_sat (b, __riscv_ztt_scalar_make_i8_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i32_rnu (carrier_i16 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mcmpge_ew_x_i32_rnu_1x1_i16_rdn_sat (b, __riscv_ztt_scalar_make_i16_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i32_rne (carrier_i32 c)
{
  __riscv_ztt_bf16_rtz_1x1_t b = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_mcmpge_ew_x_i32_rne_1x1_i32_rne_sat (b, __riscv_ztt_scalar_make_i32_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i32_rdn (carrier_i64 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_mcmpge_ew_x_i32_rdn_1x1_i64_rnu_sat (b, __riscv_ztt_scalar_from_bits_i64_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i32_rod (carrier_u64 c)
{
  __riscv_ztt_bf16_rup_1x1_t b = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mcmpge_ew_x_i32_rod_1x1_u64_rod_sat (b, __riscv_ztt_scalar_from_bits_u64_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u32_rnu (carrier_u128 c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mcmpge_ew_x_u32_rnu_1x1_u128_rdn_sat (b, __riscv_ztt_scalar_from_bits_u128_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u32_rne (_Float16 c)
{
  __riscv_ztt_bf16_rno_1x1_t b = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_mcmpge_ew_x_u32_rne_1x1_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u32_rdn (float c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mcmpge_ew_x_u32_rdn_1x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u32_rod (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_mcmpge_ew_x_u32_rod_1x1_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i4_rnu_sat (carrier_i8 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i4_rnu_sat_2x1_t d = __riscv_ztt_mcmpge_ew_x_i4_rnu_sat_2x1_i8_rdn (b, __riscv_ztt_scalar_make_i8_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i4_rne_sat (carrier_i16 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i4_rne_sat_1x2_t d = __riscv_ztt_mcmpge_ew_x_i4_rne_sat_1x2_i16_rne (b, __riscv_ztt_scalar_make_i16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i4_rdn_sat (carrier_i32 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i4_rdn_sat_2x1_t d = __riscv_ztt_mcmpge_ew_x_i4_rdn_sat_2x1_i32_rnu (b, __riscv_ztt_scalar_make_i32_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i4_rod_sat (carrier_u32 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i4_rod_sat_1x2_t d = __riscv_ztt_mcmpge_ew_x_i4_rod_sat_1x2_u32_rod (b, __riscv_ztt_scalar_make_u32_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u4_rnu_sat (carrier_u64 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_u4_rnu_sat_2x1_t d = __riscv_ztt_mcmpge_ew_x_u4_rnu_sat_2x1_u64_rdn (b, __riscv_ztt_scalar_from_bits_u64_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u4_rne_sat (carrier_u128 c)
{
  __riscv_ztt_f16_rtz_1x2_t b = __riscv_ztt_mzero_m_f16_rtz_1x2 ();
  __riscv_ztt_u4_rne_sat_1x2_t d = __riscv_ztt_mcmpge_ew_x_u4_rne_sat_1x2_u128_rne (b, __riscv_ztt_scalar_from_bits_u128_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u4_rdn_sat (carrier_u8 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_u4_rdn_sat_2x1_t d = __riscv_ztt_mcmpge_ew_x_u4_rdn_sat_2x1_u8_rnu_sat (b, __riscv_ztt_scalar_make_u8_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u4_rod_sat (carrier_i16 c)
{
  __riscv_ztt_f16_rup_1x2_t b = __riscv_ztt_mzero_m_f16_rup_1x2 ();
  __riscv_ztt_u4_rod_sat_1x2_t d = __riscv_ztt_mcmpge_ew_x_u4_rod_sat_1x2_i16_rod_sat (b, __riscv_ztt_scalar_make_i16_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i8_rnu_sat (carrier_i32 c)
{
  __riscv_ztt_f16_rmm_2x1_t b = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_i8_rnu_sat_2x1_t d = __riscv_ztt_mcmpge_ew_x_i8_rnu_sat_2x1_i32_rdn_sat (b, __riscv_ztt_scalar_make_i32_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i8_rne_sat (carrier_i64 c)
{
  __riscv_ztt_f16_rno_1x2_t b = __riscv_ztt_mzero_m_f16_rno_1x2 ();
  __riscv_ztt_i8_rne_sat_1x2_t d = __riscv_ztt_mcmpge_ew_x_i8_rne_sat_1x2_i64_rne_sat (b, __riscv_ztt_scalar_from_bits_i64_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i8_rdn_sat (carrier_i128 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_i8_rdn_sat_1x1_t d = __riscv_ztt_mcmpge_ew_x_i8_rdn_sat_1x1_i128_rnu_sat (b, __riscv_ztt_scalar_from_bits_i128_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i8_rod_sat (carrier_u128 c)
{
  __riscv_ztt_bf16_rtz_1x2_t b = __riscv_ztt_mzero_m_bf16_rtz_1x2 ();
  __riscv_ztt_i8_rod_sat_1x2_t d = __riscv_ztt_mcmpge_ew_x_i8_rod_sat_1x2_u128_rod_sat (b, __riscv_ztt_scalar_from_bits_u128_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u8_rnu_sat (__bf16 c)
{
  __riscv_ztt_bf16_rdn_2x1_t b = __riscv_ztt_mzero_m_bf16_rdn_2x1 ();
  __riscv_ztt_u8_rnu_sat_2x1_t d = __riscv_ztt_mcmpge_ew_x_u8_rnu_sat_2x1_bf16_rne (b, __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u8_rne_sat (float c)
{
  __riscv_ztt_bf16_rup_1x1_t b = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_u8_rne_sat_1x1_t d = __riscv_ztt_mcmpge_ew_x_u8_rne_sat_1x1_f32_rtz (b, __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u8_rdn_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rmm_2x1_t b = __riscv_ztt_mzero_m_bf16_rmm_2x1 ();
  __riscv_ztt_u8_rdn_sat_2x1_t d = __riscv_ztt_mcmpge_ew_x_u8_rdn_sat_2x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u8_rod_sat (carrier_i8 c)
{
  __riscv_ztt_bf16_rno_1x2_t b = __riscv_ztt_mzero_m_bf16_rno_1x2 ();
  __riscv_ztt_u8_rod_sat_1x2_t d = __riscv_ztt_mcmpge_ew_x_u8_rod_sat_1x2_i8_rod (b, __riscv_ztt_scalar_make_i8_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i16_rnu_sat (carrier_i16 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t d = __riscv_ztt_mcmpge_ew_x_i16_rnu_sat_1x1_i16_rdn (b, __riscv_ztt_scalar_make_i16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i16_rne_sat (carrier_i32 c)
{
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_i16_rne_sat_1x1_t d = __riscv_ztt_mcmpge_ew_x_i16_rne_sat_1x1_i32_rne (b, __riscv_ztt_scalar_make_i32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i16_rdn_sat (carrier_i64 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t d = __riscv_ztt_mcmpge_ew_x_i16_rdn_sat_1x1_i64_rnu (b, __riscv_ztt_scalar_from_bits_i64_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i16_rod_sat (carrier_u64 c)
{
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_i16_rod_sat_1x1_t d = __riscv_ztt_mcmpge_ew_x_i16_rod_sat_1x1_u64_rod (b, __riscv_ztt_scalar_from_bits_u64_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u16_rnu_sat (carrier_u128 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t d = __riscv_ztt_mcmpge_ew_x_u16_rnu_sat_1x1_u128_rdn (b, __riscv_ztt_scalar_from_bits_u128_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u16_rne_sat (carrier_u8 c)
{
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_u16_rne_sat_1x1_t d = __riscv_ztt_mcmpge_ew_x_u16_rne_sat_1x1_u8_rne_sat (b, __riscv_ztt_scalar_make_u8_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u16_rdn_sat (carrier_u16 c)
{
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_u16_rdn_sat_1x1_t d = __riscv_ztt_mcmpge_ew_x_u16_rdn_sat_1x1_u16_rnu_sat (b, __riscv_ztt_scalar_make_u16_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u16_rod_sat (carrier_i32 c)
{
  __riscv_ztt_f16_rtz_1x2_t b = __riscv_ztt_mzero_m_f16_rtz_1x2 ();
  __riscv_ztt_u16_rod_sat_1x2_t d = __riscv_ztt_mcmpge_ew_x_u16_rod_sat_1x2_i32_rod_sat (b, __riscv_ztt_scalar_make_i32_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i32_rnu_sat (carrier_i64 c)
{
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_mcmpge_ew_x_i32_rnu_sat_1x1_i64_rdn_sat (b, __riscv_ztt_scalar_from_bits_i64_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i32_rne_sat (carrier_i128 c)
{
  __riscv_ztt_f16_rup_1x1_t b = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_mcmpge_ew_x_i32_rne_sat_1x1_i128_rne_sat (b, __riscv_ztt_scalar_from_bits_i128_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i32_rdn_sat (_Float16 c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mcmpge_ew_x_i32_rdn_sat_1x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_i32_rod_sat (__bf16 c)
{
  __riscv_ztt_f16_rno_1x1_t b = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_mcmpge_ew_x_i32_rod_sat_1x1_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u32_rnu_sat (float c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_mcmpge_ew_x_u32_rnu_sat_1x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u32_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rtz_1x1_t b = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mcmpge_ew_x_u32_rne_sat_1x1_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u32_rdn_sat (carrier_u8 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_mcmpge_ew_x_u32_rdn_sat_1x1_u8_rnu (b, __riscv_ztt_scalar_make_u8_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmpge_u32_rod_sat (carrier_i16 c)
{
  __riscv_ztt_bf16_rup_1x1_t b = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_mcmpge_ew_x_u32_rod_sat_1x1_i16_rod (b, __riscv_ztt_scalar_make_i16_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i4_rnu (float c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i4_rnu_1x2_t d = __riscv_ztt_mcmplt_ew_x_i4_rnu_1x2_f32_rup (b, __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i4_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f16_rtz_2x1_t b = __riscv_ztt_mzero_m_f16_rtz_2x1 ();
  __riscv_ztt_i4_rne_2x1_t d = __riscv_ztt_mcmplt_ew_x_i4_rne_2x1_f64_rmm (b, ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i4_rdn (carrier_u8 c)
{
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_i4_rdn_1x2_t d = __riscv_ztt_mcmplt_ew_x_i4_rdn_1x2_u8_rne (b, __riscv_ztt_scalar_make_u8_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i4_rod (carrier_u16 c)
{
  __riscv_ztt_f16_rup_2x1_t b = __riscv_ztt_mzero_m_f16_rup_2x1 ();
  __riscv_ztt_i4_rod_2x1_t d = __riscv_ztt_mcmplt_ew_x_i4_rod_2x1_u16_rnu (b, __riscv_ztt_scalar_make_u16_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u4_rnu (carrier_i32 c)
{
  __riscv_ztt_f16_rmm_1x2_t b = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_u4_rnu_1x2_t d = __riscv_ztt_mcmplt_ew_x_u4_rnu_1x2_i32_rod (b, __riscv_ztt_scalar_make_i32_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u4_rne (carrier_i64 c)
{
  __riscv_ztt_f16_rno_2x1_t b = __riscv_ztt_mzero_m_f16_rno_2x1 ();
  __riscv_ztt_u4_rne_2x1_t d = __riscv_ztt_mcmplt_ew_x_u4_rne_2x1_i64_rdn (b, __riscv_ztt_scalar_from_bits_i64_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u4_rdn (carrier_i128 c)
{
  __riscv_ztt_bf16_rne_1x2_t b = __riscv_ztt_mzero_m_bf16_rne_1x2 ();
  __riscv_ztt_u4_rdn_1x2_t d = __riscv_ztt_mcmplt_ew_x_u4_rdn_1x2_i128_rne (b, __riscv_ztt_scalar_from_bits_i128_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u4_rod (carrier_i8 c)
{
  __riscv_ztt_bf16_rtz_2x1_t b = __riscv_ztt_mzero_m_bf16_rtz_2x1 ();
  __riscv_ztt_u4_rod_2x1_t d = __riscv_ztt_mcmplt_ew_x_u4_rod_2x1_i8_rnu_sat (b, __riscv_ztt_scalar_make_i8_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i8_rnu (carrier_u8 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t d = __riscv_ztt_mcmplt_ew_x_i8_rnu_1x1_u8_rod_sat (b, __riscv_ztt_scalar_make_u8_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i8_rne (carrier_u16 c)
{
  __riscv_ztt_bf16_rup_2x1_t b = __riscv_ztt_mzero_m_bf16_rup_2x1 ();
  __riscv_ztt_i8_rne_2x1_t d = __riscv_ztt_mcmplt_ew_x_i8_rne_2x1_u16_rdn_sat (b, __riscv_ztt_scalar_make_u16_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i8_rdn (carrier_u32 c)
{
  __riscv_ztt_bf16_rmm_1x2_t b = __riscv_ztt_mzero_m_bf16_rmm_1x2 ();
  __riscv_ztt_i8_rdn_1x2_t d = __riscv_ztt_mcmplt_ew_x_i8_rdn_1x2_u32_rne_sat (b, __riscv_ztt_scalar_make_u32_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i8_rod (carrier_u64 c)
{
  __riscv_ztt_bf16_rno_1x1_t b = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_i8_rod_1x1_t d = __riscv_ztt_mcmplt_ew_x_i8_rod_1x1_u64_rnu_sat (b, __riscv_ztt_scalar_from_bits_u64_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u8_rnu (carrier_i128 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t d = __riscv_ztt_mcmplt_ew_x_u8_rnu_1x1_i128_rod_sat (b, __riscv_ztt_scalar_from_bits_i128_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u8_rne (_Float16 c)
{
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_u8_rne_1x1_t d = __riscv_ztt_mcmplt_ew_x_u8_rne_1x1_f16_rdn (b, __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u8_rdn (__bf16 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t d = __riscv_ztt_mcmplt_ew_x_u8_rdn_1x1_bf16_rup (b, __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u8_rod (float c)
{
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_u8_rod_1x1_t d = __riscv_ztt_mcmplt_ew_x_u8_rod_1x1_f32_rmm (b, __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i16_rnu (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t d = __riscv_ztt_mcmplt_ew_x_i16_rnu_1x1_f64_rno (b, ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i16_rne (carrier_u8 c)
{
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_i16_rne_1x1_t d = __riscv_ztt_mcmplt_ew_x_i16_rne_1x1_u8_rdn (b, __riscv_ztt_scalar_make_u8_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i16_rdn (carrier_u16 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i16_rdn_1x2_t d = __riscv_ztt_mcmplt_ew_x_i16_rdn_1x2_u16_rne (b, __riscv_ztt_scalar_make_u16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i16_rod (carrier_u32 c)
{
  __riscv_ztt_f16_rtz_2x1_t b = __riscv_ztt_mzero_m_f16_rtz_2x1 ();
  __riscv_ztt_i16_rod_2x1_t d = __riscv_ztt_mcmplt_ew_x_i16_rod_2x1_u32_rnu (b, __riscv_ztt_scalar_make_u32_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u16_rnu (carrier_i64 c)
{
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_u16_rnu_1x1_t d = __riscv_ztt_mcmplt_ew_x_u16_rnu_1x1_i64_rod (b, __riscv_ztt_scalar_from_bits_i64_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u16_rne (carrier_i128 c)
{
  __riscv_ztt_f16_rup_2x1_t b = __riscv_ztt_mzero_m_f16_rup_2x1 ();
  __riscv_ztt_u16_rne_2x1_t d = __riscv_ztt_mcmplt_ew_x_u16_rne_2x1_i128_rdn (b, __riscv_ztt_scalar_from_bits_i128_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u16_rdn (carrier_i8 c)
{
  __riscv_ztt_f16_rmm_1x2_t b = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_u16_rdn_1x2_t d = __riscv_ztt_mcmplt_ew_x_u16_rdn_1x2_i8_rne_sat (b, __riscv_ztt_scalar_make_i8_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u16_rod (carrier_i16 c)
{
  __riscv_ztt_f16_rno_1x1_t b = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_u16_rod_1x1_t d = __riscv_ztt_mcmplt_ew_x_u16_rod_1x1_i16_rnu_sat (b, __riscv_ztt_scalar_make_i16_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i32_rnu (carrier_u16 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mcmplt_ew_x_i32_rnu_1x1_u16_rod_sat (b, __riscv_ztt_scalar_make_u16_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i32_rne (carrier_u32 c)
{
  __riscv_ztt_bf16_rtz_1x1_t b = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_mcmplt_ew_x_i32_rne_1x1_u32_rdn_sat (b, __riscv_ztt_scalar_make_u32_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i32_rdn (carrier_u64 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_mcmplt_ew_x_i32_rdn_1x1_u64_rne_sat (b, __riscv_ztt_scalar_from_bits_u64_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i32_rod (carrier_u128 c)
{
  __riscv_ztt_bf16_rup_1x1_t b = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mcmplt_ew_x_i32_rod_1x1_u128_rnu_sat (b, __riscv_ztt_scalar_from_bits_u128_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u32_rnu (_Float16 c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mcmplt_ew_x_u32_rnu_1x1_f16_rup (b, __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u32_rne (__bf16 c)
{
  __riscv_ztt_bf16_rno_1x1_t b = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_mcmplt_ew_x_u32_rne_1x1_bf16_rmm (b, __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u32_rdn (float c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mcmplt_ew_x_u32_rdn_1x1_f32_rno (b, __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u32_rod (carrier_i8 c)
{
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_mcmplt_ew_x_u32_rod_1x1_i8_rnu (b, __riscv_ztt_scalar_make_i8_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i4_rnu_sat (carrier_u8 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i4_rnu_sat_1x2_t d = __riscv_ztt_mcmplt_ew_x_i4_rnu_sat_1x2_u8_rod (b, __riscv_ztt_scalar_make_u8_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i4_rne_sat (carrier_u16 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i4_rne_sat_2x1_t d = __riscv_ztt_mcmplt_ew_x_i4_rne_sat_2x1_u16_rdn (b, __riscv_ztt_scalar_make_u16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i4_rdn_sat (carrier_u32 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i4_rdn_sat_1x2_t d = __riscv_ztt_mcmplt_ew_x_i4_rdn_sat_1x2_u32_rne (b, __riscv_ztt_scalar_make_u32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i4_rod_sat (carrier_u64 c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_i4_rod_sat_2x1_t d = __riscv_ztt_mcmplt_ew_x_i4_rod_sat_2x1_u64_rnu (b, __riscv_ztt_scalar_from_bits_u64_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u4_rnu_sat (carrier_i128 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_u4_rnu_sat_1x2_t d = __riscv_ztt_mcmplt_ew_x_u4_rnu_sat_1x2_i128_rod (b, __riscv_ztt_scalar_from_bits_i128_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u4_rne_sat (carrier_i8 c)
{
  __riscv_ztt_f16_rtz_2x1_t b = __riscv_ztt_mzero_m_f16_rtz_2x1 ();
  __riscv_ztt_u4_rne_sat_2x1_t d = __riscv_ztt_mcmplt_ew_x_u4_rne_sat_2x1_i8_rdn_sat (b, __riscv_ztt_scalar_make_i8_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u4_rdn_sat (carrier_i16 c)
{
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_u4_rdn_sat_1x2_t d = __riscv_ztt_mcmplt_ew_x_u4_rdn_sat_1x2_i16_rne_sat (b, __riscv_ztt_scalar_make_i16_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u4_rod_sat (carrier_i32 c)
{
  __riscv_ztt_f16_rup_2x1_t b = __riscv_ztt_mzero_m_f16_rup_2x1 ();
  __riscv_ztt_u4_rod_sat_2x1_t d = __riscv_ztt_mcmplt_ew_x_u4_rod_sat_2x1_i32_rnu_sat (b, __riscv_ztt_scalar_make_i32_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i8_rnu_sat (carrier_u32 c)
{
  __riscv_ztt_f16_rmm_1x2_t b = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_i8_rnu_sat_1x2_t d = __riscv_ztt_mcmplt_ew_x_i8_rnu_sat_1x2_u32_rod_sat (b, __riscv_ztt_scalar_make_u32_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i8_rne_sat (carrier_u64 c)
{
  __riscv_ztt_f16_rno_1x1_t b = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_i8_rne_sat_1x1_t d = __riscv_ztt_mcmplt_ew_x_i8_rne_sat_1x1_u64_rdn_sat (b, __riscv_ztt_scalar_from_bits_u64_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i8_rdn_sat (carrier_u128 c)
{
  __riscv_ztt_bf16_rne_1x2_t b = __riscv_ztt_mzero_m_bf16_rne_1x2 ();
  __riscv_ztt_i8_rdn_sat_1x2_t d = __riscv_ztt_mcmplt_ew_x_i8_rdn_sat_1x2_u128_rne_sat (b, __riscv_ztt_scalar_from_bits_u128_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i8_rod_sat (_Float16 c)
{
  __riscv_ztt_bf16_rtz_2x1_t b = __riscv_ztt_mzero_m_bf16_rtz_2x1 ();
  __riscv_ztt_i8_rod_sat_2x1_t d = __riscv_ztt_mcmplt_ew_x_i8_rod_sat_2x1_f16_rmm (b, __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u8_rnu_sat (__bf16 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_u8_rnu_sat_1x1_t d = __riscv_ztt_mcmplt_ew_x_u8_rnu_sat_1x1_bf16_rno (b, __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u8_rne_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rup_2x1_t b = __riscv_ztt_mzero_m_bf16_rup_2x1 ();
  __riscv_ztt_u8_rne_sat_2x1_t d = __riscv_ztt_mcmplt_ew_x_u8_rne_sat_2x1_f64_rne (b, ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u8_rdn_sat (carrier_i8 c)
{
  __riscv_ztt_bf16_rmm_1x2_t b = __riscv_ztt_mzero_m_bf16_rmm_1x2 ();
  __riscv_ztt_u8_rdn_sat_1x2_t d = __riscv_ztt_mcmplt_ew_x_u8_rdn_sat_1x2_i8_rne (b, __riscv_ztt_scalar_make_i8_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u8_rod_sat (carrier_i16 c)
{
  __riscv_ztt_bf16_rno_1x1_t b = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_u8_rod_sat_1x1_t d = __riscv_ztt_mcmplt_ew_x_u8_rod_sat_1x1_i16_rnu (b, __riscv_ztt_scalar_make_i16_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i16_rnu_sat (carrier_u16 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t d = __riscv_ztt_mcmplt_ew_x_i16_rnu_sat_1x1_u16_rod (b, __riscv_ztt_scalar_make_u16_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i16_rne_sat (carrier_u32 c)
{
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_i16_rne_sat_1x1_t d = __riscv_ztt_mcmplt_ew_x_i16_rne_sat_1x1_u32_rdn (b, __riscv_ztt_scalar_make_u32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i16_rdn_sat (carrier_u64 c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t d = __riscv_ztt_mcmplt_ew_x_i16_rdn_sat_1x1_u64_rne (b, __riscv_ztt_scalar_from_bits_u64_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i16_rod_sat (carrier_u128 c)
{
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_i16_rod_sat_1x1_t d = __riscv_ztt_mcmplt_ew_x_i16_rod_sat_1x1_u128_rnu (b, __riscv_ztt_scalar_from_bits_u128_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u16_rnu_sat (carrier_i8 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t d = __riscv_ztt_mcmplt_ew_x_u16_rnu_sat_1x1_i8_rod_sat (b, __riscv_ztt_scalar_make_i8_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u16_rne_sat (carrier_i16 c)
{
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_u16_rne_sat_1x1_t d = __riscv_ztt_mcmplt_ew_x_u16_rne_sat_1x1_i16_rdn_sat (b, __riscv_ztt_scalar_make_i16_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u16_rdn_sat (carrier_i32 c)
{
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_u16_rdn_sat_1x2_t d = __riscv_ztt_mcmplt_ew_x_u16_rdn_sat_1x2_i32_rne_sat (b, __riscv_ztt_scalar_make_i32_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u16_rod_sat (carrier_i64 c)
{
  __riscv_ztt_f16_rtz_2x1_t b = __riscv_ztt_mzero_m_f16_rtz_2x1 ();
  __riscv_ztt_u16_rod_sat_2x1_t d = __riscv_ztt_mcmplt_ew_x_u16_rod_sat_2x1_i64_rnu_sat (b, __riscv_ztt_scalar_from_bits_i64_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i32_rnu_sat (carrier_u64 c)
{
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_mcmplt_ew_x_i32_rnu_sat_1x1_u64_rod_sat (b, __riscv_ztt_scalar_from_bits_u64_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i32_rne_sat (carrier_u128 c)
{
  __riscv_ztt_f16_rup_1x1_t b = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_mcmplt_ew_x_i32_rne_sat_1x1_u128_rdn_sat (b, __riscv_ztt_scalar_from_bits_u128_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i32_rdn_sat (_Float16 c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mcmplt_ew_x_i32_rdn_sat_1x1_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_i32_rod_sat (float c)
{
  __riscv_ztt_f16_rno_1x1_t b = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_mcmplt_ew_x_i32_rod_sat_1x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u32_rnu_sat (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_mcmplt_ew_x_u32_rnu_sat_1x1_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u32_rne_sat (carrier_i8 c)
{
  __riscv_ztt_bf16_rtz_1x1_t b = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mcmplt_ew_x_u32_rne_sat_1x1_i8_rdn (b, __riscv_ztt_scalar_make_i8_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u32_rdn_sat (carrier_i16 c)
{
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_mcmplt_ew_x_u32_rdn_sat_1x1_i16_rne (b, __riscv_ztt_scalar_make_i16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mcmplt_u32_rod_sat (carrier_i32 c)
{
  __riscv_ztt_bf16_rup_1x1_t b = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_mcmplt_ew_x_u32_rod_sat_1x1_i32_rnu (b, __riscv_ztt_scalar_make_i32_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mlog2sub_f16_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f16_rne_2x1_t b = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_f16_rne_2x1_t d = __riscv_ztt_mlog2sub_ew_x_f16_rne_2x1_f64_rdn (b, ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mlog2sub_f16_rtz (carrier_i8 c)
{
  __riscv_ztt_f16_rtz_1x1_t b = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_mlog2sub_ew_x_f16_rtz_1x1_i8_rod (b, __riscv_ztt_scalar_make_i8_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mlog2sub_f16_rdn (carrier_i16 c)
{
  __riscv_ztt_f16_rdn_2x1_t b = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_f16_rdn_2x1_t d = __riscv_ztt_mlog2sub_ew_x_f16_rdn_2x1_i16_rdn (b, __riscv_ztt_scalar_make_i16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mlog2sub_f16_rup (carrier_i32 c)
{
  __riscv_ztt_f16_rup_1x2_t b = __riscv_ztt_mzero_m_f16_rup_1x2 ();
  __riscv_ztt_f16_rup_1x2_t d = __riscv_ztt_mlog2sub_ew_x_f16_rup_1x2_i32_rne (b, __riscv_ztt_scalar_make_i32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mlog2sub_f16_rmm (carrier_i64 c)
{
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mlog2sub_ew_x_f16_rmm_1x1_i64_rnu (b, __riscv_ztt_scalar_from_bits_i64_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mlog2sub_f16_rno (carrier_u64 c)
{
  __riscv_ztt_f16_rno_1x2_t b = __riscv_ztt_mzero_m_f16_rno_1x2 ();
  __riscv_ztt_f16_rno_1x2_t d = __riscv_ztt_mlog2sub_ew_x_f16_rno_1x2_u64_rod (b, __riscv_ztt_scalar_from_bits_u64_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mlog2sub_bf16_rne (carrier_u128 c)
{
  __riscv_ztt_bf16_rne_2x1_t b = __riscv_ztt_mzero_m_bf16_rne_2x1 ();
  __riscv_ztt_bf16_rne_2x1_t d = __riscv_ztt_mlog2sub_ew_x_bf16_rne_2x1_u128_rdn (b, __riscv_ztt_scalar_from_bits_u128_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mlog2sub_bf16_rtz (carrier_u8 c)
{
  __riscv_ztt_bf16_rtz_1x1_t b = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t d = __riscv_ztt_mlog2sub_ew_x_bf16_rtz_1x1_u8_rne_sat (b, __riscv_ztt_scalar_make_u8_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mlog2sub_bf16_rdn (carrier_u16 c)
{
  __riscv_ztt_bf16_rdn_2x1_t b = __riscv_ztt_mzero_m_bf16_rdn_2x1 ();
  __riscv_ztt_bf16_rdn_2x1_t d = __riscv_ztt_mlog2sub_ew_x_bf16_rdn_2x1_u16_rnu_sat (b, __riscv_ztt_scalar_make_u16_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mlog2sub_bf16_rup (carrier_i32 c)
{
  __riscv_ztt_bf16_rup_1x2_t b = __riscv_ztt_mzero_m_bf16_rup_1x2 ();
  __riscv_ztt_bf16_rup_1x2_t d = __riscv_ztt_mlog2sub_ew_x_bf16_rup_1x2_i32_rod_sat (b, __riscv_ztt_scalar_make_i32_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mlog2sub_bf16_rmm (carrier_i64 c)
{
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_bf16_rmm_1x1_t d = __riscv_ztt_mlog2sub_ew_x_bf16_rmm_1x1_i64_rdn_sat (b, __riscv_ztt_scalar_from_bits_i64_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mlog2sub_bf16_rno (carrier_i128 c)
{
  __riscv_ztt_bf16_rno_1x2_t b = __riscv_ztt_mzero_m_bf16_rno_1x2 ();
  __riscv_ztt_bf16_rno_1x2_t d = __riscv_ztt_mlog2sub_ew_x_bf16_rno_1x2_i128_rne_sat (b, __riscv_ztt_scalar_from_bits_i128_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mlog2sub_f32_rne (_Float16 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mlog2sub_ew_x_f32_rne_1x1_f16_rne (b, __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mlog2sub_f32_rtz (__bf16 c)
{
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mlog2sub_ew_x_f32_rtz_1x1_bf16_rtz (b, __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mlog2sub_f32_rdn (float c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mlog2sub_ew_x_f32_rdn_1x1_f32_rdn (b, __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mlog2sub_f32_rup (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mlog2sub_ew_x_f32_rup_1x1_f64_rup (b, ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mlog2sub_f32_rmm (carrier_u8 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mlog2sub_ew_x_f32_rmm_1x1_u8_rnu (b, __riscv_ztt_scalar_make_u8_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_mlog2sub_f32_rno (carrier_i16 c)
{
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mlog2sub_ew_x_f32_rno_1x1_i16_rod (b, __riscv_ztt_scalar_make_i16_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msublog2_f16_rne (carrier_i8 c)
{
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_f16_rne_1x1_t d = __riscv_ztt_msublog2_ew_x_f16_rne_1x1_i8_rne (b, __riscv_ztt_scalar_make_i8_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msublog2_f16_rtz (carrier_i16 c)
{
  __riscv_ztt_f16_rtz_2x1_t b = __riscv_ztt_mzero_m_f16_rtz_2x1 ();
  __riscv_ztt_f16_rtz_2x1_t d = __riscv_ztt_msublog2_ew_x_f16_rtz_2x1_i16_rnu (b, __riscv_ztt_scalar_make_i16_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msublog2_f16_rdn (carrier_u16 c)
{
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_f16_rdn_1x2_t d = __riscv_ztt_msublog2_ew_x_f16_rdn_1x2_u16_rod (b, __riscv_ztt_scalar_make_u16_rod (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msublog2_f16_rup (carrier_u32 c)
{
  __riscv_ztt_f16_rup_1x1_t b = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_f16_rup_1x1_t d = __riscv_ztt_msublog2_ew_x_f16_rup_1x1_u32_rdn (b, __riscv_ztt_scalar_make_u32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msublog2_f16_rmm (carrier_u64 c)
{
  __riscv_ztt_f16_rmm_1x2_t b = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_f16_rmm_1x2_t d = __riscv_ztt_msublog2_ew_x_f16_rmm_1x2_u64_rne (b, __riscv_ztt_scalar_from_bits_u64_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msublog2_f16_rno (carrier_u128 c)
{
  __riscv_ztt_f16_rno_2x1_t b = __riscv_ztt_mzero_m_f16_rno_2x1 ();
  __riscv_ztt_f16_rno_2x1_t d = __riscv_ztt_msublog2_ew_x_f16_rno_2x1_u128_rnu (b, __riscv_ztt_scalar_from_bits_u128_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msublog2_bf16_rne (carrier_i8 c)
{
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t d = __riscv_ztt_msublog2_ew_x_bf16_rne_1x1_i8_rod_sat (b, __riscv_ztt_scalar_make_i8_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msublog2_bf16_rtz (carrier_i16 c)
{
  __riscv_ztt_bf16_rtz_2x1_t b = __riscv_ztt_mzero_m_bf16_rtz_2x1 ();
  __riscv_ztt_bf16_rtz_2x1_t d = __riscv_ztt_msublog2_ew_x_bf16_rtz_2x1_i16_rdn_sat (b, __riscv_ztt_scalar_make_i16_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msublog2_bf16_rdn (carrier_i32 c)
{
  __riscv_ztt_bf16_rdn_1x2_t b = __riscv_ztt_mzero_m_bf16_rdn_1x2 ();
  __riscv_ztt_bf16_rdn_1x2_t d = __riscv_ztt_msublog2_ew_x_bf16_rdn_1x2_i32_rne_sat (b, __riscv_ztt_scalar_make_i32_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msublog2_bf16_rup (carrier_i64 c)
{
  __riscv_ztt_bf16_rup_1x1_t b = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_bf16_rup_1x1_t d = __riscv_ztt_msublog2_ew_x_bf16_rup_1x1_i64_rnu_sat (b, __riscv_ztt_scalar_from_bits_i64_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msublog2_bf16_rmm (carrier_u64 c)
{
  __riscv_ztt_bf16_rmm_1x2_t b = __riscv_ztt_mzero_m_bf16_rmm_1x2 ();
  __riscv_ztt_bf16_rmm_1x2_t d = __riscv_ztt_msublog2_ew_x_bf16_rmm_1x2_u64_rod_sat (b, __riscv_ztt_scalar_from_bits_u64_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msublog2_bf16_rno (carrier_u128 c)
{
  __riscv_ztt_bf16_rno_2x1_t b = __riscv_ztt_mzero_m_bf16_rno_2x1 ();
  __riscv_ztt_bf16_rno_2x1_t d = __riscv_ztt_msublog2_ew_x_bf16_rno_2x1_u128_rdn_sat (b, __riscv_ztt_scalar_from_bits_u128_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msublog2_f32_rne (_Float16 c)
{
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_msublog2_ew_x_f32_rne_1x1_f16_rno (b, __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msublog2_f32_rtz (float c)
{
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_msublog2_ew_x_f32_rtz_1x1_f32_rne (b, __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msublog2_f32_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_msublog2_ew_x_f32_rdn_1x1_f64_rtz (b, ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msublog2_f32_rup (carrier_i8 c)
{
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_msublog2_ew_x_f32_rup_1x1_i8_rdn (b, __riscv_ztt_scalar_make_i8_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msublog2_f32_rmm (carrier_i16 c)
{
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_msublog2_ew_x_f32_rmm_1x1_i16_rne (b, __riscv_ztt_scalar_make_i16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
void scalar_msublog2_f32_rno (carrier_i32 c)
{
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_msublog2_ew_x_f32_rno_1x1_i32_rnu (b, __riscv_ztt_scalar_make_i32_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (b));
}
