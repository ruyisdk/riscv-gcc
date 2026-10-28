#include <riscv_ztt.h>
#ifndef MI_TYPE
#define MI_TYPE u32_rod_sat
#define MI_ELEMENT __UINT32_TYPE__
#define MI_CARRIER __UINT32_TYPE__
#endif
#define MI_NAME_(f,t) __riscv_ztt_##f##_##t##_1x1
#define MI_NAME_I(f,t) MI_NAME_(f,t)
#define MI_NAME(f) MI_NAME_I(f,MI_TYPE)
#define MI_MAKE_(t) __riscv_ztt_scalar_from_bits_##t
#define MI_MAKE(t) MI_MAKE_(t)
#define MI_T_(t) __riscv_ztt_##t##_1x1_t
#define MI_T(t) MI_T_(t)
typedef MI_ELEMENT mi_element;
typedef MI_CARRIER mi_carrier;
typedef MI_T(MI_TYPE) mi_matrix;
#define MI_ARGS const mi_element *in, mi_element *out, mi_element *saved, mi_carrier k
#define MI_LOAD mi_matrix a=MI_NAME(mls_rm) (in)
#define MI_BCAST(k) MI_NAME(mbcast_m_x) (MI_MAKE(MI_TYPE) ((mi_carrier)(k)))
#define MI_INIT MI_LOAD; mi_matrix mask=MI_BCAST(-1)
#define MI_AND(a,b) MI_NAME(mand_ew) (a,b)
#define MI_MIN(a,b) MI_NAME(mmin_ew) (a,b)
#define MI_STORE(v) __riscv_ztt_mss_rm (out,v)
#ifdef __cplusplus
extern "C" {
#endif
extern void mi_callee (void);
extern volatile unsigned long mi_observed;
void mi_and_left (MI_ARGS) { MI_INIT; MI_STORE(MI_AND(mask,a)); }
void mi_and_right (MI_ARGS) { MI_INIT; MI_STORE(MI_AND(a,mask)); }
void mi_min_left (MI_ARGS) { MI_INIT; MI_STORE(MI_MIN(mask,a)); }
void mi_min_right (MI_ARGS) { MI_INIT; MI_STORE(MI_MIN(a,mask)); }
void mi_copy (MI_ARGS)
{ MI_INIT; mi_matrix b=MI_NAME(mcopy_m2m) (mask); MI_STORE(MI_AND(a,b)); }
void mi_live_input (MI_ARGS)
{
  MI_INIT; mi_matrix b=MI_AND(a,mask);
  __riscv_ztt_mss_rm (saved,a); MI_STORE(b);
}
void mi_live_mask (MI_ARGS)
{
  MI_INIT; mi_matrix b=MI_AND(a,mask);
  __riscv_ztt_mss_rm (saved,mask); MI_STORE(b);
}
void mi_after_call (MI_ARGS)
{
  MI_INIT; mi_matrix b=MI_AND(a,mask); mi_callee ();
  __riscv_ztt_mss_rm (saved,mask); MI_STORE(b);
}
void mi_call (MI_ARGS) { MI_INIT; mi_callee (); MI_STORE(MI_AND(a,mask)); }
void mi_asm (MI_ARGS)
{ MI_INIT; asm volatile ("" ::: "memory"); MI_STORE(MI_AND(a,mask)); }
void mi_memory (MI_ARGS) { MI_INIT; mi_observed=11; MI_STORE(MI_AND(a,mask)); }
void mi_dynamic (MI_ARGS)
{ MI_LOAD; mi_matrix b=MI_BCAST(k); MI_STORE(MI_AND(a,b)); }
void mi_partial (MI_ARGS)
{ MI_LOAD; mi_matrix b=MI_BCAST(0x7f); MI_STORE(MI_AND(a,b)); }
void mi_zero (MI_ARGS)
{ MI_LOAD; mi_matrix b=MI_BCAST(0); MI_STORE(MI_AND(a,b)); }
void mi_mixed_scalar (MI_ARGS)
{
  MI_LOAD;
  mi_matrix b=MI_NAME(mbcast_m_x) (__riscv_ztt_scalar_from_bits_i16_rne
    ((__UINT16_TYPE__) -1));
  MI_STORE(MI_AND(a,b));
}
void mi_or (MI_ARGS) { MI_INIT; MI_STORE(MI_NAME(mor_ew) (a,mask)); }
void mi_reference (MI_ARGS) { MI_INIT; MI_STORE(a); }
#ifdef __cplusplus
}
#endif
