/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pusati.h\ta[0-9],a[0-9],1
** ...
*/

uint16x4_t f0 (uint16x4_t x0, int64_t x1){
    return __rv_pusati_h(x0, 1);
}

/*
**f1:
** pusati.w\ta[0-9],a[0-9],1
** ...
*/

uint32x2_t f1 (uint32x2_t x0, int64_t x1){
    return __rv_pusati_w(x0, 1);
}

/*
**f2:
** usati\ta[0-9],a[0-9],1
** ...
*/

uint64_t f2 (uint64_t x0, int64_t x1){
    return __rv_usati(x0, 1);
}
