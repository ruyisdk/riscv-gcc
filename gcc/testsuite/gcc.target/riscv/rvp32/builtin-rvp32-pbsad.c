/* This is a test program for pbsad instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** pbsad\ta[0-9],a[0-9],a[0-9]
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0, uintXLEN_t x1){

    return __rv_pbsad(x0, x1);

}



/*
**f1:
** pbsad\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32_t f1 (uint8x4_t x0, uint8x4_t x1){

    return __rv_v_pbsad(x0, x1);

}



