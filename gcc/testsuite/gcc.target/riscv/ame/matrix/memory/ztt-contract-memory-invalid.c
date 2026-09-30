/* See the F58 contract mapping for normative IDs and controls.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0 -Werror=implicit-function-declaration" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0 -Werror=implicit-function-declaration" { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>

/* mls_rm:01: base element type does not match; spec line 10545.  */
void
case_mls_rm_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  (void) __riscv_ztt_mls_rm_i16_1x2 ((const int32_t *)base_i32); /* { dg-error "requires a pointer to 'short int'" } */
}

/* mls_rm:02: 4-bit memory element types are unsupported; spec line 10546.  */
void
case_mls_rm_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i4_1x8_t available = __riscv_ztt_mzero_m_i4_1x8 ();
  (void) available;
  (void) __riscv_ztt_mls_rm_i4_1x8 ((const int8_t *)base_i8); /* { dg-error "implicit declaration of function '__riscv_ztt_mls_rm_i4_1x8'" } */
}

/* mls_cm:01: base element type does not match; spec line 10631.  */
void
case_mls_cm_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  (void) __riscv_ztt_mls_cm_i16_1x2 ((const int32_t *)base_i32); /* { dg-error "requires a pointer to 'short int'" } */
}

/* mls_cm:02: 4-bit memory element types are unsupported; spec line 10632.  */
void
case_mls_cm_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i4_1x8_t available = __riscv_ztt_mzero_m_i4_1x8 ();
  (void) available;
  (void) __riscv_ztt_mls_cm_i4_1x8 ((const int8_t *)base_i8); /* { dg-error "implicit declaration of function '__riscv_ztt_mls_cm_i4_1x8'" } */
}

/* mls_st:01: base element type does not match; spec line 10717.  */
void
case_mls_st_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  (void) __riscv_ztt_mls_st_i16_1x2 ((const int32_t *)base_i32, (size_t)16); /* { dg-error "requires a pointer to 'short int'" } */
}

/* mls_st:02: 4-bit memory element types are unsupported; spec line 10718.  */
void
case_mls_st_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i4_1x8_t available = __riscv_ztt_mzero_m_i4_1x8 ();
  (void) available;
  (void) __riscv_ztt_mls_st_i4_1x8 ((const int8_t *)base_i8, (size_t)16); /* { dg-error "implicit declaration of function '__riscv_ztt_mls_st_i4_1x8'" } */
}

/* mls_tst:01: base element type does not match; spec line 10807.  */
void
case_mls_tst_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  (void) __riscv_ztt_mls_tst_i16_1x2 ((const int32_t *)base_i32, (size_t)16); /* { dg-error "requires a pointer to 'short int'" } */
}

/* mls_tst:02: 4-bit memory element types are unsupported; spec line 10808.  */
void
case_mls_tst_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i4_1x8_t available = __riscv_ztt_mzero_m_i4_1x8 ();
  (void) available;
  (void) __riscv_ztt_mls_tst_i4_1x8 ((const int8_t *)base_i8, (size_t)16); /* { dg-error "implicit declaration of function '__riscv_ztt_mls_tst_i4_1x8'" } */
}

/* mss_rm:01: base element type does not match; spec line 10919.  */
void
case_mss_rm_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i16_1x2_t src_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  (void) __riscv_ztt_mss_rm ((int32_t *)base_i32, src_i16_1x2); /* { dg-error "requires a pointer to writable 'short int'" } */
}

/* mss_rm:02: Store base must not be const; spec line 10920.  */
void
case_mss_rm_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i16_1x2_t src_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  (void) __riscv_ztt_mss_rm ((const int16_t *)base_i16, src_i16_1x2); /* { dg-error "requires a pointer to writable 'short int'" } */
}

/* mss_rm:03: 4-bit memory element types are unsupported; spec line 10921.  */
void
case_mss_rm_03 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i4_1x8_t src_i4_1x8 = __riscv_ztt_mzero_m_i4_1x8 ();
  (void) __riscv_ztt_mss_rm ((int8_t *)base_i8, src_i4_1x8); /* { dg-error "AME/Ztt i4/u4 memory interfaces are not supported" } */
}

/* mss_cm:01: base element type does not match; spec line 11002.  */
void
case_mss_cm_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i16_1x2_t src_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  (void) __riscv_ztt_mss_cm ((int32_t *)base_i32, src_i16_1x2); /* { dg-error "requires a pointer to writable 'short int'" } */
}

/* mss_cm:02: Store base must not be const; spec line 11003.  */
void
case_mss_cm_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i16_1x2_t src_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  (void) __riscv_ztt_mss_cm ((const int16_t *)base_i16, src_i16_1x2); /* { dg-error "requires a pointer to writable 'short int'" } */
}

/* mss_cm:03: 4-bit memory element types are unsupported; spec line 11004.  */
void
case_mss_cm_03 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i4_1x8_t src_i4_1x8 = __riscv_ztt_mzero_m_i4_1x8 ();
  (void) __riscv_ztt_mss_cm ((int8_t *)base_i8, src_i4_1x8); /* { dg-error "AME/Ztt i4/u4 memory interfaces are not supported" } */
}

/* mss_st:01: base element type does not match; spec line 11085.  */
void
case_mss_st_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i16_1x2_t src_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  (void) __riscv_ztt_mss_st ((int32_t *)base_i32, (size_t)16, src_i16_1x2); /* { dg-error "requires a pointer to writable 'short int'" } */
}

/* mss_st:02: Store base must not be const; spec line 11086.  */
void
case_mss_st_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i16_1x2_t src_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  (void) __riscv_ztt_mss_st ((const int16_t *)base_i16, (size_t)16, src_i16_1x2); /* { dg-error "requires a pointer to writable 'short int'" } */
}

/* mss_st:03: 4-bit memory element types are unsupported; spec line 11087.  */
void
case_mss_st_03 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i4_1x8_t src_i4_1x8 = __riscv_ztt_mzero_m_i4_1x8 ();
  (void) __riscv_ztt_mss_st ((int8_t *)base_i8, (size_t)16, src_i4_1x8); /* { dg-error "AME/Ztt i4/u4 memory interfaces are not supported" } */
}

/* mss_tst:01: base element type does not match; spec line 11172.  */
void
case_mss_tst_01 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i16_1x2_t src_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  (void) __riscv_ztt_mss_tst ((int32_t *)base_i32, (size_t)16, src_i16_1x2); /* { dg-error "requires a pointer to writable 'short int'" } */
}

/* mss_tst:02: Store base must not be const; spec line 11173.  */
void
case_mss_tst_02 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i16_1x2_t src_i16_1x2 = __riscv_ztt_mzero_m_i16_1x2 ();
  (void) __riscv_ztt_mss_tst ((const int16_t *)base_i16, (size_t)16, src_i16_1x2); /* { dg-error "requires a pointer to writable 'short int'" } */
}

/* mss_tst:03: 4-bit memory element types are unsupported; spec line 11174.  */
void
case_mss_tst_03 (int8_t *base_i8,
  int16_t *base_i16, int32_t *base_i32, size_t sh, size_t col,
  size_t row, int offset)
{
  __riscv_ztt_i4_1x8_t src_i4_1x8 = __riscv_ztt_mzero_m_i4_1x8 ();
  (void) __riscv_ztt_mss_tst ((int8_t *)base_i8, (size_t)16, src_i4_1x8); /* { dg-error "AME/Ztt i4/u4 memory interfaces are not supported" } */
}
