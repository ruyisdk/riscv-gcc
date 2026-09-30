/* integer
   1x1 types with UDS=8.  Wider elements own a complete 2/4-M group.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

void
bad (int8_t *i8, uint8_t *u8, int16_t *i16, uint16_t *u16,
     int32_t *i32, uint32_t *u32, const int16_t *c, volatile uint32_t *v)
{
  __riscv_ztt_i16_rnu_1x1_t a = __riscv_ztt_mclear_m_i16_rnu_1x1 ();
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mclear_m_u32_rne_1x1 ();
  __riscv_ztt_mls_rm_u8_rnu_1x1 (i8); /* { dg-error "requires a pointer to" } */
  __riscv_ztt_mls_rm_i16_rnu_1x1 (u16); /* { dg-error "requires a pointer to" } */
  __riscv_ztt_mls_rm_i32_rod_1x1 (i16); /* { dg-error "requires a pointer to" } */
  __riscv_ztt_mls_rm_u32_rdn_1x1 (i32); /* { dg-error "requires a pointer to" } */
  __riscv_ztt_mss_rm (u8, a); /* { dg-error "requires a pointer to writable" } */
  __riscv_ztt_mss_rm (u16, a); /* { dg-error "requires a pointer to writable" } */
  __riscv_ztt_mss_rm (c, a); /* { dg-error "requires a pointer to writable" } */
  __riscv_ztt_mss_rm (i32, b); /* { dg-error "requires a pointer to writable" } */
  __riscv_ztt_mss_rm (v, b); /* { dg-error "cannot access volatile or atomic" } */
  __riscv_ztt_mls_rm_u32_rne_1x1 (v); /* { dg-error "cannot access volatile or atomic" } */
  b = __riscv_ztt_madd_ew_i16_rnu_1x1 (a, b); /* { dg-error "incompatible type|cannot convert" } */
  __riscv_ztt_mss_rm_i16_rnu_1x1 (i16, b); /* { dg-error "incompatible type|cannot convert" } */
}
