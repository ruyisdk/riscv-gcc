/* See the F58 contract mapping for normative IDs and controls.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>

extern "C" {
/* Legal counterpart of mls_rm:01.  */
void
positive_mls_rm_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i16_1x2_t value = __riscv_ztt_mls_rm_i16_1x2 ((const int16_t *) base);
  __riscv_ztt_mss_rm ((int16_t *) out, value);
}

/* Legal counterpart of mls_rm:02.  */
void
positive_mls_rm_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i8_1x8_t value = __riscv_ztt_mls_rm_i8_1x8 ((const int8_t *) base);
  __riscv_ztt_mss_rm ((int8_t *) out, value);
}

/* Legal counterpart of mls_cm:01.  */
void
positive_mls_cm_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i16_1x2_t value = __riscv_ztt_mls_cm_i16_1x2 ((const int16_t *) base);
  __riscv_ztt_mss_rm ((int16_t *) out, value);
}

/* Legal counterpart of mls_cm:02.  */
void
positive_mls_cm_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i8_1x8_t value = __riscv_ztt_mls_cm_i8_1x8 ((const int8_t *) base);
  __riscv_ztt_mss_rm ((int8_t *) out, value);
}

/* Legal counterpart of mls_st:01.  */
void
positive_mls_st_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i16_1x2_t value = __riscv_ztt_mls_st_i16_1x2 ((const int16_t *) base, (size_t) 16);
  __riscv_ztt_mss_rm ((int16_t *) out, value);
}

/* Legal counterpart of mls_st:02.  */
void
positive_mls_st_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i8_1x8_t value = __riscv_ztt_mls_st_i8_1x8 ((const int8_t *) base, (size_t) 16);
  __riscv_ztt_mss_rm ((int8_t *) out, value);
}

/* Legal counterpart of mls_tst:01.  */
void
positive_mls_tst_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i16_1x2_t value = __riscv_ztt_mls_tst_i16_1x2 ((const int16_t *) base, (size_t) 16);
  __riscv_ztt_mss_rm ((int16_t *) out, value);
}

/* Legal counterpart of mls_tst:02.  */
void
positive_mls_tst_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i8_1x8_t value = __riscv_ztt_mls_tst_i8_1x8 ((const int8_t *) base, (size_t) 16);
  __riscv_ztt_mss_rm ((int8_t *) out, value);
}

/* Legal counterpart of mss_rm:01.  */
void
positive_mss_rm_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i16_1x2_t src_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_mss_rm ((int16_t *) out, src_i16_1x2);
}

/* Legal counterpart of mss_rm:02.  */
void
positive_mss_rm_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i16_1x2_t src_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_mss_rm ((int16_t *) out, src_i16_1x2);
}

/* Legal counterpart of mss_rm:03.  */
void
positive_mss_rm_03 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i8_1x8_t src_i8_1x8 = __riscv_ztt_mzero_m_i8_1x8 ();
  __riscv_ztt_mss_rm ((int8_t *) out, src_i8_1x8);
}

/* Legal counterpart of mss_cm:01.  */
void
positive_mss_cm_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i16_1x2_t src_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_mss_cm ((int16_t *) out, src_i16_1x2);
}

/* Legal counterpart of mss_cm:02.  */
void
positive_mss_cm_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i16_1x2_t src_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_mss_cm ((int16_t *) out, src_i16_1x2);
}

/* Legal counterpart of mss_cm:03.  */
void
positive_mss_cm_03 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i8_1x8_t src_i8_1x8 = __riscv_ztt_mzero_m_i8_1x8 ();
  __riscv_ztt_mss_cm ((int8_t *) out, src_i8_1x8);
}

/* Legal counterpart of mss_st:01.  */
void
positive_mss_st_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i16_1x2_t src_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_mss_st ((int16_t *) out, (size_t) 16, src_i16_1x2);
}

/* Legal counterpart of mss_st:02.  */
void
positive_mss_st_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i16_1x2_t src_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_mss_st ((int16_t *) out, (size_t) 16, src_i16_1x2);
}

/* Legal counterpart of mss_st:03.  */
void
positive_mss_st_03 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i8_1x8_t src_i8_1x8 = __riscv_ztt_mzero_m_i8_1x8 ();
  __riscv_ztt_mss_st ((int8_t *) out, (size_t) 16, src_i8_1x8);
}

/* Legal counterpart of mss_tst:01.  */
void
positive_mss_tst_01 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i16_1x2_t src_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_mss_tst ((int16_t *) out, (size_t) 16, src_i16_1x2);
}

/* Legal counterpart of mss_tst:02.  */
void
positive_mss_tst_02 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i16_1x2_t src_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  __riscv_ztt_mss_tst ((int16_t *) out, (size_t) 16, src_i16_1x2);
}

/* Legal counterpart of mss_tst:03.  */
void
positive_mss_tst_03 (void *out, const void *base, size_t control)
{
  __riscv_ztt_i8_1x8_t src_i8_1x8 = __riscv_ztt_mzero_m_i8_1x8 ();
  __riscv_ztt_mss_tst ((int8_t *) out, (size_t) 16, src_i8_1x8);
}

}
/* { dg-final { scan-assembler {	mls\.cm	} } } */
/* { dg-final { scan-assembler {	mls\.rm	} } } */
/* { dg-final { scan-assembler {	mls\.st	} } } */
/* { dg-final { scan-assembler {	mls\.tst	} } } */
/* { dg-final { scan-assembler {	mss\.cm	} } } */
/* { dg-final { scan-assembler {	mss\.rm	} } } */
/* { dg-final { scan-assembler {	mss\.st	} } } */
/* { dg-final { scan-assembler {	mss\.tst	} } } */
