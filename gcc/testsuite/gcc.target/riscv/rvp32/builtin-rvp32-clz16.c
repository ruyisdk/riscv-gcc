/* This is a test program for clz16 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** clz16\ta[0-9],a[0-9]
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0){

    return __rv_clz16(x0);

}



/*
**f1:
** clz16\ta[0-9],a[0-9]
** ...
*/

uint16x2_t f1 (uint16x2_t x0){

    return __rv_v_clz16(x0);

}



