/* { dg-do compile { target { rv64 } } } */
/* { dg-options "-march=rv64gcv_zvzip0p1 -mabi=lp64d -O2" } */

#include "riscv_vector.h"

vint8m2_t
test_vzip_vv_i8m2 (vint8m1_t a, vint8m1_t b, size_t vl)
{
  return __riscv_vzip_vv_i8m2 (a, b, vl);
}

/* This follows the current rvv-intrinsic-doc PR #431.  */
vint8m2_t
test_vzip_vv_i8m2_m (vbool8_t mask, vint8m1_t a, vint8m1_t b, size_t vl)
{
  return __riscv_vzip_vv_i8m2_m (mask, a, b, vl);
}

vint8m1_t
test_vunzipe_v_i8m1 (vint8m2_t a, size_t vl)
{
  return __riscv_vunzipe_v_i8m1 (a, vl);
}

vint8m1_t
test_vunzipe_v_i8m1_m (vbool8_t mask, vint8m2_t a, size_t vl)
{
  return __riscv_vunzipe_v_i8m1_m (mask, a, vl);
}

vint8m1_t
test_vunzipo_v_i8m1 (vint8m2_t a, size_t vl)
{
  return __riscv_vunzipo_v_i8m1 (a, vl);
}

vint8m1_t
test_vunzipo_v_i8m1_m (vbool8_t mask, vint8m2_t a, size_t vl)
{
  return __riscv_vunzipo_v_i8m1_m (mask, a, vl);
}

vuint16m1_t
test_vpaire_vv_u16m1 (vuint16m1_t a, vuint16m1_t b, size_t vl)
{
  return __riscv_vpaire_vv_u16m1 (a, b, vl);
}

vuint16m1_t
test_vpaire_vv_u16m1_m (vbool16_t mask, vuint16m1_t a, vuint16m1_t b,
			size_t vl)
{
  return __riscv_vpaire_vv_u16m1_m (mask, a, b, vl);
}

vuint16m1_t
test_vpairo_vv_u16m1 (vuint16m1_t a, vuint16m1_t b, size_t vl)
{
  return __riscv_vpairo_vv_u16m1 (a, b, vl);
}

vuint16m1_t
test_vpairo_vv_u16m1_m (vbool16_t mask, vuint16m1_t a, vuint16m1_t b,
			size_t vl)
{
  return __riscv_vpairo_vv_u16m1_m (mask, a, b, vl);
}

/* { dg-final { scan-assembler-times {vzip\.vv} 2 } } */
/* { dg-final { scan-assembler-times {vunzipe\.v} 2 } } */
/* { dg-final { scan-assembler-times {vunzipo\.v} 2 } } */
/* { dg-final { scan-assembler-times {vpaire\.vv} 2 } } */
/* { dg-final { scan-assembler-times {vpairo\.vv} 2 } } */
/* { dg-final { scan-assembler-times {vzip\.vv[ \t]+v[0-9]+,[ \t]*v[0-9]+,[ \t]*v[0-9]+,[ \t]*v0\.t} 1 } } */
/* { dg-final { scan-assembler-times {vunzipe\.v[ \t]+v[0-9]+,[ \t]*v[0-9]+,[ \t]*v0\.t} 1 } } */
/* { dg-final { scan-assembler-times {vunzipo\.v[ \t]+v[0-9]+,[ \t]*v[0-9]+,[ \t]*v0\.t} 1 } } */
/* { dg-final { scan-assembler-times {vpaire\.vv[ \t]+v[0-9]+,[ \t]*v[0-9]+,[ \t]*v[0-9]+,[ \t]*v0\.t} 1 } } */
/* { dg-final { scan-assembler-times {vpairo\.vv[ \t]+v[0-9]+,[ \t]*v[0-9]+,[ \t]*v[0-9]+,[ \t]*v0\.t} 1 } } */
