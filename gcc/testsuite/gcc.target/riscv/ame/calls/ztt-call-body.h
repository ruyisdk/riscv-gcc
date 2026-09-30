/* A complete M and ACC value must survive ordinary direct/indirect calls.
   The external callee may overwrite the physical bank and its descriptors,
   but returns with ownership and N unchanged.  */
#include <riscv_ztt.h>
typedef __INT8_TYPE__ int8_t;
typedef __INT32_TYPE__ int32_t;

#define NAME1(OP, TC, SHAPE) __riscv_ztt_##OP##_##TC##_rne_##SHAPE
#define NAME(OP, TC, SHAPE) NAME1(OP, TC, SHAPE)
#define M(OP) NAME(OP, CALL_TC, 1x2)
#define A(OP) NAME(OP, CALL_TC, accx2)
#define TYPE1(TC, SHAPE) __riscv_ztt_##TC##_rne_##SHAPE##_t
#define TYPE(TC, SHAPE) TYPE1(TC, SHAPE)
typedef TYPE(CALL_TC, 1x2) matrix;
typedef TYPE(CALL_TC, accx2) accumulator;

#ifdef __cplusplus
extern "C" {
#endif
extern int call_boundary (int);

int matrix_call (const CALL_ELEMENT *in, CALL_ELEMENT *out)
{
  matrix m = M(mls_rm) (in);
  asm volatile ("" : : "Wmr" (m));
  int result = call_boundary (1);
  M(mss_rm) (out, m);
  return result;
}

int accumulator_call (const CALL_ELEMENT *in, CALL_ELEMENT *out)
{
  matrix m = M(mls_rm) (in);
  accumulator a = A(mcopy_m2a) (m);
  asm volatile ("" : : "War" (a));
  int result = call_boundary (2);
  M(mss_rm) (out, M(mcopy_a2m) (a));
  return result;
}

int combined_call (const CALL_ELEMENT *in, CALL_ELEMENT *out_m,
                   CALL_ELEMENT *out_a, int (*callback) (int), int count)
{
  matrix m = M(mls_rm) (in);
  accumulator a = A(mcopy_m2a) (m);
  asm volatile ("" : : "Wmr" (m), "War" (a));
  int sum = 0;
  for (int i = 0; i < count; ++i)
    {
      sum += callback (i);
      M(mss_rm) (out_m, m);
      M(mss_rm) (out_a, M(mcopy_a2m) (a));
    }
  if (count)
    sum += call_boundary (sum);
  M(mss_rm) (out_m, m);
  M(mss_rm) (out_a, M(mcopy_a2m) (a));
  return sum;
}
#ifdef __cplusplus
}
#endif
