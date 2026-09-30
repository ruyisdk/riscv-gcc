/* multi-UDS.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u64-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u64-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
__riscv_ztt_i8_rnu_1x4_t *half; /* { dg-error "(unknown type name|does not name a type)" } */
__riscv_ztt_i32_rnu_1x1_t *small; /* { dg-error "(unknown type name|does not name a type)" } */
typedef __riscv_ztt_i32_rnu_1x32_t now_available_large;
__riscv_ztt_i64_rnu_1x32_t *large; /* { dg-error "(unknown type name|does not name a type)" } */
#if defined (__riscv_ztt_i8_1x1_irm) || defined (__riscv_ztt_i16_u16_1x1_irm) || defined (__riscv_ztt_i32_u32_1x1_irm)
#error half-register capabilities must be absent
#endif
#if __riscv_ztt_i8_u8_shapes != 2016 || __riscv_ztt_i16_u16_shapes != 2040 || __riscv_ztt_i32_u32_shapes != 2046
#error incorrect shape capabilities
#endif
