#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CASE(OP, T, C, NAME, CONTROL) \
void NAME##_##OP##_##T (C *out, const C *in, __SIZE_TYPE__ index) \
{ \
  __riscv_ztt_##T##_1x1_t a = __riscv_ztt_mls_rm_##T##_1x1 (in); \
  a = __riscv_ztt_##OP##_ew_x_##T##_1x1 (a, CONTROL); \
  __riscv_ztt_mss_rm (out, a); \
}
#define OP_CASES(OP, T, C) \
CASE (OP, T, C, zero, 0) \
CASE (OP, T, C, one, 1) \
CASE (OP, T, C, dynamic, index)
#define TYPE_CASES(T, C) \
OP_CASES (mrowbcast, T, C) \
OP_CASES (mcolbcast, T, C) \
OP_CASES (mrowshift, T, C) \
OP_CASES (mcolshift, T, C) \
void effect_##T (C *out, const C *in, volatile unsigned *effect) \
{ \
  __riscv_ztt_##T##_1x1_t a = __riscv_ztt_mls_rm_##T##_1x1 (in); \
  a = __riscv_ztt_mrowbcast_ew_x_##T##_1x1 (a, ((void) *effect, 0)); \
  __riscv_ztt_mss_rm (out, a); \
} \
void unknown_##T (C *out, const C *in) \
{ \
  __riscv_ztt_##T##_1x1_t a = __riscv_ztt_mls_rm_##T##_1x1 (in); \
  __asm__ volatile ("" : "+Wmr" (a)); \
  a = __riscv_ztt_mcolbcast_ew_x_##T##_1x1 (a, 0); \
  __riscv_ztt_mss_rm (out, a); \
} \
void unused_##T (const C *in) \
{ \
  __riscv_ztt_##T##_1x1_t a = __riscv_ztt_mls_rm_##T##_1x1 (in); \
  (void) __riscv_ztt_mrowbcast_ew_x_##T##_1x1 (a, 0); \
}

TYPE_CASES (i32_rnu, __INT32_TYPE__)
TYPE_CASES (f32_rne, float)
TYPE_CASES (f64_rne, double)

#if __SIZEOF_SIZE_T__ > 4
#define HIGH_CASE(T, C) \
void high_##T (C *out, const C *in, __SIZE_TYPE__ *saved) \
{ \
  __SIZE_TYPE__ control = (__SIZE_TYPE__) 1 << 32; \
  __riscv_ztt_##T##_1x1_t a = __riscv_ztt_mls_rm_##T##_1x1 (in); \
  *saved = control; \
  a = __riscv_ztt_mrowbcast_ew_x_##T##_1x1 (a, control); \
  __riscv_ztt_mss_rm (out, a); \
}
HIGH_CASE (i32_rnu, __INT32_TYPE__)
HIGH_CASE (f32_rne, float)
HIGH_CASE (f64_rne, double)
#undef HIGH_CASE
#endif

#undef TYPE_CASES
#undef OP_CASES
#undef CASE
#ifdef __cplusplus
}
#endif
