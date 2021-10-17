
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

float32xm1_t test_vseg_element_get_float32x2xm1 (float32x2xm1_t source, const int index) {
    return vseg_element_get_float32x2xm1 (source, 0);
}


float32xm1_t test_vseg_element_get_float32x3xm1 (float32x3xm1_t source, const int index) {
    return vseg_element_get_float32x3xm1 (source, 0);
}


float32xm1_t test_vseg_element_get_float32x4xm1 (float32x4xm1_t source, const int index) {
    return vseg_element_get_float32x4xm1 (source, 0);
}


float32xm1_t test_vseg_element_get_float32x5xm1 (float32x5xm1_t source, const int index) {
    return vseg_element_get_float32x5xm1 (source, 0);
}


float32xm1_t test_vseg_element_get_float32x6xm1 (float32x6xm1_t source, const int index) {
    return vseg_element_get_float32x6xm1 (source, 0);
}


float32xm1_t test_vseg_element_get_float32x7xm1 (float32x7xm1_t source, const int index) {
    return vseg_element_get_float32x7xm1 (source, 0);
}


float32xm1_t test_vseg_element_get_float32x8xm1 (float32x8xm1_t source, const int index) {
    return vseg_element_get_float32x8xm1 (source, 0);
}


float32xm2_t test_vseg_element_get_float32x2xm2 (float32x2xm2_t source, const int index) {
    return vseg_element_get_float32x2xm2 (source, 0);
}


float32xm2_t test_vseg_element_get_float32x3xm2 (float32x3xm2_t source, const int index) {
    return vseg_element_get_float32x3xm2 (source, 0);
}


float32xm2_t test_vseg_element_get_float32x4xm2 (float32x4xm2_t source, const int index) {
    return vseg_element_get_float32x4xm2 (source, 0);
}


float32xm4_t test_vseg_element_get_float32x2xm4 (float32x2xm4_t source, const int index) {
    return vseg_element_get_float32x2xm4 (source, 0);
}


float64xm1_t test_vseg_element_get_float64x2xm1 (float64x2xm1_t source, const int index) {
    return vseg_element_get_float64x2xm1 (source, 0);
}


float64xm1_t test_vseg_element_get_float64x3xm1 (float64x3xm1_t source, const int index) {
    return vseg_element_get_float64x3xm1 (source, 0);
}


float64xm1_t test_vseg_element_get_float64x4xm1 (float64x4xm1_t source, const int index) {
    return vseg_element_get_float64x4xm1 (source, 0);
}


float64xm1_t test_vseg_element_get_float64x5xm1 (float64x5xm1_t source, const int index) {
    return vseg_element_get_float64x5xm1 (source, 0);
}


float64xm1_t test_vseg_element_get_float64x6xm1 (float64x6xm1_t source, const int index) {
    return vseg_element_get_float64x6xm1 (source, 0);
}


float64xm1_t test_vseg_element_get_float64x7xm1 (float64x7xm1_t source, const int index) {
    return vseg_element_get_float64x7xm1 (source, 0);
}


float64xm1_t test_vseg_element_get_float64x8xm1 (float64x8xm1_t source, const int index) {
    return vseg_element_get_float64x8xm1 (source, 0);
}


float64xm2_t test_vseg_element_get_float64x2xm2 (float64x2xm2_t source, const int index) {
    return vseg_element_get_float64x2xm2 (source, 0);
}


float64xm2_t test_vseg_element_get_float64x3xm2 (float64x3xm2_t source, const int index) {
    return vseg_element_get_float64x3xm2 (source, 0);
}


float64xm2_t test_vseg_element_get_float64x4xm2 (float64x4xm2_t source, const int index) {
    return vseg_element_get_float64x4xm2 (source, 0);
}


float64xm4_t test_vseg_element_get_float64x2xm4 (float64x2xm4_t source, const int index) {
    return vseg_element_get_float64x2xm4 (source, 0);
}


