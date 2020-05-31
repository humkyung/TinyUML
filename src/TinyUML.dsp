# Microsoft Developer Studio Project File - Name="TinyUML" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=TinyUML - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TinyUML.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TinyUML.mak" CFG="TinyUML - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TinyUML - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "TinyUML - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "TinyUML"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "TinyUML - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O1 /I "C:\Program Files\Business Components Gallery\BCGControlBar" /I "..\Is" /I "d:\project\TinyLib" /I "../IsGUI" /I "../IsDrawCtrl" /I "../IsDrawCtrl\IsDraw" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 IsGUI.lib ClassParser.lib IsDrawCtrl.lib IsDraw.lib IsDraw.lib shlwapi.lib /nologo /subsystem:windows /machine:I386 /out:"../Bin/TinyUML.exe" /libpath:"../Bin"
# SUBTRACT LINK32 /debug

!ELSEIF  "$(CFG)" == "TinyUML - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../bin"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "C:\Program Files\Business Components Gallery\BCGControlBar" /I "..\Is" /I "d:\project\TinyLib" /I "../IsGUI" /I "../IsDrawCtrl" /I "../IsDrawCtrl\IsDraw" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 ../Bin/IsGUId.lib ../bin/ClassParser.lib ../bin/IsDrawCtrl.lib IsDraw.lib shlwapi.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept /libpath:"..\bin"

!ENDIF 

# Begin Target

# Name "TinyUML - Win32 Release"
# Name "TinyUML - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ChildFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\ClassThemePropertyPage.cpp
# End Source File
# Begin Source File

SOURCE=.\ClassTreeCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\ComboColorPicker.cpp
# End Source File
# Begin Source File

SOURCE=.\ComboLineStyle.cpp
# End Source File
# Begin Source File

SOURCE=.\ComboLineWeight.cpp
# End Source File
# Begin Source File

SOURCE=.\ContentFile.cpp
# End Source File
# Begin Source File

SOURCE=.\DrawingStyleToolBar.cpp
# End Source File
# Begin Source File

SOURCE=.\FileViewTreeCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\GeneralThemePropertyPage.cpp
# End Source File
# Begin Source File

SOURCE=.\GUID.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\NoteThemePropertyPage.cpp
# End Source File
# Begin Source File

SOURCE=.\NoToolDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PackageThemePropertyPage.cpp
# End Source File
# Begin Source File

SOURCE=.\RelationThemePropertyPage.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\ThemePropSheet.cpp
# End Source File
# Begin Source File

SOURCE=..\TinyLib\TinyDrawCtrl\TinyDrawCtrl.rc
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\TinyUML.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUML.rc
# End Source File
# Begin Source File

SOURCE=.\TinyUMLAssociation.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLAssociationController.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLAssociationDraw.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLAssociationFactory.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLAssociationPropertyPage.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLAttributesPropertyPage.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLClass.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLClassController.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLClassDraw.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLClassFactory.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLClassPropertyPage.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLClipboardManager.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLDefaultTheme.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLDependency.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLDependencyController.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLDependencyDraw.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLDependencyPropertyPage.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLEditor.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLEntity.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLEntityContainer.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLGeneralization.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLGeneralizationController.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLGeneralizationDraw.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLGeneralizationPropertyPage.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLLabel.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLLabelController.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLLabelDraw.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLLabelFactory.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLLabelPropertyPage.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLMethodsPropertyPage.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLNote.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLNoteController.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLNoteDraw.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLNotePropertyPage.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLPackage.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLPackageController.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLPackageDraw.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLPackagePropertyPage.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLRelation.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLRelationDraw.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLTheme.cpp
# End Source File
# Begin Source File

SOURCE=.\TinyUMLView.cpp
# End Source File
# Begin Source File

SOURCE=.\ToolShell.cpp
# End Source File
# Begin Source File

SOURCE=.\TyUMLDocReactor.cpp
# End Source File
# Begin Source File

SOURCE=.\WorkspaceBar.cpp
# End Source File
# Begin Source File

SOURCE=.\WriteSourceFiles.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ChildFrm.h
# End Source File
# Begin Source File

SOURCE=.\ClassThemePropertyPage.h
# End Source File
# Begin Source File

SOURCE=.\ClassTreeCtrl.h
# End Source File
# Begin Source File

SOURCE=..\TinyLib\TinyDrawCtrl\ClipboardManager.h
# End Source File
# Begin Source File

SOURCE=.\ComboColorPicker.h
# End Source File
# Begin Source File

SOURCE=.\ComboLineStyle.h
# End Source File
# Begin Source File

SOURCE=.\ComboLineWeight.h
# End Source File
# Begin Source File

SOURCE=.\ContentFile.h
# End Source File
# Begin Source File

SOURCE=..\spoon_0_0_1\editorctrl\CTinyEditorLine.h
# End Source File
# Begin Source File

SOURCE=..\TinyLib\TinyDrawCtrl\DrawingEditorCreateCmd.h
# End Source File
# Begin Source File

SOURCE=..\TinyLib\TinyDrawCtrl\DrawingEditorProperty.h
# End Source File
# Begin Source File

SOURCE=..\TinyLib\TinyDrawCtrl\DrawingEntityGroupTable.h
# End Source File
# Begin Source File

