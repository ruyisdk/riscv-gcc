#include <stdint.h>
#include <riscv_ztt.h>

#define VALUES(F) \
  F(0) F(1) F(2) F(3) F(4) F(5) F(6) F(7) F(8) F(9) F(10) F(11) \
  F(12) F(13) F(14) F(15) F(16) F(17) F(18) F(19) F(20) F(21) F(22) F(23)
#define READ(I) unsigned long v##I = control[I];
#define MIX(I) result = (result ^ v##I) * 33 + v##I;
#define SPILL_CASE(NAME, TAIL) \
void NAME (const int32_t *in, int32_t *out, \
           volatile unsigned long *control, unsigned long *status, int flag) \
{ \
  VALUES (READ) \
  __riscv_ztt_i32_rnu_1x1_t m = __riscv_ztt_mls_rm_i32_rnu_1x1 (in); \
  __riscv_ztt_i32_rnu_accx1_t a = __riscv_ztt_mcopy_m2a_i32_rnu_accx1 (m); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (a)); \
  unsigned long result = out[0]; \
  VALUES (MIX) \
  TAIL; \
}
#ifdef __cplusplus
extern "C" {
#endif
SPILL_CASE (spill_two_exits, if (flag) status[0] = result; else status[1] = result + 1)
SPILL_CASE (spill_three_exits, if (flag < 0) status[0] = result;
      else if (flag) status[1] = result + 1; else status[2] = result + 2)
#ifdef __cplusplus
}
#endif
#undef SPILL_CASE
#undef MIX
#undef READ
#undef VALUES
