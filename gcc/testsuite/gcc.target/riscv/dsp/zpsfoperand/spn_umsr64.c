
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv32*p*" } } */
/* { dg-options "-O2 --save-temps" } */

long long test_smar64(long long t, unsigned int a, unsigned int b) {
    return t - (long long)a * (long long)b;
}

/* { dg-final { scan-assembler "\tumsr64" } }*/

/* { dg-final { cleanup-saved-temps } } */
