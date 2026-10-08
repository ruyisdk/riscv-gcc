#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef __INT32_TYPE__ cfg_elem;
#define CFG_FN __attribute__((noinline,noclone))
#define CFG_COPY(O, I) __riscv_ztt_mss_rm ((O), __riscv_ztt_mls_rm_i32_1x1 (I))

CFG_FN void workspace_while (cfg_elem *out, const cfg_elem *in,
                             unsigned long count)
{
  while (count--)
    {
      CFG_COPY (out, in);
      ++out;
      ++in;
    }
}

CFG_FN void workspace_do (cfg_elem *out, const cfg_elem *in,
                          unsigned long count)
{
  do
    {
      CFG_COPY (out, in);
      ++out;
      ++in;
    }
  while (--count);
}

CFG_FN void workspace_break (cfg_elem *out, const cfg_elem *in,
                             unsigned long count, const volatile int *stop)
{
  for (unsigned long i = 0; i < count; ++i)
    {
      if (i == (unsigned long) *stop)
        break;
      CFG_COPY (out + i, in + i);
    }
}

CFG_FN void workspace_diamond (cfg_elem *out, const cfg_elem *a,
                               const cfg_elem *b, int choice)
{
  if (choice)
    CFG_COPY (out, a);
  else
    CFG_COPY (out, b);
}

CFG_FN void workspace_early (cfg_elem *out, const cfg_elem *in,
                             unsigned long count, int skip)
{
  if (skip)
    return;
  for (unsigned long i = 0; i < count; ++i)
    CFG_COPY (out + i, in + i);
}

#undef CFG_FN
#undef CFG_COPY
#ifdef __cplusplus
}
#endif
