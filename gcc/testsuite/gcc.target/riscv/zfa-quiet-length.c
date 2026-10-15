/* { dg-do compile } */
/* { dg-options "-O2 -dp" } */
/* { dg-additional-options "-march=rv32imafd_zicsr_zfa_zfh -mabi=ilp32d" { target rv32 } } */
/* { dg-additional-options "-march=rv64imafd_zicsr_zfa_zfh -mabi=lp64d" { target rv64 } } */
#define TEST(T, NAME) \
int less_##NAME (T a, T b) { return __builtin_isless (a, b); } \
int le_##NAME (T a, T b) { return __builtin_islessequal (a, b); }
TEST (_Float16, half)
TEST (float, single)
TEST (double, twice)
/* { dg-final { scan-assembler-times {l=4[^\n]*f(?:lt|le)_quiet[^\n]*_zfa} 6 } } */
/* { dg-final { scan-assembler-not {l=16[^\n]*_zfa} } } */
