#include <riscv_ztt.h>
#ifndef MC_TYPE
#define MC_TYPE i32
#define MC_CARRIER __INT32_TYPE__
#endif
#define MC_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define MC_NAME(f, t) MC_NAME_(f, t)
#define MC_T_(t) __riscv_ztt_##t##_1x1_t
#define MC_T(t) MC_T_(t)
typedef MC_CARRIER element_t;
#define HIGH ((unsigned long) 0xabcdef1200000002ULL)
#define INVALID ((unsigned long) 0xabcdef12ffffffffULL)
#define ARGS const element_t *in, element_t *out0, element_t *out1, \
  element_t *out2, volatile unsigned long *full
#define LOAD MC_T(MC_TYPE) a = MC_NAME(mls_rm, MC_TYPE) (in)
#define ROW(value, out) \
  __riscv_ztt_mss_rm (out, MC_NAME(mrowbcast_ew_x, MC_TYPE) (a, value))
#define COL(value, out) \
  __riscv_ztt_mss_rm (out, MC_NAME(mcolbcast_ew_x, MC_TYPE) (a, value))
#ifdef __cplusplus
extern "C" {
#endif
extern void mc_callee (void);
unsigned long mc_two (ARGS)
{ LOAD; ROW(HIGH,out0); COL(HIGH,out1); return 0; }
unsigned long mc_three (ARGS)
{ LOAD; ROW(HIGH,out0); COL(HIGH,out1); ROW(HIGH,out2); return 0; }
unsigned long mc_return (ARGS)
{ LOAD; ROW(HIGH,out0); COL(HIGH,out1); return HIGH; }
unsigned long mc_store (ARGS)
{ LOAD; ROW(HIGH,out0); COL(HIGH,out1); *full=HIGH; return 0; }
unsigned long mc_between (ARGS)
{ LOAD; ROW(HIGH,out0); *full=HIGH; COL(HIGH,out1); return 0; }
unsigned long mc_asm (ARGS)
{ LOAD; ROW(HIGH,out0); asm volatile ("" ::: "memory"); COL(HIGH,out1); return 0; }
unsigned long mc_asm_full (ARGS)
{ LOAD; ROW(HIGH,out0); asm volatile ("" :: "r" (HIGH)); COL(HIGH,out1); return 0; }
unsigned long mc_call (ARGS)
{ LOAD; ROW(HIGH,out0); mc_callee (); COL(HIGH,out1); return 0; }
unsigned long mc_dynamic (ARGS)
{ unsigned long k=*full; LOAD; ROW(k,out0); COL(k,out1); return k; }
unsigned long mc_invalid (ARGS)
{ LOAD; ROW(INVALID,out0); COL(INVALID,out1); return 0; }
unsigned long mc_invalid_late (ARGS)
{ LOAD; ROW(HIGH,out0); COL(INVALID,out1); ROW(INVALID,out2); return 0; }
#ifdef __cplusplus
}
#endif
