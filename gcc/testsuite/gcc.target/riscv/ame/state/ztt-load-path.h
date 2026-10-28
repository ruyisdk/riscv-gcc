#include <riscv_ztt.h>
typedef __INT32_TYPE__ i32;
typedef __UINT32_TYPE__ u32;
typedef __SIZE_TYPE__ usize;
typedef __riscv_ztt_i32_rnu_accx1_t accumulator;
#define load __riscv_ztt_mls_rm_i32_rnu_1x1

#ifdef __cplusplus
extern "C" {
#endif
extern void path_callee (void);

#define PATH(NAME, BARRIER) \
void NAME (i32 *out, const i32 *seed, const i32 *right, \
           i32 *work, const i32 *input, usize n, usize tiles) \
{ \
  accumulator acc = __riscv_ztt_mcopy_m2a_i32_rnu_accx1 (load (seed)); \
  for (usize tile = 0; tile < tiles; ++tile) \
    { \
      for (usize row = 0; row < n; ++row) \
        for (usize col = 0; col < n; ++col) \
          work[row*n+col] = col <= row ? input[row*n+col] : 0; \
      BARRIER; \
      acc = __riscv_ztt_mmulacc_2d_i32_rnu_accx1 \
        (acc, load (work), load (right)); \
    } \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (acc)); \
}

PATH (path_pack, (void)0)
PATH (path_call, path_callee ())
PATH (path_asm, asm volatile ("# Md boundary" ::: "memory"))

#ifdef __cplusplus
}
#endif
