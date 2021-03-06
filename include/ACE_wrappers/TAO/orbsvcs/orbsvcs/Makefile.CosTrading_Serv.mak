# Microsoft Developer Studio Generated NMAKE File
!IF "$(CFG)" == ""
CFG=Win64 Debug
!MESSAGE No configuration specified. Defaulting to Win64 Debug.
!ENDIF

!IF "$(CFG)" == "Win64 Debug" || "$(CFG)" == "Win64 Release" || "$(CFG)" == "Win64 Static Debug" || "$(CFG)" == "Win64 Static Release"
!ELSE
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "Makefile.CosTrading_Serv.mak" CFG="Win64 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "Win64 Debug" (based on "Win64 (IA64) Dynamic-Link Library")
!MESSAGE "Win64 Release" (based on "Win64 (IA64) Dynamic-Link Library")
!MESSAGE "Win64 Static Debug" (based on "Win64 (IA64) Static Library")
!MESSAGE "Win64 Static Release" (based on "Win64 (IA64) Static Library")
!MESSAGE
!ERROR An invalid configuration was specified.
!ENDIF

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF

!IF "$(DEPGEN)" == ""
!IF EXISTS("$(MPC_ROOT)/depgen.pl")
DEPGEN=perl $(MPC_ROOT)/depgen.pl -i -t nmake
!ELSEIF EXISTS("$(DEPGEN_ROOT)/depgen.pl")
DEPGEN=perl $(DEPGEN_ROOT)/depgen.pl -i -t nmake
!ELSEIF EXISTS("$(ACE_ROOT)/bin/depgen.pl")
DEPGEN=perl $(ACE_ROOT)/bin/depgen.pl -i -t nmake
!ENDIF
!ENDIF

GENERATED_DIRTY =

!IF  "$(CFG)" == "Win64 Debug"

OUTDIR=..\..\..\lib
INTDIR=Debug\CosTrading_Serv\IA64

ALL : "$(INTDIR)" "$(OUTDIR)" DEPENDCHECK $(GENERATED_DIRTY) "..\..\..\lib\TAO_CosTrading_Servd.dll"

DEPEND :
!IF "$(DEPGEN)" == ""
	@echo No suitable dependency generator could be found.
	@echo One comes with MPC, just set the MPC_ROOT environment variable
	@echo to the full path of MPC.  You can download MPC from
	@echo http://www.ociweb.com/products/mpc/down.html
!ELSE
	$(DEPGEN) -I"..\..\.." -I"..\.." -I"..\..\orbsvcs" -D_DEBUG -DWIN64 -DWIN32 -D_WINDOWS -D_CRT_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -DTAO_TRADING_SERV_BUILD_DLL -f "Makefile.CosTrading_Serv.dep" "Trader\Offer_Iterators.cpp" "Trader\Trader_Utils.cpp" "Trader\Constraint_y.cpp" "Trader\Trader.cpp" "Trader\Service_Type_Repository.cpp" "Trader\Constraint_l.cpp" "Trader\Constraint_Interpreter.cpp" "Trader\Interpreter.cpp" "Trader\Offer_Database.cpp" "Trader\Trading_Loader.cpp" "Trader\Interpreter_Utils.cpp" "Trader\Trader_Interfaces.cpp" "Trader\Constraint_Visitors.cpp" "Trader\Trader_Constraint_Visitors.cpp" "Trader\Constraint_Nodes.cpp"
!ENDIF

REALCLEAN : CLEAN
	-@del /f/q "$(OUTDIR)\TAO_CosTrading_Servd.pdb"
	-@del /f/q "..\..\..\lib\TAO_CosTrading_Servd.dll"
	-@del /f/q "$(OUTDIR)\TAO_CosTrading_Servd.lib"
	-@del /f/q "$(OUTDIR)\TAO_CosTrading_Servd.exp"
	-@del /f/q "$(OUTDIR)\TAO_CosTrading_Servd.ilk"

"$(INTDIR)" :
	if not exist "Debug\$(NULL)" mkdir "Debug"
	if not exist "Debug\CosTrading_Serv\$(NULL)" mkdir "Debug\CosTrading_Serv"
	if not exist "$(INTDIR)\$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
