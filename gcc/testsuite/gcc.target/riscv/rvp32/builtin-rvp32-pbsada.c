/* This is a test program for pbsada instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** pbsada\ta[0-9],a[0-9],a[0-9]
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0, uintXLEN_t x1, uintXLEN_t x2){

    return __rv_pbsada(x0, x1, x2);

}



/*
**f1:
** pbsada\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32_t f1 (uint32_t x0, uint8x4_t x1, uint8x4_t x2){

    return __rv_v_pbsada(x0, x1, x2);

}



