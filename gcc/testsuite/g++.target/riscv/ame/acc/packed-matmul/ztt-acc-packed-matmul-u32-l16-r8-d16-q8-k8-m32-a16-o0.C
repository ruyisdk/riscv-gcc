/* Complete packed matmul.  */
/* { dg-do assemble } */
/* { dg-options "-O0 -fstack-clash-protection -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O0 -fstack-clash-protection -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#define TEST_LHS 16
#define TEST_RHS 8
#define TEST_DEST 16
#define TEST_Q 8
#define TEST_K 8
#include "../../../../../gcc.target/riscv/ame/acc/mixed/ztt-acc-mixed-body.h"
#if __riscv_ztt_acc_matmul_packed != 63
#error packed matmul capability missing
#endif
