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
extern void ui_callee (void);
extern volatile unsigned long ui_observed;
#define UI_CASE(NAME, FIRST, GAP, SECOND, AFTER, SAVE) \
void ui_##NAME (const UI_ELEMENT *in, UI_ELEMENT *out, UI_ELEMENT *saved) \
{ \
  UI_T(UI_TYPE, UI_SHAPE) a = UI_OP(mls_rm) (in); \
  UI_T(UI_TYPE, UI_SHAPE) b = UI_OP(FIRST) (a); \
  GAP; \
  UI_T(UI_TYPE, UI_SHAPE) v = UI_OP(SECOND) (b); \
  AFTER; \
  __riscv_ztt_mss_rm (out, v); \
  SAVE; \
}
UI_CASE(abs, mabs_ew, , mabs_ew, , )
UI_CASE(pmaxr, mprefixmax_row, , mprefixmax_row, , )
UI_CASE(pmaxc, mprefixmax_col, , mprefixmax_col, , )
UI_CASE(rmaxr, mreducemax_row, , mreducemax_row, , )
UI_CASE(rmaxc, mreducemax_col, , mreducemax_col, , )
UI_CASE(rminr, mreducemin_row, , mreducemin_row, , )
UI_CASE(rminc, mreducemin_col, , mreducemin_col, , )
UI_CASE(copy, mabs_ew, b = UI_OP(mcopy_m2m) (b), mabs_ew, , )
UI_CASE(live, mprefixmax_row, , mprefixmax_row, , __riscv_ztt_mss_rm (saved, a))
UI_CASE(after_call, mprefixmax_row, , mprefixmax_row, ui_callee (),
        __riscv_ztt_mss_rm (saved, b))
UI_CASE(call, mprefixmax_row, ui_callee (), mprefixmax_row, , )
UI_CASE(asm, mprefixmax_row, __asm__ volatile ("nop" ::: "memory"), mprefixmax_row, , )
UI_CASE(memory, mprefixmax_row, ui_observed = 1, mprefixmax_row, , )
UI_CASE(flags, mabs_ew, __asm__ volatile ("csrw amexsat,zero" ::: "memory"), mabs_ew, , )
UI_CASE(different, mprefixmax_row, , mprefixmax_col, , )
UI_CASE(add, mprefixadd_row, , mprefixadd_row, , )
void ui_reference (const UI_ELEMENT *in, UI_ELEMENT *out, UI_ELEMENT *)
{
  UI_T(UI_TYPE, UI_SHAPE) a = UI_OP(mls_rm) (in);
  __riscv_ztt_mss_rm (out, UI_OP(mabs_ew) (a));
}
#ifdef __cplusplus
}
#endif
