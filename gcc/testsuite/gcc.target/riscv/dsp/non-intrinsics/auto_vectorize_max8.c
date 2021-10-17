
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O3 --save-temps" } */

#if (__riscv_xlen==64)
#define N 8
#else
#define N 4
#endif

signed char a[N];
signed char b[N];
signed char c[N];
unsigned char ua[N];
unsigned char ub[N];
unsigned char uc[N];

int func()
{
  int i;
  for (i=0;i<N;i++)
   a[i]= b[i]>c[i] ? b[i] : c[i];
}

/* { dg-final { scan-assembler "smax8\t" } }*/

int ufunc()
{
  int i;
  for (i=0;i<N;i++)
   ua[i]= ub[i]>uc[i] ? ub[i] : uc[i];
}

/* { dg-final { scan-assembler "umax8\t" } }*/

/* { dg-final { cleanup-saved-temps } } */

