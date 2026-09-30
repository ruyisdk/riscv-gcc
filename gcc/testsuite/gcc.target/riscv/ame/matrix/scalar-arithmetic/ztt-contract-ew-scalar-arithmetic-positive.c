/* Normative IDs and adaptations are recorded in F60.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

/* Observable legal counterpart of mabsdiff_ew_x:01.  */
void
positive_mabsdiff_ew_x_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mabsdiff_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mabsdiff_ew_x:02.  */
void
positive_mabsdiff_ew_x_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mabsdiff_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mabsdiff_ew_x:03.  */
void
positive_mabsdiff_ew_x_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mabsdiff_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of madd_ew_x:01.  */
void
positive_madd_ew_x_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_madd_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of madd_ew_x:02.  */
void
positive_madd_ew_x_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_madd_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of madd_ew_x:03.  */
void
positive_madd_ew_x_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_madd_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mhdiff_ew_x:01.  */
void
positive_mhdiff_ew_x_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mhdiff_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mhdiff_ew_x:02.  */
void
positive_mhdiff_ew_x_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mhdiff_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mhdiff_ew_x:03.  */
void
positive_mhdiff_ew_x_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mhdiff_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmax_ew_x:01.  */
void
positive_mmax_ew_x_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmax_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmax_ew_x:02.  */
void
positive_mmax_ew_x_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmax_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmax_ew_x:03.  */
void
positive_mmax_ew_x_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmax_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmax_ew_x:04.  */
void
positive_mmax_ew_x_04 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmax_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmean_ew_x:01.  */
void
positive_mmean_ew_x_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmean_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmean_ew_x:02.  */
void
positive_mmean_ew_x_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmean_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmean_ew_x:03.  */
void
positive_mmean_ew_x_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmean_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmin_ew_x:01.  */
void
positive_mmin_ew_x_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmin_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmin_ew_x:02.  */
void
positive_mmin_ew_x_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmin_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmin_ew_x:03.  */
void
positive_mmin_ew_x_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmin_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmin_ew_x:04.  */
void
positive_mmin_ew_x_04 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmin_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmul_ew_x:01.  */
void
positive_mmul_ew_x_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmul_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmul_ew_x:02.  */
void
positive_mmul_ew_x_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmul_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmul_ew_x:03.  */
void
positive_mmul_ew_x_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmul_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmulneg_ew_x:01.  */
void
positive_mmulneg_ew_x_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmulneg_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmulneg_ew_x:02.  */
void
positive_mmulneg_ew_x_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmulneg_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mmulneg_ew_x:03.  */
void
positive_mmulneg_ew_x_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mmulneg_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of msub_ew_x:01.  */
void
positive_msub_ew_x_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msub_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of msub_ew_x:02.  */
void
positive_msub_ew_x_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msub_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of msub_ew_x:03.  */
void
positive_msub_ew_x_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_msub_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* { dg-final { scan-assembler {\tmabsdiff\.ew\.x\t} } } */
/* { dg-final { scan-assembler {\tmadd\.ew\.x\t} } } */
/* { dg-final { scan-assembler {\tmhdiff\.ew\.x\t} } } */
/* { dg-final { scan-assembler {\tmmax\.ew\.x\t} } } */
/* { dg-final { scan-assembler {\tmmean\.ew\.x\t} } } */
/* { dg-final { scan-assembler {\tmmin\.ew\.x\t} } } */
/* { dg-final { scan-assembler {\tmmul\.ew\.x\t} } } */
/* { dg-final { scan-assembler {\tmmulneg\.ew\.x\t} } } */
/* { dg-final { scan-assembler {\tmsub\.ew\.x\t} } } */
