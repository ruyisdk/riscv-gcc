
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

float32xm2_t test_velement_set_float32xm2 (float32xm2_t dest, const int index, float32xm1_t element) {
    return velement_set_float32xm2 (dest, 0, element);
}


float32xm4_t test_velement_set_float32xm4 (float32xm4_t dest, const int index, float32xm1_t element) {
    return velement_set_float32xm4 (dest, 0, element);
}


float32xm8_t test_velement_set_float32xm8 (float32xm8_t dest, const int index, float32xm1_t element) {
    return velement_set_float32xm8 (dest, 0, element);
}


float64xm2_t test_velement_set_float64xm2 (float64xm2_t dest, const int index, float64xm1_t element) {
    return velement_set_float64xm2 (dest, 0, element);
}


float64xm4_t test_velement_set_float64xm4 (float64xm4_t dest, const int index, float64xm1_t element) {
    return velement_set_float64xm4 (dest, 0, element);
}


float64xm8_t test_velement_set_float64xm8 (float64xm8_t dest, const int index, float64xm1_t element) {
    return velement_set_float64xm8 (dest, 0, element);
}


int16xm2_t test_velement_set_int16xm2 (int16xm2_t dest, const int index, int16xm1_t element) {
    return velement_set_int16xm2 (dest, 0, element);
}


int16xm4_t test_velement_set_int16xm4 (int16xm4_t dest, const int index, int16xm1_t element) {
    return velement_set_int16xm4 (dest, 0, element);
}


int16xm8_t test_velement_set_int16xm8 (int16xm8_t dest, const int index, int16xm1_t element) {
    return velement_set_int16xm8 (dest, 0, element);
}


int32xm2_t test_velement_set_int32xm2 (int32xm2_t dest, const int index, int32xm1_t element) {
    return velement_set_int32xm2 (dest, 0, element);
}


int32xm4_t test_velement_set_int32xm4 (int32xm4_t dest, const int index, int32xm1_t element) {
    return velement_set_int32xm4 (dest, 0, element);
}


int32xm8_t test_velement_set_int32xm8 (int32xm8_t dest, const int index, int32xm1_t element) {
    return velement_set_int32xm8 (dest, 0, element);
}


int64xm2_t test_velement_set_int64xm2 (int64xm2_t dest, const int index, int64xm1_t element) {
    return velement_set_int64xm2 (dest, 0, element);
}


int64xm4_t test_velement_set_int64xm4 (int64xm4_t dest, const int index, int64xm1_t element) {
    return velement_set_int64xm4 (dest, 0, element);
}


int64xm8_t test_velement_set_int64xm8 (int64xm8_t dest, const int index, int64xm1_t element) {
    return velement_set_int64xm8 (dest, 0, element);
}


int8xm2_t test_velement_set_int8xm2 (int8xm2_t dest, const int index, int8xm1_t element) {
    return velement_set_int8xm2 (dest, 0, element);
}


int8xm4_t test_velement_set_int8xm4 (int8xm4_t dest, const int index, int8xm1_t element) {
    return velement_set_int8xm4 (dest, 0, element);
}


int8xm8_t test_velement_set_int8xm8 (int8xm8_t dest, const int index, int8xm1_t element) {
    return velement_set_int8xm8 (dest, 0, element);
}


uint16xm2_t test_velement_set_uint16xm2 (uint16xm2_t dest, const int index, uint16xm1_t element) {
    return velement_set_uint16xm2 (dest, 0, element);
}


uint16xm4_t test_velement_set_uint16xm4 (uint16xm4_t dest, const int index, uint16xm1_t element) {
    return velement_set_uint16xm4 (dest, 0, element);
}


uint16xm8_t test_velement_set_uint16xm8 (uint16xm8_t dest, const int index, uint16xm1_t element) {
    return velement_set_uint16xm8 (dest, 0, element);
}


uint32xm2_t test_velement_set_uint32xm2 (uint32xm2_t dest, const int index, uint32xm1_t element) {
    return velement_set_uint32xm2 (dest, 0, element);
}


uint32xm4_t test_velement_set_uint32xm4 (uint32xm4_t dest, const int index, uint32xm1_t element) {
    return velement_set_uint32xm4 (dest, 0, element);
}


uint32xm8_t test_velement_set_uint32xm8 (uint32xm8_t dest, const int index, uint32xm1_t element) {
    return velement_set_uint32xm8 (dest, 0, element);
}


uint64xm2_t test_velement_set_uint64xm2 (uint64xm2_t dest, const int index, uint64xm1_t element) {
    return velement_set_uint64xm2 (dest, 0, element);
}


uint64xm4_t test_velement_set_uint64xm4 (uint64xm4_t dest, const int index, uint64xm1_t element) {
    return velement_set_uint64xm4 (dest, 0, element);
}


uint64xm8_t test_velement_set_uint64xm8 (uint64xm8_t dest, const int index, uint64xm1_t element) {
    return velement_set_uint64xm8 (dest, 0, element);
}


uint8xm2_t test_velement_set_uint8xm2 (uint8xm2_t dest, const int index, uint8xm1_t element) {
    return velement_set_uint8xm2 (dest, 0, element);
}


uint8xm4_t test_velement_set_uint8xm4 (uint8xm4_t dest, const int index, uint8xm1_t element) {
    return velement_set_uint8xm4 (dest, 0, element);
}


uint8xm8_t test_velement_set_uint8xm8 (uint8xm8_t dest, const int index, uint8xm1_t element) {
    return velement_set_uint8xm8 (dest, 0, element);
}


/* { dg-final { cleanup-saved-temps } } */

