/* See the F58 contract mapping for normative IDs and controls.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0 -Werror=implicit-function-declaration" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0 -Werror=implicit-function-declaration" { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>

/* Legal counterpart of mcolbcast_ew_x:01.  */
void
positive_mcolbcast_ew_x_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t src_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mcolbcast_ew_x_i32_1x1 (src_i32_1x1, (size_t) control);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mcolbcast_ew_x:02.  */
void
positive_mcolbcast_ew_x_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t src_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mcolbcast_ew_x_i32_1x1 (src_i32_1x1, (size_t) control);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mrowbcast_ew_x:01.  */
void
positive_mrowbcast_ew_x_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t src_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mrowbcast_ew_x_i32_1x1 (src_i32_1x1, (size_t) control);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mrowbcast_ew_x:02.  */
void
positive_mrowbcast_ew_x_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t src_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mrowbcast_ew_x_i32_1x1 (src_i32_1x1, (size_t) control);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mcolgather_ew:01.  */
void
positive_mcolgather_ew_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mcolgather_ew_i32_1x1 (src1_i32_1x1, src2_u32_1x1);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mcolgather_ew:02.  */
void
positive_mcolgather_ew_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mcolgather_ew_i32_1x1 (src1_i32_1x1, src2_u32_1x1);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mcolgather_ew:03.  */
void
positive_mcolgather_ew_03 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mcolgather_ew_i32_1x1 (src1_i32_1x1, src2_u32_1x1);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mrowgather_ew:01.  */
void
positive_mrowgather_ew_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mrowgather_ew_i32_1x1 (src1_i32_1x1, src2_u32_1x1);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mrowgather_ew:02.  */
void
positive_mrowgather_ew_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mrowgather_ew_i32_1x1 (src1_i32_1x1, src2_u32_1x1);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mrowgather_ew:03.  */
void
positive_mrowgather_ew_03 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mrowgather_ew_i32_1x1 (src1_i32_1x1, src2_u32_1x1);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mcolscatadd_ew:01.  */
void
positive_mcolscatadd_ew_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t old_d_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mcolscatadd_ew_i32_1x1 (old_d_i32_1x1, src1_i32_1x1, src2_u32_1x1);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mcolscatadd_ew:02.  */
void
positive_mcolscatadd_ew_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t old_d_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mcolscatadd_ew_i32_1x1 (old_d_i32_1x1, src1_i32_1x1, src2_u32_1x1);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mcolscatadd_ew:03.  */
void
positive_mcolscatadd_ew_03 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t old_d_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mcolscatadd_ew_i32_1x1 (old_d_i32_1x1, src1_i32_1x1, src2_u32_1x1);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mcolscatadd_ew:04.  */
void
positive_mcolscatadd_ew_04 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t old_d_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mcolscatadd_ew_i32_1x1 (old_d_i32_1x1, src1_i32_1x1, src2_u32_1x1);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mrowscatadd_ew:01.  */
void
positive_mrowscatadd_ew_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t old_d_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mrowscatadd_ew_i32_1x1 (old_d_i32_1x1, src1_i32_1x1, src2_u32_1x1);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mrowscatadd_ew:02.  */
void
positive_mrowscatadd_ew_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t old_d_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mrowscatadd_ew_i32_1x1 (old_d_i32_1x1, src1_i32_1x1, src2_u32_1x1);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mrowscatadd_ew:03.  */
void
positive_mrowscatadd_ew_03 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t old_d_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mrowscatadd_ew_i32_1x1 (old_d_i32_1x1, src1_i32_1x1, src2_u32_1x1);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mrowscatadd_ew:04.  */
void
positive_mrowscatadd_ew_04 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t old_d_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mrowscatadd_ew_i32_1x1 (old_d_i32_1x1, src1_i32_1x1, src2_u32_1x1);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mcolscatmax_ew:01.  */
void
positive_mcolscatmax_ew_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t old_d_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mcolscatmax_ew_i32_1x1 (old_d_i32_1x1, src1_i32_1x1, src2_u32_1x1);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mcolscatmax_ew:02.  */
void
positive_mcolscatmax_ew_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t old_d_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mcolscatmax_ew_i32_1x1 (old_d_i32_1x1, src1_i32_1x1, src2_u32_1x1);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mcolscatmax_ew:03.  */
void
positive_mcolscatmax_ew_03 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t old_d_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mcolscatmax_ew_i32_1x1 (old_d_i32_1x1, src1_i32_1x1, src2_u32_1x1);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mcolscatmax_ew:04.  */
void
positive_mcolscatmax_ew_04 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t old_d_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mcolscatmax_ew_i32_1x1 (old_d_i32_1x1, src1_i32_1x1, src2_u32_1x1);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mrowscatmax_ew:01.  */
void
positive_mrowscatmax_ew_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t old_d_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mrowscatmax_ew_i32_1x1 (old_d_i32_1x1, src1_i32_1x1, src2_u32_1x1);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mrowscatmax_ew:02.  */
void
positive_mrowscatmax_ew_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t old_d_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mrowscatmax_ew_i32_1x1 (old_d_i32_1x1, src1_i32_1x1, src2_u32_1x1);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mrowscatmax_ew:03.  */
void
positive_mrowscatmax_ew_03 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t old_d_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mrowscatmax_ew_i32_1x1 (old_d_i32_1x1, src1_i32_1x1, src2_u32_1x1);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mrowscatmax_ew:04.  */
void
positive_mrowscatmax_ew_04 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t old_d_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t src1_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_u32_1x1_t src2_u32_1x1 = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mrowscatmax_ew_i32_1x1 (old_d_i32_1x1, src1_i32_1x1, src2_u32_1x1);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mcolshift_ew_x:01.  */
void
positive_mcolshift_ew_x_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t src_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mcolshift_ew_x_i32_1x1 (src_i32_1x1, (int) control);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mcolshift_ew_x:02.  */
void
positive_mcolshift_ew_x_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t src_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mcolshift_ew_x_i32_1x1 (src_i32_1x1, (int) control);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mcolshift_ew_x:03.  */
void
positive_mcolshift_ew_x_03 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t src_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mcolshift_ew_x_i32_1x1 (src_i32_1x1, (int) control);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mrowshift_ew_x:01.  */
void
positive_mrowshift_ew_x_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t src_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mrowshift_ew_x_i32_1x1 (src_i32_1x1, (int) control);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mrowshift_ew_x:02.  */
void
positive_mrowshift_ew_x_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t src_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mrowshift_ew_x_i32_1x1 (src_i32_1x1, (int) control);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of mrowshift_ew_x:03.  */
void
positive_mrowshift_ew_x_03 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x1_t src_i32_1x1 = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_1x1_t value = __riscv_ztt_mrowshift_ew_x_i32_1x1 (src_i32_1x1, (int) control);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* { dg-final { scan-assembler {	mcolbcast\.ew\.x	} } } */
/* { dg-final { scan-assembler {	mcolgather\.ew	} } } */
/* { dg-final { scan-assembler {	mcolscatadd\.ew	} } } */
/* { dg-final { scan-assembler {	mcolscatmax\.ew	} } } */
/* { dg-final { scan-assembler {	mcolshift\.ew\.x	} } } */
/* { dg-final { scan-assembler {	mrowbcast\.ew\.x	} } } */
/* { dg-final { scan-assembler {	mrowgather\.ew	} } } */
/* { dg-final { scan-assembler {	mrowscatadd\.ew	} } } */
/* { dg-final { scan-assembler {	mrowscatmax\.ew	} } } */
/* { dg-final { scan-assembler {	mrowshift\.ew\.x	} } } */
