#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BINARY(OP, T, C, TC, KIND, VALUE) \
void KIND##_##OP##_##T##_##TC (C *out, const C *in, __UINTPTR_TYPE__ value) \
{ \
  __riscv_ztt_##T##_1x1_t a = __riscv_ztt_mls_rm_##T##_1x1 (in); \
  a = __riscv_ztt_##OP##_ew_x_##T##_1x1_##TC \
    (a, __riscv_ztt_scalar_from_bits_##TC (VALUE)); \
  __riscv_ztt_mss_rm (out, a); \
}
#define BINARY_CASES(OP, T, C, TC) \
BINARY (OP, T, C, TC, zero, 0) \
BINARY (OP, T, C, TC, one, 1) \
BINARY (OP, T, C, TC, dynamic, value)
#define INTEGER(OP) BINARY_CASES (OP, i32_rnu, __INT32_TYPE__, i32_rnu)
INTEGER (madd)
INTEGER (msub)
INTEGER (mabsdiff)
INTEGER (mhdiff)
INTEGER (mmean)
INTEGER (mmul)
INTEGER (mmulneg)
INTEGER (mmin)
INTEGER (mmax)
INTEGER (mand)
INTEGER (mandnot)
INTEGER (mor)
INTEGER (mornot)
INTEGER (mxor)
INTEGER (mcmpge)
INTEGER (mcmplt)
BINARY_CASES (mlog2sub, f32_rne, float, f32_rne)
BINARY_CASES (msublog2, f32_rne, float, f32_rne)

#define TERNARY(OP, KIND, VALUE) \
void KIND##_##OP (__INT32_TYPE__ *out, const __INT32_TYPE__ *in, __UINTPTR_TYPE__ value) \
{ \
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in); \
  __riscv_ztt_i32_1x1_t d = __riscv_ztt_mls_rm_i32_1x1 (out); \
  d = __riscv_ztt_##OP##_ew_x_i32_rnu_1x1_i32_rnu \
    (d, a, __riscv_ztt_scalar_make_i32_rnu (VALUE)); \
  __riscv_ztt_mss_rm (out, d); \
}
#define TERNARY_CASES(OP) \
TERNARY (OP, zero, 0) \
TERNARY (OP, one, 1) \
TERNARY (OP, dynamic, value)
TERNARY_CASES (mmulacc)
TERNARY_CASES (mmulaccneg)
TERNARY_CASES (mmuladd)
TERNARY_CASES (mmulsub)

#define CARRIER(TC) \
BINARY (madd, i32_rnu, __INT32_TYPE__, TC, zero, 0) \
BINARY (madd, i32_rnu, __INT32_TYPE__, TC, dynamic, value)
CARRIER (i8_rdn)
CARRIER (u16_rod)
CARRIER (i64_rne)
CARRIER (u128_rnu)
CARRIER (f16_rne)
CARRIER (bf16_rne)
CARRIER (f32_rne)
CARRIER (f64_rne)
BINARY (madd, i32_rnu_sat, __INT32_TYPE__, i8_rdn_sat, zero, 0)
BINARY (madd, i32_rnu_sat, __INT32_TYPE__, i8_rdn_sat, dynamic, value)
BINARY (madd, i64_rdn, __INT64_TYPE__, i32_rnu, zero, 0)
BINARY (madd, i64_rdn, __INT64_TYPE__, i32_rnu, dynamic, value)

#define NATIVE(KIND, VALUE) \
void KIND##_native (float *out, const float *in, float value) \
{ \
  __riscv_ztt_f32_1x1_t a = __riscv_ztt_mls_rm_f32_1x1 (in); \
  a = __riscv_ztt_madd_ew_x_f32_rne_1x1_f32_rne \
    (a, __riscv_ztt_scalar_make_f32_rne (VALUE)); \
  __riscv_ztt_mss_rm (out, a); \
}
NATIVE (zero, 0.0f)
NATIVE (negative_zero, -0.0f)
NATIVE (dynamic, value)

void effect (__INT32_TYPE__ *out, const __INT32_TYPE__ *in,
             volatile unsigned *effect)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  a = __riscv_ztt_madd_ew_x_i32_rnu_1x1_i32_rnu
    (a, __riscv_ztt_scalar_make_i32_rnu (((void) *effect, 0)));
  __riscv_ztt_mss_rm (out, a);
}

void unknown (__INT32_TYPE__ *out, const __INT32_TYPE__ *in)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  __asm__ volatile ("" : "+Wmr" (a));
  a = __riscv_ztt_mmulacc_ew_x_i32_rnu_1x1_i32_rnu
    (a, a, __riscv_ztt_scalar_make_i32_rnu (0));
  __riscv_ztt_mss_rm (out, a);
}

void unused (const float *in)
{
  __riscv_ztt_f32_1x1_t a = __riscv_ztt_mls_rm_f32_1x1 (in);
  (void) __riscv_ztt_mmul_ew_x_f32_rne_1x1_f32_rne
    (a, __riscv_ztt_scalar_make_f32_rne (0.0f));
}

#undef NATIVE
#undef CARRIER
#undef TERNARY_CASES
#undef TERNARY
#undef INTEGER
#undef BINARY_CASES
#undef BINARY
#ifdef __cplusplus
}
#endif
