#include <riscv_ztt.h>
#define MZ_T_(D,Q) __riscv_ztt_##D##_1x##Q##_t
#define MZ_T(D,Q) MZ_T_ (D,Q)
#define MZ_ZERO_(D,Q) __riscv_ztt_mzero_m_##D##_1x##Q ()
#define MZ_ZERO(D,Q) MZ_ZERO_ (D,Q)
#define MZ_CLEAR_(D,Q) __riscv_ztt_mclear_m_##D##_1x##Q ()
#define MZ_CLEAR(D,Q) MZ_CLEAR_ (D,Q)
#define MZ_ACC_(D,Q,V) __riscv_ztt_mcopy_m2a_##D##_accx##Q (V)
#define MZ_ACC(D,Q,V) MZ_ACC_ (D,Q,V)
#define MZ_MOVE_(D,Q,V) __riscv_ztt_mcopy_a2m_##D##_1x##Q (V)
#define MZ_MOVE(D,Q,V) MZ_MOVE_ (D,Q,V)
#define MZ_STORE(P,V) __riscv_ztt_mss_rm (P,MZ_MOVE (MZ_TYPE,MZ_COUNT,MZ_ACC (MZ_TYPE,MZ_COUNT,V)))
extern void callee (void);
void zero (MZ_CARRIER *out)
{
  MZ_T (MZ_TYPE,MZ_COUNT) m = MZ_ZERO (MZ_TYPE,MZ_COUNT);
  MZ_STORE (out,m);
}
void clear (MZ_CARRIER *out)
{
  MZ_T (MZ_TYPE,MZ_COUNT) m = MZ_CLEAR (MZ_TYPE,MZ_COUNT);
  MZ_STORE (out,m);
}
void call (MZ_CARRIER *out)
{
  MZ_T (MZ_TYPE,MZ_COUNT) m = MZ_ZERO (MZ_TYPE,MZ_COUNT);
  callee ();
  MZ_STORE (out,m);
}
void barrier (MZ_CARRIER *out)
{
  MZ_T (MZ_TYPE,MZ_COUNT) m = MZ_ZERO (MZ_TYPE,MZ_COUNT);
  __asm__ volatile ("# AME boundary" ::: "memory");
  MZ_STORE (out,m);
}
