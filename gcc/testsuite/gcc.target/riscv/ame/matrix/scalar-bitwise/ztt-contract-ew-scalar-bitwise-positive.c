/* Normative IDs and adaptations are recorded in F60.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

/* Observable legal counterpart of mand_ew_x:01.  */
void
positive_mand_ew_x_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mand_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mand_ew_x:02.  */
void
positive_mand_ew_x_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mand_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mand_ew_x:03.  */
void
positive_mand_ew_x_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mand_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mand_ew_x:04.  */
void
positive_mand_ew_x_04 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mand_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mand_ew_x:05.  */
void
positive_mand_ew_x_05 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mand_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mandnot_ew_x:01.  */
void
positive_mandnot_ew_x_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mandnot_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mandnot_ew_x:02.  */
void
positive_mandnot_ew_x_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mandnot_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mandnot_ew_x:03.  */
void
positive_mandnot_ew_x_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mandnot_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mandnot_ew_x:04.  */
void
positive_mandnot_ew_x_04 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mandnot_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mandnot_ew_x:05.  */
void
positive_mandnot_ew_x_05 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mandnot_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mor_ew_x:01.  */
void
positive_mor_ew_x_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mor_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mor_ew_x:02.  */
void
positive_mor_ew_x_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mor_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mor_ew_x:03.  */
void
positive_mor_ew_x_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mor_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mor_ew_x:04.  */
void
positive_mor_ew_x_04 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mor_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mor_ew_x:05.  */
void
positive_mor_ew_x_05 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mor_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mornot_ew_x:01.  */
void
positive_mornot_ew_x_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mornot_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mornot_ew_x:02.  */
void
positive_mornot_ew_x_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mornot_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mornot_ew_x:03.  */
void
positive_mornot_ew_x_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mornot_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mornot_ew_x:04.  */
void
positive_mornot_ew_x_04 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mornot_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mornot_ew_x:05.  */
void
positive_mornot_ew_x_05 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mornot_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mxor_ew_x:01.  */
void
positive_mxor_ew_x_01 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mxor_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mxor_ew_x:02.  */
void
positive_mxor_ew_x_02 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mxor_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mxor_ew_x:03.  */
void
positive_mxor_ew_x_03 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mxor_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mxor_ew_x:04.  */
void
positive_mxor_ew_x_04 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mxor_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mxor_ew_x:05.  */
void
positive_mxor_ew_x_05 (void *out)
{
  __riscv_ztt_i32_1x2_t src_i32_1x2 = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mxor_ew_x_i32_1x2 (src_i32_1x2, scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* { dg-final { scan-assembler {\tmand\.ew\.x\t} } } */
/* { dg-final { scan-assembler {\tmandnot\.ew\.x\t} } } */
/* { dg-final { scan-assembler {\tmor\.ew\.x\t} } } */
/* { dg-final { scan-assembler {\tmornot\.ew\.x\t} } } */
/* { dg-final { scan-assembler {\tmxor\.ew\.x\t} } } */
