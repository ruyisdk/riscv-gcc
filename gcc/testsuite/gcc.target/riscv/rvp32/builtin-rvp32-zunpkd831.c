/* This is a test program for zunpkd831 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** zunpkd831\ta[0-9],a[0-9]
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0){

    return __rv_zunpkd831(x0);

}



/*
**f1:
** zunpkd831\ta[0-9],a[0-9]
** ...
*/

uint16x2_t f1 (uint8x4_t x0){

    return __rv_v_zunpkd831(x0);

}



