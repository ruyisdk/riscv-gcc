/* Floating/mixed broadcast contracts, not numerical execution.  */
/* { dg-do assemble } */
/* { dg-options "-O0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv32 } } */
/* { dg-options "-O0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv64 } } */
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
#if __riscv_ztt_floating_broadcast != 1
#error missing capability
#endif
#ifdef __cplusplus
extern "C" {
#endif
void bcast_0_i4_rnu_2x1_f16_rne (_Float16 c)
{
  __riscv_ztt_i4_rnu_2x1_t d = __riscv_ztt_mbcast_m_x_i4_rnu_2x1_f16_rne ( __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_1_i4_rne_1x4_f16_rtz (_Float16 c)
{
  __riscv_ztt_i4_rne_1x4_t d = __riscv_ztt_mbcast_m_x_i4_rne_1x4_f16_rtz ( __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_2_i4_rdn_8x1_f16_rdn (_Float16 c)
{
  __riscv_ztt_i4_rdn_8x1_t d = __riscv_ztt_mbcast_m_x_i4_rdn_8x1_f16_rdn ( __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_3_i4_rod_1x2_f16_rup (_Float16 c)
{
  __riscv_ztt_i4_rod_1x2_t d = __riscv_ztt_mbcast_m_x_i4_rod_1x2_f16_rup ( __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_4_u4_rnu_4x1_f16_rmm (_Float16 c)
{
  __riscv_ztt_u4_rnu_4x1_t d = __riscv_ztt_mbcast_m_x_u4_rnu_4x1_f16_rmm ( __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_5_u4_rne_1x8_f16_rno (_Float16 c)
{
  __riscv_ztt_u4_rne_1x8_t d = __riscv_ztt_mbcast_m_x_u4_rne_1x8_f16_rno ( __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_6_u4_rdn_2x1_bf16_rne (__bf16 c)
{
  __riscv_ztt_u4_rdn_2x1_t d = __riscv_ztt_mbcast_m_x_u4_rdn_2x1_bf16_rne ( __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_7_u4_rod_1x4_bf16_rtz (__bf16 c)
{
  __riscv_ztt_u4_rod_1x4_t d = __riscv_ztt_mbcast_m_x_u4_rod_1x4_bf16_rtz ( __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_8_i8_rnu_4x1_bf16_rdn (__bf16 c)
{
  __riscv_ztt_i8_rnu_4x1_t d = __riscv_ztt_mbcast_m_x_i8_rnu_4x1_bf16_rdn ( __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_9_i8_rne_1x1_bf16_rup (__bf16 c)
{
  __riscv_ztt_i8_rne_1x1_t d = __riscv_ztt_mbcast_m_x_i8_rne_1x1_bf16_rup ( __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_10_i8_rdn_2x1_bf16_rmm (__bf16 c)
{
  __riscv_ztt_i8_rdn_2x1_t d = __riscv_ztt_mbcast_m_x_i8_rdn_2x1_bf16_rmm ( __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_11_i8_rod_1x4_bf16_rno (__bf16 c)
{
  __riscv_ztt_i8_rod_1x4_t d = __riscv_ztt_mbcast_m_x_i8_rod_1x4_bf16_rno ( __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_12_u8_rnu_1x1_f32_rne (float c)
{
  __riscv_ztt_u8_rnu_1x1_t d = __riscv_ztt_mbcast_m_x_u8_rnu_1x1_f32_rne ( __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_13_u8_rne_1x2_f32_rtz (float c)
{
  __riscv_ztt_u8_rne_1x2_t d = __riscv_ztt_mbcast_m_x_u8_rne_1x2_f32_rtz ( __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_14_u8_rdn_4x1_f32_rdn (float c)
{
  __riscv_ztt_u8_rdn_4x1_t d = __riscv_ztt_mbcast_m_x_u8_rdn_4x1_f32_rdn ( __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_15_u8_rod_1x1_f32_rup (float c)
{
  __riscv_ztt_u8_rod_1x1_t d = __riscv_ztt_mbcast_m_x_u8_rod_1x1_f32_rup ( __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_16_i16_rnu_2x1_f32_rmm (float c)
{
  __riscv_ztt_i16_rnu_2x1_t d = __riscv_ztt_mbcast_m_x_i16_rnu_2x1_f32_rmm ( __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_17_i16_rne_1x2_f32_rno (float c)
{
  __riscv_ztt_i16_rne_1x2_t d = __riscv_ztt_mbcast_m_x_i16_rne_1x2_f32_rno ( __riscv_ztt_scalar_make_f32_rno (c));
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
void bcast_20_u16_rnu_2x1_f64_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rnu_2x1_t d = __riscv_ztt_mbcast_m_x_u16_rnu_2x1_f64_rdn ( ZTT_TEST_F64(rdn, c));
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
void bcast_23_u16_rod_1x2_f64_rno (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u16_rod_1x2_t d = __riscv_ztt_mbcast_m_x_u16_rod_1x2_f64_rno ( ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_24_i32_rnu_1x1_f16_rne (_Float16 c)
{
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mbcast_m_x_i32_rnu_1x1_f16_rne ( __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_25_i32_rne_1x1_f16_rtz (_Float16 c)
{
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_mbcast_m_x_i32_rne_1x1_f16_rtz ( __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_26_i32_rdn_1x1_f16_rdn (_Float16 c)
{
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_i32_rdn_1x1_f16_rdn ( __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_27_i32_rod_1x1_f16_rup (_Float16 c)
{
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mbcast_m_x_i32_rod_1x1_f16_rup ( __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_28_u32_rnu_1x1_f16_rmm (_Float16 c)
{
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mbcast_m_x_u32_rnu_1x1_f16_rmm ( __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_29_u32_rne_1x1_f16_rno (_Float16 c)
{
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_mbcast_m_x_u32_rne_1x1_f16_rno ( __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_30_u32_rdn_1x1_bf16_rne (__bf16 c)
{
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_u32_rdn_1x1_bf16_rne ( __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_31_u32_rod_1x1_bf16_rtz (__bf16 c)
{
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_mbcast_m_x_u32_rod_1x1_bf16_rtz ( __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_32_i4_rnu_sat_8x1_bf16_rdn (__bf16 c)
{
  __riscv_ztt_i4_rnu_sat_8x1_t d = __riscv_ztt_mbcast_m_x_i4_rnu_sat_8x1_bf16_rdn ( __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_33_i4_rne_sat_1x2_bf16_rup (__bf16 c)
{
  __riscv_ztt_i4_rne_sat_1x2_t d = __riscv_ztt_mbcast_m_x_i4_rne_sat_1x2_bf16_rup ( __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_34_i4_rdn_sat_4x1_bf16_rmm (__bf16 c)
{
  __riscv_ztt_i4_rdn_sat_4x1_t d = __riscv_ztt_mbcast_m_x_i4_rdn_sat_4x1_bf16_rmm ( __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_35_i4_rod_sat_1x8_bf16_rno (__bf16 c)
{
  __riscv_ztt_i4_rod_sat_1x8_t d = __riscv_ztt_mbcast_m_x_i4_rod_sat_1x8_bf16_rno ( __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_36_u4_rnu_sat_2x1_f32_rne (float c)
{
  __riscv_ztt_u4_rnu_sat_2x1_t d = __riscv_ztt_mbcast_m_x_u4_rnu_sat_2x1_f32_rne ( __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_37_u4_rne_sat_1x4_f32_rtz (float c)
{
  __riscv_ztt_u4_rne_sat_1x4_t d = __riscv_ztt_mbcast_m_x_u4_rne_sat_1x4_f32_rtz ( __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_38_u4_rdn_sat_8x1_f32_rdn (float c)
{
  __riscv_ztt_u4_rdn_sat_8x1_t d = __riscv_ztt_mbcast_m_x_u4_rdn_sat_8x1_f32_rdn ( __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_39_u4_rod_sat_1x2_f32_rup (float c)
{
  __riscv_ztt_u4_rod_sat_1x2_t d = __riscv_ztt_mbcast_m_x_u4_rod_sat_1x2_f32_rup ( __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_40_i8_rnu_sat_2x1_f32_rmm (float c)
{
  __riscv_ztt_i8_rnu_sat_2x1_t d = __riscv_ztt_mbcast_m_x_i8_rnu_sat_2x1_f32_rmm ( __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_41_i8_rne_sat_1x4_f32_rno (float c)
{
  __riscv_ztt_i8_rne_sat_1x4_t d = __riscv_ztt_mbcast_m_x_i8_rne_sat_1x4_f32_rno ( __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_42_i8_rdn_sat_1x1_f64_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rdn_sat_1x1_t d = __riscv_ztt_mbcast_m_x_i8_rdn_sat_1x1_f64_rne ( ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_43_i8_rod_sat_1x2_f64_rtz (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_i8_rod_sat_1x2_t d = __riscv_ztt_mbcast_m_x_i8_rod_sat_1x2_f64_rtz ( ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_44_u8_rnu_sat_4x1_f64_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rnu_sat_4x1_t d = __riscv_ztt_mbcast_m_x_u8_rnu_sat_4x1_f64_rdn ( ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_45_u8_rne_sat_1x1_f64_rup (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rne_sat_1x1_t d = __riscv_ztt_mbcast_m_x_u8_rne_sat_1x1_f64_rup ( ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_46_u8_rdn_sat_2x1_f64_rmm (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rdn_sat_2x1_t d = __riscv_ztt_mbcast_m_x_u8_rdn_sat_2x1_f64_rmm ( ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_47_u8_rod_sat_1x4_f64_rno (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_u8_rod_sat_1x4_t d = __riscv_ztt_mbcast_m_x_u8_rod_sat_1x4_f64_rno ( ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_48_i16_rnu_sat_1x1_f16_rne (_Float16 c)
{
  __riscv_ztt_i16_rnu_sat_1x1_t d = __riscv_ztt_mbcast_m_x_i16_rnu_sat_1x1_f16_rne ( __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_49_i16_rne_sat_1x2_f16_rtz (_Float16 c)
{
  __riscv_ztt_i16_rne_sat_1x2_t d = __riscv_ztt_mbcast_m_x_i16_rne_sat_1x2_f16_rtz ( __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_50_i16_rdn_sat_2x1_f16_rdn (_Float16 c)
{
  __riscv_ztt_i16_rdn_sat_2x1_t d = __riscv_ztt_mbcast_m_x_i16_rdn_sat_2x1_f16_rdn ( __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_51_i16_rod_sat_1x1_f16_rup (_Float16 c)
{
  __riscv_ztt_i16_rod_sat_1x1_t d = __riscv_ztt_mbcast_m_x_i16_rod_sat_1x1_f16_rup ( __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_52_u16_rnu_sat_2x1_f16_rmm (_Float16 c)
{
  __riscv_ztt_u16_rnu_sat_2x1_t d = __riscv_ztt_mbcast_m_x_u16_rnu_sat_2x1_f16_rmm ( __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_53_u16_rne_sat_1x2_f16_rno (_Float16 c)
{
  __riscv_ztt_u16_rne_sat_1x2_t d = __riscv_ztt_mbcast_m_x_u16_rne_sat_1x2_f16_rno ( __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_54_u16_rdn_sat_1x1_bf16_rne (__bf16 c)
{
  __riscv_ztt_u16_rdn_sat_1x1_t d = __riscv_ztt_mbcast_m_x_u16_rdn_sat_1x1_bf16_rne ( __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_55_u16_rod_sat_1x2_bf16_rtz (__bf16 c)
{
  __riscv_ztt_u16_rod_sat_1x2_t d = __riscv_ztt_mbcast_m_x_u16_rod_sat_1x2_bf16_rtz ( __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_56_i32_rnu_sat_1x1_bf16_rdn (__bf16 c)
{
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_mbcast_m_x_i32_rnu_sat_1x1_bf16_rdn ( __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_57_i32_rne_sat_1x1_bf16_rup (__bf16 c)
{
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_mbcast_m_x_i32_rne_sat_1x1_bf16_rup ( __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_58_i32_rdn_sat_1x1_bf16_rmm (__bf16 c)
{
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mbcast_m_x_i32_rdn_sat_1x1_bf16_rmm ( __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_59_i32_rod_sat_1x1_bf16_rno (__bf16 c)
{
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_mbcast_m_x_i32_rod_sat_1x1_bf16_rno ( __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_60_u32_rnu_sat_1x1_f32_rne (float c)
{
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_mbcast_m_x_u32_rnu_sat_1x1_f32_rne ( __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_61_u32_rne_sat_1x1_f32_rtz (float c)
{
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mbcast_m_x_u32_rne_sat_1x1_f32_rtz ( __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_62_u32_rdn_sat_1x1_f32_rdn (float c)
{
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_mbcast_m_x_u32_rdn_sat_1x1_f32_rdn ( __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_63_u32_rod_sat_1x1_f32_rup (float c)
{
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_mbcast_m_x_u32_rod_sat_1x1_f32_rup ( __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_64_f16_rne_2x1_i64_rnu_sat (carrier_i64 c)
{
  __riscv_ztt_f16_rne_2x1_t d = __riscv_ztt_mbcast_m_x_f16_rne_2x1_i64_rnu_sat ( __riscv_ztt_scalar_from_bits_i64_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_65_f16_rtz_1x2_i64_rne_sat (carrier_i64 c)
{
  __riscv_ztt_f16_rtz_1x2_t d = __riscv_ztt_mbcast_m_x_f16_rtz_1x2_i64_rne_sat ( __riscv_ztt_scalar_from_bits_i64_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_66_f16_rdn_1x1_i64_rdn_sat (carrier_i64 c)
{
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rdn_1x1_i64_rdn_sat ( __riscv_ztt_scalar_from_bits_i64_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_67_f16_rup_1x2_i64_rod_sat (carrier_i64 c)
{
  __riscv_ztt_f16_rup_1x2_t d = __riscv_ztt_mbcast_m_x_f16_rup_1x2_i64_rod_sat ( __riscv_ztt_scalar_from_bits_i64_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_68_f16_rmm_2x1_u64_rnu_sat (carrier_u64 c)
{
  __riscv_ztt_f16_rmm_2x1_t d = __riscv_ztt_mbcast_m_x_f16_rmm_2x1_u64_rnu_sat ( __riscv_ztt_scalar_from_bits_u64_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_69_f16_rno_1x1_u64_rne_sat (carrier_u64 c)
{
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rno_1x1_u64_rne_sat ( __riscv_ztt_scalar_from_bits_u64_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_70_bf16_rne_2x1_u64_rdn_sat (carrier_u64 c)
{
  __riscv_ztt_bf16_rne_2x1_t d = __riscv_ztt_mbcast_m_x_bf16_rne_2x1_u64_rdn_sat ( __riscv_ztt_scalar_from_bits_u64_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_71_bf16_rtz_1x2_u64_rod_sat (carrier_u64 c)
{
  __riscv_ztt_bf16_rtz_1x2_t d = __riscv_ztt_mbcast_m_x_bf16_rtz_1x2_u64_rod_sat ( __riscv_ztt_scalar_from_bits_u64_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_72_bf16_rdn_1x1_i128_rnu_sat (carrier_i128 c)
{
  __riscv_ztt_bf16_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rdn_1x1_i128_rnu_sat ( __riscv_ztt_scalar_from_bits_i128_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_73_bf16_rup_1x2_i128_rne_sat (carrier_i128 c)
{
  __riscv_ztt_bf16_rup_1x2_t d = __riscv_ztt_mbcast_m_x_bf16_rup_1x2_i128_rne_sat ( __riscv_ztt_scalar_from_bits_i128_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_74_bf16_rmm_2x1_i128_rdn_sat (carrier_i128 c)
{
  __riscv_ztt_bf16_rmm_2x1_t d = __riscv_ztt_mbcast_m_x_bf16_rmm_2x1_i128_rdn_sat ( __riscv_ztt_scalar_from_bits_i128_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_75_bf16_rno_1x1_i128_rod_sat (carrier_i128 c)
{
  __riscv_ztt_bf16_rno_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rno_1x1_i128_rod_sat ( __riscv_ztt_scalar_from_bits_i128_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_76_f32_rne_1x1_u128_rnu_sat (carrier_u128 c)
{
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rne_1x1_u128_rnu_sat ( __riscv_ztt_scalar_from_bits_u128_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_77_f32_rtz_1x1_u128_rne_sat (carrier_u128 c)
{
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rtz_1x1_u128_rne_sat ( __riscv_ztt_scalar_from_bits_u128_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_78_f32_rdn_1x1_u128_rdn_sat (carrier_u128 c)
{
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rdn_1x1_u128_rdn_sat ( __riscv_ztt_scalar_from_bits_u128_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_79_f32_rup_1x1_u128_rod_sat (carrier_u128 c)
{
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rup_1x1_u128_rod_sat ( __riscv_ztt_scalar_from_bits_u128_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_80_f32_rmm_1x1_f16_rne (_Float16 c)
{
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rmm_1x1_f16_rne ( __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_81_f32_rno_1x1_f16_rtz (_Float16 c)
{
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rno_1x1_f16_rtz ( __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_82_f16_rne_2x1_i8_rnu (carrier_i8 c)
{
  __riscv_ztt_f16_rne_2x1_t d = __riscv_ztt_mbcast_m_x_f16_rne_2x1_i8_rnu ( __riscv_ztt_scalar_make_i8_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_83_f16_rtz_1x2_i8_rne (carrier_i8 c)
{
  __riscv_ztt_f16_rtz_1x2_t d = __riscv_ztt_mbcast_m_x_f16_rtz_1x2_i8_rne ( __riscv_ztt_scalar_make_i8_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_84_f16_rdn_1x1_i8_rdn (carrier_i8 c)
{
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rdn_1x1_i8_rdn ( __riscv_ztt_scalar_make_i8_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_85_f16_rup_1x2_i8_rod (carrier_i8 c)
{
  __riscv_ztt_f16_rup_1x2_t d = __riscv_ztt_mbcast_m_x_f16_rup_1x2_i8_rod ( __riscv_ztt_scalar_make_i8_rod (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_86_f16_rmm_2x1_u8_rnu (carrier_u8 c)
{
  __riscv_ztt_f16_rmm_2x1_t d = __riscv_ztt_mbcast_m_x_f16_rmm_2x1_u8_rnu ( __riscv_ztt_scalar_make_u8_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_87_f16_rno_1x1_u8_rne (carrier_u8 c)
{
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rno_1x1_u8_rne ( __riscv_ztt_scalar_make_u8_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_88_bf16_rne_2x1_u8_rdn (carrier_u8 c)
{
  __riscv_ztt_bf16_rne_2x1_t d = __riscv_ztt_mbcast_m_x_bf16_rne_2x1_u8_rdn ( __riscv_ztt_scalar_make_u8_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_89_bf16_rtz_1x2_u8_rod (carrier_u8 c)
{
  __riscv_ztt_bf16_rtz_1x2_t d = __riscv_ztt_mbcast_m_x_bf16_rtz_1x2_u8_rod ( __riscv_ztt_scalar_make_u8_rod (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_90_bf16_rdn_1x1_i16_rnu (carrier_i16 c)
{
  __riscv_ztt_bf16_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rdn_1x1_i16_rnu ( __riscv_ztt_scalar_make_i16_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_91_bf16_rup_1x2_i16_rne (carrier_i16 c)
{
  __riscv_ztt_bf16_rup_1x2_t d = __riscv_ztt_mbcast_m_x_bf16_rup_1x2_i16_rne ( __riscv_ztt_scalar_make_i16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_92_bf16_rmm_2x1_i16_rdn (carrier_i16 c)
{
  __riscv_ztt_bf16_rmm_2x1_t d = __riscv_ztt_mbcast_m_x_bf16_rmm_2x1_i16_rdn ( __riscv_ztt_scalar_make_i16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_93_bf16_rno_1x1_i16_rod (carrier_i16 c)
{
  __riscv_ztt_bf16_rno_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rno_1x1_i16_rod ( __riscv_ztt_scalar_make_i16_rod (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_94_f32_rne_1x1_u16_rnu (carrier_u16 c)
{
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rne_1x1_u16_rnu ( __riscv_ztt_scalar_make_u16_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_95_f32_rtz_1x1_u16_rne (carrier_u16 c)
{
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rtz_1x1_u16_rne ( __riscv_ztt_scalar_make_u16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_96_f32_rdn_1x1_u16_rdn (carrier_u16 c)
{
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rdn_1x1_u16_rdn ( __riscv_ztt_scalar_make_u16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_97_f32_rup_1x1_u16_rod (carrier_u16 c)
{
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rup_1x1_u16_rod ( __riscv_ztt_scalar_make_u16_rod (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_98_f32_rmm_1x1_i32_rnu (carrier_i32 c)
{
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rmm_1x1_i32_rnu ( __riscv_ztt_scalar_make_i32_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_99_f32_rno_1x1_i32_rne (carrier_i32 c)
{
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rno_1x1_i32_rne ( __riscv_ztt_scalar_make_i32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_100_f16_rne_2x1_i32_rdn (carrier_i32 c)
{
  __riscv_ztt_f16_rne_2x1_t d = __riscv_ztt_mbcast_m_x_f16_rne_2x1_i32_rdn ( __riscv_ztt_scalar_make_i32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_101_f16_rtz_1x2_i32_rod (carrier_i32 c)
{
  __riscv_ztt_f16_rtz_1x2_t d = __riscv_ztt_mbcast_m_x_f16_rtz_1x2_i32_rod ( __riscv_ztt_scalar_make_i32_rod (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_102_f16_rdn_1x1_u32_rnu (carrier_u32 c)
{
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rdn_1x1_u32_rnu ( __riscv_ztt_scalar_make_u32_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_103_f16_rup_1x2_u32_rne (carrier_u32 c)
{
  __riscv_ztt_f16_rup_1x2_t d = __riscv_ztt_mbcast_m_x_f16_rup_1x2_u32_rne ( __riscv_ztt_scalar_make_u32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_104_f16_rmm_2x1_u32_rdn (carrier_u32 c)
{
  __riscv_ztt_f16_rmm_2x1_t d = __riscv_ztt_mbcast_m_x_f16_rmm_2x1_u32_rdn ( __riscv_ztt_scalar_make_u32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_105_f16_rno_1x1_u32_rod (carrier_u32 c)
{
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rno_1x1_u32_rod ( __riscv_ztt_scalar_make_u32_rod (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_106_bf16_rne_2x1_i64_rnu (carrier_i64 c)
{
  __riscv_ztt_bf16_rne_2x1_t d = __riscv_ztt_mbcast_m_x_bf16_rne_2x1_i64_rnu ( __riscv_ztt_scalar_from_bits_i64_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_107_bf16_rtz_1x2_i64_rne (carrier_i64 c)
{
  __riscv_ztt_bf16_rtz_1x2_t d = __riscv_ztt_mbcast_m_x_bf16_rtz_1x2_i64_rne ( __riscv_ztt_scalar_from_bits_i64_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_108_bf16_rdn_1x1_i64_rdn (carrier_i64 c)
{
  __riscv_ztt_bf16_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rdn_1x1_i64_rdn ( __riscv_ztt_scalar_from_bits_i64_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_109_bf16_rup_1x2_i64_rod (carrier_i64 c)
{
  __riscv_ztt_bf16_rup_1x2_t d = __riscv_ztt_mbcast_m_x_bf16_rup_1x2_i64_rod ( __riscv_ztt_scalar_from_bits_i64_rod (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_110_bf16_rmm_2x1_u64_rnu (carrier_u64 c)
{
  __riscv_ztt_bf16_rmm_2x1_t d = __riscv_ztt_mbcast_m_x_bf16_rmm_2x1_u64_rnu ( __riscv_ztt_scalar_from_bits_u64_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_111_bf16_rno_1x1_u64_rne (carrier_u64 c)
{
  __riscv_ztt_bf16_rno_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rno_1x1_u64_rne ( __riscv_ztt_scalar_from_bits_u64_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_112_f32_rne_1x1_u64_rdn (carrier_u64 c)
{
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rne_1x1_u64_rdn ( __riscv_ztt_scalar_from_bits_u64_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_113_f32_rtz_1x1_u64_rod (carrier_u64 c)
{
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rtz_1x1_u64_rod ( __riscv_ztt_scalar_from_bits_u64_rod (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_114_f32_rdn_1x1_i128_rnu (carrier_i128 c)
{
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rdn_1x1_i128_rnu ( __riscv_ztt_scalar_from_bits_i128_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_115_f32_rup_1x1_i128_rne (carrier_i128 c)
{
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rup_1x1_i128_rne ( __riscv_ztt_scalar_from_bits_i128_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_116_f32_rmm_1x1_i128_rdn (carrier_i128 c)
{
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rmm_1x1_i128_rdn ( __riscv_ztt_scalar_from_bits_i128_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_117_f32_rno_1x1_i128_rod (carrier_i128 c)
{
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rno_1x1_i128_rod ( __riscv_ztt_scalar_from_bits_i128_rod (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_118_f16_rne_2x1_u128_rnu (carrier_u128 c)
{
  __riscv_ztt_f16_rne_2x1_t d = __riscv_ztt_mbcast_m_x_f16_rne_2x1_u128_rnu ( __riscv_ztt_scalar_from_bits_u128_rnu (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_119_f16_rtz_1x2_u128_rne (carrier_u128 c)
{
  __riscv_ztt_f16_rtz_1x2_t d = __riscv_ztt_mbcast_m_x_f16_rtz_1x2_u128_rne ( __riscv_ztt_scalar_from_bits_u128_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_120_f16_rdn_1x1_u128_rdn (carrier_u128 c)
{
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rdn_1x1_u128_rdn ( __riscv_ztt_scalar_from_bits_u128_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_121_f16_rup_1x2_u128_rod (carrier_u128 c)
{
  __riscv_ztt_f16_rup_1x2_t d = __riscv_ztt_mbcast_m_x_f16_rup_1x2_u128_rod ( __riscv_ztt_scalar_from_bits_u128_rod (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_122_f16_rmm_2x1_i8_rnu_sat (carrier_i8 c)
{
  __riscv_ztt_f16_rmm_2x1_t d = __riscv_ztt_mbcast_m_x_f16_rmm_2x1_i8_rnu_sat ( __riscv_ztt_scalar_make_i8_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_123_f16_rno_1x1_i8_rne_sat (carrier_i8 c)
{
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rno_1x1_i8_rne_sat ( __riscv_ztt_scalar_make_i8_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_124_bf16_rne_2x1_i8_rdn_sat (carrier_i8 c)
{
  __riscv_ztt_bf16_rne_2x1_t d = __riscv_ztt_mbcast_m_x_bf16_rne_2x1_i8_rdn_sat ( __riscv_ztt_scalar_make_i8_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_125_bf16_rtz_1x2_i8_rod_sat (carrier_i8 c)
{
  __riscv_ztt_bf16_rtz_1x2_t d = __riscv_ztt_mbcast_m_x_bf16_rtz_1x2_i8_rod_sat ( __riscv_ztt_scalar_make_i8_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_126_bf16_rdn_1x1_u8_rnu_sat (carrier_u8 c)
{
  __riscv_ztt_bf16_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rdn_1x1_u8_rnu_sat ( __riscv_ztt_scalar_make_u8_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_127_bf16_rup_1x2_u8_rne_sat (carrier_u8 c)
{
  __riscv_ztt_bf16_rup_1x2_t d = __riscv_ztt_mbcast_m_x_bf16_rup_1x2_u8_rne_sat ( __riscv_ztt_scalar_make_u8_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_128_bf16_rmm_2x1_u8_rdn_sat (carrier_u8 c)
{
  __riscv_ztt_bf16_rmm_2x1_t d = __riscv_ztt_mbcast_m_x_bf16_rmm_2x1_u8_rdn_sat ( __riscv_ztt_scalar_make_u8_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_129_bf16_rno_1x1_u8_rod_sat (carrier_u8 c)
{
  __riscv_ztt_bf16_rno_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rno_1x1_u8_rod_sat ( __riscv_ztt_scalar_make_u8_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_130_f32_rne_1x1_i16_rnu_sat (carrier_i16 c)
{
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rne_1x1_i16_rnu_sat ( __riscv_ztt_scalar_make_i16_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_131_f32_rtz_1x1_i16_rne_sat (carrier_i16 c)
{
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rtz_1x1_i16_rne_sat ( __riscv_ztt_scalar_make_i16_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_132_f32_rdn_1x1_i16_rdn_sat (carrier_i16 c)
{
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rdn_1x1_i16_rdn_sat ( __riscv_ztt_scalar_make_i16_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_133_f32_rup_1x1_i16_rod_sat (carrier_i16 c)
{
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rup_1x1_i16_rod_sat ( __riscv_ztt_scalar_make_i16_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_134_f32_rmm_1x1_u16_rnu_sat (carrier_u16 c)
{
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rmm_1x1_u16_rnu_sat ( __riscv_ztt_scalar_make_u16_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_135_f32_rno_1x1_u16_rne_sat (carrier_u16 c)
{
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rno_1x1_u16_rne_sat ( __riscv_ztt_scalar_make_u16_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_136_f16_rne_2x1_u16_rdn_sat (carrier_u16 c)
{
  __riscv_ztt_f16_rne_2x1_t d = __riscv_ztt_mbcast_m_x_f16_rne_2x1_u16_rdn_sat ( __riscv_ztt_scalar_make_u16_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_137_f16_rtz_1x2_u16_rod_sat (carrier_u16 c)
{
  __riscv_ztt_f16_rtz_1x2_t d = __riscv_ztt_mbcast_m_x_f16_rtz_1x2_u16_rod_sat ( __riscv_ztt_scalar_make_u16_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_138_f16_rdn_1x1_i32_rnu_sat (carrier_i32 c)
{
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rdn_1x1_i32_rnu_sat ( __riscv_ztt_scalar_make_i32_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_139_f16_rup_1x2_i32_rne_sat (carrier_i32 c)
{
  __riscv_ztt_f16_rup_1x2_t d = __riscv_ztt_mbcast_m_x_f16_rup_1x2_i32_rne_sat ( __riscv_ztt_scalar_make_i32_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_140_f16_rmm_2x1_i32_rdn_sat (carrier_i32 c)
{
  __riscv_ztt_f16_rmm_2x1_t d = __riscv_ztt_mbcast_m_x_f16_rmm_2x1_i32_rdn_sat ( __riscv_ztt_scalar_make_i32_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_141_f16_rno_1x1_i32_rod_sat (carrier_i32 c)
{
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rno_1x1_i32_rod_sat ( __riscv_ztt_scalar_make_i32_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_142_bf16_rne_2x1_u32_rnu_sat (carrier_u32 c)
{
  __riscv_ztt_bf16_rne_2x1_t d = __riscv_ztt_mbcast_m_x_bf16_rne_2x1_u32_rnu_sat ( __riscv_ztt_scalar_make_u32_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_143_bf16_rtz_1x2_u32_rne_sat (carrier_u32 c)
{
  __riscv_ztt_bf16_rtz_1x2_t d = __riscv_ztt_mbcast_m_x_bf16_rtz_1x2_u32_rne_sat ( __riscv_ztt_scalar_make_u32_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_144_bf16_rdn_1x1_u32_rdn_sat (carrier_u32 c)
{
  __riscv_ztt_bf16_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rdn_1x1_u32_rdn_sat ( __riscv_ztt_scalar_make_u32_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_145_bf16_rup_1x2_u32_rod_sat (carrier_u32 c)
{
  __riscv_ztt_bf16_rup_1x2_t d = __riscv_ztt_mbcast_m_x_bf16_rup_1x2_u32_rod_sat ( __riscv_ztt_scalar_make_u32_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_146_bf16_rmm_2x1_i64_rnu_sat (carrier_i64 c)
{
  __riscv_ztt_bf16_rmm_2x1_t d = __riscv_ztt_mbcast_m_x_bf16_rmm_2x1_i64_rnu_sat ( __riscv_ztt_scalar_from_bits_i64_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_147_bf16_rno_1x1_i64_rne_sat (carrier_i64 c)
{
  __riscv_ztt_bf16_rno_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rno_1x1_i64_rne_sat ( __riscv_ztt_scalar_from_bits_i64_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_148_f32_rne_1x1_i64_rdn_sat (carrier_i64 c)
{
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rne_1x1_i64_rdn_sat ( __riscv_ztt_scalar_from_bits_i64_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_149_f32_rtz_1x1_i64_rod_sat (carrier_i64 c)
{
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rtz_1x1_i64_rod_sat ( __riscv_ztt_scalar_from_bits_i64_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_150_f32_rdn_1x1_u64_rnu_sat (carrier_u64 c)
{
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rdn_1x1_u64_rnu_sat ( __riscv_ztt_scalar_from_bits_u64_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_151_f32_rup_1x1_u64_rne_sat (carrier_u64 c)
{
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rup_1x1_u64_rne_sat ( __riscv_ztt_scalar_from_bits_u64_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_152_f32_rmm_1x1_u64_rdn_sat (carrier_u64 c)
{
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rmm_1x1_u64_rdn_sat ( __riscv_ztt_scalar_from_bits_u64_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_153_f32_rno_1x1_u64_rod_sat (carrier_u64 c)
{
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rno_1x1_u64_rod_sat ( __riscv_ztt_scalar_from_bits_u64_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_154_f16_rne_2x1_i128_rnu_sat (carrier_i128 c)
{
  __riscv_ztt_f16_rne_2x1_t d = __riscv_ztt_mbcast_m_x_f16_rne_2x1_i128_rnu_sat ( __riscv_ztt_scalar_from_bits_i128_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_155_f16_rtz_1x2_i128_rne_sat (carrier_i128 c)
{
  __riscv_ztt_f16_rtz_1x2_t d = __riscv_ztt_mbcast_m_x_f16_rtz_1x2_i128_rne_sat ( __riscv_ztt_scalar_from_bits_i128_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_156_f16_rdn_1x1_i128_rdn_sat (carrier_i128 c)
{
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rdn_1x1_i128_rdn_sat ( __riscv_ztt_scalar_from_bits_i128_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_157_f16_rup_1x2_i128_rod_sat (carrier_i128 c)
{
  __riscv_ztt_f16_rup_1x2_t d = __riscv_ztt_mbcast_m_x_f16_rup_1x2_i128_rod_sat ( __riscv_ztt_scalar_from_bits_i128_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_158_f16_rmm_2x1_u128_rnu_sat (carrier_u128 c)
{
  __riscv_ztt_f16_rmm_2x1_t d = __riscv_ztt_mbcast_m_x_f16_rmm_2x1_u128_rnu_sat ( __riscv_ztt_scalar_from_bits_u128_rnu_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_159_f16_rno_1x1_u128_rne_sat (carrier_u128 c)
{
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rno_1x1_u128_rne_sat ( __riscv_ztt_scalar_from_bits_u128_rne_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_160_bf16_rne_2x1_u128_rdn_sat (carrier_u128 c)
{
  __riscv_ztt_bf16_rne_2x1_t d = __riscv_ztt_mbcast_m_x_bf16_rne_2x1_u128_rdn_sat ( __riscv_ztt_scalar_from_bits_u128_rdn_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_161_bf16_rtz_1x2_u128_rod_sat (carrier_u128 c)
{
  __riscv_ztt_bf16_rtz_1x2_t d = __riscv_ztt_mbcast_m_x_bf16_rtz_1x2_u128_rod_sat ( __riscv_ztt_scalar_from_bits_u128_rod_sat (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_162_bf16_rdn_1x1_f16_rne (_Float16 c)
{
  __riscv_ztt_bf16_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rdn_1x1_f16_rne ( __riscv_ztt_scalar_make_f16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_163_bf16_rup_1x2_f16_rtz (_Float16 c)
{
  __riscv_ztt_bf16_rup_1x2_t d = __riscv_ztt_mbcast_m_x_bf16_rup_1x2_f16_rtz ( __riscv_ztt_scalar_make_f16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_164_bf16_rmm_2x1_f16_rdn (_Float16 c)
{
  __riscv_ztt_bf16_rmm_2x1_t d = __riscv_ztt_mbcast_m_x_bf16_rmm_2x1_f16_rdn ( __riscv_ztt_scalar_make_f16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_165_bf16_rno_1x1_f16_rup (_Float16 c)
{
  __riscv_ztt_bf16_rno_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rno_1x1_f16_rup ( __riscv_ztt_scalar_make_f16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_166_f32_rne_1x1_f16_rmm (_Float16 c)
{
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rne_1x1_f16_rmm ( __riscv_ztt_scalar_make_f16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_167_f32_rtz_1x1_f16_rno (_Float16 c)
{
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rtz_1x1_f16_rno ( __riscv_ztt_scalar_make_f16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_168_f32_rdn_1x1_bf16_rne (__bf16 c)
{
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rdn_1x1_bf16_rne ( __riscv_ztt_scalar_make_bf16_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_169_f32_rup_1x1_bf16_rtz (__bf16 c)
{
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rup_1x1_bf16_rtz ( __riscv_ztt_scalar_make_bf16_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_170_f32_rmm_1x1_bf16_rdn (__bf16 c)
{
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rmm_1x1_bf16_rdn ( __riscv_ztt_scalar_make_bf16_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_171_f32_rno_1x1_bf16_rup (__bf16 c)
{
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rno_1x1_bf16_rup ( __riscv_ztt_scalar_make_bf16_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_172_f16_rne_2x1_bf16_rmm (__bf16 c)
{
  __riscv_ztt_f16_rne_2x1_t d = __riscv_ztt_mbcast_m_x_f16_rne_2x1_bf16_rmm ( __riscv_ztt_scalar_make_bf16_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_173_f16_rtz_1x2_bf16_rno (__bf16 c)
{
  __riscv_ztt_f16_rtz_1x2_t d = __riscv_ztt_mbcast_m_x_f16_rtz_1x2_bf16_rno ( __riscv_ztt_scalar_make_bf16_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_174_f16_rdn_1x1_f32_rne (float c)
{
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rdn_1x1_f32_rne ( __riscv_ztt_scalar_make_f32_rne (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_175_f16_rup_1x2_f32_rtz (float c)
{
  __riscv_ztt_f16_rup_1x2_t d = __riscv_ztt_mbcast_m_x_f16_rup_1x2_f32_rtz ( __riscv_ztt_scalar_make_f32_rtz (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_176_f16_rmm_2x1_f32_rdn (float c)
{
  __riscv_ztt_f16_rmm_2x1_t d = __riscv_ztt_mbcast_m_x_f16_rmm_2x1_f32_rdn ( __riscv_ztt_scalar_make_f32_rdn (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_177_f16_rno_1x1_f32_rup (float c)
{
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mbcast_m_x_f16_rno_1x1_f32_rup ( __riscv_ztt_scalar_make_f32_rup (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_178_bf16_rne_2x1_f32_rmm (float c)
{
  __riscv_ztt_bf16_rne_2x1_t d = __riscv_ztt_mbcast_m_x_bf16_rne_2x1_f32_rmm ( __riscv_ztt_scalar_make_f32_rmm (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_179_bf16_rtz_1x2_f32_rno (float c)
{
  __riscv_ztt_bf16_rtz_1x2_t d = __riscv_ztt_mbcast_m_x_bf16_rtz_1x2_f32_rno ( __riscv_ztt_scalar_make_f32_rno (c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_180_bf16_rdn_1x1_f64_rne (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rdn_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rdn_1x1_f64_rne ( ZTT_TEST_F64(rne, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_181_bf16_rup_1x2_f64_rtz (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rup_1x2_t d = __riscv_ztt_mbcast_m_x_bf16_rup_1x2_f64_rtz ( ZTT_TEST_F64(rtz, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_182_bf16_rmm_2x1_f64_rdn (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rmm_2x1_t d = __riscv_ztt_mbcast_m_x_bf16_rmm_2x1_f64_rdn ( ZTT_TEST_F64(rdn, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_183_bf16_rno_1x1_f64_rup (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_bf16_rno_1x1_t d = __riscv_ztt_mbcast_m_x_bf16_rno_1x1_f64_rup ( ZTT_TEST_F64(rup, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_184_f32_rne_1x1_f64_rmm (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rne_1x1_f64_rmm ( ZTT_TEST_F64(rmm, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
void bcast_185_f32_rtz_1x1_f64_rno (ztt_test_f64_carrier_t c)
{
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mbcast_m_x_f32_rtz_1x1_f64_rno ( ZTT_TEST_F64(rno, c));
  __asm__ volatile ("" : : "Wmr" (d));
}
#ifdef __cplusplus
}
#endif
