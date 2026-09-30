/* { dg-do assemble } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u64-m16-a16" { target rv32 } } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u64-m16-a16" { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>
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
void mcolzip_ew_f64_rne_dead (double *out, const double *in)
{
  __riscv_ztt_f64_rne_1x2_t a = __riscv_ztt_mls_rm_f64_rne_1x2 (in);
  __riscv_ztt_f64_rne_1x2_t b = __riscv_ztt_mcolzip_ew_f64_rne_1x2 (a);
  __riscv_ztt_mss_rm (out, b);
}
