#include <riscv_ztt.h>
#define AZ_T_(D,Q) __riscv_ztt_##D##_accx##Q##_t
#define AZ_T(D,Q) AZ_T_ (D,Q)
#define AZ_ZERO_(D,Q) __riscv_ztt_mzero_acc_##D##_accx##Q ()
#define AZ_ZERO(D,Q) AZ_ZERO_ (D,Q)
#define AZ_CLEAR_(D,Q) __riscv_ztt_mclear_acc_##D##_accx##Q ()
#define AZ_CLEAR(D,Q) AZ_CLEAR_ (D,Q)
#define AZ_MOVE_(D,Q,V) __riscv_ztt_mcopy_a2m_##D##_1x##Q (V)
#define AZ_MOVE(D,Q,V) AZ_MOVE_ (D,Q,V)
extern void callee (void);
void zero (AZ_CARRIER *out)
{
  AZ_T (AZ_TYPE,AZ_COUNT) a = AZ_ZERO (AZ_TYPE,AZ_COUNT);
  __riscv_ztt_mss_rm (out,AZ_MOVE (AZ_TYPE,AZ_COUNT,a));
}
void clear (AZ_CARRIER *out)
{
  AZ_T (AZ_TYPE,AZ_COUNT) a = AZ_CLEAR (AZ_TYPE,AZ_COUNT);
  __riscv_ztt_mss_rm (out,AZ_MOVE (AZ_TYPE,AZ_COUNT,a));
}
void call (AZ_CARRIER *out)
{
  AZ_T (AZ_TYPE,AZ_COUNT) a = AZ_ZERO (AZ_TYPE,AZ_COUNT);
  callee ();
  __riscv_ztt_mss_rm (out,AZ_MOVE (AZ_TYPE,AZ_COUNT,a));
}
void barrier (AZ_CARRIER *out)
{
  AZ_T (AZ_TYPE,AZ_COUNT) a = AZ_ZERO (AZ_TYPE,AZ_COUNT);
  __asm__ volatile ("# AME boundary" ::: "memory");
  __riscv_ztt_mss_rm (out,AZ_MOVE (AZ_TYPE,AZ_COUNT,a));
}
