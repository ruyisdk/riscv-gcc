/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a16 " { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a16 " { target rv64 } } */
#include <riscv_ztt.h>
#include <stdint.h>
#define MEMORY(D, C, Q) \
void mem_##D (C *p, const C *q, __SIZE_TYPE__ stride) \
{ \
  __riscv_ztt_##D##_1x##Q##_t v = __riscv_ztt_mls_rm_##D##_1x##Q (q); \
  __riscv_ztt_mss_rm (p, v); \
  v = __riscv_ztt_mls_cm_##D##_1x##Q (q); \
  __riscv_ztt_mss_cm (p, v); \
  v = __riscv_ztt_mls_st_##D##_1x##Q (q, stride); \
  __riscv_ztt_mss_st (p, stride, v); \
  v = __riscv_ztt_mls_tst_##D##_1x##Q (q, stride); \
  __riscv_ztt_mss_tst (p, stride, v); \
}
MEMORY(i8_rne_sat, int8_t, 4)
MEMORY(u16_rdn_sat, uint16_t, 2)
MEMORY(i32_rod_sat, int32_t, 1)
MEMORY(u64_rnu_sat, uint64_t, 1)
/* { dg-final { scan-assembler "mls\\.tst" } } */
/* { dg-final { scan-assembler "mss\\.st" } } */
