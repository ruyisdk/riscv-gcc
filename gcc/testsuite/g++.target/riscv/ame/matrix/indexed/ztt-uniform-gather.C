/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/indexed/ztt-uniform-gather.h"
/* { dg-final { scan-assembler-times {mrowgather\.ew} 3 } } */
/* { dg-final { scan-assembler-times {mcolgather\.ew} 2 } } */
/* { dg-final { scan-assembler-times {mls\.rm} 13 } } */
/* { dg-final { scan-rtl-dump "Reuse load descriptor" "ztt_md_reuse" } } */
