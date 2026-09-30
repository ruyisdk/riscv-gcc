/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u64-m32-a16 " { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u64-m32-a16 " { target rv64 } } */
#include <stdint.h>
#include <stddef.h>
#include <riscv_ztt.h>
void align_load_i64_rnu_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_1x1_t value = __riscv_ztt_mls_tst_i64_rnu_1x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rnu_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_1x1_t value = __riscv_ztt_mls_rm_i64_rnu_1x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rnu_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_1x1_t value = __riscv_ztt_mls_tst_i64_rnu_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rnu_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_1x2_t value = __riscv_ztt_mls_tst_i64_rnu_1x2 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rnu_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_1x2_t value = __riscv_ztt_mls_rm_i64_rnu_1x2 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rnu_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_1x2_t value = __riscv_ztt_mls_tst_i64_rnu_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rnu_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_2x1_t value = __riscv_ztt_mls_tst_i64_rnu_2x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rnu_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_2x1_t value = __riscv_ztt_mls_rm_i64_rnu_2x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rnu_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_2x1_t value = __riscv_ztt_mls_tst_i64_rnu_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rnu_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_1x4_t value = __riscv_ztt_mls_tst_i64_rnu_1x4 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rnu_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_1x4_t value = __riscv_ztt_mls_rm_i64_rnu_1x4 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rnu_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_1x4_t value = __riscv_ztt_mls_tst_i64_rnu_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rnu_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_4x1_t value = __riscv_ztt_mls_tst_i64_rnu_4x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rnu_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_4x1_t value = __riscv_ztt_mls_rm_i64_rnu_4x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rnu_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_4x1_t value = __riscv_ztt_mls_tst_i64_rnu_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rnu_sat_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_sat_1x1_t value = __riscv_ztt_mls_tst_i64_rnu_sat_1x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rnu_sat_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_sat_1x1_t value = __riscv_ztt_mls_rm_i64_rnu_sat_1x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rnu_sat_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_sat_1x1_t value = __riscv_ztt_mls_tst_i64_rnu_sat_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rnu_sat_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_sat_1x2_t value = __riscv_ztt_mls_tst_i64_rnu_sat_1x2 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rnu_sat_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_sat_1x2_t value = __riscv_ztt_mls_rm_i64_rnu_sat_1x2 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rnu_sat_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_sat_1x2_t value = __riscv_ztt_mls_tst_i64_rnu_sat_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rnu_sat_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_sat_2x1_t value = __riscv_ztt_mls_tst_i64_rnu_sat_2x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rnu_sat_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_sat_2x1_t value = __riscv_ztt_mls_rm_i64_rnu_sat_2x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rnu_sat_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_sat_2x1_t value = __riscv_ztt_mls_tst_i64_rnu_sat_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rnu_sat_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_sat_1x4_t value = __riscv_ztt_mls_tst_i64_rnu_sat_1x4 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rnu_sat_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_sat_1x4_t value = __riscv_ztt_mls_rm_i64_rnu_sat_1x4 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rnu_sat_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_sat_1x4_t value = __riscv_ztt_mls_tst_i64_rnu_sat_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rnu_sat_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_sat_4x1_t value = __riscv_ztt_mls_tst_i64_rnu_sat_4x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rnu_sat_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_sat_4x1_t value = __riscv_ztt_mls_rm_i64_rnu_sat_4x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rnu_sat_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rnu_sat_4x1_t value = __riscv_ztt_mls_tst_i64_rnu_sat_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rne_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_1x1_t value = __riscv_ztt_mls_tst_i64_rne_1x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rne_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_1x1_t value = __riscv_ztt_mls_rm_i64_rne_1x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rne_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_1x1_t value = __riscv_ztt_mls_tst_i64_rne_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rne_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_1x2_t value = __riscv_ztt_mls_tst_i64_rne_1x2 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rne_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_1x2_t value = __riscv_ztt_mls_rm_i64_rne_1x2 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rne_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_1x2_t value = __riscv_ztt_mls_tst_i64_rne_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rne_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_2x1_t value = __riscv_ztt_mls_tst_i64_rne_2x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rne_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_2x1_t value = __riscv_ztt_mls_rm_i64_rne_2x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rne_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_2x1_t value = __riscv_ztt_mls_tst_i64_rne_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rne_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_1x4_t value = __riscv_ztt_mls_tst_i64_rne_1x4 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rne_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_1x4_t value = __riscv_ztt_mls_rm_i64_rne_1x4 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rne_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_1x4_t value = __riscv_ztt_mls_tst_i64_rne_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rne_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_4x1_t value = __riscv_ztt_mls_tst_i64_rne_4x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rne_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_4x1_t value = __riscv_ztt_mls_rm_i64_rne_4x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rne_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_4x1_t value = __riscv_ztt_mls_tst_i64_rne_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rne_sat_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_sat_1x1_t value = __riscv_ztt_mls_tst_i64_rne_sat_1x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rne_sat_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_sat_1x1_t value = __riscv_ztt_mls_rm_i64_rne_sat_1x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rne_sat_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_sat_1x1_t value = __riscv_ztt_mls_tst_i64_rne_sat_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rne_sat_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_sat_1x2_t value = __riscv_ztt_mls_tst_i64_rne_sat_1x2 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rne_sat_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_sat_1x2_t value = __riscv_ztt_mls_rm_i64_rne_sat_1x2 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rne_sat_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_sat_1x2_t value = __riscv_ztt_mls_tst_i64_rne_sat_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rne_sat_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_sat_2x1_t value = __riscv_ztt_mls_tst_i64_rne_sat_2x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rne_sat_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_sat_2x1_t value = __riscv_ztt_mls_rm_i64_rne_sat_2x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rne_sat_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_sat_2x1_t value = __riscv_ztt_mls_tst_i64_rne_sat_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rne_sat_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_sat_1x4_t value = __riscv_ztt_mls_tst_i64_rne_sat_1x4 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rne_sat_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_sat_1x4_t value = __riscv_ztt_mls_rm_i64_rne_sat_1x4 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rne_sat_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_sat_1x4_t value = __riscv_ztt_mls_tst_i64_rne_sat_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rne_sat_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_sat_4x1_t value = __riscv_ztt_mls_tst_i64_rne_sat_4x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rne_sat_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_sat_4x1_t value = __riscv_ztt_mls_rm_i64_rne_sat_4x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rne_sat_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rne_sat_4x1_t value = __riscv_ztt_mls_tst_i64_rne_sat_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rdn_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_1x1_t value = __riscv_ztt_mls_tst_i64_rdn_1x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rdn_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_1x1_t value = __riscv_ztt_mls_rm_i64_rdn_1x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rdn_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_1x1_t value = __riscv_ztt_mls_tst_i64_rdn_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rdn_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_1x2_t value = __riscv_ztt_mls_tst_i64_rdn_1x2 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rdn_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_1x2_t value = __riscv_ztt_mls_rm_i64_rdn_1x2 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rdn_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_1x2_t value = __riscv_ztt_mls_tst_i64_rdn_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rdn_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_2x1_t value = __riscv_ztt_mls_tst_i64_rdn_2x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rdn_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_2x1_t value = __riscv_ztt_mls_rm_i64_rdn_2x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rdn_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_2x1_t value = __riscv_ztt_mls_tst_i64_rdn_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rdn_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_1x4_t value = __riscv_ztt_mls_tst_i64_rdn_1x4 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rdn_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_1x4_t value = __riscv_ztt_mls_rm_i64_rdn_1x4 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rdn_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_1x4_t value = __riscv_ztt_mls_tst_i64_rdn_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rdn_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_4x1_t value = __riscv_ztt_mls_tst_i64_rdn_4x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rdn_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_4x1_t value = __riscv_ztt_mls_rm_i64_rdn_4x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rdn_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_4x1_t value = __riscv_ztt_mls_tst_i64_rdn_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rdn_sat_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_sat_1x1_t value = __riscv_ztt_mls_tst_i64_rdn_sat_1x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rdn_sat_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_sat_1x1_t value = __riscv_ztt_mls_rm_i64_rdn_sat_1x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rdn_sat_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_sat_1x1_t value = __riscv_ztt_mls_tst_i64_rdn_sat_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rdn_sat_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_sat_1x2_t value = __riscv_ztt_mls_tst_i64_rdn_sat_1x2 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rdn_sat_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_sat_1x2_t value = __riscv_ztt_mls_rm_i64_rdn_sat_1x2 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rdn_sat_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_sat_1x2_t value = __riscv_ztt_mls_tst_i64_rdn_sat_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rdn_sat_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_sat_2x1_t value = __riscv_ztt_mls_tst_i64_rdn_sat_2x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rdn_sat_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_sat_2x1_t value = __riscv_ztt_mls_rm_i64_rdn_sat_2x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rdn_sat_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_sat_2x1_t value = __riscv_ztt_mls_tst_i64_rdn_sat_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rdn_sat_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_sat_1x4_t value = __riscv_ztt_mls_tst_i64_rdn_sat_1x4 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rdn_sat_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_sat_1x4_t value = __riscv_ztt_mls_rm_i64_rdn_sat_1x4 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rdn_sat_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_sat_1x4_t value = __riscv_ztt_mls_tst_i64_rdn_sat_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rdn_sat_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_sat_4x1_t value = __riscv_ztt_mls_tst_i64_rdn_sat_4x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rdn_sat_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_sat_4x1_t value = __riscv_ztt_mls_rm_i64_rdn_sat_4x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rdn_sat_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rdn_sat_4x1_t value = __riscv_ztt_mls_tst_i64_rdn_sat_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rod_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_1x1_t value = __riscv_ztt_mls_tst_i64_rod_1x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rod_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_1x1_t value = __riscv_ztt_mls_rm_i64_rod_1x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rod_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_1x1_t value = __riscv_ztt_mls_tst_i64_rod_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rod_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_1x2_t value = __riscv_ztt_mls_tst_i64_rod_1x2 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rod_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_1x2_t value = __riscv_ztt_mls_rm_i64_rod_1x2 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rod_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_1x2_t value = __riscv_ztt_mls_tst_i64_rod_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rod_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_2x1_t value = __riscv_ztt_mls_tst_i64_rod_2x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rod_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_2x1_t value = __riscv_ztt_mls_rm_i64_rod_2x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rod_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_2x1_t value = __riscv_ztt_mls_tst_i64_rod_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rod_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_1x4_t value = __riscv_ztt_mls_tst_i64_rod_1x4 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rod_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_1x4_t value = __riscv_ztt_mls_rm_i64_rod_1x4 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rod_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_1x4_t value = __riscv_ztt_mls_tst_i64_rod_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rod_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_4x1_t value = __riscv_ztt_mls_tst_i64_rod_4x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rod_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_4x1_t value = __riscv_ztt_mls_rm_i64_rod_4x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rod_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_4x1_t value = __riscv_ztt_mls_tst_i64_rod_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rod_sat_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_sat_1x1_t value = __riscv_ztt_mls_tst_i64_rod_sat_1x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rod_sat_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_sat_1x1_t value = __riscv_ztt_mls_rm_i64_rod_sat_1x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rod_sat_1x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_sat_1x1_t value = __riscv_ztt_mls_tst_i64_rod_sat_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rod_sat_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_sat_1x2_t value = __riscv_ztt_mls_tst_i64_rod_sat_1x2 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rod_sat_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_sat_1x2_t value = __riscv_ztt_mls_rm_i64_rod_sat_1x2 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rod_sat_1x2 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_sat_1x2_t value = __riscv_ztt_mls_tst_i64_rod_sat_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rod_sat_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_sat_2x1_t value = __riscv_ztt_mls_tst_i64_rod_sat_2x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rod_sat_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_sat_2x1_t value = __riscv_ztt_mls_rm_i64_rod_sat_2x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rod_sat_2x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_sat_2x1_t value = __riscv_ztt_mls_tst_i64_rod_sat_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rod_sat_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_sat_1x4_t value = __riscv_ztt_mls_tst_i64_rod_sat_1x4 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rod_sat_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_sat_1x4_t value = __riscv_ztt_mls_rm_i64_rod_sat_1x4 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rod_sat_1x4 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_sat_1x4_t value = __riscv_ztt_mls_tst_i64_rod_sat_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_i64_rod_sat_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_sat_4x1_t value = __riscv_ztt_mls_tst_i64_rod_sat_4x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_i64_rod_sat_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_sat_4x1_t value = __riscv_ztt_mls_rm_i64_rod_sat_4x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_i64_rod_sat_4x1 (int64_t *out, const int64_t *in, size_t stride)
{
  __riscv_ztt_i64_rod_sat_4x1_t value = __riscv_ztt_mls_tst_i64_rod_sat_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rnu_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_1x1_t value = __riscv_ztt_mls_tst_u64_rnu_1x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rnu_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_1x1_t value = __riscv_ztt_mls_rm_u64_rnu_1x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rnu_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_1x1_t value = __riscv_ztt_mls_tst_u64_rnu_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rnu_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_1x2_t value = __riscv_ztt_mls_tst_u64_rnu_1x2 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rnu_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_1x2_t value = __riscv_ztt_mls_rm_u64_rnu_1x2 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rnu_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_1x2_t value = __riscv_ztt_mls_tst_u64_rnu_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rnu_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_2x1_t value = __riscv_ztt_mls_tst_u64_rnu_2x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rnu_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_2x1_t value = __riscv_ztt_mls_rm_u64_rnu_2x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rnu_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_2x1_t value = __riscv_ztt_mls_tst_u64_rnu_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rnu_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_1x4_t value = __riscv_ztt_mls_tst_u64_rnu_1x4 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rnu_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_1x4_t value = __riscv_ztt_mls_rm_u64_rnu_1x4 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rnu_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_1x4_t value = __riscv_ztt_mls_tst_u64_rnu_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rnu_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_4x1_t value = __riscv_ztt_mls_tst_u64_rnu_4x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rnu_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_4x1_t value = __riscv_ztt_mls_rm_u64_rnu_4x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rnu_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_4x1_t value = __riscv_ztt_mls_tst_u64_rnu_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rnu_sat_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_sat_1x1_t value = __riscv_ztt_mls_tst_u64_rnu_sat_1x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rnu_sat_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_sat_1x1_t value = __riscv_ztt_mls_rm_u64_rnu_sat_1x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rnu_sat_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_sat_1x1_t value = __riscv_ztt_mls_tst_u64_rnu_sat_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rnu_sat_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_sat_1x2_t value = __riscv_ztt_mls_tst_u64_rnu_sat_1x2 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rnu_sat_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_sat_1x2_t value = __riscv_ztt_mls_rm_u64_rnu_sat_1x2 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rnu_sat_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_sat_1x2_t value = __riscv_ztt_mls_tst_u64_rnu_sat_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rnu_sat_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_sat_2x1_t value = __riscv_ztt_mls_tst_u64_rnu_sat_2x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rnu_sat_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_sat_2x1_t value = __riscv_ztt_mls_rm_u64_rnu_sat_2x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rnu_sat_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_sat_2x1_t value = __riscv_ztt_mls_tst_u64_rnu_sat_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rnu_sat_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_sat_1x4_t value = __riscv_ztt_mls_tst_u64_rnu_sat_1x4 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rnu_sat_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_sat_1x4_t value = __riscv_ztt_mls_rm_u64_rnu_sat_1x4 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rnu_sat_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_sat_1x4_t value = __riscv_ztt_mls_tst_u64_rnu_sat_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rnu_sat_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_sat_4x1_t value = __riscv_ztt_mls_tst_u64_rnu_sat_4x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rnu_sat_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_sat_4x1_t value = __riscv_ztt_mls_rm_u64_rnu_sat_4x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rnu_sat_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rnu_sat_4x1_t value = __riscv_ztt_mls_tst_u64_rnu_sat_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rne_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_1x1_t value = __riscv_ztt_mls_tst_u64_rne_1x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rne_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_1x1_t value = __riscv_ztt_mls_rm_u64_rne_1x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rne_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_1x1_t value = __riscv_ztt_mls_tst_u64_rne_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rne_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_1x2_t value = __riscv_ztt_mls_tst_u64_rne_1x2 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rne_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_1x2_t value = __riscv_ztt_mls_rm_u64_rne_1x2 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rne_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_1x2_t value = __riscv_ztt_mls_tst_u64_rne_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rne_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_2x1_t value = __riscv_ztt_mls_tst_u64_rne_2x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rne_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_2x1_t value = __riscv_ztt_mls_rm_u64_rne_2x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rne_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_2x1_t value = __riscv_ztt_mls_tst_u64_rne_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rne_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_1x4_t value = __riscv_ztt_mls_tst_u64_rne_1x4 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rne_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_1x4_t value = __riscv_ztt_mls_rm_u64_rne_1x4 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rne_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_1x4_t value = __riscv_ztt_mls_tst_u64_rne_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rne_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_4x1_t value = __riscv_ztt_mls_tst_u64_rne_4x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rne_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_4x1_t value = __riscv_ztt_mls_rm_u64_rne_4x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rne_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_4x1_t value = __riscv_ztt_mls_tst_u64_rne_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rne_sat_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_sat_1x1_t value = __riscv_ztt_mls_tst_u64_rne_sat_1x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rne_sat_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_sat_1x1_t value = __riscv_ztt_mls_rm_u64_rne_sat_1x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rne_sat_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_sat_1x1_t value = __riscv_ztt_mls_tst_u64_rne_sat_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rne_sat_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_sat_1x2_t value = __riscv_ztt_mls_tst_u64_rne_sat_1x2 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rne_sat_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_sat_1x2_t value = __riscv_ztt_mls_rm_u64_rne_sat_1x2 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rne_sat_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_sat_1x2_t value = __riscv_ztt_mls_tst_u64_rne_sat_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rne_sat_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_sat_2x1_t value = __riscv_ztt_mls_tst_u64_rne_sat_2x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rne_sat_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_sat_2x1_t value = __riscv_ztt_mls_rm_u64_rne_sat_2x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rne_sat_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_sat_2x1_t value = __riscv_ztt_mls_tst_u64_rne_sat_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rne_sat_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_sat_1x4_t value = __riscv_ztt_mls_tst_u64_rne_sat_1x4 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rne_sat_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_sat_1x4_t value = __riscv_ztt_mls_rm_u64_rne_sat_1x4 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rne_sat_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_sat_1x4_t value = __riscv_ztt_mls_tst_u64_rne_sat_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rne_sat_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_sat_4x1_t value = __riscv_ztt_mls_tst_u64_rne_sat_4x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rne_sat_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_sat_4x1_t value = __riscv_ztt_mls_rm_u64_rne_sat_4x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rne_sat_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rne_sat_4x1_t value = __riscv_ztt_mls_tst_u64_rne_sat_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rdn_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_1x1_t value = __riscv_ztt_mls_tst_u64_rdn_1x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rdn_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_1x1_t value = __riscv_ztt_mls_rm_u64_rdn_1x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rdn_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_1x1_t value = __riscv_ztt_mls_tst_u64_rdn_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rdn_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_1x2_t value = __riscv_ztt_mls_tst_u64_rdn_1x2 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rdn_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_1x2_t value = __riscv_ztt_mls_rm_u64_rdn_1x2 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rdn_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_1x2_t value = __riscv_ztt_mls_tst_u64_rdn_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rdn_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_2x1_t value = __riscv_ztt_mls_tst_u64_rdn_2x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rdn_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_2x1_t value = __riscv_ztt_mls_rm_u64_rdn_2x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rdn_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_2x1_t value = __riscv_ztt_mls_tst_u64_rdn_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rdn_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_1x4_t value = __riscv_ztt_mls_tst_u64_rdn_1x4 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rdn_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_1x4_t value = __riscv_ztt_mls_rm_u64_rdn_1x4 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rdn_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_1x4_t value = __riscv_ztt_mls_tst_u64_rdn_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rdn_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_4x1_t value = __riscv_ztt_mls_tst_u64_rdn_4x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rdn_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_4x1_t value = __riscv_ztt_mls_rm_u64_rdn_4x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rdn_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_4x1_t value = __riscv_ztt_mls_tst_u64_rdn_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rdn_sat_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_sat_1x1_t value = __riscv_ztt_mls_tst_u64_rdn_sat_1x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rdn_sat_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_sat_1x1_t value = __riscv_ztt_mls_rm_u64_rdn_sat_1x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rdn_sat_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_sat_1x1_t value = __riscv_ztt_mls_tst_u64_rdn_sat_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rdn_sat_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_sat_1x2_t value = __riscv_ztt_mls_tst_u64_rdn_sat_1x2 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rdn_sat_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_sat_1x2_t value = __riscv_ztt_mls_rm_u64_rdn_sat_1x2 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rdn_sat_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_sat_1x2_t value = __riscv_ztt_mls_tst_u64_rdn_sat_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rdn_sat_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_sat_2x1_t value = __riscv_ztt_mls_tst_u64_rdn_sat_2x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rdn_sat_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_sat_2x1_t value = __riscv_ztt_mls_rm_u64_rdn_sat_2x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rdn_sat_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_sat_2x1_t value = __riscv_ztt_mls_tst_u64_rdn_sat_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rdn_sat_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_sat_1x4_t value = __riscv_ztt_mls_tst_u64_rdn_sat_1x4 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rdn_sat_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_sat_1x4_t value = __riscv_ztt_mls_rm_u64_rdn_sat_1x4 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rdn_sat_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_sat_1x4_t value = __riscv_ztt_mls_tst_u64_rdn_sat_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rdn_sat_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_sat_4x1_t value = __riscv_ztt_mls_tst_u64_rdn_sat_4x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rdn_sat_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_sat_4x1_t value = __riscv_ztt_mls_rm_u64_rdn_sat_4x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rdn_sat_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rdn_sat_4x1_t value = __riscv_ztt_mls_tst_u64_rdn_sat_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rod_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_1x1_t value = __riscv_ztt_mls_tst_u64_rod_1x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rod_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_1x1_t value = __riscv_ztt_mls_rm_u64_rod_1x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rod_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_1x1_t value = __riscv_ztt_mls_tst_u64_rod_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rod_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_1x2_t value = __riscv_ztt_mls_tst_u64_rod_1x2 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rod_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_1x2_t value = __riscv_ztt_mls_rm_u64_rod_1x2 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rod_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_1x2_t value = __riscv_ztt_mls_tst_u64_rod_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rod_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_2x1_t value = __riscv_ztt_mls_tst_u64_rod_2x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rod_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_2x1_t value = __riscv_ztt_mls_rm_u64_rod_2x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rod_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_2x1_t value = __riscv_ztt_mls_tst_u64_rod_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rod_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_1x4_t value = __riscv_ztt_mls_tst_u64_rod_1x4 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rod_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_1x4_t value = __riscv_ztt_mls_rm_u64_rod_1x4 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rod_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_1x4_t value = __riscv_ztt_mls_tst_u64_rod_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rod_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_4x1_t value = __riscv_ztt_mls_tst_u64_rod_4x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rod_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_4x1_t value = __riscv_ztt_mls_rm_u64_rod_4x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rod_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_4x1_t value = __riscv_ztt_mls_tst_u64_rod_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rod_sat_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_sat_1x1_t value = __riscv_ztt_mls_tst_u64_rod_sat_1x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rod_sat_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_sat_1x1_t value = __riscv_ztt_mls_rm_u64_rod_sat_1x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rod_sat_1x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_sat_1x1_t value = __riscv_ztt_mls_tst_u64_rod_sat_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rod_sat_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_sat_1x2_t value = __riscv_ztt_mls_tst_u64_rod_sat_1x2 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rod_sat_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_sat_1x2_t value = __riscv_ztt_mls_rm_u64_rod_sat_1x2 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rod_sat_1x2 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_sat_1x2_t value = __riscv_ztt_mls_tst_u64_rod_sat_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rod_sat_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_sat_2x1_t value = __riscv_ztt_mls_tst_u64_rod_sat_2x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rod_sat_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_sat_2x1_t value = __riscv_ztt_mls_rm_u64_rod_sat_2x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rod_sat_2x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_sat_2x1_t value = __riscv_ztt_mls_tst_u64_rod_sat_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rod_sat_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_sat_1x4_t value = __riscv_ztt_mls_tst_u64_rod_sat_1x4 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rod_sat_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_sat_1x4_t value = __riscv_ztt_mls_rm_u64_rod_sat_1x4 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rod_sat_1x4 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_sat_1x4_t value = __riscv_ztt_mls_tst_u64_rod_sat_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_u64_rod_sat_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_sat_4x1_t value = __riscv_ztt_mls_tst_u64_rod_sat_4x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_u64_rod_sat_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_sat_4x1_t value = __riscv_ztt_mls_rm_u64_rod_sat_4x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_u64_rod_sat_4x1 (uint64_t *out, const uint64_t *in, size_t stride)
{
  __riscv_ztt_u64_rod_sat_4x1_t value = __riscv_ztt_mls_tst_u64_rod_sat_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rne_1x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_1x1_t value = __riscv_ztt_mls_tst_f64_rne_1x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rne_1x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_1x1_t value = __riscv_ztt_mls_rm_f64_rne_1x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rne_1x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_1x1_t value = __riscv_ztt_mls_tst_f64_rne_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rne_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_1x2_t value = __riscv_ztt_mls_tst_f64_rne_1x2 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rne_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_1x2_t value = __riscv_ztt_mls_rm_f64_rne_1x2 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rne_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_1x2_t value = __riscv_ztt_mls_tst_f64_rne_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rne_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_2x1_t value = __riscv_ztt_mls_tst_f64_rne_2x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rne_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_2x1_t value = __riscv_ztt_mls_rm_f64_rne_2x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rne_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_2x1_t value = __riscv_ztt_mls_tst_f64_rne_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rne_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_1x4_t value = __riscv_ztt_mls_tst_f64_rne_1x4 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rne_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_1x4_t value = __riscv_ztt_mls_rm_f64_rne_1x4 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rne_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_1x4_t value = __riscv_ztt_mls_tst_f64_rne_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rne_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_4x1_t value = __riscv_ztt_mls_tst_f64_rne_4x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rne_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_4x1_t value = __riscv_ztt_mls_rm_f64_rne_4x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rne_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rne_4x1_t value = __riscv_ztt_mls_tst_f64_rne_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rtz_1x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_1x1_t value = __riscv_ztt_mls_tst_f64_rtz_1x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rtz_1x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_1x1_t value = __riscv_ztt_mls_rm_f64_rtz_1x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rtz_1x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_1x1_t value = __riscv_ztt_mls_tst_f64_rtz_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rtz_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_1x2_t value = __riscv_ztt_mls_tst_f64_rtz_1x2 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rtz_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_1x2_t value = __riscv_ztt_mls_rm_f64_rtz_1x2 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rtz_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_1x2_t value = __riscv_ztt_mls_tst_f64_rtz_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rtz_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_2x1_t value = __riscv_ztt_mls_tst_f64_rtz_2x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rtz_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_2x1_t value = __riscv_ztt_mls_rm_f64_rtz_2x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rtz_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_2x1_t value = __riscv_ztt_mls_tst_f64_rtz_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rtz_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_1x4_t value = __riscv_ztt_mls_tst_f64_rtz_1x4 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rtz_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_1x4_t value = __riscv_ztt_mls_rm_f64_rtz_1x4 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rtz_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_1x4_t value = __riscv_ztt_mls_tst_f64_rtz_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rtz_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_4x1_t value = __riscv_ztt_mls_tst_f64_rtz_4x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rtz_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_4x1_t value = __riscv_ztt_mls_rm_f64_rtz_4x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rtz_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rtz_4x1_t value = __riscv_ztt_mls_tst_f64_rtz_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rdn_1x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_1x1_t value = __riscv_ztt_mls_tst_f64_rdn_1x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rdn_1x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_1x1_t value = __riscv_ztt_mls_rm_f64_rdn_1x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rdn_1x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_1x1_t value = __riscv_ztt_mls_tst_f64_rdn_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rdn_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_1x2_t value = __riscv_ztt_mls_tst_f64_rdn_1x2 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rdn_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_1x2_t value = __riscv_ztt_mls_rm_f64_rdn_1x2 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rdn_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_1x2_t value = __riscv_ztt_mls_tst_f64_rdn_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rdn_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_2x1_t value = __riscv_ztt_mls_tst_f64_rdn_2x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rdn_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_2x1_t value = __riscv_ztt_mls_rm_f64_rdn_2x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rdn_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_2x1_t value = __riscv_ztt_mls_tst_f64_rdn_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rdn_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_1x4_t value = __riscv_ztt_mls_tst_f64_rdn_1x4 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rdn_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_1x4_t value = __riscv_ztt_mls_rm_f64_rdn_1x4 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rdn_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_1x4_t value = __riscv_ztt_mls_tst_f64_rdn_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rdn_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_4x1_t value = __riscv_ztt_mls_tst_f64_rdn_4x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rdn_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_4x1_t value = __riscv_ztt_mls_rm_f64_rdn_4x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rdn_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rdn_4x1_t value = __riscv_ztt_mls_tst_f64_rdn_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rup_1x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_1x1_t value = __riscv_ztt_mls_tst_f64_rup_1x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rup_1x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_1x1_t value = __riscv_ztt_mls_rm_f64_rup_1x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rup_1x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_1x1_t value = __riscv_ztt_mls_tst_f64_rup_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rup_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_1x2_t value = __riscv_ztt_mls_tst_f64_rup_1x2 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rup_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_1x2_t value = __riscv_ztt_mls_rm_f64_rup_1x2 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rup_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_1x2_t value = __riscv_ztt_mls_tst_f64_rup_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rup_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_2x1_t value = __riscv_ztt_mls_tst_f64_rup_2x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rup_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_2x1_t value = __riscv_ztt_mls_rm_f64_rup_2x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rup_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_2x1_t value = __riscv_ztt_mls_tst_f64_rup_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rup_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_1x4_t value = __riscv_ztt_mls_tst_f64_rup_1x4 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rup_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_1x4_t value = __riscv_ztt_mls_rm_f64_rup_1x4 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rup_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_1x4_t value = __riscv_ztt_mls_tst_f64_rup_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rup_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_4x1_t value = __riscv_ztt_mls_tst_f64_rup_4x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rup_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_4x1_t value = __riscv_ztt_mls_rm_f64_rup_4x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rup_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rup_4x1_t value = __riscv_ztt_mls_tst_f64_rup_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rmm_1x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_1x1_t value = __riscv_ztt_mls_tst_f64_rmm_1x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rmm_1x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_1x1_t value = __riscv_ztt_mls_rm_f64_rmm_1x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rmm_1x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_1x1_t value = __riscv_ztt_mls_tst_f64_rmm_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rmm_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_1x2_t value = __riscv_ztt_mls_tst_f64_rmm_1x2 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rmm_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_1x2_t value = __riscv_ztt_mls_rm_f64_rmm_1x2 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rmm_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_1x2_t value = __riscv_ztt_mls_tst_f64_rmm_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rmm_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_2x1_t value = __riscv_ztt_mls_tst_f64_rmm_2x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rmm_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_2x1_t value = __riscv_ztt_mls_rm_f64_rmm_2x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rmm_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_2x1_t value = __riscv_ztt_mls_tst_f64_rmm_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rmm_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_1x4_t value = __riscv_ztt_mls_tst_f64_rmm_1x4 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rmm_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_1x4_t value = __riscv_ztt_mls_rm_f64_rmm_1x4 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rmm_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_1x4_t value = __riscv_ztt_mls_tst_f64_rmm_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rmm_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_4x1_t value = __riscv_ztt_mls_tst_f64_rmm_4x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rmm_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_4x1_t value = __riscv_ztt_mls_rm_f64_rmm_4x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rmm_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rmm_4x1_t value = __riscv_ztt_mls_tst_f64_rmm_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rno_1x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_1x1_t value = __riscv_ztt_mls_tst_f64_rno_1x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rno_1x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_1x1_t value = __riscv_ztt_mls_rm_f64_rno_1x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rno_1x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_1x1_t value = __riscv_ztt_mls_tst_f64_rno_1x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rno_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_1x2_t value = __riscv_ztt_mls_tst_f64_rno_1x2 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rno_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_1x2_t value = __riscv_ztt_mls_rm_f64_rno_1x2 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rno_1x2 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_1x2_t value = __riscv_ztt_mls_tst_f64_rno_1x2 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rno_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_2x1_t value = __riscv_ztt_mls_tst_f64_rno_2x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rno_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_2x1_t value = __riscv_ztt_mls_rm_f64_rno_2x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rno_2x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_2x1_t value = __riscv_ztt_mls_tst_f64_rno_2x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rno_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_1x4_t value = __riscv_ztt_mls_tst_f64_rno_1x4 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rno_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_1x4_t value = __riscv_ztt_mls_rm_f64_rno_1x4 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rno_1x4 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_1x4_t value = __riscv_ztt_mls_tst_f64_rno_1x4 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_load_f64_rno_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_4x1_t value = __riscv_ztt_mls_tst_f64_rno_4x1 (in, stride);
  __riscv_ztt_mss_rm (out, value);
}

void align_store_f64_rno_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_4x1_t value = __riscv_ztt_mls_rm_f64_rno_4x1 (in);
  __riscv_ztt_mss_tst (out, stride, value);
}

void align_roundtrip_f64_rno_4x1 (double *out, const double *in, size_t stride)
{
  __riscv_ztt_f64_rno_4x1_t value = __riscv_ztt_mls_tst_f64_rno_4x1 (in, stride);
  __riscv_ztt_mss_tst (out, stride, value);
}
/* { dg-final { scan-assembler {\tlbu?\t} } } */
/* { dg-final { scan-assembler {\tsb\t} } } */
/* { dg-final { scan-assembler-not {\tcall\t} } } */
