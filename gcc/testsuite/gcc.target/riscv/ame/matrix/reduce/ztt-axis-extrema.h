#include <riscv_ztt.h>
#ifndef AE_TYPE
#define AE_TYPE i32_rnu
#define AE_ELEMENT __INT32_TYPE__
#endif
#define AE_TYPE_(T) __riscv_ztt_##T##_1x1_t
#define AE_T(T) AE_TYPE_(T)
#define AE_OP_(F, T) __riscv_ztt_##F##_##T##_1x1
#define AE_EXPAND(F, T) AE_OP_(F, T)
#define AE_OP(F) AE_EXPAND(F, AE_TYPE)
#define AE_LOAD AE_OP(mls_rm) (input)
#define AE_ROW AE_OP(mrowbcast_ew_x) (AE_LOAD, k)
#define AE_COL AE_OP(mcolbcast_ew_x) (AE_LOAD, k)
#ifdef AE_FLOAT
#define AE_ROWID AE_LOAD
#define AE_COLID AE_LOAD
#else
#define AE_ROWID AE_OP(mrowid_ew) ()
#define AE_COLID AE_OP(mcolid_ew) ()
#endif
#define AE_CASE(NAME, INIT, GAP, OP, AFTER, SAVE) \
void ae_##NAME (unsigned long k, const AE_ELEMENT *input, \
                AE_ELEMENT *out, AE_ELEMENT *saved) \
{ \
  AE_T(AE_TYPE) a = INIT; \
  GAP; \
  AE_T(AE_TYPE) b = AE_OP(OP) (a); \
  AFTER; \
  __riscv_ztt_mss_rm (out, b); \
  SAVE; \
}
#ifdef __cplusplus
extern "C" {
#endif
extern void ae_callee (void);
extern volatile unsigned long ae_observed;
AE_CASE(row_max, AE_ROW, , mreducemax_col, , )
AE_CASE(row_min, AE_ROW, , mreducemin_col, , )
AE_CASE(row_prefix, AE_ROW, , mprefixmax_col, , )
AE_CASE(col_max, AE_COL, , mreducemax_row, , )
AE_CASE(col_min, AE_COL, , mreducemin_row, , )
AE_CASE(col_prefix, AE_COL, , mprefixmax_row, , )
AE_CASE(rowid, AE_ROWID, , mreducemin_row, , )
AE_CASE(colid, AE_COLID, , mreducemax_col, , )
AE_CASE(id_prefix, AE_ROWID, , mprefixmax_row, , )
AE_CASE(copy, AE_ROW, a=AE_OP(mcopy_m2m)(a); a=AE_OP(mcopy_m2m)(a);
        a=AE_OP(mcopy_m2m)(a); a=AE_OP(mcopy_m2m)(a), mreducemax_col, , )
AE_CASE(postinc, AE_OP(mrowbcast_ew_x)(AE_LOAD, ae_observed++),
        , mreducemin_col, , )
AE_CASE(live, AE_ROW, , mreducemax_col, , __riscv_ztt_mss_rm(saved, a))
AE_CASE(after_call, AE_ROW, , mreducemin_col, ae_callee(),
        __riscv_ztt_mss_rm(saved, a))
AE_CASE(orthogonal, AE_OP(mrowbcast_ew_x)(AE_COL, k), , mreducemin_row, , )
AE_CASE(wrong_axis, AE_ROW, , mreducemin_row, , )
AE_CASE(add, AE_ROW, , mreduceadd_col, , )
AE_CASE(abs, AE_ROW, , mabs_ew, , )
AE_CASE(call, AE_ROW, ae_callee(), mreducemin_col, , )
AE_CASE(asm, AE_ROW, __asm__ volatile ("" ::: "memory"), mreducemax_col, , )
AE_CASE(flags, AE_ROW, __asm__ volatile ("csrw amefflags,zero" ::: "memory"),
        mreducemin_col, , )
AE_CASE(memory, AE_ROW, ae_observed=1, mreducemax_col, , )
void ae_reference (unsigned long k, const AE_ELEMENT *input,
                   AE_ELEMENT *out, AE_ELEMENT *)
{
  AE_T(AE_TYPE) a = AE_ROW;
  __riscv_ztt_mss_rm (out, a);
}
#ifdef __cplusplus
}
#endif
