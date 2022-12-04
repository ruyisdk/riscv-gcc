/* { dg-do compile } */
/* { dg-skip-if "test rvv optimize" { *-*-* } { "-march=rv*v0p7*" } { "" } } */

#include <riscv_vector.h>

extern void consume(vuint8m1_t);

void f(vuint8m1x2_t data)
{
    for (int i = 0; i < 4; i++)
    {
        size_t gvl = vsetvlmax_e8m1();
        vuint8m1_t res = vget_u8m1x2_u8m1(data, 0);
        consume(res);
    }
}

/* { dg-final { scan-assembler-times "csrr\ts11,vlenb" 1} } */