int16xm1_t test_vseg_element_get_int16x2xm1 (int16x2xm1_t source, const int index) {
    return vseg_element_get_int16x2xm1 (source, 0);
}


int16xm1_t test_vseg_element_get_int16x3xm1 (int16x3xm1_t source, const int index) {
    return vseg_element_get_int16x3xm1 (source, 0);
}


int16xm1_t test_vseg_element_get_int16x4xm1 (int16x4xm1_t source, const int index) {
    return vseg_element_get_int16x4xm1 (source, 0);
}


int16xm1_t test_vseg_element_get_int16x5xm1 (int16x5xm1_t source, const int index) {
    return vseg_element_get_int16x5xm1 (source, 0);
}


int16xm1_t test_vseg_element_get_int16x6xm1 (int16x6xm1_t source, const int index) {
    return vseg_element_get_int16x6xm1 (source, 0);
}


int16xm1_t test_vseg_element_get_int16x7xm1 (int16x7xm1_t source, const int index) {
    return vseg_element_get_int16x7xm1 (source, 0);
}


int16xm1_t test_vseg_element_get_int16x8xm1 (int16x8xm1_t source, const int index) {
    return vseg_element_get_int16x8xm1 (source, 0);
}


int16xm2_t test_vseg_element_get_int16x2xm2 (int16x2xm2_t source, const int index) {
    return vseg_element_get_int16x2xm2 (source, 0);
}


int16xm2_t test_vseg_element_get_int16x3xm2 (int16x3xm2_t source, const int index) {
    return vseg_element_get_int16x3xm2 (source, 0);
}


int16xm2_t test_vseg_element_get_int16x4xm2 (int16x4xm2_t source, const int index) {
    return vseg_element_get_int16x4xm2 (source, 0);
}


int16xm4_t test_vseg_element_get_int16x2xm4 (int16x2xm4_t source, const int index) {
    return vseg_element_get_int16x2xm4 (source, 0);
}


int32xm1_t test_vseg_element_get_int32x2xm1 (int32x2xm1_t source, const int index) {
    return vseg_element_get_int32x2xm1 (source, 0);
}


int32xm1_t test_vseg_element_get_int32x3xm1 (int32x3xm1_t source, const int index) {
    return vseg_element_get_int32x3xm1 (source, 0);
}


int32xm1_t test_vseg_element_get_int32x4xm1 (int32x4xm1_t source, const int index) {
    return vseg_element_get_int32x4xm1 (source, 0);
}


int32xm1_t test_vseg_element_get_int32x5xm1 (int32x5xm1_t source, const int index) {
    return vseg_element_get_int32x5xm1 (source, 0);
}


int32xm1_t test_vseg_element_get_int32x6xm1 (int32x6xm1_t source, const int index) {
    return vseg_element_get_int32x6xm1 (source, 0);
}


int32xm1_t test_vseg_element_get_int32x7xm1 (int32x7xm1_t source, const int index) {
    return vseg_element_get_int32x7xm1 (source, 0);
}


int32xm1_t test_vseg_element_get_int32x8xm1 (int32x8xm1_t source, const int index) {
    return vseg_element_get_int32x8xm1 (source, 0);
}


int32xm2_t test_vseg_element_get_int32x2xm2 (int32x2xm2_t source, const int index) {
    return vseg_element_get_int32x2xm2 (source, 0);
}


int32xm2_t test_vseg_element_get_int32x3xm2 (int32x3xm2_t source, const int index) {
    return vseg_element_get_int32x3xm2 (source, 0);
}


int32xm2_t test_vseg_element_get_int32x4xm2 (int32x4xm2_t source, const int index) {
    return vseg_element_get_int32x4xm2 (source, 0);
}


int32xm4_t test_vseg_element_get_int32x2xm4 (int32x2xm4_t source, const int index) {
    return vseg_element_get_int32x2xm4 (source, 0);
}


int64xm1_t test_vseg_element_get_int64x2xm1 (int64x2xm1_t source, const int index) {
    return vseg_element_get_int64x2xm1 (source, 0);
}


