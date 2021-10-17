
#ifndef GCC_RISCV_THEAD_H
#define GCC_RISCV_THEAD_H


#define TARGET_XTHEAD_LDR ((TARGET_XTHEAD_C || TARGET_XTHEAD_E) && riscv_insn_ldr)
#define TARGET_XTHEAD_LDI ((TARGET_XTHEAD_C || TARGET_XTHEAD_E) && riscv_insn_ldi)

#define TARGET_XTHEAD_EXT ((TARGET_XTHEAD_C || TARGET_XTHEAD_E) && riscv_insn_ext)
#define TARGET_XTHEAD_MULA ((TARGET_XTHEAD_C || TARGET_XTHEAD_E) && riscv_insn_mula)
#define TARGET_XTHEAD_ADDSL ((TARGET_XTHEAD_C || TARGET_XTHEAD_E) && riscv_insn_addsl)
#define TARGET_XTHEAD_ADDSLUW (TARGET_XTHEAD_C && riscv_insn_addsluw)
#define TARGET_XTHEAD_REV ((TARGET_XTHEAD_C || TARGET_XTHEAD_E) && riscv_insn_rev)
#define TARGET_XTHEAD_REVW (TARGET_XTHEAD_C && riscv_insn_revw)
#define TARGET_XTHEAD_SRRI ((TARGET_XTHEAD_C || TARGET_XTHEAD_E) && riscv_insn_srri)
#define TARGET_XTHEAD_SRRIW (TARGET_XTHEAD_C && riscv_insn_srriw)
#define TARGET_XTHEAD_CONDMV ((TARGET_XTHEAD_C || TARGET_XTHEAD_E) && riscv_insn_condmv)
#define TARGET_XTHEAD_LDD (TARGET_XTHEAD_C && riscv_insn_ldd)
#define TARGET_XTHEAD_IPUSH (TARGET_XTHEAD_E && riscv_insn_ipush)
#define TARGET_XTHEAD_FMVHW32 (TARGET_XTHEAD_E && riscv_insn_fmvhw32)

#define TARGET_XTHEAD_XOR_COMBINE ((TARGET_XTHEAD_C || TARGET_XTHEAD_E) && riscv_xor_combine)
#define TARGET_XTHEAD_COMBINE_COPY (TARGET_XTHEAD ? riscv_combine_copy : true)
#define TARGET_XTHEAD_DUP_LOOP_HEADER (TARGET_XTHEAD ? riscv_dup_loop_header : false)
#define TARGET_XTHEAD_UNHOT_INLINE (TARGET_XTHEAD ? riscv_ipa_unhot_inline : false)
#define TARGET_XTHEAD_INVARIANT_AS_CONSTANT (TARGET_XTHEAD ? riscv_invariant_as_constant : false)

#define TARGET_XTHEAD_SIGNEDNESS_COMPARISON_IV (TARGET_XTHEAD ? riscv_signedness_comparison_iv : false)
#define TARGET_XTHEAD_IV_ADJUST_ADDR_COST (TARGET_XTHEAD ? riscv_iv_adjust_addr_cost : true)
#define TARGET_XTHEAD_EXPAND_SPLIT_IMM (TARGET_XTHEAD ? riscv_expand_split_imm : true)
#define TARGET_XTHEAD_THREAD1 (TARGET_XTHEAD ? riscv_thread_jumps1 : true)

#define TARGET_XTHEAD_FLDR (TARGET_HARD_FLOAT && TARGET_XTHEAD_C && riscv_insn_fldr)
#define TARGET_XTHEAD_FP16 (TARGET_HARD_FLOAT && TARGET_XTHEAD_C && riscv_insn_fp16)
#define TARGET_XTHEAD_FCLASS (TARGET_HARD_FLOAT && TARGET_XTHEAD && riscv_insn_fclass)

#define HAVE_POST_MODIFY_DISP TARGET_XTHEAD_LDI
#define HAVE_PRE_MODIFY_DISP  TARGET_XTHEAD_LDI

#define RISCV_TUNE_STRING_DEFAULT	\
  (TARGET_XTHEAD_C ? "c910" :		\
   TARGET_XTHEAD_E ? "e906" :		\
   TARGET_XTHEAD_SE ? "e902" :		\
   "rocket")

/* True if VALUE is an unsigned 16-bit number.  */
#define SMALL_OPERAND_UNSIGNED16(VALUE) \
  (((VALUE) & ~(unsigned HOST_WIDE_INT) 0xffff) == 0)

#define TARGET_XTHEAD_INTERRUPT_HANDLER_P() \
  (cfun->machine->interrupt_handler_p \
   && TARGET_XTHEAD_IPUSH \
   && (cfun->machine->interrupt_mode == USER_MODE \
       || cfun->machine->interrupt_mode == MACHINE_MODE))

