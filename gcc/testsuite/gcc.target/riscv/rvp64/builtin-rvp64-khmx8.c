/* This is a test program for khmx8 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** khmx8\ta[0-9],a[0-9],a[0-9]
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0, uintXLEN_t x1){

    return __rv_khmx8(x0, x1);

}



/*
**f2:
** khmx8\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x8_t f2 (int8x8_t x0, int8x8_t x1){

    return __rv_v_khmx8(x0, x1);

}



