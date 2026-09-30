/* local v0.2.3 contract.  */
/* { dg-do compile } */
/* { dg-options "-std=gnu11 -O2 -fdiagnostics-plain-output -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-std=gnu11 -O2 -fdiagnostics-plain-output -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>

void
bad_carriers (void *raw, unsigned char *u8, char *plain, short *i16,
	      const signed char *ro, volatile signed char *io,
	      _Atomic signed char *atomic_ptr)
{
  __riscv_ztt_i8_rne_1x1_t value
    = __riscv_ztt_mzero_2d_m_i8_rne_1x1 ();
  __riscv_ztt_mls_rm_i8_rne_1x1 (raw); /* { dg-error "requires a pointer to" } */
  __riscv_ztt_mls_rm_i8_rne_1x1 (u8); /* { dg-error "requires a pointer to" } */
  __riscv_ztt_mls_rm_i8_rne_1x1 (plain); /* { dg-error "requires a pointer to" } */
  __riscv_ztt_mls_rm_i8_rne_1x1 (i16); /* { dg-error "requires a pointer to" } */
  __riscv_ztt_mss_rm (raw, value); /* { dg-error "requires a pointer to writable" } */
  __riscv_ztt_mss_rm (u8, value); /* { dg-error "requires a pointer to writable" } */
  __riscv_ztt_mss_rm (ro, value); /* { dg-error "requires a pointer to writable" } */
  __riscv_ztt_mls_rm_i8_rne_1x1 (io); /* { dg-error "cannot access volatile or atomic memory" } */
  __riscv_ztt_mss_rm (io, value); /* { dg-error "cannot access volatile or atomic memory" } */
  __riscv_ztt_mls_rm_i8_rne_1x1 (atomic_ptr); /* { dg-error "cannot access volatile or atomic memory" } */
  __riscv_ztt_mss_rm (atomic_ptr, value); /* { dg-error "cannot access volatile or atomic memory" } */
}
