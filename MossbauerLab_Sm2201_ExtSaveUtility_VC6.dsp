# Microsoft Developer Studio Project File - Name="MossbauerLab_Sm2201_ExtSaveUtility_VC6" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=MossbauerLab_Sm2201_ExtSaveUtility_VC6 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MossbauerLab_Sm2201_ExtSaveUtility_VC6.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MossbauerLab_Sm2201_ExtSaveUtility_VC6.mak" CFG="MossbauerLab_Sm2201_ExtSaveUtility_VC6 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MossbauerLab_Sm2201_ExtSaveUtility_VC6 - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "MossbauerLab_Sm2201_ExtSaveUtility_VC6 - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MossbauerLab_Sm2201_ExtSaveUtility_VC6 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x419 /d "NDEBUG"
# ADD RSC /l 0x419 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "MossbauerLab_Sm2201_ExtSaveUtility_VC6 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x419 /d "_DEBUG"
# ADD RSC /l 0x419 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "MossbauerLab_Sm2201_ExtSaveUtility_VC6 - Win32 Release"
# Name "MossbauerLab_Sm2201_ExtSaveUtility_VC6 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\MossbauerLab.Sm2201.ExtSaveUtility\src\saveManager\applicationTextUserInterface.cpp
# End Source File
# Begin Source File

SOURCE=.\MossbauerLab.Sm2201.ExtSaveUtility\src\saveManager\autoSaveManager.cpp

!IF  "$(CFG)" == "MossbauerLab_Sm2201_ExtSaveUtility_VC6 - Win32 Release"

!ELSEIF  "$(CFG)" == "MossbauerLab_Sm2201_ExtSaveUtility_VC6 - Win32 Debug"

# ADD CPP /D _WIN32_WINNT=0x0401 _WINNT_VERSION=0x0401
# SUBTRACT CPP /D "_MBCS"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\MossbauerLab.Sm2201.ExtSaveUtility\src\utils\windows\fileInfo.cpp

!IF  "$(CFG)" == "MossbauerLab_Sm2201_ExtSaveUtility_VC6 - Win32 Release"

!ELSEIF  "$(CFG)" == "MossbauerLab_Sm2201_ExtSaveUtility_VC6 - Win32 Debug"

# ADD CPP /D _WIN32_WINNT=0x0401 _WINNT_VERSION=0x0401
# SUBTRACT CPP /D "_MBCS"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\MossbauerLab.Sm2201.ExtSaveUtility\src\main.cpp

!IF  "$(CFG)" == "MossbauerLab_Sm2201_ExtSaveUtility_VC6 - Win32 Release"

!ELSEIF  "$(CFG)" == "MossbauerLab_Sm2201_ExtSaveUtility_VC6 - Win32 Debug"

# ADD CPP /D _WIN32_WINNT=0x0401 _WINNT_VERSION=0x0401
# SUBTRACT CPP /D "_MBCS"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\MossbauerLab.Sm2201.ExtSaveUtility\src\utils\config\propertyReader.cpp

!IF  "$(CFG)" == "MossbauerLab_Sm2201_ExtSaveUtility_VC6 - Win32 Release"

!ELSEIF  "$(CFG)" == "MossbauerLab_Sm2201_ExtSaveUtility_VC6 - Win32 Debug"

# ADD CPP /D _WIN32_WINNT=0x0401 _WINNT_VERSION=0x0401
# SUBTRACT CPP /D "_MBCS"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\MossbauerLab.Sm2201.ExtSaveUtility\src\configs\schedulerConfig.cpp

!IF  "$(CFG)" == "MossbauerLab_Sm2201_ExtSaveUtility_VC6 - Win32 Release"

!ELSEIF  "$(CFG)" == "MossbauerLab_Sm2201_ExtSaveUtility_VC6 - Win32 Debug"

# ADD CPP /D _WIN32_WINNT=0x0401 _WINNT_VERSION=0x0401
# SUBTRACT CPP /D "_MBCS"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\MossbauerLab.Sm2201.ExtSaveUtility\src\utils\strings\strBaseUtils.cpp

!IF  "$(CFG)" == "MossbauerLab_Sm2201_ExtSaveUtility_VC6 - Win32 Release"

!ELSEIF  "$(CFG)" == "MossbauerLab_Sm2201_ExtSaveUtility_VC6 - Win32 Debug"

# ADD CPP /D _WIN32_WINNT=0x0401 _WINNT_VERSION=0x0401
# SUBTRACT CPP /D "_MBCS"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\MossbauerLab.Sm2201.ExtSaveUtility\src\utils\windows\vxdAccessor.cpp
# End Source File
# Begin Source File

SOURCE=.\MossbauerLab.Sm2201.ExtSaveUtility\src\utils\windows\windowsInfo.cpp

!IF  "$(CFG)" == "MossbauerLab_Sm2201_ExtSaveUtility_VC6 - Win32 Release"

!ELSEIF  "$(CFG)" == "MossbauerLab_Sm2201_ExtSaveUtility_VC6 - Win32 Debug"

# ADD CPP /D _WIN32_WINNT=0x0401 _WINNT_VERSION=0x0401
# SUBTRACT CPP /D "_MBCS"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\MossbauerLab.Sm2201.ExtSaveUtility\src\saveManager\applicationTextUserInterface.h
# End Source File
# Begin Source File

SOURCE=.\MossbauerLab.Sm2201.ExtSaveUtility\src\saveManager\autoSaveManager.h
# End Source File
# Begin Source File

SOURCE=.\MossbauerLab.Sm2201.ExtSaveUtility\src\utils\windows\fileInfo.h
# End Source File
# Begin Source File

SOURCE=.\MossbauerLab.Sm2201.ExtSaveUtility\src\utils\config\propertyReader.h
# End Source File
# Begin Source File

SOURCE=.\MossbauerLab.Sm2201.ExtSaveUtility\src\configs\schedulerConfig.h
# End Source File
# Begin Source File

SOURCE=.\MossbauerLab.Sm2201.ExtSaveUtility\src\utils\strings\strBaseUtils.h
# End Source File
# Begin Source File

SOURCE=.\MossbauerLab.Sm2201.ExtSaveUtility\src\utils\windows\vxdAccessor.h
# End Source File
# Begin Source File

SOURCE=.\MossbauerLab.Sm2201.ExtSaveUtility\src\utils\windows\windowsInfo.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
