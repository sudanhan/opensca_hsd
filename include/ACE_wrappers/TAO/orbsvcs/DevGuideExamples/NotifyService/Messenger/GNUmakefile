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

all: NotifyServiceMessenger_Idl NotifyServiceMessenger_Client NotifyServiceMessenger_Server NotifyServiceMessenger_Consumer

REMAINING_TARGETS := $(filter-out all,$(TARGETS_NESTED:.nested=)) $(CUSTOM_TARGETS)

$(REMAINING_TARGETS):
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.NotifyServiceMessenger_Idl $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.NotifyServiceMessenger_Client $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.NotifyServiceMessenger_Server $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.NotifyServiceMessenger_Consumer $(@)

.PHONY: NotifyServiceMessenger_Idl
NotifyServiceMessenger_Idl:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.NotifyServiceMessenger_Idl all

.PHONY: NotifyServiceMessenger_Client
NotifyServiceMessenger_Client: NotifyServiceMessenger_Idl
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.NotifyServiceMessenger_Client all

.PHONY: NotifyServiceMessenger_Server
NotifyServiceMessenger_Server: NotifyServiceMessenger_Idl NotifyServiceMessenger_Client
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.NotifyServiceMessenger_Server all

.PHONY: NotifyServiceMessenger_Consumer
NotifyServiceMessenger_Consumer: NotifyServiceMessenger_Idl NotifyServiceMessenger_Client NotifyServiceMessenger_Server
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.NotifyServiceMessenger_Consumer all

project_name_list:
	@echo NotifyServiceMessenger_Client
	@echo NotifyServiceMessenger_Consumer
	@echo NotifyServiceMessenger_Idl
	@echo NotifyServiceMessenger_Server
