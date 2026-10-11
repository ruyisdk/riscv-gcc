#include <riscv_ztt.h>
#ifndef SR_TYPE
#define SR_TYPE u32_rnu
#define SR_CARRIER __UINT32_TYPE__
#endif
#ifndef SR_CONTROL_OP
#define SR_CONTROL_OP msll_ew_x
#endif
#define SR_TYPE_(T) __riscv_ztt_##T##_1x1_t
#define SR_T(T) SR_TYPE_(T)
#define SR_NAME_(F, T) __riscv_ztt_##F##_##T##_1x1
#define SR_NAME(F, T) SR_NAME_(F, T)
#define SR_OP_(F, T) __riscv_ztt_##F##_##T##_1x1_u32_rnu
#define SR_OP(F, T) SR_OP_(F, T)
#define SR_BITS __riscv_ztt_scalar_from_bits_u32_rnu ((__UINT32_TYPE__) bits)
#define SR_ARGS const SR_CARRIER *in, SR_CARRIER *out, SR_CARRIER *saved, unsigned long bits
#define SR_SAVE __riscv_ztt_mss_rm (saved, b)
#ifdef __cplusplus
extern "C" {
#endif
extern void sr_callee (void);
#define SR_CASE(NAME, BEFORE, EXPR, SAVE) \
void sr_##NAME (SR_ARGS) \
{ \
  SR_T(SR_TYPE) b = SR_NAME(mls_rm, SR_TYPE) (in); \
  BEFORE; \
  SR_T(SR_TYPE) d = EXPR; \
  __riscv_ztt_mss_rm (out, d); \
  SAVE; \
}
SR_CASE(add_dead, , SR_OP(madd_ew_x, SR_TYPE) (b, SR_BITS), )
SR_CASE(add_live, , SR_OP(madd_ew_x, SR_TYPE) (b, SR_BITS), SR_SAVE)
SR_CASE(sub_dead, , SR_OP(msub_ew_x, SR_TYPE) (b, SR_BITS), )
SR_CASE(sub_live, , SR_OP(msub_ew_x, SR_TYPE) (b, SR_BITS), SR_SAVE)
SR_CASE(mul_dead, , SR_OP(mmul_ew_x, SR_TYPE) (b, SR_BITS), )
SR_CASE(mul_live, , SR_OP(mmul_ew_x, SR_TYPE) (b, SR_BITS), SR_SAVE)
SR_CASE(control, , SR_NAME(SR_CONTROL_OP, SR_TYPE) (b, bits), )
SR_CASE(call, sr_callee (), SR_OP(madd_ew_x, SR_TYPE) (b, SR_BITS), SR_SAVE)
SR_CASE(reference, , b, )
#ifdef __cplusplus
}
#endif
