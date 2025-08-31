/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pslli.db\ta[0-9],a[0-9],1
** ...
*/

int64_t f0 (int64_t x0, int32_t x1){
    return __rv_pslli_db(x0, 1);
}

/*
**f1:
** pslli.dh\ta[0-9],a[0-9],1
** ...
*/

int64_t f1 (int64_t x0, int32_t x1){
    return __rv_pslli_dh(x0, 1);
}

/*
**f2:
** pslli.dw\ta[0-9],a[0-9],1
** ...
*/

int64_t f2 (int64_t x0, int32_t x1){
    return __rv_pslli_dw(x0, 1);
}

/*
**f3:
** psll.dbs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f3 (int64_t x0, int32_t x1){
    return __rv_psll_dbs(x0, x1);
}

/*
**f4:
** psll.dhs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f4 (int64_t x0, int32_t x1){
    return __rv_psll_dhs(x0, x1);
}

/*
**f5:
** psll.dws\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f5 (int64_t x0, int32_t x1){
    return __rv_psll_dws(x0, x1);
}

/*
**f6:
** psslai.dh\ta[0-9],a[0-9],1
** ...
*/

int64_t f6 (int64_t x0, int32_t x1){
    return __rv_psslai_dh(x0, 1);
}

/*
**f7:
** psslai.dw\ta[0-9],a[0-9],1
** ...
*/

int64_t f7 (int64_t x0, int32_t x1){
    return __rv_psslai_dw(x0, 1);
}

/*
**f8:
** pssha.dhs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f8 (int64_t x0, int32_t x1){
    return __rv_pssha_dhs(x0, x1);
}

/*
**f9:
** pssha.dws\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f9 (int64_t x0, int32_t x1){
    return __rv_pssha_dws(x0, x1);
}

/*
**f10:
** psshar.dhs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f10 (int64_t x0, int32_t x1){
    return __rv_psshar_dhs(x0, x1);
}

/*
**f11:
** psshar.dws\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f11 (int64_t x0, int32_t x1){
    return __rv_psshar_dws(x0, x1);
}

/*
**f12:
** psrl.dbs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f12 (int64_t x0, int32_t x1){
    return __rv_psrl_dbs(x0, x1);
}

/*
**f13:
** psrl.dhs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f13 (int64_t x0, int32_t x1){
    return __rv_psrl_dhs(x0, x1);
}

/*
**f14:
** psrl.dws\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f14 (int64_t x0, int32_t x1){
    return __rv_psrl_dws(x0, x1);
}

/*
**f15:
** psra.dbs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f15 (int64_t x0, int32_t x1){
    return __rv_psra_dbs(x0, x1);
}

/*
**f16:
** psra.dhs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f16 (int64_t x0, int32_t x1){
    return __rv_psra_dhs(x0, x1);
}

/*
**f17:
** psra.dws\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f17 (int64_t x0, int32_t x1){
    return __rv_psra_dws(x0, x1);
}
