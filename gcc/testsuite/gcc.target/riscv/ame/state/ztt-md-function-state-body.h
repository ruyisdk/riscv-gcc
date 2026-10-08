#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
extern void state_scope_callee (void);
#define SCOPE(NAME, TYPE, RM, BARRIER) \
__attribute__((noinline, noclone)) \
void NAME (const TYPE *a, const TYPE *b, TYPE *out, TYPE *copy) \
{ \
  __riscv_ztt_##RM##_1x1_t x = __riscv_ztt_mls_rm_##RM##_1x1 (a); \
  __riscv_ztt_##RM##_1x1_t y = __riscv_ztt_mls_rm_##RM##_1x1 (b); \
  __riscv_ztt_##RM##_1x1_t z = __riscv_ztt_madd_ew_##RM##_1x1 (x, y); \
  BARRIER; \
  __riscv_ztt_mss_rm (out, z); \
  __riscv_ztt_mss_rm (copy, x); \
}
SCOPE (scope_implicit_before, signed char, i8_rnu, (void) 0)
SCOPE (scope_explicit_i32, __INT32_TYPE__, i32_rnu, (void) 0)
SCOPE (scope_implicit_middle, signed char, i8_rnu, (void) 0)
SCOPE (scope_explicit_call, signed char, i8_rnu, state_scope_callee ())
SCOPE (scope_implicit_after_call, signed char, i8_rnu, (void) 0)
SCOPE (scope_explicit_query, signed char, i8_rnu,
       (void) __riscv_ztt_get_ameown ())
SCOPE (scope_implicit_last, signed char, i8_rnu, (void) 0)
__attribute__((noinline, noclone))
unsigned long scope_scalar (unsigned long x, unsigned long y)
{
  return (x * 17) ^ (y + 3);
}
#undef SCOPE
#ifdef __cplusplus
}
#endif
