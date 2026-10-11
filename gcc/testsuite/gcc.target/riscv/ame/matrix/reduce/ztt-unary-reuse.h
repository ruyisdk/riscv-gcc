#include <riscv_ztt.h>
#ifndef UR_TYPE
#define UR_TYPE i32_rnu
#define UR_CARRIER __INT32_TYPE__
#endif
#ifndef UR_DEST
#define UR_DEST UR_TYPE
#endif
#define UR_TYPE_(T) __riscv_ztt_##T##_1x1_t
#define UR_T(T) UR_TYPE_(T)
#define UR_OP_(F, T) __riscv_ztt_##F##_##T##_1x1
#define UR_OP(F, T) UR_OP_(F, T)
#define UR_SAVE __riscv_ztt_mss_rm (saved, b)
#ifdef __cplusplus
extern "C" {
#endif
extern void ur_callee (void);
#define UR_CASE(NAME, BEFORE, EXPR, SAVE) \
void ur_##NAME (const UR_CARRIER *in, UR_CARRIER *out, \
               UR_CARRIER *saved, int control) \
{ \
  UR_T(UR_TYPE) b = UR_OP(mls_rm, UR_TYPE) (in); \
  BEFORE; \
  __typeof__ (EXPR) d = EXPR; \
  __riscv_ztt_mss_rm (out, d); \
  SAVE; \
}
UR_CASE(abs_dead, , UR_OP(mabs_ew, UR_DEST) (b), )
UR_CASE(abs_live, , UR_OP(mabs_ew, UR_DEST) (b), UR_SAVE)
UR_CASE(reduce_row, , UR_OP(mreducemax_row, UR_DEST) (b), )
UR_CASE(reduce_col, , UR_OP(mreducemax_col, UR_DEST) (b), )
UR_CASE(prefix_row, , UR_OP(mprefixmax_row, UR_DEST) (b), )
UR_CASE(prefix_col, , UR_OP(mprefixmax_col, UR_DEST) (b), )
UR_CASE(rowbcast_dead, , UR_OP(mrowbcast_ew_x, UR_TYPE) (b, control), )
UR_CASE(rowbcast_live, , UR_OP(mrowbcast_ew_x, UR_TYPE) (b, control), UR_SAVE)
UR_CASE(colbcast, , UR_OP(mcolbcast_ew_x, UR_TYPE) (b, control), )
UR_CASE(rowshift, , UR_OP(mrowshift_ew_x, UR_TYPE) (b, control), )
UR_CASE(colshift, , UR_OP(mcolshift_ew_x, UR_TYPE) (b, control), )
UR_CASE(convert, , UR_OP(mconv_ew, UR_DEST) (b), )
UR_CASE(call, ur_callee (), UR_OP(mabs_ew, UR_DEST) (b), UR_SAVE)
UR_CASE(reference, , b, )
UR_CASE(call_dead, ur_callee (), UR_OP(mabs_ew, UR_DEST) (b), )
#ifdef __cplusplus
}
#endif
