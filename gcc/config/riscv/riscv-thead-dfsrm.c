
static unsigned int
rest_of_handle_dfsrm (void)
{
  basic_block bb;

  FOR_EACH_BB_FN (bb, cfun)
    {
      rtx_insn *insn;
      int last_fsrm = -1;

      FOR_BB_INSNS (bb, insn)
	{
	  if (NONJUMP_INSN_P (insn)
	      && GET_CODE (PATTERN (insn)) == SET
	      && GET_CODE (SET_SRC (PATTERN (insn))) == UNSPEC_VOLATILE
	      && XINT (SET_SRC (PATTERN (insn)), 1) == UNSPECV_FSRM)
	    {
	      if (dump_file)
		fprintf (dump_file, "Found fsrm insn (%d).\n",INSN_UID (insn));
	      rtx round_mode = XVECEXP (SET_SRC (PATTERN (insn)), 0, 0);
	      if (CONST_INT_P (round_mode))
		{
		  HOST_WIDE_INT round_mode_value = INTVAL (round_mode);
		  if (last_fsrm != -1)
		    {
		      if (round_mode_value != last_fsrm)
			{
			  if (dump_file)
			    fprintf (dump_file, "\tReset the record mode from (%d) to (%d)\n",
				     last_fsrm, round_mode_value);
			  last_fsrm = round_mode_value;
			}
		      else
			{
			  if (dump_file)
			    fprintf (dump_file, "\tSame mode, delete the insn\n");
			  delete_insn (insn);
			}
		    }
		  else
		    {
		      if (dump_file)
			fprintf (dump_file, "\tNot find last const set fsrm, record the mode (%d)\n",
				 round_mode_value);
		      last_fsrm = round_mode_value;
		    }
		}
	      else
		{
		  if (dump_file)
		    fprintf (dump_file, "\tThe fsrm is set by register, clear record.\n");
		  last_fsrm = -1;
		}
	    }
	}
    }
  return 0;
}

const pass_data pass_data_dfsrm =
{
    RTL_PASS, /* type */
    "dfsrm", /* name */
    OPTGROUP_NONE, /* optinfo_flags */
    TV_NONE, /* tv_id */
    0, /* properties_required */
    0, /* properties_provided */
    0, /* properties_destroyed */
    0, /* todo_flags_start */
    TODO_df_finish, /* todo_flags_finish */
};

class pass_delete_redundancy_fsrm : public rtl_opt_pass
{
  public:
      pass_delete_redundancy_fsrm (gcc::context *ctxt)
	  : rtl_opt_pass (pass_data_dfsrm, ctxt)
      {}
  /* opt_pass methods: */
  virtual bool gate (function *)
  { return riscv_insn_dfsrm && optimize > 0; }

  virtual unsigned int execute (function *)
  { return rest_of_handle_dfsrm ();}
}; // class pass_delete_redundancy_fsrm

rtl_opt_pass *
make_pass_delete_redundancy_fsrm (gcc::context *ctxt)
{
  return new pass_delete_redundancy_fsrm (ctxt);
}
