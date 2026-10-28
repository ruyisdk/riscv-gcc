#include <riscv_ztt.h>
typedef __SIZE_TYPE__ usize;
typedef __UINT32_TYPE__ u32;
typedef __riscv_ztt_u32_1x1_t matrix;
#define LOAD __riscv_ztt_mls_rm_u32_1x1
#define STORE __riscv_ztt_mss_rm
#define ARGS u32 *out, const u32 *in, const u32 *initial, \
  const u32 *index, usize count, usize step
#ifdef __cplusplus
extern "C" {
#endif
extern void indexed_loop_callee (void);

#define GATHER(NAME, OP, GAP) \
void NAME (ARGS) \
{ \
  matrix ix = LOAD (index); \
  for (usize i = 0; i < count; ++i) \
    { \
      GAP; \
      STORE (out, __riscv_ztt_##OP##_u32_1x1 (LOAD (in), ix)); \
      in += step; out += step; \
    } \
}
#define SCATTER(NAME, OP, GAP) \
void NAME (ARGS) \
{ \
  matrix d = LOAD (initial), ix = LOAD (index); \
  for (usize i = 0; i < count; ++i) \
    { \
      GAP; \
      d = __riscv_ztt_##OP##_u32_1x1 (d, LOAD (in), ix); \
      in += step; \
    } \
  STORE (out, d); \
}
GATHER (indexed_colgather, mcolgather_ew, (void) 0)
GATHER (indexed_rowgather, mrowgather_ew, (void) 0)
SCATTER (indexed_coladd, mcolscatadd_ew, (void) 0)
SCATTER (indexed_rowadd, mrowscatadd_ew, (void) 0)
SCATTER (indexed_colmax, mcolscatmax_ew, (void) 0)
SCATTER (indexed_rowmax, mrowscatmax_ew, (void) 0)
GATHER (indexed_gather_call, mcolgather_ew, indexed_loop_callee ())
SCATTER (indexed_scatter_call, mcolscatadd_ew, indexed_loop_callee ())
GATHER (indexed_gather_asm, mcolgather_ew, asm volatile ("# Md boundary" ::: "memory"))
SCATTER (indexed_scatter_asm, mcolscatadd_ew, asm volatile ("# Md boundary" ::: "memory"))

void indexed_gather_mixed (float *out, const float *in, const u32 *index,
			   usize count, usize step)
{
  matrix ix = LOAD (index);
  for (usize i = 0; i < count; ++i)
    {
      STORE (out, __riscv_ztt_mcolgather_ew_f32_rne_1x1
	     (__riscv_ztt_mls_rm_f32_rne_1x1 (in), ix));
      in += step; out += step;
    }
}

void indexed_scatter_mixed (float *out, const float *in, const float *initial,
			    const u32 *index, usize count, usize step)
{
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mls_rm_f32_rne_1x1 (initial);
  matrix ix = LOAD (index);
  for (usize i = 0; i < count; ++i)
    {
      d = __riscv_ztt_mcolscatadd_ew_f32_rne_1x1
	(d, __riscv_ztt_mls_rm_f32_rne_1x1 (in), ix);
      in += step;
    }
  STORE (out, d);
}
#ifdef __cplusplus
}
#endif
