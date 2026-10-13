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
#define RB_FIRST ((unsigned long) 0xabcdef1200000002ULL)
#define RB_SECOND ((unsigned long) 0x1234567800000002ULL)
#define RB_INVALID1 ((unsigned long) 0xabcdefffffffffffULL)
#define RB_INVALID2 ((unsigned long) 0x12345678ffffffffULL)
#ifdef __cplusplus
extern "C" {
#endif
extern void rb_callee (void);
extern volatile unsigned long rb_observed;

void rb_row (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, RB_FIRST); RB_ROW (c, b, RB_SECOND);
  __riscv_ztt_mss_rm (out, c);
}
void rb_col (RB_ARGS)
{
  RB_LOAD; RB_COL (b, a, RB_FIRST); RB_COL (c, b, RB_SECOND);
  __riscv_ztt_mss_rm (out, c);
}
void rb_constant (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, RB_FIRST); RB_ROW (c, b, 2);
  __riscv_ztt_mss_rm (out, c);
}
void rb_query (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, RB_FIRST);
  unsigned long n = __riscv_ztt_get_amenlen ();
  RB_ROW (c, b, RB_SECOND);
  __riscv_ztt_mss_rm (out, c);
  rb_observed = n;
}
void rb_shared (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, RB_FIRST); RB_ROW (c, b, RB_SECOND);
  __riscv_ztt_mss_rm (out, c);
  __riscv_ztt_mss_rm (extra, b);
}
void rb_copy (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, RB_FIRST);
  RB_T(RB_TYPE) d = RB_NAME(mcopy_m2m, RB_TYPE) (b);
  RB_ROW (c, d, RB_SECOND);
  __riscv_ztt_mss_rm (out, c);
}
void rb_high (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, 2); RB_ROW (c, b, RB_SECOND);
  __riscv_ztt_mss_rm (out, c);
}
void rb_different (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, k); RB_ROW (c, b, j);
  __riscv_ztt_mss_rm (out, c);
}
void rb_cross (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, RB_FIRST); RB_COL (c, b, RB_SECOND);
  __riscv_ztt_mss_rm (out, c);
}
void rb_call (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, RB_FIRST);
  rb_callee ();
  RB_ROW (c, b, RB_SECOND);
  __riscv_ztt_mss_rm (out, c);
}
void rb_asm (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, RB_FIRST);
  asm volatile ("" ::: "memory");
  RB_ROW (c, b, RB_SECOND);
  __riscv_ztt_mss_rm (out, c);
}
void rb_memory (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, RB_FIRST);
  rb_observed = rb_observed + 1;
  RB_ROW (c, b, RB_SECOND);
  __riscv_ztt_mss_rm (out, c);
}
void rb_reference (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, RB_FIRST);
  __riscv_ztt_mss_rm (out, b);
}
void rb_invalid (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, RB_INVALID1); RB_ROW (c, b, RB_INVALID2);
  __riscv_ztt_mss_rm (out, c);
}
void rb_invalid_first (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, RB_INVALID1); RB_ROW (c, b, RB_SECOND);
  __riscv_ztt_mss_rm (out, c);
}
void rb_invalid_second (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, RB_FIRST); RB_ROW (c, b, RB_INVALID2);
  __riscv_ztt_mss_rm (out, c);
}
void rb_lowdiff (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, RB_FIRST); RB_ROW (c, b, RB_SECOND + 1);
  __riscv_ztt_mss_rm (out, c);
}
#ifdef __cplusplus
}
#endif
