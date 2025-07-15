/* This is a test program for cmix instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn_zbpbo -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** cmix\ta[0-9],a[0-9],a[0-9],a[0-9]
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0, uintXLEN_t x1, uintXLEN_t x2){

    return __rv_cmix(x0, x1, x2);

}



