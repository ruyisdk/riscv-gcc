/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

struct impostor { uint32_t __bits; };
void bad (struct impostor fake, double d, __riscv_ztt_u128_storage_t storage)
{
  __riscv_ztt_i32_1x1_t m = __riscv_ztt_mclear_m_i32_1x1 ();
  (void) __riscv_ztt_madd_ew_x_i32_1x1 (m, 3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_mbcast_m_x_i32_1x1 (3); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_mbcast_m_x_i32_1x1 (fake); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_mbcast_m_x_i32_1x1 (storage); /* { dg-error "independent Scalar type" } */
  (void) __riscv_ztt_scalar_make_f32_rne (d); /* { dg-error "exact C floating format" } */
  (void) __riscv_ztt_scalar_make_i8_rnu (128); /* { dg-error "constant is out of range" } */
  (void) __riscv_ztt_scalar_from_bits_i8_rnu (-1); /* { dg-error "constant is out of range" } */
  (void) __riscv_ztt_scalar_make_i32_rnu (d); /* { dg-error "integer carrier" } */
  (void) __riscv_ztt_scalar_bits_i32_rnu (__riscv_ztt_scalar_make_i32_rne (3)); /* { dg-error "exact TC/RM/SAT type" } */
  (void) __riscv_ztt_scalar_bits_i32_rnu (__riscv_ztt_scalar_make_i32_rnu_sat (3)); /* { dg-error "exact TC/RM/SAT type" } */
#if __riscv_xlen == 32
  (void) __riscv_ztt_scalar_from_bits_u128_rnu (1ull << 40); /* { dg-error "XLEN-bit carrier" "" { target rv32 } } */
#endif
}
