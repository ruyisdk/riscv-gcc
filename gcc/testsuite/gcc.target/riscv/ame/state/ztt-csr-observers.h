#include <stdint.h>
#include <riscv_ztt.h>
#ifndef OB_TYPE
#define OB_TYPE i32_rnu
#define OB_CARRIER int32_t
#endif
#define OB_NAME_I(OP, TYPE) __riscv_ztt_##OP##_##TYPE##_1x1
#define OB_NAME_X(OP, TYPE) OB_NAME_I (OP, TYPE)
#define OB(OP) OB_NAME_X (OP, OB_TYPE)
#define OB_VALUE_I(TYPE) __riscv_ztt_##TYPE##_1x1_t
#define OB_VALUE_X(TYPE) OB_VALUE_I (TYPE)
#define OB_VALUE OB_VALUE_X (OB_TYPE)
#define OB_ARGS const OB_CARRIER *in, const OB_CARRIER *other, OB_CARRIER *out
#define OB_FN(NAME) __attribute__((noipa)) unsigned long NAME (OB_ARGS)
#define OB_LOAD OB_VALUE a = OB (mls_rm) (in)
#define OB_STORE __riscv_ztt_mss_rm (out, a)

#ifdef __cplusplus
extern "C" {
#endif
#ifndef OB_ADD_ONLY
#define OBSERVE(CSR) \
OB_FN (observe_##CSR) \
{ \
  OB_LOAD; \
  unsigned long value = __riscv_ztt_get_##CSR (); \
  OB_STORE; \
  return value; \
}
OBSERVE (amenlen)
OBSERVE (ameudsz)
OBSERVE (ameown)
OBSERVE (amestype)
OBSERVE (amefflags)
OBSERVE (amexsat)
OBSERVE (amestatus)

OB_FN (observe_discarded)
{
  OB_LOAD;
  __riscv_ztt_get_amefflags ();
  OB_STORE;
  return 0;
}

OB_FN (observe_repeated)
{
  OB_LOAD;
  unsigned long first = __riscv_ztt_get_amefflags ();
  unsigned long second = __riscv_ztt_get_amefflags ();
  OB_STORE;
  return first + second;
}

OB_FN (observe_asm)
{
  OB_LOAD;
  unsigned long value;
  __asm__ volatile ("csrr %0,amefflags" : "=r" (value) :: "memory");
  OB_STORE;
  return value;
}

OB_FN (observe_write)
{
  OB_LOAD;
  __asm__ volatile ("csrw amefflags,%0" :: "r" (4UL) : "memory");
  unsigned long value = __riscv_ztt_get_amefflags ();
  OB_STORE;
  return value;
}

extern void observer_callee (void);
OB_FN (observe_call)
{
  OB_LOAD;
  observer_callee ();
  unsigned long value = __riscv_ztt_get_amefflags ();
  OB_STORE;
  return value;
}

OB_FN (observe_then_asm)
{
  OB_LOAD;
  unsigned long value = __riscv_ztt_get_amefflags ();
  __asm__ volatile ("" ::: "memory");
  OB_STORE;
  return value;
}
#endif

OB_FN (observe_add)
{
  OB_LOAD;
  OB_VALUE b = OB (mls_rm) (other);
  OB_VALUE first = OB (madd_ew) (a, b);
  unsigned long value = __riscv_ztt_get_amefflags ();
  OB_VALUE second = OB (madd_ew) (first, b);
  __riscv_ztt_mss_rm (out, second);
  return value;
}
#ifdef __cplusplus
}
#endif
