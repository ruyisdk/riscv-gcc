/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_state -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/indexed/ztt-gather-index-reuse.h"
/* { dg-final { scan-rtl-dump-times {UNSPECV_ZTT_STATE_GATHER_REUSE_BOTH} 3 "ztt_state" } } */
/* { dg-final { scan-assembler-times {mcolgather\.ew} 7 } } */
/* { dg-final { scan-assembler-times {mrowgather\.ew} 4 } } */
/* { dg-final { scan-assembler {mcolgather\.ew\s+m([0-9]+),m[0-9]+,m\1} } } */
