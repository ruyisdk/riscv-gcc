#include <riscv_ztt.h>
typedef __UINT32_TYPE__ element_t;
typedef __riscv_ztt_u32_rnu_1x1_t matrix_t;
#if __riscv_xlen == 64
#define CLMUL __builtin_riscv_clmul_64
#define CLMULH __builtin_riscv_clmulh_64
#define CLMULR __builtin_riscv_clmulr_64
#define SIG512(A, B) __builtin_riscv_sha512sig0 (A)
#else
#define CLMUL __builtin_riscv_clmul_32
#define CLMULH __builtin_riscv_clmulh_32
#define CLMULR __builtin_riscv_clmulr_32
#define SIG512(A, B) __builtin_riscv_sha512sig0h (A, B)
#endif
#ifdef __cplusplus
extern "C" {
#endif
extern void hash_tail_call (void);
#define CASE(NAME, EXPR, GAP) \
unsigned long __attribute__((noipa)) \
hash_tail_##NAME (const element_t *in, element_t *out, element_t *saved, \
                  const unsigned long *x, unsigned long y) \
{ \
  matrix_t d = __riscv_ztt_mls_rm_u32_rnu_1x1 (in); \
  matrix_t result = __riscv_ztt_mrowscatadd_ew_u32_rnu_1x1 (d, d, d); \
  __riscv_ztt_mss_rm (out, result); \
  GAP; \
  unsigned long a = *x; \
  __riscv_ztt_mss_rm (saved, d); \
  return EXPR; \
}
CASE (low, CLMUL (a, y), (void) 0)
CASE (high, CLMULH (a, y), (void) 0)
CASE (reverse, CLMULR (a, y), (void) 0)
CASE (s256, __builtin_riscv_sha256sig0 (a), (void) 0)
CASE (s512, SIG512 (a, y), (void) 0)
CASE (sm3, __builtin_riscv_sm3p0 (a), (void) 0)
CASE (asm, __builtin_riscv_sha256sig0 (a), __asm__ volatile ("# tail boundary" ::: "memory"))
CASE (external, __builtin_riscv_sha256sig0 (a), hash_tail_call ())
#undef CASE
#ifdef __cplusplus
}
#endif
