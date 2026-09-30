/* Maximum-group values remain live across a scalar/pointer ABI call.
   The call may overwrite the entire M/ACC bank and datatype state.  */
#include <riscv_ztt.h>

#define NAME_(OP, TC, SHAPE) __riscv_ztt_##OP##_##TC##_##SHAPE
#define NAME(OP, TC, SHAPE) NAME_(OP, TC, SHAPE)
#define TYPE_(TC, SHAPE) __riscv_ztt_##TC##_##SHAPE##_t
#define TYPE(TC, SHAPE) TYPE_(TC, SHAPE)
typedef TYPE(CALL_M_TC, CALL_M_SHAPE) matrix;
typedef TYPE(CALL_A_TC, CALL_A_SHAPE) accumulator;

#ifdef __cplusplus
extern "C" {
#endif
extern int call_boundary (int);

int matrix_pressure (int count)
{
  matrix m = NAME (mzero_m, CALL_M_TC, CALL_M_SHAPE) ();
  asm volatile ("" : "+Wmr" (m));
  int result = call_boundary (count);
  asm volatile ("" : : "Wmr" (m));
  return result;
}

int accumulator_pressure (int count)
{
  accumulator a = NAME (mzero_acc, CALL_A_TC, CALL_A_SHAPE) ();
  asm volatile ("" : "+War" (a));
  int result = call_boundary (count);
  asm volatile ("" : : "War" (a));
  return result;
}

int combined_pressure (int count, int (*callback) (int))
{
  matrix m = NAME (mzero_m, CALL_M_TC, CALL_M_SHAPE) ();
  accumulator a = NAME (mzero_acc, CALL_A_TC, CALL_A_SHAPE) ();
  /* Both operand orders must work even when M occupies the whole bank.  */
  asm volatile ("" : "+War" (a), "+Wmr" (m));
  int result = 0;
  for (int i = 0; i < count; ++i)
    {
      result += callback (i);
      asm volatile ("" : : "War" (a), "Wmr" (m));
    }
  if (count)
    result += call_boundary (result);
  asm volatile ("" : : "War" (a), "Wmr" (m));
  return result;
}

int combined_pressure_m_first (int count, int (*callback) (int))
{
  matrix m = NAME (mzero_m, CALL_M_TC, CALL_M_SHAPE) ();
  accumulator a = NAME (mzero_acc, CALL_A_TC, CALL_A_SHAPE) ();
  asm volatile ("" : "+Wmr" (m), "+War" (a));
  int result = 0;
  for (int i = 0; i < count; ++i)
    {
      result += callback (i);
      asm volatile ("" : : "Wmr" (m), "War" (a));
    }
  if (count)
    result += call_boundary (result);
  asm volatile ("" : : "Wmr" (m), "War" (a));
  return result;
}

int scalar_call_control (int value)
{
  return call_boundary (value) + 1;
}
#ifdef __cplusplus
}
#endif
