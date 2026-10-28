#include <riscv_ztt.h>
#ifndef UI_TYPE
#define UI_TYPE i32_rnu
#define UI_ELEMENT __INT32_TYPE__
#endif
#ifndef UI_SHAPE
#define UI_SHAPE 1x1
#endif
#define UI_TYPE_(T, S) __riscv_ztt_##T##_##S##_t
#define UI_T(T, S) UI_TYPE_(T, S)
#define UI_OP_(F, T, S) __riscv_ztt_##F##_##T##_##S
#define UI_EXPAND(F, T, S) UI_OP_(F, T, S)
#define UI_OP(F) UI_EXPAND(F, UI_TYPE, UI_SHAPE)
#ifdef __cplusplus
extern "C" {
#endif
extern void ur_callee (void);
extern volatile unsigned long ur_observed;
#define UR_CASE(NAME, FIRST, GAP, SECOND, AFTER, SAVE) \
void ur_##NAME (const UI_ELEMENT *in, UI_ELEMENT *out, UI_ELEMENT *saved) \
{ \
  UI_T(UI_TYPE, UI_SHAPE) a = UI_OP(mls_rm) (in); \
  UI_T(UI_TYPE, UI_SHAPE) b = UI_OP(FIRST) (a); \
  GAP; \
  UI_T(UI_TYPE, UI_SHAPE) v = UI_OP(SECOND) (b); \
  AFTER; \
  __riscv_ztt_mss_rm (out, v); \
  SAVE; \
}
UR_CASE(max_min, mreducemax_row, , mreducemin_row, , )
UR_CASE(min_max, mreducemin_col, , mreducemax_col, , )
UR_CASE(sum_prefix_row, mreduceadd_row, , mprefixmax_row, , )
UR_CASE(sum_prefix_col, mreduceadd_col, , mprefixmax_col, , )
UR_CASE(sum_max, mreduceadd_col, , mreducemax_col, , )
UR_CASE(min_prefix, mreducemin_row, , mprefixmax_row, , )
UR_CASE(copy, mreduceadd_row, b = UI_OP(mcopy_m2m) (b);
        b = UI_OP(mcopy_m2m) (b); b = UI_OP(mcopy_m2m) (b);
        b = UI_OP(mcopy_m2m) (b), mreducemin_row, , )
UR_CASE(live, mreducemax_col, , mprefixmax_col, , __riscv_ztt_mss_rm (saved, a))
UR_CASE(after_call, mreducemin_col, , mreducemax_col, ur_callee (),
        __riscv_ztt_mss_rm (saved, b))
UR_CASE(call, mreducemax_row, ur_callee (), mreducemin_row, , )
UR_CASE(asm, mreducemin_col, __asm__ volatile ("" ::: "memory"), mprefixmax_col, , )
UR_CASE(memory, mreduceadd_row, ur_observed = 1, mreducemax_row, , )
UR_CASE(flags, mreducemax_col, __asm__ volatile ("csrw amefflags,zero" ::: "memory"),
        mreducemin_col, , )
UR_CASE(wrong, mreducemax_row, , mreducemin_col, , )
UR_CASE(add, mreducemax_row, , mreduceadd_row, , )
UR_CASE(abs, mreducemin_col, , mabs_ew, , )
void ur_reference (const UI_ELEMENT *in, UI_ELEMENT *out, UI_ELEMENT *)
{
  UI_T(UI_TYPE, UI_SHAPE) a = UI_OP(mls_rm) (in);
  __riscv_ztt_mss_rm (out, UI_OP(mreduceadd_row) (a));
}
#ifdef __cplusplus
}
#endif
