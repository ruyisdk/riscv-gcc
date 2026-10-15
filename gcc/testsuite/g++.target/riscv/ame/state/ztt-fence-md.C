/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -fdump-rtl-ztt_md_reuse -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -fdump-rtl-ztt_md_reuse -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-fence-md.h"
/* { dg-final { scan-rtl-dump "Preserve Md across fence" "ztt_md_reuse" } } */
/* { dg-final { scan-assembler {\tfence\tr,rw} } } */
/* { dg-final { scan-assembler {\tfence\trw,w} } } */
