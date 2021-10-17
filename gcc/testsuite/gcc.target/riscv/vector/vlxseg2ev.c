
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

float32x2xm1_t test_vlxseg2ev_float32x2xm1 (const float *address, int32xm1_t index, unsigned int gvl) {
    return vlxseg2ev_float32x2xm1 (address, index, gvl);
}


float32x2xm2_t test_vlxseg2ev_float32x2xm2 (const float *address, int32xm2_t index, unsigned int gvl) {
    return vlxseg2ev_float32x2xm2 (address, index, gvl);
}


float32x2xm4_t test_vlxseg2ev_float32x2xm4 (const float *address, int32xm4_t index, unsigned int gvl) {
    return vlxseg2ev_float32x2xm4 (address, index, gvl);
}


float64x2xm1_t test_vlxseg2ev_float64x2xm1 (const double *address, int64xm1_t index, unsigned int gvl) {
    return vlxseg2ev_float64x2xm1 (address, index, gvl);
}


float64x2xm2_t test_vlxseg2ev_float64x2xm2 (const double *address, int64xm2_t index, unsigned int gvl) {
    return vlxseg2ev_float64x2xm2 (address, index, gvl);
}


float64x2xm4_t test_vlxseg2ev_float64x2xm4 (const double *address, int64xm4_t index, unsigned int gvl) {
    return vlxseg2ev_float64x2xm4 (address, index, gvl);
}


int16x2xm1_t test_vlxseg2ev_int16x2xm1 (const short *address, int16xm1_t index, unsigned int gvl) {
    return vlxseg2ev_int16x2xm1 (address, index, gvl);
}


int16x2xm2_t test_vlxseg2ev_int16x2xm2 (const short *address, int16xm2_t index, unsigned int gvl) {
    return vlxseg2ev_int16x2xm2 (address, index, gvl);
}


int16x2xm4_t test_vlxseg2ev_int16x2xm4 (const short *address, int16xm4_t index, unsigned int gvl) {
    return vlxseg2ev_int16x2xm4 (address, index, gvl);
}


int32x2xm1_t test_vlxseg2ev_int32x2xm1 (const int *address, int32xm1_t index, unsigned int gvl) {
    return vlxseg2ev_int32x2xm1 (address, index, gvl);
}


int32x2xm2_t test_vlxseg2ev_int32x2xm2 (const int *address, int32xm2_t index, unsigned int gvl) {
    return vlxseg2ev_int32x2xm2 (address, index, gvl);
}


int32x2xm4_t test_vlxseg2ev_int32x2xm4 (const int *address, int32xm4_t index, unsigned int gvl) {
    return vlxseg2ev_int32x2xm4 (address, index, gvl);
}


int64x2xm1_t test_vlxseg2ev_int64x2xm1 (const long *address, int64xm1_t index, unsigned int gvl) {
    return vlxseg2ev_int64x2xm1 (address, index, gvl);
}


int64x2xm2_t test_vlxseg2ev_int64x2xm2 (const long *address, int64xm2_t index, unsigned int gvl) {
    return vlxseg2ev_int64x2xm2 (address, index, gvl);
}


int64x2xm4_t test_vlxseg2ev_int64x2xm4 (const long *address, int64xm4_t index, unsigned int gvl) {
    return vlxseg2ev_int64x2xm4 (address, index, gvl);
}


int8x2xm1_t test_vlxseg2ev_int8x2xm1 (const signed char *address, int8xm1_t index, unsigned int gvl) {
    return vlxseg2ev_int8x2xm1 (address, index, gvl);
}


int8x2xm2_t test_vlxseg2ev_int8x2xm2 (const signed char *address, int8xm2_t index, unsigned int gvl) {
    return vlxseg2ev_int8x2xm2 (address, index, gvl);
}


int8x2xm4_t test_vlxseg2ev_int8x2xm4 (const signed char *address, int8xm4_t index, unsigned int gvl) {
    return vlxseg2ev_int8x2xm4 (address, index, gvl);
}


uint16x2xm1_t test_vlxseg2ev_uint16x2xm1 (const unsigned short *address, uint16xm1_t index, unsigned int gvl) {
    return vlxseg2ev_uint16x2xm1 (address, index, gvl);
}


uint16x2xm2_t test_vlxseg2ev_uint16x2xm2 (const unsigned short *address, uint16xm2_t index, unsigned int gvl) {
    return vlxseg2ev_uint16x2xm2 (address, index, gvl);
}


uint16x2xm4_t test_vlxseg2ev_uint16x2xm4 (const unsigned short *address, uint16xm4_t index, unsigned int gvl) {
    return vlxseg2ev_uint16x2xm4 (address, index, gvl);
}


uint32x2xm1_t test_vlxseg2ev_uint32x2xm1 (const unsigned int *address, uint32xm1_t index, unsigned int gvl) {
    return vlxseg2ev_uint32x2xm1 (address, index, gvl);
}


uint32x2xm2_t test_vlxseg2ev_uint32x2xm2 (const unsigned int *address, uint32xm2_t index, unsigned int gvl) {
    return vlxseg2ev_uint32x2xm2 (address, index, gvl);
}


uint32x2xm4_t test_vlxseg2ev_uint32x2xm4 (const unsigned int *address, uint32xm4_t index, unsigned int gvl) {
    return vlxseg2ev_uint32x2xm4 (address, index, gvl);
}


uint64x2xm1_t test_vlxseg2ev_uint64x2xm1 (const unsigned long *address, uint64xm1_t index, unsigned int gvl) {
    return vlxseg2ev_uint64x2xm1 (address, index, gvl);
}


uint64x2xm2_t test_vlxseg2ev_uint64x2xm2 (const unsigned long *address, uint64xm2_t index, unsigned int gvl) {
    return vlxseg2ev_uint64x2xm2 (address, index, gvl);
}


uint64x2xm4_t test_vlxseg2ev_uint64x2xm4 (const unsigned long *address, uint64xm4_t index, unsigned int gvl) {
    return vlxseg2ev_uint64x2xm4 (address, index, gvl);
}


uint8x2xm1_t test_vlxseg2ev_uint8x2xm1 (const unsigned char *address, uint8xm1_t index, unsigned int gvl) {
    return vlxseg2ev_uint8x2xm1 (address, index, gvl);
}


uint8x2xm2_t test_vlxseg2ev_uint8x2xm2 (const unsigned char *address, uint8xm2_t index, unsigned int gvl) {
    return vlxseg2ev_uint8x2xm2 (address, index, gvl);
}


uint8x2xm4_t test_vlxseg2ev_uint8x2xm4 (const unsigned char *address, uint8xm4_t index, unsigned int gvl) {
    return vlxseg2ev_uint8x2xm4 (address, index, gvl);
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

