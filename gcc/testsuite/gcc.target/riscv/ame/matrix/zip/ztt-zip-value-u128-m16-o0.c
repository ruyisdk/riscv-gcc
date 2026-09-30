/* { dg-do assemble } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a16" { target rv32 } } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a16" { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>
void mcolzip_ew_i128_rnu_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rnu_1x2_t a = __riscv_ztt_mls_rm_i128_rnu_1x2 (in);
  __riscv_ztt_i128_rnu_1x2_t b = __riscv_ztt_mcolzip_ew_i128_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i128_rnu_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rnu_1x2_t a = __riscv_ztt_mls_rm_i128_rnu_1x2 (in);
  __riscv_ztt_i128_rnu_1x2_t b = __riscv_ztt_mrowzip_ew_i128_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i128_rnu_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rnu_1x2_t a = __riscv_ztt_mls_rm_i128_rnu_1x2 (in);
  __riscv_ztt_i128_rnu_1x2_t b = __riscv_ztt_mcolunzip_ew_i128_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i128_rnu_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rnu_1x2_t a = __riscv_ztt_mls_rm_i128_rnu_1x2 (in);
  __riscv_ztt_i128_rnu_1x2_t b = __riscv_ztt_mrowunzip_ew_i128_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i128_rnu_sat_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_i128_rnu_sat_1x2 (in);
  __riscv_ztt_i128_rnu_sat_1x2_t b = __riscv_ztt_mcolzip_ew_i128_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i128_rnu_sat_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_i128_rnu_sat_1x2 (in);
  __riscv_ztt_i128_rnu_sat_1x2_t b = __riscv_ztt_mrowzip_ew_i128_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i128_rnu_sat_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_i128_rnu_sat_1x2 (in);
  __riscv_ztt_i128_rnu_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_i128_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i128_rnu_sat_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_i128_rnu_sat_1x2 (in);
  __riscv_ztt_i128_rnu_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_i128_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i128_rne_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rne_1x2_t a = __riscv_ztt_mls_rm_i128_rne_1x2 (in);
  __riscv_ztt_i128_rne_1x2_t b = __riscv_ztt_mcolzip_ew_i128_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i128_rne_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rne_1x2_t a = __riscv_ztt_mls_rm_i128_rne_1x2 (in);
  __riscv_ztt_i128_rne_1x2_t b = __riscv_ztt_mrowzip_ew_i128_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i128_rne_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rne_1x2_t a = __riscv_ztt_mls_rm_i128_rne_1x2 (in);
  __riscv_ztt_i128_rne_1x2_t b = __riscv_ztt_mcolunzip_ew_i128_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i128_rne_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rne_1x2_t a = __riscv_ztt_mls_rm_i128_rne_1x2 (in);
  __riscv_ztt_i128_rne_1x2_t b = __riscv_ztt_mrowunzip_ew_i128_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i128_rne_sat_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rne_sat_1x2_t a = __riscv_ztt_mls_rm_i128_rne_sat_1x2 (in);
  __riscv_ztt_i128_rne_sat_1x2_t b = __riscv_ztt_mcolzip_ew_i128_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i128_rne_sat_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rne_sat_1x2_t a = __riscv_ztt_mls_rm_i128_rne_sat_1x2 (in);
  __riscv_ztt_i128_rne_sat_1x2_t b = __riscv_ztt_mrowzip_ew_i128_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i128_rne_sat_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rne_sat_1x2_t a = __riscv_ztt_mls_rm_i128_rne_sat_1x2 (in);
  __riscv_ztt_i128_rne_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_i128_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i128_rne_sat_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rne_sat_1x2_t a = __riscv_ztt_mls_rm_i128_rne_sat_1x2 (in);
  __riscv_ztt_i128_rne_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_i128_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i128_rdn_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rdn_1x2_t a = __riscv_ztt_mls_rm_i128_rdn_1x2 (in);
  __riscv_ztt_i128_rdn_1x2_t b = __riscv_ztt_mcolzip_ew_i128_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i128_rdn_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rdn_1x2_t a = __riscv_ztt_mls_rm_i128_rdn_1x2 (in);
  __riscv_ztt_i128_rdn_1x2_t b = __riscv_ztt_mrowzip_ew_i128_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i128_rdn_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rdn_1x2_t a = __riscv_ztt_mls_rm_i128_rdn_1x2 (in);
  __riscv_ztt_i128_rdn_1x2_t b = __riscv_ztt_mcolunzip_ew_i128_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i128_rdn_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rdn_1x2_t a = __riscv_ztt_mls_rm_i128_rdn_1x2 (in);
  __riscv_ztt_i128_rdn_1x2_t b = __riscv_ztt_mrowunzip_ew_i128_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i128_rdn_sat_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_i128_rdn_sat_1x2 (in);
  __riscv_ztt_i128_rdn_sat_1x2_t b = __riscv_ztt_mcolzip_ew_i128_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i128_rdn_sat_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_i128_rdn_sat_1x2 (in);
  __riscv_ztt_i128_rdn_sat_1x2_t b = __riscv_ztt_mrowzip_ew_i128_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i128_rdn_sat_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_i128_rdn_sat_1x2 (in);
  __riscv_ztt_i128_rdn_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_i128_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i128_rdn_sat_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_i128_rdn_sat_1x2 (in);
  __riscv_ztt_i128_rdn_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_i128_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i128_rod_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rod_1x2_t a = __riscv_ztt_mls_rm_i128_rod_1x2 (in);
  __riscv_ztt_i128_rod_1x2_t b = __riscv_ztt_mcolzip_ew_i128_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i128_rod_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rod_1x2_t a = __riscv_ztt_mls_rm_i128_rod_1x2 (in);
  __riscv_ztt_i128_rod_1x2_t b = __riscv_ztt_mrowzip_ew_i128_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i128_rod_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rod_1x2_t a = __riscv_ztt_mls_rm_i128_rod_1x2 (in);
  __riscv_ztt_i128_rod_1x2_t b = __riscv_ztt_mcolunzip_ew_i128_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i128_rod_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rod_1x2_t a = __riscv_ztt_mls_rm_i128_rod_1x2 (in);
  __riscv_ztt_i128_rod_1x2_t b = __riscv_ztt_mrowunzip_ew_i128_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i128_rod_sat_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rod_sat_1x2_t a = __riscv_ztt_mls_rm_i128_rod_sat_1x2 (in);
  __riscv_ztt_i128_rod_sat_1x2_t b = __riscv_ztt_mcolzip_ew_i128_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_i128_rod_sat_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rod_sat_1x2_t a = __riscv_ztt_mls_rm_i128_rod_sat_1x2 (in);
  __riscv_ztt_i128_rod_sat_1x2_t b = __riscv_ztt_mrowzip_ew_i128_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_i128_rod_sat_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rod_sat_1x2_t a = __riscv_ztt_mls_rm_i128_rod_sat_1x2 (in);
  __riscv_ztt_i128_rod_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_i128_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_i128_rod_sat_live (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in, __riscv_ztt_i128_storage_t *old)
{
  __riscv_ztt_i128_rod_sat_1x2_t a = __riscv_ztt_mls_rm_i128_rod_sat_1x2 (in);
  __riscv_ztt_i128_rod_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_i128_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u128_rnu_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rnu_1x2_t a = __riscv_ztt_mls_rm_u128_rnu_1x2 (in);
  __riscv_ztt_u128_rnu_1x2_t b = __riscv_ztt_mcolzip_ew_u128_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u128_rnu_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rnu_1x2_t a = __riscv_ztt_mls_rm_u128_rnu_1x2 (in);
  __riscv_ztt_u128_rnu_1x2_t b = __riscv_ztt_mrowzip_ew_u128_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u128_rnu_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rnu_1x2_t a = __riscv_ztt_mls_rm_u128_rnu_1x2 (in);
  __riscv_ztt_u128_rnu_1x2_t b = __riscv_ztt_mcolunzip_ew_u128_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u128_rnu_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rnu_1x2_t a = __riscv_ztt_mls_rm_u128_rnu_1x2 (in);
  __riscv_ztt_u128_rnu_1x2_t b = __riscv_ztt_mrowunzip_ew_u128_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u128_rnu_sat_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_u128_rnu_sat_1x2 (in);
  __riscv_ztt_u128_rnu_sat_1x2_t b = __riscv_ztt_mcolzip_ew_u128_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u128_rnu_sat_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_u128_rnu_sat_1x2 (in);
  __riscv_ztt_u128_rnu_sat_1x2_t b = __riscv_ztt_mrowzip_ew_u128_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u128_rnu_sat_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_u128_rnu_sat_1x2 (in);
  __riscv_ztt_u128_rnu_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_u128_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u128_rnu_sat_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rnu_sat_1x2_t a = __riscv_ztt_mls_rm_u128_rnu_sat_1x2 (in);
  __riscv_ztt_u128_rnu_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_u128_rnu_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u128_rne_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rne_1x2_t a = __riscv_ztt_mls_rm_u128_rne_1x2 (in);
  __riscv_ztt_u128_rne_1x2_t b = __riscv_ztt_mcolzip_ew_u128_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u128_rne_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rne_1x2_t a = __riscv_ztt_mls_rm_u128_rne_1x2 (in);
  __riscv_ztt_u128_rne_1x2_t b = __riscv_ztt_mrowzip_ew_u128_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u128_rne_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rne_1x2_t a = __riscv_ztt_mls_rm_u128_rne_1x2 (in);
  __riscv_ztt_u128_rne_1x2_t b = __riscv_ztt_mcolunzip_ew_u128_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u128_rne_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rne_1x2_t a = __riscv_ztt_mls_rm_u128_rne_1x2 (in);
  __riscv_ztt_u128_rne_1x2_t b = __riscv_ztt_mrowunzip_ew_u128_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u128_rne_sat_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rne_sat_1x2_t a = __riscv_ztt_mls_rm_u128_rne_sat_1x2 (in);
  __riscv_ztt_u128_rne_sat_1x2_t b = __riscv_ztt_mcolzip_ew_u128_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u128_rne_sat_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rne_sat_1x2_t a = __riscv_ztt_mls_rm_u128_rne_sat_1x2 (in);
  __riscv_ztt_u128_rne_sat_1x2_t b = __riscv_ztt_mrowzip_ew_u128_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u128_rne_sat_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rne_sat_1x2_t a = __riscv_ztt_mls_rm_u128_rne_sat_1x2 (in);
  __riscv_ztt_u128_rne_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_u128_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u128_rne_sat_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rne_sat_1x2_t a = __riscv_ztt_mls_rm_u128_rne_sat_1x2 (in);
  __riscv_ztt_u128_rne_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_u128_rne_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u128_rdn_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rdn_1x2_t a = __riscv_ztt_mls_rm_u128_rdn_1x2 (in);
  __riscv_ztt_u128_rdn_1x2_t b = __riscv_ztt_mcolzip_ew_u128_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u128_rdn_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rdn_1x2_t a = __riscv_ztt_mls_rm_u128_rdn_1x2 (in);
  __riscv_ztt_u128_rdn_1x2_t b = __riscv_ztt_mrowzip_ew_u128_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u128_rdn_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rdn_1x2_t a = __riscv_ztt_mls_rm_u128_rdn_1x2 (in);
  __riscv_ztt_u128_rdn_1x2_t b = __riscv_ztt_mcolunzip_ew_u128_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u128_rdn_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rdn_1x2_t a = __riscv_ztt_mls_rm_u128_rdn_1x2 (in);
  __riscv_ztt_u128_rdn_1x2_t b = __riscv_ztt_mrowunzip_ew_u128_rdn_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u128_rdn_sat_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_u128_rdn_sat_1x2 (in);
  __riscv_ztt_u128_rdn_sat_1x2_t b = __riscv_ztt_mcolzip_ew_u128_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u128_rdn_sat_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_u128_rdn_sat_1x2 (in);
  __riscv_ztt_u128_rdn_sat_1x2_t b = __riscv_ztt_mrowzip_ew_u128_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u128_rdn_sat_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_u128_rdn_sat_1x2 (in);
  __riscv_ztt_u128_rdn_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_u128_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u128_rdn_sat_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rdn_sat_1x2_t a = __riscv_ztt_mls_rm_u128_rdn_sat_1x2 (in);
  __riscv_ztt_u128_rdn_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_u128_rdn_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u128_rod_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rod_1x2_t a = __riscv_ztt_mls_rm_u128_rod_1x2 (in);
  __riscv_ztt_u128_rod_1x2_t b = __riscv_ztt_mcolzip_ew_u128_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u128_rod_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rod_1x2_t a = __riscv_ztt_mls_rm_u128_rod_1x2 (in);
  __riscv_ztt_u128_rod_1x2_t b = __riscv_ztt_mrowzip_ew_u128_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u128_rod_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rod_1x2_t a = __riscv_ztt_mls_rm_u128_rod_1x2 (in);
  __riscv_ztt_u128_rod_1x2_t b = __riscv_ztt_mcolunzip_ew_u128_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u128_rod_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rod_1x2_t a = __riscv_ztt_mls_rm_u128_rod_1x2 (in);
  __riscv_ztt_u128_rod_1x2_t b = __riscv_ztt_mrowunzip_ew_u128_rod_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_u128_rod_sat_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rod_sat_1x2_t a = __riscv_ztt_mls_rm_u128_rod_sat_1x2 (in);
  __riscv_ztt_u128_rod_sat_1x2_t b = __riscv_ztt_mcolzip_ew_u128_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowzip_ew_u128_rod_sat_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rod_sat_1x2_t a = __riscv_ztt_mls_rm_u128_rod_sat_1x2 (in);
  __riscv_ztt_u128_rod_sat_1x2_t b = __riscv_ztt_mrowzip_ew_u128_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolunzip_ew_u128_rod_sat_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rod_sat_1x2_t a = __riscv_ztt_mls_rm_u128_rod_sat_1x2 (in);
  __riscv_ztt_u128_rod_sat_1x2_t b = __riscv_ztt_mcolunzip_ew_u128_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mrowunzip_ew_u128_rod_sat_live (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in, __riscv_ztt_u128_storage_t *old)
{
  __riscv_ztt_u128_rod_sat_1x2_t a = __riscv_ztt_mls_rm_u128_rod_sat_1x2 (in);
  __riscv_ztt_u128_rod_sat_1x2_t b = __riscv_ztt_mrowunzip_ew_u128_rod_sat_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (old, a);
}
void mcolzip_ew_i128_rnu_dead (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in)
{
  __riscv_ztt_i128_rnu_1x2_t a = __riscv_ztt_mls_rm_i128_rnu_1x2 (in);
  __riscv_ztt_i128_rnu_1x2_t b = __riscv_ztt_mcolzip_ew_i128_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
void mcolzip_ew_i128_rne_dead (__riscv_ztt_i128_storage_t *out, const __riscv_ztt_i128_storage_t *in)
{
  __riscv_ztt_i128_rne_1x2_t a = __riscv_ztt_mls_rm_i128_rne_1x2 (in);
  __riscv_ztt_i128_rne_1x2_t b = __riscv_ztt_mcolzip_ew_i128_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
void mcolzip_ew_u128_rnu_dead (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in)
{
  __riscv_ztt_u128_rnu_1x2_t a = __riscv_ztt_mls_rm_u128_rnu_1x2 (in);
  __riscv_ztt_u128_rnu_1x2_t b = __riscv_ztt_mcolzip_ew_u128_rnu_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
void mcolzip_ew_u128_rne_dead (__riscv_ztt_u128_storage_t *out, const __riscv_ztt_u128_storage_t *in)
{
  __riscv_ztt_u128_rne_1x2_t a = __riscv_ztt_mls_rm_u128_rne_1x2 (in);
  __riscv_ztt_u128_rne_1x2_t b = __riscv_ztt_mcolzip_ew_u128_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
