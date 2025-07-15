/* This is a test program for ucmplt8 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** ucmplt8\ta[0-9],a[0-9],a[0-9]
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0, uintXLEN_t x1){

    return __rv_ucmplt8(x0, x1);

}



/*
**f2:
** ucmplt8\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x8_t f2 (uint8x8_t x0, uint8x8_t x1){

    return __rv_v_ucmplt8(x0, x1);

}



