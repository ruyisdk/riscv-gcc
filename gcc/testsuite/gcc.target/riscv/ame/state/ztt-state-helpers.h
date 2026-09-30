/* Shared C/C++ fixture, not an independent test.  */
#include <stddef.h>
#include <riscv_ztt.h>

#ifdef __cplusplus
template<class A, class B> struct same { enum { value = 0 }; };
template<class A> struct same<A, A> { enum { value = 1 }; };
#define CHECK_TYPE(EXPR, TYPE) static_assert (same<decltype (EXPR), TYPE>::value, #EXPR)
extern "C" {
#else
#define CHECK_TYPE(EXPR, TYPE) \
  _Static_assert (__builtin_types_compatible_p (__typeof__ (EXPR), TYPE), #EXPR)
#endif

#define KEEP __attribute__((noinline, noclone, used, externally_visible))
#define OBSERVE(NAME) \
  CHECK_TYPE (__riscv_ztt_get_##NAME (), size_t); \
  KEEP size_t get_##NAME (void) { return __riscv_ztt_get_##NAME (); } \
  KEEP void discard_##NAME (void) { __riscv_ztt_get_##NAME (); }
OBSERVE (ameown)
OBSERVE (amestype)
OBSERVE (amenlen)
OBSERVE (ameudsz)
OBSERVE (amefflags)
OBSERVE (amexsat)
OBSERVE (amestatus)
#undef OBSERVE

CHECK_TYPE (__riscv_ztt_ame_acquire ((size_t) 0), size_t);
CHECK_TYPE (__riscv_ztt_ame_release (), void);

KEEP size_t observe_ownership (size_t desc)
{
  size_t before = __riscv_ztt_get_ameown ();
  __riscv_ztt_ame_release ();
  size_t acquired = __riscv_ztt_ame_acquire (desc);
  size_t after = __riscv_ztt_get_ameown ();
  return before + acquired + after;
}

KEEP void discarded_acquire (volatile size_t *desc)
{
  __riscv_ztt_ame_acquire (*desc);
  __riscv_ztt_ame_release ();
}

#ifdef __cplusplus
}
#endif
#undef CHECK_TYPE
#undef KEEP
