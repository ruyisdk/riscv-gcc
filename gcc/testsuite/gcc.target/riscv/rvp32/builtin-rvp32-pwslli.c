/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pwslli.b\ta[0-9],a[0-9],1
** ...
*/

int64_t f0 (int32_t x0, int32_t x1){
    return __rv_pwslli_b(x0, 1);
}

/*
**f1:
** pwslli.h\ta[0-9],a[0-9],1
** ...
*/

int64_t f1 (int32_t x0, int32_t x1){
    return __rv_pwslli_h(x0, 1);
}

/*
**f2:
** wslli\ta[0-9],a[0-9],1
** ...
*/

int64_t f2 (int32_t x0, int32_t x1){
    return __rv_wslli(x0, 1);
}

/*
**f3:
** pwslai.b\ta[0-9],a[0-9],1
** ...
*/

int64_t f3 (int32_t x0, int32_t x1){
    return __rv_pwslai_b(x0, 1);
}

/*
**f4:
** pwslai.h\ta[0-9],a[0-9],1
** ...
*/

int64_t f4 (int32_t x0, int32_t x1){
    return __rv_pwslai_h(x0, 1);
}

/*
**f5:
** wslai\ta[0-9],a[0-9],1
** ...
*/

int64_t f5 (int32_t x0, int32_t x1){
    return __rv_wslai(x0, 1);
}

/*
**f6:
** pwsll.bs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f6 (int32_t x0, int32_t x1){
    return __rv_pwsll_bs(x0, x1);
}

/*
**f7:
** pwsll.hs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f7 (int32_t x0, int32_t x1){
    return __rv_pwsll_hs(x0, x1);
}

/*
**f8:
** wsll\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f8 (int32_t x0, int32_t x1){
    return __rv_wsll(x0, x1);
}

/*
**f9:
** pwsla.bs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f9 (int32_t x0, int32_t x1){
    return __rv_pwsla_bs(x0, x1);
}

/*
**f10:
** pwsla.hs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f10 (int32_t x0, int32_t x1){
    return __rv_pwsla_hs(x0, x1);
}

/*
**f11:
** wsla\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f11 (int32_t x0, int32_t x1){
    return __rv_wsla(x0, x1);
}
