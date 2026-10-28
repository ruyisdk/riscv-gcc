#include "ztt-exponent-old-copy.h"
#ifdef __cplusplus
extern "C" {
#endif

void tc_shared_zero (TC_ARGS)
{
  TC_T(TC_TYPE) a = TC_NAME(mls_rm, TC_TYPE) (in);
  TC_STORE (out, TC_ACC (a, a, 0));
  TC_STORE (saved, a);
}

void tc_shared_constant (TC_ARGS)
{
  TC_T(TC_TYPE) a = TC_NAME(mls_rm, TC_TYPE) (in);
  TC_STORE (out, TC_ACC (a, a, 3));
  TC_STORE (saved, a);
}

void tc_shared_copy (TC_ARGS)
{
  TC_T(TC_TYPE) a = TC_NAME(mls_rm, TC_TYPE) (in);
  TC_T(TC_TYPE) b = TC_NAME(mcopy_m2m, TC_TYPE) (a);
  TC_STORE (out, TC_ACC (a, b, e));
  TC_STORE (saved, a);
}

void tc_shared_call (TC_ARGS)
{
  TC_T(TC_TYPE) a = TC_NAME(mls_rm, TC_TYPE) (in);
  tc_callee ();
  TC_STORE (out, TC_ACC (a, a, e));
  TC_STORE (saved, a);
}

void tc_shared_after (TC_ARGS)
{
  TC_T(TC_TYPE) a = TC_NAME(mls_rm, TC_TYPE) (in);
  TC_STORE (out, TC_ACC (a, a, e));
  tc_callee ();
  TC_STORE (saved, a);
}

void tc_shared_dead (TC_ARGS)
{
  TC_T(TC_TYPE) a = TC_NAME(mls_rm, TC_TYPE) (in);
  TC_STORE (out, TC_ACC (a, a, e));
}

void tc_shared_chain (TC_ARGS)
{
  TC_T(TC_TYPE) a = TC_NAME(mls_rm, TC_TYPE) (in);
  TC_T(TC_TYPE) b = TC_ACC (a, a, e);
  TC_STORE (out, TC_ACC (b, b, e));
  TC_STORE (saved, a);
  TC_STORE (extra, b);
}
#ifdef __cplusplus
}
#endif
