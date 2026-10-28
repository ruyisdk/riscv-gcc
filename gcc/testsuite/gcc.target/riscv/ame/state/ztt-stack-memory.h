#include <stdint.h>
#include <riscv_ztt.h>

#define VALUES(F) \
  F(0) F(1) F(2) F(3) F(4) F(5) F(6) F(7) F(8) F(9) F(10) F(11) \
  F(12) F(13) F(14) F(15) F(16) F(17) F(18) F(19) F(20) F(21) F(22) F(23)
#define READ(I) unsigned long v##I = control[I];
#define INPUT(I) "r" (v##I)
#define OUTPUT(I) "+r" (v##I)
#define SUM(I) + v##I

#ifdef __cplusplus
extern "C"
#endif
unsigned long stack_memory (const int32_t *in, int32_t *out,
                            volatile unsigned long *control)
{
  VALUES (READ)
  __asm__ volatile ("" : :
    INPUT(0), INPUT(1), INPUT(2), INPUT(3), INPUT(4), INPUT(5),
    INPUT(6), INPUT(7), INPUT(8), INPUT(9), INPUT(10), INPUT(11),
    INPUT(12), INPUT(13), INPUT(14), INPUT(15), INPUT(16), INPUT(17),
    INPUT(18), INPUT(19), INPUT(20), INPUT(21), INPUT(22), INPUT(23) : "memory");
  __riscv_ztt_i32_rnu_1x1_t m = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  __riscv_ztt_i32_rnu_accx1_t a = __riscv_ztt_mcopy_m2a_i32_rnu_accx1 (m);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (a));
  __asm__ volatile ("" :
    OUTPUT(0), OUTPUT(1), OUTPUT(2), OUTPUT(3), OUTPUT(4), OUTPUT(5),
    OUTPUT(6), OUTPUT(7), OUTPUT(8), OUTPUT(9), OUTPUT(10), OUTPUT(11) : : "memory");
  __asm__ volatile ("" :
    OUTPUT(12), OUTPUT(13), OUTPUT(14), OUTPUT(15), OUTPUT(16), OUTPUT(17),
    OUTPUT(18), OUTPUT(19), OUTPUT(20), OUTPUT(21), OUTPUT(22), OUTPUT(23) : : "memory");
  return 0 VALUES (SUM);
}
#undef SUM
#undef OUTPUT
#undef INPUT
#undef READ
#undef VALUES
