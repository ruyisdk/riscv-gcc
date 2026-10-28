#include <riscv_ztt.h>

typedef __INT32_TYPE__ i32;
typedef i32 (*stack_fn) (i32, i32, i32, i32, i32,
			 i32, i32, i32, i32, i32);

#ifdef __cplusplus
extern "C" {
#endif
extern i32 stack_limit (i32, i32, i32, i32, i32,
			i32, i32, i32, i32, i32);
#ifdef STACK_ALLOCA
extern void stack_escape (void *);
#define LOCAL \
  void *buffer = __builtin_alloca ((value & 31) + 16); \
  stack_escape (buffer);
#elif defined (STACK_EH)
struct cleanup { ~cleanup (); };
#define LOCAL cleanup guard;
#else
#define LOCAL
#endif

#define CALL(F, V) F (V, 1, 2, 3, 4, 5, 6, 7, 8, 9)
#define TEST(NAME, EXPR) \
i32 NAME (i32 *out, const i32 *in, stack_fn fn, i32 value) \
{ \
  LOCAL \
  __riscv_ztt_i32_rnu_1x1_t m = __riscv_ztt_mls_rm_i32_rnu_1x1 (in); \
  i32 result = EXPR; \
  m = __riscv_ztt_mmax_ew_x_i32_rnu_1x1_i32_rnu \
    (m, __riscv_ztt_scalar_make_i32_rnu (result)); \
  __riscv_ztt_mss_rm (out, m); \
  return result; \
}
TEST (stack_direct, CALL (stack_limit, value))
TEST (stack_indirect, CALL (fn, value))
TEST (stack_twice, CALL (fn, CALL (stack_limit, value)))
#undef TEST
#undef CALL
#undef LOCAL
#ifdef __cplusplus
}
#endif
