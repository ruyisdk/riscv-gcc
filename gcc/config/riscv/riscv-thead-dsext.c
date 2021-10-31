
static sbitmap sext_marked;

static void mark_insn (rtx_insn *insn)
{
  bitmap_set_bit (sext_marked, INSN_UID (insn));

  if (dump_file)
    fprintf (dump_file, "Add insn %d to sext queue.\n",
	     INSN_UID (insn));
}

static void init_dsext_data (void)
{
  basic_block bb;
  sext_marked = sbitmap_alloc (get_max_uid () + 1);
  bitmap_clear (sext_marked);

  if (dump_file)
    fprintf (dump_file, "-------- Initialize dsext data --------\n\n");

  FOR_EACH_BB_FN (bb, cfun)
    {
      rtx_insn *insn;

      FOR_BB_INSNS (bb, insn)
	{
	  if (NONJUMP_INSN_P (insn)
	      && GET_CODE (PATTERN (insn)) == SET
	      && REG_P (SET_DEST (PATTERN (insn))))
	    {
	      rtx source = SET_SRC (PATTERN (insn));
	      enum rtx_code code = GET_CODE (source);
	      machine_mode mode = GET_MODE (SET_DEST (PATTERN (insn)));

	      if (mode == SImode)
		{
		  if (code == PLUS || code == MINUS
		      || code == MULT || code == DIV
		      || code == UDIV || code == BSWAP
		      || code == ASHIFT || code == ASHIFTRT
		      || code == LSHIFTRT || code == ROTATERT
		      || code == CONST_INT)
		    mark_insn (insn);
		}
	      else if (CONST_INT_P (source))
		{
		  /* If the mode is DI, or when the sign bit is 0 for other mode,
		     we assume the dest reg is sign extened.  */
		  if (mode == DImode && !(INTVAL (source) &
					  HOST_WIDE_INT_C (0xffffffff80000000)))
		    mark_insn (insn);
		  else if (!(INTVAL (source) &
			     ~((HOST_WIDE_INT_C (1) <<
				(GET_MODE_SIZE (mode) - 1)) - 1)))
		    mark_insn (insn);
		}
	      else if (mode == DImode && code == SIGN_EXTEND
		       && GET_MODE (XEXP (source, 0)) == SImode)
		mark_insn (insn);
	    }
	}
    }

  if (dump_file)
    fprintf (dump_file, "\n-------- Finish initializing --------\n\n");
}

/* Scan insns to find which registers have been sign extended.
   For example,
	(set (reg:DI a) (sign_extend:DI (reg:SI b)))
	(set (reg:DI c) (reg:DI a))
   then, the register 'c' is sign extended and the second insn
   will be propagated to have sext attribute. */
