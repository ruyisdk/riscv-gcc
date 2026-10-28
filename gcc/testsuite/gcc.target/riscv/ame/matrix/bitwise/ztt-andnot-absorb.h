#ifdef AC_TYPE
#define AN_TYPE AC_TYPE
#define AN_CARRIER AC_ELEMENT
#define AN_SHAPE AC_SHAPE
#endif
#include "ztt-andnot-zero.h"
#ifdef __cplusplus
extern "C" {
#endif
void an_observed (AN_ARGS, element_t *saved)
{
  matrix_t a = AN_OP(mls_rm) (in);
  matrix_t z = AN_OP(mzero_m) ();
  matrix_t v = AN_OP(mandnot_ew) (z, a);
  __riscv_ztt_mss_rm (saved, a);
  __riscv_ztt_mss_rm (out, v);
}
void an_copy_observed (AN_ARGS, element_t *saved)
{
  matrix_t a = AN_OP(mls_rm) (in);
  matrix_t z = AN_OP(mzero_m) ();
  matrix_t c1 = AN_OP(mcopy_m2m) (z);
  matrix_t c2 = AN_OP(mcopy_m2m) (c1);
  matrix_t v = AN_OP(mandnot_ew) (c2, a);
  __riscv_ztt_mss_rm (saved, a);
  __riscv_ztt_mss_rm (out, v);
}
void an_deep_observed (AN_ARGS, element_t *saved)
{
  matrix_t a = AN_OP(mls_rm) (in);
  matrix_t z = AN_OP(mzero_m) ();
  matrix_t c1 = AN_OP(mcopy_m2m) (z);
  matrix_t c2 = AN_OP(mcopy_m2m) (c1);
  matrix_t c3 = AN_OP(mcopy_m2m) (c2);
  matrix_t c4 = AN_OP(mcopy_m2m) (c3);
  matrix_t c5 = AN_OP(mcopy_m2m) (c4);
  matrix_t v = AN_OP(mandnot_ew) (c5, a);
  __riscv_ztt_mss_rm (saved, a);
  __riscv_ztt_mss_rm (out, v);
}
void an_live_source (AN_ARGS, element_t *saved)
{
  matrix_t a = AN_OP(mls_rm) (in);
  matrix_t z = AN_OP(mzero_m) ();
  matrix_t v = AN_OP(mandnot_ew) (z, a);
  an_callee ();
  __riscv_ztt_mss_rm (saved, a);
  __riscv_ztt_mss_rm (out, v);
}
#ifdef __cplusplus
}
#endif
