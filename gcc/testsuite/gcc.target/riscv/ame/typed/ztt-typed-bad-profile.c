/* { dg-do compile } */
/* { dg-options "-march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=invalid" { target rv32 } } */
/* { dg-options "-march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=invalid" { target rv64 } } */
/* { dg-error "unknown AME/Ztt target profile .invalid." "" { target *-*-* } 0 } */
