#include <riscv_ztt.h>
#ifndef CV_TYPE
#define CV_TYPE i32_rnu
#define CV_OTHER i32_rdn
#define CV_CARRIER __INT32_TYPE__
#endif
#ifndef CV_SHAPE
#define CV_SHAPE 1x1
#endif
#define CV_N_(f,t,s) __riscv_ztt_##f##_##t##_##s
#define CV_N(f,t,s) CV_N_(f,t,s)
#define CV_T_(t,s) __riscv_ztt_##t##_##s##_t
#define CV_T(t,s) CV_T_(t,s)
typedef CV_CARRIER cv_element;
#define CV_ARGS const cv_element *in, cv_element *out, cv_element *extra
#define CV_LOAD CV_T(CV_TYPE,CV_SHAPE) a = CV_N(mls_rm,CV_TYPE,CV_SHAPE) (in)
#define CV_CONVERT CV_T(CV_TYPE,CV_SHAPE) b = CV_N(mconv_ew,CV_TYPE,CV_SHAPE) (a)
#ifdef __cplusplus
extern "C" {
#endif
extern void cv_callee (void);
void cv_same (CV_ARGS)
{
  CV_LOAD; CV_CONVERT;
  __riscv_ztt_mss_rm (out,b);
}
void cv_live (CV_ARGS)
{
  CV_LOAD; CV_CONVERT;
  __riscv_ztt_mss_rm (out,b);
  __riscv_ztt_mss_rm (extra,a);
}
void cv_call (CV_ARGS)
{
  CV_LOAD; CV_CONVERT;
  cv_callee ();
  __riscv_ztt_mss_rm (out,b);
  __riscv_ztt_mss_rm (extra,a);
}
void cv_unused (CV_ARGS)
{
  CV_LOAD;
  CV_N(mconv_ew,CV_TYPE,CV_SHAPE) (a);
  __riscv_ztt_mss_rm (out,a);
}
void cv_rm (CV_ARGS)
{
  CV_LOAD;
  CV_T(CV_OTHER,CV_SHAPE) b = CV_N(mconv_ew,CV_OTHER,CV_SHAPE) (a);
  __riscv_ztt_mss_rm (out,b);
}
void cv_reference (CV_ARGS)
{
  CV_LOAD;
  CV_T(CV_TYPE,CV_SHAPE) b = CV_N(mcopy_m2m,CV_TYPE,CV_SHAPE) (a);
  __riscv_ztt_mss_rm (out,b);
}
#ifdef __cplusplus
}
#endif
