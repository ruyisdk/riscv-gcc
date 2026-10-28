#ifndef UI_TYPE
#define UI_TYPE f32_rne
#define UI_ELEMENT float
#endif
#include "ztt-unary-idempotent.h"
#ifdef __cplusplus
extern "C" {
#endif
UI_CASE(fpflags, mabs_ew, __asm__ volatile ("csrw amefflags,zero" ::: "memory"),
        mabs_ew, , )
#ifdef __cplusplus
}
#endif