SOURCE=.\DrawingStyleToolBar.h
# End Source File
# Begin Source File

SOURCE=.\FileViewTreeCtrl.h
# End Source File
# Begin Source File

SOURCE=.\GeneralThemePropertyPage.h
# End Source File
# Begin Source File

SOURCE=.\GUID.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\NoteThemePropertyPage.h
# End Source File
# Begin Source File

SOURCE=.\NoToolDlg.h
# End Source File
# Begin Source File

SOURCE=..\spoon_0_0_1\guictrl\orderer.h
# End Source File
# Begin Source File

SOURCE=.\PackageThemePropertyPage.h
# End Source File
# Begin Source File

SOURCE=.\RelationThemePropertyPage.h
# End Source File
# Begin Source File

SOURCE=.\ReportCtrl.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\ThemePropSheet.h
# End Source File
# Begin Source File

SOURCE=..\..\TinyLib\TinyDrawCtrl\TinyControllerObject.h
# End Source File
# Begin Source File

SOURCE=..\..\TinyLib\TinyDrawCtrl\TinyDocIterator.h
# End Source File
# Begin Source File

SOURCE=..\..\TinyLib\TinyDrawCtrl\TinyDrawEditor.h
# End Source File
# Begin Source File

SOURCE=..\..\TinyLib\TinyDrawCtrl\TinyDrawEntitySet.h
# End Source File
# Begin Source File

SOURCE=..\..\TinyLib\TinyDrawCtrl\TinyDrawEntJig.h
# End Source File
# Begin Source File

SOURCE=..\..\TinyLib\TinyDrawCtrl\TinyDrawMessage.h
# End Source File
# Begin Source File

SOURCE=.\TinyFlatComboBox.h
# End Source File
# Begin Source File

SOURCE=..\..\TinyLib\TinyDrawCtrl\TinyIterator.h
# End Source File
# Begin Source File

SOURCE=..\..\TinyLib\TinyDrawCtrl\TinyObject.h
# End Source File
# Begin Source File

SOURCE=..\..\TinyLib\TinyDrawCtrl\TinyObjectId.h
# End Source File
# Begin Source File

SOURCE=.\TinyUML.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLAssociation.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLAssociationController.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLAssociationDraw.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLAssociationFactory.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLAssociationPropertyPage.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLAttributesPropertyPage.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLClass.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLClassController.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLClassDraw.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLClassFactory.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLClassPropertyPage.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLClipboardManager.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLDefaultTheme.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLDependency.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLDependencyController.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLDependencyDraw.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLDependencyPropertyPage.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLDoc.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLEditor.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLEntity.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLEntityContainer.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLGeneralization.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLGeneralizationController.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLGeneralizationDraw.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLGeneralizationPropertyPage.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLLabel.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLLabelController.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLLabelDraw.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLLabelFactory.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLLabelPropertyPage.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLMethodsPropertyPage.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLNote.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLNoteController.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLNoteDraw.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLNotePropertyPage.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLPackage.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLPackageController.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLPackageDraw.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLPackagePropertyPage.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLRelation.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLRelationDraw.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLTheme.h
# End Source File
# Begin Source File

SOURCE=.\TinyUMLView.h
# End Source File
# Begin Source File

SOURCE=.\ToolShell.h
# End Source File
# Begin Source File

SOURCE=..\..\TinyLib\TinyDrawCtrl\TyDrawContainerReactor.h
# End Source File
# Begin Source File

SOURCE=..\..\TinyLib\TinyDrawCtrl\TyDrawLabel.h
# End Source File
# Begin Source File

SOURCE=..\..\TinyLib\TinyDrawCtrl\TyDrawLabelController.h
# End Source File
# Begin Source File

SOURCE=..\..\TinyLib\TinyDrawCtrl\TyDrawLabelFactory.h
# End Source File
# Begin Source File

SOURCE=.\TyUMLDocReactor.h
# End Source File
# Begin Source File

SOURCE=.\WorkspaceBar.h
# End Source File
# Begin Source File

SOURCE=.\WriteSourceFiles.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\add.ico
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00001.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00002.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00003.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00004.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00005.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00006.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00007.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00008.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00009.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00010.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Cursor_6.cur
# End Source File
# Begin Source File

SOURCE=.\res\delete.ico
# End Source File
# Begin Source File

SOURCE=..\TinyLib\TinyDrawCtrl\res\hand.cur
# End Source File
# Begin Source File

SOURCE=.\res\ico00001.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00002.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00003.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00006.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00007.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\Icon_2.ico
# End Source File
# Begin Source File

SOURCE=.\res\Icon_7.ico
# End Source File
# Begin Source File

SOURCE=.\res\mouse.cur
# End Source File
# Begin Source File

SOURCE=.\res\objectba.bmp
# End Source File
# Begin Source File

SOURCE=.\res\style_to.bmp
# End Source File
# Begin Source File

SOURCE=.\res\TinyUML.ico
# End Source File
# Begin Source File

SOURCE=.\res\TinyUML.rc2
# End Source File
# Begin Source File

SOURCE=.\res\TinyUMLDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolsbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ttf_glyph.bmp
# End Source File
# Begin Source File

SOURCE=.\TyDraw.rct
# End Source File
# Begin Source File

SOURCE=.\res\viewbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\workspace.bmp
# PROP Exclude_From_Scan -1
# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
