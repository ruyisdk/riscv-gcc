/* unsigned logical data.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include "ztt-shift-body.h"
ZTT_SHIFT_M (unsigned_left, msll_ew, int32_t, uint8_t, int16_t, i32_rne, u8_rdn, i16_rod, 1x4)
ZTT_SHIFT_M (unsigned_right, msrl_ew, int32_t, uint8_t, int16_t, i32_rne, u8_rdn, i16_rod, 1x4)
ZTT_SHIFT_X (unsigned_scalar_left, msll_ew_x, int32_t, uint8_t, i32_rne, u8_rdn, 1x4)
ZTT_SHIFT_X (unsigned_scalar_right, msrl_ew_x, int32_t, uint8_t, i32_rne, u8_rdn, 1x4)
/* { dg-final { scan-assembler-times {\tmsll\.ew\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmsrl\.ew\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmsll\.ew\.x\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmsrl\.ew\.x\t} 1 } } */
