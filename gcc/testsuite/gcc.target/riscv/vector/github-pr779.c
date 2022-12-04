/* { dg-do compile } */
/* { dg-skip-if "test rvv" { *-*-* } { "*" } { "-march=rv32*v*" } } */

#include <riscv_vector.h>
int32_t x_to_s(int32_t i, word_type vl)
{
   vint32m8_t v;
   v    = vmv_s_x_i32m8(v, i, vl);
   return vmv_x_s_i32m8_i32(v);
}

