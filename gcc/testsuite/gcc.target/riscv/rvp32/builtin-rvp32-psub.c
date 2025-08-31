/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** psub.b\ta[0-9],a[0-9],[0-9]
** ...
*/

int8x4_t f0 (int8x4_t x0, int8x4_t x1){
    return __rv_psub_b(x0, x1);
}

/*
**f1:
** psub.h\ta[0-9],a[0-9],[0-9]
** ...
*/

int16x2_t f1 (int16x2_t x0, int16x2_t x1){
    return __rv_psub_h(x0, x1);
}

/*
**f2:
** ssub\ta[0-9],a[0-9],[0-9]
** ...
*/

int32_t f2 (int32_t x0, int32_t x1){
    return __rv_ssub(x0, x1);
}

/*
**f3:
** pssub.b\ta[0-9],a[0-9],[0-9]
** ...
*/

int8x4_t f3 (int8x4_t x0, int8x4_t x1){
    return __rv_pssub_b(x0, x1);
}

/*
**f4:
** pssub.h\ta[0-9],a[0-9],[0-9]
** ...
*/

int16x2_t f4 (int16x2_t x0, int16x2_t x1){
    return __rv_pssub_h(x0, x1);
}

/*
**f5:
** asub\ta[0-9],a[0-9],[0-9]
** ...
*/

int32_t f5 (int32_t x0, int32_t x1){
    return __rv_asub(x0, x1);
}

/*
**f6:
** ssubu\ta[0-9],a[0-9],[0-9]
** ...
*/

uint32_t f6 (uint32_t x0, uint32_t x1){
    return __rv_ssubu(x0, x1);
}

/*
**f7:
** pssubu.b\ta[0-9],a[0-9],[0-9]
** ...
*/

uint8x4_t f7 (uint8x4_t x0, uint8x4_t x1){
    return __rv_pssubu_b(x0, x1);
}

/*
**f8:
** pssubu.h\ta[0-9],a[0-9],[0-9]
** ...
*/

uint16x2_t f8 (uint16x2_t x0, uint16x2_t x1){
    return __rv_pssubu_h(x0, x1);
}

/*
**f9:
** asubu\ta[0-9],a[0-9],[0-9]
** ...
*/

uint32_t f9 (uint32_t x0, uint32_t x1){
    return __rv_asubu(x0, x1);
}

/*
**f10:
** pasubu.b\ta[0-9],a[0-9],[0-9]
** ...
*/

uint8x4_t f10 (uint8x4_t x0, uint8x4_t x1){
    return __rv_pasubu_b(x0, x1);
}

/*
**f11:
** pasubu.h\ta[0-9],a[0-9],[0-9]
** ...
*/

uint16x2_t f11 (uint16x2_t x0, uint16x2_t x1){
    return __rv_pasubu_h(x0, x1);
}
