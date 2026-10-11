#include "ztt-copy-project-body.h"

#define FOUR(X) TWICE (TWICE (X))
#define FIVE(X) COPY (FOUR (X))
PROJECT (four0, FOUR, 0)
PROJECT (four1, FOUR, 1)
PROJECT (five0, FIVE, 0)
PROJECT (five1, FIVE, 1)

void live_middle (ARGS)
{
  PAIR;
  full_t q = TWICE (p);
  full_t r = TWICE (q);
  STORE (HALF (mextract) (r, 0));
  __riscv_ztt_mss_rm (extra, q);
}

void middle_barrier (ARGS)
{
  PAIR;
  full_t q = TWICE (p);
  __asm__ volatile ("" ::: "memory");
  full_t r = TWICE (q);
  STORE (HALF (mextract) (r, 1));
}
