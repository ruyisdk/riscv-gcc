#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
extern void binary_callee (void);
extern volatile int binary_condition;
#if __riscv_ztt_uds <= 16
#define EW_BASIC 1
#define EW_PAIR 2
#define EW_MIXED 1
#elif __riscv_ztt_uds == 32
#define EW_BASIC 1
#define EW_PAIR 2
#define EW_MIXED 2
#elif __riscv_ztt_uds == 64
#define EW_BASIC 2
#define EW_PAIR 4
#define EW_MIXED 4
#else
#define EW_BASIC 4
#define EW_PAIR 8
#define EW_MIXED 8
#endif
#define EW_C_i16 __INT16_TYPE__
#define EW_C_i32 __INT32_TYPE__
#define EW_C_u32 __UINT32_TYPE__
#define EW_(NAME, OP, D, DR, L, LR, R, RR, Q, RHS, BARRIER) \
__attribute__((noinline, noclone)) \
void NAME (const void *a, const void *b, void *out, void *left, void *right) \
{ \
  __riscv_ztt_##L##_##LR##_1x##Q##_t x \
    = __riscv_ztt_mls_rm_##L##_##LR##_1x##Q ((const EW_C_##L *) a); \
  __riscv_ztt_##R##_##RR##_1x##Q##_t y \
    = __riscv_ztt_mls_rm_##R##_##RR##_1x##Q ((const EW_C_##R *) b); \
  __riscv_ztt_##D##_##DR##_1x##Q##_t z \
    = __riscv_ztt_##OP##_ew_##D##_##DR##_1x##Q (x, RHS); \
  BARRIER; \
  __riscv_ztt_mss_rm ((EW_C_##D *) out, z); \
  __riscv_ztt_mss_rm ((EW_C_##L *) left, x); \
  __riscv_ztt_mss_rm ((EW_C_##R *) right, y); \
}
#define EW(...) EW_ (__VA_ARGS__)
EW (ew_mul, mmul, i32, rnu, i32, rnu, i32, rnu, EW_BASIC, y, (void) 0)
EW (ew_rne, mmul, i32, rne, i32, rdn, i32, rod, EW_BASIC, y, (void) 0)
EW (ew_rdn, mmul, i32, rdn, i32, rne, i32, rnu, EW_BASIC, y, (void) 0)
EW (ew_rod, mmul, i32, rod, i32, rnu, i32, rne, EW_BASIC, y, (void) 0)
EW (ew_mixed, mmul, i32, rnu, i16, rne, u32, rdn, EW_MIXED, y, (void) 0)
EW (ew_narrow, mmul, i16, rod, i32, rnu, i16, rne, EW_MIXED, y, (void) 0)
EW (ew_shared, mmul, i32, rnu, i32, rnu, i32, rnu, EW_BASIC, x, (void) 0)
EW (ew_pair, mmul, i32, rnu, i32, rnu, i32, rnu, EW_PAIR, y, (void) 0)
EW (ew_shift, msll, i32, rnu, i32, rnu, u32, rnu, EW_BASIC, y, (void) 0)
EW (ew_add, madd, i32, rne, i32, rnu, i32, rod, EW_BASIC, y, (void) 0)
EW (ew_asm, mmul, i32, rnu, i32, rnu, i32, rnu, EW_BASIC, y,
    __asm__ volatile ("" ::: "memory"))
EW (ew_call, mmul, i32, rnu, i32, rnu, i32, rnu, EW_BASIC, y, binary_callee ())
EW (ew_join, mmul, i32, rnu, i32, rnu, i32, rnu, EW_BASIC, y,
    if (binary_condition) __asm__ volatile ("" ::: "memory"))
#undef EW
#undef EW_
#undef EW_C_i16
#undef EW_C_i32
#undef EW_C_u32
#undef EW_BASIC
#undef EW_PAIR
#undef EW_MIXED
#ifdef __cplusplus
}
#endif
