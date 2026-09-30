#include <stddef.h>
#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif

void
release_order (unsigned long *p)
{
  *p = 11;
  __riscv_ztt_ame_release ();
  *p = 22;
}

void
acquire_order (unsigned long *p, size_t desc)
{
  *p = 11;
  __riscv_ztt_ame_acquire (desc);
  *p = 22;
}

#ifdef __cplusplus
}
#endif
