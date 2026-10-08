#include "ztt-copy-witness-body.h"

#ifdef __cplusplus
extern "C" {
#endif
void edge_two_tail (ARGS)
{
  LOAD;
  PART a = HALF (mextract) (p, 0);
  PART x = HALF (mcopy_m2m) (a);
  (void) HALF (mcopy_m2m) (x);
  ZIP; UNZIP; STORE;
}
void edge_live_tail (ARGS)
{
  LOAD;
  PART a = HALF (mextract) (p, 0);
  PART x = HALF (mcopy_m2m) (a);
  ZIP; UNZIP;
  __riscv_ztt_mss_rm (other, x);
  STORE;
}
void edge_multi_user (ARGS)
{
  LOAD;
  PART a = HALF (mextract) (p, 0);
  (void) HALF (mcopy_m2m) (a);
  ZIP; UNZIP;
  __riscv_ztt_mss_rm (other, a);
  STORE;
}
void edge_numeric (ARGS)
{
  LOAD;
  PART a = HALF (mextract) (p, 0);
  (void) HALF (madd_ew) (a, a);
  ZIP; UNZIP; STORE;
}
void edge_late_tail (ARGS)
{
  LOAD;
  PART a = HALF (mextract) (p, 0);
  ZIP; UNZIP;
  if (select)
    (void) HALF (mcopy_m2m) (a);
  STORE;
}
void edge_call_tail (ARGS)
{
  LOAD;
  PART a = HALF (mextract) (p, 0);
  witness_callee ();
  (void) HALF (mcopy_m2m) (a);
  ZIP; UNZIP; STORE;
}
void edge_expanded_limit (ARGS)
{
  LOAD;
#define WITNESS(N) PART a##N = HALF (mextract) (p, 0); \
                   (void) HALF (mcopy_m2m) (a##N)
  WITNESS (0); WITNESS (1); WITNESS (2); WITNESS (3);
  WITNESS (4); WITNESS (5); WITNESS (6); WITNESS (7);
#undef WITNESS
  ZIP; UNZIP; STORE;
}
void edge_nested_call (ARGS)
{
  LOAD;
  PART a = HALF (mextract) (p, 0);
  PART b = HALF (mextract) (p, 1);
  PART x = HALF (mcopy_m2m) (a);
  PART y = HALF (mcopy_m2m) (b);
  PAIR joined = FULL (mconcat_m) (x, y);
  witness_callee ();
  PAIR q = FULL (mcolzip_ew) (joined);
  UNZIP; STORE;
}
#ifdef __cplusplus
}
#endif
