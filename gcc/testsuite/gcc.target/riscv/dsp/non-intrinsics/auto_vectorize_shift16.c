/* TODO: This case can't be auto vectorized now, and open
         this file when the common vectorize pass can deal
         with it. */
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } {} } */
/* { dg-options "-O3 --save-temps" } */

#if (__riscv_xlen==64)
#define N 4
#else
#define N 2
#endif

signed short a[N];
signed short b[N];
int c;
unsigned short ua[N];
unsigned short ub[N];

int auto_sra()
{
  int i;
  for (i=0;i<N;i++)
   a[i]= b[i]>>c;
}

/* { dg-final { scan-assembler "sra16\t" } }*/

int auto_srl()
{
  int i;
  for (i=0;i<N;i++)
   ua[i]= ub[i]>>c;
}

/* { dg-final { scan-assembler "srl16\t" } }*/

int auto_sll()
{
  int i;
  for (i=0;i<N;i++)
   a[i]= b[i]<<c;
}

/* { dg-final { scan-assembler "sll16\t" } }*/

int auto_srai()
{
  int i;
  for (i=0;i<N;i++)
   a[i]= b[i]>>10;
}

/* { dg-final { scan-assembler "srai16\t" } }*/

int auto_srli()
{
  int i;
  for (i=0;i<N;i++)
   ua[i]= ub[i]>>10;
}

/* { dg-final { scan-assembler "srli16\t" } }*/

int auto_slli()
{
  int i;
  for (i=0;i<N;i++)
   a[i]= b[i]<<10;
}

/* { dg-final { scan-assembler "slli16\t" } }*/

/* { dg-final { cleanup-saved-temps } } */
