/* This is a test program for sunpkd831 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** sunpkd831\ta[0-9],a[0-9]
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0){

    return __rv_sunpkd831(x0);

}



/*
**f2:
** sunpkd831\ta[0-9],a[0-9]
** ...
*/

int16x4_t f2 (int8x8_t x0){

    return __rv_v_sunpkd831(x0);

}



