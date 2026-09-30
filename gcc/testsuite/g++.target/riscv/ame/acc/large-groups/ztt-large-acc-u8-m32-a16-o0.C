/* Complete ACC storage.  */
/* { dg-do compile } */
/* { dg-options "-O0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#define TEST_UDS 8
#define TEST_M 32
#define TEST_A 16
extern "C" {
#include "../../../../../gcc.target/riscv/ame/acc/large-groups/ztt-large-acc.h"
}