static bool
propagate_sext_attribute (void)
{
  basic_block bb;
  bool changed = false;

  FOR_EACH_BB_FN (bb, cfun)
    {
      rtx_insn *insn;

      FOR_BB_INSNS (bb, insn)
	{
	  if (NONJUMP_INSN_P (insn)
	      && GET_CODE (PATTERN (insn)) == SET
	      && REG_P (SET_DEST (PATTERN (insn)))
	      && GET_MODE (SET_DEST (PATTERN (insn))) == SImode)
	    {
	      rtx source = SET_SRC (PATTERN (insn));
	      enum rtx_code code = GET_CODE (source);

	      if (bitmap_bit_p (sext_marked, INSN_UID (insn)))
		continue;

	      if (code == REG || code == IF_THEN_ELSE)
		{
		  df_ref use;
		  bool can_propagate = true;

		  if (dump_file)
		    {
		      fprintf (dump_file, "Processing insn %d\n", INSN_UID (insn));
		    }

		  FOR_EACH_INSN_USE (use, insn)
		    {
		      struct df_link *defs;
		      rtx reg = DF_REF_REG (use);

		      if (!REG_P (reg))
			continue;

		      if (code == IF_THEN_ELSE
			  && REGNO (reg) != REGNO (XEXP (source, 1))
			  && REGNO (reg) != REGNO (XEXP (source, 2)))
			{
			  if (dump_file)
			    {
			      fprintf (dump_file, "Skip reg %d\n", REGNO (reg));
			    }
			  continue;
			}

		      if (dump_file)
			{
			  fprintf (dump_file, "Use reg %d\n", REGNO (reg));
			}

		      for (defs = DF_REF_CHAIN (use); defs; defs = defs->next)
			{
			  rtx_insn *ref_insn;

			  if (DF_REF_IS_ARTIFICIAL (defs->ref))
			    continue;
			  ref_insn = DF_REF_INSN (defs->ref);

			  if (!bitmap_bit_p (sext_marked, INSN_UID (ref_insn)))
			    can_propagate = false;

			  if (dump_file)
			    {
			      if (bitmap_bit_p (sext_marked, INSN_UID (ref_insn)))
				fprintf (dump_file, "Def insn %d is sexted\n", INSN_UID (ref_insn));
			      else
				fprintf (dump_file, "Def insn %d is not sexted\n", INSN_UID (ref_insn));
			    }
			}
		    }

		    if (can_propagate)
		      {
			bitmap_set_bit (sext_marked, INSN_UID (insn));
			changed = true;

			if (dump_file)
			  fprintf (dump_file, "Propagate successfully!\n");
		      }
		    if (dump_file)
		      {
			fprintf (dump_file, "\n");
		      }
		}
	    }
	  else if (NONJUMP_INSN_P (insn)
		   && GET_CODE (PATTERN (insn)) == SET
		   && REG_P (SET_DEST (PATTERN (insn)))
		   && GET_MODE (SET_DEST (PATTERN (insn))) == DImode
		   && REG_P (SET_SRC (PATTERN (insn)))
		   && GET_MODE (SET_SRC (PATTERN (insn))) == DImode)
	    {
	      df_ref use = DF_INSN_USES (insn);
	      gcc_assert (use);
	      bool can_propagate = true;
	      int unartificial_refs = 0;
	      struct df_link *defs;

	      if (bitmap_bit_p (sext_marked, INSN_UID (insn)))
		continue;

	      if (dump_file)
		{
		  fprintf (dump_file, "Processing insn %d\n", INSN_UID (insn));
		}

	      if (dump_file)
		{
		  fprintf (dump_file, "Use reg %d\n", REGNO (DF_REF_REG (use)));
		}

	      for (defs = DF_REF_CHAIN (use); defs; defs = defs->next)
		{
		  rtx_insn *ref_insn;

		  if (DF_REF_IS_ARTIFICIAL (defs->ref))
		    continue;
		  unartificial_refs ++;
		  ref_insn = DF_REF_INSN (defs->ref);

		  if (!bitmap_bit_p (sext_marked, INSN_UID (ref_insn)))
		    can_propagate = false;

		  if (dump_file)
		    {
		      if (bitmap_bit_p (sext_marked, INSN_UID (ref_insn)))
			fprintf (dump_file, "Def insn %d is sexted\n", INSN_UID (ref_insn));
		      else
			fprintf (dump_file, "Def insn %d is not sexted\n", INSN_UID (ref_insn));
		    }
		}

	      /* The register source maybe function argument,
		 it cannot be propagated. */
	      if (unartificial_refs == 0)
		can_propagate = false;

	      if (can_propagate)
		{
		  bitmap_set_bit (sext_marked, INSN_UID (insn));
		  changed = true;

		  if (dump_file)
		    fprintf (dump_file, "Propagate successfully!\n");
		}

	       if (dump_file)
		 {
		   fprintf (dump_file, "\n");
		 }
	    }
	}
    }

  return changed;
}


static void
replace_insn_regnum (rtx *pattern_ref,
		     rtx old_reg,
		     unsigned int new_regnum)
{
  const char *fmt;
  int i, j;
  enum rtx_code code = GET_CODE (*pattern_ref);

  fmt = GET_RTX_FORMAT (code);
  for (i = GET_RTX_LENGTH (code) - 1; i >= 0; i--)
    if (fmt[i] == 'e')
      replace_insn_regnum (&XEXP (*pattern_ref, i), old_reg, new_regnum);
    else if (fmt[i] == 'E')
      for (j = 0; j < XVECLEN (*pattern_ref, i); j++)
	replace_insn_regnum (&XVECEXP (*pattern_ref, i, j), old_reg,
			     new_regnum);
    else if (fmt[i] == 'r')
      {
	if (REGNO (*pattern_ref) == REGNO (old_reg))
	  *pattern_ref = gen_rtx_REG (GET_MODE (*pattern_ref), new_regnum);
      }
}


