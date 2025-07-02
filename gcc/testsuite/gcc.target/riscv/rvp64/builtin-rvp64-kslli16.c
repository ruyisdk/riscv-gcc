/* This is a test program for kslli16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** kslli16\ta[0-9],a[0-9],1
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0, uint32_t x1){

    return __rv_kslli16(x0, 1);

}



/*
**f2:
** kslli16\ta[0-9],a[0-9],1
** ...
*/

int16x4_t f2 (int16x4_t x0, uint32_t x1){

    return __rv_v_kslli16(x0, 1);

}



/*
**f4:
** kslli16\ta[0-9],a[0-9],1
** ...
*/

int16x4_t f4 (int16x4_t x0, uint32_t x1){

    return __rv_v_kslli16(x0, 1);

}



