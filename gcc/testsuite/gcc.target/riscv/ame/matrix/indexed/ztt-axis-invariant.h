#include <riscv_ztt.h>

#ifndef AI_TYPE
#define AI_TYPE i32_rnu
#define AI_ELEMENT __INT32_TYPE__
#endif
#define AI_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define AI_NAME_I(f, t) AI_NAME_(f, t)
#define AI_NAME(f) AI_NAME_I(f, AI_TYPE)
#define AI_T_(t) __riscv_ztt_##t##_1x1_t
#define AI_T(t) AI_T_(t)
typedef AI_ELEMENT ai_element;
typedef AI_T(AI_TYPE) ai_matrix;
#define AI_ARGS const __INT32_TYPE__ *index, ai_element *out, \
  ai_element *extra, __INT32_TYPE__ *saved, unsigned long k
#define AI_INDEX __riscv_ztt_i32_rnu_1x1_t i = __riscv_ztt_mls_rm_i32_rnu_1x1 (index)
#define AI_COL ai_matrix a = AI_NAME(mcolid_ew) ()
#define AI_ROW ai_matrix a = AI_NAME(mrowid_ew) ()
#define AI_STORE(a) __riscv_ztt_mss_rm (out, a)
#define AI_SAVE __riscv_ztt_mss_rm (saved, i)

#ifdef __cplusplus
extern "C" {
#endif
extern void ai_callee (void);
extern volatile unsigned long ai_observed;

void ai_row_bcast (AI_ARGS) { AI_COL; AI_STORE (AI_NAME(mrowbcast_ew_x) (a, 0)); }
void ai_col_bcast (AI_ARGS) { AI_ROW; AI_STORE (AI_NAME(mcolbcast_ew_x) (a, 0)); }
void ai_high (AI_ARGS)
{
  AI_COL; AI_STORE (AI_NAME(mrowbcast_ew_x) (a, (unsigned long) 0x100000000ULL));
}
void ai_copy (AI_ARGS)
{
  AI_ROW; ai_matrix b = AI_NAME(mcopy_m2m) (a);
  AI_STORE (AI_NAME(mcolbcast_ew_x) (b, 0));
}
void ai_row_gather (AI_ARGS)
{
  AI_INDEX; AI_COL; AI_STORE (AI_NAME(mrowgather_ew) (a, i)); AI_SAVE;
}
void ai_col_gather (AI_ARGS)
{
  AI_INDEX; AI_ROW; AI_STORE (AI_NAME(mcolgather_ew) (a, i)); AI_SAVE;
}
void ai_shared (AI_ARGS)
{
  AI_INDEX; AI_COL; AI_STORE (AI_NAME(mrowgather_ew) (a, i));
  __riscv_ztt_mss_rm (extra, a); AI_SAVE;
}
void ai_row_wrong (AI_ARGS) { AI_ROW; AI_STORE (AI_NAME(mrowbcast_ew_x) (a, 0)); }
void ai_col_wrong (AI_ARGS) { AI_COL; AI_STORE (AI_NAME(mcolbcast_ew_x) (a, 0)); }
void ai_gather_wrong (AI_ARGS)
{
  AI_INDEX; AI_COL; AI_STORE (AI_NAME(mcolgather_ew) (a, i)); AI_SAVE;
}
void ai_nonzero (AI_ARGS) { AI_COL; AI_STORE (AI_NAME(mrowbcast_ew_x) (a, 1)); }
void ai_dynamic (AI_ARGS) { AI_ROW; AI_STORE (AI_NAME(mcolbcast_ew_x) (a, k)); }
void ai_invalid (AI_ARGS) { AI_COL; AI_STORE (AI_NAME(mrowbcast_ew_x) (a, ~0UL)); }
void ai_call (AI_ARGS)
{
  AI_INDEX; AI_COL; ai_callee ();
  AI_STORE (AI_NAME(mrowgather_ew) (a, i)); AI_SAVE;
}
void ai_asm (AI_ARGS)
{
  AI_INDEX; AI_ROW; asm volatile ("" ::: "memory");
  AI_STORE (AI_NAME(mcolgather_ew) (a, i)); AI_SAVE;
}
void ai_memory (AI_ARGS)
{
  AI_COL; ai_observed = k; AI_STORE (AI_NAME(mrowbcast_ew_x) (a, 0));
}
void ai_unstored (AI_ARGS)
{
  AI_INDEX; AI_COL; AI_STORE (AI_NAME(mrowgather_ew) (a, i));
}
void ai_reference (AI_ARGS) { AI_INDEX; AI_COL; AI_STORE (a); AI_SAVE; }
#ifdef __cplusplus
}
#endif
