/* This is a test program for sunpkd832 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** sunpkd832\ta[0-9],a[0-9]
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0){

    return __rv_sunpkd832(x0);

}



/*
**f1:
** sunpkd832\ta[0-9],a[0-9]
** ...
*/

int16x2_t f1 (int8x4_t x0){

    return __rv_v_sunpkd832(x0);

}



