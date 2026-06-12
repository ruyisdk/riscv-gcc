/* { dg-do compile { target { rv64 } } } */
/* { dg-options "-march=rv64gcv_zvzip0p1 -mabi=lp64d -O2" } */

#include "riscv_vector.h"

/* This follows the current rvv-intrinsic-doc PR #431:
   masked vzip uses the source vector mask type.  */

vint8m2_t
test_vzip_mask_source_type (vbool8_t mask, vint8m1_t a, vint8m1_t b,
			    size_t vl)
{
  return __riscv_vzip_vv_i8m2_m (mask, a, b, vl);
}

vint8m2_t
test_vzip_mask_return_type_rejected (vbool4_t mask, vint8m1_t a,
				     vint8m1_t b, size_t vl)
{
  return __riscv_vzip_vv_i8m2_m (mask, a, b, vl); /* { dg-error {incompatible type|invalid argument} } */
}
