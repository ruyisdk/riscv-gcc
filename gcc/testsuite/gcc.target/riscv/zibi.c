/* { dg-do compile { target { ! riscv_abi_e } } } */
/* { dg-require-effective-target rv64 } */
/* { dg-options "-march=rv64gc_zibi -mabi=lp64d -O2" } */

extern void foo (void);

void
beqi_5 (long x)
{
  if (x == 5)
    foo ();
}

void
bnei_5 (long x)
{
  if (x != 5)
    foo ();
}

void
beq_0 (long x)
{
  if (x == 0)
    foo ();
}

void
beqi_31 (long x)
{
  if (x == 31)
    foo ();
}

void
not_zibi_32 (long x)
{
  if (x == 32)
    foo ();
}

void
beqi_m1 (long x)
{
  if (x == -1)
    foo ();
}

void
bnei_m1 (long x)
{
  if (x != -1)
    foo ();
}

/* { dg-final { scan-assembler-times "\tbeqi\t" 3 } } */
/* { dg-final { scan-assembler-times "\tbnei\t" 2 } } */
/* { dg-final { scan-assembler-times "\tbeq\t.*zero," 1 } } */
/* { dg-final { scan-assembler-times "\tli\t.*,32" 1 } } */
