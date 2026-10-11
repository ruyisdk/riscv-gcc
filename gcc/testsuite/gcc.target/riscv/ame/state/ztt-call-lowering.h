#include <riscv_ztt.h>

#ifdef STATE_WIDE
#define ELEMENT __INT32_TYPE__
#define MATRIX __riscv_ztt_i32_rnu_1x1_t
#define LOAD __riscv_ztt_mls_rm_i32_rnu_1x1
#else
#define ELEMENT __INT8_TYPE__
#define MATRIX __riscv_ztt_i8_rnu_1x1_t
#define LOAD __riscv_ztt_mls_rm_i8_rnu_1x1
#endif

#ifdef __cplusplus
extern "C" {
#endif
extern int lowering_callee (int);

int call_after_matrix (const ELEMENT *in, ELEMENT *out)
{
  MATRIX m = LOAD (in);
  int result = lowering_callee (1);
  __riscv_ztt_mss_rm (out, m);
  return result;
}

int call_before_matrix (const ELEMENT *in, ELEMENT *out)
{
  int result = lowering_callee (2);
  MATRIX m = LOAD (in);
  __riscv_ztt_mss_rm (out, m);
  return result;
}

int call_indirect_matrix (const ELEMENT *in, ELEMENT *out, int (*callback) (int))
{
  MATRIX m = LOAD (in);
  int result = callback (3);
  __riscv_ztt_mss_rm (out, m);
  return result;
}

int call_acc_only (void)
{
  __riscv_ztt_i32_rnu_accx1_t a = __riscv_ztt_mzero_acc_i32_rnu_accx1 ();
  int result = lowering_callee (4);
  __asm__ volatile ("" : : "War" (a));
  return result;
}

int call_matrix_asm_acc (const ELEMENT *in)
{
  __riscv_ztt_i32_rnu_accx1_t a = __riscv_ztt_mzero_acc_i32_rnu_accx1 ();
  MATRIX m = LOAD (in);
  __asm__ volatile ("" : : "Wmr" (m));
  int result = lowering_callee (5);
  __asm__ volatile ("" : : "War" (a));
  return result;
}

int call_scalar_only (int value)
{
  return lowering_callee (value) + 1;
}
#ifdef __cplusplus
}
#endif

#undef ELEMENT
#undef MATRIX
#undef LOAD
