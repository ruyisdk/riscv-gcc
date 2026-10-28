#include <riscv_ztt.h>
typedef __UINT32_TYPE__ element;
typedef __riscv_ztt_u32_rnu_1x1_t matrix;
#ifdef __cplusplus
extern "C" {
#endif
extern void bp_callee (void);
#define CHAIN(NAME, EXPR, BOUNDARY) \
__attribute__((noipa)) void bp_##NAME \
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
#if __riscv_xlen == 32
#define BREV8(X) __builtin_riscv_brev8_32 (X)
CHAIN (zip, __builtin_riscv_zip (x), (void) 0)
CHAIN (unzip, __builtin_riscv_unzip (x), (void) 0)
#else
#define BREV8(X) __builtin_riscv_brev8_64 (X)
#endif
CHAIN (brev8, BREV8 (x), (void) 0)
CHAIN (xperm4, __builtin_riscv_xperm4 (x, y), (void) 0)
CHAIN (xperm8, __builtin_riscv_xperm8 (x, y), (void) 0)
CHAIN (barrier, BREV8 (x), __asm__ volatile ("# boundary" ::: "memory"))
CHAIN (call, BREV8 (x), bp_callee ())
CHAIN (plain, x ^ y, (void) 0)
#undef BREV8
#undef CHAIN
#ifdef __cplusplus
}
#endif
