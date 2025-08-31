/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pwadd.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f0 (int32_t x0, int32_t x1){
    return __rv_pwadd_b(x0, x1);
}

/*
**f1:
** pwadd.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f1 (int32_t x0, int32_t x1){
    return __rv_pwadd_h(x0, x1);
}

/*
**f2:
** wadd\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f2 (int32_t x0, int32_t x1){
    return __rv_wadd(x0, x1);
}

/*
**f3:
** pwadda.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f3 (int32_t x0, int32_t x1){
    return __rv_pwadda_b(x0, x1);
}

/*
**f4:
** pwadda.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f4 (int32_t x0, int32_t x1){
    return __rv_pwadda_h(x0, x1);
}

/*
**f5:
** wadda\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f5 (int32_t x0, int32_t x1){
    return __rv_wadda(x0, x1);
}

/*
**f6:
** pwaddu.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f6 (int32_t x0, int32_t x1){
    return __rv_pwaddu_b(x0, x1);
}

/*
**f7:
** pwaddu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f7 (int32_t x0, int32_t x1){
    return __rv_pwaddu_h(x0, x1);
}

/*
**f8:
** waddu\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f8 (int32_t x0, int32_t x1){
    return __rv_waddu(x0, x1);
}

/*
**f9:
** pwaddau.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f9 (int32_t x0, int32_t x1){
    return __rv_pwaddau_b(x0, x1);
}

/*
**f10:
** pwaddau.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f10 (int32_t x0, int32_t x1){
    return __rv_pwaddau_h(x0, x1);
}

/*
**f11:
** waddau\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f11 (int32_t x0, int32_t x1){
    return __rv_waddau(x0, x1);
}
