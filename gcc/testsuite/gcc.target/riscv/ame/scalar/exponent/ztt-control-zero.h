#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CASE(OP, T, C, KIND, CONTROL) \
void KIND##_##OP##_##T (C *out, const C *in, long control) \
{ \
  __riscv_ztt_##T##_1x1_t a = __riscv_ztt_mls_rm_##T##_1x1 (in); \
  a = __riscv_ztt_##OP##_ew_x_##T##_1x1 (a, CONTROL); \
  __riscv_ztt_mss_rm (out, a); \
}
#define CONTROLS(OP, T, C) \
CASE (OP, T, C, zero, 0) \
CASE (OP, T, C, one, 1) \
CASE (OP, T, C, dynamic, control)
#define SHIFTS(T, C) \
CONTROLS (msll, T, C) \
CONTROLS (msrl, T, C) \
CONTROLS (msra, T, C)
SHIFTS (i32_rnu, __INT32_TYPE__)
SHIFTS (i64_rdn, __INT64_TYPE__)

#define ACC(T, C, KIND, CONTROL) \
void KIND##_mldexpacc_##T (C *out, const C *in, long control) \
{ \
  __riscv_ztt_##T##_1x1_t a = __riscv_ztt_mls_rm_##T##_1x1 (in); \
  __riscv_ztt_##T##_1x1_t d = __riscv_ztt_mls_rm_##T##_1x1 (out); \
  d = __riscv_ztt_mldexpacc_ew_x_##T##_1x1 (d, a, CONTROL); \
  __riscv_ztt_mss_rm (out, d); \
}
#define EXPONENTS(T, C) \
CONTROLS (mldexp, T, C) \
ACC (T, C, zero, 0) \
ACC (T, C, one, 1) \
ACC (T, C, dynamic, control)
EXPONENTS (i32_rnu, __INT32_TYPE__)
EXPONENTS (i32_rnu_sat, __INT32_TYPE__)
EXPONENTS (f32_rne, float)
EXPONENTS (f64_rne, double)
CASE (mldexp, f32_rne, float, negative, -1)

void effect (float *out, const float *in, volatile unsigned *effect)
{
  __riscv_ztt_f32_1x1_t a = __riscv_ztt_mls_rm_f32_1x1 (in);
  a = __riscv_ztt_mldexp_ew_x_f32_1x1 (a, ((void) *effect, 0));
  __riscv_ztt_mss_rm (out, a);
}

void unknown (float *out, const float *in)
{
  __riscv_ztt_f32_1x1_t a = __riscv_ztt_mls_rm_f32_1x1 (in);
  __asm__ volatile ("" : "+Wmr" (a));
  a = __riscv_ztt_mldexpacc_ew_x_f32_1x1 (a, a, 0);
  __riscv_ztt_mss_rm (out, a);
}

void unused (const float *in)
{
  __riscv_ztt_f32_1x1_t a = __riscv_ztt_mls_rm_f32_1x1 (in);
  (void) __riscv_ztt_mldexp_ew_x_f32_1x1 (a, 0);
}

void data_zero (__INT32_TYPE__ *out, const __INT32_TYPE__ *in)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  a = __riscv_ztt_madd_ew_x_i32_rnu_1x1_i32_rnu
    (a, __riscv_ztt_scalar_make_i32_rnu (0));
  __riscv_ztt_mss_rm (out, a);
}

#undef EXPONENTS
#undef ACC
#undef SHIFTS
#undef CONTROLS
#undef CASE
#ifdef __cplusplus
}
#endif