CPP_COMMON=/Zc:wchar_t /nologo /Wp64 /Ob0 /W3 /Gm /EHsc /Zi /MDd /GR /Gy /wd4355 /wd4250 /wd4290 /Fd"$(INTDIR)/" /I "..\..\.." /I "..\.." /I "..\..\orbsvcs" /D _DEBUG /D WIN64 /D WIN32 /D _WINDOWS /D _CRT_SECURE_NO_WARNINGS /D _CRT_SECURE_NO_DEPRECATE /D _CRT_NONSTDC_NO_DEPRECATE /D TAO_TRADING_SERV_BUILD_DLL /D MPC_LIB_MODIFIER=\"d\" /FD /c

CPP_PROJ=$(CPP_COMMON) /Fo"$(INTDIR)\\"

RSC=rc.exe

LINK32=link.exe
LINK32_FLAGS=advapi32.lib user32.lib /INCREMENTAL:NO ACEd.lib TAOd.lib TAO_AnyTypeCoded.lib TAO_CosTradingd.lib TAO_PortableServerd.lib TAO_CosTrading_Skeld.lib TAO_Valuetyped.lib TAO_DynamicAnyd.lib TAO_Svc_Utilsd.lib TAO_CodecFactoryd.lib TAO_PId.lib TAO_Utilsd.lib TAO_IORTabled.lib /libpath:"." /libpath:"..\..\..\lib" /nologo /subsystem:windows /dll /debug /pdb:"..\..\..\lib\TAO_CosTrading_Servd.pdb" /machine:IA64 /out:"..\..\..\lib\TAO_CosTrading_Servd.dll" /implib:"$(OUTDIR)\TAO_CosTrading_Servd.lib"
LINK32_OBJS= \
	"$(INTDIR)\CosTrading_Serv.res" \
	"$(INTDIR)\Trader\Offer_Iterators.obj" \
	"$(INTDIR)\Trader\Trader_Utils.obj" \
	"$(INTDIR)\Trader\Constraint_y.obj" \
	"$(INTDIR)\Trader\Trader.obj" \
	"$(INTDIR)\Trader\Service_Type_Repository.obj" \
	"$(INTDIR)\Trader\Constraint_l.obj" \
	"$(INTDIR)\Trader\Constraint_Interpreter.obj" \
	"$(INTDIR)\Trader\Interpreter.obj" \
	"$(INTDIR)\Trader\Offer_Database.obj" \
	"$(INTDIR)\Trader\Trading_Loader.obj" \
	"$(INTDIR)\Trader\Interpreter_Utils.obj" \
	"$(INTDIR)\Trader\Trader_Interfaces.obj" \
	"$(INTDIR)\Trader\Constraint_Visitors.obj" \
	"$(INTDIR)\Trader\Trader_Constraint_Visitors.obj" \
	"$(INTDIR)\Trader\Constraint_Nodes.obj"

