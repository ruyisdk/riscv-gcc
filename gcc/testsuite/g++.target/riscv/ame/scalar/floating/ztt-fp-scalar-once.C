/* Floating data scalar contracts, not numerical execution.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized -ffat-lto-objects -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -fdump-tree-optimized -ffat-lto-objects -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
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
__attribute__((always_inline)) static inline float next (volatile float *p)
{ return *p; }
void once (volatile float *p)
{
  __riscv_ztt_f16_1x1_t a = __riscv_ztt_mzero_m_f16_1x1 ();
  __riscv_ztt_f16_1x1_t b = __riscv_ztt_mmuladd_ew_x_f16_1x1_f32 (a, a, __riscv_ztt_scalar_make_f32_rne (next(p)));
  __asm__ volatile ("" : : "Wmr"(a), "Wmr"(b));
}
/* { dg-final { scan-tree-dump-times { =\{v\} \*p[^;]*;} 1 "optimized" } } */
