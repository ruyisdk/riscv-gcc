#include <riscv_ztt.h>
typedef __UINT32_TYPE__ element;
typedef __riscv_ztt_u32_rnu_1x1_t matrix;
#if __riscv_xlen == 64
#define CLMUL __builtin_riscv_clmul_64
#define CLMULH __builtin_riscv_clmulh_64
#define CLMULR __builtin_riscv_clmulr_64
#else
#define CLMUL __builtin_riscv_clmul_32
#define CLMULH __builtin_riscv_clmulh_32
#define CLMULR __builtin_riscv_clmulr_32
#endif
#ifdef __cplusplus
extern "C" {
#endif
extern void cm_callee (void);
#define CHAIN(NAME, EXPR, BOUNDARY) \
__attribute__((noipa)) void cm_##NAME \
  (const element *in, element *work, element *out, \
   volatile unsigned long *control, unsigned long y) \
{ \
  matrix a = __riscv_ztt_mls_rm_u32_rnu_1x1 (in); \
  __riscv_ztt_mss_rm (work, a); \
  unsigned long x = *control; \
  *control = EXPR; \
  BOUNDARY; \
  matrix b = __riscv_ztt_mls_rm_u32_rnu_1x1 (work); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_madd_ew_u32_rnu_1x1 (a, b)); \
}
CHAIN (low, CLMUL (x, y), (void) 0)
CHAIN (high, CLMULH (x, y), (void) 0)
CHAIN (reverse, CLMULR (x, y), (void) 0)
CHAIN (crc, __builtin_crc32_data32 (x, y, 0x04c11db7), (void) 0)
CHAIN (revcrc, __builtin_rev_crc32_data32 (x, y, 0x04c11db7), (void) 0)
CHAIN (barrier, CLMUL (x, y), __asm__ volatile ("# boundary" ::: "memory"))
CHAIN (call, CLMUL (x, y), cm_callee ())
CHAIN (plain, x ^ y, (void) 0)
#undef CHAIN
#ifdef __cplusplus
}
#endif
