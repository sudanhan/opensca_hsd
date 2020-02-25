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

all: LoadBalancing_Performance_IDL LoadBalancing_Performance_Client LoadBalancing_Performance_Server RTEC_Perf Colocated_Roundtrip Federated_Roundtrip_Client Federated_Roundtrip_Server RTCORBA_Baseline_IDL RTCORBA_Baseline_Client RTCORBA_Baseline_Server RTCORBA_Callback_IDL RTCORBA_Callback_Client RTCORBA_Callback_Server Roundtrip_RTEvent_Client Roundtrip_RTEvent_Server TCP_Baseline_Client TCP_Baseline_Server

clean depend generated realclean $(CUSTOM_TARGETS):
	@cd LoadBalancing/LBPerf/RPS
	@echo Directory: LoadBalancing/LBPerf/RPS
	@echo Project: Makefile.LoadBalancing_Performance_IDL.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.LoadBalancing_Performance_IDL.mak CFG="$(CFG)" $(@)
	@cd $(MAKEDIR)
	@cd LoadBalancing/LBPerf/RPS
	@echo Directory: LoadBalancing/LBPerf/RPS
	@echo Project: Makefile.LoadBalancing_Performance_Client.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.LoadBalancing_Performance_Client.mak CFG="$(CFG)" $(@)
	@cd $(MAKEDIR)
	@cd LoadBalancing/LBPerf/RPS
	@echo Directory: LoadBalancing/LBPerf/RPS
	@echo Project: Makefile.LoadBalancing_Performance_Server.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.LoadBalancing_Performance_Server.mak CFG="$(CFG)" $(@)
	@cd $(MAKEDIR)
	@cd RTEvent/lib
	@echo Directory: RTEvent/lib
	@echo Project: Makefile.RTEC_Perf.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.RTEC_Perf.mak CFG="$(CFG)" $(@)
	@cd $(MAKEDIR)
	@cd RTEvent/Colocated_Roundtrip
	@echo Directory: RTEvent/Colocated_Roundtrip
	@echo Project: Makefile.Colocated_Roundtrip.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.Colocated_Roundtrip.mak CFG="$(CFG)" $(@)
	@cd $(MAKEDIR)
	@cd RTEvent/Federated_Roundtrip
	@echo Directory: RTEvent/Federated_Roundtrip
	@echo Project: Makefile.Federated_Roundtrip_Client.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.Federated_Roundtrip_Client.mak CFG="$(CFG)" $(@)
	@cd $(MAKEDIR)
	@cd RTEvent/Federated_Roundtrip
	@echo Directory: RTEvent/Federated_Roundtrip
	@echo Project: Makefile.Federated_Roundtrip_Server.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.Federated_Roundtrip_Server.mak CFG="$(CFG)" $(@)
	@cd $(MAKEDIR)
	@cd RTEvent/RTCORBA_Baseline
	@echo Directory: RTEvent/RTCORBA_Baseline
	@echo Project: Makefile.RTCORBA_Baseline_IDL.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.RTCORBA_Baseline_IDL.mak CFG="$(CFG)" $(@)
	@cd $(MAKEDIR)
	@cd RTEvent/RTCORBA_Baseline
	@echo Directory: RTEvent/RTCORBA_Baseline
	@echo Project: Makefile.RTCORBA_Baseline_Client.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.RTCORBA_Baseline_Client.mak CFG="$(CFG)" $(@)
	@cd $(MAKEDIR)
	@cd RTEvent/RTCORBA_Baseline
	@echo Directory: RTEvent/RTCORBA_Baseline
	@echo Project: Makefile.RTCORBA_Baseline_Server.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.RTCORBA_Baseline_Server.mak CFG="$(CFG)" $(@)
	@cd $(MAKEDIR)
	@cd RTEvent/RTCORBA_Callback
	@echo Directory: RTEvent/RTCORBA_Callback
	@echo Project: Makefile.RTCORBA_Callback_IDL.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.RTCORBA_Callback_IDL.mak CFG="$(CFG)" $(@)
	@cd $(MAKEDIR)
	@cd RTEvent/RTCORBA_Callback
	@echo Directory: RTEvent/RTCORBA_Callback
	@echo Project: Makefile.RTCORBA_Callback_Client.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.RTCORBA_Callback_Client.mak CFG="$(CFG)" $(@)
	@cd $(MAKEDIR)
	@cd RTEvent/RTCORBA_Callback
	@echo Directory: RTEvent/RTCORBA_Callback
	@echo Project: Makefile.RTCORBA_Callback_Server.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.RTCORBA_Callback_Server.mak CFG="$(CFG)" $(@)
	@cd $(MAKEDIR)
	@cd RTEvent/Roundtrip
	@echo Directory: RTEvent/Roundtrip
	@echo Project: Makefile.Roundtrip_RTEvent_Client.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.Roundtrip_RTEvent_Client.mak CFG="$(CFG)" $(@)
	@cd $(MAKEDIR)
	@cd RTEvent/Roundtrip
	@echo Directory: RTEvent/Roundtrip
	@echo Project: Makefile.Roundtrip_RTEvent_Server.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.Roundtrip_RTEvent_Server.mak CFG="$(CFG)" $(@)
	@cd $(MAKEDIR)
	@cd RTEvent/TCP_Baseline
	@echo Directory: RTEvent/TCP_Baseline
	@echo Project: Makefile.TCP_Baseline_Client.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.TCP_Baseline_Client.mak CFG="$(CFG)" $(@)
	@cd $(MAKEDIR)
	@cd RTEvent/TCP_Baseline
	@echo Directory: RTEvent/TCP_Baseline
	@echo Project: Makefile.TCP_Baseline_Server.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.TCP_Baseline_Server.mak CFG="$(CFG)" $(@)
	@cd $(MAKEDIR)

