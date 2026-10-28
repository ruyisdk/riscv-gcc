/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define MR_LEFT i32_rne
#define MR_RIGHT i32_rdn
#define MR_DEST i32_rnu
#define MR_LE __INT32_TYPE__
#define MR_RE __INT32_TYPE__
#define MR_DE __INT32_TYPE__
#include "../../../../gcc.target/riscv/ame/state/ztt-reload-matmul.h"
/* { dg-final { scan-rtl-dump "Prepare Md before matmul reload .*source 0" "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump "Prepare Md before matmul reload .*source 1" "ztt_md_reuse" } } */
/* { dg-final { scan-assembler {\tmmulacc\.2d\t} } } */
