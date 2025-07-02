/* This is a test program for add8 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
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
**f3:
** add8\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x8_t f3 (uint8x8_t x0, uint8x8_t x1){

    return __rv_v_uadd8(x0, x1);

}



/*
**f4:
** add8\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x8_t f4 (int8x8_t x0, int8x8_t x1){

    return __rv_v_sadd8(x0, x1);

}