static bool
check_insn_legal (rtx checked_insn, basic_block bb)
{
  start_sequence ();
  emit_insn (checked_insn);
  rtx_insn *insn = get_insns ();
  end_sequence ();

  if (NEXT_INSN (insn))
    return false;
  if (recog_memoized (insn) < 0)
    return false;
  extract_insn (insn);
  if (!constrain_operands (1, get_preferred_alternatives (insn, bb)))
    return false;

  return true;
}


/* Change the register number of DEF to NEW_DEF_REG,
   then the registers which uses the DEF except SEXT_INSN
   should be changed too.  */

static bool
replace_use_regs (struct df_link *def, rtx new_def_reg,
		  rtx sext_insn, bool check_only)
{
  struct df_link *reg_use;
  rtx_insn *def_insn = DF_REF_INSN (def->ref);
  rtx org_reg = SET_DEST (PATTERN (def_insn));
  basic_block def_bb = BLOCK_FOR_INSN (def_insn);

  for (reg_use = DF_REF_CHAIN (def->ref); reg_use; reg_use = reg_use->next)
    {
      if (!DF_REF_INSN_INFO (reg_use->ref))
	continue;

      rtx_insn *use_insn = DF_REF_INSN (reg_use->ref);
      rtx pat = PATTERN (use_insn);
      rtx use_reg = DF_REF_REG (reg_use->ref);
      basic_block use_bb = BLOCK_FOR_INSN (use_insn);

      if (use_insn == sext_insn)
	continue;

      if (check_only)
	{
	  rtx tmp = copy_rtx ((rtx)PATTERN (use_insn));
	  replace_insn_regnum (&tmp, use_reg, REGNO (new_def_reg));
	  if (!check_insn_legal (tmp, use_bb))
	    return false;
	}
      else
	{
	  replace_insn_regnum (&pat, use_reg, REGNO (new_def_reg));
	  gcc_assert (check_insn_legal (pat, use_bb));
	  df_insn_rescan (use_insn);
	}
    }


  if (check_only)
    {
      rtx tmp = copy_rtx ((rtx)PATTERN (def_insn));
      SET_DEST (tmp) = gen_rtx_REG (
	      GET_MODE (org_reg), REGNO (new_def_reg));
      if (!check_insn_legal (tmp, def_bb))
	return false;
    }
  else
    {
      SET_DEST (PATTERN (def_insn)) = gen_rtx_REG (
	      GET_MODE (org_reg), REGNO (new_def_reg));
      gcc_assert (check_insn_legal (PATTERN (def_insn), def_bb));
      df_insn_rescan (def_insn);
    }

  return true;
}

