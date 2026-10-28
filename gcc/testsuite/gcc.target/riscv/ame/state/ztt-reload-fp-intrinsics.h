#include <riscv_ztt.h>

typedef __INT64_TYPE__ element;
typedef __riscv_ztt_i64_rnu_1x1_t matrix;
#define LOAD(P) __riscv_ztt_mls_rm_i64_rnu_1x1(P)
#define STORE(P,V) __riscv_ztt_mss_rm(P,V)
#define SCALAR(V) __riscv_ztt_scalar_from_bits_i32_rnu((__UINT32_TYPE__)(V))

#ifdef __cplusplus
extern "C" {
#endif
extern double fr_callee (void);

#define TEST(NAME, EXPR) \
void fr_##NAME (const element *in, const element *other, element *out, \
                element *saved, const volatile double *input, double *result) \
{ \
  matrix a = LOAD(in), b = LOAD(other); \
  double p = input[0]; \
  double delta = fr_callee (); \
  double value = (EXPR); \
  matrix d = __riscv_ztt_mmulacc_ew_x_i64_rnu_1x1(a, b, SCALAR(value)); \
  STORE(out, d); \
  STORE(saved, a); \
  *result = value; \
}

TEST(min, __builtin_fmin(p, delta))
TEST(max, __builtin_fmax(p, delta))
TEST(sign, __builtin_copysign(p, delta))
TEST(round, __builtin_lrint(p + delta))
#ifdef __cplusplus
}
#endif
