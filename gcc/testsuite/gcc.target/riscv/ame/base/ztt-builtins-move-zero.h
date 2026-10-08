#ifdef __cplusplus
extern "C" {
#endif

#define EFFECT(P) ((void) (*(P) = *(P) + 1), 0)
#define INGRESS(NAME) \
void data_zero_##NAME (void) \
{ __builtin_riscv_ztt_##NAME (15, 0, 32); } \
void second_zero_##NAME (void) \
{ __builtin_riscv_ztt_##NAME (15, 31, 0); } \
void both_zero_##NAME (void) \
{ __builtin_riscv_ztt_##NAME (15, 0, 0); } \
void dynamic_##NAME (unsigned long x, unsigned long y) \
{ __builtin_riscv_ztt_##NAME (15, x, y); } \
void effect_##NAME (volatile unsigned long *p, unsigned long y) \
{ __builtin_riscv_ztt_##NAME (15, EFFECT (p), y); }

INGRESS (mbcast_m_x)
INGRESS (mmove8_m_x)
INGRESS (mmove16_m_x)
INGRESS (mmove32_m_x)
INGRESS (mmove64_m_x)
#undef INGRESS

#define EGRESS(NAME) \
unsigned long position_zero_##NAME (void) \
{ return __builtin_riscv_ztt_##NAME (15, 0); } \
unsigned long dynamic_##NAME (unsigned long position) \
{ return __builtin_riscv_ztt_##NAME (15, position); } \
unsigned long effect_##NAME (volatile unsigned long *p) \
{ return __builtin_riscv_ztt_##NAME (15, EFFECT (p)); }

EGRESS (mmove8_x_m)
EGRESS (mmove16_x_m)
EGRESS (mmove32_x_m)
EGRESS (mmove64_x_m)
#undef EGRESS

void
effect_position (unsigned long x, volatile unsigned long *p)
{
  __builtin_riscv_ztt_mmove32_m_x (15, x, EFFECT (p));
}
#undef EFFECT

#ifdef __cplusplus
}
#endif