static bool
can_delete_sext (rtx_insn *insn, bool check_only)
{
  df_ref use = DF_INSN_USES (insn);
  df_ref def = DF_INSN_DEFS (insn);
  rtx src_reg = DF_REF_REG (use);
  rtx dest_reg = DF_REF_REG (def);
  basic_block bb = BLOCK_FOR_INSN (insn);
  rtx bb_end = BB_END (bb);
  struct df_link *use_of_def;
  auto_vec<rtx_insn *> use_insns_list;

  for (use_of_def = DF_REF_CHAIN (def); use_of_def; use_of_def = use_of_def->next)
    {
      if (!DF_REF_INSN_INFO (use_of_def->ref))
	continue;

      rtx_insn *use_insn = DF_REF_INSN (use_of_def->ref);

      /* If the USE_INSN's dest is not reg and it define the
	 same register INSN defines, we cannot handle this
	 situation.  */
      if (!REG_P (SET_DEST (use_insn)))
	{
	  df_ref def_of_use_insn;

	  df_insn_info *insn_info = DF_INSN_INFO_GET (use_insn);
	  FOR_EACH_INSN_INFO_DEF (def_of_use_insn, insn_info)
	    {
	      if (DF_REF_REGNO (def_of_use_insn) == REGNO (dest_reg))
		return false;
	    }
	}

      /* If the USE_INSN is not at the same basic block of INSN(sext).
	 It's difficult to judge whether it is safe to delete the INSN,
	 so we donot delete it here.  */
      if (BLOCK_FOR_INSN (use_insn) != bb
	  || GET_CODE (PATTERN (use_insn)) != SET)
	return false;
      else
	use_insns_list.safe_push (use_insn);
    }

  /* If there is no USE_INSN, we can delete INSN directly.  */
  if (use_insns_list.is_empty ())
    return true;
  /* We cannot analysis the dependence arcoss blocks right now.  */
  else if (insn == bb_end)
    return false;
  else
    {
      rtx_insn *cur_insn = NEXT_INSN (insn);
      unsigned int i;
      rtx_insn *member;

      while (cur_insn != bb_end)
	{
	  if (DEBUG_INSN_P (cur_insn) || !INSN_P (cur_insn))
	    {
	      cur_insn = NEXT_INSN (cur_insn);
	      continue;
	    }
	  if (use_insns_list.is_empty ())
	    return true;

	  bool found = false;
	  df_ref cur_def;
	  /* If the SRC_REG has been changed, the sext cannot be deleted.  */
	  FOR_EACH_INSN_DEF (cur_def, cur_insn)
	    {
	      if (HARD_REGISTER_NUM_P (DF_REF_REGNO (cur_def))
		  && DF_REF_REGNO (cur_def) == REGNO (src_reg))
		return false;
	    }
	  FOR_EACH_VEC_ELT (use_insns_list, i, member)
	    if (member == cur_insn)
	      {
		if (check_only)
		  {
		    rtx tmp = copy_rtx ((rtx)PATTERN (member));
		    if (REG_P (SET_DEST (tmp)))
		      replace_insn_regnum (&SET_SRC (tmp), dest_reg, REGNO (src_reg));
		    else
		      replace_insn_regnum (&tmp, dest_reg, REGNO (src_reg));
		    if (!check_insn_legal (tmp, bb))
		      return false;
		  }
		else
		  {
		    if (REG_P (SET_DEST (PATTERN (member))))
		      replace_insn_regnum (&SET_SRC (PATTERN (member)),
					   dest_reg, REGNO (src_reg));
		    else
		      replace_insn_regnum (&PATTERN (member),
					   dest_reg, REGNO (src_reg));
		    gcc_assert (check_insn_legal (PATTERN (member), bb));
		    INSN_CODE (member) = -1;
		    df_insn_rescan (member);
		  }
		found = true;
		break;
	      }
	  if (found)
	    use_insns_list.unordered_remove (i);

	  cur_insn = NEXT_INSN (cur_insn);
	}
    }

  return false;
}

static bool ATTRIBUTE_UNUSED
combine_define_insn (rtx_insn *insn, bool check_only)
{
  /* Try to eliminate the sext insn,
     combine the sext insn to the insn define the source,
     and change the insns who use the defination.
     The new insn after combination should satisfy the constaint. */
  df_ref def = DF_INSN_DEFS (insn);
  rtx new_def_reg = DF_REF_REG (def);
  bool success = true;
  struct df_link *defs;
  df_ref use = DF_INSN_USES (insn);

  for (defs = DF_REF_CHAIN (use); defs; defs = defs->next)
    {
      if (DF_REF_IS_ARTIFICIAL (defs->ref))
	continue;
      if (!replace_use_regs (defs, new_def_reg, insn, true))
	{
	  success = false;
	  break;
	}
    }

  if (success && !check_only)
    {
      for (defs = DF_REF_CHAIN (use); defs; defs = defs->next)
	{
	  if (DF_REF_IS_ARTIFICIAL (defs->ref))
	    continue;
	  gcc_assert (replace_use_regs (defs, new_def_reg, insn, false));
	}
      delete_insn (insn);
    }

  return success;
}


static bool
is_lbu_insn (rtx_insn * insn)
{
  rtx pattern = PATTERN (insn);
  if (GET_CODE (pattern) == SET)
    {
      rtx src = SET_SRC (pattern);
      rtx dest = SET_DEST (pattern);

      if (GET_MODE (dest) == DImode && GET_CODE (src) == ZERO_EXTEND)
	{
	  rtx inner_src = XEXP (src, 0);
	    if (GET_CODE (inner_src) == MEM && GET_MODE (inner_src) == QImode)
	      return true;
	}
    }

  return false;
}

