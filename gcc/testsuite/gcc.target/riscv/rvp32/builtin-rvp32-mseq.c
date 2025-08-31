/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** mseq\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f0 (int32_t x0, int32_t x1){
    return __rv_mseq(x0, x1);
}

/*
**f1:
** pmseq.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x4_t f1 (int8x4_t x0, int8x4_t x1){
    return __rv_pmseq_b(x0, x1);
}

/*
**f2:
** pmseq.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f2 (int16x2_t x0, int16x2_t x1){
    return __rv_pmseq_h(x0, x1);
}

/*
**f3:
** mslt\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f3 (int32_t x0, int32_t x1){
    return __rv_mslt(x0, x1);
}

/*
**f4:
** pmslt.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x4_t f4 (int8x4_t x0, int8x4_t x1){
    return __rv_pmslt_b(x0, x1);
}

/*
**f5:
** pmslt.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f5 (int16x2_t x0, int16x2_t x1){
    return __rv_pmslt_h(x0, x1);
}

/*
**f6:
** msltu\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32_t f6 (uint32_t x0, uint32_t x1){
    return __rv_msltu(x0, x1);
}

/*
**f7:
** pmsltu.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x4_t f7 (uint8x4_t x0, uint8x4_t x1){
    return __rv_pmsltu_b(x0, x1);
}

/*
**f8:
** pmsltu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x2_t f8 (uint16x2_t x0, uint16x2_t x1){
    return __rv_pmsltu_h(x0, x1);
}

/*
**f9:
** pmin.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x4_t f9 (int8x4_t x0, int8x4_t x1){
    return __rv_pmin_b(x0, x1);
}

/*
**f10:
** pmin.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f10 (int16x2_t x0, int16x2_t x1){
    return __rv_pmin_h(x0, x1);
}

/*
**f11:
** pminu.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x4_t f11 (uint8x4_t x0, uint8x4_t x1){
    return __rv_pminu_b(x0, x1);
}

/*
**f12:
** pminu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x2_t f12 (uint16x2_t x0, uint16x2_t x1){
    return __rv_pminu_h(x0, x1);
}

/*
**f13:
** pmax.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x4_t f13 (int8x4_t x0, int8x4_t x1){
    return __rv_pmax_b(x0, x1);
}

/*
**f14:
** pmax.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f14 (int16x2_t x0, int16x2_t x1){
    return __rv_pmax_h(x0, x1);
}

/*
**f15:
** pmaxu.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x4_t f15 (uint8x4_t x0, uint8x4_t x1){
    return __rv_pmaxu_b(x0, x1);
}

/*
**f16:
** pmaxu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x2_t f16 (uint16x2_t x0, uint16x2_t x1){
    return __rv_pmaxu_h(x0, x1);
}

