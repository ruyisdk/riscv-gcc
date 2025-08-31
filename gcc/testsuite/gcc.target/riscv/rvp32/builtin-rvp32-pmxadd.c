/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pm2add.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f0 (int16x2_t x0, int16x2_t x1){
    return __rv_pm2add_h(x0, x1);
}

/*
**f1:
** pm4add.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x4_t f1 (int8x4_t x0, int8x4_t x1){
    return __rv_pm4add_b(x0, x1);
}

/*
**f2:
** pm2adda.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f2 (int16x2_t x0, int16x2_t x1){
    return __rv_pm2adda_h(x0, x1);
}

/*
**f3:
** pm4adda.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x4_t f3 (int8x4_t x0, int8x4_t x1){
    return __rv_pm4adda_b(x0, x1);
}

/*
**f4:
** pm2add.hx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f4 (int16x2_t x0, int16x2_t x1){
    return __rv_pm2add_hx(x0, x1);
}

/*
**f5:
** pm2adda.hx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f5 (int16x2_t x0, int16x2_t x1){
    return __rv_pm2adda_hx(x0, x1);
}

/*
**f6:
** pm2addu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x2_t f6 (uint16x2_t x0, uint16x2_t x1){
    return __rv_pm2addu_h(x0, x1);
}

/*
**f7:
** pm4addu.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x4_t f7 (uint8x4_t x0, uint8x4_t x1){
    return __rv_pm4addu_b(x0, x1);
}

/*
**f8:
** pm2addau.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x2_t f8 (uint16x2_t x0, uint16x2_t x1){
    return __rv_pm2addau_h(x0, x1);
}

/*
**f9:
** pm4addau.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x4_t f9 (uint8x4_t x0, uint8x4_t x1){
    return __rv_pm4addau_b(x0, x1);
}

/*
**f10:
** pmq2add.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f10 (int16x2_t x0, int16x2_t x1){
    return __rv_pmq2add_h(x0, x1);
}

/*
**f11:
** pmqr2add.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f11 (int16x2_t x0, int16x2_t x1){
    return __rv_pmqr2add_h(x0, x1);
}

/*
**f12:
** pmq2adda.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f12 (int16x2_t x0, int16x2_t x1){
    return __rv_pmq2adda_h(x0, x1);
}

/*
**f13:
** pmqr2adda.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f13 (int16x2_t x0, int16x2_t x1){
    return __rv_pmqr2adda_h(x0, x1);
}

/*
**f14:
** pm2sub.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f14 (int16x2_t x0, int16x2_t x1){
    return __rv_pm2sub_h(x0, x1);
}

/*
**f15:
** pm2sadd.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f15 (int16x2_t x0, int16x2_t x1){
    return __rv_pm2sadd_h(x0, x1);
}

/*
**f16:
** pm2suba.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f16 (int16x2_t x0, int16x2_t x1){
    return __rv_pm2suba_h(x0, x1);
}

/*
**f17:
** pm2sub.hx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f17 (int16x2_t x0, int16x2_t x1){
    return __rv_pm2sub_hx(x0, x1);
}

/*
**f18:
** pm2sadd.hx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f18 (int16x2_t x0, int16x2_t x1){
    return __rv_pm2sadd_hx(x0, x1);
}

/*
**f19:
** pm2suba.hx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f19 (int16x2_t x0, int16x2_t x1){
    return __rv_pm2suba_hx(x0, x1);
}

/*
**f20:
** pm2addsu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x2_t f20 (uint16x2_t x0, uint16x2_t x1){
    return __rv_pm2addsu_h(x0, x1);
}

/*
**f21:
** pm4addsu.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x4_t f21 (uint8x4_t x0, uint8x4_t x1){
    return __rv_pm4addsu_b(x0, x1);
}

/*
**f22:
** pm2addasu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x2_t f22 (uint16x2_t x0, uint16x2_t x1){
    return __rv_pm2addasu_h(x0, x1);
}

/*
**f23:
** pm4addasu.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x4_t f23 (uint8x4_t x0, uint8x4_t x1){
    return __rv_pm4addasu_b(x0, x1);
}

/*
**f24:
** mqacc.h01\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f24 (int16x2_t x0, int16x2_t x1){
    return __rv_mqacc_h01(x0, x1);
}

/*
**f25:
** mqracc.h01\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f25 (int16x2_t x0, int16x2_t x1){
    return __rv_mqracc_h01(x0, x1);
}
