/* Compile/assemble checks, not numerical execution evidence.  */
#include "ztt-wide-matmul-body.h"
#if TEST_UDS == 64
RUN(wide_input_q4, i64_rne, 4, i64_rnu, u32_rod, 4)
RUN(wide_output_q16, i128_rne, 1, i8_rnu, u16_rod, 16)
RUN(wide_output_q8, i64_rne, 2, i16_rnu, u32_rod, 8)
#else
RUN(wide_input_q8, i64_rne, 2, i64_rnu, u32_rod, 8)
RUN(wide_input_q4, u128_rod, 4, i128_rne, u64_rnu, 4)
RUN(wide_output_q32, i128_rne, 1, i8_rnu, u16_rod, 32)
RUN(wide_output_q16, u64_rod, 2, i16_rne, u32_rnu, 16)
RUN(wide_output_q8, i128_rnu, 2, i32_rdn, u64_rne, 8)
#endif
