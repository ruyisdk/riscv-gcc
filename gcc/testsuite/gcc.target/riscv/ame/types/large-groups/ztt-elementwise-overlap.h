/* Complete destination reuse must retain both live old sources.  */
#include <riscv_ztt.h>
#define TYPE_(D) __riscv_ztt_##D##_1x1_t
#define TYPE(D) TYPE_(D)
#define CALL_(O, D) __riscv_ztt_##O##_##D##_1x1
#define CALL(O, D) CALL_(O, D)
#define BCAST_(D) __riscv_ztt_mbcast_m_x_##D##_1x1_i8_rnu
#define BCAST(D) BCAST_(D)
#define SCALAR_(D) __riscv_ztt_mmul_ew_x_##D##_1x1_u128_rnu
#define SCALAR(D) SCALAR_(D)
#define KEEP(X) __asm__ volatile ("" : : "Wmr" (X))
#define SAME(D) \
void same_##D (signed char x) \
{ \
  TYPE(D) a = BCAST(D) ( __riscv_ztt_scalar_make_i8_rnu (x)); \
  TYPE(D) d = CALL(mmul_ew, D) (a, a); \
  KEEP(d); KEEP(a); \
}
#define DISTINCT(D, NAME, LIVE) \
void NAME##_##D (signed char x, signed char y) \
{ \
  TYPE(D) a = BCAST(D) ( __riscv_ztt_scalar_make_i8_rnu (x)); \
  TYPE(D) b = BCAST(D) ( __riscv_ztt_scalar_make_i8_rnu (y)); \
  TYPE(D) d = CALL(mmul_ew, D) (a, b); \
  KEEP(d); LIVE \
}
#define SOURCES(D) \
  DISTINCT(D, dead, ) \
  DISTINCT(D, left, KEEP(a);) \
  DISTINCT(D, right, KEEP(b);) \
  DISTINCT(D, both, KEEP(a); KEEP(b);)
#define UNARY(D) \
SAME(D) \
void scalar_##D (signed char x, __UINTPTR_TYPE__ bits) \
{ \
  TYPE(D) a = BCAST(D) ( __riscv_ztt_scalar_make_i8_rnu (x)); \
  TYPE(D) d = SCALAR(D) (a, __riscv_ztt_scalar_from_bits_u128_rnu (bits)); \
  KEEP(d); KEEP(a); \
} \
void shift_##D (signed char x, unsigned long count) \
{ \
  TYPE(D) a = BCAST(D) ( __riscv_ztt_scalar_make_i8_rnu (x)); \
  TYPE(D) d = CALL(msll_ew_x, D) (a, count); \
  KEEP(d); KEEP(a); \
}
UNARY(i64_rnu)
UNARY(u64_rne)
UNARY(i128_rdn)
UNARY(u128_rod)
UNARY(i128_rnu_sat)
SOURCES(i64_rnu)
SOURCES(u64_rne)
#if TEST_UDS >= 16 || TEST_M >= 32
SOURCES(i128_rdn)
SOURCES(u128_rod)
SOURCES(i128_rnu_sat)

#define MIXED(D, S, ORDER, A, B) \
void mixed_##ORDER##_##D##_##S (signed char x, signed char y) \
{ \
  TYPE(D) a = BCAST(D) ( __riscv_ztt_scalar_make_i8_rnu (x)); \
  TYPE(S) b = BCAST(S) ( __riscv_ztt_scalar_make_i8_rnu (y)); \
  TYPE(D) d = CALL(mmul_ew, D) (A, B); \
  KEEP(d); KEEP(a); KEEP(b); \
}
MIXED(i128_rnu, i64_rdn, lhs, a, b)
MIXED(i128_rnu, i64_rdn, rhs, b, a)
MIXED(u128_rod, u64_rne, lhs, a, b)
MIXED(u128_rod, u64_rne, rhs, b, a)
MIXED(i128_rnu_sat, i64_rdn, lhs, a, b)
MIXED(i128_rnu_sat, i64_rdn, rhs, b, a)
#endif

void floating_f64_rne (const double *x, const double *y)
{
  __riscv_ztt_f64_rne_1x1_t a = __riscv_ztt_mls_rm_f64_rne_1x1 (x);
  __riscv_ztt_f64_rne_1x1_t b = __riscv_ztt_mls_rm_f64_rne_1x1 (y);
  __riscv_ztt_f64_rne_1x1_t d = __riscv_ztt_mmul_ew_f64_rne_1x1 (a, b);
  KEEP(d); KEEP(a); KEEP(b);
}

void flags_i128_rnu_sat (signed char x)
{
  __riscv_ztt_i128_rnu_sat_1x1_t a =
    __riscv_ztt_mbcast_m_x_i128_rnu_sat_1x1_i8_rnu ( __riscv_ztt_scalar_make_i8_rnu (x));
  __riscv_ztt_mmul_ew_i128_rnu_sat_1x1 (a, a);
}

void flags_f64_rne (const double *x)
{
  __riscv_ztt_f64_rne_1x1_t a = __riscv_ztt_mls_rm_f64_rne_1x1 (x);
  __riscv_ztt_mmul_ew_f64_rne_1x1 (a, a);
}
