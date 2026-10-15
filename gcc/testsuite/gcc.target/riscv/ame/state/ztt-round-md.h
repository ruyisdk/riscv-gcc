#include <riscv_ztt.h>

#ifdef FP_DOUBLE
typedef double element;
typedef __riscv_ztt_f64_rne_1x1_t matrix;
#define LOAD __riscv_ztt_mls_rm_f64_rne_1x1
#define ADD __riscv_ztt_madd_ew_f64_rne_1x1
#define FN(N) __builtin_##N
#else
typedef float element;
typedef __riscv_ztt_f32_rne_1x1_t matrix;
#define LOAD __riscv_ztt_mls_rm_f32_rne_1x1
#define ADD __riscv_ztt_madd_ew_f32_rne_1x1
#define FN(N) __builtin_##N##f
#endif

#ifdef __cplusplus
extern "C" {
#endif
extern void fenv_callee (void);
#define CHAIN(NAME, EXPR, BOUNDARY) \
__attribute__((noipa)) void round_##NAME \
  (const element *in, element *work, element *out) \
{ \
  matrix a = LOAD (in); \
  __riscv_ztt_mss_rm (work, a); \
  work[0] = (EXPR); \
  BOUNDARY; \
  matrix b = LOAD (work); \
  __riscv_ztt_mss_rm (out, ADD (a, b)); \
}
CHAIN (away, FN (round) (work[0]), (void) 0)
CHAIN (down, FN (floor) (work[0]), (void) 0)
CHAIN (up, FN (ceil) (work[0]), (void) 0)
CHAIN (zero, FN (trunc) (work[0]), (void) 0)
CHAIN (even, FN (roundeven) (work[0]), (void) 0)
CHAIN (nearby, FN (nearbyint) (work[0]), (void) 0)
CHAIN (rint, FN (rint) (work[0]), (void) 0)
CHAIN (long_rint, (element) FN (lrint) (work[0]), (void) 0)
CHAIN (long_away, (element) FN (lround) (work[0]), (void) 0)
CHAIN (long_down, (element) FN (lfloor) (work[0]), (void) 0)
CHAIN (long_up, (element) FN (lceil) (work[0]), (void) 0)
CHAIN (barrier, FN (rint) (work[0]), __asm__ volatile ("# boundary" ::: "memory"))
CHAIN (call, FN (rint) (work[0]), fenv_callee ())
CHAIN (plain, work[0], (void) 0)
#undef CHAIN
#ifdef __cplusplus
}
#endif
#undef FN
#undef LOAD
#undef ADD
