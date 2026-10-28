/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_md_reuse -march=rv32ima_zicsr_zbc_zknh_zksh_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_md_reuse -march=rv64ima_zicsr_zbc_zknh_zksh_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-spill-hash-tail.h"
/* { dg-final { scan-rtl-dump-times {Drop dead private spill} 48 "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump-times {Drop interleaved raw reload} 60 "ztt_md_reuse" { target rv32 } } } */
/* { dg-final { scan-rtl-dump-times {Drop interleaved raw reload} 61 "ztt_md_reuse" { target rv64 } } } */
/* { dg-final { scan-assembler-times {\tclmulh\t} 1 } } */
/* { dg-final { scan-assembler-times {\tsha256sig0\t} 3 } } */
/* { dg-final { scan-assembler-times {\tmrowscatadd\.ew\t} 8 } } */
