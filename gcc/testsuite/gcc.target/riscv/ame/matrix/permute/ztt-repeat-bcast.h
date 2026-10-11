#include <riscv_ztt.h>

#ifndef RB_TYPE
#define RB_TYPE i32
#define RB_CARRIER __INT32_TYPE__
#endif
#define RB_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define RB_NAME(f, t) RB_NAME_(f, t)
#define RB_T_(t) __riscv_ztt_##t##_1x1_t
#define RB_T(t) RB_T_(t)
typedef RB_CARRIER rb_element;
#define RB_ARGS const rb_element *in, rb_element *out, rb_element *extra, \
  unsigned long k, unsigned long j
#define RB_LOAD RB_T(RB_TYPE) a = RB_NAME(mls_rm, RB_TYPE) (in)
#define RB_ROW(dst, src, idx) \
  RB_T(RB_TYPE) dst = RB_NAME(mrowbcast_ew_x, RB_TYPE) (src, idx)
#define RB_COL(dst, src, idx) \
  RB_T(RB_TYPE) dst = RB_NAME(mcolbcast_ew_x, RB_TYPE) (src, idx)
#ifdef __cplusplus
extern "C" {
#endif
extern void rb_callee (void);
extern volatile unsigned long rb_observed;

void rb_row (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, k); RB_ROW (c, b, k);
  __riscv_ztt_mss_rm (out, c);
}
void rb_col (RB_ARGS)
{
  RB_LOAD; RB_COL (b, a, k); RB_COL (c, b, k);
  __riscv_ztt_mss_rm (out, c);
}
void rb_constant (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, 2); RB_ROW (c, b, 2);
  __riscv_ztt_mss_rm (out, c);
}
void rb_query (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, k);
  unsigned long n = __riscv_ztt_get_amenlen ();
  RB_ROW (c, b, k);
  __riscv_ztt_mss_rm (out, c);
  rb_observed = n;
}
void rb_shared (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, k); RB_ROW (c, b, k);
  __riscv_ztt_mss_rm (out, c);
  __riscv_ztt_mss_rm (extra, b);
}
void rb_different (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, k); RB_ROW (c, b, j);
  __riscv_ztt_mss_rm (out, c);
}
void rb_cross (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, k); RB_COL (c, b, k);
  __riscv_ztt_mss_rm (out, c);
}
void rb_call (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, k);
  rb_callee ();
  RB_ROW (c, b, k);
  __riscv_ztt_mss_rm (out, c);
}
void rb_asm (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, k);
  asm volatile ("" ::: "memory");
  RB_ROW (c, b, k);
  __riscv_ztt_mss_rm (out, c);
}
void rb_memory (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, k);
  rb_observed = rb_observed + 1;
  RB_ROW (c, b, k);
  __riscv_ztt_mss_rm (out, c);
}
void rb_reference (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, k);
  __riscv_ztt_mss_rm (out, b);
}
#ifdef __cplusplus
}
#endif
