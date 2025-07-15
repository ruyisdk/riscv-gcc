/* This is a test program for clz8 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** clz8\ta[0-9],a[0-9]
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0){

    return __rv_clz8(x0);

}



/*
**f2:
** clz8\ta[0-9],a[0-9]
** ...
*/

uint8x8_t f2 (uint8x8_t x0){

    return __rv_v_clz8(x0);

}



