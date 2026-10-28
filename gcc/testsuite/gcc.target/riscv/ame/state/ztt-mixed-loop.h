#include <riscv_ztt.h>
typedef __SIZE_TYPE__ usize;
typedef __UINT32_TYPE__ u32;
typedef __riscv_ztt_f32_rne_1x1_t matrix;
typedef __riscv_ztt_u32_1x1_t indices;
#define LOAD __riscv_ztt_mls_rm_f32_rne_1x1
#define INDEX __riscv_ztt_mls_rm_u32_1x1
#define STORE __riscv_ztt_mss_rm
#define ARGS float *out, const float *in, const float *initial, \
  const u32 *index, usize count, usize step
#ifdef __cplusplus
extern "C" {
#endif

#define GATHER(NAME, OP) \
void NAME (ARGS) \
{ \
  indices ix = INDEX (index); \
  for (usize i = 0; i < count; ++i) \
    { \
      STORE (out, __riscv_ztt_##OP##_f32_rne_1x1 (LOAD (in), ix)); \
      in += step; out += step; \
    } \
}
#define SCATTER(NAME, OP) \
void NAME (ARGS) \
{ \
  matrix d = LOAD (initial); \
  indices ix = INDEX (index); \
  for (usize i = 0; i < count; ++i) \
    { \
      d = __riscv_ztt_##OP##_f32_rne_1x1 (d, LOAD (in), ix); \
      in += step; \
    } \
  STORE (out, d); \
}
GATHER (mixed_colgather, mcolgather_ew)
GATHER (mixed_rowgather, mrowgather_ew)
SCATTER (mixed_coladd, mcolscatadd_ew)
SCATTER (mixed_rowadd, mrowscatadd_ew)
SCATTER (mixed_colmax, mcolscatmax_ew)
SCATTER (mixed_rowmax, mrowscatmax_ew)

#ifdef __cplusplus
}
#endif
