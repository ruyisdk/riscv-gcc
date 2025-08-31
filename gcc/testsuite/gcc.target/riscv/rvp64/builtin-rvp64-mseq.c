/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pmseq.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x8_t f0 (int8x8_t x0, int8x8_t x1){
    return __rv_pmseq_b(x0, x1);
}

/*
**f1:
** pmseq.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f1 (int16x4_t x0, int16x4_t x1){
    return __rv_pmseq_h(x0, x1);
}

/*
**f2:
** pmseq.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f2 (int32x2_t x0, int32x2_t x1){
    return __rv_pmseq_w(x0, x1);
}

/*
**f3:
** pmslt.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x8_t f3 (int8x8_t x0, int8x8_t x1){
    return __rv_pmslt_b(x0, x1);
}

/*
**f4:
** pmslt.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f4 (int16x4_t x0, int16x4_t x1){
    return __rv_pmslt_h(x0, x1);
}

/*
**f5:
** pmslt.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f5 (int32x2_t x0, int32x2_t x1){
    return __rv_pmslt_w(x0, x1);
}

/*
**f6:
** pmsltu.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x8_t f6 (uint8x8_t x0, uint8x8_t x1){
    return __rv_pmsltu_b(x0, x1);
}

/*
**f7:
** pmsltu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x4_t f7 (uint16x4_t x0, uint16x4_t x1){
    return __rv_pmsltu_h(x0, x1);
}

/*
**f8:
** pmsltu.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32x2_t f8 (uint32x2_t x0, uint32x2_t x1){
    return __rv_pmsltu_w(x0, x1);
}

/*
**f9:
** pmin.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x8_t f9 (int8x8_t x0, int8x8_t x1){
    return __rv_pmin_b(x0, x1);
}

/*
**f10:
** pmin.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f10 (int16x4_t x0, int16x4_t x1){
    return __rv_pmin_h(x0, x1);
}

/*
**f11:
** pmin.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f11 (int32x2_t x0, int32x2_t x1){
    return __rv_pmin_w(x0, x1);
}

/*
**f12:
** pminu.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x8_t f12 (uint8x8_t x0, uint8x8_t x1){
    return __rv_pminu_b(x0, x1);
}

/*
**f13:
** pminu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x4_t f13 (uint16x4_t x0, uint16x4_t x1){
    return __rv_pminu_h(x0, x1);
}

/*
**f14:
** pminu.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32x2_t f14 (uint32x2_t x0, uint32x2_t x1){
    return __rv_pminu_w(x0, x1);
}

/*
**f15:
** pmax.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x8_t f15 (int8x8_t x0, int8x8_t x1){
    return __rv_pmax_b(x0, x1);
}

/*
**f16:
** pmax.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f16 (int16x4_t x0, int16x4_t x1){
    return __rv_pmax_h(x0, x1);
}

/*
**f17:
** pmax.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f17 (int32x2_t x0, int32x2_t x1){
    return __rv_pmax_w(x0, x1);
}

/*
**f18:
** pmaxu.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x8_t f18 (uint8x8_t x0, uint8x8_t x1){
    return __rv_pmaxu_b(x0, x1);
}

/*
**f19:
** pmaxu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x4_t f19 (uint16x4_t x0, uint16x4_t x1){
    return __rv_pmaxu_h(x0, x1);
}

/*
**f20:
** pmaxu.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32x2_t f20 (uint32x2_t x0, uint32x2_t x1){
    return __rv_pmaxu_w(x0, x1);
}
