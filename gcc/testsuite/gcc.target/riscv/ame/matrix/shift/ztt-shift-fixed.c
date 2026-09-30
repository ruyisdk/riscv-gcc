/* fixed P0 remains supported.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */
#include "ztt-shift-body.h"
ZTT_SHIFT_M (fixed_matrix, msll_ew, uint8_t, int32_t, uint16_t, u8_rnu, i32_rne, u16_rod, 1x1)
ZTT_SHIFT_X (fixed_scalar, msra_ew_x, uint8_t, int32_t, u8_rnu, i32_rdn, 1x1)
/* { dg-final { scan-assembler-times {\tmsll\.ew\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmsra\.ew\.x\t} 1 } } */
/* { dg-final { scan-assembler-not {amestype} } } */
