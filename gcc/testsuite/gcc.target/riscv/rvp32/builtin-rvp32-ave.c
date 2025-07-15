/* This is a test program for ave instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** ave\ta[0-9],a[0-9],a[0-9]
** ...
*/

intXLEN_t f0 (intXLEN_t x0, intXLEN_t x1){

    return __rv_ave(x0, x1);

}



