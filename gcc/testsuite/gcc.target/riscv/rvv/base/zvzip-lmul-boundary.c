/* { dg-do compile { target { rv64 } } } */
/* { dg-options "-march=rv64gcv_zvzip0p1 -mabi=lp64d -O2 -Werror=implicit-function-declaration" } */

#include "riscv_vector.h"

void
test_vzip_lmul_boundary (vint8m8_t a, size_t vl)
{
  __riscv_vzip_vv_i8m16 (a, a, vl); /* { dg-error {implicit declaration} } */
  __riscv_vunzipe_v_i8m8 (a, vl); /* { dg-error {implicit declaration} } */
  __riscv_vunzipo_v_i8m8 (a, vl); /* { dg-error {implicit declaration} } */
}

vint8m8_t
test_vzip_lmul_boundary_ok (vint8m4_t a, size_t vl)
{
  return __riscv_vzip_vv_i8m8 (a, a, vl);
}

vint8m4_t
test_vunzipe_lmul_boundary_ok (vint8m8_t a, size_t vl)
{
  return __riscv_vunzipe_v_i8m4 (a, vl);
}

vint8m4_t
test_vunzipo_lmul_boundary_ok (vint8m8_t a, size_t vl)
{
  return __riscv_vunzipo_v_i8m4 (a, vl);
}
