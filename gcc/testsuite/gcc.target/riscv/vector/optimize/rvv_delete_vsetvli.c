/* { dg-do compile } */
/* { dg-skip-if "test rvv optimize" { *-*-* } { "*" } { "-march=rv*v*" } } */

#include <riscv_vector.h>

uint8_t c=4;
float64_t f1=0.4;
float64_t test_vfmacc_vv_f64m1 (vfloat64m1_t vd, vfloat64m1_t vs1, vfloat64m1_t vs2)
{
  size_t vl = vsetvlmax_e64m1 ();
  vd = vfmacc_vv_f64m1 (vd, vs1, vs2, vl);
  f1 = vfmv_f_s_f64m1_f64 (vd);
  return f1 + 0.4;
}

/* { dg-final { scan-assembler-times "vsetvli\t" 1} } */