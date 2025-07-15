/* This is a test program for scmplt16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** scmplt16\ta[0-9],a[0-9],a[0-9]
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0, uintXLEN_t x1){

    return __rv_scmplt16(x0, x1);

}



/*
**f2:
** scmplt16\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x4_t f2 (int16x4_t x0, int16x4_t x1){

    return __rv_v_scmplt16(x0, x1);

}