"..\..\..\lib\TAO_CosTrading_Servd.dll" : $(DEF_FILE) $(LINK32_OBJS)
	$(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<
	if exist "..\..\..\lib\TAO_CosTrading_Servd.dll.manifest" mt.exe -manifest "..\..\..\lib\TAO_CosTrading_Servd.dll.manifest" -outputresource:$@;2

!ELSEIF  "$(CFG)" == "Win64 Release"

OUTDIR=..\..\..\lib
INTDIR=Release\CosTrading_Serv\IA64

ALL : "$(INTDIR)" "$(OUTDIR)" DEPENDCHECK $(GENERATED_DIRTY) "..\..\..\lib\TAO_CosTrading_Serv.dll"

DEPEND :
!IF "$(DEPGEN)" == ""
	@echo No suitable dependency generator could be found.
	@echo One comes with MPC, just set the MPC_ROOT environment variable
	@echo to the full path of MPC.  You can download MPC from
	@echo http://www.ociweb.com/products/mpc/down.html
!ELSE
	$(DEPGEN) -I"..\..\.." -I"..\.." -I"..\..\orbsvcs" -DNDEBUG -DWIN64 -DWIN32 -D_WINDOWS -D_CRT_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -DTAO_TRADING_SERV_BUILD_DLL -f "Makefile.CosTrading_Serv.dep" "Trader\Offer_Iterators.cpp" "Trader\Trader_Utils.cpp" "Trader\Constraint_y.cpp" "Trader\Trader.cpp" "Trader\Service_Type_Repository.cpp" "Trader\Constraint_l.cpp" "Trader\Constraint_Interpreter.cpp" "Trader\Interpreter.cpp" "Trader\Offer_Database.cpp" "Trader\Trading_Loader.cpp" "Trader\Interpreter_Utils.cpp" "Trader\Trader_Interfaces.cpp" "Trader\Constraint_Visitors.cpp" "Trader\Trader_Constraint_Visitors.cpp" "Trader\Constraint_Nodes.cpp"
!ENDIF

REALCLEAN : CLEAN
	-@del /f/q "..\..\..\lib\TAO_CosTrading_Serv.dll"
	-@del /f/q "$(OUTDIR)\TAO_CosTrading_Serv.lib"
	-@del /f/q "$(OUTDIR)\TAO_CosTrading_Serv.exp"
	-@del /f/q "$(OUTDIR)\TAO_CosTrading_Serv.ilk"

"$(INTDIR)" :
	if not exist "Release\$(NULL)" mkdir "Release"
	if not exist "Release\CosTrading_Serv\$(NULL)" mkdir "Release\CosTrading_Serv"
	if not exist "$(INTDIR)\$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
CPP_COMMON=/Zc:wchar_t /nologo /Wp64 /O2 /W3 /EHsc /MD /GR /wd4355 /wd4250 /wd4290 /I "..\..\.." /I "..\.." /I "..\..\orbsvcs" /D NDEBUG /D WIN64 /D WIN32 /D _WINDOWS /D _CRT_SECURE_NO_WARNINGS /D _CRT_SECURE_NO_DEPRECATE /D _CRT_NONSTDC_NO_DEPRECATE /D TAO_TRADING_SERV_BUILD_DLL  /FD /c

CPP_PROJ=$(CPP_COMMON) /Fo"$(INTDIR)\\"

RSC=rc.exe

LINK32=link.exe
LINK32_FLAGS=advapi32.lib user32.lib /INCREMENTAL:NO ACE.lib TAO.lib TAO_AnyTypeCode.lib TAO_CosTrading.lib TAO_PortableServer.lib TAO_CosTrading_Skel.lib TAO_Valuetype.lib TAO_DynamicAny.lib TAO_Svc_Utils.lib TAO_CodecFactory.lib TAO_PI.lib TAO_Utils.lib TAO_IORTable.lib /libpath:"." /libpath:"..\..\..\lib" /nologo /subsystem:windows /dll  /machine:IA64 /out:"..\..\..\lib\TAO_CosTrading_Serv.dll" /implib:"$(OUTDIR)\TAO_CosTrading_Serv.lib"
LINK32_OBJS= \
	"$(INTDIR)\CosTrading_Serv.res" \
	"$(INTDIR)\Trader\Offer_Iterators.obj" \
	"$(INTDIR)\Trader\Trader_Utils.obj" \
	"$(INTDIR)\Trader\Constraint_y.obj" \
	"$(INTDIR)\Trader\Trader.obj" \
	"$(INTDIR)\Trader\Service_Type_Repository.obj" \
	"$(INTDIR)\Trader\Constraint_l.obj" \
	"$(INTDIR)\Trader\Constraint_Interpreter.obj" \
	"$(INTDIR)\Trader\Interpreter.obj" \
	"$(INTDIR)\Trader\Offer_Database.obj" \
	"$(INTDIR)\Trader\Trading_Loader.obj" \
	"$(INTDIR)\Trader\Interpreter_Utils.obj" \
	"$(INTDIR)\Trader\Trader_Interfaces.obj" \
	"$(INTDIR)\Trader\Constraint_Visitors.obj" \
	"$(INTDIR)\Trader\Trader_Constraint_Visitors.obj" \
	"$(INTDIR)\Trader\Constraint_Nodes.obj"

"..\..\..\lib\TAO_CosTrading_Serv.dll" : $(DEF_FILE) $(LINK32_OBJS)
	$(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<
	if exist "..\..\..\lib\TAO_CosTrading_Serv.dll.manifest" mt.exe -manifest "..\..\..\lib\TAO_CosTrading_Serv.dll.manifest" -outputresource:$@;2

!ELSEIF  "$(CFG)" == "Win64 Static Debug"

OUTDIR=..\..\..\lib
INTDIR=Static_Debug\CosTrading_Serv\IA64

ALL : "$(INTDIR)" "$(OUTDIR)" DEPENDCHECK $(GENERATED_DIRTY) "$(OUTDIR)\TAO_CosTrading_Servsd.lib"

DEPEND :
!IF "$(DEPGEN)" == ""
	@echo No suitable dependency generator could be found.
	@echo One comes with MPC, just set the MPC_ROOT environment variable
	@echo to the full path of MPC.  You can download MPC from
	@echo http://www.ociweb.com/products/mpc/down.html
!ELSE
	$(DEPGEN) -I"..\..\.." -I"..\.." -I"..\..\orbsvcs" -D_DEBUG -DWIN64 -DWIN32 -D_WINDOWS -D_CRT_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -DACE_AS_STATIC_LIBS -DTAO_AS_STATIC_LIBS -f "Makefile.CosTrading_Serv.dep" "Trader\Offer_Iterators.cpp" "Trader\Trader_Utils.cpp" "Trader\Constraint_y.cpp" "Trader\Trader.cpp" "Trader\Service_Type_Repository.cpp" "Trader\Constraint_l.cpp" "Trader\Constraint_Interpreter.cpp" "Trader\Interpreter.cpp" "Trader\Offer_Database.cpp" "Trader\Trading_Loader.cpp" "Trader\Interpreter_Utils.cpp" "Trader\Trader_Interfaces.cpp" "Trader\Constraint_Visitors.cpp" "Trader\Trader_Constraint_Visitors.cpp" "Trader\Constraint_Nodes.cpp"
!ENDIF

REALCLEAN : CLEAN
	-@del /f/q "$(OUTDIR)\TAO_CosTrading_Servsd.lib"
	-@del /f/q "$(OUTDIR)\TAO_CosTrading_Servsd.exp"
	-@del /f/q "$(OUTDIR)\TAO_CosTrading_Servsd.ilk"
	-@del /f/q "..\..\..\lib\TAO_CosTrading_Servsd.pdb"

"$(INTDIR)" :
	if not exist "Static_Debug\$(NULL)" mkdir "Static_Debug"
	if not exist "Static_Debug\CosTrading_Serv\$(NULL)" mkdir "Static_Debug\CosTrading_Serv"
	if not exist "$(INTDIR)\$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
CPP_COMMON=/Zc:wchar_t /nologo /Wp64 /Ob0 /W3 /Gm /EHsc /Zi /GR /Gy /MDd /wd4355 /wd4250 /wd4290 /Fd"..\..\..\lib\TAO_CosTrading_Servsd.pdb" /I "..\..\.." /I "..\.." /I "..\..\orbsvcs" /D _DEBUG /D WIN64 /D WIN32 /D _WINDOWS /D _CRT_SECURE_NO_WARNINGS /D _CRT_SECURE_NO_DEPRECATE /D _CRT_NONSTDC_NO_DEPRECATE /D ACE_AS_STATIC_LIBS /D TAO_AS_STATIC_LIBS /D MPC_LIB_MODIFIER=\"sd\" /FD /c

CPP_PROJ=$(CPP_COMMON) /Fo"$(INTDIR)\\"


LINK32=link.exe -lib
LINK32_FLAGS=/nologo /machine:IA64 /out:"..\..\..\lib\TAO_CosTrading_Servsd.lib"
LINK32_OBJS= \
	"$(INTDIR)\Trader\Offer_Iterators.obj" \
	"$(INTDIR)\Trader\Trader_Utils.obj" \
	"$(INTDIR)\Trader\Constraint_y.obj" \
	"$(INTDIR)\Trader\Trader.obj" \
	"$(INTDIR)\Trader\Service_Type_Repository.obj" \
	"$(INTDIR)\Trader\Constraint_l.obj" \
	"$(INTDIR)\Trader\Constraint_Interpreter.obj" \
	"$(INTDIR)\Trader\Interpreter.obj" \
	"$(INTDIR)\Trader\Offer_Database.obj" \
	"$(INTDIR)\Trader\Trading_Loader.obj" \
	"$(INTDIR)\Trader\Interpreter_Utils.obj" \
	"$(INTDIR)\Trader\Trader_Interfaces.obj" \
	"$(INTDIR)\Trader\Constraint_Visitors.obj" \
	"$(INTDIR)\Trader\Trader_Constraint_Visitors.obj" \
	"$(INTDIR)\Trader\Constraint_Nodes.obj"

"$(OUTDIR)\TAO_CosTrading_Servsd.lib" : $(DEF_FILE) $(LINK32_OBJS)
	$(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<
	if exist "$(OUTDIR)\TAO_CosTrading_Servsd.lib.manifest" mt.exe -manifest "$(OUTDIR)\TAO_CosTrading_Servsd.lib.manifest" -outputresource:$@;2

!ELSEIF  "$(CFG)" == "Win64 Static Release"

OUTDIR=..\..\..\lib
INTDIR=Static_Release\CosTrading_Serv\IA64

ALL : "$(INTDIR)" "$(OUTDIR)" DEPENDCHECK $(GENERATED_DIRTY) "$(OUTDIR)\TAO_CosTrading_Servs.lib"

DEPEND :
!IF "$(DEPGEN)" == ""
	@echo No suitable dependency generator could be found.
	@echo One comes with MPC, just set the MPC_ROOT environment variable
	@echo to the full path of MPC.  You can download MPC from
	@echo http://www.ociweb.com/products/mpc/down.html
!ELSE
	$(DEPGEN) -I"..\..\.." -I"..\.." -I"..\..\orbsvcs" -DNDEBUG -DWIN64 -DWIN32 -D_WINDOWS -D_CRT_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -DACE_AS_STATIC_LIBS -DTAO_AS_STATIC_LIBS -f "Makefile.CosTrading_Serv.dep" "Trader\Offer_Iterators.cpp" "Trader\Trader_Utils.cpp" "Trader\Constraint_y.cpp" "Trader\Trader.cpp" "Trader\Service_Type_Repository.cpp" "Trader\Constraint_l.cpp" "Trader\Constraint_Interpreter.cpp" "Trader\Interpreter.cpp" "Trader\Offer_Database.cpp" "Trader\Trading_Loader.cpp" "Trader\Interpreter_Utils.cpp" "Trader\Trader_Interfaces.cpp" "Trader\Constraint_Visitors.cpp" "Trader\Trader_Constraint_Visitors.cpp" "Trader\Constraint_Nodes.cpp"
!ENDIF

REALCLEAN : CLEAN
	-@del /f/q "$(OUTDIR)\TAO_CosTrading_Servs.lib"
	-@del /f/q "$(OUTDIR)\TAO_CosTrading_Servs.exp"
	-@del /f/q "$(OUTDIR)\TAO_CosTrading_Servs.ilk"

"$(INTDIR)" :
	if not exist "Static_Release\$(NULL)" mkdir "Static_Release"
	if not exist "Static_Release\CosTrading_Serv\$(NULL)" mkdir "Static_Release\CosTrading_Serv"
	if not exist "$(INTDIR)\$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
CPP_COMMON=/Zc:wchar_t /nologo /Wp64 /O2 /W3 /EHsc /MD /GR /wd4355 /wd4250 /wd4290 /I "..\..\.." /I "..\.." /I "..\..\orbsvcs" /D NDEBUG /D WIN64 /D WIN32 /D _WINDOWS /D _CRT_SECURE_NO_WARNINGS /D _CRT_SECURE_NO_DEPRECATE /D _CRT_NONSTDC_NO_DEPRECATE /D ACE_AS_STATIC_LIBS /D TAO_AS_STATIC_LIBS /D MPC_LIB_MODIFIER=\"s\" /FD /c

CPP_PROJ=$(CPP_COMMON) /Fo"$(INTDIR)\\"


LINK32=link.exe -lib
LINK32_FLAGS=/nologo /machine:IA64 /out:"..\..\..\lib\TAO_CosTrading_Servs.lib"
LINK32_OBJS= \
	"$(INTDIR)\Trader\Offer_Iterators.obj" \
	"$(INTDIR)\Trader\Trader_Utils.obj" \
	"$(INTDIR)\Trader\Constraint_y.obj" \
	"$(INTDIR)\Trader\Trader.obj" \
	"$(INTDIR)\Trader\Service_Type_Repository.obj" \
	"$(INTDIR)\Trader\Constraint_l.obj" \
	"$(INTDIR)\Trader\Constraint_Interpreter.obj" \
	"$(INTDIR)\Trader\Interpreter.obj" \
	"$(INTDIR)\Trader\Offer_Database.obj" \
	"$(INTDIR)\Trader\Trading_Loader.obj" \
	"$(INTDIR)\Trader\Interpreter_Utils.obj" \
	"$(INTDIR)\Trader\Trader_Interfaces.obj" \
	"$(INTDIR)\Trader\Constraint_Visitors.obj" \
	"$(INTDIR)\Trader\Trader_Constraint_Visitors.obj" \
	"$(INTDIR)\Trader\Constraint_Nodes.obj"

"$(OUTDIR)\TAO_CosTrading_Servs.lib" : $(DEF_FILE) $(LINK32_OBJS)
	$(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<
	if exist "$(OUTDIR)\TAO_CosTrading_Servs.lib.manifest" mt.exe -manifest "$(OUTDIR)\TAO_CosTrading_Servs.lib.manifest" -outputresource:$@;2

!ENDIF

CLEAN :
	-@del /f/s/q "$(INTDIR)"

"$(OUTDIR)" :
	if not exist "$(OUTDIR)\$(NULL)" mkdir "$(OUTDIR)"

.c{$(INTDIR)}.obj::
	$(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.obj::
	$(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.obj::
	$(CPP) @<<
   $(CPP_PROJ) $<
<<

.c{$(INTDIR)}.sbr::
	$(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.sbr::
	$(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.sbr::
	$(CPP) @<<
   $(CPP_PROJ) $<
<<

!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("Makefile.CosTrading_Serv.dep")
!INCLUDE "Makefile.CosTrading_Serv.dep"
!ENDIF
!ENDIF

!IF "$(CFG)" == "Win64 Debug" || "$(CFG)" == "Win64 Release" || "$(CFG)" == "Win64 Static Debug" || "$(CFG)" == "Win64 Static Release" 
SOURCE="Trader\Offer_Iterators.cpp"

"$(INTDIR)\Trader\Offer_Iterators.obj" : $(SOURCE)
	@if not exist "$(INTDIR)\Trader\$(NULL)" mkdir "$(INTDIR)\Trader\"
	$(CPP) $(CPP_COMMON) /Fo"$(INTDIR)\Trader\Offer_Iterators.obj" $(SOURCE)

SOURCE="Trader\Trader_Utils.cpp"

"$(INTDIR)\Trader\Trader_Utils.obj" : $(SOURCE)
	@if not exist "$(INTDIR)\Trader\$(NULL)" mkdir "$(INTDIR)\Trader\"
	$(CPP) $(CPP_COMMON) /Fo"$(INTDIR)\Trader\Trader_Utils.obj" $(SOURCE)

SOURCE="Trader\Constraint_y.cpp"

"$(INTDIR)\Trader\Constraint_y.obj" : $(SOURCE)
	@if not exist "$(INTDIR)\Trader\$(NULL)" mkdir "$(INTDIR)\Trader\"
	$(CPP) $(CPP_COMMON) /Fo"$(INTDIR)\Trader\Constraint_y.obj" $(SOURCE)

SOURCE="Trader\Trader.cpp"

"$(INTDIR)\Trader\Trader.obj" : $(SOURCE)
	@if not exist "$(INTDIR)\Trader\$(NULL)" mkdir "$(INTDIR)\Trader\"
	$(CPP) $(CPP_COMMON) /Fo"$(INTDIR)\Trader\Trader.obj" $(SOURCE)

SOURCE="Trader\Service_Type_Repository.cpp"

"$(INTDIR)\Trader\Service_Type_Repository.obj" : $(SOURCE)
	@if not exist "$(INTDIR)\Trader\$(NULL)" mkdir "$(INTDIR)\Trader\"
	$(CPP) $(CPP_COMMON) /Fo"$(INTDIR)\Trader\Service_Type_Repository.obj" $(SOURCE)

SOURCE="Trader\Constraint_l.cpp"

"$(INTDIR)\Trader\Constraint_l.obj" : $(SOURCE)
	@if not exist "$(INTDIR)\Trader\$(NULL)" mkdir "$(INTDIR)\Trader\"
	$(CPP) $(CPP_COMMON) /Fo"$(INTDIR)\Trader\Constraint_l.obj" $(SOURCE)

SOURCE="Trader\Constraint_Interpreter.cpp"

"$(INTDIR)\Trader\Constraint_Interpreter.obj" : $(SOURCE)
	@if not exist "$(INTDIR)\Trader\$(NULL)" mkdir "$(INTDIR)\Trader\"
	$(CPP) $(CPP_COMMON) /Fo"$(INTDIR)\Trader\Constraint_Interpreter.obj" $(SOURCE)

SOURCE="Trader\Interpreter.cpp"

"$(INTDIR)\Trader\Interpreter.obj" : $(SOURCE)
	@if not exist "$(INTDIR)\Trader\$(NULL)" mkdir "$(INTDIR)\Trader\"
	$(CPP) $(CPP_COMMON) /Fo"$(INTDIR)\Trader\Interpreter.obj" $(SOURCE)

SOURCE="Trader\Offer_Database.cpp"

"$(INTDIR)\Trader\Offer_Database.obj" : $(SOURCE)
	@if not exist "$(INTDIR)\Trader\$(NULL)" mkdir "$(INTDIR)\Trader\"
	$(CPP) $(CPP_COMMON) /Fo"$(INTDIR)\Trader\Offer_Database.obj" $(SOURCE)

SOURCE="Trader\Trading_Loader.cpp"

"$(INTDIR)\Trader\Trading_Loader.obj" : $(SOURCE)
	@if not exist "$(INTDIR)\Trader\$(NULL)" mkdir "$(INTDIR)\Trader\"
	$(CPP) $(CPP_COMMON) /Fo"$(INTDIR)\Trader\Trading_Loader.obj" $(SOURCE)

SOURCE="Trader\Interpreter_Utils.cpp"

"$(INTDIR)\Trader\Interpreter_Utils.obj" : $(SOURCE)
	@if not exist "$(INTDIR)\Trader\$(NULL)" mkdir "$(INTDIR)\Trader\"
	$(CPP) $(CPP_COMMON) /Fo"$(INTDIR)\Trader\Interpreter_Utils.obj" $(SOURCE)

SOURCE="Trader\Trader_Interfaces.cpp"

"$(INTDIR)\Trader\Trader_Interfaces.obj" : $(SOURCE)
	@if not exist "$(INTDIR)\Trader\$(NULL)" mkdir "$(INTDIR)\Trader\"
	$(CPP) $(CPP_COMMON) /Fo"$(INTDIR)\Trader\Trader_Interfaces.obj" $(SOURCE)

SOURCE="Trader\Constraint_Visitors.cpp"

"$(INTDIR)\Trader\Constraint_Visitors.obj" : $(SOURCE)
	@if not exist "$(INTDIR)\Trader\$(NULL)" mkdir "$(INTDIR)\Trader\"
	$(CPP) $(CPP_COMMON) /Fo"$(INTDIR)\Trader\Constraint_Visitors.obj" $(SOURCE)

SOURCE="Trader\Trader_Constraint_Visitors.cpp"

"$(INTDIR)\Trader\Trader_Constraint_Visitors.obj" : $(SOURCE)
	@if not exist "$(INTDIR)\Trader\$(NULL)" mkdir "$(INTDIR)\Trader\"
	$(CPP) $(CPP_COMMON) /Fo"$(INTDIR)\Trader\Trader_Constraint_Visitors.obj" $(SOURCE)

SOURCE="Trader\Constraint_Nodes.cpp"

"$(INTDIR)\Trader\Constraint_Nodes.obj" : $(SOURCE)
	@if not exist "$(INTDIR)\Trader\$(NULL)" mkdir "$(INTDIR)\Trader\"
	$(CPP) $(CPP_COMMON) /Fo"$(INTDIR)\Trader\Constraint_Nodes.obj" $(SOURCE)

!IF  "$(CFG)" == "Win64 Debug"
!ELSEIF  "$(CFG)" == "Win64 Release"
!ELSEIF  "$(CFG)" == "Win64 Static Debug"
!ELSEIF  "$(CFG)" == "Win64 Static Release"
!ENDIF

SOURCE="CosTrading_Serv.rc"

"$(INTDIR)\CosTrading_Serv.res" : $(SOURCE)
	$(RSC) /l 0x409 /fo"$(INTDIR)\CosTrading_Serv.res" /d NDEBUG /d WIN64 /d _CRT_SECURE_NO_WARNINGS /d _CRT_SECURE_NO_DEPRECATE /d _CRT_NONSTDC_NO_DEPRECATE /i "..\..\.." /i "..\.." /i "..\..\orbsvcs" $(SOURCE)



!ENDIF

GENERATED : "$(INTDIR)" "$(OUTDIR)" $(GENERATED_DIRTY)
	-@rem

DEPENDCHECK :
!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("Makefile.CosTrading_Serv.dep")
	@echo Using "Makefile.CosTrading_Serv.dep"
!ELSE
	@echo Warning: cannot find "Makefile.CosTrading_Serv.dep"
!ENDIF
!ENDIF

