#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
/* The second multiply must reuse the original descriptors of both sources.  */
#define CHAIN(SIDE) \
__attribute__((noinline,noclone)) \
void partial_chain##SIDE (const __INT32_TYPE__ *left, \
                         const __INT32_TYPE__ *right, \
                         const __INT32_TYPE__ *old, __INT32_TYPE__ *out, \
                         __INT32_TYPE__ *live_left, __INT32_TYPE__ *live_right) \
{ \
  __riscv_ztt_i32_rnu_accx1_t d = __riscv_ztt_mcopy_m2a_i32_rnu_accx1 ( \
    __riscv_ztt_mls_rm_i32_rnu_1x1 (old)); \
  __riscv_ztt_i32_rne_1x1_t a; \
  __riscv_ztt_i32_rdn_1x1_t b; \
  if (SIDE == 2) a = __riscv_ztt_mls_rm_i32_rne_1x1 (left); \
  if (SIDE == 1) b = __riscv_ztt_mls_rm_i32_rdn_1x1 (right); \
  __asm__ volatile ("" ::: "memory"); \
  if (SIDE == 1) a = __riscv_ztt_mls_rm_i32_rne_1x1 (left); \
  if (SIDE == 2) b = __riscv_ztt_mls_rm_i32_rdn_1x1 (right); \
  d = __riscv_ztt_mmulacc_2d_i32_rnu_accx1 (d, a, b); \
  d = __riscv_ztt_mmulacc_2d_i32_rnu_accx1 (d, a, b); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (d)); \
  __riscv_ztt_mss_rm (live_left, a); \
  __riscv_ztt_mss_rm (live_right, b); \
}
CHAIN (1)
CHAIN (2)
#undef CHAIN
#ifdef __cplusplus
}
#endif
