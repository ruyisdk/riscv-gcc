/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** psh1add.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f0 (int16x4_t x0, int16x4_t x1){
    return __rv_psh1add_h(x0, x1);
}

/*
**f0:
** psh1add.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f1 (int32x2_t x0, int32x2_t x1){
    return __rv_psh1add_w(x0, x1);
}

/*
**f0:
** pssh1sadd.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f2 (int16x4_t x0, int16x4_t x1){
    return __rv_pssh1sadd_h(x0, x1);
}

/*
**f0:
** pssh1sadd.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f3 (int32x2_t x0, int32x2_t x1){
    return __rv_pssh1sadd_w(x0, x1);
}
