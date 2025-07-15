/* This is a test program for clz32 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** clz32\ta[0-9],a[0-9]
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0){

    return __rv_clz32(x0);

}



