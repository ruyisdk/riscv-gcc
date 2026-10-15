#include <riscv_ztt.h>

#ifdef FP_DOUBLE
typedef double element;
typedef __riscv_ztt_f64_rne_1x1_t matrix;
#define LOAD __riscv_ztt_mls_rm_f64_rne_1x1
#define ADD __riscv_ztt_madd_ew_f64_rne_1x1
#define MIN __builtin_fmin
#define MAX __builtin_fmax
#define SIGN __builtin_copysign
#else
typedef float element;
typedef __riscv_ztt_f32_rne_1x1_t matrix;
#define LOAD __riscv_ztt_mls_rm_f32_rne_1x1
#define ADD __riscv_ztt_madd_ew_f32_rne_1x1
#define MIN __builtin_fminf
#define MAX __builtin_fmaxf
#define SIGN __builtin_copysignf
#endif

#ifdef __cplusplus
extern "C" {
#endif
extern void scalar_fp_callee (void);
#define CHAIN(NAME, EXPR, BOUNDARY) \
__attribute__((noipa)) void scalar_fp_##NAME \
  (const element *in, element *work, element *out, element scalar) \
{ \
  matrix a = LOAD (in); \
  __riscv_ztt_mss_rm (work, a); \
  work[0] = (EXPR); \
  BOUNDARY; \
  matrix b = LOAD (work); \
  __riscv_ztt_mss_rm (out, ADD (a, b)); \
}
CHAIN (min, MIN (work[0], scalar), (void) 0)
CHAIN (max, MAX (work[0], scalar), (void) 0)
CHAIN (sign, SIGN (work[0], scalar), (void) 0)
CHAIN (normal, (element) __builtin_isnormal (work[0]), (void) 0)
CHAIN (plain, work[0] + scalar, (void) 0)
CHAIN (barrier, MIN (work[0], scalar), __asm__ volatile ("# boundary" ::: "memory"))
CHAIN (call, MIN (work[0], scalar), scalar_fp_callee ())
#undef CHAIN
#ifdef __cplusplus
}
#endif
#undef LOAD
#undef ADD
#undef MIN
#undef MAX
#undef SIGN
