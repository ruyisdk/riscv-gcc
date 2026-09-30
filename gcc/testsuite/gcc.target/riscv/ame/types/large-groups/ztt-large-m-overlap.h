/* Equal-Md wide operations must allow exact result/source overlap while
   keeping any live old values.  Scalars are independent runtime inputs.  */
#include <riscv_ztt.h>
#define TYPE_(D) __riscv_ztt_##D##_1x1_t
#define TYPE(D) TYPE_(D)
#define CALL_(O, D) __riscv_ztt_##O##_##D##_1x1
#define CALL(O, D) CALL_(O, D)
#define BCAST_(D) __riscv_ztt_mbcast_m_x_##D##_1x1_i8_rnu
#define BCAST(D) BCAST_(D)
#define KEEP(X) __asm__ volatile ("" : : "Wmr" (X))
#define SAME(O, D) \
void same_##O##_##D (signed char x) \
{ \
  TYPE(D) a = BCAST(D) ( __riscv_ztt_scalar_make_i8_rnu (x)); \
  TYPE(D) result = CALL(O, D) (a, a); \
  KEEP(result); KEEP(a); \
}
#define DISTINCT(O, D, NAME, LIVE) \
void NAME##_##O##_##D (signed char x, signed char y) \
{ \
  TYPE(D) a = BCAST(D) ( __riscv_ztt_scalar_make_i8_rnu (x)); \
  TYPE(D) b = BCAST(D) ( __riscv_ztt_scalar_make_i8_rnu (y)); \
  TYPE(D) result = CALL(O, D) (a, b); \
  KEEP(result); LIVE \
}
#define SOURCES(O, D) \
  DISTINCT(O, D, dead, ) \
  DISTINCT(O, D, left, KEEP(a);) \
  DISTINCT(O, D, right, KEEP(b);) \
  DISTINCT(O, D, both, KEEP(a); KEEP(b);)
#define ALL(MACRO, D) \
  MACRO(madd_ew, D) MACRO(msub_ew, D) \
  MACRO(mmin_ew, D) MACRO(mmax_ew, D) \
  MACRO(mand_ew, D) MACRO(mandnot_ew, D) \
  MACRO(mor_ew, D) MACRO(mornot_ew, D) MACRO(mxor_ew, D)
ALL(SAME, i64_rnu)
ALL(SAME, u64_rne)
ALL(SAME, i128_rdn)
ALL(SAME, u128_rod)
ALL(SOURCES, i64_rnu)
ALL(SOURCES, u64_rne)
#if TEST_UDS >= 16 || TEST_M >= 32
ALL(SOURCES, i128_rdn)
ALL(SOURCES, u128_rod)
#endif
