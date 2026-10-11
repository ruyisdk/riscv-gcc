/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -fdisable-rtl-ztt_md_reuse -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -fdisable-rtl-ztt_md_reuse -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */
/* { dg-prune-output "disable pass rtl-ztt_md_reuse" } */
#include "ztt-convert-body.h"
/* { dg-final { scan-assembler-times {\tmconv\.ew\t} 11 } } */
