SET(CMAKE_SYSTEM_NAME  VxWorks)             
SET(CMAKE_SYSTEM_VERSION  7   )              
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY) 
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY) 
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
SET(CMAKE_C_COMPILER     C:/git/vx7-ux-ports/compilers/gnu-4.8.1.5/x86-win32/bin/ccpentium.exe )        
SET(CMAKE_CXX_COMPILER   C:/git/vx7-ux-ports/compilers/gnu-4.8.1.5/x86-win32/bin/c++pentium.exe )       
SET(CMAKE_C_FLAGS        -m64 -mcmodel=large -mno-red-zone -fno-implicit-fp -fno-builtin -fno-omit-frame-pointer -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -std=c99 -fasm -O2 -fno-defer-pop -Wall -IC:/git/vx7-ux-ports/vxworks-7/pkgs/os/utils/unix/friend_h/ -D_WRS_CONFIG_VSB_USR_H=C:/git/vx7-ux-ports/workbench-4/workspace/VSB64/usr/h -D_VX_CPU=_VX_SIMNT -D_VX_TOOL_FAMILY=gnu -D_VX_TOOL=gnu -D_WRS_CONFIG_DEPENDS_LAYER_CMAKE -D_WRS_CONFIG_DEPENDS_LAYER_UNIX -D_nq_VSB_CONFIG_FILE=C:/git/vx7-ux-ports/workbench-4/workspace/VSB64/h/config/vsbConfig.h -save-temps -IC:/git/vx7-ux-ports/workbench-4/workspace/VSB64/share/h -isystemC:/git/vx7-ux-ports/workbench-4/workspace/VSB64/usr/h -isystemC:/git/vx7-ux-ports/workbench-4/workspace/VSB64/usr/h/system -isystemC:/git/vx7-ux-ports/workbench-4/workspace/VSB64/usr/h/public -I. -includeC:/git/vx7-ux-ports/workbench-4/workspace/VSB64/usr/src/EIGEN/eigen-eigen-b30b87236a1b/autoconf_vsbConfig_quote.h )    
SET(CMAKE_CXX_FLAGS      -m64 -mcmodel=large -mno-red-zone -fno-implicit-fp -fno-builtin -fno-omit-frame-pointer -ansi -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -std=c++11 -isystemC:/git/vx7-ux-ports/workbench-4/workspace/VSB64/usr/h/public/c++11 -O2 -fno-defer-pop -Wall -IC:/git/vx7-ux-ports/vxworks-7/pkgs/os/utils/unix/friend_h/ -D_WRS_CONFIG_VSB_USR_H=C:/git/vx7-ux-ports/workbench-4/workspace/VSB64/usr/h -D_VX_CPU=_VX_SIMNT -D_VX_TOOL_FAMILY=gnu -D_VX_TOOL=gnu -D_WRS_CONFIG_DEPENDS_LAYER_CMAKE -D_WRS_CONFIG_DEPENDS_LAYER_UNIX -D_nq_VSB_CONFIG_FILE=C:/git/vx7-ux-ports/workbench-4/workspace/VSB64/h/config/vsbConfig.h -save-temps -IC:/git/vx7-ux-ports/workbench-4/workspace/VSB64/share/h -isystemC:/git/vx7-ux-ports/workbench-4/workspace/VSB64/usr/h -isystemC:/git/vx7-ux-ports/workbench-4/workspace/VSB64/usr/h/system -isystemC:/git/vx7-ux-ports/workbench-4/workspace/VSB64/usr/h/public -includeC:/git/vx7-ux-ports/workbench-4/workspace/VSB64/usr/src/EIGEN/eigen-eigen-b30b87236a1b/autoconf_vsbConfig_quote.h )  
SET(CMAKE_C_LINK_FLAGS   -Wl,--defsym,__wrs_rtp_base=0x200000000 -mrtp -Wl,--defsym,_GLOBAL_OFFSET_TABLE_=0 -Wl,-T,C:/git/vx7-ux-ports/vxworks-7/build/tool/gnu_4_8_1/usr/ldscript.exe.lp64.SIMCOMMON -LC:/git/vx7-ux-ports/workbench-4/workspace/VSB64/usr/lib/common/ )  
SET(CMAKE_FIND_ROOT_PATH C:/git/vx7-ux-ports/workbench-4/workspace/VSB64/usr/root )      
SET(LIBS                 -lunix  -lsupc++  -lstdc++11 )           
set(CMAKE_SYSTEM_INCLUDE_PATH C:/git/vx7-ux-ports/workbench-4/workspace/VSB64/usr/h/public C:/git/vx7-ux-ports/workbench-4/workspace/VSB64/usr/h ) 
set(CMAKE_SYSTEM_LIBRARY_PATH C:/git/vx7-ux-ports/workbench-4/workspace/VSB64/usr/libcommon )              
set(CMAKE_SYSTEM_PROGRAM_PATH C:/git/vx7-ux-ports/workbench-4/workspace/VSB64/usr/root/gnu/bin ) 