/* { dg-do compile } */
/* { dg-options "-march=rv32gc_ztt0p51 -mabi=ilp32" { target rv32 } } */
/* { dg-options "-march=rv64gc_ztt0p51 -mabi=lp64" { target rv64 } } */
/* { dg-error "unsupported version 0.51" "" { target *-*-* } 0 } */

void
ztt_old_version_is_rejected (void)
{
}
