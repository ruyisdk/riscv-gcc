/* { dg-do compile } */
/* { dg-options "-std=gnu11 -O2 -fdiagnostics-plain-output -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-std=gnu11 -O2 -fdiagnostics-plain-output -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>

__riscv_ztt_i8_rne_1x1_t global_value; /* { dg-error "does not have a fixed C object size" } */
_Thread_local __riscv_ztt_i8_rne_1x1_t thread_value; /* { dg-error "cannot have thread-local storage duration" } */

struct bad_field
{
  __riscv_ztt_i8_rne_1x1_t value; /* { dg-error "fields cannot have AME/Ztt type" } */
};

void
bad_contexts (__riscv_ztt_i8_rne_1x1_t *pointer)
{
  __riscv_ztt_i8_rne_1x1_t array[2]; /* { dg-error "array elements cannot have AME/Ztt type" } */
  (void) sizeof (__riscv_ztt_i8_rne_1x1_t); /* { dg-error "does not have a fixed C object size" } */
  (void) _Alignof (__riscv_ztt_i8_rne_1x1_t); /* { dg-error "does not have a defined C alignment" } */
  ++pointer; /* { dg-error "arithmetic on pointer to AME/Ztt type" } */
  (void) *pointer; /* { dg-error "cannot dereference pointer to AME/Ztt type" } */
  (void) array;
}
