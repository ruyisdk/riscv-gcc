/* local v0.2.3 groundwork.  */
/* { dg-do compile } */
/* { dg-options "-O3 -march=rv32i_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-options "-O3 -march=rv64i_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */

#ifndef __riscv_ztt_runtime_queries
#error "Runtime CSR queries must be available without V or a typed profile"
#endif
#ifdef __riscv_ztt_profile
#error "Runtime queries must not select a fixed-N profile"
#endif
#ifdef __riscv_ztt_n
#error "Runtime N must not be advertised as a compile-time constant"
#endif

unsigned long
observe_backend (unsigned long request)
{
  unsigned long first = __builtin_riscv_ztt_read_amenlen ();
  __builtin_riscv_ztt_read_amenlen ();
  __builtin_riscv_ztt_ame_release ();
  unsigned long acquired = __builtin_riscv_ztt_ame_acquire (request);
  unsigned long second = __builtin_riscv_ztt_read_amenlen ();
  return first + second + acquired + __builtin_riscv_ztt_read_ameudsz ();
}

/* Repeated and discarded reads remain observations across ownership changes.  */
/* { dg-final { scan-assembler-times "csrr\t\[a-z0-9\]+,amenlen" 3 } } */
/* { dg-final { scan-assembler-times "csrr\t\[a-z0-9\]+,ameudsz" 1 } } */
/* { dg-final { scan-assembler "amenlen(.|\n)*ame\\.release(.|\n)*ame\\.acquire(.|\n)*amenlen" } } */
