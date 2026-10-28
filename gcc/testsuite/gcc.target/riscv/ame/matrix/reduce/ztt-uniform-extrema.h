#include <riscv_ztt.h>
#ifndef UE_TYPE
#define UE_TYPE i32_rnu
#define UE_ELEMENT __INT32_TYPE__
#define UE_CARRIER __UINT32_TYPE__
#endif
#ifndef UE_SHAPE
#define UE_SHAPE 1x1
#endif
#define UE_TYPE_(T, S) __riscv_ztt_##T##_##S##_t
#define UE_T(T, S) UE_TYPE_(T, S)
#define UE_OP_(F, T, S) __riscv_ztt_##F##_##T##_##S
#define UE_EXPAND(F, T, S) UE_OP_(F, T, S)
#define UE_OP(F) UE_EXPAND(F, UE_TYPE, UE_SHAPE)
#define UE_BITS_(T) __riscv_ztt_scalar_from_bits_##T
#define UE_BITS(T) UE_BITS_(T)
#define UE_BCAST UE_OP(mbcast_m_x) (UE_BITS(UE_TYPE) ((UE_CARRIER) k))
#define UE_ZERO UE_OP(mzero_m) ()
#define UE_CASE(NAME, INIT, GAP, OP, AFTER, SAVE) \
void ue_##NAME (unsigned long k, UE_ELEMENT *out, UE_ELEMENT *saved) \
{ \
  UE_T(UE_TYPE, UE_SHAPE) a = INIT; \
  GAP; \
  UE_T(UE_TYPE, UE_SHAPE) b = UE_OP(OP) (a); \
  AFTER; \
  __riscv_ztt_mss_rm (out, b); \
  SAVE; \
}
#ifdef __cplusplus
extern "C" {
#endif
extern void ue_callee (void);
extern volatile unsigned long ue_observed;
UE_CASE(max_row, UE_BCAST, , mreducemax_row, , )
UE_CASE(max_col, UE_BCAST, , mreducemax_col, , )
UE_CASE(min_row, UE_BCAST, , mreducemin_row, , )
UE_CASE(min_col, UE_BCAST, , mreducemin_col, , )
UE_CASE(prefix_row, UE_BCAST, , mprefixmax_row, , )
UE_CASE(prefix_col, UE_BCAST, , mprefixmax_col, , )
UE_CASE(copy, UE_BCAST, a=UE_OP(mcopy_m2m)(a); a=UE_OP(mcopy_m2m)(a);
        a=UE_OP(mcopy_m2m)(a); a=UE_OP(mcopy_m2m)(a), mreducemin_row, , )
UE_CASE(postinc, UE_OP(mbcast_m_x) (UE_BITS(UE_TYPE) ((UE_CARRIER) ue_observed++)),
        , mreducemax_col, , )
UE_CASE(live, UE_BCAST, , mreducemax_row, , __riscv_ztt_mss_rm (saved, a))
UE_CASE(after_call, UE_BCAST, , mreducemin_col, ue_callee (),
        __riscv_ztt_mss_rm (saved, a))
UE_CASE(zero_abs, UE_ZERO, , mabs_ew, , )
UE_CASE(zero_max, UE_ZERO, , mreducemax_col, , )
UE_CASE(zero_prefix, UE_ZERO, , mprefixmax_row, , )
UE_CASE(call, UE_BCAST, ue_callee (), mreducemin_row, , )
UE_CASE(asm, UE_BCAST, __asm__ volatile ("" ::: "memory"), mreducemax_col, , )
UE_CASE(memory, UE_BCAST, ue_observed=1, mreducemax_row, , )
UE_CASE(flags, UE_BCAST, __asm__ volatile ("csrw amefflags,zero" ::: "memory"),
        mreducemin_col, , )
UE_CASE(abs, UE_BCAST, , mabs_ew, , )
UE_CASE(add, UE_BCAST, , mreduceadd_row, , )
void ue_reference (unsigned long k, UE_ELEMENT *out, UE_ELEMENT *)
{
  UE_T(UE_TYPE, UE_SHAPE) a = UE_BCAST;
  __riscv_ztt_mss_rm (out, a);
}
#ifdef __cplusplus
}
#endif
