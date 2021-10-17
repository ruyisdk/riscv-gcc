
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O3 --save-temps" } */

int a[2];
int b[2]={1,2};
int c[2]={0,7};
int i;

int func()
{
  for (i=0;i<2;i++)
   a[i]= b[i]<c[i] ? b[i] : c[i];
}

/* { dg-final { scan-assembler "smin32\t" } }*/

/* { dg-final { cleanup-saved-temps } } */

