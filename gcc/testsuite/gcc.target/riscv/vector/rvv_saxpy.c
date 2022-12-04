/* { dg-do compile } */
/* { dg-skip-if "test rvv" { *-*-* } { "*" } { "-march=rv*v*" } } */

#include <riscv_vector.h>
#include <stddef.h>

void saxpy(size_t n, const float a, const float *x, float *y) {
  size_t l;

  vfloat32m8_t vx, vy;

  for (; (l = vsetvl_e32m8(n)) > 0; n -= l) {
    vx = vle32_v_f32m8(x, l);
    x += l;
    vy = vle32_v_f32m8(y, l);
    // vfmacc
    vy = vfmacc_vf_f32m8(vy, a, vx, l);
    vse32_v_f32m8(y, vy, l);
    y += l;
  }
}

/* { dg-final { scan-assembler-times "vsetvli" 1 } } */
/* { dg-final { scan-assembler-times "vle32.v" 2 } } */
/* { dg-final { scan-assembler "vf(?:macc|madd).vf" } } */
/* { dg-final { scan-assembler "vse32.v" } } */
