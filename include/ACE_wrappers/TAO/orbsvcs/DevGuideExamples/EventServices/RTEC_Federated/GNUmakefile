# -*- makefile -*-
#----------------------------------------------------------------------------
#       GNU ACE Workspace
#
# $Id: GNUACEWorkspaceCreator.pm 1861 2011-08-31 16:18:08Z mesnierp $
#
# This file was generated by MPC.  Any changes made directly to
# this file will be lost the next time it is generated.
#
# MPC Command:
# C:\ACE_wrappers\bin\mwc.pl -type gnuace
#
#----------------------------------------------------------------------------

MAKEFILE = GNUmakefile

ifeq ($(findstring k,$(MAKEFLAGS)),k)
  KEEP_GOING = -
endif

include $(ACE_ROOT)/include/makeinclude/macros.GNU

all: RTEC_Federated_Consumer RTEC_Federated_Supplier

REMAINING_TARGETS := $(filter-out all,$(TARGETS_NESTED:.nested=)) $(CUSTOM_TARGETS)

$(REMAINING_TARGETS):
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.RTEC_Federated_Consumer $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.RTEC_Federated_Supplier $(@)

.PHONY: RTEC_Federated_Consumer
RTEC_Federated_Consumer:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.RTEC_Federated_Consumer all

.PHONY: RTEC_Federated_Supplier
RTEC_Federated_Supplier:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.RTEC_Federated_Supplier all

project_name_list:
	@echo RTEC_Federated_Consumer
	@echo RTEC_Federated_Supplier
