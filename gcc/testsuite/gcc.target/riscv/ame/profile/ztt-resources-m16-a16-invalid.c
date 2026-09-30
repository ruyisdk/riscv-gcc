/* runtime-N resource profiles.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv64 } } */
/* { dg-skip-if "L0 diagnostics require expansion" { *-*-* } { "-flto" } } */
void
bad_selectors (unsigned long dtype)
{
  __builtin_riscv_ztt_mzero_2d_m (16); /* { dg-error "AME/Ztt M selector must be in" } */
  __builtin_riscv_ztt_mzero_2d_acc (16); /* { dg-error "AME/Ztt ACC selector must be in" } */
  __builtin_riscv_ztt_mgettyp (16); /* { dg-error "AME/Ztt M selector must be in" } */
  __builtin_riscv_ztt_agettyp (16); /* { dg-error "AME/Ztt ACC selector must be in" } */
  __builtin_riscv_ztt_msettyp (16, dtype); /* { dg-error "AME/Ztt M selector must be in" } */
  __builtin_riscv_ztt_asettyp (16, dtype); /* { dg-error "AME/Ztt ACC selector must be in" } */
  __builtin_riscv_ztt_madd_ew (0, 16, 0); /* { dg-error "AME/Ztt M selector must be in" } */
  __builtin_riscv_ztt_madd_ew (0, 0, 16); /* { dg-error "AME/Ztt M selector must be in" } */
  __builtin_riscv_ztt_mmov_m_a (0, 16); /* { dg-error "AME/Ztt ACC selector must be in" } */
  __builtin_riscv_ztt_mmov_a_m (16, 0); /* { dg-error "AME/Ztt ACC selector must be in" } */
  __builtin_riscv_ztt_mmulacc_2d (16, 0, 0); /* { dg-error "AME/Ztt ACC selector must be in" } */
}
