/* { dg-do compile { target { rv64 } } } */
/* { dg-options "-march=rv64gcv_zvzip0p1 -mabi=lp64d -O2" } */

#include "riscv_vector.h"

vint8m2_t
test_vzip_tu (vint8m2_t merge, vint8m1_t a, vint8m1_t b, size_t vl)
{
  return __riscv_vzip_vv_i8m2_tu (merge, a, b, vl);
}

vint8m2_t
test_vzip_tum (vbool8_t mask, vint8m2_t merge, vint8m1_t a,
	       vint8m1_t b, size_t vl)
{
  return __riscv_vzip_vv_i8m2_tum (mask, merge, a, b, vl);
}

vint8m2_t
test_vzip_tumu (vbool8_t mask, vint8m2_t merge, vint8m1_t a,
		vint8m1_t b, size_t vl)
{
  return __riscv_vzip_vv_i8m2_tumu (mask, merge, a, b, vl);
}

vint8m2_t
test_vzip_mu (vbool8_t mask, vint8m2_t merge, vint8m1_t a,
	      vint8m1_t b, size_t vl)
{
  return __riscv_vzip_vv_i8m2_mu (mask, merge, a, b, vl);
}

vint8m1_t
test_vunzipe_tu (vint8m1_t merge, vint8m2_t a, size_t vl)
{
  return __riscv_vunzipe_v_i8m1_tu (merge, a, vl);
}

vint8m1_t
test_vunzipe_tum (vbool8_t mask, vint8m1_t merge, vint8m2_t a,
		  size_t vl)
{
  return __riscv_vunzipe_v_i8m1_tum (mask, merge, a, vl);
}

vint8m1_t
test_vunzipe_tumu (vbool8_t mask, vint8m1_t merge, vint8m2_t a,
		   size_t vl)
{
  return __riscv_vunzipe_v_i8m1_tumu (mask, merge, a, vl);
}

vint8m1_t
test_vunzipe_mu (vbool8_t mask, vint8m1_t merge, vint8m2_t a, size_t vl)
{
  return __riscv_vunzipe_v_i8m1_mu (mask, merge, a, vl);
}

vint8m1_t
test_vunzipo_tu (vint8m1_t merge, vint8m2_t a, size_t vl)
{
  return __riscv_vunzipo_v_i8m1_tu (merge, a, vl);
}

vint8m1_t
test_vunzipo_tum (vbool8_t mask, vint8m1_t merge, vint8m2_t a,
		  size_t vl)
{
  return __riscv_vunzipo_v_i8m1_tum (mask, merge, a, vl);
}

vint8m1_t
test_vunzipo_tumu (vbool8_t mask, vint8m1_t merge, vint8m2_t a,
		   size_t vl)
{
  return __riscv_vunzipo_v_i8m1_tumu (mask, merge, a, vl);
}

vint8m1_t
test_vunzipo_mu (vbool8_t mask, vint8m1_t merge, vint8m2_t a, size_t vl)
{
  return __riscv_vunzipo_v_i8m1_mu (mask, merge, a, vl);
}

vuint16m1_t
test_vpaire_tu (vuint16m1_t merge, vuint16m1_t a, vuint16m1_t b,
		size_t vl)
{
  return __riscv_vpaire_vv_u16m1_tu (merge, a, b, vl);
}

vuint16m1_t
test_vpaire_tum (vbool16_t mask, vuint16m1_t merge, vuint16m1_t a,
		 vuint16m1_t b, size_t vl)
{
  return __riscv_vpaire_vv_u16m1_tum (mask, merge, a, b, vl);
}

vuint16m1_t
test_vpaire_tumu (vbool16_t mask, vuint16m1_t merge, vuint16m1_t a,
		  vuint16m1_t b, size_t vl)
{
  return __riscv_vpaire_vv_u16m1_tumu (mask, merge, a, b, vl);
}

vuint16m1_t
test_vpaire_mu (vbool16_t mask, vuint16m1_t merge, vuint16m1_t a,
		vuint16m1_t b, size_t vl)
{
  return __riscv_vpaire_vv_u16m1_mu (mask, merge, a, b, vl);
}

vuint16m1_t
test_vpairo_tu (vuint16m1_t merge, vuint16m1_t a, vuint16m1_t b,
		size_t vl)
{
  return __riscv_vpairo_vv_u16m1_tu (merge, a, b, vl);
}

vuint16m1_t
test_vpairo_tum (vbool16_t mask, vuint16m1_t merge, vuint16m1_t a,
		 vuint16m1_t b, size_t vl)
{
  return __riscv_vpairo_vv_u16m1_tum (mask, merge, a, b, vl);
}

vuint16m1_t
test_vpairo_tumu (vbool16_t mask, vuint16m1_t merge, vuint16m1_t a,
		  vuint16m1_t b, size_t vl)
{
  return __riscv_vpairo_vv_u16m1_tumu (mask, merge, a, b, vl);
}

vuint16m1_t
test_vpairo_mu (vbool16_t mask, vuint16m1_t merge, vuint16m1_t a,
		vuint16m1_t b, size_t vl)
{
  return __riscv_vpairo_vv_u16m1_mu (mask, merge, a, b, vl);
}