int64xm1_t test_vseg_element_get_int64x3xm1 (int64x3xm1_t source, const int index) {
    return vseg_element_get_int64x3xm1 (source, 0);
}


int64xm1_t test_vseg_element_get_int64x4xm1 (int64x4xm1_t source, const int index) {
    return vseg_element_get_int64x4xm1 (source, 0);
}


int64xm1_t test_vseg_element_get_int64x5xm1 (int64x5xm1_t source, const int index) {
    return vseg_element_get_int64x5xm1 (source, 0);
}


int64xm1_t test_vseg_element_get_int64x6xm1 (int64x6xm1_t source, const int index) {
    return vseg_element_get_int64x6xm1 (source, 0);
}


int64xm1_t test_vseg_element_get_int64x7xm1 (int64x7xm1_t source, const int index) {
    return vseg_element_get_int64x7xm1 (source, 0);
}


int64xm1_t test_vseg_element_get_int64x8xm1 (int64x8xm1_t source, const int index) {
    return vseg_element_get_int64x8xm1 (source, 0);
}


int64xm2_t test_vseg_element_get_int64x2xm2 (int64x2xm2_t source, const int index) {
    return vseg_element_get_int64x2xm2 (source, 0);
}


int64xm2_t test_vseg_element_get_int64x3xm2 (int64x3xm2_t source, const int index) {
    return vseg_element_get_int64x3xm2 (source, 0);
}


int64xm2_t test_vseg_element_get_int64x4xm2 (int64x4xm2_t source, const int index) {
    return vseg_element_get_int64x4xm2 (source, 0);
}


int64xm4_t test_vseg_element_get_int64x2xm4 (int64x2xm4_t source, const int index) {
    return vseg_element_get_int64x2xm4 (source, 0);
}


int8xm1_t test_vseg_element_get_int8x2xm1 (int8x2xm1_t source, const int index) {
    return vseg_element_get_int8x2xm1 (source, 0);
}


int8xm1_t test_vseg_element_get_int8x3xm1 (int8x3xm1_t source, const int index) {
    return vseg_element_get_int8x3xm1 (source, 0);
}


int8xm1_t test_vseg_element_get_int8x4xm1 (int8x4xm1_t source, const int index) {
    return vseg_element_get_int8x4xm1 (source, 0);
}


int8xm1_t test_vseg_element_get_int8x5xm1 (int8x5xm1_t source, const int index) {
    return vseg_element_get_int8x5xm1 (source, 0);
}


int8xm1_t test_vseg_element_get_int8x6xm1 (int8x6xm1_t source, const int index) {
    return vseg_element_get_int8x6xm1 (source, 0);
}


int8xm1_t test_vseg_element_get_int8x7xm1 (int8x7xm1_t source, const int index) {
    return vseg_element_get_int8x7xm1 (source, 0);
}


int8xm1_t test_vseg_element_get_int8x8xm1 (int8x8xm1_t source, const int index) {
    return vseg_element_get_int8x8xm1 (source, 0);
}


int8xm2_t test_vseg_element_get_int8x2xm2 (int8x2xm2_t source, const int index) {
    return vseg_element_get_int8x2xm2 (source, 0);
}


int8xm2_t test_vseg_element_get_int8x3xm2 (int8x3xm2_t source, const int index) {
    return vseg_element_get_int8x3xm2 (source, 0);
}


int8xm2_t test_vseg_element_get_int8x4xm2 (int8x4xm2_t source, const int index) {
    return vseg_element_get_int8x4xm2 (source, 0);
}


int8xm4_t test_vseg_element_get_int8x2xm4 (int8x2xm4_t source, const int index) {
    return vseg_element_get_int8x2xm4 (source, 0);
}


uint16xm1_t test_vseg_element_get_uint16x2xm1 (uint16x2xm1_t source, const int index) {
    return vseg_element_get_uint16x2xm1 (source, 0);
}


uint16xm1_t test_vseg_element_get_uint16x3xm1 (uint16x3xm1_t source, const int index) {
    return vseg_element_get_uint16x3xm1 (source, 0);
}


