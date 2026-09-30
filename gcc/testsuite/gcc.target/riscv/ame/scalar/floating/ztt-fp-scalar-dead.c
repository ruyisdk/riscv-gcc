/* Floating data scalar contracts, not numerical execution.  */
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
  __riscv_ztt_i16_1x1_t b = __riscv_ztt_mzero_m_i16_1x1 ();
  __riscv_ztt_f16_1x1_t f = __riscv_ztt_mzero_m_f16_1x1 ();
  unsigned long before = __riscv_ztt_get_amefflags ();
  __riscv_ztt_madd_ew_x_i16_1x1_f32 (b, __riscv_ztt_scalar_make_f32_rne (c));
  __riscv_ztt_msub_ew_x_i16_1x1_f32 (b, __riscv_ztt_scalar_make_f32_rne (c));
  __riscv_ztt_mmul_ew_x_i16_1x1_f32 (b, __riscv_ztt_scalar_make_f32_rne (c));
  __riscv_ztt_mabsdiff_ew_x_i16_1x1_f32 (b, __riscv_ztt_scalar_make_f32_rne (c));
  __riscv_ztt_mhdiff_ew_x_i16_1x1_f32 (b, __riscv_ztt_scalar_make_f32_rne (c));
  __riscv_ztt_mmean_ew_x_i16_1x1_f32 (b, __riscv_ztt_scalar_make_f32_rne (c));
  __riscv_ztt_mmulneg_ew_x_i16_1x1_f32 (b, __riscv_ztt_scalar_make_f32_rne (c));
  __riscv_ztt_mmin_ew_x_i16_1x1_f32 (b, __riscv_ztt_scalar_make_f32_rne (c));
  __riscv_ztt_mmax_ew_x_i16_1x1_f32 (b, __riscv_ztt_scalar_make_f32_rne (c));
  __riscv_ztt_mand_ew_x_i16_1x1_f32 (b, __riscv_ztt_scalar_make_f32_rne (c));
  __riscv_ztt_mandnot_ew_x_i16_1x1_f32 (b, __riscv_ztt_scalar_make_f32_rne (c));
  __riscv_ztt_mor_ew_x_i16_1x1_f32 (b, __riscv_ztt_scalar_make_f32_rne (c));
  __riscv_ztt_mornot_ew_x_i16_1x1_f32 (b, __riscv_ztt_scalar_make_f32_rne (c));
  __riscv_ztt_mxor_ew_x_i16_1x1_f32 (b, __riscv_ztt_scalar_make_f32_rne (c));
  __riscv_ztt_mmulacc_ew_x_i16_1x1_f32 (b, b, __riscv_ztt_scalar_make_f32_rne (c));
  __riscv_ztt_mmulaccneg_ew_x_i16_1x1_f32 (b, b, __riscv_ztt_scalar_make_f32_rne (c));
  __riscv_ztt_mmuladd_ew_x_i16_1x1_f32 (b, b, __riscv_ztt_scalar_make_f32_rne (c));
  __riscv_ztt_mmulsub_ew_x_i16_1x1_f32 (b, b, __riscv_ztt_scalar_make_f32_rne (c));
  __riscv_ztt_mcmpge_ew_x_i16_1x1_f32 (b, __riscv_ztt_scalar_make_f32_rne (c));
  __riscv_ztt_mcmplt_ew_x_i16_1x1_f32 (b, __riscv_ztt_scalar_make_f32_rne (c));
  __riscv_ztt_mlog2sub_ew_x_f16_1x1_f32 (f, __riscv_ztt_scalar_make_f32_rne (c));
  __riscv_ztt_msublog2_ew_x_f16_1x1_f32 (f, __riscv_ztt_scalar_make_f32_rne (c));
  return __riscv_ztt_get_amefflags () - before;
}
/* { dg-final { scan-assembler-times {	madd\.ew\.x	} 1 } } */
/* { dg-final { scan-assembler-times {	msub\.ew\.x	} 1 } } */
/* { dg-final { scan-assembler-times {	mmul\.ew\.x	} 1 } } */
/* { dg-final { scan-assembler-times {	mabsdiff\.ew\.x	} 1 } } */
/* { dg-final { scan-assembler-times {	mhdiff\.ew\.x	} 1 } } */
/* { dg-final { scan-assembler-times {	mmean\.ew\.x	} 1 } } */
/* { dg-final { scan-assembler-times {	mmulneg\.ew\.x	} 1 } } */
/* { dg-final { scan-assembler-times {	mmin\.ew\.x	} 1 } } */
/* { dg-final { scan-assembler-times {	mmax\.ew\.x	} 1 } } */
/* { dg-final { scan-assembler-times {	mand\.ew\.x	} 1 } } */
/* { dg-final { scan-assembler-times {	mandnot\.ew\.x	} 1 } } */
/* { dg-final { scan-assembler-times {	mor\.ew\.x	} 1 } } */
/* { dg-final { scan-assembler-times {	mornot\.ew\.x	} 1 } } */
/* { dg-final { scan-assembler-times {	mxor\.ew\.x	} 1 } } */
/* { dg-final { scan-assembler-times {	mmulacc\.ew\.x	} 1 } } */
/* { dg-final { scan-assembler-times {	mmulaccneg\.ew\.x	} 1 } } */
/* { dg-final { scan-assembler-times {	mmuladd\.ew\.x	} 1 } } */
/* { dg-final { scan-assembler-times {	mmulsub\.ew\.x	} 1 } } */
/* { dg-final { scan-assembler-times {	mcmpge\.ew\.x	} 1 } } */
/* { dg-final { scan-assembler-times {	mcmplt\.ew\.x	} 1 } } */
/* { dg-final { scan-assembler-times {	mlog2sub\.ew\.x	} 1 } } */
/* { dg-final { scan-assembler-times {	msublog2\.ew\.x	} 1 } } */
/* { dg-final { scan-assembler-times {amefflags} 2 } } */
