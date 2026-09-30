/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu11 -Werror=implicit-function-declaration -march=rv32i_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-options "-O2 -std=gnu11 -Werror=implicit-function-declaration -march=rv64i_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */

#include <stddef.h>
#ifdef __riscv_ztt_profile
#error "Observers must not select a typed profile"
#endif
#ifdef __riscv_vector
#error "Observers do not require V"
#endif

size_t without_profile (size_t desc)
{
  size_t result = __builtin_riscv_ztt_acquire (desc);
  result += __builtin_riscv_ztt_get_ameown ();
  result += __builtin_riscv_ztt_get_amestype ();
  result += __builtin_riscv_ztt_get_amenlen ();
  result += __builtin_riscv_ztt_get_ameudsz ();
  result += __builtin_riscv_ztt_get_amefflags ();
  result += __builtin_riscv_ztt_get_amexsat ();
  result += __builtin_riscv_ztt_get_amestatus ();
  __builtin_riscv_ztt_ame_release ();
  return result;
}
/* { dg-final { scan-assembler-times {csrr\t[^,]+,ameown} 1 } } */
/* { dg-final { scan-assembler-times {csrr\t[^,]+,amestype} 1 } } */
/* { dg-final { scan-assembler-times {csrr\t[^,]+,amenlen} 1 } } */
/* { dg-final { scan-assembler-times {csrr\t[^,]+,ameudsz} 1 } } */
/* { dg-final { scan-assembler-times {csrr\t[^,]+,amefflags} 1 } } */
/* { dg-final { scan-assembler-times {csrr\t[^,]+,amexsat} 1 } } */
/* { dg-final { scan-assembler-times {csrr\t[^,]+,amestatus} 1 } } */
/* { dg-final { scan-assembler-not {csrw|s11|msettyp|asettyp|call\s} } } */
