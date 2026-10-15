#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
extern void asm_descriptor_callee (void);
#define AD_ARGS const float *in, float *out, float *last, \
  unsigned char *scratch, unsigned long token
#define AD_METADATA \
  __asm__ volatile ("csrr t0,ameudsz\n\tli t1,0x40000000\n\tor t0,t0,t1\n\t" \
                    "csrw amestype,t0\n\t" \
                    ".irp r,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15," \
                    "16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31\n\t" \
                    "mss.1r m\\r,%0\n\tmsettyp m\\r,t0\n\tmls.1r m\\r,%0\n\t.endr" \
                    : : "r" (scratch) : "t0", "t1", "memory")
#define AD_CHAIN(NAME, GAP) \
unsigned long asm_##NAME (AD_ARGS) \
{ \
  __riscv_ztt_f32_1x1_t a = __riscv_ztt_mls_rm_f32_1x1 (in); \
  a = __riscv_ztt_mrowbcast_ew_x_f32_1x1 (a, 0); \
  __riscv_ztt_mss_rm (out, a); \
  GAP; \
  a = __riscv_ztt_madd_ew_f32_1x1 (a, a); \
  __riscv_ztt_mss_rm (last, a); \
  return token; \
}
AD_CHAIN (memory, __asm__ volatile ("# AME state boundary" ::: "memory"))
AD_CHAIN (gpr, __asm__ volatile ("li t0,7\n\tli t1,9" ::: "t0", "t1", "memory"))
AD_CHAIN (output, __asm__ volatile ("li %0,9" : "=r" (token) : : "memory"))
AD_CHAIN (readwrite, __asm__ volatile ("addi %0,%0,1" : "+r" (token) : : "memory"))
AD_CHAIN (partial, unsigned small = token;
          __asm__ volatile ("addi %0,%0,2" : "+r" (small) : : "memory"); token = small)
AD_CHAIN (metadata, AD_METADATA)
AD_CHAIN (basic, __asm__ volatile ("nop"))
AD_CHAIN (branch, __asm__ goto ("beq %0,zero,%l1" : : "r" (token) : "memory" : done);
          __asm__ volatile ("nop" ::: "memory"); done:)
AD_CHAIN (call, asm_descriptor_callee ())

unsigned long asm_scalar (AD_ARGS)
{
  __riscv_ztt_f32_1x1_t a = __riscv_ztt_mls_rm_f32_1x1 (in);
  __riscv_ztt_f32_rne_scalar_t one = __riscv_ztt_scalar_from_bits_f32_rne (0x3f800000);
  a = __riscv_ztt_madd_ew_x_f32_rne_1x1_f32_rne (a, one);
  __riscv_ztt_mss_rm (out, a);
  AD_METADATA;
  a = __riscv_ztt_madd_ew_x_f32_rne_1x1_f32_rne (a, one);
  __riscv_ztt_mss_rm (last, a);
  return token;
}
#ifdef __cplusplus
}
#endif
#undef AD_ARGS
#undef AD_METADATA
#undef AD_CHAIN
