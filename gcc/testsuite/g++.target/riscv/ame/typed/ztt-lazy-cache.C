/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#define ZTT_LAZY_NAME lazy_first
#include "../../../../gcc.target/riscv/ame/typed/ztt-lazy-cache-body.h"
#undef ZTT_LAZY_NAME
namespace later_scope {
#define ZTT_LAZY_NAME lazy_again
#include "../../../../gcc.target/riscv/ame/typed/ztt-lazy-cache-body.h"
}
/* { dg-final { scan-assembler-times {\tmconv\.ew\t} 32 } } */
/* { dg-final { scan-assembler-times {\tmmul\.ew\t} 32 } } */
/* { dg-final { scan-assembler-times {\tmmulacc\.2d\t} 64 } } */
/* { dg-final { scan-assembler-not {call\s+__builtin_riscv_ztt} } } */
