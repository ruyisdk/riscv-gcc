#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
extern void indexed_descriptor_callee (void);

#define INDEXED_CHAIN(NAME, TYPE, CTYPE, EXPR, GAP) \
__attribute__((noipa)) void NAME \
  (const CTYPE *in, const __INT32_TYPE__ *indices, \
   CTYPE *out, CTYPE *last, int flag) \
{ \
  __riscv_ztt_##TYPE##_1x1_t a = __riscv_ztt_mls_rm_##TYPE##_1x1 (in); \
  __riscv_ztt_i32_rnu_1x1_t i = __riscv_ztt_mls_rm_i32_rnu_1x1 (indices); \
  __riscv_ztt_##TYPE##_1x1_t d = __riscv_ztt_mzero_m_##TYPE##_1x1 (); \
  d = EXPR; \
  __riscv_ztt_mss_rm (out, d); \
  GAP; \
  __riscv_ztt_mss_rm (last, __riscv_ztt_madd_ew_##TYPE##_1x1 (a, a)); \
}
#define FAMILY(N, T, C) \
INDEXED_CHAIN (colgather_##N, T, C, __riscv_ztt_mcolgather_ew_##T##_1x1 (a, i), (void) 0) \
INDEXED_CHAIN (rowgather_##N, T, C, __riscv_ztt_mrowgather_ew_##T##_1x1 (a, i), (void) 0) \
INDEXED_CHAIN (colscatadd_##N, T, C, __riscv_ztt_mcolscatadd_ew_##T##_1x1 (d, a, i), (void) 0) \
INDEXED_CHAIN (rowscatadd_##N, T, C, __riscv_ztt_mrowscatadd_ew_##T##_1x1 (d, a, i), (void) 0) \
INDEXED_CHAIN (colscatmax_##N, T, C, __riscv_ztt_mcolscatmax_ew_##T##_1x1 (d, a, i), (void) 0) \
INDEXED_CHAIN (rowscatmax_##N, T, C, __riscv_ztt_mrowscatmax_ew_##T##_1x1 (d, a, i), (void) 0)
FAMILY (int, i32_rnu, __INT32_TYPE__)
FAMILY (fp, f32_rne, float)
#define BOUNDARY(NAME, EXPR, GAP) \
  INDEXED_CHAIN (NAME, f32_rne, float, EXPR, GAP)
#define GATHER __riscv_ztt_mcolgather_ew_f32_rne_1x1 (a, i)
#define SCATTER __riscv_ztt_mcolscatadd_ew_f32_rne_1x1 (d, a, i)
BOUNDARY (gather_asm, GATHER, __asm__ volatile ("" ::: "memory"))
BOUNDARY (gather_call, GATHER, indexed_descriptor_callee ())
BOUNDARY (gather_join, GATHER, if (flag) indexed_descriptor_callee ())
BOUNDARY (scatter_asm, SCATTER, __asm__ volatile ("" ::: "memory"))
BOUNDARY (scatter_call, SCATTER, indexed_descriptor_callee ())
BOUNDARY (scatter_join, SCATTER, if (flag) indexed_descriptor_callee ())
#undef SCATTER
#undef GATHER
#undef BOUNDARY
#undef FAMILY
#undef INDEXED_CHAIN
#ifdef __cplusplus
}
#endif
