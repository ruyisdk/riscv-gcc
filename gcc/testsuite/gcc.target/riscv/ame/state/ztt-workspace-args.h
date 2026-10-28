#include "../matrix/ternary/ztt-mixed-old-copy.h"

#define WS_ARGS const tc_element *old, const ta_element *left, \
  tc_element *out, tc_element *saved, ta_element *asaved, \
  long p5, long p6, long p7
#define WS_BODY \
  TC_LOAD_SCALAR; \
  TC_STORE (out, TC_SCALAR); \
  TC_STORE (saved, d); \
  TC_STORE (asaved, a)

#ifdef __cplusplus
extern "C" {
#endif
void ws_signed (WS_ARGS, signed char control)
{
  long e = control;
  WS_BODY;
}
void ws_unsigned (WS_ARGS, unsigned char control)
{
  long e = control;
  WS_BODY;
}
void ws_second (WS_ARGS, long unused, long e)
{
  WS_BODY;
}
void ws_local (WS_ARGS, long control)
{
  volatile long local[4];
  local[0] = control;
  long e = local[0];
  WS_BODY;
}
void ws_frame (WS_ARGS, long control)
{
  long e = control;
  WS_BODY;
  *(void **) out = __builtin_frame_address (0);
}
#ifdef __cplusplus
}
#endif
