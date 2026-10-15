#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif
extern void am_callee (void);
typedef __INT32_TYPE__ element_t;
typedef __riscv_ztt_i32_rnu_1x1_t matrix_t;
typedef __riscv_ztt_i32_rnu_accx1_t acc_t;
#define LOAD(p) __riscv_ztt_mls_rm_i32_rnu_1x1 (p)
#define FROM(m) __riscv_ztt_mcopy_m2a_i32_rnu_accx1 (m)
#define TO(a) __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (a)
#define MUL(a, x, y) __riscv_ztt_mmulacc_2d_i32_rnu_accx1 (a, x, y)
#define CASE(NAME, LEFT, GAP) \
void __attribute__((noipa)) \
NAME (const element_t *in, const element_t *other, element_t *out, \
      element_t *old, element_t *live) \
{ \
  matrix_t m = LOAD (in); \
  matrix_t n = LOAD (other); \
  acc_t a = FROM (m); \
  acc_t b = a; \
  GAP; \
  b = MUL (b, LEFT, m); \
  __riscv_ztt_mss_rm (out, TO (b)); \
  __riscv_ztt_mss_rm (old, TO (a)); \
  __riscv_ztt_mss_rm (live, m); \
}
CASE (am_same, m, (void) 0)
CASE (am_distinct, n, (void) 0)
CASE (am_call, n, am_callee ())
CASE (am_asm, n, __asm__ volatile ("" ::: "memory"))
#ifdef __cplusplus
}
#endif
