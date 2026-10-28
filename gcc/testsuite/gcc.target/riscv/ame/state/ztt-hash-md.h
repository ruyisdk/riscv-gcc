#include <riscv_ztt.h>
typedef __UINT32_TYPE__ element;
typedef __riscv_ztt_u32_rnu_1x1_t matrix;
#ifdef __cplusplus
extern "C" {
#endif
extern void hash_callee (void);
#define CHAIN(NAME, EXPR, BOUNDARY) \
__attribute__((noipa)) void hash_##NAME \
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
CHAIN (s256sig0, __builtin_riscv_sha256sig0 (x), (void) 0)
CHAIN (s256sig1, __builtin_riscv_sha256sig1 (x), (void) 0)
CHAIN (s256sum0, __builtin_riscv_sha256sum0 (x), (void) 0)
CHAIN (s256sum1, __builtin_riscv_sha256sum1 (x), (void) 0)
CHAIN (sm3p0, __builtin_riscv_sm3p0 (x), (void) 0)
CHAIN (sm3p1, __builtin_riscv_sm3p1 (x), (void) 0)
#if __riscv_xlen == 64
CHAIN (s512sig0, __builtin_riscv_sha512sig0 (x), (void) 0)
CHAIN (s512sig1, __builtin_riscv_sha512sig1 (x), (void) 0)
CHAIN (s512sum0, __builtin_riscv_sha512sum0 (x), (void) 0)
CHAIN (s512sum1, __builtin_riscv_sha512sum1 (x), (void) 0)
#else
CHAIN (s512sig0h, __builtin_riscv_sha512sig0h (x, y), (void) 0)
CHAIN (s512sig0l, __builtin_riscv_sha512sig0l (x, y), (void) 0)
CHAIN (s512sig1h, __builtin_riscv_sha512sig1h (x, y), (void) 0)
CHAIN (s512sig1l, __builtin_riscv_sha512sig1l (x, y), (void) 0)
CHAIN (s512sum0r, __builtin_riscv_sha512sum0r (x, y), (void) 0)
CHAIN (s512sum1r, __builtin_riscv_sha512sum1r (x, y), (void) 0)
#endif
CHAIN (barrier, __builtin_riscv_sha256sig0 (x), __asm__ volatile ("# boundary" ::: "memory"))
CHAIN (call, __builtin_riscv_sm3p0 (x), hash_callee ())
CHAIN (plain, x ^ y, (void) 0)
#undef CHAIN
#ifdef __cplusplus
}
#endif
