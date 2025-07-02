/* This is a test program for rdov instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** csrr\ta0, vxsat, zero
** ...
*/

uintXLEN_t f0 (){

    return __rv_rdov();

}



