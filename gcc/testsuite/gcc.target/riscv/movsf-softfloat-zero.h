#ifdef __cplusplus
extern "C" {
#endif

void positive_zero (float *p) { *p = 0.0f; }
void volatile_zero (volatile float *p) { *p = 0.0f; }
void negative_zero (float *p) { *p = -0.0f; }
void nonzero (float *p) { *p = 1.25f; }
void dynamic_value (float *p, float value) { *p = value; }
void double_zero (double *p) { *p = 0.0; }

#ifdef __cplusplus
}
#endif
