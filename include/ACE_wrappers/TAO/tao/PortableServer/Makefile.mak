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

all: PortableServer_Idl PortableServer

clean depend generated realclean $(CUSTOM_TARGETS):
	@echo Project: Makefile.PortableServer_Idl.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.PortableServer_Idl.mak CFG="$(CFG)" $(@)
	@echo Project: Makefile.PortableServer.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.PortableServer.mak CFG="$(CFG)" $(@)

PortableServer_Idl:
	@echo Project: Makefile.PortableServer_Idl.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.PortableServer_Idl.mak CFG="$(CFG)" all

PortableServer: PortableServer_Idl
	@echo Project: Makefile.PortableServer.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.PortableServer.mak CFG="$(CFG)" all

project_name_list:
	@echo PortableServer
	@echo PortableServer_Idl
