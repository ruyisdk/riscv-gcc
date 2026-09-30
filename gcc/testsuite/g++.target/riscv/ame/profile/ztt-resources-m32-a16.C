/* runtime-N resource profiles.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#define EXPECT_M 32
#define EXPECT_ACC 16
#include "../../../../gcc.target/riscv/ame/profile/ztt-resources-body.h"
/* { dg-final { scan-assembler "csrr\ts11,amenlen" } } */
/* { dg-final { scan-assembler {\tmss\.1r\t} } } */
