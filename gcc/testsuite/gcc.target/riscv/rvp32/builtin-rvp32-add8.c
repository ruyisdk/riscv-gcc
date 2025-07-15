/* This is a test program for add8 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** add8\ta[0-9],a[0-9],a[0-9]
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0, uintXLEN_t x1){

    return __rv_add8(x0, x1);

}



/*
**f1:
** add8\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x4_t f1 (uint8x4_t x0, uint8x4_t x1){

    return __rv_v_uadd8(x0, x1);

}



/*
**f2:
** add8\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x4_t f2 (int8x4_t x0, int8x4_t x1){

    return __rv_v_sadd8(x0, x1);

}



