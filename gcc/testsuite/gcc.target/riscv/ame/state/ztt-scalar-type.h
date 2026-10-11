#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif
extern void tc_callee (void);
extern volatile int tc_condition;

#define IOP(OP, TC, A, X) \
  __riscv_ztt_##OP##_ew_x_i32_rnu_1x1_##TC \
    (A, __riscv_ztt_scalar_from_bits_##TC (X))
#define CHAIN(NAME, T0, T1, T2) \
void NAME (__INT32_TYPE__ *out, const __INT32_TYPE__ *in, \
           __UINTPTR_TYPE__ x, __UINTPTR_TYPE__ y) \
{ \
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in); \
  a = IOP (madd, T0, a, x); \
  a = IOP (mmul, T1, a, y); \
  a = IOP (msub, T2, a, x); \
  __riscv_ztt_mss_rm (out, a); \
}
CHAIN (tc_chain, i32_rne, i32_rne, i32_rne)
CHAIN (tc_rm_change, i32_rne, i32_rdn, i32_rne)
CHAIN (tc_width_change, i32_rne, i16_rne, i32_rne)
CHAIN (tc_format_change, f32_rne, i32_rne, f32_rne)
#undef CHAIN

void tc_old (__INT32_TYPE__ *out, const __INT32_TYPE__ *in,
             __UINTPTR_TYPE__ x, __UINTPTR_TYPE__ y)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  __riscv_ztt_i32_1x1_t d = __riscv_ztt_mls_rm_i32_1x1 (out);
  d = __riscv_ztt_mmulacc_ew_x_i32_rnu_1x1_i32_rne
    (d, a, __riscv_ztt_scalar_from_bits_i32_rne (x));
  d = __riscv_ztt_mmulsub_ew_x_i32_rnu_1x1_i32_rne
    (d, a, __riscv_ztt_scalar_from_bits_i32_rne (y));
  d = IOP (madd, i32_rne, d, x);
  __riscv_ztt_mss_rm (out, d);
}

#define BOUNDARY(NAME, GAP) \
void NAME (__INT32_TYPE__ *out, const __INT32_TYPE__ *in, \
           __UINTPTR_TYPE__ x, __UINTPTR_TYPE__ y) \
{ \
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in); \
  a = IOP (madd, i32_rne, a, x); \
  GAP; \
  a = IOP (mmul, i32_rne, a, y); \
  __riscv_ztt_mss_rm (out, a); \
}
BOUNDARY (tc_asm, __asm__ volatile ("" ::: "memory"))
BOUNDARY (tc_call, tc_callee ())
BOUNDARY (tc_join, if (tc_condition) __asm__ volatile ("" ::: "memory"))
BOUNDARY (tc_write, __asm__ volatile ("csrw\tamestype,%0" : : "r" (y) : "memory"))
BOUNDARY (tc_unknown, __asm__ volatile ("" : "+Wmr" (a)))
#undef BOUNDARY

void tc_control (__INT32_TYPE__ *out, const __INT32_TYPE__ *in,
                 __UINTPTR_TYPE__ x, __UINTPTR_TYPE__ shift)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  a = IOP (madd, i32_rne, a, x);
  a = __riscv_ztt_msll_ew_x_i32_rnu_1x1 (a, shift);
  a = IOP (mmul, i32_rne, a, x);
  __riscv_ztt_mss_rm (out, a);
}

void tc_control_first (__INT32_TYPE__ *out, const __INT32_TYPE__ *in,
                       __UINTPTR_TYPE__ x, __UINTPTR_TYPE__ shift)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  a = __riscv_ztt_msll_ew_x_i32_rnu_1x1 (a, shift);
  a = IOP (madd, i32_rne, a, x);
  __riscv_ztt_mss_rm (out, a);
}

void tc_pair (__INT32_TYPE__ *out, const __INT32_TYPE__ *in,
              __UINTPTR_TYPE__ x, __UINTPTR_TYPE__ y)
{
  __riscv_ztt_i32_1x2_t a = __riscv_ztt_mls_rm_i32_1x2 (in);
  a = __riscv_ztt_madd_ew_x_i32_rnu_1x2_i32_rne
    (a, __riscv_ztt_scalar_from_bits_i32_rne (x));
  a = __riscv_ztt_mmul_ew_x_i32_rnu_1x2_i32_rne
    (a, __riscv_ztt_scalar_from_bits_i32_rne (y));
  __riscv_ztt_mss_rm (out, a);
}

void tc_float (float *out, const float *in,
               __UINTPTR_TYPE__ x, __UINTPTR_TYPE__ y)
{
  __riscv_ztt_f32_1x1_t a = __riscv_ztt_mls_rm_f32_1x1 (in);
  a = __riscv_ztt_madd_ew_x_f32_rne_1x1_f32_rne
    (a, __riscv_ztt_scalar_from_bits_f32_rne (x));
  a = __riscv_ztt_mmul_ew_x_f32_rne_1x1_f32_rne
    (a, __riscv_ztt_scalar_from_bits_f32_rne (y));
  a = __riscv_ztt_msub_ew_x_f32_rne_1x1_f32_rne
    (a, __riscv_ztt_scalar_from_bits_f32_rne (x));
  __riscv_ztt_mss_rm (out, a);
}

#undef IOP
#ifdef __cplusplus
}
#endif
