/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pmseq.db\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f0 (int64_t x0, int64_t x1){
    return __rv_pmseq_db(x0, x1);
}

/*
**f1:
** pmseq.dh\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f1 (int64_t x0, int64_t x1){
    return __rv_pmseq_dh(x0, x1);
}

/*
**f2:
** pmseq.dw\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f2 (int64_t x0, int64_t x1){
    return __rv_pmseq_dw(x0, x1);
}

/*
**f3:
** pmslt.db\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f3 (int64_t x0, int64_t x1){
    return __rv_pmslt_db(x0, x1);
}

/*
**f4:
** pmslt.dh\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f4 (int64_t x0, int64_t x1){
    return __rv_pmslt_dh(x0, x1);
}

/*
**f5:
** pmslt.dw\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f5 (int64_t x0, int64_t x1){
    return __rv_pmslt_dw(x0, x1);
}

/*
**f6:
** pmsltu.db\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f6 (int64_t x0, int64_t x1){
    return __rv_pmsltu_db(x0, x1);
}

/*
**f7:
** pmsltu.dh\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f7 (int64_t x0, int64_t x1){
    return __rv_pmsltu_dh(x0, x1);
}

/*
**f8:
** pmsltu.dw\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f8 (int64_t x0, int64_t x1){
    return __rv_pmsltu_dw(x0, x1);
}
