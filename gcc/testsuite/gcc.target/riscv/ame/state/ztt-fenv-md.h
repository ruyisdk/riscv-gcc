#include <riscv_ztt.h>

#ifdef FP_DOUBLE
typedef double element;
typedef __riscv_ztt_f64_rne_1x1_t matrix;
#define LOAD __riscv_ztt_mls_rm_f64_rne_1x1
#define ADD __riscv_ztt_madd_ew_f64_rne_1x1
#else
typedef float element;
typedef __riscv_ztt_f32_rne_1x1_t matrix;
#define LOAD __riscv_ztt_mls_rm_f32_rne_1x1
#define ADD __riscv_ztt_madd_ew_f32_rne_1x1
#endif

#ifdef __cplusplus
extern "C" {
#endif
extern void fenv_callee (void);
#define CHAIN(NAME, EXPR, BOUNDARY) \
__attribute__((noipa)) void fenv_##NAME \
  (const element *in, element *work, element *out, element scalar, unsigned flags) \
{ \
  matrix a = LOAD (in); \
  __riscv_ztt_mss_rm (work, a); \
  work[0] = (EXPR); \
  BOUNDARY; \
  matrix b = LOAD (work); \
  __riscv_ztt_mss_rm (out, ADD (a, b)); \
}
CHAIN (gt, (element) __builtin_isgreater (work[0], scalar), (void) 0)
CHAIN (lt, (element) __builtin_isless (work[0], scalar), (void) 0)
CHAIN (ge, (element) __builtin_isgreaterequal (work[0], scalar), (void) 0)
CHAIN (le, (element) __builtin_islessequal (work[0], scalar), (void) 0)
CHAIN (read, work[0] + (element) __builtin_riscv_frflags (), (void) 0)
CHAIN (write, (__builtin_riscv_fsflags (flags), work[0]), (void) 0)
CHAIN (clear, (__builtin_riscv_fsflags (0), work[0]), (void) 0)
CHAIN (barrier, (element) __builtin_isgreater (work[0], scalar),
       __asm__ volatile ("# boundary" ::: "memory"))
CHAIN (call, (element) __builtin_isgreater (work[0], scalar), fenv_callee ())
CHAIN (plain, work[0] + scalar, (void) 0)
#undef CHAIN
#ifdef __cplusplus
}
#endif
#undef LOAD
#undef ADD
