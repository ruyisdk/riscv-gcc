/* See the F58 contract mapping for normative IDs and controls.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0 -Werror=implicit-function-declaration" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0 -Werror=implicit-function-declaration" { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>

/* Legal counterpart of msll_ew:01.  */
void
positive_msll_ew_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msll_ew_i32_1x2 (src1_i32_1x2, src2_u32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msll_ew:02.  */
void
positive_msll_ew_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msll_ew_i32_1x2 (src1_i32_1x2, src2_u32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msll_ew:03.  */
void
positive_msll_ew_03 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msll_ew_i32_1x2 (src1_i32_1x2, src2_u32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msll_ew:04.  */
void
positive_msll_ew_04 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msll_ew_i32_1x2 (src1_i32_1x2, src2_u32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msll_ew:05.  */
void
positive_msll_ew_05 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msll_ew_i32_1x2 (src1_i32_1x2, src2_u32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msll_ew_x:01.  */
void
positive_msll_ew_x_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msll_ew_x_i32_1x2 (src1_i32_1x2, (size_t) control);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msll_ew_x:02.  */
void
positive_msll_ew_x_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msll_ew_x_i32_1x2 (src1_i32_1x2, (size_t) control);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msll_ew_x:03.  */
void
positive_msll_ew_x_03 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msll_ew_x_i32_1x2 (src1_i32_1x2, (size_t) control);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msll_ew_x:04.  */
void
positive_msll_ew_x_04 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msll_ew_x_i32_1x2 (src1_i32_1x2, (size_t) control);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msra_ew:01.  */
void
positive_msra_ew_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msra_ew_i32_1x2 (src1_i32_1x2, src2_u32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msra_ew:02.  */
void
positive_msra_ew_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msra_ew_i32_1x2 (src1_i32_1x2, src2_u32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msra_ew:03.  */
void
positive_msra_ew_03 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msra_ew_i32_1x2 (src1_i32_1x2, src2_u32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msra_ew:04.  */
void
positive_msra_ew_04 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msra_ew_i32_1x2 (src1_i32_1x2, src2_u32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msra_ew:05.  */
void
positive_msra_ew_05 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msra_ew_i32_1x2 (src1_i32_1x2, src2_u32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msra_ew:06.  */
void
positive_msra_ew_06 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msra_ew_i32_1x2 (src1_i32_1x2, src2_u32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msra_ew_x:01.  */
void
positive_msra_ew_x_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msra_ew_x_i32_1x2 (src1_i32_1x2, (size_t) control);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msra_ew_x:02.  */
void
positive_msra_ew_x_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msra_ew_x_i32_1x2 (src1_i32_1x2, (size_t) control);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msra_ew_x:03.  */
void
positive_msra_ew_x_03 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msra_ew_x_i32_1x2 (src1_i32_1x2, (size_t) control);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msra_ew_x:04.  */
void
positive_msra_ew_x_04 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msra_ew_x_i32_1x2 (src1_i32_1x2, (size_t) control);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msra_ew_x:05.  */
void
positive_msra_ew_x_05 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msra_ew_x_i32_1x2 (src1_i32_1x2, (size_t) control);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msrl_ew:01.  */
void
positive_msrl_ew_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msrl_ew_i32_1x2 (src1_i32_1x2, src2_u32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msrl_ew:02.  */
void
positive_msrl_ew_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msrl_ew_i32_1x2 (src1_i32_1x2, src2_u32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msrl_ew:03.  */
void
positive_msrl_ew_03 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msrl_ew_i32_1x2 (src1_i32_1x2, src2_u32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msrl_ew:04.  */
void
positive_msrl_ew_04 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msrl_ew_i32_1x2 (src1_i32_1x2, src2_u32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msrl_ew:05.  */
void
positive_msrl_ew_05 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_u32_1x2_t src2_u32_1x2 = __riscv_ztt_mzero_m_u32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msrl_ew_i32_1x2 (src1_i32_1x2, src2_u32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msrl_ew_x:01.  */
void
positive_msrl_ew_x_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msrl_ew_x_i32_1x2 (src1_i32_1x2, (size_t) control);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msrl_ew_x:02.  */
void
positive_msrl_ew_x_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msrl_ew_x_i32_1x2 (src1_i32_1x2, (size_t) control);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msrl_ew_x:03.  */
void
positive_msrl_ew_x_03 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msrl_ew_x_i32_1x2 (src1_i32_1x2, (size_t) control);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Legal counterpart of msrl_ew_x:04.  */
void
positive_msrl_ew_x_04 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msrl_ew_x_i32_1x2 (src1_i32_1x2, (size_t) control);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* { dg-final { scan-assembler {	msll\.ew	} } } */
/* { dg-final { scan-assembler {	msll\.ew\.x	} } } */
/* { dg-final { scan-assembler {	msra\.ew	} } } */
/* { dg-final { scan-assembler {	msra\.ew\.x	} } } */
/* { dg-final { scan-assembler {	msrl\.ew	} } } */
/* { dg-final { scan-assembler {	msrl\.ew\.x	} } } */
