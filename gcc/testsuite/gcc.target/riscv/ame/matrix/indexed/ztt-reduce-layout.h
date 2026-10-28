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
#define UG_STORE(a) __riscv_ztt_mss_rm (out, a)
#define UG_SAVE __riscv_ztt_mss_rm (saved, i)
#ifdef __cplusplus
extern "C" {
#endif
extern void ug_callee (void);
extern volatile unsigned long ug_observed;

void ug_row (UG_ARGS)
{
  UG_INDEX; UG_LOAD;
  ug_matrix b = UG_NAME(mreducemax_col) (a);
  UG_STORE (UG_NAME(mrowgather_ew) (b, i)); UG_SAVE;
}
void ug_col (UG_ARGS)
{
  UG_INDEX; UG_LOAD;
  ug_matrix b = UG_NAME(mreducemin_row) (a);
  UG_STORE (UG_NAME(mcolgather_ew) (b, i)); UG_SAVE;
}
void ug_copy (UG_ARGS)
{
  UG_INDEX; UG_LOAD;
  ug_matrix b = UG_NAME(mreduceadd_col) (a);
  b = UG_NAME(mcopy_m2m) (b);
  b = UG_NAME(mcopy_m2m) (b);
  b = UG_NAME(mcopy_m2m) (b);
  b = UG_NAME(mcopy_m2m) (b);
  UG_STORE (UG_NAME(mrowbcast_ew_x) (b, 0)); UG_SAVE;
}
void ug_shared (UG_ARGS)
{
  UG_INDEX; UG_LOAD;
  ug_matrix b = UG_NAME(mreduceadd_row) (a);
  UG_STORE (UG_NAME(mcolgather_ew) (b, i));
  __riscv_ztt_mss_rm (extra, b); UG_SAVE;
}
void ug_live_source (UG_ARGS)
{
  UG_INDEX; UG_LOAD;
  ug_matrix b = UG_NAME(mreducemin_col) (a);
  UG_STORE (UG_NAME(mrowbcast_ew_x) (b, 0));
  __riscv_ztt_mss_rm (extra, a); UG_SAVE;
}
void ug_postinc (UG_ARGS)
{
  UG_INDEX; UG_LOAD;
  ug_matrix b = UG_NAME(mreducemax_row) (a);
  UG_STORE (UG_NAME(mcolbcast_ew_x) (b, ug_observed++)); UG_SAVE;
}
void ug_wrong (UG_ARGS)
{
  UG_INDEX; UG_LOAD;
  ug_matrix b = UG_NAME(mreducemax_row) (a);
  UG_STORE (UG_NAME(mrowgather_ew) (b, i)); UG_SAVE;
}
void ug_call (UG_ARGS)
{
  UG_INDEX; UG_LOAD;
  ug_matrix b = UG_NAME(mreducemin_col) (a);
  ug_callee ();
  UG_STORE (UG_NAME(mrowgather_ew) (b, i)); UG_SAVE;
}
void ug_asm (UG_ARGS)
{
  UG_INDEX; UG_LOAD;
  ug_matrix b = UG_NAME(mreducemax_row) (a);
  asm volatile ("" ::: "memory");
  UG_STORE (UG_NAME(mcolgather_ew) (b, i)); UG_SAVE;
}
void ug_memory (UG_ARGS)
{
  UG_INDEX; UG_LOAD;
  ug_matrix b = UG_NAME(mreducemax_col) (a);
  ug_observed = k;
  UG_STORE (UG_NAME(mrowgather_ew) (b, i)); UG_SAVE;
}
void ug_unstored (UG_ARGS)
{
  UG_INDEX; UG_LOAD;
  ug_matrix b = UG_NAME(mreduceadd_row) (a);
  UG_STORE (UG_NAME(mcolgather_ew) (b, i));
}
void ug_reference (UG_ARGS)
{
  UG_INDEX; UG_LOAD;
  ug_matrix b = UG_NAME(mreduceadd_col) (a);
  UG_STORE (b); UG_SAVE;
}
#ifdef __cplusplus
}
#endif
