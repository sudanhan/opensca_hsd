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

all: NotifyServiceMessenger_Idl NotifyServiceMessenger_Client NotifyServiceMessenger_Consumer NotifyServiceMessenger_Server

clean depend generated realclean $(CUSTOM_TARGETS):
	@echo Project: Makefile.NotifyServiceMessenger_Idl.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.NotifyServiceMessenger_Idl.mak CFG="$(CFG)" $(@)
	@echo Project: Makefile.NotifyServiceMessenger_Client.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.NotifyServiceMessenger_Client.mak CFG="$(CFG)" $(@)
	@echo Project: Makefile.NotifyServiceMessenger_Consumer.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.NotifyServiceMessenger_Consumer.mak CFG="$(CFG)" $(@)
	@echo Project: Makefile.NotifyServiceMessenger_Server.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.NotifyServiceMessenger_Server.mak CFG="$(CFG)" $(@)

NotifyServiceMessenger_Idl:
	@echo Project: Makefile.NotifyServiceMessenger_Idl.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.NotifyServiceMessenger_Idl.mak CFG="$(CFG)" all

NotifyServiceMessenger_Client: NotifyServiceMessenger_Idl
	@echo Project: Makefile.NotifyServiceMessenger_Client.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.NotifyServiceMessenger_Client.mak CFG="$(CFG)" all

NotifyServiceMessenger_Consumer: NotifyServiceMessenger_Idl
	@echo Project: Makefile.NotifyServiceMessenger_Consumer.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.NotifyServiceMessenger_Consumer.mak CFG="$(CFG)" all

NotifyServiceMessenger_Server: NotifyServiceMessenger_Idl
	@echo Project: Makefile.NotifyServiceMessenger_Server.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.NotifyServiceMessenger_Server.mak CFG="$(CFG)" all

project_name_list:
	@echo NotifyServiceMessenger_Client
	@echo NotifyServiceMessenger_Consumer
	@echo NotifyServiceMessenger_Idl
	@echo NotifyServiceMessenger_Server
