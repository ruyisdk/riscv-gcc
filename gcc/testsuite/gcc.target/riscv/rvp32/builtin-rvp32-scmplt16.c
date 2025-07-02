/* This is a test program for scmplt16 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O3" } */
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
**f1:
** scmplt16\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x2_t f1 (int16x2_t x0, int16x2_t x1){

    return __rv_v_scmplt16(x0, x1);

}



