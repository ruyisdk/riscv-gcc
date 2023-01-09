/* { dg-do assemble } */
/* { dg-skip-if "test ipush/ipop insns" { *-*-* } { "*" } { "-march=*xtheade*" } } */
/* { dg-options "--save-temps -O2" } */

__attribute__((interrupt)) void func(void)
{
}

/* { dg-final { scan-assembler-not "ipush" } }*/
/* { dg-final { scan-assembler-not "ipop" } }*

/* { dg-final { cleanup-saved-temps } } */
