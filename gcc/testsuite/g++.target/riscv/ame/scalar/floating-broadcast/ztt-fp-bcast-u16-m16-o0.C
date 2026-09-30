/* Floating/mixed broadcast contracts, not numerical execution.  */
/* { dg-do assemble } */
/* { dg-options "-O0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m16-a16" { target rv32 } } */
/* { dg-options "-O0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m16-a16" { target rv64 } } */
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
#if __riscv_ztt_floating_broadcast != 1
#error missing capability
#endif
#ifdef __cplusplus
extern "C" {
#endif
void bcast_0_i4_rnu_4x1_f16_rne (_Float16 c)
{
  __riscv_ztt_i4_rnu_4x1_t d = __riscv_ztt_mbcast_m_x_i4_rnu_4x1_f16_rne ( __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_1_i4_rne_1x8_f16_rtz (_Float16 c)
{
  __riscv_ztt_i4_rne_1x8_t d = __riscv_ztt_mbcast_m_x_i4_rne_1x8_f16_rtz ( __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_2_i4_rdn_16x1_f16_rdn (_Float16 c)
{
  __riscv_ztt_i4_rdn_16x1_t d = __riscv_ztt_mbcast_m_x_i4_rdn_16x1_f16_rdn ( __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_3_i4_rod_1x4_f16_rup (_Float16 c)
{
  __riscv_ztt_i4_rod_1x4_t d = __riscv_ztt_mbcast_m_x_i4_rod_1x4_f16_rup ( __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_4_u4_rnu_8x1_f16_rmm (_Float16 c)
{
  __riscv_ztt_u4_rnu_8x1_t d = __riscv_ztt_mbcast_m_x_u4_rnu_8x1_f16_rmm ( __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_5_u4_rne_1x16_f16_rno (_Float16 c)
{
  __riscv_ztt_u4_rne_1x16_t d = __riscv_ztt_mbcast_m_x_u4_rne_1x16_f16_rno ( __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_6_u4_rdn_4x1_bf16_rne (__bf16 c)
{
  __riscv_ztt_u4_rdn_4x1_t d = __riscv_ztt_mbcast_m_x_u4_rdn_4x1_bf16_rne ( __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_7_u4_rod_1x8_bf16_rtz (__bf16 c)
{
  __riscv_ztt_u4_rod_1x8_t d = __riscv_ztt_mbcast_m_x_u4_rod_1x8_bf16_rtz ( __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_8_i8_rnu_8x1_bf16_rdn (__bf16 c)
{
  __riscv_ztt_i8_rnu_8x1_t d = __riscv_ztt_mbcast_m_x_i8_rnu_8x1_bf16_rdn ( __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_9_i8_rne_1x2_bf16_rup (__bf16 c)
{
  __riscv_ztt_i8_rne_1x2_t d = __riscv_ztt_mbcast_m_x_i8_rne_1x2_bf16_rup ( __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_10_i8_rdn_4x1_bf16_rmm (__bf16 c)
{
  __riscv_ztt_i8_rdn_4x1_t d = __riscv_ztt_mbcast_m_x_i8_rdn_4x1_bf16_rmm ( __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_11_i8_rod_1x8_bf16_rno (__bf16 c)
{
  __riscv_ztt_i8_rod_1x8_t d = __riscv_ztt_mbcast_m_x_i8_rod_1x8_bf16_rno ( __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_12_u8_rnu_2x1_f32_rne (float c)
{
  __riscv_ztt_u8_rnu_2x1_t d = __riscv_ztt_mbcast_m_x_u8_rnu_2x1_f32_rne ( __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_13_u8_rne_1x4_f32_rtz (float c)
{
  __riscv_ztt_u8_rne_1x4_t d = __riscv_ztt_mbcast_m_x_u8_rne_1x4_f32_rtz ( __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_14_u8_rdn_8x1_f32_rdn (float c)
{
  __riscv_ztt_u8_rdn_8x1_t d = __riscv_ztt_mbcast_m_x_u8_rdn_8x1_f32_rdn ( __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_15_u8_rod_1x2_f32_rup (float c)
{
  __riscv_ztt_u8_rod_1x2_t d = __riscv_ztt_mbcast_m_x_u8_rod_1x2_f32_rup ( __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_16_i16_rnu_2x1_f32_rmm (float c)
{
  __riscv_ztt_i16_rnu_2x1_t d = __riscv_ztt_mbcast_m_x_i16_rnu_2x1_f32_rmm ( __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_17_i16_rne_1x4_f32_rno (float c)
{
  __riscv_ztt_i16_rne_1x4_t d = __riscv_ztt_mbcast_m_x_i16_rne_1x4_f32_rno ( __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_18_i16_rdn_1x1_f64_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_i16_rdn_1x1_f64_rne ( ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_19_i16_rod_1x2_f64_rtz (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i16_rod_1x2_t d = __riscv_ztt_mbcast_m_x_i16_rod_1x2_f64_rtz ( ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_20_u16_rnu_4x1_f64_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rnu_4x1_t d = __riscv_ztt_mbcast_m_x_u16_rnu_4x1_f64_rdn ( ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_21_u16_rne_1x1_f64_rup (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rne_1x1_t d = __riscv_ztt_mbcast_m_x_u16_rne_1x1_f64_rup ( ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_22_u16_rdn_2x1_f64_rmm (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rdn_2x1_t d = __riscv_ztt_mbcast_m_x_u16_rdn_2x1_f64_rmm ( ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_23_u16_rod_1x4_f64_rno (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rod_1x4_t d = __riscv_ztt_mbcast_m_x_u16_rod_1x4_f64_rno ( ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_24_i32_rnu_1x1_f16_rne (_Float16 c)
{
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mbcast_m_x_i32_rnu_1x1_f16_rne ( __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_25_i32_rne_1x2_f16_rtz (_Float16 c)
{
  __riscv_ztt_i32_rne_1x2_t d = __riscv_ztt_mbcast_m_x_i32_rne_1x2_f16_rtz ( __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_26_i32_rdn_2x1_f16_rdn (_Float16 c)
{
  __riscv_ztt_i32_rdn_2x1_t d = __riscv_ztt_mbcast_m_x_i32_rdn_2x1_f16_rdn ( __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_27_i32_rod_1x1_f16_rup (_Float16 c)
{
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mbcast_m_x_i32_rod_1x1_f16_rup ( __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_28_u32_rnu_2x1_f16_rmm (_Float16 c)
{
  __riscv_ztt_u32_rnu_2x1_t d = __riscv_ztt_mbcast_m_x_u32_rnu_2x1_f16_rmm ( __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_29_u32_rne_1x2_f16_rno (_Float16 c)
{
  __riscv_ztt_u32_rne_1x2_t d = __riscv_ztt_mbcast_m_x_u32_rne_1x2_f16_rno ( __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_30_u32_rdn_1x1_bf16_rne (__bf16 c)
{
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_u32_rdn_1x1_bf16_rne ( __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_31_u32_rod_1x2_bf16_rtz (__bf16 c)
{
  __riscv_ztt_u32_rod_1x2_t d = __riscv_ztt_mbcast_m_x_u32_rod_1x2_bf16_rtz ( __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_32_i64_rnu_1x1_bf16_rdn (__bf16 c)
{
  __riscv_ztt_i64_rnu_1x1_t d = __riscv_ztt_mbcast_m_x_i64_rnu_1x1_bf16_rdn ( __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_33_i64_rne_1x1_bf16_rup (__bf16 c)
{
  __riscv_ztt_i64_rne_1x1_t d = __riscv_ztt_mbcast_m_x_i64_rne_1x1_bf16_rup ( __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_34_i64_rdn_1x1_bf16_rmm (__bf16 c)
{
  __riscv_ztt_i64_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_i64_rdn_1x1_bf16_rmm ( __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_35_i64_rod_1x1_bf16_rno (__bf16 c)
{
  __riscv_ztt_i64_rod_1x1_t d = __riscv_ztt_mbcast_m_x_i64_rod_1x1_bf16_rno ( __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_36_u64_rnu_1x1_f32_rne (float c)
{
  __riscv_ztt_u64_rnu_1x1_t d = __riscv_ztt_mbcast_m_x_u64_rnu_1x1_f32_rne ( __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_37_u64_rne_1x1_f32_rtz (float c)
{
  __riscv_ztt_u64_rne_1x1_t d = __riscv_ztt_mbcast_m_x_u64_rne_1x1_f32_rtz ( __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_38_u64_rdn_1x1_f32_rdn (float c)
{
  __riscv_ztt_u64_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_u64_rdn_1x1_f32_rdn ( __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_39_u64_rod_1x1_f32_rup (float c)
{
  __riscv_ztt_u64_rod_1x1_t d = __riscv_ztt_mbcast_m_x_u64_rod_1x1_f32_rup ( __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_40_i4_rnu_sat_8x1_f32_rmm (float c)
{
  __riscv_ztt_i4_rnu_sat_8x1_t d = __riscv_ztt_mbcast_m_x_i4_rnu_sat_8x1_f32_rmm ( __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_41_i4_rne_sat_1x16_f32_rno (float c)
{
  __riscv_ztt_i4_rne_sat_1x16_t d = __riscv_ztt_mbcast_m_x_i4_rne_sat_1x16_f32_rno ( __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_42_i4_rdn_sat_4x1_f64_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rdn_sat_4x1_t d = __riscv_ztt_mbcast_m_x_i4_rdn_sat_4x1_f64_rne ( ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_43_i4_rod_sat_1x8_f64_rtz (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i4_rod_sat_1x8_t d = __riscv_ztt_mbcast_m_x_i4_rod_sat_1x8_f64_rtz ( ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_44_u4_rnu_sat_16x1_f64_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rnu_sat_16x1_t d = __riscv_ztt_mbcast_m_x_u4_rnu_sat_16x1_f64_rdn ( ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_45_u4_rne_sat_1x4_f64_rup (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rne_sat_1x4_t d = __riscv_ztt_mbcast_m_x_u4_rne_sat_1x4_f64_rup ( ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_46_u4_rdn_sat_8x1_f64_rmm (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rdn_sat_8x1_t d = __riscv_ztt_mbcast_m_x_u4_rdn_sat_8x1_f64_rmm ( ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_47_u4_rod_sat_1x16_f64_rno (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u4_rod_sat_1x16_t d = __riscv_ztt_mbcast_m_x_u4_rod_sat_1x16_f64_rno ( ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_48_i8_rnu_sat_2x1_f16_rne (_Float16 c)
{
  __riscv_ztt_i8_rnu_sat_2x1_t d = __riscv_ztt_mbcast_m_x_i8_rnu_sat_2x1_f16_rne ( __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_49_i8_rne_sat_1x4_f16_rtz (_Float16 c)
{
  __riscv_ztt_i8_rne_sat_1x4_t d = __riscv_ztt_mbcast_m_x_i8_rne_sat_1x4_f16_rtz ( __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_50_i8_rdn_sat_8x1_f16_rdn (_Float16 c)
{
  __riscv_ztt_i8_rdn_sat_8x1_t d = __riscv_ztt_mbcast_m_x_i8_rdn_sat_8x1_f16_rdn ( __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_51_i8_rod_sat_1x2_f16_rup (_Float16 c)
{
  __riscv_ztt_i8_rod_sat_1x2_t d = __riscv_ztt_mbcast_m_x_i8_rod_sat_1x2_f16_rup ( __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_52_u8_rnu_sat_4x1_f16_rmm (_Float16 c)
{
  __riscv_ztt_u8_rnu_sat_4x1_t d = __riscv_ztt_mbcast_m_x_u8_rnu_sat_4x1_f16_rmm ( __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_53_u8_rne_sat_1x8_f16_rno (_Float16 c)
{
  __riscv_ztt_u8_rne_sat_1x8_t d = __riscv_ztt_mbcast_m_x_u8_rne_sat_1x8_f16_rno ( __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_54_u8_rdn_sat_2x1_bf16_rne (__bf16 c)
{
  __riscv_ztt_u8_rdn_sat_2x1_t d = __riscv_ztt_mbcast_m_x_u8_rdn_sat_2x1_bf16_rne ( __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_55_u8_rod_sat_1x4_bf16_rtz (__bf16 c)
{
  __riscv_ztt_u8_rod_sat_1x4_t d = __riscv_ztt_mbcast_m_x_u8_rod_sat_1x4_bf16_rtz ( __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_56_i16_rnu_sat_4x1_bf16_rdn (__bf16 c)
{
  __riscv_ztt_i16_rnu_sat_4x1_t d = __riscv_ztt_mbcast_m_x_i16_rnu_sat_4x1_bf16_rdn ( __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_57_i16_rne_sat_1x1_bf16_rup (__bf16 c)
{
  __riscv_ztt_i16_rne_sat_1x1_t d = __riscv_ztt_mbcast_m_x_i16_rne_sat_1x1_bf16_rup ( __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_58_i16_rdn_sat_2x1_bf16_rmm (__bf16 c)
{
  __riscv_ztt_i16_rdn_sat_2x1_t d = __riscv_ztt_mbcast_m_x_i16_rdn_sat_2x1_bf16_rmm ( __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_59_i16_rod_sat_1x4_bf16_rno (__bf16 c)
{
  __riscv_ztt_i16_rod_sat_1x4_t d = __riscv_ztt_mbcast_m_x_i16_rod_sat_1x4_bf16_rno ( __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_60_u16_rnu_sat_1x1_f32_rne (float c)
{
  __riscv_ztt_u16_rnu_sat_1x1_t d = __riscv_ztt_mbcast_m_x_u16_rnu_sat_1x1_f32_rne ( __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_61_u16_rne_sat_1x2_f32_rtz (float c)
{
  __riscv_ztt_u16_rne_sat_1x2_t d = __riscv_ztt_mbcast_m_x_u16_rne_sat_1x2_f32_rtz ( __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_62_u16_rdn_sat_4x1_f32_rdn (float c)
{
  __riscv_ztt_u16_rdn_sat_4x1_t d = __riscv_ztt_mbcast_m_x_u16_rdn_sat_4x1_f32_rdn ( __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_63_u16_rod_sat_1x1_f32_rup (float c)
{
  __riscv_ztt_u16_rod_sat_1x1_t d = __riscv_ztt_mbcast_m_x_u16_rod_sat_1x1_f32_rup ( __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_64_i32_rnu_sat_2x1_f32_rmm (float c)
{
  __riscv_ztt_i32_rnu_sat_2x1_t d = __riscv_ztt_mbcast_m_x_i32_rnu_sat_2x1_f32_rmm ( __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_65_i32_rne_sat_1x2_f32_rno (float c)
{
  __riscv_ztt_i32_rne_sat_1x2_t d = __riscv_ztt_mbcast_m_x_i32_rne_sat_1x2_f32_rno ( __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_66_i32_rdn_sat_1x1_f64_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mbcast_m_x_i32_rdn_sat_1x1_f64_rne ( ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_67_i32_rod_sat_1x2_f64_rtz (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i32_rod_sat_1x2_t d = __riscv_ztt_mbcast_m_x_i32_rod_sat_1x2_f64_rtz ( ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_68_u32_rnu_sat_2x1_f64_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rnu_sat_2x1_t d = __riscv_ztt_mbcast_m_x_u32_rnu_sat_2x1_f64_rdn ( ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_69_u32_rne_sat_1x1_f64_rup (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mbcast_m_x_u32_rne_sat_1x1_f64_rup ( ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_70_u32_rdn_sat_2x1_f64_rmm (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rdn_sat_2x1_t d = __riscv_ztt_mbcast_m_x_u32_rdn_sat_2x1_f64_rmm ( ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_71_u32_rod_sat_1x2_f64_rno (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u32_rod_sat_1x2_t d = __riscv_ztt_mbcast_m_x_u32_rod_sat_1x2_f64_rno ( ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_72_i64_rnu_sat_1x1_f16_rne (_Float16 c)
{
  __riscv_ztt_i64_rnu_sat_1x1_t d = __riscv_ztt_mbcast_m_x_i64_rnu_sat_1x1_f16_rne ( __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_73_i64_rne_sat_1x1_f16_rtz (_Float16 c)
{
  __riscv_ztt_i64_rne_sat_1x1_t d = __riscv_ztt_mbcast_m_x_i64_rne_sat_1x1_f16_rtz ( __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_74_i64_rdn_sat_1x1_f16_rdn (_Float16 c)
{
  __riscv_ztt_i64_rdn_sat_1x1_t d = __riscv_ztt_mbcast_m_x_i64_rdn_sat_1x1_f16_rdn ( __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_75_i64_rod_sat_1x1_f16_rup (_Float16 c)
{
  __riscv_ztt_i64_rod_sat_1x1_t d = __riscv_ztt_mbcast_m_x_i64_rod_sat_1x1_f16_rup ( __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_76_u64_rnu_sat_1x1_f16_rmm (_Float16 c)
{
  __riscv_ztt_u64_rnu_sat_1x1_t d = __riscv_ztt_mbcast_m_x_u64_rnu_sat_1x1_f16_rmm ( __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_77_u64_rne_sat_1x1_f16_rno (_Float16 c)
{
  __riscv_ztt_u64_rne_sat_1x1_t d = __riscv_ztt_mbcast_m_x_u64_rne_sat_1x1_f16_rno ( __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_78_u64_rdn_sat_1x1_bf16_rne (__bf16 c)
{
  __riscv_ztt_u64_rdn_sat_1x1_t d = __riscv_ztt_mbcast_m_x_u64_rdn_sat_1x1_bf16_rne ( __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_79_u64_rod_sat_1x1_bf16_rtz (__bf16 c)
{
  __riscv_ztt_u64_rod_sat_1x1_t d = __riscv_ztt_mbcast_m_x_u64_rod_sat_1x1_bf16_rtz ( __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_80_f16_rne_4x1_f16_rne (_Float16 c)
{
  __riscv_ztt_f16_rne_4x1_t d = __riscv_ztt_mbcast_m_x_f16_rne_4x1_f16_rne ( __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_81_f16_rtz_1x1_f16_rtz (_Float16 c)
{
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rtz_1x1_f16_rtz ( __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_82_f16_rdn_2x1_f16_rdn (_Float16 c)
{
  __riscv_ztt_f16_rdn_2x1_t d = __riscv_ztt_mbcast_m_x_f16_rdn_2x1_f16_rdn ( __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_83_f16_rup_1x4_f16_rup (_Float16 c)
{
  __riscv_ztt_f16_rup_1x4_t d = __riscv_ztt_mbcast_m_x_f16_rup_1x4_f16_rup ( __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_84_f16_rmm_1x1_f16_rmm (_Float16 c)
{
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rmm_1x1_f16_rmm ( __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_85_f16_rno_1x2_f16_rno (_Float16 c)
{
  __riscv_ztt_f16_rno_1x2_t d = __riscv_ztt_mbcast_m_x_f16_rno_1x2_f16_rno ( __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_86_bf16_rne_4x1_bf16_rne (__bf16 c)
{
  __riscv_ztt_bf16_rne_4x1_t d = __riscv_ztt_mbcast_m_x_bf16_rne_4x1_bf16_rne ( __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_87_bf16_rtz_1x1_bf16_rtz (__bf16 c)
{
  __riscv_ztt_bf16_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rtz_1x1_bf16_rtz ( __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_88_bf16_rdn_2x1_bf16_rdn (__bf16 c)
{
  __riscv_ztt_bf16_rdn_2x1_t d = __riscv_ztt_mbcast_m_x_bf16_rdn_2x1_bf16_rdn ( __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_89_bf16_rup_1x4_bf16_rup (__bf16 c)
{
  __riscv_ztt_bf16_rup_1x4_t d = __riscv_ztt_mbcast_m_x_bf16_rup_1x4_bf16_rup ( __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_90_bf16_rmm_1x1_bf16_rmm (__bf16 c)
{
  __riscv_ztt_bf16_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rmm_1x1_bf16_rmm ( __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_91_bf16_rno_1x2_bf16_rno (__bf16 c)
{
  __riscv_ztt_bf16_rno_1x2_t d = __riscv_ztt_mbcast_m_x_bf16_rno_1x2_bf16_rno ( __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_92_f32_rne_2x1_f32_rne (float c)
{
  __riscv_ztt_f32_rne_2x1_t d = __riscv_ztt_mbcast_m_x_f32_rne_2x1_f32_rne ( __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_93_f32_rtz_1x1_f32_rtz (float c)
{
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rtz_1x1_f32_rtz ( __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_94_f32_rdn_2x1_f32_rdn (float c)
{
  __riscv_ztt_f32_rdn_2x1_t d = __riscv_ztt_mbcast_m_x_f32_rdn_2x1_f32_rdn ( __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_95_f32_rup_1x2_f32_rup (float c)
{
  __riscv_ztt_f32_rup_1x2_t d = __riscv_ztt_mbcast_m_x_f32_rup_1x2_f32_rup ( __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_96_f32_rmm_1x1_f32_rmm (float c)
{
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rmm_1x1_f32_rmm ( __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_97_f32_rno_1x2_f32_rno (float c)
{
  __riscv_ztt_f32_rno_1x2_t d = __riscv_ztt_mbcast_m_x_f32_rno_1x2_f32_rno ( __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_98_f64_rne_1x1_f64_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f64_rne_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rne_1x1_f64_rne ( ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_99_f64_rtz_1x1_f64_rtz (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f64_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rtz_1x1_f64_rtz ( ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_100_f64_rdn_1x1_f64_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f64_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rdn_1x1_f64_rdn ( ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_101_f64_rup_1x1_f64_rup (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f64_rup_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rup_1x1_f64_rup ( ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_102_f64_rmm_1x1_f64_rmm (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f64_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rmm_1x1_f64_rmm ( ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_103_f64_rno_1x1_f64_rno (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f64_rno_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rno_1x1_f64_rno ( ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_104_f16_rne_4x1_i8_rnu (carrier_i8 c)
{
  __riscv_ztt_f16_rne_4x1_t d = __riscv_ztt_mbcast_m_x_f16_rne_4x1_i8_rnu ( __riscv_ztt_scalar_make_i8_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_105_f16_rtz_1x1_i8_rne (carrier_i8 c)
{
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rtz_1x1_i8_rne ( __riscv_ztt_scalar_make_i8_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_106_f16_rdn_2x1_i8_rdn (carrier_i8 c)
{
  __riscv_ztt_f16_rdn_2x1_t d = __riscv_ztt_mbcast_m_x_f16_rdn_2x1_i8_rdn ( __riscv_ztt_scalar_make_i8_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_107_f16_rup_1x4_i8_rod (carrier_i8 c)
{
  __riscv_ztt_f16_rup_1x4_t d = __riscv_ztt_mbcast_m_x_f16_rup_1x4_i8_rod ( __riscv_ztt_scalar_make_i8_rod (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_108_f16_rmm_1x1_u8_rnu (carrier_u8 c)
{
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rmm_1x1_u8_rnu ( __riscv_ztt_scalar_make_u8_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_109_f16_rno_1x2_u8_rne (carrier_u8 c)
{
  __riscv_ztt_f16_rno_1x2_t d = __riscv_ztt_mbcast_m_x_f16_rno_1x2_u8_rne ( __riscv_ztt_scalar_make_u8_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_110_bf16_rne_4x1_u8_rdn (carrier_u8 c)
{
  __riscv_ztt_bf16_rne_4x1_t d = __riscv_ztt_mbcast_m_x_bf16_rne_4x1_u8_rdn ( __riscv_ztt_scalar_make_u8_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_111_bf16_rtz_1x1_u8_rod (carrier_u8 c)
{
  __riscv_ztt_bf16_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rtz_1x1_u8_rod ( __riscv_ztt_scalar_make_u8_rod (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_112_bf16_rdn_2x1_i16_rnu (carrier_i16 c)
{
  __riscv_ztt_bf16_rdn_2x1_t d = __riscv_ztt_mbcast_m_x_bf16_rdn_2x1_i16_rnu ( __riscv_ztt_scalar_make_i16_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_113_bf16_rup_1x4_i16_rne (carrier_i16 c)
{
  __riscv_ztt_bf16_rup_1x4_t d = __riscv_ztt_mbcast_m_x_bf16_rup_1x4_i16_rne ( __riscv_ztt_scalar_make_i16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_114_bf16_rmm_1x1_i16_rdn (carrier_i16 c)
{
  __riscv_ztt_bf16_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rmm_1x1_i16_rdn ( __riscv_ztt_scalar_make_i16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_115_bf16_rno_1x2_i16_rod (carrier_i16 c)
{
  __riscv_ztt_bf16_rno_1x2_t d = __riscv_ztt_mbcast_m_x_bf16_rno_1x2_i16_rod ( __riscv_ztt_scalar_make_i16_rod (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_116_f32_rne_2x1_u16_rnu (carrier_u16 c)
{
  __riscv_ztt_f32_rne_2x1_t d = __riscv_ztt_mbcast_m_x_f32_rne_2x1_u16_rnu ( __riscv_ztt_scalar_make_u16_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_117_f32_rtz_1x1_u16_rne (carrier_u16 c)
{
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rtz_1x1_u16_rne ( __riscv_ztt_scalar_make_u16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_118_f32_rdn_2x1_u16_rdn (carrier_u16 c)
{
  __riscv_ztt_f32_rdn_2x1_t d = __riscv_ztt_mbcast_m_x_f32_rdn_2x1_u16_rdn ( __riscv_ztt_scalar_make_u16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_119_f32_rup_1x2_u16_rod (carrier_u16 c)
{
  __riscv_ztt_f32_rup_1x2_t d = __riscv_ztt_mbcast_m_x_f32_rup_1x2_u16_rod ( __riscv_ztt_scalar_make_u16_rod (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_120_f32_rmm_1x1_i32_rnu (carrier_i32 c)
{
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rmm_1x1_i32_rnu ( __riscv_ztt_scalar_make_i32_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_121_f32_rno_1x2_i32_rne (carrier_i32 c)
{
  __riscv_ztt_f32_rno_1x2_t d = __riscv_ztt_mbcast_m_x_f32_rno_1x2_i32_rne ( __riscv_ztt_scalar_make_i32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_122_f64_rne_1x1_i32_rdn (carrier_i32 c)
{
  __riscv_ztt_f64_rne_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rne_1x1_i32_rdn ( __riscv_ztt_scalar_make_i32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_123_f64_rtz_1x1_i32_rod (carrier_i32 c)
{
  __riscv_ztt_f64_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rtz_1x1_i32_rod ( __riscv_ztt_scalar_make_i32_rod (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_124_f64_rdn_1x1_u32_rnu (carrier_u32 c)
{
  __riscv_ztt_f64_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rdn_1x1_u32_rnu ( __riscv_ztt_scalar_make_u32_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_125_f64_rup_1x1_u32_rne (carrier_u32 c)
{
  __riscv_ztt_f64_rup_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rup_1x1_u32_rne ( __riscv_ztt_scalar_make_u32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_126_f64_rmm_1x1_u32_rdn (carrier_u32 c)
{
  __riscv_ztt_f64_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rmm_1x1_u32_rdn ( __riscv_ztt_scalar_make_u32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_127_f64_rno_1x1_u32_rod (carrier_u32 c)
{
  __riscv_ztt_f64_rno_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rno_1x1_u32_rod ( __riscv_ztt_scalar_make_u32_rod (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_128_f16_rne_4x1_i64_rnu (carrier_i64 c)
{
  __riscv_ztt_f16_rne_4x1_t d = __riscv_ztt_mbcast_m_x_f16_rne_4x1_i64_rnu ( __riscv_ztt_scalar_from_bits_i64_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_129_f16_rtz_1x1_i64_rne (carrier_i64 c)
{
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rtz_1x1_i64_rne ( __riscv_ztt_scalar_from_bits_i64_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_130_f16_rdn_2x1_i64_rdn (carrier_i64 c)
{
  __riscv_ztt_f16_rdn_2x1_t d = __riscv_ztt_mbcast_m_x_f16_rdn_2x1_i64_rdn ( __riscv_ztt_scalar_from_bits_i64_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_131_f16_rup_1x4_i64_rod (carrier_i64 c)
{
  __riscv_ztt_f16_rup_1x4_t d = __riscv_ztt_mbcast_m_x_f16_rup_1x4_i64_rod ( __riscv_ztt_scalar_from_bits_i64_rod (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_132_f16_rmm_1x1_u64_rnu (carrier_u64 c)
{
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rmm_1x1_u64_rnu ( __riscv_ztt_scalar_from_bits_u64_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_133_f16_rno_1x2_u64_rne (carrier_u64 c)
{
  __riscv_ztt_f16_rno_1x2_t d = __riscv_ztt_mbcast_m_x_f16_rno_1x2_u64_rne ( __riscv_ztt_scalar_from_bits_u64_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_134_bf16_rne_4x1_u64_rdn (carrier_u64 c)
{
  __riscv_ztt_bf16_rne_4x1_t d = __riscv_ztt_mbcast_m_x_bf16_rne_4x1_u64_rdn ( __riscv_ztt_scalar_from_bits_u64_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_135_bf16_rtz_1x1_u64_rod (carrier_u64 c)
{
  __riscv_ztt_bf16_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rtz_1x1_u64_rod ( __riscv_ztt_scalar_from_bits_u64_rod (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_136_bf16_rdn_2x1_i128_rnu (carrier_i128 c)
{
  __riscv_ztt_bf16_rdn_2x1_t d = __riscv_ztt_mbcast_m_x_bf16_rdn_2x1_i128_rnu ( __riscv_ztt_scalar_from_bits_i128_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_137_bf16_rup_1x4_i128_rne (carrier_i128 c)
{
  __riscv_ztt_bf16_rup_1x4_t d = __riscv_ztt_mbcast_m_x_bf16_rup_1x4_i128_rne ( __riscv_ztt_scalar_from_bits_i128_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_138_bf16_rmm_1x1_i128_rdn (carrier_i128 c)
{
  __riscv_ztt_bf16_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rmm_1x1_i128_rdn ( __riscv_ztt_scalar_from_bits_i128_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_139_bf16_rno_1x2_i128_rod (carrier_i128 c)
{
  __riscv_ztt_bf16_rno_1x2_t d = __riscv_ztt_mbcast_m_x_bf16_rno_1x2_i128_rod ( __riscv_ztt_scalar_from_bits_i128_rod (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_140_f32_rne_2x1_u128_rnu (carrier_u128 c)
{
  __riscv_ztt_f32_rne_2x1_t d = __riscv_ztt_mbcast_m_x_f32_rne_2x1_u128_rnu ( __riscv_ztt_scalar_from_bits_u128_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_141_f32_rtz_1x1_u128_rne (carrier_u128 c)
{
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rtz_1x1_u128_rne ( __riscv_ztt_scalar_from_bits_u128_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_142_f32_rdn_2x1_u128_rdn (carrier_u128 c)
{
  __riscv_ztt_f32_rdn_2x1_t d = __riscv_ztt_mbcast_m_x_f32_rdn_2x1_u128_rdn ( __riscv_ztt_scalar_from_bits_u128_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_143_f32_rup_1x2_u128_rod (carrier_u128 c)
{
  __riscv_ztt_f32_rup_1x2_t d = __riscv_ztt_mbcast_m_x_f32_rup_1x2_u128_rod ( __riscv_ztt_scalar_from_bits_u128_rod (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_144_f32_rmm_1x1_i8_rnu_sat (carrier_i8 c)
{
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rmm_1x1_i8_rnu_sat ( __riscv_ztt_scalar_make_i8_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_145_f32_rno_1x2_i8_rne_sat (carrier_i8 c)
{
  __riscv_ztt_f32_rno_1x2_t d = __riscv_ztt_mbcast_m_x_f32_rno_1x2_i8_rne_sat ( __riscv_ztt_scalar_make_i8_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_146_f64_rne_1x1_i8_rdn_sat (carrier_i8 c)
{
  __riscv_ztt_f64_rne_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rne_1x1_i8_rdn_sat ( __riscv_ztt_scalar_make_i8_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_147_f64_rtz_1x1_i8_rod_sat (carrier_i8 c)
{
  __riscv_ztt_f64_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rtz_1x1_i8_rod_sat ( __riscv_ztt_scalar_make_i8_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_148_f64_rdn_1x1_u8_rnu_sat (carrier_u8 c)
{
  __riscv_ztt_f64_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rdn_1x1_u8_rnu_sat ( __riscv_ztt_scalar_make_u8_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_149_f64_rup_1x1_u8_rne_sat (carrier_u8 c)
{
  __riscv_ztt_f64_rup_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rup_1x1_u8_rne_sat ( __riscv_ztt_scalar_make_u8_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_150_f64_rmm_1x1_u8_rdn_sat (carrier_u8 c)
{
  __riscv_ztt_f64_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rmm_1x1_u8_rdn_sat ( __riscv_ztt_scalar_make_u8_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_151_f64_rno_1x1_u8_rod_sat (carrier_u8 c)
{
  __riscv_ztt_f64_rno_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rno_1x1_u8_rod_sat ( __riscv_ztt_scalar_make_u8_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_152_f16_rne_4x1_i16_rnu_sat (carrier_i16 c)
{
  __riscv_ztt_f16_rne_4x1_t d = __riscv_ztt_mbcast_m_x_f16_rne_4x1_i16_rnu_sat ( __riscv_ztt_scalar_make_i16_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_153_f16_rtz_1x1_i16_rne_sat (carrier_i16 c)
{
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rtz_1x1_i16_rne_sat ( __riscv_ztt_scalar_make_i16_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_154_f16_rdn_2x1_i16_rdn_sat (carrier_i16 c)
{
  __riscv_ztt_f16_rdn_2x1_t d = __riscv_ztt_mbcast_m_x_f16_rdn_2x1_i16_rdn_sat ( __riscv_ztt_scalar_make_i16_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_155_f16_rup_1x4_i16_rod_sat (carrier_i16 c)
{
  __riscv_ztt_f16_rup_1x4_t d = __riscv_ztt_mbcast_m_x_f16_rup_1x4_i16_rod_sat ( __riscv_ztt_scalar_make_i16_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_156_f16_rmm_1x1_u16_rnu_sat (carrier_u16 c)
{
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rmm_1x1_u16_rnu_sat ( __riscv_ztt_scalar_make_u16_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_157_f16_rno_1x2_u16_rne_sat (carrier_u16 c)
{
  __riscv_ztt_f16_rno_1x2_t d = __riscv_ztt_mbcast_m_x_f16_rno_1x2_u16_rne_sat ( __riscv_ztt_scalar_make_u16_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_158_bf16_rne_4x1_u16_rdn_sat (carrier_u16 c)
{
  __riscv_ztt_bf16_rne_4x1_t d = __riscv_ztt_mbcast_m_x_bf16_rne_4x1_u16_rdn_sat ( __riscv_ztt_scalar_make_u16_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_159_bf16_rtz_1x1_u16_rod_sat (carrier_u16 c)
{
  __riscv_ztt_bf16_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rtz_1x1_u16_rod_sat ( __riscv_ztt_scalar_make_u16_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_160_bf16_rdn_2x1_i32_rnu_sat (carrier_i32 c)
{
  __riscv_ztt_bf16_rdn_2x1_t d = __riscv_ztt_mbcast_m_x_bf16_rdn_2x1_i32_rnu_sat ( __riscv_ztt_scalar_make_i32_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_161_bf16_rup_1x4_i32_rne_sat (carrier_i32 c)
{
  __riscv_ztt_bf16_rup_1x4_t d = __riscv_ztt_mbcast_m_x_bf16_rup_1x4_i32_rne_sat ( __riscv_ztt_scalar_make_i32_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_162_bf16_rmm_1x1_i32_rdn_sat (carrier_i32 c)
{
  __riscv_ztt_bf16_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rmm_1x1_i32_rdn_sat ( __riscv_ztt_scalar_make_i32_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_163_bf16_rno_1x2_i32_rod_sat (carrier_i32 c)
{
  __riscv_ztt_bf16_rno_1x2_t d = __riscv_ztt_mbcast_m_x_bf16_rno_1x2_i32_rod_sat ( __riscv_ztt_scalar_make_i32_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_164_f32_rne_2x1_u32_rnu_sat (carrier_u32 c)
{
  __riscv_ztt_f32_rne_2x1_t d = __riscv_ztt_mbcast_m_x_f32_rne_2x1_u32_rnu_sat ( __riscv_ztt_scalar_make_u32_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_165_f32_rtz_1x1_u32_rne_sat (carrier_u32 c)
{
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rtz_1x1_u32_rne_sat ( __riscv_ztt_scalar_make_u32_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_166_f32_rdn_2x1_u32_rdn_sat (carrier_u32 c)
{
  __riscv_ztt_f32_rdn_2x1_t d = __riscv_ztt_mbcast_m_x_f32_rdn_2x1_u32_rdn_sat ( __riscv_ztt_scalar_make_u32_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_167_f32_rup_1x2_u32_rod_sat (carrier_u32 c)
{
  __riscv_ztt_f32_rup_1x2_t d = __riscv_ztt_mbcast_m_x_f32_rup_1x2_u32_rod_sat ( __riscv_ztt_scalar_make_u32_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_168_f32_rmm_1x1_i64_rnu_sat (carrier_i64 c)
{
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rmm_1x1_i64_rnu_sat ( __riscv_ztt_scalar_from_bits_i64_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_169_f32_rno_1x2_i64_rne_sat (carrier_i64 c)
{
  __riscv_ztt_f32_rno_1x2_t d = __riscv_ztt_mbcast_m_x_f32_rno_1x2_i64_rne_sat ( __riscv_ztt_scalar_from_bits_i64_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_170_f64_rne_1x1_i64_rdn_sat (carrier_i64 c)
{
  __riscv_ztt_f64_rne_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rne_1x1_i64_rdn_sat ( __riscv_ztt_scalar_from_bits_i64_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_171_f64_rtz_1x1_i64_rod_sat (carrier_i64 c)
{
  __riscv_ztt_f64_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rtz_1x1_i64_rod_sat ( __riscv_ztt_scalar_from_bits_i64_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_172_f64_rdn_1x1_u64_rnu_sat (carrier_u64 c)
{
  __riscv_ztt_f64_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rdn_1x1_u64_rnu_sat ( __riscv_ztt_scalar_from_bits_u64_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_173_f64_rup_1x1_u64_rne_sat (carrier_u64 c)
{
  __riscv_ztt_f64_rup_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rup_1x1_u64_rne_sat ( __riscv_ztt_scalar_from_bits_u64_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_174_f64_rmm_1x1_u64_rdn_sat (carrier_u64 c)
{
  __riscv_ztt_f64_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rmm_1x1_u64_rdn_sat ( __riscv_ztt_scalar_from_bits_u64_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_175_f64_rno_1x1_u64_rod_sat (carrier_u64 c)
{
  __riscv_ztt_f64_rno_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rno_1x1_u64_rod_sat ( __riscv_ztt_scalar_from_bits_u64_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_176_f16_rne_4x1_i128_rnu_sat (carrier_i128 c)
{
  __riscv_ztt_f16_rne_4x1_t d = __riscv_ztt_mbcast_m_x_f16_rne_4x1_i128_rnu_sat ( __riscv_ztt_scalar_from_bits_i128_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_177_f16_rtz_1x1_i128_rne_sat (carrier_i128 c)
{
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rtz_1x1_i128_rne_sat ( __riscv_ztt_scalar_from_bits_i128_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_178_f16_rdn_2x1_i128_rdn_sat (carrier_i128 c)
{
  __riscv_ztt_f16_rdn_2x1_t d = __riscv_ztt_mbcast_m_x_f16_rdn_2x1_i128_rdn_sat ( __riscv_ztt_scalar_from_bits_i128_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_179_f16_rup_1x4_i128_rod_sat (carrier_i128 c)
{
  __riscv_ztt_f16_rup_1x4_t d = __riscv_ztt_mbcast_m_x_f16_rup_1x4_i128_rod_sat ( __riscv_ztt_scalar_from_bits_i128_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_180_f16_rmm_1x1_u128_rnu_sat (carrier_u128 c)
{
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rmm_1x1_u128_rnu_sat ( __riscv_ztt_scalar_from_bits_u128_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_181_f16_rno_1x2_u128_rne_sat (carrier_u128 c)
{
  __riscv_ztt_f16_rno_1x2_t d = __riscv_ztt_mbcast_m_x_f16_rno_1x2_u128_rne_sat ( __riscv_ztt_scalar_from_bits_u128_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_182_bf16_rne_4x1_u128_rdn_sat (carrier_u128 c)
{
  __riscv_ztt_bf16_rne_4x1_t d = __riscv_ztt_mbcast_m_x_bf16_rne_4x1_u128_rdn_sat ( __riscv_ztt_scalar_from_bits_u128_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_183_bf16_rtz_1x1_u128_rod_sat (carrier_u128 c)
{
  __riscv_ztt_bf16_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rtz_1x1_u128_rod_sat ( __riscv_ztt_scalar_from_bits_u128_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_184_bf16_rdn_2x1_f16_rne (_Float16 c)
{
  __riscv_ztt_bf16_rdn_2x1_t d = __riscv_ztt_mbcast_m_x_bf16_rdn_2x1_f16_rne ( __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_185_bf16_rup_1x4_f16_rtz (_Float16 c)
{
  __riscv_ztt_bf16_rup_1x4_t d = __riscv_ztt_mbcast_m_x_bf16_rup_1x4_f16_rtz ( __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_186_bf16_rmm_1x1_f16_rdn (_Float16 c)
{
  __riscv_ztt_bf16_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rmm_1x1_f16_rdn ( __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_187_bf16_rno_1x2_f16_rup (_Float16 c)
{
  __riscv_ztt_bf16_rno_1x2_t d = __riscv_ztt_mbcast_m_x_bf16_rno_1x2_f16_rup ( __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_188_f32_rne_2x1_f16_rmm (_Float16 c)
{
  __riscv_ztt_f32_rne_2x1_t d = __riscv_ztt_mbcast_m_x_f32_rne_2x1_f16_rmm ( __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_189_f32_rtz_1x1_f16_rno (_Float16 c)
{
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rtz_1x1_f16_rno ( __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_190_f32_rdn_2x1_bf16_rne (__bf16 c)
{
  __riscv_ztt_f32_rdn_2x1_t d = __riscv_ztt_mbcast_m_x_f32_rdn_2x1_bf16_rne ( __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_191_f32_rup_1x2_bf16_rtz (__bf16 c)
{
  __riscv_ztt_f32_rup_1x2_t d = __riscv_ztt_mbcast_m_x_f32_rup_1x2_bf16_rtz ( __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_192_f32_rmm_1x1_bf16_rdn (__bf16 c)
{
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rmm_1x1_bf16_rdn ( __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_193_f32_rno_1x2_bf16_rup (__bf16 c)
{
  __riscv_ztt_f32_rno_1x2_t d = __riscv_ztt_mbcast_m_x_f32_rno_1x2_bf16_rup ( __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_194_f64_rne_1x1_bf16_rmm (__bf16 c)
{
  __riscv_ztt_f64_rne_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rne_1x1_bf16_rmm ( __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_195_f64_rtz_1x1_bf16_rno (__bf16 c)
{
  __riscv_ztt_f64_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rtz_1x1_bf16_rno ( __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_196_f64_rdn_1x1_f32_rne (float c)
{
  __riscv_ztt_f64_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rdn_1x1_f32_rne ( __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_197_f64_rup_1x1_f32_rtz (float c)
{
  __riscv_ztt_f64_rup_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rup_1x1_f32_rtz ( __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_198_f64_rmm_1x1_f32_rdn (float c)
{
  __riscv_ztt_f64_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rmm_1x1_f32_rdn ( __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_199_f64_rno_1x1_f32_rup (float c)
{
  __riscv_ztt_f64_rno_1x1_t d = __riscv_ztt_mbcast_m_x_f64_rno_1x1_f32_rup ( __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_200_f16_rne_4x1_f32_rmm (float c)
{
  __riscv_ztt_f16_rne_4x1_t d = __riscv_ztt_mbcast_m_x_f16_rne_4x1_f32_rmm ( __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_201_f16_rtz_1x1_f32_rno (float c)
{
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rtz_1x1_f32_rno ( __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_202_f16_rdn_2x1_f64_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f16_rdn_2x1_t d = __riscv_ztt_mbcast_m_x_f16_rdn_2x1_f64_rne ( ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_203_f16_rup_1x4_f64_rtz (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f16_rup_1x4_t d = __riscv_ztt_mbcast_m_x_f16_rup_1x4_f64_rtz ( ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_204_f16_rmm_1x1_f64_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rmm_1x1_f64_rdn ( ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_205_f16_rno_1x2_f64_rup (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f16_rno_1x2_t d = __riscv_ztt_mbcast_m_x_f16_rno_1x2_f64_rup ( ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_206_bf16_rne_4x1_f64_rmm (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rne_4x1_t d = __riscv_ztt_mbcast_m_x_bf16_rne_4x1_f64_rmm ( ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_207_bf16_rtz_1x1_f64_rno (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rtz_1x1_f64_rno ( ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
#ifdef __cplusplus
}
#endif
