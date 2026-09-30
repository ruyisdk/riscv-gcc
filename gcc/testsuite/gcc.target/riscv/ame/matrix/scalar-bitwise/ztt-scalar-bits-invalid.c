/* scalar bitwise.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
void invalid (void)
{
  __riscv_ztt_i16_2x1_t col = __riscv_ztt_mzero_m_i16_2x1 ();
  __riscv_ztt_i32_1x2_t wide = __riscv_ztt_mzero_m_i32_1x2 ();
  __riscv_ztt_i32_1x1_t sq = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_i32_rne_1x1_t rounded = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_u32_1x1_t uns = __riscv_ztt_mzero_m_u32_1x1 ();
  __riscv_ztt_i32_accx1_t acc = __riscv_ztt_mzero_acc_i32_accx1 ();
  (void) __riscv_ztt_mand_ew_x_i32_1x1_i8 (sq, __riscv_ztt_scalar_make_i8_rnu (1.5)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mand_ew_x_i32_1x1_i8 (sq, __riscv_ztt_scalar_make_i8_rnu ((int *) 0)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mand_ew_x_i32_1x1_i8 (sq, __riscv_ztt_scalar_make_i8_rnu (sq)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mand_ew_x_i32_1x1_i8 (sq, __riscv_ztt_scalar_make_i8_rnu (acc)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mand_ew_x_i32_1x1_i8 (acc, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "compatible types, shapes" } */
  (void) __riscv_ztt_mand_ew_x_i32_1x1_i8 (0, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "compatible types, shapes" } */
  (void) __riscv_ztt_mand_ew_x_i16_1x2_i8 (col, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "compatible types, shapes" } */
  (void) __riscv_ztt_mand_ew_x_i32_1x1_i8 (sq); /* { dg-error "data-scalar operation expects" } */
  (void) __riscv_ztt_mand_ew_x_i32_1x1_i8 (sq, 0, 0); /* { dg-error "data-scalar operation expects" } */
  (void) __riscv_ztt_mand_ew_x_i32_1x1_i8 (rounded, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "exact result datatype" } */
  (void) __riscv_ztt_mand_ew_x_i32_1x1_i8 (uns, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "exact result datatype" } */
  (void) __riscv_ztt_mand_ew_x_i16_1x2_i8 (wide, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "exact result datatype" } */
  (void) __riscv_ztt_mandnot_ew_x_i32_1x1_i8 (sq, __riscv_ztt_scalar_make_i8_rnu (1.5)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mandnot_ew_x_i32_1x1_i8 (sq, __riscv_ztt_scalar_make_i8_rnu ((int *) 0)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mandnot_ew_x_i32_1x1_i8 (sq, __riscv_ztt_scalar_make_i8_rnu (sq)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mandnot_ew_x_i32_1x1_i8 (sq, __riscv_ztt_scalar_make_i8_rnu (acc)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mandnot_ew_x_i32_1x1_i8 (acc, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "compatible types, shapes" } */
  (void) __riscv_ztt_mandnot_ew_x_i32_1x1_i8 (0, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "compatible types, shapes" } */
  (void) __riscv_ztt_mandnot_ew_x_i16_1x2_i8 (col, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "compatible types, shapes" } */
  (void) __riscv_ztt_mandnot_ew_x_i32_1x1_i8 (sq); /* { dg-error "data-scalar operation expects" } */
  (void) __riscv_ztt_mandnot_ew_x_i32_1x1_i8 (sq, 0, 0); /* { dg-error "data-scalar operation expects" } */
  (void) __riscv_ztt_mandnot_ew_x_i32_1x1_i8 (rounded, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "exact result datatype" } */
  (void) __riscv_ztt_mandnot_ew_x_i32_1x1_i8 (uns, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "exact result datatype" } */
  (void) __riscv_ztt_mandnot_ew_x_i16_1x2_i8 (wide, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "exact result datatype" } */
  (void) __riscv_ztt_mor_ew_x_i32_1x1_i8 (sq, __riscv_ztt_scalar_make_i8_rnu (1.5)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mor_ew_x_i32_1x1_i8 (sq, __riscv_ztt_scalar_make_i8_rnu ((int *) 0)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mor_ew_x_i32_1x1_i8 (sq, __riscv_ztt_scalar_make_i8_rnu (sq)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mor_ew_x_i32_1x1_i8 (sq, __riscv_ztt_scalar_make_i8_rnu (acc)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mor_ew_x_i32_1x1_i8 (acc, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "compatible types, shapes" } */
  (void) __riscv_ztt_mor_ew_x_i32_1x1_i8 (0, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "compatible types, shapes" } */
  (void) __riscv_ztt_mor_ew_x_i16_1x2_i8 (col, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "compatible types, shapes" } */
  (void) __riscv_ztt_mor_ew_x_i32_1x1_i8 (sq); /* { dg-error "data-scalar operation expects" } */
  (void) __riscv_ztt_mor_ew_x_i32_1x1_i8 (sq, 0, 0); /* { dg-error "data-scalar operation expects" } */
  (void) __riscv_ztt_mor_ew_x_i32_1x1_i8 (rounded, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "exact result datatype" } */
  (void) __riscv_ztt_mor_ew_x_i32_1x1_i8 (uns, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "exact result datatype" } */
  (void) __riscv_ztt_mor_ew_x_i16_1x2_i8 (wide, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "exact result datatype" } */
  (void) __riscv_ztt_mornot_ew_x_i32_1x1_i8 (sq, __riscv_ztt_scalar_make_i8_rnu (1.5)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mornot_ew_x_i32_1x1_i8 (sq, __riscv_ztt_scalar_make_i8_rnu ((int *) 0)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mornot_ew_x_i32_1x1_i8 (sq, __riscv_ztt_scalar_make_i8_rnu (sq)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mornot_ew_x_i32_1x1_i8 (sq, __riscv_ztt_scalar_make_i8_rnu (acc)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mornot_ew_x_i32_1x1_i8 (acc, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "compatible types, shapes" } */
  (void) __riscv_ztt_mornot_ew_x_i32_1x1_i8 (0, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "compatible types, shapes" } */
  (void) __riscv_ztt_mornot_ew_x_i16_1x2_i8 (col, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "compatible types, shapes" } */
  (void) __riscv_ztt_mornot_ew_x_i32_1x1_i8 (sq); /* { dg-error "data-scalar operation expects" } */
  (void) __riscv_ztt_mornot_ew_x_i32_1x1_i8 (sq, 0, 0); /* { dg-error "data-scalar operation expects" } */
  (void) __riscv_ztt_mornot_ew_x_i32_1x1_i8 (rounded, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "exact result datatype" } */
  (void) __riscv_ztt_mornot_ew_x_i32_1x1_i8 (uns, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "exact result datatype" } */
  (void) __riscv_ztt_mornot_ew_x_i16_1x2_i8 (wide, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "exact result datatype" } */
  (void) __riscv_ztt_mxor_ew_x_i32_1x1_i8 (sq, __riscv_ztt_scalar_make_i8_rnu (1.5)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mxor_ew_x_i32_1x1_i8 (sq, __riscv_ztt_scalar_make_i8_rnu ((int *) 0)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mxor_ew_x_i32_1x1_i8 (sq, __riscv_ztt_scalar_make_i8_rnu (sq)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mxor_ew_x_i32_1x1_i8 (sq, __riscv_ztt_scalar_make_i8_rnu (acc)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  (void) __riscv_ztt_mxor_ew_x_i32_1x1_i8 (acc, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "compatible types, shapes" } */
  (void) __riscv_ztt_mxor_ew_x_i32_1x1_i8 (0, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "compatible types, shapes" } */
  (void) __riscv_ztt_mxor_ew_x_i16_1x2_i8 (col, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "compatible types, shapes" } */
  (void) __riscv_ztt_mxor_ew_x_i32_1x1_i8 (sq); /* { dg-error "data-scalar operation expects" } */
  (void) __riscv_ztt_mxor_ew_x_i32_1x1_i8 (sq, 0, 0); /* { dg-error "data-scalar operation expects" } */
  (void) __riscv_ztt_mxor_ew_x_i32_1x1_i8 (rounded, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "exact result datatype" } */
  (void) __riscv_ztt_mxor_ew_x_i32_1x1_i8 (uns, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "exact result datatype" } */
  (void) __riscv_ztt_mxor_ew_x_i16_1x2_i8 (wide, __riscv_ztt_scalar_make_i8_rnu (0)); /* { dg-error "exact result datatype" } */
}
