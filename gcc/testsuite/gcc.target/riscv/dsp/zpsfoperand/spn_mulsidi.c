
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv32*p*" } } */
/* { dg-options "-O2 --save-temps" } */

long long test_mulsr64 (int a, int b) {
return (long long) a * b;
}

/* { dg-final { scan-assembler "mulsr64\t" } }*/
/* { dg-final { cleanup-saved-temps } } */
