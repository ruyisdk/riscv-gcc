
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

float32x2xm1_t test_vlxseg2ev_mask_float32x2xm1 (float32x2xm1_t merge, const float *address, int32xm1_t index, e32xm1_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_float32x2xm1 (merge, address, index, mask, gvl);
}


float32x2xm2_t test_vlxseg2ev_mask_float32x2xm2 (float32x2xm2_t merge, const float *address, int32xm2_t index, e32xm2_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_float32x2xm2 (merge, address, index, mask, gvl);
}


float32x2xm4_t test_vlxseg2ev_mask_float32x2xm4 (float32x2xm4_t merge, const float *address, int32xm4_t index, e32xm4_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_float32x2xm4 (merge, address, index, mask, gvl);
}


float64x2xm1_t test_vlxseg2ev_mask_float64x2xm1 (float64x2xm1_t merge, const double *address, int64xm1_t index, e64xm1_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_float64x2xm1 (merge, address, index, mask, gvl);
}


float64x2xm2_t test_vlxseg2ev_mask_float64x2xm2 (float64x2xm2_t merge, const double *address, int64xm2_t index, e64xm2_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_float64x2xm2 (merge, address, index, mask, gvl);
}


float64x2xm4_t test_vlxseg2ev_mask_float64x2xm4 (float64x2xm4_t merge, const double *address, int64xm4_t index, e64xm4_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_float64x2xm4 (merge, address, index, mask, gvl);
}


int16x2xm1_t test_vlxseg2ev_mask_int16x2xm1 (int16x2xm1_t merge, const short *address, int16xm1_t index, e16xm1_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_int16x2xm1 (merge, address, index, mask, gvl);
}


int16x2xm2_t test_vlxseg2ev_mask_int16x2xm2 (int16x2xm2_t merge, const short *address, int16xm2_t index, e16xm2_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_int16x2xm2 (merge, address, index, mask, gvl);
}


int16x2xm4_t test_vlxseg2ev_mask_int16x2xm4 (int16x2xm4_t merge, const short *address, int16xm4_t index, e16xm4_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_int16x2xm4 (merge, address, index, mask, gvl);
}


int32x2xm1_t test_vlxseg2ev_mask_int32x2xm1 (int32x2xm1_t merge, const int *address, int32xm1_t index, e32xm1_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_int32x2xm1 (merge, address, index, mask, gvl);
}


int32x2xm2_t test_vlxseg2ev_mask_int32x2xm2 (int32x2xm2_t merge, const int *address, int32xm2_t index, e32xm2_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_int32x2xm2 (merge, address, index, mask, gvl);
}


int32x2xm4_t test_vlxseg2ev_mask_int32x2xm4 (int32x2xm4_t merge, const int *address, int32xm4_t index, e32xm4_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_int32x2xm4 (merge, address, index, mask, gvl);
}


int64x2xm1_t test_vlxseg2ev_mask_int64x2xm1 (int64x2xm1_t merge, const long *address, int64xm1_t index, e64xm1_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_int64x2xm1 (merge, address, index, mask, gvl);
}


int64x2xm2_t test_vlxseg2ev_mask_int64x2xm2 (int64x2xm2_t merge, const long *address, int64xm2_t index, e64xm2_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_int64x2xm2 (merge, address, index, mask, gvl);
}


int64x2xm4_t test_vlxseg2ev_mask_int64x2xm4 (int64x2xm4_t merge, const long *address, int64xm4_t index, e64xm4_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_int64x2xm4 (merge, address, index, mask, gvl);
}


int8x2xm1_t test_vlxseg2ev_mask_int8x2xm1 (int8x2xm1_t merge, const signed char *address, int8xm1_t index, e8xm1_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_int8x2xm1 (merge, address, index, mask, gvl);
}


int8x2xm2_t test_vlxseg2ev_mask_int8x2xm2 (int8x2xm2_t merge, const signed char *address, int8xm2_t index, e8xm2_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_int8x2xm2 (merge, address, index, mask, gvl);
}


int8x2xm4_t test_vlxseg2ev_mask_int8x2xm4 (int8x2xm4_t merge, const signed char *address, int8xm4_t index, e8xm4_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_int8x2xm4 (merge, address, index, mask, gvl);
}


uint16x2xm1_t test_vlxseg2ev_mask_uint16x2xm1 (uint16x2xm1_t merge, const unsigned short *address, uint16xm1_t index, e16xm1_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_uint16x2xm1 (merge, address, index, mask, gvl);
}


uint16x2xm2_t test_vlxseg2ev_mask_uint16x2xm2 (uint16x2xm2_t merge, const unsigned short *address, uint16xm2_t index, e16xm2_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_uint16x2xm2 (merge, address, index, mask, gvl);
}


uint16x2xm4_t test_vlxseg2ev_mask_uint16x2xm4 (uint16x2xm4_t merge, const unsigned short *address, uint16xm4_t index, e16xm4_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_uint16x2xm4 (merge, address, index, mask, gvl);
}


uint32x2xm1_t test_vlxseg2ev_mask_uint32x2xm1 (uint32x2xm1_t merge, const unsigned int *address, uint32xm1_t index, e32xm1_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_uint32x2xm1 (merge, address, index, mask, gvl);
}


uint32x2xm2_t test_vlxseg2ev_mask_uint32x2xm2 (uint32x2xm2_t merge, const unsigned int *address, uint32xm2_t index, e32xm2_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_uint32x2xm2 (merge, address, index, mask, gvl);
}


uint32x2xm4_t test_vlxseg2ev_mask_uint32x2xm4 (uint32x2xm4_t merge, const unsigned int *address, uint32xm4_t index, e32xm4_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_uint32x2xm4 (merge, address, index, mask, gvl);
}


uint64x2xm1_t test_vlxseg2ev_mask_uint64x2xm1 (uint64x2xm1_t merge, const unsigned long *address, uint64xm1_t index, e64xm1_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_uint64x2xm1 (merge, address, index, mask, gvl);
}


uint64x2xm2_t test_vlxseg2ev_mask_uint64x2xm2 (uint64x2xm2_t merge, const unsigned long *address, uint64xm2_t index, e64xm2_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_uint64x2xm2 (merge, address, index, mask, gvl);
}


uint64x2xm4_t test_vlxseg2ev_mask_uint64x2xm4 (uint64x2xm4_t merge, const unsigned long *address, uint64xm4_t index, e64xm4_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_uint64x2xm4 (merge, address, index, mask, gvl);
}


uint8x2xm1_t test_vlxseg2ev_mask_uint8x2xm1 (uint8x2xm1_t merge, const unsigned char *address, uint8xm1_t index, e8xm1_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_uint8x2xm1 (merge, address, index, mask, gvl);
}


uint8x2xm2_t test_vlxseg2ev_mask_uint8x2xm2 (uint8x2xm2_t merge, const unsigned char *address, uint8xm2_t index, e8xm2_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_uint8x2xm2 (merge, address, index, mask, gvl);
}


uint8x2xm4_t test_vlxseg2ev_mask_uint8x2xm4 (uint8x2xm4_t merge, const unsigned char *address, uint8xm4_t index, e8xm4_t mask, unsigned int gvl) {
    return vlxseg2ev_mask_uint8x2xm4 (merge, address, index, mask, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m2.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m4.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m2.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m4.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m2.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m4.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m2.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m4.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m2.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m4.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e8,m1.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e8,m2.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e8,m4.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m2.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m4.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m2.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m4.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m2.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m4.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e8,m1.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e8,m2.*vlxseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e8,m4.*vlxseg2e\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

