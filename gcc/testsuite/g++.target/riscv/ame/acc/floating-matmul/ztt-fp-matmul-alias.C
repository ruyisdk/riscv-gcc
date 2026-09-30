/* { dg-do assemble } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#define TEST_UDS 0
#include "../../../../../gcc.target/riscv/ame/acc/floating-matmul/ztt-fp-matmul-body.h"
RUN(alias_f16, f16, 2, bf16_rno, i16_rdn, 2)
RUN(alias_bf16, bf16, 2, f32_rup, i16_rdn, 2)
RUN(alias_f32, f32, 1, f16_rtz, u32_rne, 2)
RUN(alias_f64, f64, 1, bf16_rmm, f16_rno, 2)
