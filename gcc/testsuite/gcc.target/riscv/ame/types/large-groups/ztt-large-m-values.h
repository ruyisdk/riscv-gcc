/* Whole-value pressure, source overwrite, branches and group utilities.
   No 128-bit public memory carrier is assumed.  */
#include <stdint.h>
#include <riscv_ztt.h>
/* Shape macros describe M resource limits, not the ACC payload limit.  */
#if TEST_UDS == 8
#if __riscv_ztt_i8_u8_shapes != (TEST_M == 16 ? 511 : 2047)
#error incorrect M shape availability
#endif
/* All wrappers provide Acc16; this complete ACCx2 payload supports four RMs.  */
#if __riscv_ztt_i32_u32_accx2_irm != 15
#error incorrect ACC rounding availability
#endif
#endif
#define T_(D, S) __riscv_ztt_##D##_##S##_t
#define T(D, S) T_(D, S)
#define OP_(O, D, S) __riscv_ztt_##O##_##D##_##S
#define OP(O, D, S) OP_(O, D, S)
#define KEEP(X) __asm__ volatile ("" : : "Wmr" (X))

#define VALUES(NAME, D, BIG, HALF) \
void NAME (int branch) \
{ \
  T(D, BIG) source = OP(mzero_m, D, BIG) (); \
  T(D, BIG) saved = OP(mcopy_m2m, D, BIG) (source); \
  T(D, HALF) left = OP(mextract, D, HALF) (source, 0); \
  T(D, HALF) right = OP(mextract, D, HALF) (source, 1); \
  source = OP(mclear_m, D, BIG) (); \
  KEEP(source); \
  if (branch) left = OP(mzero_m, D, HALF) (); \
  T(D, BIG) rebuilt = OP(mconcat_m, D, BIG) (right, left); \
  KEEP(rebuilt); KEEP(saved); KEEP(right); \
}

#define MEMORY(NAME, D, C, S) \
void NAME (const C *in, C *out, __SIZE_TYPE__ stride) \
{ \
  T(D, S) a = OP(mls_rm, D, S) (in); \
  T(D, S) b = OP(mls_st, D, S) (in, stride); \
  T(D, S) c = a; \
  __riscv_ztt_mss_rm (out, a); \
  a = OP(mclear_m, D, S) (); \
  KEEP(a); \
  __riscv_ztt_mss_st (out, stride, b); \
  __riscv_ztt_mss_cm (out, c); \
}

#define ARITH(NAME, D, S) \
void NAME (void) \
{ \
  T(D, S) a = OP(mzero_m, D, S) (); \
  T(D, S) b = OP(mzero_m, D, S) (); \
  T(D, S) result = OP(madd_ew, D, S) (a, b); \
  KEEP(result); KEEP(a); KEEP(b); \
}

#if TEST_UDS == 8
#define DTYPE u8_rne
#define CTYPE uint8_t
#elif TEST_UDS == 16
#define DTYPE u16_rdn
#define CTYPE uint16_t
#elif TEST_UDS == 32
#define DTYPE u32_rod
#define CTYPE uint32_t
#elif TEST_UDS == 64
#define DTYPE u64_rnu
#define CTYPE uint64_t
#else
#define DTYPE u128_rne
#endif

VALUES(values8, DTYPE, 1x8, 1x4)
VALUES(values16, DTYPE, 16x1, 8x1)
ARITH(arith8, DTYPE, 1x8)
ARITH(arith16, DTYPE, 16x1)
#if TEST_M == 32
VALUES(values32, DTYPE, 1x32, 1x16)
ARITH(arith32, DTYPE, 1x32)
#endif
#if TEST_UDS != 128
MEMORY(memory8, DTYPE, CTYPE, 1x8)
MEMORY(memory16, DTYPE, CTYPE, 16x1)
#if TEST_M == 32
MEMORY(memory32, DTYPE, CTYPE, 1x32)
#endif
#endif

#if TEST_UDS == 8
/* A single wide Square, not just a concatenation of narrow Squares.  */
MEMORY(wide8, f64_rne, double, 1x1)
void wide16 (void)
{
  __riscv_ztt_i128_rod_1x1_t a = __riscv_ztt_mzero_m_i128_rod_1x1 ();
  __riscv_ztt_i128_rod_1x1_t b = a;
  a = __riscv_ztt_mclear_m_i128_rod_1x1 ();
  KEEP(a); KEEP(b);
}
#endif
