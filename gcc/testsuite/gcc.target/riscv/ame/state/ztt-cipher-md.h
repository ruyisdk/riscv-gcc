#include <riscv_ztt.h>
typedef __UINT32_TYPE__ element;
typedef __riscv_ztt_u32_rnu_1x1_t matrix;
#ifdef __cplusplus
extern "C" {
#endif
extern void cp_callee (void);
#define CHAIN(NAME, EXPR, BOUNDARY) \
__attribute__((noipa)) void cp_##NAME \
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
#define AES(X,Y) __builtin_riscv_aes32esi (X,Y,0)
CHAIN (esmi, __builtin_riscv_aes32esmi (x,y,3), (void) 0)
CHAIN (dsi, __builtin_riscv_aes32dsi (x,y,1), (void) 0)
CHAIN (dsmi, __builtin_riscv_aes32dsmi (x,y,2), (void) 0)
#else
#define AES(X,Y) __builtin_riscv_aes64ks2 (X,Y)
CHAIN (es, __builtin_riscv_aes64es (x,y), (void) 0)
CHAIN (esm, __builtin_riscv_aes64esm (x,y), (void) 0)
CHAIN (ds, __builtin_riscv_aes64ds (x,y), (void) 0)
CHAIN (dsm, __builtin_riscv_aes64dsm (x,y), (void) 0)
CHAIN (im, __builtin_riscv_aes64im (x), (void) 0)
CHAIN (ks1i, __builtin_riscv_aes64ks1i (x,10), (void) 0)
#endif
CHAIN (aes, AES (x,y), (void) 0)
CHAIN (sm4ed, __builtin_riscv_sm4ed (x,y,0), (void) 0)
CHAIN (sm4ks, __builtin_riscv_sm4ks (x,y,3), (void) 0)
CHAIN (barrier, AES (x,y), __asm__ volatile ("# boundary" ::: "memory"))
CHAIN (call, AES (x,y), cp_callee ())
CHAIN (plain, x ^ y, (void) 0)
#undef AES
#undef CHAIN
#ifdef __cplusplus
}
#endif
