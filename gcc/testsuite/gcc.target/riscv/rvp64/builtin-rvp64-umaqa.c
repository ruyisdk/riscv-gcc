/* This is a test program for umaqa instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** umaqa\ta[0-9],a[0-9],a[0-9]
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0, uintXLEN_t x1, uintXLEN_t x2){

    return __rv_umaqa(x0, x1, x2);

}



/*
**f2:
** umaqa\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32x2_t f2 (uint32x2_t x0, uint8x8_t x1, uint8x8_t x2){

    return __rv_v_umaqa(x0, x1, x2);

}



