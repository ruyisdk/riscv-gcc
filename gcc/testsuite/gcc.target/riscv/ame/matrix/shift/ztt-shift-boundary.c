/* shifts.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>
void msll_0 (uint32_t *out, const int8_t *in)
{
  __riscv_ztt_i8_1x4_t a = __riscv_ztt_mls_rm_i8_1x4 (in);
  __riscv_ztt_u32_1x4_t d = __riscv_ztt_msll_ew_x_u32_1x4 (a, 0);
  __riscv_ztt_mss_rm (out, d);
}
void msrl_0 (uint32_t *out, const int8_t *in)
{
  __riscv_ztt_i8_1x4_t a = __riscv_ztt_mls_rm_i8_1x4 (in);
  __riscv_ztt_u32_1x4_t d = __riscv_ztt_msrl_ew_x_u32_1x4 (a, 0);
  __riscv_ztt_mss_rm (out, d);
}
void msra_0 (uint32_t *out, const int8_t *in)
{
  __riscv_ztt_i8_1x4_t a = __riscv_ztt_mls_rm_i8_1x4 (in);
  __riscv_ztt_u32_1x4_t d = __riscv_ztt_msra_ew_x_u32_1x4 (a, 0);
  __riscv_ztt_mss_rm (out, d);
}
void msll_1 (uint32_t *out, const int8_t *in)
{
  __riscv_ztt_i8_1x4_t a = __riscv_ztt_mls_rm_i8_1x4 (in);
  __riscv_ztt_u32_1x4_t d = __riscv_ztt_msll_ew_x_u32_1x4 (a, 7);
  __riscv_ztt_mss_rm (out, d);
}
void msrl_1 (uint32_t *out, const int8_t *in)
{
  __riscv_ztt_i8_1x4_t a = __riscv_ztt_mls_rm_i8_1x4 (in);
  __riscv_ztt_u32_1x4_t d = __riscv_ztt_msrl_ew_x_u32_1x4 (a, 7);
  __riscv_ztt_mss_rm (out, d);
}
void msra_1 (uint32_t *out, const int8_t *in)
{
  __riscv_ztt_i8_1x4_t a = __riscv_ztt_mls_rm_i8_1x4 (in);
  __riscv_ztt_u32_1x4_t d = __riscv_ztt_msra_ew_x_u32_1x4 (a, 7);
  __riscv_ztt_mss_rm (out, d);
}
void msll_2 (uint32_t *out, const int8_t *in)
{
  __riscv_ztt_i8_1x4_t a = __riscv_ztt_mls_rm_i8_1x4 (in);
  __riscv_ztt_u32_1x4_t d = __riscv_ztt_msll_ew_x_u32_1x4 (a, 8);
  __riscv_ztt_mss_rm (out, d);
}
void msrl_2 (uint32_t *out, const int8_t *in)
{
  __riscv_ztt_i8_1x4_t a = __riscv_ztt_mls_rm_i8_1x4 (in);
  __riscv_ztt_u32_1x4_t d = __riscv_ztt_msrl_ew_x_u32_1x4 (a, 8);
  __riscv_ztt_mss_rm (out, d);
}
void msra_2 (uint32_t *out, const int8_t *in)
{
  __riscv_ztt_i8_1x4_t a = __riscv_ztt_mls_rm_i8_1x4 (in);
  __riscv_ztt_u32_1x4_t d = __riscv_ztt_msra_ew_x_u32_1x4 (a, 8);
  __riscv_ztt_mss_rm (out, d);
}
void msll_3 (uint32_t *out, const int8_t *in)
{
  __riscv_ztt_i8_1x4_t a = __riscv_ztt_mls_rm_i8_1x4 (in);
  __riscv_ztt_u32_1x4_t d = __riscv_ztt_msll_ew_x_u32_1x4 (a, 9);
  __riscv_ztt_mss_rm (out, d);
}
void msrl_3 (uint32_t *out, const int8_t *in)
{
  __riscv_ztt_i8_1x4_t a = __riscv_ztt_mls_rm_i8_1x4 (in);
  __riscv_ztt_u32_1x4_t d = __riscv_ztt_msrl_ew_x_u32_1x4 (a, 9);
  __riscv_ztt_mss_rm (out, d);
}
void msra_3 (uint32_t *out, const int8_t *in)
{
  __riscv_ztt_i8_1x4_t a = __riscv_ztt_mls_rm_i8_1x4 (in);
  __riscv_ztt_u32_1x4_t d = __riscv_ztt_msra_ew_x_u32_1x4 (a, 9);
  __riscv_ztt_mss_rm (out, d);
}
void msll_4 (uint32_t *out, const int8_t *in)
{
  __riscv_ztt_i8_1x4_t a = __riscv_ztt_mls_rm_i8_1x4 (in);
  __riscv_ztt_u32_1x4_t d = __riscv_ztt_msll_ew_x_u32_1x4 (a, (size_t)-1);
  __riscv_ztt_mss_rm (out, d);
}
void msrl_4 (uint32_t *out, const int8_t *in)
{
  __riscv_ztt_i8_1x4_t a = __riscv_ztt_mls_rm_i8_1x4 (in);
  __riscv_ztt_u32_1x4_t d = __riscv_ztt_msrl_ew_x_u32_1x4 (a, (size_t)-1);
  __riscv_ztt_mss_rm (out, d);
}
void msra_4 (uint32_t *out, const int8_t *in)
{
  __riscv_ztt_i8_1x4_t a = __riscv_ztt_mls_rm_i8_1x4 (in);
  __riscv_ztt_u32_1x4_t d = __riscv_ztt_msra_ew_x_u32_1x4 (a, (size_t)-1);
  __riscv_ztt_mss_rm (out, d);
}
/* { dg-final { scan-assembler-times {\tmsll\.ew\.x\t} 5 } } */
/* { dg-final { scan-assembler-times {\tmsrl\.ew\.x\t} 5 } } */
/* { dg-final { scan-assembler-times {\tmsra\.ew\.x\t} 5 } } */
/* { dg-final { scan-assembler-not {amestype} } } */
