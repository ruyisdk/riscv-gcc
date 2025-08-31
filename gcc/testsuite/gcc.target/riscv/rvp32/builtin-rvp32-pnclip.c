/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pnclipiu.b\ta[0-9],a[0-9],1
** ...
*/

int32_t f0 (int64_t x0, int32_t x1){
    return __rv_pnclipiu_b(x0, 1);
}

/*
**f1:
** pnclipiu.h\ta[0-9],a[0-9],1
** ...
*/

int32_t f1 (int64_t x0, int32_t x1){
    return __rv_pnclipiu_h(x0, 1);
}

/*
**f2:
** nclipiu\ta[0-9],a[0-9],1
** ...
*/

int32_t f2 (int64_t x0, int32_t x1){
    return __rv_nclipiu(x0, 1);
}

/*
**f3:
** pnclipriu.b\ta[0-9],a[0-9],1
** ...
*/

int32_t f3 (int64_t x0, int32_t x1){
    return __rv_pnclipriu_b(x0, 1);
}

/*
**f4:
** pnclipriu.h\ta[0-9],a[0-9],1
** ...
*/

int32_t f4 (int64_t x0, int32_t x1){
    return __rv_pnclipriu_h(x0, 1);
}

/*
**f5:
** nclipriu\ta[0-9],a[0-9],1
** ...
*/

int32_t f5 (int64_t x0, int32_t x1){
    return __rv_nclipriu(x0, 1);
}
