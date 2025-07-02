/* This is a test program for clrov instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
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