uint16xm1_t test_vseg_element_get_uint16x4xm1 (uint16x4xm1_t source, const int index) {
    return vseg_element_get_uint16x4xm1 (source, 0);
}


uint16xm1_t test_vseg_element_get_uint16x5xm1 (uint16x5xm1_t source, const int index) {
    return vseg_element_get_uint16x5xm1 (source, 0);
}


uint16xm1_t test_vseg_element_get_uint16x6xm1 (uint16x6xm1_t source, const int index) {
    return vseg_element_get_uint16x6xm1 (source, 0);
}


uint16xm1_t test_vseg_element_get_uint16x7xm1 (uint16x7xm1_t source, const int index) {
    return vseg_element_get_uint16x7xm1 (source, 0);
}


uint16xm1_t test_vseg_element_get_uint16x8xm1 (uint16x8xm1_t source, const int index) {
    return vseg_element_get_uint16x8xm1 (source, 0);
}


uint16xm2_t test_vseg_element_get_uint16x2xm2 (uint16x2xm2_t source, const int index) {
    return vseg_element_get_uint16x2xm2 (source, 0);
}


uint16xm2_t test_vseg_element_get_uint16x3xm2 (uint16x3xm2_t source, const int index) {
    return vseg_element_get_uint16x3xm2 (source, 0);
}


uint16xm2_t test_vseg_element_get_uint16x4xm2 (uint16x4xm2_t source, const int index) {
    return vseg_element_get_uint16x4xm2 (source, 0);
}


uint16xm4_t test_vseg_element_get_uint16x2xm4 (uint16x2xm4_t source, const int index) {
    return vseg_element_get_uint16x2xm4 (source, 0);
}


uint32xm1_t test_vseg_element_get_uint32x2xm1 (uint32x2xm1_t source, const int index) {
    return vseg_element_get_uint32x2xm1 (source, 0);
}


uint32xm1_t test_vseg_element_get_uint32x3xm1 (uint32x3xm1_t source, const int index) {
    return vseg_element_get_uint32x3xm1 (source, 0);
}


uint32xm1_t test_vseg_element_get_uint32x4xm1 (uint32x4xm1_t source, const int index) {
    return vseg_element_get_uint32x4xm1 (source, 0);
}


uint32xm1_t test_vseg_element_get_uint32x5xm1 (uint32x5xm1_t source, const int index) {
    return vseg_element_get_uint32x5xm1 (source, 0);
}


uint32xm1_t test_vseg_element_get_uint32x6xm1 (uint32x6xm1_t source, const int index) {
    return vseg_element_get_uint32x6xm1 (source, 0);
}


uint32xm1_t test_vseg_element_get_uint32x7xm1 (uint32x7xm1_t source, const int index) {
    return vseg_element_get_uint32x7xm1 (source, 0);
}


uint32xm1_t test_vseg_element_get_uint32x8xm1 (uint32x8xm1_t source, const int index) {
    return vseg_element_get_uint32x8xm1 (source, 0);
}


uint32xm2_t test_vseg_element_get_uint32x2xm2 (uint32x2xm2_t source, const int index) {
    return vseg_element_get_uint32x2xm2 (source, 0);
}


uint32xm2_t test_vseg_element_get_uint32x3xm2 (uint32x3xm2_t source, const int index) {
    return vseg_element_get_uint32x3xm2 (source, 0);
}


uint32xm2_t test_vseg_element_get_uint32x4xm2 (uint32x4xm2_t source, const int index) {
    return vseg_element_get_uint32x4xm2 (source, 0);
}


uint32xm4_t test_vseg_element_get_uint32x2xm4 (uint32x2xm4_t source, const int index) {
    return vseg_element_get_uint32x2xm4 (source, 0);
}


uint64xm1_t test_vseg_element_get_uint64x2xm1 (uint64x2xm1_t source, const int index) {
    return vseg_element_get_uint64x2xm1 (source, 0);
}


