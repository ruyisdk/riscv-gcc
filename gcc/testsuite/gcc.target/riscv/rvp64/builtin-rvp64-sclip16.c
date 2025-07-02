/* This is a test program for sclip16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** sclip16\ta[0-9],a[0-9],1
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0, uint32_t x1){

    return __rv_sclip16(x0, 1);

}



/*
**f2:
** sclip16\ta[0-9],a[0-9],1
** ...
*/

int16x4_t f2 (int16x4_t x0, uint32_t x1){

    return __rv_v_sclip16(x0, 1);

}



