#include <riscv_ztt.h>
typedef __UINT32_TYPE__ element_t;
typedef __riscv_ztt_u32_rnu_1x1_t matrix_t;
#if __riscv_xlen == 64
#define BREV8 __builtin_riscv_brev8_64
#else
#define BREV8 __builtin_riscv_brev8_32
#endif
#ifdef __cplusplus
extern "C" {
#endif
extern void bp_tail_call (void);
#define CASE(NAME, EXPR, GAP) \
unsigned long __attribute__((noipa)) \
bp_tail_##NAME (const element_t *in, element_t *out, element_t *saved, \
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
CASE (brev8, BREV8 (a), (void) 0)
CASE (xperm4, __builtin_riscv_xperm4 (a, y), (void) 0)
CASE (xperm8, __builtin_riscv_xperm8 (a, y), (void) 0)
#if __riscv_xlen == 32
CASE (zip, __builtin_riscv_zip (a), (void) 0)
CASE (unzip, __builtin_riscv_unzip (a), (void) 0)
#endif
CASE (asm, BREV8 (a), __asm__ volatile ("# tail boundary" ::: "memory"))
CASE (external, BREV8 (a), bp_tail_call ())
#undef BREV8
#undef CASE
#ifdef __cplusplus
}
#endif
