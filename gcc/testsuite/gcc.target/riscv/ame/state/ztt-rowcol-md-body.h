#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
extern void binary_callee (void);
extern volatile int binary_condition;
extern volatile long binary_selector;
#if __riscv_ztt_uds <= 32
typedef __INT32_TYPE__ rowcol_element;
#define ROWCOL_TYPE i32
#else
typedef __riscv_ztt_i128_storage_t rowcol_element;
#define ROWCOL_TYPE i128
#endif
#define ROWCOL_(NAME, OP, RM, T, BARRIER) \
__attribute__((noinline, noclone)) \
void NAME (const rowcol_element *a, const rowcol_element *b, \
           rowcol_element *out, rowcol_element *left, rowcol_element *right) \
{ \
  __riscv_ztt_##T##_##RM##_1x1_t x \
    = __riscv_ztt_mls_rm_##T##_##RM##_1x1 (a); \
  __riscv_ztt_##T##_##RM##_1x1_t y \
    = __riscv_ztt_mls_rm_##T##_##RM##_1x1 (b); \
  __riscv_ztt_##T##_##RM##_1x1_t z \
    = __riscv_ztt_##OP##_ew_x_##T##_##RM##_1x1 (x, binary_selector); \
  BARRIER; \
  __riscv_ztt_mss_rm (out, z); \
  __riscv_ztt_mss_rm (left, x); \
  __riscv_ztt_mss_rm (right, y); \
}
#define ROWCOL_EXPAND(NAME, OP, RM, T, BARRIER) ROWCOL_(NAME, OP, RM, T, BARRIER)
#define ROWCOL(NAME, OP, RM, BARRIER) ROWCOL_EXPAND(NAME, OP, RM, ROWCOL_TYPE, BARRIER)
ROWCOL (rowcol_col, mcolbcast, rnu, (void) 0)
ROWCOL (rowcol_rne, mcolbcast, rne, (void) 0)
ROWCOL (rowcol_rdn, mcolbcast, rdn, (void) 0)
ROWCOL (rowcol_rod, mcolbcast, rod, (void) 0)
ROWCOL (rowcol_row, mrowbcast, rnu, (void) 0)
ROWCOL (rowcol_colshift, mcolshift, rnu, (void) 0)
ROWCOL (rowcol_rowshift, mrowshift, rnu, (void) 0)
ROWCOL (rowcol_asm, mcolshift, rnu, __asm__ volatile ("" ::: "memory"))
ROWCOL (rowcol_call, mcolshift, rnu, binary_callee ())
ROWCOL (rowcol_join, mcolshift, rnu,
        if (binary_condition) __asm__ volatile ("" ::: "memory"))
#undef ROWCOL
#undef ROWCOL_EXPAND
#undef ROWCOL_
#undef ROWCOL_TYPE
#ifdef __cplusplus
}
#endif
