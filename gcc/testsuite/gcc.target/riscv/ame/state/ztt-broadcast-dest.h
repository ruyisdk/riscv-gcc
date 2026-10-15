#include <riscv_ztt.h>
#ifndef BC_TYPE
#define BC_TYPE i32_rnu
#define BC_ALT i32_rod
#define BC_SCALAR i8_rdn
#define BC_CARRIER __INT32_TYPE__
#endif
#ifndef BC_SHAPE
#define BC_SHAPE 1x1
#endif
#define BC_T_(T,S) __riscv_ztt_##T##_##S##_t
#define BC_T_I(T,S) BC_T_(T,S)
#define BC_T(T) BC_T_I(T,BC_SHAPE)
#define BC_F_(F,T,S) __riscv_ztt_##F##_##T##_##S
#define BC_F_I(F,T,S) BC_F_(F,T,S)
#define BC_F(F,T) BC_F_I(F,T,BC_SHAPE)
#define BC_BITS_(T,V) __riscv_ztt_scalar_from_bits_##T (V)
#define BC_BITS(T,V) BC_BITS_(T,V)
#define BC_B_(T,S,C) __riscv_ztt_mbcast_m_x_##T##_##S##_##C
#define BC_B_I(T,S,C) BC_B_(T,S,C)
#define BC_B(V) BC_B_I(BC_TYPE,BC_SHAPE,BC_SCALAR) (BC_BITS(BC_SCALAR,V))
#define BC_ARGS const BC_CARRIER *in, BC_CARRIER *previous, \
  BC_CARRIER *out, BC_CARRIER *saved, unsigned long value, \
  unsigned long other, int control
#ifdef __cplusplus
extern "C" {
#endif
extern void bc_callee (void);
#define BC_CASE(NAME,FIRST,BETWEEN,RESULT,KEEP) \
__attribute__((noipa)) void bc_##NAME (BC_ARGS) \
{ \
  BC_T(FIRST) a = BC_F(mls_rm,FIRST) (in); \
  __riscv_ztt_mss_rm (previous, a); \
  BETWEEN; \
  BC_T(BC_TYPE) b = RESULT; \
  __riscv_ztt_mss_rm (out, b); \
  KEEP; \
}
BC_CASE(load, BC_TYPE, , BC_B(value), )
BC_CASE(changed, BC_ALT, , BC_B(value), )
BC_CASE(call, BC_TYPE, bc_callee (), BC_B(value), )
BC_CASE(barrier, BC_TYPE, __asm__ volatile ("# AME state boundary" ::: "memory"),
        BC_B(value), )
BC_CASE(join, BC_TYPE, if (control & 1) bc_callee (), BC_B(value), )
BC_CASE(live, BC_TYPE, , BC_B(value), __riscv_ztt_mss_rm (saved, a))
BC_CASE(zero, BC_TYPE, , BC_B(0), )
BC_CASE(zero_m, BC_TYPE, , BC_F(mzero_m,BC_TYPE) (), )
__attribute__((noipa)) void bc_repeat (BC_ARGS)
{
  BC_T(BC_TYPE) a = BC_B(value);
  __riscv_ztt_mss_rm (previous, a);
  BC_T(BC_TYPE) b = BC_B(other);
  __riscv_ztt_mss_rm (out, b);
}
__attribute__((noipa)) void bc_unknown (BC_ARGS)
{
  BC_T(BC_TYPE) a = BC_B(value);
  __riscv_ztt_mss_rm (out, a);
}
__attribute__((noipa)) void bc_reference (BC_ARGS)
{
  BC_T(BC_TYPE) a = BC_F(mls_rm,BC_TYPE) (in);
  __riscv_ztt_mss_rm (out, a);
}
#ifdef __cplusplus
}
#endif