LoadBalancing_Performance_IDL:
	@cd LoadBalancing/LBPerf/RPS
	@echo Directory: LoadBalancing/LBPerf/RPS
	@echo Project: Makefile.LoadBalancing_Performance_IDL.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.LoadBalancing_Performance_IDL.mak CFG="$(CFG)" all
	@cd $(MAKEDIR)

LoadBalancing_Performance_Client: LoadBalancing_Performance_IDL
	@cd LoadBalancing/LBPerf/RPS
	@echo Directory: LoadBalancing/LBPerf/RPS
	@echo Project: Makefile.LoadBalancing_Performance_Client.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.LoadBalancing_Performance_Client.mak CFG="$(CFG)" all
	@cd $(MAKEDIR)

LoadBalancing_Performance_Server: LoadBalancing_Performance_IDL
	@cd LoadBalancing/LBPerf/RPS
	@echo Directory: LoadBalancing/LBPerf/RPS
	@echo Project: Makefile.LoadBalancing_Performance_Server.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.LoadBalancing_Performance_Server.mak CFG="$(CFG)" all
	@cd $(MAKEDIR)

RTEC_Perf:
	@cd RTEvent/lib
	@echo Directory: RTEvent/lib
	@echo Project: Makefile.RTEC_Perf.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.RTEC_Perf.mak CFG="$(CFG)" all
	@cd $(MAKEDIR)

Colocated_Roundtrip: RTEC_Perf
	@cd RTEvent/Colocated_Roundtrip
	@echo Directory: RTEvent/Colocated_Roundtrip
	@echo Project: Makefile.Colocated_Roundtrip.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.Colocated_Roundtrip.mak CFG="$(CFG)" all
	@cd $(MAKEDIR)

Federated_Roundtrip_Client: RTEC_Perf
	@cd RTEvent/Federated_Roundtrip
	@echo Directory: RTEvent/Federated_Roundtrip
	@echo Project: Makefile.Federated_Roundtrip_Client.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.Federated_Roundtrip_Client.mak CFG="$(CFG)" all
	@cd $(MAKEDIR)

Federated_Roundtrip_Server: RTEC_Perf
	@cd RTEvent/Federated_Roundtrip
	@echo Directory: RTEvent/Federated_Roundtrip
	@echo Project: Makefile.Federated_Roundtrip_Server.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.Federated_Roundtrip_Server.mak CFG="$(CFG)" all
	@cd $(MAKEDIR)

RTCORBA_Baseline_IDL:
	@cd RTEvent/RTCORBA_Baseline
	@echo Directory: RTEvent/RTCORBA_Baseline
	@echo Project: Makefile.RTCORBA_Baseline_IDL.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.RTCORBA_Baseline_IDL.mak CFG="$(CFG)" all
	@cd $(MAKEDIR)

