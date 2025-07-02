/* This is a test program for scmple8 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** scmple8\ta[0-9],a[0-9],a[0-9]
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0, uintXLEN_t x1){

    return __rv_scmple8(x0, x1);

}



/*
**f2:
** scmple8\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x8_t f2 (int8x8_t x0, int8x8_t x1){

    return __rv_v_scmple8(x0, x1);

}



