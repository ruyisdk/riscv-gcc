
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

float32xm1_t test_velement_get_float32xm2 (float32xm2_t source, const int index) {
    return velement_get_float32xm2 (source, 0);
}


float32xm1_t test_velement_get_float32xm4 (float32xm4_t source, const int index) {
    return velement_get_float32xm4 (source, 0);
}


float32xm1_t test_velement_get_float32xm8 (float32xm8_t source, const int index) {
    return velement_get_float32xm8 (source, 0);
}


float64xm1_t test_velement_get_float64xm2 (float64xm2_t source, const int index) {
    return velement_get_float64xm2 (source, 0);
}


float64xm1_t test_velement_get_float64xm4 (float64xm4_t source, const int index) {
    return velement_get_float64xm4 (source, 0);
}


float64xm1_t test_velement_get_float64xm8 (float64xm8_t source, const int index) {
    return velement_get_float64xm8 (source, 0);
}


int16xm1_t test_velement_get_int16xm2 (int16xm2_t source, const int index) {
    return velement_get_int16xm2 (source, 0);
}


int16xm1_t test_velement_get_int16xm4 (int16xm4_t source, const int index) {
    return velement_get_int16xm4 (source, 0);
}


int16xm1_t test_velement_get_int16xm8 (int16xm8_t source, const int index) {
    return velement_get_int16xm8 (source, 0);
}


int32xm1_t test_velement_get_int32xm2 (int32xm2_t source, const int index) {
    return velement_get_int32xm2 (source, 0);
}


int32xm1_t test_velement_get_int32xm4 (int32xm4_t source, const int index) {
    return velement_get_int32xm4 (source, 0);
}


int32xm1_t test_velement_get_int32xm8 (int32xm8_t source, const int index) {
    return velement_get_int32xm8 (source, 0);
}


int64xm1_t test_velement_get_int64xm2 (int64xm2_t source, const int index) {
    return velement_get_int64xm2 (source, 0);
}


int64xm1_t test_velement_get_int64xm4 (int64xm4_t source, const int index) {
    return velement_get_int64xm4 (source, 0);
}


int64xm1_t test_velement_get_int64xm8 (int64xm8_t source, const int index) {
    return velement_get_int64xm8 (source, 0);
}


int8xm1_t test_velement_get_int8xm2 (int8xm2_t source, const int index) {
    return velement_get_int8xm2 (source, 0);
}


int8xm1_t test_velement_get_int8xm4 (int8xm4_t source, const int index) {
    return velement_get_int8xm4 (source, 0);
}


int8xm1_t test_velement_get_int8xm8 (int8xm8_t source, const int index) {
    return velement_get_int8xm8 (source, 0);
}


uint16xm1_t test_velement_get_uint16xm2 (uint16xm2_t source, const int index) {
    return velement_get_uint16xm2 (source, 0);
}


uint16xm1_t test_velement_get_uint16xm4 (uint16xm4_t source, const int index) {
    return velement_get_uint16xm4 (source, 0);
}


uint16xm1_t test_velement_get_uint16xm8 (uint16xm8_t source, const int index) {
    return velement_get_uint16xm8 (source, 0);
}


uint32xm1_t test_velement_get_uint32xm2 (uint32xm2_t source, const int index) {
    return velement_get_uint32xm2 (source, 0);
}


uint32xm1_t test_velement_get_uint32xm4 (uint32xm4_t source, const int index) {
    return velement_get_uint32xm4 (source, 0);
}


uint32xm1_t test_velement_get_uint32xm8 (uint32xm8_t source, const int index) {
    return velement_get_uint32xm8 (source, 0);
}


uint64xm1_t test_velement_get_uint64xm2 (uint64xm2_t source, const int index) {
    return velement_get_uint64xm2 (source, 0);
}


uint64xm1_t test_velement_get_uint64xm4 (uint64xm4_t source, const int index) {
    return velement_get_uint64xm4 (source, 0);
}


uint64xm1_t test_velement_get_uint64xm8 (uint64xm8_t source, const int index) {
    return velement_get_uint64xm8 (source, 0);
}


uint8xm1_t test_velement_get_uint8xm2 (uint8xm2_t source, const int index) {
    return velement_get_uint8xm2 (source, 0);
}


uint8xm1_t test_velement_get_uint8xm4 (uint8xm4_t source, const int index) {
    return velement_get_uint8xm4 (source, 0);
}


uint8xm1_t test_velement_get_uint8xm8 (uint8xm8_t source, const int index) {
    return velement_get_uint8xm8 (source, 0);
}


/* { dg-final { cleanup-saved-temps } } */

