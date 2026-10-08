#include "ztt-structure-fold-body.h"
#ifdef __cplusplus
extern "C" {
#endif
extern void structure_callee (void);

#define SF_INPUTS \
  SF_VALUE (SF_HALF) x = SF_NAME (mls_rm, SF_HALF) (a); \
  SF_VALUE (SF_HALF) y = SF_NAME (mls_rm, SF_HALF) (b); \
  SF_VALUE (SF_PAIR) pair = SF_NAME (mconcat_m, SF_PAIR) (x, y)

void
structure_call (SF_CARRIER *out, const SF_CARRIER *a, const SF_CARRIER *b)
{
  SF_INPUTS;
  structure_callee ();
  __riscv_ztt_mss_rm (out, SF_NAME (mextract, SF_HALF) (pair, 0));
}

void
structure_asm (SF_CARRIER *out, const SF_CARRIER *a, const SF_CARRIER *b)
{
  SF_INPUTS;
  __asm__ volatile ("" ::: "memory");
  __riscv_ztt_mss_rm (out, SF_NAME (mextract, SF_HALF) (pair, 1));
}

void
structure_memory (SF_CARRIER *out, const SF_CARRIER *a, const SF_CARRIER *b,
		  volatile int *flag)
{
  SF_INPUTS;
  *flag = 17;
  __riscv_ztt_mss_rm (out, SF_NAME (mextract, SF_HALF) (pair, 0));
}

void
structure_join (SF_CARRIER *out, const SF_CARRIER *a, const SF_CARRIER *b,
		int branch)
{
  SF_INPUTS;
  if (branch)
    pair = SF_NAME (mconcat_m, SF_PAIR) (y, x);
  __riscv_ztt_mss_rm (out, SF_NAME (mextract, SF_HALF) (pair, 0));
}
#ifdef __cplusplus
}
#endif
