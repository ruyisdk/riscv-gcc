#include <riscv_ztt.h>

#ifndef UG_TYPE
#define UG_TYPE i32_rnu
#define UG_ELEMENT __INT32_TYPE__
#endif
#define UG_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define UG_NAME_I(f, t) UG_NAME_(f, t)
#define UG_NAME(f) UG_NAME_I(f, UG_TYPE)
#define UG_T_(t) __riscv_ztt_##t##_1x1_t
#define UG_T(t) UG_T_(t)
typedef UG_ELEMENT ug_element;
typedef UG_T(UG_TYPE) ug_matrix;
#define UG_ARGS unsigned long k, unsigned long l, const ug_element *in, \
  const __INT32_TYPE__ *index, ug_element *out, ug_element *extra, \
  __INT32_TYPE__ *saved
#define UG_LOAD ug_matrix a = UG_NAME(mls_rm) (in)
#define UG_INDEX __riscv_ztt_i32_rnu_1x1_t i = __riscv_ztt_mls_rm_i32_rnu_1x1 (index)
#define UG_ROW ug_matrix t = UG_NAME(mrowbcast_ew_x) (a, k); \
  ug_matrix b = UG_NAME(mcolbcast_ew_x) (t, l)
#define UG_COL ug_matrix t = UG_NAME(mcolbcast_ew_x) (a, l); \
  ug_matrix b = UG_NAME(mrowbcast_ew_x) (t, k)
#define UG_STORE(a) __riscv_ztt_mss_rm (out, a)
#define UG_SAVE __riscv_ztt_mss_rm (saved, i)

#ifdef __cplusplus
extern "C" {
#endif
extern void ug_callee (void);
extern volatile unsigned long ug_observed;

void ug_row (UG_ARGS)
{
  UG_INDEX; UG_LOAD; UG_ROW;
  UG_STORE (UG_NAME(mrowgather_ew) (b, i)); UG_SAVE;
}
void ug_col (UG_ARGS)
{
  UG_INDEX; UG_LOAD; UG_COL;
  UG_STORE (UG_NAME(mcolgather_ew) (b, i)); UG_SAVE;
}
void ug_copy (UG_ARGS)
{
  UG_INDEX; UG_LOAD; UG_ROW;
  ug_matrix c = UG_NAME(mcopy_m2m) (b);
  c = UG_NAME(mcopy_m2m) (c);
  c = UG_NAME(mcopy_m2m) (c);
  c = UG_NAME(mcopy_m2m) (c);
  c = UG_NAME(mrowbcast_ew_x) (c, 0);
  UG_STORE (UG_NAME(mrowgather_ew) (c, i)); UG_SAVE;
}
void ug_shared (UG_ARGS)
{
  UG_INDEX; UG_LOAD; UG_COL;
  UG_STORE (UG_NAME(mcolgather_ew) (b, i));
  __riscv_ztt_mss_rm (extra, b); UG_SAVE;
}
void ug_live_source (UG_ARGS)
{
  UG_INDEX; UG_LOAD; UG_ROW;
  UG_STORE (UG_NAME(mrowgather_ew) (b, i));
  __riscv_ztt_mss_rm (extra, a); UG_SAVE;
}
void ug_postinc (UG_ARGS)
{
  UG_INDEX; UG_LOAD;
  ug_matrix t = UG_NAME(mcolbcast_ew_x) (a, l);
  ug_matrix b = UG_NAME(mrowbcast_ew_x) (t, ug_observed++);
  UG_STORE (UG_NAME(mcolgather_ew) (b, i)); UG_SAVE;
}
void ug_wrong (UG_ARGS)
{
  UG_INDEX; UG_LOAD;
  ug_matrix t = UG_NAME(mrowbcast_ew_x) (a, k);
  ug_matrix b = UG_NAME(mrowbcast_ew_x) (t, l);
  UG_STORE (UG_NAME(mcolgather_ew) (b, i)); UG_SAVE;
}
void ug_call (UG_ARGS)
{
  UG_INDEX; UG_LOAD; UG_ROW; ug_callee ();
  UG_STORE (UG_NAME(mrowgather_ew) (b, i)); UG_SAVE;
}
void ug_asm (UG_ARGS)
{
  UG_INDEX; UG_LOAD; UG_COL; asm volatile ("" ::: "memory");
  UG_STORE (UG_NAME(mcolgather_ew) (b, i)); UG_SAVE;
}
void ug_memory (UG_ARGS)
{
  UG_INDEX; UG_LOAD; UG_ROW; ug_observed = k;
  UG_STORE (UG_NAME(mrowgather_ew) (b, i)); UG_SAVE;
}
void ug_unstored (UG_ARGS)
{
  UG_INDEX; UG_LOAD; UG_COL;
  UG_STORE (UG_NAME(mcolgather_ew) (b, i));
}
void ug_reference (UG_ARGS)
{
  UG_INDEX; UG_LOAD; UG_ROW; UG_STORE (b); UG_SAVE;
}
#ifdef __cplusplus
}
#endif
