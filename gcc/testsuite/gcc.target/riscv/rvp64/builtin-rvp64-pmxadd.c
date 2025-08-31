/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pm2add.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f0 (int16x4_t x0, int16x4_t x1){
    return __rv_pm2add_h(x0, x1);
}

/*
**f1:
** pm2add.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f1 (int32x2_t x0, int32x2_t x1){
    return __rv_pm2add_w(x0, x1);
}

/*
**f2:
** pm4add.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x8_t f2 (int8x8_t x0, int8x8_t x1){
    return __rv_pm4add_b(x0, x1);
}

/*
**f3:
** pm4add.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f3 (int16x4_t x0, int16x4_t x1){
    return __rv_pm4add_h(x0, x1);
}

/*
**f4:
** pm2adda.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f4 (int16x4_t x0, int16x4_t x1){
    return __rv_pm2adda_h(x0, x1);
}

/*
**f5:
** pm2adda.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f5 (int32x2_t x0, int32x2_t x1){
    return __rv_pm2adda_w(x0, x1);
}

/*
**f6:
** pm4adda.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x8_t f6 (int8x8_t x0, int8x8_t x1){
    return __rv_pm4adda_b(x0, x1);
}

/*
**f7:
** pm4adda.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f7 (int16x4_t x0, int16x4_t x1){
    return __rv_pm4adda_h(x0, x1);
}

/*
**f8:
** pm2add.hx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f8 (int16x4_t x0, int16x4_t x1){
    return __rv_pm2add_hx(x0, x1);
}

/*
**f9:
** pm2add.wx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f9 (int32x2_t x0, int32x2_t x1){
    return __rv_pm2add_wx(x0, x1);
}

/*
**f10:
** pm2adda.hx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f10 (int16x4_t x0, int16x4_t x1){
    return __rv_pm2adda_hx(x0, x1);
}

/*
**f11:
** pm2add.wx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f11 (int32x2_t x0, int32x2_t x1){
    return __rv_pm2adda_wx(x0, x1);
}

/*
**f12:
** pm2addu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x4_t f12 (uint16x4_t x0, uint16x4_t x1){
    return __rv_pm2addu_h(x0, x1);
}

/*
**f13:
** pm2addu.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32x2_t f13 (uint32x2_t x0, uint32x2_t x1){
    return __rv_pm2addu_w(x0, x1);
}

/*
**f14:
** pm4addu.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x8_t f14 (uint8x8_t x0, uint8x8_t x1){
    return __rv_pm4addu_b(x0, x1);
}

/*
**f15:
** pm4addu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x4_t f15 (uint16x4_t x0, uint16x4_t x1){
    return __rv_pm4addu_h(x0, x1);
}

/*
**f16:
** pm2addau.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x4_t f16 (uint16x4_t x0, uint16x4_t x1){
    return __rv_pm2addau_h(x0, x1);
}

/*
**f17:
** pm2addau.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32x2_t f17 (uint32x2_t x0, uint32x2_t x1){
    return __rv_pm2addau_w(x0, x1);
}

/*
**f18:
** pm4addau.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x8_t f18 (uint8x8_t x0, uint8x8_t x1){
    return __rv_pm4addau_b(x0, x1);
}

/*
**f19:
** pm4addau.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x4_t f19 (uint16x4_t x0, uint16x4_t x1){
    return __rv_pm4addau_h(x0, x1);
}

/*
**f20:
** pmq2add.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f20 (int16x4_t x0, int16x4_t x1){
    return __rv_pmq2add_h(x0, x1);
}

/*
**f21:
** pmq2add.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f21 (int32x2_t x0, int32x2_t x1){
    return __rv_pmq2add_w(x0, x1);
}

/*
**f22:
** pmqr2add.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f22 (int16x4_t x0, int16x4_t x1){
    return __rv_pmqr2add_h(x0, x1);
}

/*
**f23:
** pmqr2add.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f23 (int32x2_t x0, int32x2_t x1){
    return __rv_pmqr2add_w(x0, x1);
}

/*
**f24:
** pmq2adda.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f24 (int16x4_t x0, int16x4_t x1){
    return __rv_pmq2adda_h(x0, x1);
}

/*
**f25:
** pmq2adda.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f25 (int32x2_t x0, int32x2_t x1){
    return __rv_pmq2adda_w(x0, x1);
}

/*
**f26:
** pmqr2adda.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f26 (int16x4_t x0, int16x4_t x1){
    return __rv_pmqr2adda_h(x0, x1);
}

/*
**f27:
** pmqr2adda.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f27 (int32x2_t x0, int32x2_t x1){
    return __rv_pmqr2adda_w(x0, x1);
}

/*
**f28:
** pm2sub.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f28 (int16x4_t x0, int16x4_t x1){
    return __rv_pm2sub_h(x0, x1);
}

/*
**f29:
** pm2sub.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f29 (int32x2_t x0, int32x2_t x1){
    return __rv_pm2sub_w(x0, x1);
}

/*
**f30:
** pmq2sadd.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f30 (int16x4_t x0, int16x4_t x1){
    return __rv_pmq2sadd_h(x0, x1);
}

/*
**f31:
** pm2suba.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f31 (int16x4_t x0, int16x4_t x1){
    return __rv_pm2suba_h(x0, x1);
}

/*
**f32:
** pm2suba.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f32 (int32x2_t x0, int32x2_t x1){
    return __rv_pm2suba_w(x0, x1);
}

/*
**f33:
** pm2sub.hx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f33 (int16x4_t x0, int16x4_t x1){
    return __rv_pm2sub_hx(x0, x1);
}

/*
**f34:
** pm2sub.wx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f34 (int32x2_t x0, int32x2_t x1){
    return __rv_pm2sub_wx(x0, x1);
}

/*
**f35:
** pm2sadd.hx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f35 (int16x4_t x0, int16x4_t x1){
    return __rv_pm2sadd_hx(x0, x1);
}

/*
**f36:
** pm2suba.hx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f36 (int16x4_t x0, int16x4_t x1){
    return __rv_pm2suba_hx(x0, x1);
}

/*
**f37:
** pm2suba.wx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f37 (int32x2_t x0, int32x2_t x1){
    return __rv_pm2suba_wx(x0, x1);
}

/*
**f38:
** pm2addsu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x4_t f38 (uint16x4_t x0, uint16x4_t x1){
    return __rv_pm2addsu_h(x0, x1);
}

/*
**f39:
** pm2addsu.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32x2_t f39 (uint32x2_t x0, uint32x2_t x1){
    return __rv_pm2addsu_w(x0, x1);
}

/*
**f40:
** pm4addsu.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x8_t f40 (uint8x8_t x0, uint8x8_t x1){
    return __rv_pm4addsu_b(x0, x1);
}

/*
**f41:
** pm4addsu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x4_t f41 (uint16x4_t x0, uint16x4_t x1){
    return __rv_pm4addsu_h(x0, x1);
}

/*
**f42:
** pm2addsu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x4_t f42 (uint16x4_t x0, uint16x4_t x1){
    return __rv_pm2addsu_h(x0, x1);
}

/*
**f43:
** pm2addasu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x4_t f43 (uint16x4_t x0, uint16x4_t x1){
    return __rv_pm2addasu_h(x0, x1);
}

/*
**f44:
** pm2addasu.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32x2_t f44 (uint32x2_t x0, uint32x2_t x1){
    return __rv_pm2addasu_w(x0, x1);
}

/*
**f45:
** pm4addasu.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x8_t f45 (uint8x8_t x0, uint8x8_t x1){
    return __rv_pm4addasu_b(x0, x1);
}

/*
**f46:
** pm4addasu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x4_t f46 (uint16x4_t x0, uint16x4_t x1){
    return __rv_pm4addasu_h(x0, x1);
}

/*
**f47:
** pmqacc.w.h01\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f47 (int32x2_t x0, int32x2_t x1){
    return __rv_pmqacc_w_h01(x0, x1);
}

/*
**f48:
** pmqracc.w.h01\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f48 (int32x2_t x0, int32x2_t x1){
    return __rv_pmqracc_w_h01(x0, x1);
}

/*
**f49:
** mqacc.h01\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f49 (int16x4_t x0, int16x4_t x1){
    return __rv_mqacc_h01(x0, x1);
}

/*
**f50:
** mqacc.w01\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f50 (int32x2_t x0, int32x2_t x1){
    return __rv_mqacc_w01(x0, x1);
}

/*
**f51:
** mqracc.h01\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f51 (int16x4_t x0, int16x4_t x1){
    return __rv_mqracc_h01(x0, x1);
}

/*
**f52:
** mqracc.w01\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f52 (int32x2_t x0, int32x2_t x1){
    return __rv_mqracc_w01(x0, x1);
}

