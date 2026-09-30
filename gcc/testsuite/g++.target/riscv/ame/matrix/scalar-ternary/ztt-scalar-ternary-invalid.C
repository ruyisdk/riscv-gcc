/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu++11 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=gnu++11 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */

#include <stdint.h>
#include <riscv_ztt.h>
void invalid (const int8_t *p, uint32_t scalar)
{
  __riscv_ztt_i8_rnu_1x1_t d = __riscv_ztt_mls_rm_i8_rnu_1x1 (p);
  __riscv_ztt_i8_rne_1x1_t rm = __riscv_ztt_mls_rm_i8_rne_1x1 (p);
  __riscv_ztt_i8_rnu_1x2_t shape = __riscv_ztt_mls_rm_i8_rnu_1x2 (p);
  __riscv_ztt_i32_accx1_t acc = __riscv_ztt_mclear_acc_i32_accx1 ();
  __riscv_ztt_mmulacc_ew_x_i8_1x1_u32 (rm, d, __riscv_ztt_scalar_make_u32_rnu (scalar)); /* { dg-error "requires old_d to have the exact result datatype and shape" } */
  __riscv_ztt_mmulaccneg_ew_x_i8_1x1_u32 (shape, d, __riscv_ztt_scalar_make_u32_rnu (scalar)); /* { dg-error "requires old_d to have the exact result datatype and shape" } */
  __riscv_ztt_mmuladd_ew_x_i8_1x1_u32 (acc, d, __riscv_ztt_scalar_make_u32_rnu (scalar)); /* { dg-error "requires old_d to have the exact result datatype and shape" } */
  __riscv_ztt_mmulsub_ew_x_i8_1x1_u32 (scalar, d, __riscv_ztt_scalar_make_u32_rnu (scalar)); /* { dg-error "requires old_d to have the exact result datatype and shape" } */
  __riscv_ztt_mmulacc_ew_x_i8_1x1_u32 (d, shape, __riscv_ztt_scalar_make_u32_rnu (scalar)); /* { dg-error "compatible types, shapes" } */
  __riscv_ztt_mmulaccneg_ew_x_i8_1x1_u32 (d, acc, __riscv_ztt_scalar_make_u32_rnu (scalar)); /* { dg-error "compatible types, shapes" } */
  __riscv_ztt_mmuladd_ew_x_i8_1x1_u32 (d, scalar, __riscv_ztt_scalar_make_u32_rnu (scalar)); /* { dg-error "compatible types, shapes" } */
  __riscv_ztt_mmulsub_ew_x_i8_1x1_u32 (d, d, __riscv_ztt_scalar_make_u32_rnu (1.5)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  __riscv_ztt_mmulacc_ew_x_i8_1x1_u32 (d, d, __riscv_ztt_scalar_make_u32_rnu (p)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  __riscv_ztt_mmulaccneg_ew_x_i8_1x1_u32 (d, d, __riscv_ztt_scalar_make_u32_rnu (acc)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  __riscv_ztt_mmuladd_ew_x_i8_1x1_u32 (d, d, __riscv_ztt_scalar_make_u32_rnu (d)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  __riscv_ztt_mmulsub_ew_x_i8_1x1_u32 (d, d); /* { dg-error "data-scalar operation expects" } */
}
