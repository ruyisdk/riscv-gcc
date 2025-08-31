/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** unzip8p\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f0 (int64_t x0, int64_t x1){
    return __rv_unzip8p(x0, x1);
}

/*
**f1:
** unzip16p\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f1 (int64_t x0, int64_t x1){
    return __rv_unzip16p(x0, x1);
}

/*
**f2:
** unzip8hp\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f2 (int64_t x0, int64_t x1){
    return __rv_unzip8hp(x0, x1);
}

/*
**f3:
** unzip16hp\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f3 (int64_t x0, int64_t x1){
    return __rv_unzip16hp(x0, x1);
}

/*
**f4:
** zip8p\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f4 (int64_t x0, int64_t x1){
    return __rv_zip8p(x0, x1);
}

/*
**f5:
** zip16p\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f5 (int64_t x0, int64_t x1){
    return __rv_zip16p(x0, x1);
}

/*
**f6:
** zip8hp\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f6 (int64_t x0, int64_t x1){
    return __rv_zip8hp(x0, x1);
}

/*
**f7:
** zip16hp\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f7 (int64_t x0, int64_t x1){
    return __rv_zip16hp(x0, x1);
}
