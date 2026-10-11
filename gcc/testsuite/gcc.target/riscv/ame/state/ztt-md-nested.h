#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef __INT32_TYPE__ element;
typedef __riscv_ztt_i32_1x1_t matrix;
extern void nested_callee (void);

#define NESTED(NAME, BARRIER, OUTER) \
void NAME (const element *in, element *out, unsigned flag) \
{ \
  matrix a = __riscv_ztt_mls_rm_i32_1x1 (in); \
  BARRIER; \
  if (flag & 1) \
    { \
      if (flag & 2) \
        a = __riscv_ztt_madd_ew_i32_1x1 (a, a); \
      else \
        a = __riscv_ztt_msub_ew_i32_1x1 (a, a); \
    } \
  else \
    a = OUTER; \
  __riscv_ztt_mss_rm (out, a); \
}

NESTED (nested_binary, (void) 0, __riscv_ztt_mmul_ew_i32_1x1 (a, a))
NESTED (nested_rowcol, (void) 0, __riscv_ztt_mcolbcast_ew_x_i32_1x1 (a, 1))
NESTED (nested_call, nested_callee (), __riscv_ztt_mmul_ew_i32_1x1 (a, a))
NESTED (nested_asm, __asm__ volatile ("" ::: "memory"),
        __riscv_ztt_mmul_ew_i32_1x1 (a, a))
#undef NESTED

void nested_deep (const element *in, element *out, unsigned flag)
{
  matrix a = __riscv_ztt_mls_rm_i32_1x1 (in);
  if (flag & 1)
    {
      if (flag & 2)
        {
          if (flag & 4)
            a = __riscv_ztt_madd_ew_i32_1x1 (a, a);
          else
            a = __riscv_ztt_msub_ew_i32_1x1 (a, a);
        }
      else
        a = __riscv_ztt_mrowbcast_ew_x_i32_1x1 (a, 1);
    }
  else
    a = __riscv_ztt_mcolbcast_ew_x_i32_1x1 (a, 1);
  __riscv_ztt_mss_rm (out, a);
}

void nested_join (const element *in, element *out, unsigned flag)
{
  matrix a = __riscv_ztt_mls_rm_i32_1x1 (in);
  if (flag & 1)
    a = __riscv_ztt_madd_ew_i32_1x1 (a, a);
  if (flag & 2)
    a = __riscv_ztt_mrowbcast_ew_x_i32_1x1 (a, 1);
  __riscv_ztt_mss_rm (out, a);
}
#ifdef __cplusplus
}
#endif
