#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
extern void binary_callee (void);
extern volatile int binary_condition;
extern volatile long binary_scalar;
#if __riscv_ztt_uds <= 16
#define SX_BASIC 1
#define SX_PAIR 2
#define SX_MIXED 1
#elif __riscv_ztt_uds == 32
#define SX_BASIC 1
#define SX_PAIR 2
#define SX_MIXED 2
#elif __riscv_ztt_uds == 64
#define SX_BASIC 2
#define SX_PAIR 4
#define SX_MIXED 4
#else
#define SX_BASIC 4
#define SX_PAIR 8
#define SX_MIXED 8
#endif
#define SX_C_i16 __INT16_TYPE__
#define SX_C_i32 __INT32_TYPE__
#define SX_DATA(F, D, RM, Q, X) \
  __riscv_ztt_##F##_ew_x_##D##_##RM##_1x##Q##_i32_rne \
    (X, __riscv_ztt_scalar_make_i32_rne ((__INT32_TYPE__) binary_scalar))
#define SX_SHIFT(F, D, RM, Q, X) \
  __riscv_ztt_##F##_ew_x_##D##_##RM##_1x##Q (X, (unsigned long) binary_scalar)
#define SX_(NAME, FORM, OP, D, DR, L, LR, Q, BARRIER) \
__attribute__((noinline, noclone)) \
void NAME (const void *a, const void *b, void *out, void *left, void *right) \
{ \
  __riscv_ztt_##L##_##LR##_1x##Q##_t x \
    = __riscv_ztt_mls_rm_##L##_##LR##_1x##Q ((const SX_C_##L *) a); \
  __riscv_ztt_##L##_##LR##_1x##Q##_t y \
    = __riscv_ztt_mls_rm_##L##_##LR##_1x##Q ((const SX_C_##L *) b); \
  __riscv_ztt_##D##_##DR##_1x##Q##_t z = FORM (OP, D, DR, Q, x); \
  BARRIER; \
  __riscv_ztt_mss_rm ((SX_C_##D *) out, z); \
  __riscv_ztt_mss_rm ((SX_C_##L *) left, x); \
  __riscv_ztt_mss_rm ((SX_C_##L *) right, y); \
}
#define SX(...) SX_ (__VA_ARGS__)
SX (sx_mul, SX_DATA, mmul, i32, rnu, i32, rnu, SX_BASIC, (void) 0)
SX (sx_rne, SX_DATA, mmul, i32, rne, i32, rdn, SX_BASIC, (void) 0)
SX (sx_rdn, SX_DATA, mmul, i32, rdn, i32, rne, SX_BASIC, (void) 0)
SX (sx_rod, SX_DATA, mmul, i32, rod, i32, rnu, SX_BASIC, (void) 0)
SX (sx_mixed, SX_DATA, mmul, i32, rnu, i16, rne, SX_MIXED, (void) 0)
SX (sx_narrow, SX_DATA, mmul, i16, rod, i32, rnu, SX_MIXED, (void) 0)
SX (sx_xor, SX_DATA, mxor, i32, rnu, i32, rnu, SX_BASIC, (void) 0)
SX (sx_pair, SX_DATA, mmul, i32, rnu, i32, rnu, SX_PAIR, (void) 0)
SX (sx_shift, SX_SHIFT, msll, i32, rnu, i32, rnu, SX_BASIC, (void) 0)
SX (sx_add, SX_DATA, madd, i32, rne, i32, rnu, SX_BASIC, (void) 0)
SX (sx_asm, SX_DATA, mmul, i32, rnu, i32, rnu, SX_BASIC,
    __asm__ volatile ("" ::: "memory"))
SX (sx_call, SX_DATA, mmul, i32, rnu, i32, rnu, SX_BASIC, binary_callee ())
SX (sx_join, SX_DATA, mmul, i32, rnu, i32, rnu, SX_BASIC,
    if (binary_condition) __asm__ volatile ("" ::: "memory"))
#undef SX
#undef SX_
#undef SX_DATA
#undef SX_SHIFT
#undef SX_C_i16
#undef SX_C_i32
#undef SX_BASIC
#undef SX_PAIR
#undef SX_MIXED
#ifdef __cplusplus
}
#endif
