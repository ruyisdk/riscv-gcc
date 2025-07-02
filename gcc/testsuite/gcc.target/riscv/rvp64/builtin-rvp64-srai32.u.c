/* This is a test program for srai32.u instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** srai32.u\ta[0-9],a[0-9],1
** ...
*/

int64_t f0 (int64_t x0, uint32_t x1){

    return __rv_sra32_u(x0, 1);

}



/*
**f1:
** srai32.u\ta[0-9],a[0-9],1
** ...
*/

int32x2_t f1 (int32x2_t x0, uint32_t x1){

    return __rv_v_sra32_u(x0, 1);

}



/*
**f2:
** srai32.u\ta[0-9],a[0-9],1
** ...
*/

int32x2_t f2 (int32x2_t x0, uint32_t x1){

    return __rv_v_sra32_u(x0, 1);

}



