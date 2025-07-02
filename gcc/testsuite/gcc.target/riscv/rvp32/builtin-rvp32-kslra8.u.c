/* This is a test program for kslra8.u instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** kslra8.u\ta[0-9],a[0-9],a[0-9]
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0, int32_t x1){

    return __rv_kslra8_u(x0, x1);

}



/*
**f1:
** kslra8.u\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x4_t f1 (int8x4_t x0, int32_t x1){

    return __rv_v_kslra8_u(x0, x1);

}