#include "riscv-v.h"
#define TARGET_XTHEAD_DSP TARGET_DSP
#define TARGET_XTHEAD_ZPSFOPERAND TARGET_ZPSFOPERAND

#ifdef IN_TARGET_CODE
extern const struct riscv_tune_param thead_c906_tune_info;
extern const struct riscv_tune_param thead_c910_tune_info;
extern const struct riscv_tune_param thead_e9_tune_info;

void
riscv_xthead_option_override (const struct riscv_tune_param *tune_param,
			      struct gcc_options *opts,
			      struct gcc_options *opts_set);

bool
riscv_xthead_rtx_costs (rtx x, machine_mode mode, int outer_code,
			int opno ATTRIBUTE_UNUSED, int *total, bool speed);
bool
riscv_classify_address_index (struct riscv_address_info *info, rtx x,
			      machine_mode mode, bool strict_p);
bool
riscv_classify_address_modify (struct riscv_address_info *info, rtx x,
			       machine_mode mode, bool strict_p);

const char *
riscv_output_move_index (rtx x, machine_mode mode, bool ldr);
const char *
riscv_output_move_modify (rtx x, machine_mode mode, bool ldi);
const char *
riscv_output_move_index_float (rtx x, machine_mode mode, bool ldr);

bool
riscv_legitimize_address_index_p (rtx x, machine_mode mode, bool uindex);
bool
riscv_legitimize_address_modify_p (rtx x, machine_mode mode, bool post);
bool
riscv_legitimize_address_pair_p (rtx, machine_mode, bool);

int
riscv_expand_movcc (rtx *operands);

bool
riscv_save_reg_ipush_p (int regno);
rtx
riscv_adjust_ipush_cfi_prologue ();

// vector

rtx
riscv_get_varg_info (struct riscv_arg_info *info,
		     machine_mode mode, const_tree type,
		     bool return_p);
void
riscv_save_vreg (rtx reg, rtx mem);
void
riscv_restore_vreg (rtx reg, rtx mem);

rtx
riscv_legitimize_vector_address (rtx x, machine_mode mode);
bool
riscv_classify_address_vector (struct riscv_address_info *info, rtx x,
			       machine_mode mode, bool strict_p);
bool
riscv_legitimize_address_vector_p (rtx x, machine_mode mode);
void *
riscv_classify_vext_mode (machine_mode mode, int *sew, int *lmul,
			  bool enabled);
bool
riscv_vector_mode_vext_supported_p (machine_mode mode);
bool
riscv_vector_mode_supported_p (machine_mode mode);
rtx
riscv_emit_vsetvli (machine_mode mode, rtx gvl, rtx avl);
rtx
riscv_emit_vsetvli_base (machine_mode mode, rtx gvl, rtx avl, rtx nf);
machine_mode
riscv_vector_register_mode (machine_mode mode);
const char *
riscv_output_vector_insn (machine_mode mode, const char *insn);
const char *
riscv_output_vector_sew (int);
const char *
riscv_output_vector_lmul (int);

/* For P-extension.  */
bool riscv_vector_mode_pext_supported_p (machine_mode);
bool riscv_vector_mode_vext_except_pext_supported_p (machine_mode);

#endif

#define ARCH_SPEC \
  "%{march=rv64ima_xtheadc:xthead}" \
  "%{march=rv64imac_xtheadc:xthead}" \
  "%{march=rv64imaf_xtheadc:xthead}" \
  "%{march=rv64imafc_xtheadc:xthead}" \
  "%{march=rv64imafd_xtheadc:xthead}" \
  "%{march=rv64imafdc_xtheadc:xthead}" \
  "%{march=rv64imap_xtheadc:xthead}" \
  "%{march=rv64imacp_xtheadc:xthead}" \
  "%{march=rv64imafp_xtheadc:xthead}" \
  "%{march=rv64imafcp_xtheadc:xthead}" \
  "%{march=rv64imafdp_xtheadc:xthead}" \
  "%{march=rv64imafdcp_xtheadc:xthead}" \
  \
  "%{march=rv64imav_xtheadc:vxthead}" \
  "%{march=rv64imacv_xtheadc:vxthead}" \
  "%{march=rv64imafv_xtheadc:vxthead}" \
  "%{march=rv64imafcv_xtheadc:vxthead}" \
  "%{march=rv64imafdv_xtheadc:vxthead}" \
  "%{march=rv64imafdcv_xtheadc:vxthead}" \
  "%{march=rv64imapv_xtheadc:vxthead}" \
  "%{march=rv64imacpv_xtheadc:vxthead}" \
  "%{march=rv64imafpv_xtheadc:vxthead}" \
  "%{march=rv64imafcpv_xtheadc:vxthead}" \
  "%{march=rv64imafdpv_xtheadc:vxthead}" \
  "%{march=rv64imafdcpv_xtheadc:vxthead}" \

#endif