uint64xm1_t test_vseg_element_get_uint64x3xm1 (uint64x3xm1_t source, const int index) {
    return vseg_element_get_uint64x3xm1 (source, 0);
}


uint64xm1_t test_vseg_element_get_uint64x4xm1 (uint64x4xm1_t source, const int index) {
    return vseg_element_get_uint64x4xm1 (source, 0);
}


uint64xm1_t test_vseg_element_get_uint64x5xm1 (uint64x5xm1_t source, const int index) {
    return vseg_element_get_uint64x5xm1 (source, 0);
}


uint64xm1_t test_vseg_element_get_uint64x6xm1 (uint64x6xm1_t source, const int index) {
    return vseg_element_get_uint64x6xm1 (source, 0);
}


uint64xm1_t test_vseg_element_get_uint64x7xm1 (uint64x7xm1_t source, const int index) {
    return vseg_element_get_uint64x7xm1 (source, 0);
}


uint64xm1_t test_vseg_element_get_uint64x8xm1 (uint64x8xm1_t source, const int index) {
    return vseg_element_get_uint64x8xm1 (source, 0);
}


uint64xm2_t test_vseg_element_get_uint64x2xm2 (uint64x2xm2_t source, const int index) {
    return vseg_element_get_uint64x2xm2 (source, 0);
}


uint64xm2_t test_vseg_element_get_uint64x3xm2 (uint64x3xm2_t source, const int index) {
    return vseg_element_get_uint64x3xm2 (source, 0);
}


uint64xm2_t test_vseg_element_get_uint64x4xm2 (uint64x4xm2_t source, const int index) {
    return vseg_element_get_uint64x4xm2 (source, 0);
}


uint64xm4_t test_vseg_element_get_uint64x2xm4 (uint64x2xm4_t source, const int index) {
    return vseg_element_get_uint64x2xm4 (source, 0);
}


uint8xm1_t test_vseg_element_get_uint8x2xm1 (uint8x2xm1_t source, const int index) {
    return vseg_element_get_uint8x2xm1 (source, 0);
}


uint8xm1_t test_vseg_element_get_uint8x3xm1 (uint8x3xm1_t source, const int index) {
    return vseg_element_get_uint8x3xm1 (source, 0);
}


uint8xm1_t test_vseg_element_get_uint8x4xm1 (uint8x4xm1_t source, const int index) {
    return vseg_element_get_uint8x4xm1 (source, 0);
}


uint8xm1_t test_vseg_element_get_uint8x5xm1 (uint8x5xm1_t source, const int index) {
    return vseg_element_get_uint8x5xm1 (source, 0);
}


uint8xm1_t test_vseg_element_get_uint8x6xm1 (uint8x6xm1_t source, const int index) {
    return vseg_element_get_uint8x6xm1 (source, 0);
}


uint8xm1_t test_vseg_element_get_uint8x7xm1 (uint8x7xm1_t source, const int index) {
    return vseg_element_get_uint8x7xm1 (source, 0);
}


uint8xm1_t test_vseg_element_get_uint8x8xm1 (uint8x8xm1_t source, const int index) {
    return vseg_element_get_uint8x8xm1 (source, 0);
}


uint8xm2_t test_vseg_element_get_uint8x2xm2 (uint8x2xm2_t source, const int index) {
    return vseg_element_get_uint8x2xm2 (source, 0);
}


uint8xm2_t test_vseg_element_get_uint8x3xm2 (uint8x3xm2_t source, const int index) {
    return vseg_element_get_uint8x3xm2 (source, 0);
}


uint8xm2_t test_vseg_element_get_uint8x4xm2 (uint8x4xm2_t source, const int index) {
    return vseg_element_get_uint8x4xm2 (source, 0);
}


uint8xm4_t test_vseg_element_get_uint8x2xm4 (uint8x2xm4_t source, const int index) {
    return vseg_element_get_uint8x2xm4 (source, 0);
}


/* { dg-final { cleanup-saved-temps } } */

