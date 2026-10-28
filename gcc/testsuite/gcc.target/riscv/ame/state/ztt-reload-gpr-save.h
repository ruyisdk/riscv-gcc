#include <riscv_ztt.h>
typedef __INT64_TYPE__ element;
typedef __riscv_ztt_i64_rnu_1x1_t matrix;
typedef __UINTPTR_TYPE__ word;
#define LOAD(P) __riscv_ztt_mls_rm_i64_rnu_1x1(P)
#define STORE(P,V) __riscv_ztt_mss_rm(P,V)
#define SCALAR(V) __riscv_ztt_scalar_from_bits_i32_rnu((__UINT32_TYPE__)(V))
#ifdef __cplusplus
extern "C" {
#endif
extern word gr_callee (void);
#define TEST(NAME, EXPR) \
void gr_##NAME (const element *in, const element *other, element *out, \
                element *saved, const volatile word *input, word *result) \
{ \
  matrix a = LOAD(in), b = LOAD(other); \
  word p = input[0]; \
  word delta = gr_callee (); \
  word value = (EXPR); \
  matrix d = __riscv_ztt_mmulacc_ew_x_i64_rnu_1x1(a, b, SCALAR(value)); \
  STORE(out, d); STORE(saved, a); *result = value; \
}
TEST(and, p & delta)
TEST(xor, p ^ delta)
TEST(shift, p >> (delta & 31))
TEST(combined, (p ^ (delta >> 3)) & 31)
TEST(divide, p / (delta | 1))
TEST(compare, p < delta)
#ifdef __cplusplus
}
#endif
