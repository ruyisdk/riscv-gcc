/* This is a test program for smin8 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** smin8\ta[0-9],a[0-9],a[0-9]
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0, uintXLEN_t x1){

    return __rv_smin8(x0, x1);

}



/*
**f1:
** smin8\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x4_t f1 (int8x4_t x0, int8x4_t x1){

    return __rv_v_smin8(x0, x1);

}



