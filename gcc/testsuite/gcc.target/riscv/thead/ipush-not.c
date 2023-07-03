/* { dg-do assemble } */
/* { dg-skip-if "test ipush/ipop insns" { *-*-* } { "*" } { "-march=*xtheade*" } } */
/* { dg-options "--save-temps -O2" } */

__attribute__((interrupt)) void func(void)
{
}

/* { dg-final { scan-assembler-not "th.ipush\n" } }*/
/* { dg-final { scan-assembler-not "th.ipop\n" } }*

/* { dg-final { cleanup-saved-temps } } */
