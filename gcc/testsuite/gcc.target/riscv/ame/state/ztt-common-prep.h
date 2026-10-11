#include "ztt-elementwise-md-body.h"
#include "ztt-scalar-md-body.h"
#include "ztt-ternary-md-body.h"
#include "ztt-ternary-x-md-body.h"

#ifdef __cplusplus
extern "C" {
#endif
#define LOAD(P) __riscv_ztt_mls_rm_i32_rnu_1x1 (P)
#define KEEP(V) __asm__ volatile ("" : : "Wmr" (V))
#define BARRIER() __asm__ volatile ("" ::: "memory")
#define INDEXED(NAME, OP, OLD) \
void NAME (const __INT32_TYPE__ *a, const __INT32_TYPE__ *b) \
{ \
  __riscv_ztt_i32_rnu_1x1_t x = LOAD (a), y = LOAD (b); \
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_##OP##_i32_rnu_1x1 (OLD x, y); \
  KEEP (d); \
}
#define OLD x,
INDEXED (gather_col, mcolgather_ew, )
INDEXED (gather_row, mrowgather_ew, )
INDEXED (scatter_add_col, mcolscatadd_ew, OLD)
INDEXED (scatter_add_row, mrowscatadd_ew, OLD)
INDEXED (scatter_max_col, mcolscatmax_ew, OLD)
INDEXED (scatter_max_row, mrowscatmax_ew, OLD)
#undef OLD
#undef INDEXED

void binary_partial (const __INT32_TYPE__ *a, const __INT32_TYPE__ *b)
{
  __riscv_ztt_i32_rnu_1x1_t x = LOAD (a);
  BARRIER ();
  __riscv_ztt_i32_rnu_1x1_t y = LOAD (b);
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mmul_ew_i32_rnu_1x1 (x, y);
  KEEP (d);
}

void binary_boundary (const __INT32_TYPE__ *a, const __INT32_TYPE__ *b)
{
  __riscv_ztt_i32_rnu_1x1_t x = LOAD (a), y = LOAD (b);
  BARRIER ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mmul_ew_i32_rnu_1x1 (x, y);
  KEEP (d);
}

void scalar_boundary (const __INT32_TYPE__ *a, __INT32_TYPE__ scalar)
{
  __riscv_ztt_i32_rnu_1x1_t x = LOAD (a);
  BARRIER ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mmul_ew_x_i32_rnu_1x1_i32_rne
    (x, __riscv_ztt_scalar_make_i32_rne (scalar));
  KEEP (d);
}

void ternary_boundary (const __INT32_TYPE__ *a, const __INT32_TYPE__ *b,
                       const __INT32_TYPE__ *c)
{
  __riscv_ztt_i32_rnu_1x1_t x = LOAD (a), y = LOAD (b), old = LOAD (c);
  BARRIER ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mmulacc_ew_i32_rnu_1x1 (old, x, y);
  KEEP (d);
}

void fused_fp (const float *a, const float *b, const float *c)
{
  __riscv_ztt_f32_rne_1x1_t x = __riscv_ztt_mls_rm_f32_rne_1x1 (a);
  __riscv_ztt_f32_rne_1x1_t y = __riscv_ztt_mls_rm_f32_rne_1x1 (b);
  __riscv_ztt_f32_rne_1x1_t old = __riscv_ztt_mls_rm_f32_rne_1x1 (c);
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mmulacc_ew_f32_rne_1x1 (old, x, y);
  KEEP (d);
}
#undef LOAD
#undef KEEP
#undef BARRIER
#ifdef __cplusplus
}
#endif
