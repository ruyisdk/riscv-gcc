#include <riscv_ztt.h>

#ifndef DL_SRC
#define DL_SRC u64_rnu
#define DL_DST u64_rod
#define DL_INPUT __UINT64_TYPE__
#define DL_OUTPUT __UINT64_TYPE__
#endif
#ifndef DL_OP
#define DL_OP madd_ew
#endif
#define DL_FN_(f, t) __riscv_ztt_##f##_##t##_1x1
#define DL_FN(f, t) DL_FN_(f, t)
#define DL_T_(t) __riscv_ztt_##t##_1x1_t
#define DL_T(t) DL_T_(t)
#ifdef DL_SHARED
#define DL_RHS a
#else
#define DL_RHS b
#endif
#ifdef __cplusplus
extern "C" {
#endif
__attribute__((noipa))
void dl_test (const DL_INPUT *left, const DL_INPUT *right, DL_OUTPUT *out)
{
  DL_T(DL_SRC) a = DL_FN(mls_rm, DL_SRC) (left);
  DL_T(DL_SRC) b = DL_FN(mls_rm, DL_SRC) (right);
  DL_T(DL_DST) c = DL_FN(DL_OP, DL_DST) (a, DL_RHS);
  __riscv_ztt_mss_rm (out, c);
}
#ifdef __cplusplus
}
#endif
