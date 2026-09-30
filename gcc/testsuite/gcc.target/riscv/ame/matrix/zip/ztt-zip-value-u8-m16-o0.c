/* { dg-do assemble } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv32 } } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>
void mcolzip_ew_i8_rnu_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rnu_1x2_t a = __riscv_ztt_mls_rm_i8_rnu_1x2 (in);
  __riscv_ztt_i8_rnu_1x2_t b = __riscv_ztt_mcolzip_ew_i8_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i8_rnu_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rnu_1x2_t a = __riscv_ztt_mls_rm_i8_rnu_1x2 (in);
  __riscv_ztt_i8_rnu_1x2_t b = __riscv_ztt_mrowzip_ew_i8_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i8_rnu_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rnu_1x2_t a = __riscv_ztt_mls_rm_i8_rnu_1x2 (in);
  __riscv_ztt_i8_rnu_1x2_t b = __riscv_ztt_mcolunzip_ew_i8_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i8_rnu_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rnu_1x2_t a = __riscv_ztt_mls_rm_i8_rnu_1x2 (in);
  __riscv_ztt_i8_rnu_1x2_t b = __riscv_ztt_mrowunzip_ew_i8_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i8_rnu_sat_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_i8_rnu_sat_1x2 (in);
  __riscv_ztt_i8_rnu_sat_1x2_t b = __riscv_ztt_mcolzip_ew_i8_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i8_rnu_sat_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_i8_rnu_sat_1x2 (in);
  __riscv_ztt_i8_rnu_sat_1x2_t b = __riscv_ztt_mrowzip_ew_i8_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i8_rnu_sat_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_i8_rnu_sat_1x2 (in);
  __riscv_ztt_i8_rnu_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_i8_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i8_rnu_sat_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_i8_rnu_sat_1x2 (in);
  __riscv_ztt_i8_rnu_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_i8_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i8_rne_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rne_1x2_t a = __riscv_ztt_mls_rm_i8_rne_1x2 (in);
  __riscv_ztt_i8_rne_1x2_t b = __riscv_ztt_mcolzip_ew_i8_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i8_rne_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rne_1x2_t a = __riscv_ztt_mls_rm_i8_rne_1x2 (in);
  __riscv_ztt_i8_rne_1x2_t b = __riscv_ztt_mrowzip_ew_i8_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i8_rne_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rne_1x2_t a = __riscv_ztt_mls_rm_i8_rne_1x2 (in);
  __riscv_ztt_i8_rne_1x2_t b = __riscv_ztt_mcolunzip_ew_i8_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i8_rne_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rne_1x2_t a = __riscv_ztt_mls_rm_i8_rne_1x2 (in);
  __riscv_ztt_i8_rne_1x2_t b = __riscv_ztt_mrowunzip_ew_i8_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i8_rne_sat_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rne_sat_1x2_t a = __riscv_ztt_mls_rm_i8_rne_sat_1x2 (in);
  __riscv_ztt_i8_rne_sat_1x2_t b = __riscv_ztt_mcolzip_ew_i8_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i8_rne_sat_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rne_sat_1x2_t a = __riscv_ztt_mls_rm_i8_rne_sat_1x2 (in);
  __riscv_ztt_i8_rne_sat_1x2_t b = __riscv_ztt_mrowzip_ew_i8_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i8_rne_sat_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rne_sat_1x2_t a = __riscv_ztt_mls_rm_i8_rne_sat_1x2 (in);
  __riscv_ztt_i8_rne_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_i8_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i8_rne_sat_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rne_sat_1x2_t a = __riscv_ztt_mls_rm_i8_rne_sat_1x2 (in);
  __riscv_ztt_i8_rne_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_i8_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i8_rdn_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rdn_1x2_t a = __riscv_ztt_mls_rm_i8_rdn_1x2 (in);
  __riscv_ztt_i8_rdn_1x2_t b = __riscv_ztt_mcolzip_ew_i8_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i8_rdn_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rdn_1x2_t a = __riscv_ztt_mls_rm_i8_rdn_1x2 (in);
  __riscv_ztt_i8_rdn_1x2_t b = __riscv_ztt_mrowzip_ew_i8_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i8_rdn_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rdn_1x2_t a = __riscv_ztt_mls_rm_i8_rdn_1x2 (in);
  __riscv_ztt_i8_rdn_1x2_t b = __riscv_ztt_mcolunzip_ew_i8_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i8_rdn_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rdn_1x2_t a = __riscv_ztt_mls_rm_i8_rdn_1x2 (in);
  __riscv_ztt_i8_rdn_1x2_t b = __riscv_ztt_mrowunzip_ew_i8_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i8_rdn_sat_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_i8_rdn_sat_1x2 (in);
  __riscv_ztt_i8_rdn_sat_1x2_t b = __riscv_ztt_mcolzip_ew_i8_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i8_rdn_sat_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_i8_rdn_sat_1x2 (in);
  __riscv_ztt_i8_rdn_sat_1x2_t b = __riscv_ztt_mrowzip_ew_i8_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i8_rdn_sat_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_i8_rdn_sat_1x2 (in);
  __riscv_ztt_i8_rdn_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_i8_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i8_rdn_sat_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_i8_rdn_sat_1x2 (in);
  __riscv_ztt_i8_rdn_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_i8_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i8_rod_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rod_1x2_t a = __riscv_ztt_mls_rm_i8_rod_1x2 (in);
  __riscv_ztt_i8_rod_1x2_t b = __riscv_ztt_mcolzip_ew_i8_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i8_rod_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rod_1x2_t a = __riscv_ztt_mls_rm_i8_rod_1x2 (in);
  __riscv_ztt_i8_rod_1x2_t b = __riscv_ztt_mrowzip_ew_i8_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i8_rod_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rod_1x2_t a = __riscv_ztt_mls_rm_i8_rod_1x2 (in);
  __riscv_ztt_i8_rod_1x2_t b = __riscv_ztt_mcolunzip_ew_i8_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i8_rod_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rod_1x2_t a = __riscv_ztt_mls_rm_i8_rod_1x2 (in);
  __riscv_ztt_i8_rod_1x2_t b = __riscv_ztt_mrowunzip_ew_i8_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i8_rod_sat_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rod_sat_1x2_t a = __riscv_ztt_mls_rm_i8_rod_sat_1x2 (in);
  __riscv_ztt_i8_rod_sat_1x2_t b = __riscv_ztt_mcolzip_ew_i8_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i8_rod_sat_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rod_sat_1x2_t a = __riscv_ztt_mls_rm_i8_rod_sat_1x2 (in);
  __riscv_ztt_i8_rod_sat_1x2_t b = __riscv_ztt_mrowzip_ew_i8_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i8_rod_sat_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rod_sat_1x2_t a = __riscv_ztt_mls_rm_i8_rod_sat_1x2 (in);
  __riscv_ztt_i8_rod_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_i8_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i8_rod_sat_live (int8_t *out, const int8_t *in, int8_t *old)
{
  __riscv_ztt_i8_rod_sat_1x2_t a = __riscv_ztt_mls_rm_i8_rod_sat_1x2 (in);
  __riscv_ztt_i8_rod_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_i8_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u8_rnu_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rnu_1x2_t a = __riscv_ztt_mls_rm_u8_rnu_1x2 (in);
  __riscv_ztt_u8_rnu_1x2_t b = __riscv_ztt_mcolzip_ew_u8_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u8_rnu_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rnu_1x2_t a = __riscv_ztt_mls_rm_u8_rnu_1x2 (in);
  __riscv_ztt_u8_rnu_1x2_t b = __riscv_ztt_mrowzip_ew_u8_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u8_rnu_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rnu_1x2_t a = __riscv_ztt_mls_rm_u8_rnu_1x2 (in);
  __riscv_ztt_u8_rnu_1x2_t b = __riscv_ztt_mcolunzip_ew_u8_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u8_rnu_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rnu_1x2_t a = __riscv_ztt_mls_rm_u8_rnu_1x2 (in);
  __riscv_ztt_u8_rnu_1x2_t b = __riscv_ztt_mrowunzip_ew_u8_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u8_rnu_sat_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_u8_rnu_sat_1x2 (in);
  __riscv_ztt_u8_rnu_sat_1x2_t b = __riscv_ztt_mcolzip_ew_u8_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u8_rnu_sat_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_u8_rnu_sat_1x2 (in);
  __riscv_ztt_u8_rnu_sat_1x2_t b = __riscv_ztt_mrowzip_ew_u8_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u8_rnu_sat_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_u8_rnu_sat_1x2 (in);
  __riscv_ztt_u8_rnu_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_u8_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u8_rnu_sat_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_u8_rnu_sat_1x2 (in);
  __riscv_ztt_u8_rnu_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_u8_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u8_rne_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rne_1x2_t a = __riscv_ztt_mls_rm_u8_rne_1x2 (in);
  __riscv_ztt_u8_rne_1x2_t b = __riscv_ztt_mcolzip_ew_u8_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u8_rne_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rne_1x2_t a = __riscv_ztt_mls_rm_u8_rne_1x2 (in);
  __riscv_ztt_u8_rne_1x2_t b = __riscv_ztt_mrowzip_ew_u8_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u8_rne_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rne_1x2_t a = __riscv_ztt_mls_rm_u8_rne_1x2 (in);
  __riscv_ztt_u8_rne_1x2_t b = __riscv_ztt_mcolunzip_ew_u8_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u8_rne_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rne_1x2_t a = __riscv_ztt_mls_rm_u8_rne_1x2 (in);
  __riscv_ztt_u8_rne_1x2_t b = __riscv_ztt_mrowunzip_ew_u8_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u8_rne_sat_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rne_sat_1x2_t a = __riscv_ztt_mls_rm_u8_rne_sat_1x2 (in);
  __riscv_ztt_u8_rne_sat_1x2_t b = __riscv_ztt_mcolzip_ew_u8_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u8_rne_sat_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rne_sat_1x2_t a = __riscv_ztt_mls_rm_u8_rne_sat_1x2 (in);
  __riscv_ztt_u8_rne_sat_1x2_t b = __riscv_ztt_mrowzip_ew_u8_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u8_rne_sat_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rne_sat_1x2_t a = __riscv_ztt_mls_rm_u8_rne_sat_1x2 (in);
  __riscv_ztt_u8_rne_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_u8_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u8_rne_sat_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rne_sat_1x2_t a = __riscv_ztt_mls_rm_u8_rne_sat_1x2 (in);
  __riscv_ztt_u8_rne_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_u8_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u8_rdn_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rdn_1x2_t a = __riscv_ztt_mls_rm_u8_rdn_1x2 (in);
  __riscv_ztt_u8_rdn_1x2_t b = __riscv_ztt_mcolzip_ew_u8_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u8_rdn_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rdn_1x2_t a = __riscv_ztt_mls_rm_u8_rdn_1x2 (in);
  __riscv_ztt_u8_rdn_1x2_t b = __riscv_ztt_mrowzip_ew_u8_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u8_rdn_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rdn_1x2_t a = __riscv_ztt_mls_rm_u8_rdn_1x2 (in);
  __riscv_ztt_u8_rdn_1x2_t b = __riscv_ztt_mcolunzip_ew_u8_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u8_rdn_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rdn_1x2_t a = __riscv_ztt_mls_rm_u8_rdn_1x2 (in);
  __riscv_ztt_u8_rdn_1x2_t b = __riscv_ztt_mrowunzip_ew_u8_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u8_rdn_sat_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_u8_rdn_sat_1x2 (in);
  __riscv_ztt_u8_rdn_sat_1x2_t b = __riscv_ztt_mcolzip_ew_u8_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u8_rdn_sat_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_u8_rdn_sat_1x2 (in);
  __riscv_ztt_u8_rdn_sat_1x2_t b = __riscv_ztt_mrowzip_ew_u8_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u8_rdn_sat_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_u8_rdn_sat_1x2 (in);
  __riscv_ztt_u8_rdn_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_u8_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u8_rdn_sat_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_u8_rdn_sat_1x2 (in);
  __riscv_ztt_u8_rdn_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_u8_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u8_rod_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rod_1x2_t a = __riscv_ztt_mls_rm_u8_rod_1x2 (in);
  __riscv_ztt_u8_rod_1x2_t b = __riscv_ztt_mcolzip_ew_u8_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u8_rod_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rod_1x2_t a = __riscv_ztt_mls_rm_u8_rod_1x2 (in);
  __riscv_ztt_u8_rod_1x2_t b = __riscv_ztt_mrowzip_ew_u8_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u8_rod_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rod_1x2_t a = __riscv_ztt_mls_rm_u8_rod_1x2 (in);
  __riscv_ztt_u8_rod_1x2_t b = __riscv_ztt_mcolunzip_ew_u8_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u8_rod_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rod_1x2_t a = __riscv_ztt_mls_rm_u8_rod_1x2 (in);
  __riscv_ztt_u8_rod_1x2_t b = __riscv_ztt_mrowunzip_ew_u8_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u8_rod_sat_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rod_sat_1x2_t a = __riscv_ztt_mls_rm_u8_rod_sat_1x2 (in);
  __riscv_ztt_u8_rod_sat_1x2_t b = __riscv_ztt_mcolzip_ew_u8_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u8_rod_sat_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rod_sat_1x2_t a = __riscv_ztt_mls_rm_u8_rod_sat_1x2 (in);
  __riscv_ztt_u8_rod_sat_1x2_t b = __riscv_ztt_mrowzip_ew_u8_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u8_rod_sat_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rod_sat_1x2_t a = __riscv_ztt_mls_rm_u8_rod_sat_1x2 (in);
  __riscv_ztt_u8_rod_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_u8_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u8_rod_sat_live (uint8_t *out, const uint8_t *in, uint8_t *old)
{
  __riscv_ztt_u8_rod_sat_1x2_t a = __riscv_ztt_mls_rm_u8_rod_sat_1x2 (in);
  __riscv_ztt_u8_rod_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_u8_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i16_rnu_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rnu_1x2_t a = __riscv_ztt_mls_rm_i16_rnu_1x2 (in);
  __riscv_ztt_i16_rnu_1x2_t b = __riscv_ztt_mcolzip_ew_i16_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i16_rnu_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rnu_1x2_t a = __riscv_ztt_mls_rm_i16_rnu_1x2 (in);
  __riscv_ztt_i16_rnu_1x2_t b = __riscv_ztt_mrowzip_ew_i16_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i16_rnu_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rnu_1x2_t a = __riscv_ztt_mls_rm_i16_rnu_1x2 (in);
  __riscv_ztt_i16_rnu_1x2_t b = __riscv_ztt_mcolunzip_ew_i16_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i16_rnu_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rnu_1x2_t a = __riscv_ztt_mls_rm_i16_rnu_1x2 (in);
  __riscv_ztt_i16_rnu_1x2_t b = __riscv_ztt_mrowunzip_ew_i16_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i16_rnu_sat_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_i16_rnu_sat_1x2 (in);
  __riscv_ztt_i16_rnu_sat_1x2_t b = __riscv_ztt_mcolzip_ew_i16_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i16_rnu_sat_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_i16_rnu_sat_1x2 (in);
  __riscv_ztt_i16_rnu_sat_1x2_t b = __riscv_ztt_mrowzip_ew_i16_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i16_rnu_sat_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_i16_rnu_sat_1x2 (in);
  __riscv_ztt_i16_rnu_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_i16_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i16_rnu_sat_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_i16_rnu_sat_1x2 (in);
  __riscv_ztt_i16_rnu_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_i16_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i16_rne_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rne_1x2_t a = __riscv_ztt_mls_rm_i16_rne_1x2 (in);
  __riscv_ztt_i16_rne_1x2_t b = __riscv_ztt_mcolzip_ew_i16_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i16_rne_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rne_1x2_t a = __riscv_ztt_mls_rm_i16_rne_1x2 (in);
  __riscv_ztt_i16_rne_1x2_t b = __riscv_ztt_mrowzip_ew_i16_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i16_rne_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rne_1x2_t a = __riscv_ztt_mls_rm_i16_rne_1x2 (in);
  __riscv_ztt_i16_rne_1x2_t b = __riscv_ztt_mcolunzip_ew_i16_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i16_rne_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rne_1x2_t a = __riscv_ztt_mls_rm_i16_rne_1x2 (in);
  __riscv_ztt_i16_rne_1x2_t b = __riscv_ztt_mrowunzip_ew_i16_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i16_rne_sat_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rne_sat_1x2_t a = __riscv_ztt_mls_rm_i16_rne_sat_1x2 (in);
  __riscv_ztt_i16_rne_sat_1x2_t b = __riscv_ztt_mcolzip_ew_i16_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i16_rne_sat_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rne_sat_1x2_t a = __riscv_ztt_mls_rm_i16_rne_sat_1x2 (in);
  __riscv_ztt_i16_rne_sat_1x2_t b = __riscv_ztt_mrowzip_ew_i16_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i16_rne_sat_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rne_sat_1x2_t a = __riscv_ztt_mls_rm_i16_rne_sat_1x2 (in);
  __riscv_ztt_i16_rne_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_i16_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i16_rne_sat_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rne_sat_1x2_t a = __riscv_ztt_mls_rm_i16_rne_sat_1x2 (in);
  __riscv_ztt_i16_rne_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_i16_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i16_rdn_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rdn_1x2_t a = __riscv_ztt_mls_rm_i16_rdn_1x2 (in);
  __riscv_ztt_i16_rdn_1x2_t b = __riscv_ztt_mcolzip_ew_i16_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i16_rdn_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rdn_1x2_t a = __riscv_ztt_mls_rm_i16_rdn_1x2 (in);
  __riscv_ztt_i16_rdn_1x2_t b = __riscv_ztt_mrowzip_ew_i16_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i16_rdn_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rdn_1x2_t a = __riscv_ztt_mls_rm_i16_rdn_1x2 (in);
  __riscv_ztt_i16_rdn_1x2_t b = __riscv_ztt_mcolunzip_ew_i16_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i16_rdn_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rdn_1x2_t a = __riscv_ztt_mls_rm_i16_rdn_1x2 (in);
  __riscv_ztt_i16_rdn_1x2_t b = __riscv_ztt_mrowunzip_ew_i16_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i16_rdn_sat_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_i16_rdn_sat_1x2 (in);
  __riscv_ztt_i16_rdn_sat_1x2_t b = __riscv_ztt_mcolzip_ew_i16_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i16_rdn_sat_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_i16_rdn_sat_1x2 (in);
  __riscv_ztt_i16_rdn_sat_1x2_t b = __riscv_ztt_mrowzip_ew_i16_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i16_rdn_sat_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_i16_rdn_sat_1x2 (in);
  __riscv_ztt_i16_rdn_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_i16_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i16_rdn_sat_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_i16_rdn_sat_1x2 (in);
  __riscv_ztt_i16_rdn_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_i16_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i16_rod_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rod_1x2_t a = __riscv_ztt_mls_rm_i16_rod_1x2 (in);
  __riscv_ztt_i16_rod_1x2_t b = __riscv_ztt_mcolzip_ew_i16_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i16_rod_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rod_1x2_t a = __riscv_ztt_mls_rm_i16_rod_1x2 (in);
  __riscv_ztt_i16_rod_1x2_t b = __riscv_ztt_mrowzip_ew_i16_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i16_rod_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rod_1x2_t a = __riscv_ztt_mls_rm_i16_rod_1x2 (in);
  __riscv_ztt_i16_rod_1x2_t b = __riscv_ztt_mcolunzip_ew_i16_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i16_rod_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rod_1x2_t a = __riscv_ztt_mls_rm_i16_rod_1x2 (in);
  __riscv_ztt_i16_rod_1x2_t b = __riscv_ztt_mrowunzip_ew_i16_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i16_rod_sat_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rod_sat_1x2_t a = __riscv_ztt_mls_rm_i16_rod_sat_1x2 (in);
  __riscv_ztt_i16_rod_sat_1x2_t b = __riscv_ztt_mcolzip_ew_i16_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i16_rod_sat_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rod_sat_1x2_t a = __riscv_ztt_mls_rm_i16_rod_sat_1x2 (in);
  __riscv_ztt_i16_rod_sat_1x2_t b = __riscv_ztt_mrowzip_ew_i16_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i16_rod_sat_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rod_sat_1x2_t a = __riscv_ztt_mls_rm_i16_rod_sat_1x2 (in);
  __riscv_ztt_i16_rod_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_i16_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i16_rod_sat_live (int16_t *out, const int16_t *in, int16_t *old)
{
  __riscv_ztt_i16_rod_sat_1x2_t a = __riscv_ztt_mls_rm_i16_rod_sat_1x2 (in);
  __riscv_ztt_i16_rod_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_i16_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u16_rnu_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rnu_1x2_t a = __riscv_ztt_mls_rm_u16_rnu_1x2 (in);
  __riscv_ztt_u16_rnu_1x2_t b = __riscv_ztt_mcolzip_ew_u16_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u16_rnu_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rnu_1x2_t a = __riscv_ztt_mls_rm_u16_rnu_1x2 (in);
  __riscv_ztt_u16_rnu_1x2_t b = __riscv_ztt_mrowzip_ew_u16_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u16_rnu_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rnu_1x2_t a = __riscv_ztt_mls_rm_u16_rnu_1x2 (in);
  __riscv_ztt_u16_rnu_1x2_t b = __riscv_ztt_mcolunzip_ew_u16_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u16_rnu_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rnu_1x2_t a = __riscv_ztt_mls_rm_u16_rnu_1x2 (in);
  __riscv_ztt_u16_rnu_1x2_t b = __riscv_ztt_mrowunzip_ew_u16_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u16_rnu_sat_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_u16_rnu_sat_1x2 (in);
  __riscv_ztt_u16_rnu_sat_1x2_t b = __riscv_ztt_mcolzip_ew_u16_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u16_rnu_sat_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_u16_rnu_sat_1x2 (in);
  __riscv_ztt_u16_rnu_sat_1x2_t b = __riscv_ztt_mrowzip_ew_u16_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u16_rnu_sat_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_u16_rnu_sat_1x2 (in);
  __riscv_ztt_u16_rnu_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_u16_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u16_rnu_sat_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_u16_rnu_sat_1x2 (in);
  __riscv_ztt_u16_rnu_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_u16_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u16_rne_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rne_1x2_t a = __riscv_ztt_mls_rm_u16_rne_1x2 (in);
  __riscv_ztt_u16_rne_1x2_t b = __riscv_ztt_mcolzip_ew_u16_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u16_rne_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rne_1x2_t a = __riscv_ztt_mls_rm_u16_rne_1x2 (in);
  __riscv_ztt_u16_rne_1x2_t b = __riscv_ztt_mrowzip_ew_u16_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u16_rne_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rne_1x2_t a = __riscv_ztt_mls_rm_u16_rne_1x2 (in);
  __riscv_ztt_u16_rne_1x2_t b = __riscv_ztt_mcolunzip_ew_u16_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u16_rne_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rne_1x2_t a = __riscv_ztt_mls_rm_u16_rne_1x2 (in);
  __riscv_ztt_u16_rne_1x2_t b = __riscv_ztt_mrowunzip_ew_u16_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u16_rne_sat_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rne_sat_1x2_t a = __riscv_ztt_mls_rm_u16_rne_sat_1x2 (in);
  __riscv_ztt_u16_rne_sat_1x2_t b = __riscv_ztt_mcolzip_ew_u16_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u16_rne_sat_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rne_sat_1x2_t a = __riscv_ztt_mls_rm_u16_rne_sat_1x2 (in);
  __riscv_ztt_u16_rne_sat_1x2_t b = __riscv_ztt_mrowzip_ew_u16_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u16_rne_sat_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rne_sat_1x2_t a = __riscv_ztt_mls_rm_u16_rne_sat_1x2 (in);
  __riscv_ztt_u16_rne_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_u16_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u16_rne_sat_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rne_sat_1x2_t a = __riscv_ztt_mls_rm_u16_rne_sat_1x2 (in);
  __riscv_ztt_u16_rne_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_u16_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u16_rdn_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rdn_1x2_t a = __riscv_ztt_mls_rm_u16_rdn_1x2 (in);
  __riscv_ztt_u16_rdn_1x2_t b = __riscv_ztt_mcolzip_ew_u16_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u16_rdn_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rdn_1x2_t a = __riscv_ztt_mls_rm_u16_rdn_1x2 (in);
  __riscv_ztt_u16_rdn_1x2_t b = __riscv_ztt_mrowzip_ew_u16_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u16_rdn_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rdn_1x2_t a = __riscv_ztt_mls_rm_u16_rdn_1x2 (in);
  __riscv_ztt_u16_rdn_1x2_t b = __riscv_ztt_mcolunzip_ew_u16_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u16_rdn_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rdn_1x2_t a = __riscv_ztt_mls_rm_u16_rdn_1x2 (in);
  __riscv_ztt_u16_rdn_1x2_t b = __riscv_ztt_mrowunzip_ew_u16_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u16_rdn_sat_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_u16_rdn_sat_1x2 (in);
  __riscv_ztt_u16_rdn_sat_1x2_t b = __riscv_ztt_mcolzip_ew_u16_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u16_rdn_sat_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_u16_rdn_sat_1x2 (in);
  __riscv_ztt_u16_rdn_sat_1x2_t b = __riscv_ztt_mrowzip_ew_u16_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u16_rdn_sat_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_u16_rdn_sat_1x2 (in);
  __riscv_ztt_u16_rdn_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_u16_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u16_rdn_sat_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_u16_rdn_sat_1x2 (in);
  __riscv_ztt_u16_rdn_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_u16_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u16_rod_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rod_1x2_t a = __riscv_ztt_mls_rm_u16_rod_1x2 (in);
  __riscv_ztt_u16_rod_1x2_t b = __riscv_ztt_mcolzip_ew_u16_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u16_rod_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rod_1x2_t a = __riscv_ztt_mls_rm_u16_rod_1x2 (in);
  __riscv_ztt_u16_rod_1x2_t b = __riscv_ztt_mrowzip_ew_u16_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u16_rod_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rod_1x2_t a = __riscv_ztt_mls_rm_u16_rod_1x2 (in);
  __riscv_ztt_u16_rod_1x2_t b = __riscv_ztt_mcolunzip_ew_u16_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u16_rod_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rod_1x2_t a = __riscv_ztt_mls_rm_u16_rod_1x2 (in);
  __riscv_ztt_u16_rod_1x2_t b = __riscv_ztt_mrowunzip_ew_u16_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u16_rod_sat_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rod_sat_1x2_t a = __riscv_ztt_mls_rm_u16_rod_sat_1x2 (in);
  __riscv_ztt_u16_rod_sat_1x2_t b = __riscv_ztt_mcolzip_ew_u16_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u16_rod_sat_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rod_sat_1x2_t a = __riscv_ztt_mls_rm_u16_rod_sat_1x2 (in);
  __riscv_ztt_u16_rod_sat_1x2_t b = __riscv_ztt_mrowzip_ew_u16_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u16_rod_sat_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rod_sat_1x2_t a = __riscv_ztt_mls_rm_u16_rod_sat_1x2 (in);
  __riscv_ztt_u16_rod_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_u16_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u16_rod_sat_live (uint16_t *out, const uint16_t *in, uint16_t *old)
{
  __riscv_ztt_u16_rod_sat_1x2_t a = __riscv_ztt_mls_rm_u16_rod_sat_1x2 (in);
  __riscv_ztt_u16_rod_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_u16_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i32_rnu_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rnu_1x2_t a = __riscv_ztt_mls_rm_i32_rnu_1x2 (in);
  __riscv_ztt_i32_rnu_1x2_t b = __riscv_ztt_mcolzip_ew_i32_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i32_rnu_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rnu_1x2_t a = __riscv_ztt_mls_rm_i32_rnu_1x2 (in);
  __riscv_ztt_i32_rnu_1x2_t b = __riscv_ztt_mrowzip_ew_i32_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i32_rnu_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rnu_1x2_t a = __riscv_ztt_mls_rm_i32_rnu_1x2 (in);
  __riscv_ztt_i32_rnu_1x2_t b = __riscv_ztt_mcolunzip_ew_i32_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i32_rnu_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rnu_1x2_t a = __riscv_ztt_mls_rm_i32_rnu_1x2 (in);
  __riscv_ztt_i32_rnu_1x2_t b = __riscv_ztt_mrowunzip_ew_i32_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i32_rnu_sat_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_i32_rnu_sat_1x2 (in);
  __riscv_ztt_i32_rnu_sat_1x2_t b = __riscv_ztt_mcolzip_ew_i32_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i32_rnu_sat_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_i32_rnu_sat_1x2 (in);
  __riscv_ztt_i32_rnu_sat_1x2_t b = __riscv_ztt_mrowzip_ew_i32_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i32_rnu_sat_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_i32_rnu_sat_1x2 (in);
  __riscv_ztt_i32_rnu_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_i32_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i32_rnu_sat_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_i32_rnu_sat_1x2 (in);
  __riscv_ztt_i32_rnu_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_i32_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i32_rne_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rne_1x2_t a = __riscv_ztt_mls_rm_i32_rne_1x2 (in);
  __riscv_ztt_i32_rne_1x2_t b = __riscv_ztt_mcolzip_ew_i32_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i32_rne_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rne_1x2_t a = __riscv_ztt_mls_rm_i32_rne_1x2 (in);
  __riscv_ztt_i32_rne_1x2_t b = __riscv_ztt_mrowzip_ew_i32_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i32_rne_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rne_1x2_t a = __riscv_ztt_mls_rm_i32_rne_1x2 (in);
  __riscv_ztt_i32_rne_1x2_t b = __riscv_ztt_mcolunzip_ew_i32_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i32_rne_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rne_1x2_t a = __riscv_ztt_mls_rm_i32_rne_1x2 (in);
  __riscv_ztt_i32_rne_1x2_t b = __riscv_ztt_mrowunzip_ew_i32_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i32_rne_sat_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rne_sat_1x2_t a = __riscv_ztt_mls_rm_i32_rne_sat_1x2 (in);
  __riscv_ztt_i32_rne_sat_1x2_t b = __riscv_ztt_mcolzip_ew_i32_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i32_rne_sat_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rne_sat_1x2_t a = __riscv_ztt_mls_rm_i32_rne_sat_1x2 (in);
  __riscv_ztt_i32_rne_sat_1x2_t b = __riscv_ztt_mrowzip_ew_i32_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i32_rne_sat_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rne_sat_1x2_t a = __riscv_ztt_mls_rm_i32_rne_sat_1x2 (in);
  __riscv_ztt_i32_rne_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_i32_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i32_rne_sat_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rne_sat_1x2_t a = __riscv_ztt_mls_rm_i32_rne_sat_1x2 (in);
  __riscv_ztt_i32_rne_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_i32_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i32_rdn_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rdn_1x2_t a = __riscv_ztt_mls_rm_i32_rdn_1x2 (in);
  __riscv_ztt_i32_rdn_1x2_t b = __riscv_ztt_mcolzip_ew_i32_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i32_rdn_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rdn_1x2_t a = __riscv_ztt_mls_rm_i32_rdn_1x2 (in);
  __riscv_ztt_i32_rdn_1x2_t b = __riscv_ztt_mrowzip_ew_i32_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i32_rdn_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rdn_1x2_t a = __riscv_ztt_mls_rm_i32_rdn_1x2 (in);
  __riscv_ztt_i32_rdn_1x2_t b = __riscv_ztt_mcolunzip_ew_i32_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i32_rdn_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rdn_1x2_t a = __riscv_ztt_mls_rm_i32_rdn_1x2 (in);
  __riscv_ztt_i32_rdn_1x2_t b = __riscv_ztt_mrowunzip_ew_i32_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i32_rdn_sat_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_i32_rdn_sat_1x2 (in);
  __riscv_ztt_i32_rdn_sat_1x2_t b = __riscv_ztt_mcolzip_ew_i32_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i32_rdn_sat_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_i32_rdn_sat_1x2 (in);
  __riscv_ztt_i32_rdn_sat_1x2_t b = __riscv_ztt_mrowzip_ew_i32_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i32_rdn_sat_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_i32_rdn_sat_1x2 (in);
  __riscv_ztt_i32_rdn_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_i32_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i32_rdn_sat_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_i32_rdn_sat_1x2 (in);
  __riscv_ztt_i32_rdn_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_i32_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i32_rod_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rod_1x2_t a = __riscv_ztt_mls_rm_i32_rod_1x2 (in);
  __riscv_ztt_i32_rod_1x2_t b = __riscv_ztt_mcolzip_ew_i32_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i32_rod_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rod_1x2_t a = __riscv_ztt_mls_rm_i32_rod_1x2 (in);
  __riscv_ztt_i32_rod_1x2_t b = __riscv_ztt_mrowzip_ew_i32_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i32_rod_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rod_1x2_t a = __riscv_ztt_mls_rm_i32_rod_1x2 (in);
  __riscv_ztt_i32_rod_1x2_t b = __riscv_ztt_mcolunzip_ew_i32_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i32_rod_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rod_1x2_t a = __riscv_ztt_mls_rm_i32_rod_1x2 (in);
  __riscv_ztt_i32_rod_1x2_t b = __riscv_ztt_mrowunzip_ew_i32_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i32_rod_sat_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rod_sat_1x2_t a = __riscv_ztt_mls_rm_i32_rod_sat_1x2 (in);
  __riscv_ztt_i32_rod_sat_1x2_t b = __riscv_ztt_mcolzip_ew_i32_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i32_rod_sat_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rod_sat_1x2_t a = __riscv_ztt_mls_rm_i32_rod_sat_1x2 (in);
  __riscv_ztt_i32_rod_sat_1x2_t b = __riscv_ztt_mrowzip_ew_i32_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i32_rod_sat_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rod_sat_1x2_t a = __riscv_ztt_mls_rm_i32_rod_sat_1x2 (in);
  __riscv_ztt_i32_rod_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_i32_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i32_rod_sat_live (int32_t *out, const int32_t *in, int32_t *old)
{
  __riscv_ztt_i32_rod_sat_1x2_t a = __riscv_ztt_mls_rm_i32_rod_sat_1x2 (in);
  __riscv_ztt_i32_rod_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_i32_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u32_rnu_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rnu_1x2_t a = __riscv_ztt_mls_rm_u32_rnu_1x2 (in);
  __riscv_ztt_u32_rnu_1x2_t b = __riscv_ztt_mcolzip_ew_u32_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u32_rnu_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rnu_1x2_t a = __riscv_ztt_mls_rm_u32_rnu_1x2 (in);
  __riscv_ztt_u32_rnu_1x2_t b = __riscv_ztt_mrowzip_ew_u32_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u32_rnu_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rnu_1x2_t a = __riscv_ztt_mls_rm_u32_rnu_1x2 (in);
  __riscv_ztt_u32_rnu_1x2_t b = __riscv_ztt_mcolunzip_ew_u32_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u32_rnu_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rnu_1x2_t a = __riscv_ztt_mls_rm_u32_rnu_1x2 (in);
  __riscv_ztt_u32_rnu_1x2_t b = __riscv_ztt_mrowunzip_ew_u32_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u32_rnu_sat_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_u32_rnu_sat_1x2 (in);
  __riscv_ztt_u32_rnu_sat_1x2_t b = __riscv_ztt_mcolzip_ew_u32_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u32_rnu_sat_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_u32_rnu_sat_1x2 (in);
  __riscv_ztt_u32_rnu_sat_1x2_t b = __riscv_ztt_mrowzip_ew_u32_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u32_rnu_sat_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_u32_rnu_sat_1x2 (in);
  __riscv_ztt_u32_rnu_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_u32_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u32_rnu_sat_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_u32_rnu_sat_1x2 (in);
  __riscv_ztt_u32_rnu_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_u32_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u32_rne_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rne_1x2_t a = __riscv_ztt_mls_rm_u32_rne_1x2 (in);
  __riscv_ztt_u32_rne_1x2_t b = __riscv_ztt_mcolzip_ew_u32_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u32_rne_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rne_1x2_t a = __riscv_ztt_mls_rm_u32_rne_1x2 (in);
  __riscv_ztt_u32_rne_1x2_t b = __riscv_ztt_mrowzip_ew_u32_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u32_rne_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rne_1x2_t a = __riscv_ztt_mls_rm_u32_rne_1x2 (in);
  __riscv_ztt_u32_rne_1x2_t b = __riscv_ztt_mcolunzip_ew_u32_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u32_rne_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rne_1x2_t a = __riscv_ztt_mls_rm_u32_rne_1x2 (in);
  __riscv_ztt_u32_rne_1x2_t b = __riscv_ztt_mrowunzip_ew_u32_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u32_rne_sat_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rne_sat_1x2_t a = __riscv_ztt_mls_rm_u32_rne_sat_1x2 (in);
  __riscv_ztt_u32_rne_sat_1x2_t b = __riscv_ztt_mcolzip_ew_u32_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u32_rne_sat_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rne_sat_1x2_t a = __riscv_ztt_mls_rm_u32_rne_sat_1x2 (in);
  __riscv_ztt_u32_rne_sat_1x2_t b = __riscv_ztt_mrowzip_ew_u32_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u32_rne_sat_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rne_sat_1x2_t a = __riscv_ztt_mls_rm_u32_rne_sat_1x2 (in);
  __riscv_ztt_u32_rne_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_u32_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u32_rne_sat_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rne_sat_1x2_t a = __riscv_ztt_mls_rm_u32_rne_sat_1x2 (in);
  __riscv_ztt_u32_rne_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_u32_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u32_rdn_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rdn_1x2_t a = __riscv_ztt_mls_rm_u32_rdn_1x2 (in);
  __riscv_ztt_u32_rdn_1x2_t b = __riscv_ztt_mcolzip_ew_u32_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u32_rdn_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rdn_1x2_t a = __riscv_ztt_mls_rm_u32_rdn_1x2 (in);
  __riscv_ztt_u32_rdn_1x2_t b = __riscv_ztt_mrowzip_ew_u32_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u32_rdn_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rdn_1x2_t a = __riscv_ztt_mls_rm_u32_rdn_1x2 (in);
  __riscv_ztt_u32_rdn_1x2_t b = __riscv_ztt_mcolunzip_ew_u32_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u32_rdn_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rdn_1x2_t a = __riscv_ztt_mls_rm_u32_rdn_1x2 (in);
  __riscv_ztt_u32_rdn_1x2_t b = __riscv_ztt_mrowunzip_ew_u32_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u32_rdn_sat_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_u32_rdn_sat_1x2 (in);
  __riscv_ztt_u32_rdn_sat_1x2_t b = __riscv_ztt_mcolzip_ew_u32_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u32_rdn_sat_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_u32_rdn_sat_1x2 (in);
  __riscv_ztt_u32_rdn_sat_1x2_t b = __riscv_ztt_mrowzip_ew_u32_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u32_rdn_sat_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_u32_rdn_sat_1x2 (in);
  __riscv_ztt_u32_rdn_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_u32_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u32_rdn_sat_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_u32_rdn_sat_1x2 (in);
  __riscv_ztt_u32_rdn_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_u32_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u32_rod_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rod_1x2_t a = __riscv_ztt_mls_rm_u32_rod_1x2 (in);
  __riscv_ztt_u32_rod_1x2_t b = __riscv_ztt_mcolzip_ew_u32_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u32_rod_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rod_1x2_t a = __riscv_ztt_mls_rm_u32_rod_1x2 (in);
  __riscv_ztt_u32_rod_1x2_t b = __riscv_ztt_mrowzip_ew_u32_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u32_rod_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rod_1x2_t a = __riscv_ztt_mls_rm_u32_rod_1x2 (in);
  __riscv_ztt_u32_rod_1x2_t b = __riscv_ztt_mcolunzip_ew_u32_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u32_rod_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rod_1x2_t a = __riscv_ztt_mls_rm_u32_rod_1x2 (in);
  __riscv_ztt_u32_rod_1x2_t b = __riscv_ztt_mrowunzip_ew_u32_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u32_rod_sat_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rod_sat_1x2_t a = __riscv_ztt_mls_rm_u32_rod_sat_1x2 (in);
  __riscv_ztt_u32_rod_sat_1x2_t b = __riscv_ztt_mcolzip_ew_u32_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u32_rod_sat_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rod_sat_1x2_t a = __riscv_ztt_mls_rm_u32_rod_sat_1x2 (in);
  __riscv_ztt_u32_rod_sat_1x2_t b = __riscv_ztt_mrowzip_ew_u32_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u32_rod_sat_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rod_sat_1x2_t a = __riscv_ztt_mls_rm_u32_rod_sat_1x2 (in);
  __riscv_ztt_u32_rod_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_u32_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u32_rod_sat_live (uint32_t *out, const uint32_t *in, uint32_t *old)
{
  __riscv_ztt_u32_rod_sat_1x2_t a = __riscv_ztt_mls_rm_u32_rod_sat_1x2 (in);
  __riscv_ztt_u32_rod_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_u32_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i64_rnu_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rnu_1x2_t a = __riscv_ztt_mls_rm_i64_rnu_1x2 (in);
  __riscv_ztt_i64_rnu_1x2_t b = __riscv_ztt_mcolzip_ew_i64_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i64_rnu_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rnu_1x2_t a = __riscv_ztt_mls_rm_i64_rnu_1x2 (in);
  __riscv_ztt_i64_rnu_1x2_t b = __riscv_ztt_mrowzip_ew_i64_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i64_rnu_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rnu_1x2_t a = __riscv_ztt_mls_rm_i64_rnu_1x2 (in);
  __riscv_ztt_i64_rnu_1x2_t b = __riscv_ztt_mcolunzip_ew_i64_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i64_rnu_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rnu_1x2_t a = __riscv_ztt_mls_rm_i64_rnu_1x2 (in);
  __riscv_ztt_i64_rnu_1x2_t b = __riscv_ztt_mrowunzip_ew_i64_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i64_rnu_sat_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_i64_rnu_sat_1x2 (in);
  __riscv_ztt_i64_rnu_sat_1x2_t b = __riscv_ztt_mcolzip_ew_i64_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i64_rnu_sat_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_i64_rnu_sat_1x2 (in);
  __riscv_ztt_i64_rnu_sat_1x2_t b = __riscv_ztt_mrowzip_ew_i64_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i64_rnu_sat_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_i64_rnu_sat_1x2 (in);
  __riscv_ztt_i64_rnu_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_i64_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i64_rnu_sat_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_i64_rnu_sat_1x2 (in);
  __riscv_ztt_i64_rnu_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_i64_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i64_rne_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rne_1x2_t a = __riscv_ztt_mls_rm_i64_rne_1x2 (in);
  __riscv_ztt_i64_rne_1x2_t b = __riscv_ztt_mcolzip_ew_i64_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i64_rne_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rne_1x2_t a = __riscv_ztt_mls_rm_i64_rne_1x2 (in);
  __riscv_ztt_i64_rne_1x2_t b = __riscv_ztt_mrowzip_ew_i64_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i64_rne_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rne_1x2_t a = __riscv_ztt_mls_rm_i64_rne_1x2 (in);
  __riscv_ztt_i64_rne_1x2_t b = __riscv_ztt_mcolunzip_ew_i64_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i64_rne_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rne_1x2_t a = __riscv_ztt_mls_rm_i64_rne_1x2 (in);
  __riscv_ztt_i64_rne_1x2_t b = __riscv_ztt_mrowunzip_ew_i64_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i64_rne_sat_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rne_sat_1x2_t a = __riscv_ztt_mls_rm_i64_rne_sat_1x2 (in);
  __riscv_ztt_i64_rne_sat_1x2_t b = __riscv_ztt_mcolzip_ew_i64_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i64_rne_sat_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rne_sat_1x2_t a = __riscv_ztt_mls_rm_i64_rne_sat_1x2 (in);
  __riscv_ztt_i64_rne_sat_1x2_t b = __riscv_ztt_mrowzip_ew_i64_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i64_rne_sat_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rne_sat_1x2_t a = __riscv_ztt_mls_rm_i64_rne_sat_1x2 (in);
  __riscv_ztt_i64_rne_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_i64_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i64_rne_sat_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rne_sat_1x2_t a = __riscv_ztt_mls_rm_i64_rne_sat_1x2 (in);
  __riscv_ztt_i64_rne_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_i64_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i64_rdn_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rdn_1x2_t a = __riscv_ztt_mls_rm_i64_rdn_1x2 (in);
  __riscv_ztt_i64_rdn_1x2_t b = __riscv_ztt_mcolzip_ew_i64_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i64_rdn_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rdn_1x2_t a = __riscv_ztt_mls_rm_i64_rdn_1x2 (in);
  __riscv_ztt_i64_rdn_1x2_t b = __riscv_ztt_mrowzip_ew_i64_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i64_rdn_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rdn_1x2_t a = __riscv_ztt_mls_rm_i64_rdn_1x2 (in);
  __riscv_ztt_i64_rdn_1x2_t b = __riscv_ztt_mcolunzip_ew_i64_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i64_rdn_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rdn_1x2_t a = __riscv_ztt_mls_rm_i64_rdn_1x2 (in);
  __riscv_ztt_i64_rdn_1x2_t b = __riscv_ztt_mrowunzip_ew_i64_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i64_rdn_sat_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_i64_rdn_sat_1x2 (in);
  __riscv_ztt_i64_rdn_sat_1x2_t b = __riscv_ztt_mcolzip_ew_i64_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i64_rdn_sat_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_i64_rdn_sat_1x2 (in);
  __riscv_ztt_i64_rdn_sat_1x2_t b = __riscv_ztt_mrowzip_ew_i64_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i64_rdn_sat_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_i64_rdn_sat_1x2 (in);
  __riscv_ztt_i64_rdn_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_i64_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i64_rdn_sat_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_i64_rdn_sat_1x2 (in);
  __riscv_ztt_i64_rdn_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_i64_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i64_rod_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rod_1x2_t a = __riscv_ztt_mls_rm_i64_rod_1x2 (in);
  __riscv_ztt_i64_rod_1x2_t b = __riscv_ztt_mcolzip_ew_i64_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i64_rod_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rod_1x2_t a = __riscv_ztt_mls_rm_i64_rod_1x2 (in);
  __riscv_ztt_i64_rod_1x2_t b = __riscv_ztt_mrowzip_ew_i64_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i64_rod_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rod_1x2_t a = __riscv_ztt_mls_rm_i64_rod_1x2 (in);
  __riscv_ztt_i64_rod_1x2_t b = __riscv_ztt_mcolunzip_ew_i64_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i64_rod_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rod_1x2_t a = __riscv_ztt_mls_rm_i64_rod_1x2 (in);
  __riscv_ztt_i64_rod_1x2_t b = __riscv_ztt_mrowunzip_ew_i64_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i64_rod_sat_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rod_sat_1x2_t a = __riscv_ztt_mls_rm_i64_rod_sat_1x2 (in);
  __riscv_ztt_i64_rod_sat_1x2_t b = __riscv_ztt_mcolzip_ew_i64_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i64_rod_sat_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rod_sat_1x2_t a = __riscv_ztt_mls_rm_i64_rod_sat_1x2 (in);
  __riscv_ztt_i64_rod_sat_1x2_t b = __riscv_ztt_mrowzip_ew_i64_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i64_rod_sat_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rod_sat_1x2_t a = __riscv_ztt_mls_rm_i64_rod_sat_1x2 (in);
  __riscv_ztt_i64_rod_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_i64_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i64_rod_sat_live (int64_t *out, const int64_t *in, int64_t *old)
{
  __riscv_ztt_i64_rod_sat_1x2_t a = __riscv_ztt_mls_rm_i64_rod_sat_1x2 (in);
  __riscv_ztt_i64_rod_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_i64_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u64_rnu_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rnu_1x2_t a = __riscv_ztt_mls_rm_u64_rnu_1x2 (in);
  __riscv_ztt_u64_rnu_1x2_t b = __riscv_ztt_mcolzip_ew_u64_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u64_rnu_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rnu_1x2_t a = __riscv_ztt_mls_rm_u64_rnu_1x2 (in);
  __riscv_ztt_u64_rnu_1x2_t b = __riscv_ztt_mrowzip_ew_u64_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u64_rnu_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rnu_1x2_t a = __riscv_ztt_mls_rm_u64_rnu_1x2 (in);
  __riscv_ztt_u64_rnu_1x2_t b = __riscv_ztt_mcolunzip_ew_u64_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u64_rnu_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rnu_1x2_t a = __riscv_ztt_mls_rm_u64_rnu_1x2 (in);
  __riscv_ztt_u64_rnu_1x2_t b = __riscv_ztt_mrowunzip_ew_u64_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u64_rnu_sat_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_u64_rnu_sat_1x2 (in);
  __riscv_ztt_u64_rnu_sat_1x2_t b = __riscv_ztt_mcolzip_ew_u64_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u64_rnu_sat_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_u64_rnu_sat_1x2 (in);
  __riscv_ztt_u64_rnu_sat_1x2_t b = __riscv_ztt_mrowzip_ew_u64_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u64_rnu_sat_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_u64_rnu_sat_1x2 (in);
  __riscv_ztt_u64_rnu_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_u64_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u64_rnu_sat_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_u64_rnu_sat_1x2 (in);
  __riscv_ztt_u64_rnu_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_u64_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u64_rne_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rne_1x2_t a = __riscv_ztt_mls_rm_u64_rne_1x2 (in);
  __riscv_ztt_u64_rne_1x2_t b = __riscv_ztt_mcolzip_ew_u64_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u64_rne_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rne_1x2_t a = __riscv_ztt_mls_rm_u64_rne_1x2 (in);
  __riscv_ztt_u64_rne_1x2_t b = __riscv_ztt_mrowzip_ew_u64_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u64_rne_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rne_1x2_t a = __riscv_ztt_mls_rm_u64_rne_1x2 (in);
  __riscv_ztt_u64_rne_1x2_t b = __riscv_ztt_mcolunzip_ew_u64_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u64_rne_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rne_1x2_t a = __riscv_ztt_mls_rm_u64_rne_1x2 (in);
  __riscv_ztt_u64_rne_1x2_t b = __riscv_ztt_mrowunzip_ew_u64_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u64_rne_sat_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rne_sat_1x2_t a = __riscv_ztt_mls_rm_u64_rne_sat_1x2 (in);
  __riscv_ztt_u64_rne_sat_1x2_t b = __riscv_ztt_mcolzip_ew_u64_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u64_rne_sat_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rne_sat_1x2_t a = __riscv_ztt_mls_rm_u64_rne_sat_1x2 (in);
  __riscv_ztt_u64_rne_sat_1x2_t b = __riscv_ztt_mrowzip_ew_u64_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u64_rne_sat_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rne_sat_1x2_t a = __riscv_ztt_mls_rm_u64_rne_sat_1x2 (in);
  __riscv_ztt_u64_rne_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_u64_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u64_rne_sat_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rne_sat_1x2_t a = __riscv_ztt_mls_rm_u64_rne_sat_1x2 (in);
  __riscv_ztt_u64_rne_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_u64_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u64_rdn_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rdn_1x2_t a = __riscv_ztt_mls_rm_u64_rdn_1x2 (in);
  __riscv_ztt_u64_rdn_1x2_t b = __riscv_ztt_mcolzip_ew_u64_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u64_rdn_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rdn_1x2_t a = __riscv_ztt_mls_rm_u64_rdn_1x2 (in);
  __riscv_ztt_u64_rdn_1x2_t b = __riscv_ztt_mrowzip_ew_u64_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u64_rdn_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rdn_1x2_t a = __riscv_ztt_mls_rm_u64_rdn_1x2 (in);
  __riscv_ztt_u64_rdn_1x2_t b = __riscv_ztt_mcolunzip_ew_u64_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u64_rdn_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rdn_1x2_t a = __riscv_ztt_mls_rm_u64_rdn_1x2 (in);
  __riscv_ztt_u64_rdn_1x2_t b = __riscv_ztt_mrowunzip_ew_u64_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u64_rdn_sat_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_u64_rdn_sat_1x2 (in);
  __riscv_ztt_u64_rdn_sat_1x2_t b = __riscv_ztt_mcolzip_ew_u64_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u64_rdn_sat_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_u64_rdn_sat_1x2 (in);
  __riscv_ztt_u64_rdn_sat_1x2_t b = __riscv_ztt_mrowzip_ew_u64_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u64_rdn_sat_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_u64_rdn_sat_1x2 (in);
  __riscv_ztt_u64_rdn_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_u64_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u64_rdn_sat_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_u64_rdn_sat_1x2 (in);
  __riscv_ztt_u64_rdn_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_u64_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u64_rod_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rod_1x2_t a = __riscv_ztt_mls_rm_u64_rod_1x2 (in);
  __riscv_ztt_u64_rod_1x2_t b = __riscv_ztt_mcolzip_ew_u64_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u64_rod_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rod_1x2_t a = __riscv_ztt_mls_rm_u64_rod_1x2 (in);
  __riscv_ztt_u64_rod_1x2_t b = __riscv_ztt_mrowzip_ew_u64_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u64_rod_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rod_1x2_t a = __riscv_ztt_mls_rm_u64_rod_1x2 (in);
  __riscv_ztt_u64_rod_1x2_t b = __riscv_ztt_mcolunzip_ew_u64_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u64_rod_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rod_1x2_t a = __riscv_ztt_mls_rm_u64_rod_1x2 (in);
  __riscv_ztt_u64_rod_1x2_t b = __riscv_ztt_mrowunzip_ew_u64_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u64_rod_sat_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rod_sat_1x2_t a = __riscv_ztt_mls_rm_u64_rod_sat_1x2 (in);
  __riscv_ztt_u64_rod_sat_1x2_t b = __riscv_ztt_mcolzip_ew_u64_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u64_rod_sat_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rod_sat_1x2_t a = __riscv_ztt_mls_rm_u64_rod_sat_1x2 (in);
  __riscv_ztt_u64_rod_sat_1x2_t b = __riscv_ztt_mrowzip_ew_u64_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u64_rod_sat_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rod_sat_1x2_t a = __riscv_ztt_mls_rm_u64_rod_sat_1x2 (in);
  __riscv_ztt_u64_rod_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_u64_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u64_rod_sat_live (uint64_t *out, const uint64_t *in, uint64_t *old)
{
  __riscv_ztt_u64_rod_sat_1x2_t a = __riscv_ztt_mls_rm_u64_rod_sat_1x2 (in);
  __riscv_ztt_u64_rod_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_u64_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_f16_rne_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rne_1x2_t a = __riscv_ztt_mls_rm_f16_rne_1x2 (in);
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mcolzip_ew_f16_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_f16_rne_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rne_1x2_t a = __riscv_ztt_mls_rm_f16_rne_1x2 (in);
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mrowzip_ew_f16_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_f16_rne_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rne_1x2_t a = __riscv_ztt_mls_rm_f16_rne_1x2 (in);
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mcolunzip_ew_f16_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_f16_rne_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rne_1x2_t a = __riscv_ztt_mls_rm_f16_rne_1x2 (in);
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mrowunzip_ew_f16_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_f16_rtz_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rtz_1x2_t a = __riscv_ztt_mls_rm_f16_rtz_1x2 (in);
  __riscv_ztt_f16_rtz_1x2_t b = __riscv_ztt_mcolzip_ew_f16_rtz_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_f16_rtz_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rtz_1x2_t a = __riscv_ztt_mls_rm_f16_rtz_1x2 (in);
  __riscv_ztt_f16_rtz_1x2_t b = __riscv_ztt_mrowzip_ew_f16_rtz_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_f16_rtz_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rtz_1x2_t a = __riscv_ztt_mls_rm_f16_rtz_1x2 (in);
  __riscv_ztt_f16_rtz_1x2_t b = __riscv_ztt_mcolunzip_ew_f16_rtz_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_f16_rtz_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rtz_1x2_t a = __riscv_ztt_mls_rm_f16_rtz_1x2 (in);
  __riscv_ztt_f16_rtz_1x2_t b = __riscv_ztt_mrowunzip_ew_f16_rtz_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_f16_rdn_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rdn_1x2_t a = __riscv_ztt_mls_rm_f16_rdn_1x2 (in);
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mcolzip_ew_f16_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_f16_rdn_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rdn_1x2_t a = __riscv_ztt_mls_rm_f16_rdn_1x2 (in);
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mrowzip_ew_f16_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_f16_rdn_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rdn_1x2_t a = __riscv_ztt_mls_rm_f16_rdn_1x2 (in);
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mcolunzip_ew_f16_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_f16_rdn_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rdn_1x2_t a = __riscv_ztt_mls_rm_f16_rdn_1x2 (in);
  __riscv_ztt_f16_rdn_1x2_t b = __riscv_ztt_mrowunzip_ew_f16_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_f16_rup_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rup_1x2_t a = __riscv_ztt_mls_rm_f16_rup_1x2 (in);
  __riscv_ztt_f16_rup_1x2_t b = __riscv_ztt_mcolzip_ew_f16_rup_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_f16_rup_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rup_1x2_t a = __riscv_ztt_mls_rm_f16_rup_1x2 (in);
  __riscv_ztt_f16_rup_1x2_t b = __riscv_ztt_mrowzip_ew_f16_rup_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_f16_rup_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rup_1x2_t a = __riscv_ztt_mls_rm_f16_rup_1x2 (in);
  __riscv_ztt_f16_rup_1x2_t b = __riscv_ztt_mcolunzip_ew_f16_rup_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_f16_rup_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rup_1x2_t a = __riscv_ztt_mls_rm_f16_rup_1x2 (in);
  __riscv_ztt_f16_rup_1x2_t b = __riscv_ztt_mrowunzip_ew_f16_rup_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_f16_rmm_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rmm_1x2_t a = __riscv_ztt_mls_rm_f16_rmm_1x2 (in);
  __riscv_ztt_f16_rmm_1x2_t b = __riscv_ztt_mcolzip_ew_f16_rmm_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_f16_rmm_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rmm_1x2_t a = __riscv_ztt_mls_rm_f16_rmm_1x2 (in);
  __riscv_ztt_f16_rmm_1x2_t b = __riscv_ztt_mrowzip_ew_f16_rmm_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_f16_rmm_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rmm_1x2_t a = __riscv_ztt_mls_rm_f16_rmm_1x2 (in);
  __riscv_ztt_f16_rmm_1x2_t b = __riscv_ztt_mcolunzip_ew_f16_rmm_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_f16_rmm_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rmm_1x2_t a = __riscv_ztt_mls_rm_f16_rmm_1x2 (in);
  __riscv_ztt_f16_rmm_1x2_t b = __riscv_ztt_mrowunzip_ew_f16_rmm_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_f16_rno_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rno_1x2_t a = __riscv_ztt_mls_rm_f16_rno_1x2 (in);
  __riscv_ztt_f16_rno_1x2_t b = __riscv_ztt_mcolzip_ew_f16_rno_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_f16_rno_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rno_1x2_t a = __riscv_ztt_mls_rm_f16_rno_1x2 (in);
  __riscv_ztt_f16_rno_1x2_t b = __riscv_ztt_mrowzip_ew_f16_rno_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_f16_rno_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rno_1x2_t a = __riscv_ztt_mls_rm_f16_rno_1x2 (in);
  __riscv_ztt_f16_rno_1x2_t b = __riscv_ztt_mcolunzip_ew_f16_rno_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_f16_rno_live (_Float16 *out, const _Float16 *in, _Float16 *old)
{
  __riscv_ztt_f16_rno_1x2_t a = __riscv_ztt_mls_rm_f16_rno_1x2 (in);
  __riscv_ztt_f16_rno_1x2_t b = __riscv_ztt_mrowunzip_ew_f16_rno_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_bf16_rne_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rne_1x2_t a = __riscv_ztt_mls_rm_bf16_rne_1x2 (in);
  __riscv_ztt_bf16_rne_1x2_t b = __riscv_ztt_mcolzip_ew_bf16_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_bf16_rne_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rne_1x2_t a = __riscv_ztt_mls_rm_bf16_rne_1x2 (in);
  __riscv_ztt_bf16_rne_1x2_t b = __riscv_ztt_mrowzip_ew_bf16_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_bf16_rne_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rne_1x2_t a = __riscv_ztt_mls_rm_bf16_rne_1x2 (in);
  __riscv_ztt_bf16_rne_1x2_t b = __riscv_ztt_mcolunzip_ew_bf16_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_bf16_rne_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rne_1x2_t a = __riscv_ztt_mls_rm_bf16_rne_1x2 (in);
  __riscv_ztt_bf16_rne_1x2_t b = __riscv_ztt_mrowunzip_ew_bf16_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_bf16_rtz_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rtz_1x2_t a = __riscv_ztt_mls_rm_bf16_rtz_1x2 (in);
  __riscv_ztt_bf16_rtz_1x2_t b = __riscv_ztt_mcolzip_ew_bf16_rtz_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_bf16_rtz_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rtz_1x2_t a = __riscv_ztt_mls_rm_bf16_rtz_1x2 (in);
  __riscv_ztt_bf16_rtz_1x2_t b = __riscv_ztt_mrowzip_ew_bf16_rtz_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_bf16_rtz_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rtz_1x2_t a = __riscv_ztt_mls_rm_bf16_rtz_1x2 (in);
  __riscv_ztt_bf16_rtz_1x2_t b = __riscv_ztt_mcolunzip_ew_bf16_rtz_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_bf16_rtz_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rtz_1x2_t a = __riscv_ztt_mls_rm_bf16_rtz_1x2 (in);
  __riscv_ztt_bf16_rtz_1x2_t b = __riscv_ztt_mrowunzip_ew_bf16_rtz_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_bf16_rdn_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rdn_1x2_t a = __riscv_ztt_mls_rm_bf16_rdn_1x2 (in);
  __riscv_ztt_bf16_rdn_1x2_t b = __riscv_ztt_mcolzip_ew_bf16_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_bf16_rdn_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rdn_1x2_t a = __riscv_ztt_mls_rm_bf16_rdn_1x2 (in);
  __riscv_ztt_bf16_rdn_1x2_t b = __riscv_ztt_mrowzip_ew_bf16_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_bf16_rdn_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rdn_1x2_t a = __riscv_ztt_mls_rm_bf16_rdn_1x2 (in);
  __riscv_ztt_bf16_rdn_1x2_t b = __riscv_ztt_mcolunzip_ew_bf16_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_bf16_rdn_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rdn_1x2_t a = __riscv_ztt_mls_rm_bf16_rdn_1x2 (in);
  __riscv_ztt_bf16_rdn_1x2_t b = __riscv_ztt_mrowunzip_ew_bf16_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_bf16_rup_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rup_1x2_t a = __riscv_ztt_mls_rm_bf16_rup_1x2 (in);
  __riscv_ztt_bf16_rup_1x2_t b = __riscv_ztt_mcolzip_ew_bf16_rup_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_bf16_rup_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rup_1x2_t a = __riscv_ztt_mls_rm_bf16_rup_1x2 (in);
  __riscv_ztt_bf16_rup_1x2_t b = __riscv_ztt_mrowzip_ew_bf16_rup_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_bf16_rup_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rup_1x2_t a = __riscv_ztt_mls_rm_bf16_rup_1x2 (in);
  __riscv_ztt_bf16_rup_1x2_t b = __riscv_ztt_mcolunzip_ew_bf16_rup_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_bf16_rup_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rup_1x2_t a = __riscv_ztt_mls_rm_bf16_rup_1x2 (in);
  __riscv_ztt_bf16_rup_1x2_t b = __riscv_ztt_mrowunzip_ew_bf16_rup_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_bf16_rmm_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rmm_1x2_t a = __riscv_ztt_mls_rm_bf16_rmm_1x2 (in);
  __riscv_ztt_bf16_rmm_1x2_t b = __riscv_ztt_mcolzip_ew_bf16_rmm_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_bf16_rmm_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rmm_1x2_t a = __riscv_ztt_mls_rm_bf16_rmm_1x2 (in);
  __riscv_ztt_bf16_rmm_1x2_t b = __riscv_ztt_mrowzip_ew_bf16_rmm_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_bf16_rmm_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rmm_1x2_t a = __riscv_ztt_mls_rm_bf16_rmm_1x2 (in);
  __riscv_ztt_bf16_rmm_1x2_t b = __riscv_ztt_mcolunzip_ew_bf16_rmm_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_bf16_rmm_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rmm_1x2_t a = __riscv_ztt_mls_rm_bf16_rmm_1x2 (in);
  __riscv_ztt_bf16_rmm_1x2_t b = __riscv_ztt_mrowunzip_ew_bf16_rmm_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_bf16_rno_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rno_1x2_t a = __riscv_ztt_mls_rm_bf16_rno_1x2 (in);
  __riscv_ztt_bf16_rno_1x2_t b = __riscv_ztt_mcolzip_ew_bf16_rno_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_bf16_rno_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rno_1x2_t a = __riscv_ztt_mls_rm_bf16_rno_1x2 (in);
  __riscv_ztt_bf16_rno_1x2_t b = __riscv_ztt_mrowzip_ew_bf16_rno_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_bf16_rno_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rno_1x2_t a = __riscv_ztt_mls_rm_bf16_rno_1x2 (in);
  __riscv_ztt_bf16_rno_1x2_t b = __riscv_ztt_mcolunzip_ew_bf16_rno_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_bf16_rno_live (__bf16 *out, const __bf16 *in, __bf16 *old)
{
  __riscv_ztt_bf16_rno_1x2_t a = __riscv_ztt_mls_rm_bf16_rno_1x2 (in);
  __riscv_ztt_bf16_rno_1x2_t b = __riscv_ztt_mrowunzip_ew_bf16_rno_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_f32_rne_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rne_1x2_t a = __riscv_ztt_mls_rm_f32_rne_1x2 (in);
  __riscv_ztt_f32_rne_1x2_t b = __riscv_ztt_mcolzip_ew_f32_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_f32_rne_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rne_1x2_t a = __riscv_ztt_mls_rm_f32_rne_1x2 (in);
  __riscv_ztt_f32_rne_1x2_t b = __riscv_ztt_mrowzip_ew_f32_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_f32_rne_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rne_1x2_t a = __riscv_ztt_mls_rm_f32_rne_1x2 (in);
  __riscv_ztt_f32_rne_1x2_t b = __riscv_ztt_mcolunzip_ew_f32_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_f32_rne_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rne_1x2_t a = __riscv_ztt_mls_rm_f32_rne_1x2 (in);
  __riscv_ztt_f32_rne_1x2_t b = __riscv_ztt_mrowunzip_ew_f32_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_f32_rtz_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rtz_1x2_t a = __riscv_ztt_mls_rm_f32_rtz_1x2 (in);
  __riscv_ztt_f32_rtz_1x2_t b = __riscv_ztt_mcolzip_ew_f32_rtz_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_f32_rtz_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rtz_1x2_t a = __riscv_ztt_mls_rm_f32_rtz_1x2 (in);
  __riscv_ztt_f32_rtz_1x2_t b = __riscv_ztt_mrowzip_ew_f32_rtz_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_f32_rtz_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rtz_1x2_t a = __riscv_ztt_mls_rm_f32_rtz_1x2 (in);
  __riscv_ztt_f32_rtz_1x2_t b = __riscv_ztt_mcolunzip_ew_f32_rtz_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_f32_rtz_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rtz_1x2_t a = __riscv_ztt_mls_rm_f32_rtz_1x2 (in);
  __riscv_ztt_f32_rtz_1x2_t b = __riscv_ztt_mrowunzip_ew_f32_rtz_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_f32_rdn_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rdn_1x2_t a = __riscv_ztt_mls_rm_f32_rdn_1x2 (in);
  __riscv_ztt_f32_rdn_1x2_t b = __riscv_ztt_mcolzip_ew_f32_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_f32_rdn_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rdn_1x2_t a = __riscv_ztt_mls_rm_f32_rdn_1x2 (in);
  __riscv_ztt_f32_rdn_1x2_t b = __riscv_ztt_mrowzip_ew_f32_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_f32_rdn_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rdn_1x2_t a = __riscv_ztt_mls_rm_f32_rdn_1x2 (in);
  __riscv_ztt_f32_rdn_1x2_t b = __riscv_ztt_mcolunzip_ew_f32_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_f32_rdn_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rdn_1x2_t a = __riscv_ztt_mls_rm_f32_rdn_1x2 (in);
  __riscv_ztt_f32_rdn_1x2_t b = __riscv_ztt_mrowunzip_ew_f32_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_f32_rup_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rup_1x2_t a = __riscv_ztt_mls_rm_f32_rup_1x2 (in);
  __riscv_ztt_f32_rup_1x2_t b = __riscv_ztt_mcolzip_ew_f32_rup_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_f32_rup_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rup_1x2_t a = __riscv_ztt_mls_rm_f32_rup_1x2 (in);
  __riscv_ztt_f32_rup_1x2_t b = __riscv_ztt_mrowzip_ew_f32_rup_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_f32_rup_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rup_1x2_t a = __riscv_ztt_mls_rm_f32_rup_1x2 (in);
  __riscv_ztt_f32_rup_1x2_t b = __riscv_ztt_mcolunzip_ew_f32_rup_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_f32_rup_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rup_1x2_t a = __riscv_ztt_mls_rm_f32_rup_1x2 (in);
  __riscv_ztt_f32_rup_1x2_t b = __riscv_ztt_mrowunzip_ew_f32_rup_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_f32_rmm_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rmm_1x2_t a = __riscv_ztt_mls_rm_f32_rmm_1x2 (in);
  __riscv_ztt_f32_rmm_1x2_t b = __riscv_ztt_mcolzip_ew_f32_rmm_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_f32_rmm_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rmm_1x2_t a = __riscv_ztt_mls_rm_f32_rmm_1x2 (in);
  __riscv_ztt_f32_rmm_1x2_t b = __riscv_ztt_mrowzip_ew_f32_rmm_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_f32_rmm_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rmm_1x2_t a = __riscv_ztt_mls_rm_f32_rmm_1x2 (in);
  __riscv_ztt_f32_rmm_1x2_t b = __riscv_ztt_mcolunzip_ew_f32_rmm_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_f32_rmm_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rmm_1x2_t a = __riscv_ztt_mls_rm_f32_rmm_1x2 (in);
  __riscv_ztt_f32_rmm_1x2_t b = __riscv_ztt_mrowunzip_ew_f32_rmm_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_f32_rno_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rno_1x2_t a = __riscv_ztt_mls_rm_f32_rno_1x2 (in);
  __riscv_ztt_f32_rno_1x2_t b = __riscv_ztt_mcolzip_ew_f32_rno_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_f32_rno_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rno_1x2_t a = __riscv_ztt_mls_rm_f32_rno_1x2 (in);
  __riscv_ztt_f32_rno_1x2_t b = __riscv_ztt_mrowzip_ew_f32_rno_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_f32_rno_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rno_1x2_t a = __riscv_ztt_mls_rm_f32_rno_1x2 (in);
  __riscv_ztt_f32_rno_1x2_t b = __riscv_ztt_mcolunzip_ew_f32_rno_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_f32_rno_live (float *out, const float *in, float *old)
{
  __riscv_ztt_f32_rno_1x2_t a = __riscv_ztt_mls_rm_f32_rno_1x2 (in);
  __riscv_ztt_f32_rno_1x2_t b = __riscv_ztt_mrowunzip_ew_f32_rno_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_f64_rne_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rne_1x2_t a = __riscv_ztt_mls_rm_f64_rne_1x2 (in);
  __riscv_ztt_f64_rne_1x2_t b = __riscv_ztt_mcolzip_ew_f64_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_f64_rne_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rne_1x2_t a = __riscv_ztt_mls_rm_f64_rne_1x2 (in);
  __riscv_ztt_f64_rne_1x2_t b = __riscv_ztt_mrowzip_ew_f64_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_f64_rne_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rne_1x2_t a = __riscv_ztt_mls_rm_f64_rne_1x2 (in);
  __riscv_ztt_f64_rne_1x2_t b = __riscv_ztt_mcolunzip_ew_f64_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_f64_rne_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rne_1x2_t a = __riscv_ztt_mls_rm_f64_rne_1x2 (in);
  __riscv_ztt_f64_rne_1x2_t b = __riscv_ztt_mrowunzip_ew_f64_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_f64_rtz_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rtz_1x2_t a = __riscv_ztt_mls_rm_f64_rtz_1x2 (in);
  __riscv_ztt_f64_rtz_1x2_t b = __riscv_ztt_mcolzip_ew_f64_rtz_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_f64_rtz_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rtz_1x2_t a = __riscv_ztt_mls_rm_f64_rtz_1x2 (in);
  __riscv_ztt_f64_rtz_1x2_t b = __riscv_ztt_mrowzip_ew_f64_rtz_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_f64_rtz_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rtz_1x2_t a = __riscv_ztt_mls_rm_f64_rtz_1x2 (in);
  __riscv_ztt_f64_rtz_1x2_t b = __riscv_ztt_mcolunzip_ew_f64_rtz_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_f64_rtz_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rtz_1x2_t a = __riscv_ztt_mls_rm_f64_rtz_1x2 (in);
  __riscv_ztt_f64_rtz_1x2_t b = __riscv_ztt_mrowunzip_ew_f64_rtz_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_f64_rdn_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rdn_1x2_t a = __riscv_ztt_mls_rm_f64_rdn_1x2 (in);
  __riscv_ztt_f64_rdn_1x2_t b = __riscv_ztt_mcolzip_ew_f64_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_f64_rdn_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rdn_1x2_t a = __riscv_ztt_mls_rm_f64_rdn_1x2 (in);
  __riscv_ztt_f64_rdn_1x2_t b = __riscv_ztt_mrowzip_ew_f64_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_f64_rdn_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rdn_1x2_t a = __riscv_ztt_mls_rm_f64_rdn_1x2 (in);
  __riscv_ztt_f64_rdn_1x2_t b = __riscv_ztt_mcolunzip_ew_f64_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_f64_rdn_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rdn_1x2_t a = __riscv_ztt_mls_rm_f64_rdn_1x2 (in);
  __riscv_ztt_f64_rdn_1x2_t b = __riscv_ztt_mrowunzip_ew_f64_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_f64_rup_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rup_1x2_t a = __riscv_ztt_mls_rm_f64_rup_1x2 (in);
  __riscv_ztt_f64_rup_1x2_t b = __riscv_ztt_mcolzip_ew_f64_rup_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_f64_rup_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rup_1x2_t a = __riscv_ztt_mls_rm_f64_rup_1x2 (in);
  __riscv_ztt_f64_rup_1x2_t b = __riscv_ztt_mrowzip_ew_f64_rup_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_f64_rup_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rup_1x2_t a = __riscv_ztt_mls_rm_f64_rup_1x2 (in);
  __riscv_ztt_f64_rup_1x2_t b = __riscv_ztt_mcolunzip_ew_f64_rup_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_f64_rup_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rup_1x2_t a = __riscv_ztt_mls_rm_f64_rup_1x2 (in);
  __riscv_ztt_f64_rup_1x2_t b = __riscv_ztt_mrowunzip_ew_f64_rup_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_f64_rmm_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rmm_1x2_t a = __riscv_ztt_mls_rm_f64_rmm_1x2 (in);
  __riscv_ztt_f64_rmm_1x2_t b = __riscv_ztt_mcolzip_ew_f64_rmm_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_f64_rmm_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rmm_1x2_t a = __riscv_ztt_mls_rm_f64_rmm_1x2 (in);
  __riscv_ztt_f64_rmm_1x2_t b = __riscv_ztt_mrowzip_ew_f64_rmm_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_f64_rmm_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rmm_1x2_t a = __riscv_ztt_mls_rm_f64_rmm_1x2 (in);
  __riscv_ztt_f64_rmm_1x2_t b = __riscv_ztt_mcolunzip_ew_f64_rmm_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_f64_rmm_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rmm_1x2_t a = __riscv_ztt_mls_rm_f64_rmm_1x2 (in);
  __riscv_ztt_f64_rmm_1x2_t b = __riscv_ztt_mrowunzip_ew_f64_rmm_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_f64_rno_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rno_1x2_t a = __riscv_ztt_mls_rm_f64_rno_1x2 (in);
  __riscv_ztt_f64_rno_1x2_t b = __riscv_ztt_mcolzip_ew_f64_rno_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_f64_rno_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rno_1x2_t a = __riscv_ztt_mls_rm_f64_rno_1x2 (in);
  __riscv_ztt_f64_rno_1x2_t b = __riscv_ztt_mrowzip_ew_f64_rno_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_f64_rno_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rno_1x2_t a = __riscv_ztt_mls_rm_f64_rno_1x2 (in);
  __riscv_ztt_f64_rno_1x2_t b = __riscv_ztt_mcolunzip_ew_f64_rno_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_f64_rno_live (double *out, const double *in, double *old)
{
  __riscv_ztt_f64_rno_1x2_t a = __riscv_ztt_mls_rm_f64_rno_1x2 (in);
  __riscv_ztt_f64_rno_1x2_t b = __riscv_ztt_mrowunzip_ew_f64_rno_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i8_rnu_dead (int8_t *out, const int8_t *in)
{
  __riscv_ztt_i8_rnu_1x2_t a = __riscv_ztt_mls_rm_i8_rnu_1x2 (in);
  __riscv_ztt_i8_rnu_1x2_t b = __riscv_ztt_mcolzip_ew_i8_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
void mcolzip_ew_i8_rne_dead (int8_t *out, const int8_t *in)
{
  __riscv_ztt_i8_rne_1x2_t a = __riscv_ztt_mls_rm_i8_rne_1x2 (in);
  __riscv_ztt_i8_rne_1x2_t b = __riscv_ztt_mcolzip_ew_i8_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
void mcolzip_ew_u8_rnu_dead (uint8_t *out, const uint8_t *in)
{
  __riscv_ztt_u8_rnu_1x2_t a = __riscv_ztt_mls_rm_u8_rnu_1x2 (in);
  __riscv_ztt_u8_rnu_1x2_t b = __riscv_ztt_mcolzip_ew_u8_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
void mcolzip_ew_u8_rne_dead (uint8_t *out, const uint8_t *in)
{
  __riscv_ztt_u8_rne_1x2_t a = __riscv_ztt_mls_rm_u8_rne_1x2 (in);
  __riscv_ztt_u8_rne_1x2_t b = __riscv_ztt_mcolzip_ew_u8_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
void mcolzip_ew_i16_rnu_dead (int16_t *out, const int16_t *in)
{
  __riscv_ztt_i16_rnu_1x2_t a = __riscv_ztt_mls_rm_i16_rnu_1x2 (in);
  __riscv_ztt_i16_rnu_1x2_t b = __riscv_ztt_mcolzip_ew_i16_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
void mcolzip_ew_i16_rne_dead (int16_t *out, const int16_t *in)
{
  __riscv_ztt_i16_rne_1x2_t a = __riscv_ztt_mls_rm_i16_rne_1x2 (in);
  __riscv_ztt_i16_rne_1x2_t b = __riscv_ztt_mcolzip_ew_i16_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
void mcolzip_ew_u16_rnu_dead (uint16_t *out, const uint16_t *in)
{
  __riscv_ztt_u16_rnu_1x2_t a = __riscv_ztt_mls_rm_u16_rnu_1x2 (in);
  __riscv_ztt_u16_rnu_1x2_t b = __riscv_ztt_mcolzip_ew_u16_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
void mcolzip_ew_u16_rne_dead (uint16_t *out, const uint16_t *in)
{
  __riscv_ztt_u16_rne_1x2_t a = __riscv_ztt_mls_rm_u16_rne_1x2 (in);
  __riscv_ztt_u16_rne_1x2_t b = __riscv_ztt_mcolzip_ew_u16_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
void mcolzip_ew_i32_rnu_dead (int32_t *out, const int32_t *in)
{
  __riscv_ztt_i32_rnu_1x2_t a = __riscv_ztt_mls_rm_i32_rnu_1x2 (in);
  __riscv_ztt_i32_rnu_1x2_t b = __riscv_ztt_mcolzip_ew_i32_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
void mcolzip_ew_i32_rne_dead (int32_t *out, const int32_t *in)
{
  __riscv_ztt_i32_rne_1x2_t a = __riscv_ztt_mls_rm_i32_rne_1x2 (in);
  __riscv_ztt_i32_rne_1x2_t b = __riscv_ztt_mcolzip_ew_i32_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
void mcolzip_ew_u32_rnu_dead (uint32_t *out, const uint32_t *in)
{
  __riscv_ztt_u32_rnu_1x2_t a = __riscv_ztt_mls_rm_u32_rnu_1x2 (in);
  __riscv_ztt_u32_rnu_1x2_t b = __riscv_ztt_mcolzip_ew_u32_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
void mcolzip_ew_u32_rne_dead (uint32_t *out, const uint32_t *in)
{
  __riscv_ztt_u32_rne_1x2_t a = __riscv_ztt_mls_rm_u32_rne_1x2 (in);
  __riscv_ztt_u32_rne_1x2_t b = __riscv_ztt_mcolzip_ew_u32_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
void mcolzip_ew_i64_rnu_dead (int64_t *out, const int64_t *in)
{
  __riscv_ztt_i64_rnu_1x2_t a = __riscv_ztt_mls_rm_i64_rnu_1x2 (in);
  __riscv_ztt_i64_rnu_1x2_t b = __riscv_ztt_mcolzip_ew_i64_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
void mcolzip_ew_i64_rne_dead (int64_t *out, const int64_t *in)
{
  __riscv_ztt_i64_rne_1x2_t a = __riscv_ztt_mls_rm_i64_rne_1x2 (in);
  __riscv_ztt_i64_rne_1x2_t b = __riscv_ztt_mcolzip_ew_i64_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
void mcolzip_ew_u64_rnu_dead (uint64_t *out, const uint64_t *in)
{
  __riscv_ztt_u64_rnu_1x2_t a = __riscv_ztt_mls_rm_u64_rnu_1x2 (in);
  __riscv_ztt_u64_rnu_1x2_t b = __riscv_ztt_mcolzip_ew_u64_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
void mcolzip_ew_u64_rne_dead (uint64_t *out, const uint64_t *in)
{
  __riscv_ztt_u64_rne_1x2_t a = __riscv_ztt_mls_rm_u64_rne_1x2 (in);
  __riscv_ztt_u64_rne_1x2_t b = __riscv_ztt_mcolzip_ew_u64_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
void mcolzip_ew_f16_rne_dead (_Float16 *out, const _Float16 *in)
{
  __riscv_ztt_f16_rne_1x2_t a = __riscv_ztt_mls_rm_f16_rne_1x2 (in);
  __riscv_ztt_f16_rne_1x2_t b = __riscv_ztt_mcolzip_ew_f16_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
void mcolzip_ew_bf16_rne_dead (__bf16 *out, const __bf16 *in)
{
  __riscv_ztt_bf16_rne_1x2_t a = __riscv_ztt_mls_rm_bf16_rne_1x2 (in);
  __riscv_ztt_bf16_rne_1x2_t b = __riscv_ztt_mcolzip_ew_bf16_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
void mcolzip_ew_f32_rne_dead (float *out, const float *in)
{
  __riscv_ztt_f32_rne_1x2_t a = __riscv_ztt_mls_rm_f32_rne_1x2 (in);
  __riscv_ztt_f32_rne_1x2_t b = __riscv_ztt_mcolzip_ew_f32_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
void mcolzip_ew_f64_rne_dead (double *out, const double *in)
{
  __riscv_ztt_f64_rne_1x2_t a = __riscv_ztt_mls_rm_f64_rne_1x2 (in);
  __riscv_ztt_f64_rne_1x2_t b = __riscv_ztt_mcolzip_ew_f64_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
