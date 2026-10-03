#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
/* The barrier separates known from unknown source Md without changing data.  */
#define KERNEL(NAME, L, R, MASK) \
__attribute__((noinline,noclone)) \
void NAME (const __INT32_TYPE__ *left, const __INT32_TYPE__ *right, \
           const __INT32_TYPE__ *old, __INT32_TYPE__ *out, \
           __INT32_TYPE__ *live_left, __INT32_TYPE__ *live_right) \
{ \
  __riscv_ztt_i32_rnu_accx1_t d = __riscv_ztt_mcopy_m2a_i32_rnu_accx1 ( \
    __riscv_ztt_mls_rm_i32_rnu_1x1 (old)); \
  __riscv_ztt_##L##_1x1_t a; \
  __riscv_ztt_##R##_1x1_t b; \
  if (!((MASK) & 1)) a = __riscv_ztt_mls_rm_##L##_1x1 (left); \
  if (!((MASK) & 2)) b = __riscv_ztt_mls_rm_##R##_1x1 (right); \
  __asm__ volatile ("" ::: "memory"); \
  if ((MASK) & 1) a = __riscv_ztt_mls_rm_##L##_1x1 (left); \
  if ((MASK) & 2) b = __riscv_ztt_mls_rm_##R##_1x1 (right); \
  d = __riscv_ztt_mmulacc_2d_i32_rnu_accx1 (d, a, b); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (d)); \
  __riscv_ztt_mss_rm (live_left, a); \
  __riscv_ztt_mss_rm (live_right, b); \
}
#define CASES(K) \
  KERNEL (prepared_i##K, i32_rnu, i32_rnu, K) \
  KERNEL (prepared_m##K, i32_rne, i32_rdn, K)
CASES (0)
CASES (1)
CASES (2)
CASES (3)
#undef CASES
#undef KERNEL
#ifdef __cplusplus
}
#endif
