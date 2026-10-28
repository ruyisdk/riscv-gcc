#include <riscv_ztt.h>
#ifndef MO_TYPE
#define MO_TYPE i32_rnu
#define MO_ELEMENT __INT32_TYPE__
#endif
#define MO_NAME_(f,t) __riscv_ztt_##f##_##t##_1x1
#define MO_NAME_I(f,t) MO_NAME_(f,t)
#define MO_NAME(f) MO_NAME_I(f,MO_TYPE)
#ifdef MO_BITS
#define MO_MAKE_(t) __riscv_ztt_scalar_from_bits_##t
#define MO_SCALAR(k) ((unsigned long)(k))
#else
#define MO_MAKE_(t) __riscv_ztt_scalar_make_##t
#define MO_SCALAR(k) ((mo_element)(k))
#endif
#define MO_MAKE(t) MO_MAKE_(t)
#define MO_T_(t) __riscv_ztt_##t##_1x1_t
#define MO_T(t) MO_T_(t)
typedef MO_ELEMENT mo_element;
typedef MO_T(MO_TYPE) mo_matrix;
#define MO_ARGS const mo_element *in, mo_element *out, mo_element *saved, mo_element k
#define MO_LOAD mo_matrix a = MO_NAME(mls_rm) (in)
#define MO_BCAST(k) MO_NAME(mbcast_m_x) (MO_MAKE(MO_TYPE) (MO_SCALAR(k)))
#define MO_INIT MO_LOAD; mo_matrix one = MO_BCAST(1)
#define MO_MUL(a,b) MO_NAME(mmul_ew) (a,b)
#define MO_STORE(v) __riscv_ztt_mss_rm (out,v)
#ifdef __cplusplus
extern "C" {
#endif
extern void mo_callee (void);
extern volatile unsigned long mo_observed;
void mo_left (MO_ARGS) { MO_INIT; MO_STORE(MO_MUL(one,a)); }
void mo_right (MO_ARGS) { MO_INIT; MO_STORE(MO_MUL(a,one)); }
void mo_copy (MO_ARGS)
{
  MO_INIT;
  mo_matrix b = MO_NAME(mcopy_m2m) (one);
  MO_STORE(MO_MUL(a,b));
}
void mo_live_input (MO_ARGS)
{
  MO_INIT; mo_matrix b = MO_MUL(a,one);
  __riscv_ztt_mss_rm (saved,a); MO_STORE(b);
}
void mo_live_one (MO_ARGS)
{
  MO_INIT; mo_matrix b = MO_MUL(a,one);
  __riscv_ztt_mss_rm (saved,one); MO_STORE(b);
}
void mo_after_call (MO_ARGS)
{
  MO_INIT; mo_matrix b = MO_MUL(a,one);
  mo_callee (); __riscv_ztt_mss_rm (saved,one); MO_STORE(b);
}
void mo_call (MO_ARGS) { MO_INIT; mo_callee (); MO_STORE(MO_MUL(a,one)); }
void mo_asm (MO_ARGS)
{
  MO_INIT; asm volatile ("" ::: "memory"); MO_STORE(MO_MUL(a,one));
}
void mo_memory (MO_ARGS) { MO_INIT; mo_observed=11; MO_STORE(MO_MUL(a,one)); }
void mo_dynamic (MO_ARGS) { MO_LOAD; mo_matrix b=MO_BCAST(k); MO_STORE(MO_MUL(a,b)); }
void mo_two (MO_ARGS) { MO_LOAD; mo_matrix b=MO_BCAST(2); MO_STORE(MO_MUL(a,b)); }
void mo_negative_one (MO_ARGS)
{ MO_LOAD; mo_matrix b=MO_BCAST(-1); MO_STORE(MO_MUL(a,b)); }
void mo_mixed_scalar (MO_ARGS)
{
  MO_LOAD;
  mo_matrix b=MO_NAME(mbcast_m_x) (__riscv_ztt_scalar_make_i16_rne (1));
  MO_STORE(MO_MUL(a,b));
}
void mo_negate (MO_ARGS) { MO_INIT; MO_STORE(MO_NAME(mmulneg_ew) (a,one)); }
void mo_reference (MO_ARGS) { MO_INIT; MO_STORE(a); }
#ifdef __cplusplus
}
#endif
