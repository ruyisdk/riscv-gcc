/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pnclipi.b\ta[0-9],a[0-9],1
** ...
*/

int32_t f0 (int64_t x0, int32_t x1){
    return __rv_pnclipi_b(x0, 1);
}

/*
**f1:
** pnclipi.h\ta[0-9],a[0-9],1
** ...
*/

int32_t f1 (int64_t x0, int32_t x1){
    return __rv_pnclipi_h(x0, 1);
}

/*
**f2:
** nclipi\ta[0-9],a[0-9],1
** ...
*/

int32_t f2 (int64_t x0, int32_t x1){
    return __rv_nclipi(x0, 1);
}

/*
**f3:
** pnclipri.b\ta[0-9],a[0-9],1
** ...
*/

int32_t f3 (int64_t x0, int32_t x1){
    return __rv_pnclipri_b(x0, 1);
}

/*
**f4:
** pnclipri.h\ta[0-9],a[0-9],1
** ...
*/

int32_t f4 (int64_t x0, int32_t x1){
    return __rv_pnclipri_h(x0, 1);
}

/*
**f5:
** nclipri\ta[0-9],a[0-9],1
** ...
*/

int32_t f5 (int64_t x0, int32_t x1){
    return __rv_nclipri(x0, 1);
}

/*
**f6:
** pnclipru.bs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f6 (int64_t x0, int32_t x1){
    return __rv_pnclipru_bs(x0, x1);
}

/*
**f7:
** pnclipru.hs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f7 (int64_t x0, int32_t x1){
    return __rv_pnclipru_hs(x0, x1);
}

/*
**f8:
** nclipru\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f8 (int64_t x0, int32_t x1){
    return __rv_nclipru(x0, x1);
}

/*
**f9:
** pnclip.bs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f9 (int64_t x0, int32_t x1){
    return __rv_pnclip_bs(x0, x1);
}

/*
**f10:
** pnclip.hs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f10 (int64_t x0, int32_t x1){
    return __rv_pnclip_hs(x0, x1);
}

/*
**f11:
** nclip\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f11 (int64_t x0, int32_t x1){
    return __rv_nclip(x0, x1);
}

/*
**f12:
** pnclipr.bs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f12 (int64_t x0, int32_t x1){
    return __rv_pnclipr_bs(x0, x1);
}

/*
**f13:
** pnclipr.hs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f13 (int64_t x0, int32_t x1){
    return __rv_pnclipr_hs(x0, x1);
}

/*
**f14:
** nclipr\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f14 (int64_t x0, int32_t x1){
    return __rv_nclipr(x0, x1);
}
