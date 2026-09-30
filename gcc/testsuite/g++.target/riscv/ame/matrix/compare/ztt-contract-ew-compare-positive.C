/* Normative IDs and adaptations are recorded in F60.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

extern "C" {
/* Observable legal counterpart of mcmpge_ew:01.  */
void
positive_mcmpge_ew_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mcmpge_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mcmpge_ew:02.  */
void
positive_mcmpge_ew_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mcmpge_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mcmpge_ew:03.  */
void
positive_mcmpge_ew_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mcmpge_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mcmpge_ew_x:01.  */
void
positive_mcmpge_ew_x_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mcmpge_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mcmpge_ew_x:02.  */
void
positive_mcmpge_ew_x_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mcmpge_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mcmpge_ew_x:03.  */
void
positive_mcmpge_ew_x_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mcmpge_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mcmpge_ew_x:04.  */
void
positive_mcmpge_ew_x_04 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mcmpge_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mcmplt_ew:01.  */
void
positive_mcmplt_ew_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mcmplt_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mcmplt_ew:02.  */
void
positive_mcmplt_ew_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mcmplt_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mcmplt_ew:03.  */
void
positive_mcmplt_ew_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mcmplt_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mcmplt_ew_x:01.  */
void
positive_mcmplt_ew_x_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mcmplt_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mcmplt_ew_x:02.  */
void
positive_mcmplt_ew_x_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mcmplt_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mcmplt_ew_x:03.  */
void
positive_mcmplt_ew_x_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mcmplt_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mcmplt_ew_x:04.  */
void
positive_mcmplt_ew_x_04 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mcmplt_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mselge_ew:01.  */
void
positive_mselge_ew_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mselge_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mselge_ew:02.  */
void
positive_mselge_ew_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mselge_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mselge_ew:03.  */
void
positive_mselge_ew_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mselge_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of msellt_ew:01.  */
void
positive_msellt_ew_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msellt_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of msellt_ew:02.  */
void
positive_msellt_ew_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msellt_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of msellt_ew:03.  */
void
positive_msellt_ew_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src1_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t src2_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msellt_ew_i32_1x2 (src1_i32_1x2, src2_i32_1x2);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

}
/* { dg-final { scan-assembler {\tmcmpge\.ew\t} } } */
/* { dg-final { scan-assembler {\tmcmpge\.ew\.x\t} } } */
/* { dg-final { scan-assembler {\tmcmplt\.ew\t} } } */
/* { dg-final { scan-assembler {\tmcmplt\.ew\.x\t} } } */
/* { dg-final { scan-assembler {\tmselge\.ew\t} } } */
/* { dg-final { scan-assembler {\tmsellt\.ew\t} } } */
