#----------------------------------------------------------------------------
#       NMAKE Workspace
#
# $Id: NMakeWorkspaceCreator.pm 2035 2011-10-06 15:05:21Z johnnyw $
#
# This file was generated by MPC.  Any changes made directly to
# this file will be lost the next time it is generated.
#
# MPC Command:
# bin/mwc.pl -type nmake -value_template platforms=Win64 -make_coexistence -recurse -exclude TAO/CIAO -features qos=1,mfc=1
#
#----------------------------------------------------------------------------

!IF "$(CFG)" == ""
CFG=Win64 Debug
!MESSAGE No configuration specified. Defaulting to Win64 Debug.
!ENDIF

!IF "$(CUSTOM_TARGETS)" == ""
CUSTOM_TARGETS=_EMPTY_TARGET_
!ENDIF

all: DiffServPolicy_Idl DiffServPolicy

clean depend generated realclean $(CUSTOM_TARGETS):
	@echo Project: Makefile.DiffServPolicy_Idl.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.DiffServPolicy_Idl.mak CFG="$(CFG)" $(@)
	@echo Project: Makefile.DiffServPolicy.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.DiffServPolicy.mak CFG="$(CFG)" $(@)

DiffServPolicy_Idl:
	@echo Project: Makefile.DiffServPolicy_Idl.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.DiffServPolicy_Idl.mak CFG="$(CFG)" all

DiffServPolicy: DiffServPolicy_Idl
	@echo Project: Makefile.DiffServPolicy.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.DiffServPolicy.mak CFG="$(CFG)" all

project_name_list:
	@echo DiffServPolicy
	@echo DiffServPolicy_Idl
