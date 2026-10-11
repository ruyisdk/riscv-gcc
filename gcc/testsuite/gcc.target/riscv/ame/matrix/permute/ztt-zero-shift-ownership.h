#include <stdint.h>
#include <riscv_ztt.h>

extern void may_throw ();

#ifdef ZTT_SHIFT_FLOAT
typedef float shift_scalar;
typedef __riscv_ztt_f32_rno_1x1_t shift_matrix;
#define SHIFT_LOAD __riscv_ztt_mls_rm_f32_rno_1x1
#define SHIFT_COL __riscv_ztt_mcolshift_ew_x_f32_rno_1x1
#define SHIFT_ROW __riscv_ztt_mrowshift_ew_x_f32_rno_1x1
#else
typedef int32_t shift_scalar;
typedef __riscv_ztt_i32_rnu_1x1_t shift_matrix;
#define SHIFT_LOAD __riscv_ztt_mls_rm_i32_rnu_1x1
#define SHIFT_COL __riscv_ztt_mcolshift_ew_x_i32_rnu_1x1
#define SHIFT_ROW __riscv_ztt_mrowshift_ew_x_i32_rnu_1x1
#endif

void probe (shift_scalar *out, const shift_scalar *in)
{
#if ZTT_SHIFT_CASE <= 1
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
#endif
  shift_matrix a = SHIFT_LOAD (in);
#if ZTT_SHIFT_CASE <= 1
  __riscv_ztt_ame_release ();
#else
#if ZTT_SHIFT_CASE != 6
  (void) __riscv_ztt_get_ameown ();
#endif
  try { may_throw (); }
  catch (...) { }
#if ZTT_SHIFT_CASE == 5
  if (!__riscv_ztt_get_ameown ())
    return;
#endif
#endif
#if ZTT_SHIFT_CASE == 1
  shift_matrix b = SHIFT_COL (a, 0);
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_ame_release ();
#else
  (void) SHIFT_ROW (a, 0);
#endif
}
