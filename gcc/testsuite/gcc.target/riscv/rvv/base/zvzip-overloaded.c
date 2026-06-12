/* { dg-do compile { target { rv64 } } } */
/* { dg-options "-march=rv64gcv_zvzip0p1 -mabi=lp64d -O2" } */

#include "riscv_vector.h"

vint8m2_t
test_vzip_overloaded (vint8m1_t a, vint8m1_t b, size_t vl)
{
  return __riscv_vzip (a, b, vl);
}

vint8m2_t
test_vzip_overloaded_m (vbool8_t mask, vint8m1_t a, vint8m1_t b,
			size_t vl)
{
  return __riscv_vzip (mask, a, b, vl);
}

vint8m1_t
test_vunzipe_overloaded (vint8m2_t a, size_t vl)
{
  return __riscv_vunzipe (a, vl);
}

vint8m1_t
test_vunzipo_overloaded (vint8m2_t a, size_t vl)
{
  return __riscv_vunzipo (a, vl);
}

vuint16m1_t
test_vpaire_overloaded (vuint16m1_t a, vuint16m1_t b, size_t vl)
{
  return __riscv_vpaire (a, b, vl);
}

vuint16m1_t
test_vpairo_overloaded (vuint16m1_t a, vuint16m1_t b, size_t vl)
{
  return __riscv_vpairo (a, b, vl);
}

/* { dg-final { scan-assembler-times {vzip\.vv} 2 } } */
/* { dg-final { scan-assembler-times {vunzipe\.v} 1 } } */
/* { dg-final { scan-assembler-times {vunzipo\.v} 1 } } */
/* { dg-final { scan-assembler-times {vpaire\.vv} 1 } } */
/* { dg-final { scan-assembler-times {vpairo\.vv} 1 } } */
/* { dg-final { scan-assembler-times {vzip\.vv[ \t]+v[0-9]+,[ \t]*v[0-9]+,[ \t]*v[0-9]+,[ \t]*v0\.t} 1 } } */
