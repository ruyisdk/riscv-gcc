/* This is a test program for cmpeq8 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** cmpeq8\ta[0-9],a[0-9],a[0-9]
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0, uintXLEN_t x1){

    return __rv_cmpeq8(x0, x1);

}



/*
**f1:
** cmpeq8\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x4_t f1 (int8x4_t x0, int8x4_t x1){

    return __rv_v_scmpeq8(x0, x1);

}



/*
**f2:
** cmpeq8\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x4_t f2 (uint8x4_t x0, uint8x4_t x1){

    return __rv_v_ucmpeq8(x0, x1);

}



