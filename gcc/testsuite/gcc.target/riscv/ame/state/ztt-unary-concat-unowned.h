#include <riscv_ztt.h>
#ifndef UP_TYPE
#define UP_TYPE i32_rnu
#define UP_CARRIER __INT32_TYPE__
#endif
#define T_(D,S) __riscv_ztt_##D##_##S##_t
#define T(D,S) T_ (D,S)
#define F_(OP,D,S) __riscv_ztt_##OP##_##D##_##S
#define F(OP,D,S) F_ (OP,D,S)
void unowned (const UP_CARRIER *in, const UP_CARRIER *other,
              UP_CARRIER *out)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  T (UP_TYPE,1x1) a = F (mls_rm,UP_TYPE,1x1) (in);
  T (UP_TYPE,1x1) b = F (mls_rm,UP_TYPE,1x1) (other);
  __riscv_ztt_ame_release ();
  T (UP_TYPE,1x2) p = F (mconcat_m,UP_TYPE,1x2) (a,b);
  T (UP_TYPE,1x2) d = F (mabs_ew,UP_TYPE,1x2) (p);
  if (!(__riscv_ztt_ame_acquire (0) & 1)) return;
  __riscv_ztt_mss_rm (out,d);
  __riscv_ztt_ame_release ();
}
