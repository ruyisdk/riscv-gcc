#include <riscv_ztt.h>
typedef __UINT32_TYPE__ element;
typedef __riscv_ztt_u32_rnu_1x1_t matrix;
#ifdef __cplusplus
extern "C" {
#endif
extern void cache_callee (void);
#define CHAIN(NAME, EXPR, BOUNDARY) \
__attribute__((noipa)) void cache_##NAME \
  (const element *in, element *work, element *out) \
{ \
  matrix a = __riscv_ztt_mls_rm_u32_rnu_1x1 (in); \
  __riscv_ztt_mss_rm (work, a); \
  EXPR; \
  BOUNDARY; \
  matrix b = __riscv_ztt_mls_rm_u32_rnu_1x1 (work); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_madd_ew_u32_rnu_1x1 (a, b)); \
}
CHAIN (clean, __builtin_riscv_zicbom_cbo_clean (work), (void) 0)
CHAIN (flush, __builtin_riscv_zicbom_cbo_flush (work), (void) 0)
CHAIN (inval, __builtin_riscv_zicbom_cbo_inval (work), (void) 0)
CHAIN (zero, __builtin_riscv_zicboz_cbo_zero (work), (void) 0)
CHAIN (prefetch_r, __builtin_prefetch (work, 0, 3), (void) 0)
CHAIN (prefetch_w, __builtin_prefetch (work, 1, 3), (void) 0)
CHAIN (barrier, __builtin_riscv_zicbom_cbo_clean (work),
       __asm__ volatile ("# boundary" ::: "memory"))
CHAIN (call, __builtin_riscv_zicbom_cbo_clean (work), cache_callee ())
CHAIN (plain, (void) 0, (void) 0)
#undef CHAIN
#ifdef __cplusplus
}
#endif
