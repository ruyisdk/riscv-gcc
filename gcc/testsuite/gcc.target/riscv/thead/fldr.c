/* { dg-do assemble } */
/* { dg-skip-if "test float ldr/str insns" { *-*-* } { "*" } { "-march=*xtheadc* -mabi=lp*d" } } */
/* { dg-options "--save-temps -O2" } */

float funcf(float *a, int b)
{
    return a[b];
}
/* { dg-final { scan-assembler "th.flrw" } } */

double funcd(double *a, int b)
{
    return a[b];
}
/* { dg-final { scan-assembler "th.flrd" } } */

float funcsf(float *a, int b, float c)
{
    a[b] = c;
    return a[b];
}
/* { dg-final { scan-assembler "th.fsrw" } } */

double funcsd(double *a, int b, double c)
{
    a[b] = c;
    return a[b];
}
/* { dg-final { scan-assembler "th.fsrd" } } */

/* { dg-final { cleanup-saved-temps } } */

