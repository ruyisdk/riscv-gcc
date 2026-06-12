/* { dg-do compile { target { rv64 } } } */
/* { dg-options "-march=rv64gcv_zvzip0p1 -mabi=lp64d -O2" } */

#include "riscv_vector.h"

vbfloat16m2_t
test_vzip_vv_bf16m2 (vbfloat16m1_t a, vbfloat16m1_t b, size_t vl)
{
  return __riscv_vzip_vv_bf16m2 (a, b, vl); /* { dg-error {requires.*zvfbfmin} } */
}
