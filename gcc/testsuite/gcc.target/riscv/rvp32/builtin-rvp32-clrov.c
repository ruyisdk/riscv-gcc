/* This is a test program for clrov instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** csrrci	zero,vxsat,1
** ...
*/

void f0 (){

    return __rv_clrov();

}



