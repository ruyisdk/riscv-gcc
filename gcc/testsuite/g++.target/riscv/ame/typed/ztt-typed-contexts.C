/* { dg-do compile } */
/* { dg-options "-std=gnu++17 -O2 -fdiagnostics-plain-output -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-std=gnu++17 -O2 -fdiagnostics-plain-output -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>

void
bad_dereference (__riscv_ztt_i8_rne_1x1_t *pointer)
{
  (void) *pointer; /* { dg-error "cannot dereference pointer to AME/Ztt type" } */
}

void
bad_allocation ()
{
  __riscv_ztt_i8_rne_1x1_t *pointer
    = new __riscv_ztt_i8_rne_1x1_t; /* { dg-error "cannot allocate objects with AME/Ztt type" } */
  delete pointer; /* { dg-error "cannot delete objects with AME/Ztt type" } */
}

void
bad_exception ()
{
  __riscv_ztt_i8_rne_1x1_t value
    = __riscv_ztt_mzero_2d_m_i8_rne_1x1 ();
  throw value; /* { dg-error "cannot throw or catch AME/Ztt type" } */
}

void
bad_capture ()
{
  __riscv_ztt_i8_rne_1x1_t value
    = __riscv_ztt_mzero_2d_m_i8_rne_1x1 ();
  [value] {} (); /* { dg-error "capture by copy of AME/Ztt type" } */
}
