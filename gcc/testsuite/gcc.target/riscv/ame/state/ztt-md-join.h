#include "ztt-md-branch.h"
#include "ztt-md-nested.h"
#ifdef __cplusplus
extern "C" {
#endif
void join_call_arm (const element *in, element *out, unsigned flag)
{
  matrix a = __riscv_ztt_mls_rm_i32_1x1 (in);
  if (flag)
    split_callee ();
  __riscv_ztt_mss_rm (out, a);
}
void join_asm_arm (const element *in, element *out, unsigned flag)
{
  matrix a = __riscv_ztt_mls_rm_i32_1x1 (in);
  if (flag)
    asm volatile ("" ::: "memory");
  __riscv_ztt_mss_rm (out, a);
}
void join_diamond (const element *in, const element *other,
                   element *out, unsigned flag)
{
  matrix a;
  if (flag)
    {
      matrix b = __riscv_ztt_mls_rm_i32_1x1 (in);
      a = __riscv_ztt_madd_ew_i32_1x1 (b, b);
    }
  else
    {
      matrix b = __riscv_ztt_mls_rm_i32_1x1 (other);
      a = __riscv_ztt_msub_ew_i32_1x1 (b, b);
    }
  __riscv_ztt_mss_rm (out, a);
}
void join_missing (const element *in, element *out, unsigned flag)
{
  matrix a = __riscv_ztt_mls_rm_i32_1x1 (in);
  switch (flag)
    {
    case 0: a = __riscv_ztt_madd_ew_i32_1x1 (a, a); break;
    case 1: a = __riscv_ztt_msub_ew_i32_1x1 (a, a); break;
    default: asm volatile ("" ::: "memory"); break;
    }
  __riscv_ztt_mss_rm (out, a);
}
#ifdef __cplusplus
}
#endif