static void
delect_redundancy_sext (void)
{
  basic_block bb;

  if (dump_file)
    fprintf (dump_file, "-------- Start delecting sext --------\n\n");

  FOR_EACH_BB_FN (bb, cfun)
    {
      rtx_insn *insn;

      FOR_BB_INSNS (bb, insn)
	{
	  if (!(NONJUMP_INSN_P (insn)
		&& GET_CODE (PATTERN (insn)) == SET))
	    continue;

	  rtx source = SET_SRC (PATTERN (insn));
	  rtx dest = SET_DEST (PATTERN (insn));

	  if (GET_MODE (dest) == DImode
	      && REG_P (dest)
	      && GET_CODE (source) == SIGN_EXTEND
	      && REG_P (XEXP (source, 0))
	      && GET_MODE (XEXP (source, 0)) == SImode)
	    {
	      bool can_delete = true;
	      struct df_link *defs;
	      df_ref use = DF_INSN_USES (insn);
	      int unatificial_defs = 0;
	      gcc_assert (use);

	      for (defs = DF_REF_CHAIN (use); defs; defs = defs->next)
		{
		  rtx_insn *ref_insn;

		  if (DF_REF_IS_ARTIFICIAL (defs->ref))
		    continue;
		  ref_insn = DF_REF_INSN (defs->ref);

		  if (!bitmap_bit_p (sext_marked, INSN_UID (ref_insn)))
		    {
		      can_delete = false;
		      break;
		    }
		  else
		    unatificial_defs ++;
		}

	      if (!unatificial_defs)
		can_delete = false;

	      /* Detect the sequence:
			lbu rx, (ry, n)
			sext.w rz, rx  */
	      if (!can_delete)
		{
		  can_delete = true;
		  unatificial_defs = 0;
		  for (defs = DF_REF_CHAIN (use); defs; defs = defs->next)
		    {
		      rtx_insn *ref_insn;

		      if (DF_REF_IS_ARTIFICIAL (defs->ref))
			continue;
		      ref_insn = DF_REF_INSN (defs->ref);

		      if (!is_lbu_insn (ref_insn))
		    {
		      can_delete = false;
		      break;
		    }
		  else
		    unatificial_defs ++;
		    }

		  if (!unatificial_defs)
		    can_delete = false;
		}

	      if (can_delete)
		{
		  if (REGNO (dest) == REGNO (XEXP (source, 0)))
		    delete_insn (insn);
		  else if (can_delete_sext (insn, true))
		    {
		      gcc_assert (can_delete_sext (insn, false));
		      delete_insn (insn);
		    }
		  // TODO A bug exist in combine_define,
		  // some INSN will be process again after deleting.
		  //else if (combine_define_insn (insn, true))
		  //  combine_define_insn (insn, false);
		  else
		    {
		      SET_SRC (PATTERN (insn)) = gen_rtx_REG (GET_MODE (dest),
							      REGNO (XEXP (source, 0)));
		      INSN_CODE (insn) = -1;
		      df_insn_rescan (insn);
		    }
		}
	    }
	}
    }

  if (dump_file)
    fprintf (dump_file, "-------- Finish delecting sext --------\n\n");
}

static unsigned int
rest_of_handle_dsext (void)
{
  df_set_flags (DF_RD_PRUNE_DEAD_DEFS);
  df_chain_add_problem (DF_UD_CHAIN | DF_DU_CHAIN);
  df_analyze ();
  df_set_flags (DF_DEFER_INSN_RESCAN);

  init_dsext_data ();

  if (dump_file)
    fprintf (dump_file, "-------- Start propagation --------\n\n");

  while (propagate_sext_attribute ());

  if (dump_file)
    fprintf (dump_file, "-------- Finish propagation --------\n\n");

  delect_redundancy_sext ();

  sbitmap_free (sext_marked);
  return 0;
}

const pass_data pass_data_dsext =
{
    RTL_PASS, /* type */
    "dsext", /* name */
    OPTGROUP_NONE, /* optinfo_flags */
    TV_NONE, /* tv_id */
    0, /* properties_required */
    0, /* properties_provided */
    0, /* properties_destroyed */
    0, /* todo_flags_start */
    TODO_df_finish, /* todo_flags_finish */
};

class pass_delete_redundancy_sext : public rtl_opt_pass
{
  public:
      pass_delete_redundancy_sext (gcc::context *ctxt)
	  : rtl_opt_pass (pass_data_dsext, ctxt)
      {}
  /* opt_pass methods: */
  virtual bool gate (function *)
  { return riscv_insn_dsext && optimize > 0; }

  virtual unsigned int execute (function *)
  { return rest_of_handle_dsext ();}
};

rtl_opt_pass *
make_pass_delete_redundancy_sext (gcc::context *ctxt)
{
    return new pass_delete_redundancy_sext (ctxt);
}