RTCORBA_Baseline_Client: RTEC_Perf RTCORBA_Baseline_IDL
	@cd RTEvent/RTCORBA_Baseline
	@echo Directory: RTEvent/RTCORBA_Baseline
	@echo Project: Makefile.RTCORBA_Baseline_Client.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.RTCORBA_Baseline_Client.mak CFG="$(CFG)" all
	@cd $(MAKEDIR)

RTCORBA_Baseline_Server: RTEC_Perf RTCORBA_Baseline_IDL
	@cd RTEvent/RTCORBA_Baseline
	@echo Directory: RTEvent/RTCORBA_Baseline
	@echo Project: Makefile.RTCORBA_Baseline_Server.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.RTCORBA_Baseline_Server.mak CFG="$(CFG)" all
	@cd $(MAKEDIR)

RTCORBA_Callback_IDL:
	@cd RTEvent/RTCORBA_Callback
	@echo Directory: RTEvent/RTCORBA_Callback
	@echo Project: Makefile.RTCORBA_Callback_IDL.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.RTCORBA_Callback_IDL.mak CFG="$(CFG)" all
	@cd $(MAKEDIR)

RTCORBA_Callback_Client: RTEC_Perf RTCORBA_Callback_IDL
	@cd RTEvent/RTCORBA_Callback
	@echo Directory: RTEvent/RTCORBA_Callback
	@echo Project: Makefile.RTCORBA_Callback_Client.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.RTCORBA_Callback_Client.mak CFG="$(CFG)" all
	@cd $(MAKEDIR)

RTCORBA_Callback_Server: RTEC_Perf RTCORBA_Callback_IDL
	@cd RTEvent/RTCORBA_Callback
	@echo Directory: RTEvent/RTCORBA_Callback
	@echo Project: Makefile.RTCORBA_Callback_Server.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.RTCORBA_Callback_Server.mak CFG="$(CFG)" all
	@cd $(MAKEDIR)

Roundtrip_RTEvent_Client: RTEC_Perf
	@cd RTEvent/Roundtrip
	@echo Directory: RTEvent/Roundtrip
	@echo Project: Makefile.Roundtrip_RTEvent_Client.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.Roundtrip_RTEvent_Client.mak CFG="$(CFG)" all
	@cd $(MAKEDIR)

Roundtrip_RTEvent_Server: RTEC_Perf
	@cd RTEvent/Roundtrip
	@echo Directory: RTEvent/Roundtrip
	@echo Project: Makefile.Roundtrip_RTEvent_Server.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.Roundtrip_RTEvent_Server.mak CFG="$(CFG)" all
	@cd $(MAKEDIR)

TCP_Baseline_Client: RTEC_Perf
	@cd RTEvent/TCP_Baseline
	@echo Directory: RTEvent/TCP_Baseline
	@echo Project: Makefile.TCP_Baseline_Client.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.TCP_Baseline_Client.mak CFG="$(CFG)" all
	@cd $(MAKEDIR)

TCP_Baseline_Server: RTEC_Perf
	@cd RTEvent/TCP_Baseline
	@echo Directory: RTEvent/TCP_Baseline
	@echo Project: Makefile.TCP_Baseline_Server.mak
	$(MAKE) /$(MAKEFLAGS) /f Makefile.TCP_Baseline_Server.mak CFG="$(CFG)" all
	@cd $(MAKEDIR)

project_name_list:
	@echo LoadBalancing_Performance_Client
	@echo LoadBalancing_Performance_IDL
	@echo LoadBalancing_Performance_Server
	@echo Colocated_Roundtrip
	@echo Federated_Roundtrip_Client
	@echo Federated_Roundtrip_Server
	@echo RTCORBA_Baseline_Client
	@echo RTCORBA_Baseline_IDL
	@echo RTCORBA_Baseline_Server
	@echo RTCORBA_Callback_Client
	@echo RTCORBA_Callback_IDL
	@echo RTCORBA_Callback_Server
	@echo Roundtrip_RTEvent_Client
	@echo Roundtrip_RTEvent_Server
	@echo TCP_Baseline_Client
	@echo TCP_Baseline_Server
	@echo RTEC_Perf
