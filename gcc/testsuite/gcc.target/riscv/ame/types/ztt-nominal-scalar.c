/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

#ifdef __cplusplus
#define SAME(A, B) __is_same (A, B)
#else
#define SAME(A, B) __builtin_types_compatible_p (A, B)
#endif
#define CHECK(N, X) typedef char check_##N[(X) ? 1 : -1]
CHECK (alias, SAME (__riscv_ztt_i32_scalar_t, __riscv_ztt_i32_rnu_scalar_t));
CHECK (rm, !SAME (__riscv_ztt_i32_rnu_scalar_t, __riscv_ztt_i32_rne_scalar_t));
CHECK (sat, !SAME (__riscv_ztt_i32_rnu_scalar_t, __riscv_ztt_i32_rnu_sat_scalar_t));
CHECK (fp, !SAME (__riscv_ztt_i32_rne_scalar_t, __riscv_ztt_f32_rne_scalar_t));
CHECK (size, sizeof (__riscv_ztt_i32_scalar_t) == 4);
CHECK (wide, sizeof (__riscv_ztt_u128_rnu_scalar_t) == __riscv_xlen / 8);
CHECK (storage, sizeof (__riscv_ztt_u128_storage_t) == 16);

uint32_t roundtrip (volatile int32_t *p)
{
  const __riscv_ztt_i32_scalar_t s = __riscv_ztt_scalar_make_i32_rnu (*p);
  return __riscv_ztt_scalar_bits_i32_rnu (s);
}

uint32_t fp_bits (float x)
{
  return __riscv_ztt_scalar_bits_f32_rne (__riscv_ztt_scalar_make_f32_rne (x));
}

uint32_t nan_bits (void)
{
  return __riscv_ztt_scalar_bits_f32_rne
    (__riscv_ztt_scalar_from_bits_f32_rne (0x7fc12345u));
}

void integer_kernel (int32_t *out, volatile int32_t *p)
{
  const __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (*p);
  __riscv_ztt_i32_1x1_t m = __riscv_ztt_mbcast_m_x_i32_1x1 (s);
  m = __riscv_ztt_madd_ew_x_i32_1x1 (m, s);
  /* Shift counts are control values, not data Scalars.  */
  m = __riscv_ztt_msll_ew_x_i32_1x1 (m, 3);
  __riscv_ztt_mss_rm (out, m);
}

void floating_kernel (float *out)
{
  __riscv_ztt_f32_rne_scalar_t s = __riscv_ztt_scalar_from_bits_f32_rne (0x80000000u);
  __riscv_ztt_f32_1x1_t m = __riscv_ztt_mbcast_m_x_f32_1x1 (s);
  m = __riscv_ztt_madd_ew_x_f32_1x1 (m, s);
  __riscv_ztt_mss_rm (out, m);
}

/* { dg-final { scan-assembler "madd.ew.x" } } */
/* { dg-final { scan-assembler "mbcast.m.x" } } */
/* { dg-final { scan-assembler "msll.ew.x" } } */
/* { dg-final { scan-assembler-not {call[ \t]+__riscv_ztt_scalar} } } */
