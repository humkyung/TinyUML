; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTinyUMLView
LastTemplate=CPropertyPage
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TinyUML.h"
LastPage=0

ClassCount=38
Class1=CTinyUMLApp
Class2=CTinyUMLDoc
Class3=CTinyUMLView
Class4=CMainFrame
Class7=CWorkspaceBar

ResourceCount=50
Resource1=IDD_EDIT_METHOD_CODE (Korean)
Resource2=IDR_POPUP_TOOLBAR (English (U.S.))
Resource3=IDD_PROP_PACKAGE_THEME (Korean)
Resource8=IDR_POPUP_TOOLBAR
Class5=CChildFrame
Class6=CAboutDlg
Class8=CClassEditorBar
Resource4=IDD_PROP_PACKAGE (Romanian)
Resource5=IDD_PROP_PACKAGE_THEME
Resource6=IDD_PROP_GENERALIZATION (Romanian)
Resource7=IDR_DRAW_TOOLBAR (Korean)
Resource9=IDD_PROP_NOTE_THEME
Class9=CTinyZoomWnd
Resource10=IDR_MAINFRAME
Class10=CTinyUMLClassPropertyPage
Resource11=IDR_DRAW_TOOLBAR
Resource12=IDD_PROP_ASSOCIATION (Romanian)
Class11=CTinyUMLAttributesPropertyPage
Class12=CTinyUMLMethodsPropertyPage
Resource13=IDD_PROP_NOTE_THEME (Korean)
Resource14=IDD_PROP_METHODS (Romanian)
Resource15=IDD_ABOUTBOX (English (U.S.))
Resource16=IDR_CONTEXT_MENU
Resource17=IDR_CLASS_EDITOR
Class13=CTinyUMLAssociationPropertyPage
Class14=CTinyUMLDependencyPropertyPage
Class15=CTinyUMLNotePropertyPage
Class16=CTinyUMLGeneralizationPropertyPage
Class17=CTinyUMLPackagePropertyPage
Resource18=IDD_PROP_CLASS_THEME (Korean)
Class18=CTinyFlatComboBox
Class19=CClassTreeCtrl
Class20=CClassEdit
Class21=CClassEditorDoc
Class22=CClassEditorFrame
Class23=CClassEditorView
Resource19=IDD_CLASS_EDITOR
Class24=CTinyEditorWnd
Resource20=IDD_CLASS_EDITOR (Korean)
Class25=CClassEditor
Class26=CClassEditorWiew
Class27=CTinyClassEditorDoc
Class28=CTinyClassEditorFrame
Class29=CTinyClassEditorView
Resource21=IDR_CLASS_EDITOR (Korean)
Class30=CClassThemePropertyPage
Resource22=IDD_PROP_RELATION_THEME (Korean)
Class31=CNoteThemePropertyPage
Resource23=IDD_PROP_CLASS_THEME
Resource24=IDD_PROP_CLASS (Romanian)
Class32=CRelationThemePropertyPage
Resource25=IDD_NO_TOOL
Class33=CGeneralThemePropertyPage
Resource26=IDR_DRAW_TOOLSBAR
Resource27=IDD_PROP_ATTRIBUTES (Romanian)
Resource28=IDR_TINYUMTYPE (English (U.S.))
Class34=CToolShell
Class35=CNoToolDlg
Class36=CEditMethodCodeDlg
Resource29=IDD_EDIT_METHOD_CODE
Resource30=IDR_FILEVIEW_CONTEXT_MENU (English (U.S.))
Class37=CWriteSourceFiles
Resource31=IDD_PROP_NOTE (Romanian)
Resource32=IDR_STYLE_TOOLBAR
Resource33=IDD_WRITE_SOURCES
Resource34=IDR_VIEWBAR (Korean)
Resource35=IDD_PROP_DEPENDENCY (Romanian)
Resource36=IDD_PROP_GENERAL_THEME
Resource37=IDR_CONTEXT_MENU (English (U.S.))
Resource38=IDD_NO_TOOL (Korean)
Resource39=IDR_UML_TOOLBAR (Korean)
Resource40=IDR_MAINFRAME (Korean)
Resource41=IDD_ABOUTBOX
Resource42=IDD_PROP_GENERAL_THEME (Korean)
Resource43=IDD_PROP_LABEL (English (U.S.))
Resource44=IDR_VIEWBAR
Resource45=IDR_TINYUMTYPE
Resource46=IDD_WRITE_SOURCES (Korean)
Resource47=IDR_OBJECTBAR (Romanian)
Resource48=IDR_UML_TOOLBAR
Class38=CTinyUMLLabelPropertyPage
Resource49=IDD_PROP_RELATION_THEME
Resource50=IDR_MAINFRAME (English (U.S.))

[CLS:CTinyUMLApp]
Type=0
HeaderFile=TinyUML.h
ImplementationFile=TinyUML.cpp
Filter=N
LastObject=CTinyUMLApp
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CTinyUMLDoc]
Type=0
HeaderFile=TinyUMLDoc.h
ImplementationFile=TinyUMLDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CTinyUMLDoc

[CLS:CTinyUMLView]
Type=0
HeaderFile=TinyUMLView.h
ImplementationFile=TinyUMLView.cpp
Filter=W
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_DRAWING_LINE_COLOR


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
BaseClass=CMDIFrameWnd
VirtualFilter=fWC


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M
BaseClass=CMDIChildWnd
VirtualFilter=mfWC
LastObject=CChildFrame


[CLS:CAboutDlg]
Type=0
HeaderFile=TinyUML.cpp
ImplementationFile=TinyUML.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=8
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_COMPANY_URL,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,button,1342177287
Control8=IDC_UMLSCULPTOR_URL,button,1342242816

[CLS:CWorkspaceBar]
Type=0
HeaderFile=WorkspaceBar.h
ImplementationFile=WorkspaceBar.cpp
Filter=W
LastObject=CWorkspaceBar

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_STATUS_BAR
Command7=ID_VIEW_TOOLSBAR
Command8=ID_APP_ABOUT
CommandCount=8

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_ARRANGE_BRING_TO_FRONT
Command8=ID_ARRANGE_SEND_TO_BACK
Command9=ID_EDIT_PROPERTIES
Command10=ID_FILE_READSOURCE
Command11=ID_FILE_SAVESOURCE
Command12=ID_EDIT_UNDO
Command13=ID_EDIT_REDO
Command14=ID_FILE_PRINT
Command15=ID_APP_ABOUT
CommandCount=15

[MNU:IDR_TINYUMTYPE]
Type=1
Class=CTinyUMLView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_PURGE
Command5=ID_FILE_SAVE
Command6=ID_FILE_SAVE_AS
Command7=ID_FILE_READSOURCE
Command8=ID_FILE_SAVESOURCE
Command9=ID_LOAD_THEME
Command10=ID_SAVE_THEME
Command11=ID_FILE_PRINT
Command12=ID_FILE_PRINT_PREVIEW
Command13=ID_FILE_PRINT_SETUP
Command14=ID_FILE_MRU_FILE1
Command15=ID_APP_EXIT
Command16=ID_EDIT_UNDO
Command17=ID_EDIT_CUT
Command18=ID_EDIT_COPY
Command19=ID_EDIT_PASTE
Command20=ID_EDIT_PROPERTIES
Command21=ID_INSERT_IMAGE
Command22=ID_ARRANGE_BRING_TO_FRONT
Command23=ID_ARRANGE_SEND_TO_BACK
Command24=ID_UML_SETTING
Command25=ID_EDIT_THEME
Command26=ID_VIEW_STATUS_BAR
Command27=ID_VIEW_TOOLSBAR
Command28=ID_WINDOW_NEW
Command29=ID_WINDOW_CASCADE
Command30=ID_WINDOW_TILE_HORZ
Command31=ID_WINDOW_ARRANGE
Command32=ID_APP_ABOUT
CommandCount=32

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_COPY
Command2=ID_FILE_NEW
Command3=ID_FILE_OPEN
Command4=ID_FILE_PRINT
Command5=ID_FILE_SAVE
Command6=ID_EDIT_PASTE
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_NEXT_PANE
Command10=ID_PREV_PANE
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_EDIT_CUT
Command14=ID_EDIT_UNDO
CommandCount=14

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_STATUS_BAR
Command7=ID_VIEW_TOOLSBAR
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_TINYUMTYPE (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_PURGE
Command5=ID_FILE_SAVE
Command6=ID_FILE_SAVE_AS
Command7=ID_FILE_READSOURCE
Command8=ID_FILE_SAVESOURCE
Command9=ID_LOAD_THEME
Command10=ID_SAVE_THEME
Command11=ID_FILE_PRINT
Command12=ID_FILE_PRINT_PREVIEW
Command13=ID_FILE_PRINT_SETUP
Command14=ID_FILE_MRU_FILE1
Command15=ID_APP_EXIT
Command16=ID_EDIT_UNDO
Command17=ID_EDIT_CUT
Command18=ID_EDIT_COPY
Command19=ID_EDIT_PASTE
Command20=ID_EDIT_PROPERTIES
Command21=ID_INSERT_IMAGE
Command22=ID_ARRANGE_BRING_TO_FRONT
Command23=ID_ARRANGE_SEND_TO_BACK
Command24=ID_UML_SETTING
Command25=ID_EDIT_THEME
Command26=ID_VIEW_STATUS_BAR
Command27=ID_VIEW_TOOLSBAR
Command28=ID_WINDOW_NEW
Command29=ID_WINDOW_CASCADE
Command30=ID_WINDOW_TILE_HORZ
Command31=ID_WINDOW_ARRANGE
Command32=ID_APP_ABOUT
CommandCount=32

[MNU:IDR_CONTEXT_MENU (English (U.S.))]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_ARRANGE_BRING_TO_FRONT
Command5=ID_ARRANGE_SEND_TO_BACK
Command6=ID_EDIT_PROPERTIES
CommandCount=6

[MNU:IDR_POPUP_TOOLBAR (English (U.S.))]
Type=1
Class=?
Command1=ID_VIEW_TOOLBAR
Command2=ID_VIEW_WORKSPACE
Command3=ID_VIEW_OUTPUT
Command4=ID_VIEW_CUSTOMIZE
CommandCount=4

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_EDIT_COPY
Command2=ID_FILE_NEW
Command3=ID_FILE_OPEN
Command4=ID_FILE_PRINT
Command5=ID_FILE_SAVE
Command6=ID_EDIT_PASTE
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_NEXT_PANE
Command10=ID_PREV_PANE
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_EDIT_CUT
Command14=ID_EDIT_UNDO
CommandCount=14

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=8
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_COMPANY_URL,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,button,1342177287
Control8=IDC_UMLSCULPTOR_URL,button,1342242816

[TB:IDR_VIEWBAR]
Type=1
Class=?
Command1=ID_SCALE_COMBO
Command2=ID_VIEWMIN
Command3=ID_VIEWNORMAL
Command4=ID_VIEWMAX
Command5=ID_VIEWGRID
Command6=ID_VIEW_LOCK
CommandCount=6

[CLS:CTinyZoomWnd]
Type=0
HeaderFile=\Project\tinylib\tinydrawctrl\tinyzoomwnd.h
ImplementationFile=\Project\tinylib\tinydrawctrl\tinyzoomwnd.cpp
BaseClass=CWnd
Filter=W
VirtualFilter=WC
LastObject=CTinyZoomWnd

[DLG:IDD_PROP_CLASS (Romanian)]
Type=1
Class=CTinyUMLClassPropertyPage
ControlCount=12
Control1=IDC_NAME,edit,1350631552
Control2=IDC_STATIC,static,1342308864
Control3=IDC_STEREOTYPE,combobox,1344339970
Control4=IDC_STATIC,static,1342308864
Control5=IDC_SHOW_STEREOTYPE,button,1342242819
Control6=IDC_ABSTRACT_CLASS,button,1342242819
Control7=IDC_SHOW_COMPARTIMENTS_NAME,button,1342242819
Control8=IDC_STATIC,button,1342308359
Control9=IDC_DLLEXPORT,button,1342242819
Control10=IDC_EDIT_NOTE,edit,1350631556
Control11=IDC_STATIC,static,1342308352
Control12=IDC_SINGLETON,button,1342242819

[CLS:CTinyUMLClassPropertyPage]
Type=0
HeaderFile=TinyUMLClassPropertyPage.h
ImplementationFile=TinyUMLClassPropertyPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CTinyUMLClassPropertyPage

[DLG:IDD_PROP_ATTRIBUTES (Romanian)]
Type=1
Class=CTinyUMLAttributesPropertyPage
ControlCount=14
Control1=IDC_ATTRIBUTE_TYPE,combobox,1344339970
Control2=IDC_ATTRIBUTE_NAME,edit,1350631552
Control3=IDC_MEMBER_ACCESS,combobox,1344339971
Control4=IDC_ADD_ATTRIBUTE,button,1342242816
Control5=IDC_REMOVE_ATTRIBUTE,button,1342242816
Control6=IDC_SHOW_ATTRIBUTES,button,1342242819
Control7=IDC_STATIC,button,1342177287
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_ATTRIBUTES,SysListView32,1350631433
Control12=IDC_SET_ATTRIBUTE,button,1342242816
Control13=IDC_STATIC,button,1342177287
Control14=IDC_CHECK_STATIC,button,1342242819

[DLG:IDD_PROP_METHODS (Romanian)]
Type=1
Class=CTinyUMLMethodsPropertyPage
ControlCount=21
Control1=IDC_METHOD_TYPE,combobox,1344339970
Control2=IDC_METHOD_NAME,edit,1350631552
Control3=IDC_METHOD_ACCESS,combobox,1344339971
Control4=IDC_ADD_METHOD,button,1342242816
Control5=IDC_REMOVE_METHOD,button,1342242816
Control6=IDC_SHOW_METHODS,button,1342242819
Control7=IDC_STATIC,button,1342177287
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,button,1342308359
Control11=IDC_VIRTUAL,button,1342242819
Control12=IDC_PURE,button,1342242819
Control13=IDC_INLINE,button,1342242819
Control14=IDC_CONSTMETHOD,button,1342242819
Control15=IDC_DLLEXPORT,button,1342242819
Control16=IDC_STATIC_METHOD,button,1342242819
Control17=IDC_IMPLEMENT,button,1342242819
Control18=IDC_STATIC,static,1342308352
Control19=IDC_SET_METHOD,button,1342242816
Control20=IDC_LIST_METHOD,SysListView32,1350631433
Control21=IDC_EDIT_METHOD,button,1342242816

[CLS:CTinyUMLAttributesPropertyPage]
Type=0
HeaderFile=TinyUMLAttributesPropertyPage.h
ImplementationFile=TinyUMLAttributesPropertyPage.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=IDC_ATTRIBUTES

[DLG:IDD_PROP_NOTE (Romanian)]
Type=1
Class=CTinyUMLNotePropertyPage
ControlCount=7
Control1=IDC_TEXT,edit,1352732868
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_BUTTON_NOTE_COLOR,button,1342242816
Control5=IDC_COMBO_NOTE_FONT,combobox,1344340226
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,button,1342177287

[DLG:IDD_PROP_PACKAGE (Romanian)]
Type=1
Class=CTinyUMLPackagePropertyPage
ControlCount=2
Control1=IDC_NAME,edit,1350631552
Control2=IDC_STATIC,static,1342308352

[DLG:IDD_PROP_GENERALIZATION (Romanian)]
Type=1
Class=CTinyUMLGeneralizationPropertyPage
ControlCount=1
Control1=IDC_REALIZE,button,1342242819

[DLG:IDD_PROP_DEPENDENCY (Romanian)]
Type=1
Class=CTinyUMLDependencyPropertyPage
ControlCount=4
Control1=IDC_SHOW_ARROW,button,1342242819
Control2=IDC_NAME,edit,1350631552
Control3=IDC_SHOW_NAME,button,1342242819
Control4=IDC_STATIC,button,1342177287

[DLG:IDD_PROP_ASSOCIATION (Romanian)]
Type=1
Class=CTinyUMLAssociationPropertyPage
ControlCount=12
Control1=IDC_STATIC,button,1342177287
Control2=IDC_SOURCE_MULTIPLICITY,combobox,1344339970
Control3=IDC_STATIC,static,1342308352
Control4=IDC_DEST_MULTIPLICITY,combobox,1344339970
Control5=IDC_STATIC,static,1342308352
Control6=IDC_SHOW_SRC_MULTIPLICITY,button,1342242819
Control7=IDC_SHOW_DEST_MULTIPLICITY,button,1342242819
Control8=IDC_AGGREGATION,button,1342242819
Control9=IDC_NAVIGABLE,button,1342242819
Control10=IDC_NAME,edit,1350631552
Control11=IDC_SHOW_NAME,button,1342242819
Control12=IDC_STATIC,button,1342177287

[CLS:CTinyUMLAssociationPropertyPage]
Type=0
HeaderFile=TinyUMLAssociationPropertyPage.h
ImplementationFile=TinyUMLAssociationPropertyPage.cpp
BaseClass=CPropertyPage
Filter=D

[CLS:CTinyUMLDependencyPropertyPage]
Type=0
HeaderFile=TinyUMLDependencyPropertyPage.h
ImplementationFile=TinyUMLDependencyPropertyPage.cpp
BaseClass=CPropertyPage
Filter=D

[CLS:CTinyUMLNotePropertyPage]
Type=0
HeaderFile=TinyUMLNotePropertyPage.h
ImplementationFile=TinyUMLNotePropertyPage.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=CTinyUMLNotePropertyPage

[CLS:CTinyUMLGeneralizationPropertyPage]
Type=0
HeaderFile=TinyUMLGeneralizationPropertyPage.h
ImplementationFile=TinyUMLGeneralizationPropertyPage.cpp
BaseClass=CPropertyPage
Filter=D

[CLS:CTinyUMLPackagePropertyPage]
Type=0
HeaderFile=TinyUMLPackagePropertyPage.h
ImplementationFile=TinyUMLPackagePropertyPage.cpp
BaseClass=CPropertyPage
Filter=D

[CLS:CTinyUMLMethodsPropertyPage]
Type=0
HeaderFile=tinyumlmethodspropertypage.h
ImplementationFile=tinyumlmethodspropertypage.cpp
BaseClass=CPropertyPage
LastObject=IDC_METHODS
Filter=D
VirtualFilter=idWC

[TB:IDR_OBJECTBAR (Romanian)]
Type=1
Class=?
Command1=ID_BUTTON32782
Command2=ID_BUTTON32783
Command3=ID_BUTTON32786
Command4=ID_BUTTON32787
CommandCount=4

[CLS:CTinyFlatComboBox]
Type=0
HeaderFile=TinyFlatComboBox.h
ImplementationFile=TinyFlatComboBox.cpp
BaseClass=CComboBox
Filter=W
VirtualFilter=cWC
LastObject=CTinyFlatComboBox

[CLS:CClassTreeCtrl]
Type=0
HeaderFile=ClassTreeCtrl.h
ImplementationFile=ClassTreeCtrl.cpp
BaseClass=CTreeCtrl
Filter=W
VirtualFilter=GWC
LastObject=CClassTreeCtrl

[CLS:CClassEdit]
Type=0
HeaderFile=ClassEdit.h
ImplementationFile=ClassEdit.cpp
BaseClass=CEdit
Filter=W
VirtualFilter=WC
LastObject=CClassEdit

[CLS:CClassEditorDoc]
Type=0
HeaderFile=ClassEditorDoc.h
ImplementationFile=ClassEditorDoc.cpp
BaseClass=CDocument
Filter=N

[CLS:CClassEditorFrame]
Type=0
HeaderFile=ClassEditorFrame.h
ImplementationFile=ClassEditorFrame.cpp
BaseClass=CMDIChildWnd
Filter=M
VirtualFilter=mfWC
LastObject=CClassEditorFrame

[CLS:CClassEditorView]
Type=0
HeaderFile=ClassEditorView.h
ImplementationFile=ClassEditorView.cpp
BaseClass=CView
Filter=C

[MNU:IDR_CLASS_EDITOR]
Type=1
Class=?
Command1=ID_CLASS_EDIT_CUT
Command2=ID_CLASS_EDIT_COPY
Command3=ID_CLASS_EDIT_PASTE
Command4=ID_CLASS_EDIT_FIND
Command5=ID_CLASS_EDIT_REPLACE
CommandCount=5

[TB:IDR_CLASS_EDITOR]
Type=1
Class=?
Command1=ID_CLASS_EDIT_CUT
Command2=ID_CLASS_EDIT_COPY
CommandCount=2

[CLS:CTinyEditorWnd]
Type=0
HeaderFile=\Project\spoon_0_0_1\editorctrl\tinyeditorwnd.h
ImplementationFile=\Project\spoon_0_0_1\editorctrl\tinyeditorwnd.cpp
BaseClass=CWnd
LastObject=CTinyEditorWnd
Filter=W
VirtualFilter=WC

[CLS:CClassEditorBar]
Type=0
HeaderFile=classeditorbar.h
ImplementationFile=classeditorbar.cpp
BaseClass=CBCGSizingControlBar
LastObject=CClassEditorBar
Filter=W
VirtualFilter=WC

[DLG:IDD_CLASS_EDITOR]
Type=1
Class=CClassEditor
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552

[CLS:CClassEditor]
Type=0
HeaderFile=ClassEditor.h
ImplementationFile=ClassEditor.cpp
BaseClass=CDialog
Filter=D
LastObject=CClassEditor
VirtualFilter=dWC

[CLS:CClassEditorWiew]
Type=0
HeaderFile=ClassEditorWiew.h
ImplementationFile=ClassEditorWiew.cpp
BaseClass=CView
Filter=C

[CLS:CTinyClassEditorDoc]
Type=0
HeaderFile=TinyClassEditorDoc.h
ImplementationFile=TinyClassEditorDoc.cpp
BaseClass=CDocument
Filter=N

[CLS:CTinyClassEditorFrame]
Type=0
HeaderFile=TinyClassEditorFrame.h
ImplementationFile=TinyClassEditorFrame.cpp
BaseClass=CMDIChildWnd
Filter=M

[CLS:CTinyClassEditorView]
Type=0
HeaderFile=TinyClassEditorView.h
ImplementationFile=TinyClassEditorView.cpp
BaseClass=CView
Filter=C

[DLG:IDD_PROP_CLASS_THEME]
Type=1
Class=CClassThemePropertyPage
ControlCount=23
Control1=IDC_BUTTON_CLASS_TITLE_COLOR,button,1342242816
Control2=IDC_BUTTON_CLASS_BACK_COLOR,button,1342242816
Control3=IDC_EDIT_ATTRIBUTE_FONT_SIZE,edit,1350639744
Control4=IDC_SPIN_ATTRIBUTE_FONT_SIZE,msctls_updown32,1342177332
Control5=IDC_COMBO_ATTRIBUTE_FONT,combobox,1344340771
Control6=IDC_EDIT_METHOD_FONT_SIZE,edit,1350639744
Control7=IDC_SPIN_METHOD_FONT_SIZE,msctls_updown32,1342177332
Control8=IDC_COMBO_METHOD_FONT,combobox,1344340771
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308354
Control12=IDC_STATIC,button,1342177287
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308354
Control15=IDC_STATIC,button,1342177287
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,button,1342177287
Control18=IDC_STATIC,static,1342308352
Control19=IDC_BUTTON_FOLDER_COLOR,button,1342242816
Control20=IDC_STATIC,static,1342308352
Control21=IDC_BUTTON_ATTRIBUTE_COLOR,button,1342242816
Control22=IDC_STATIC,static,1342308352
Control23=IDC_BUTTON_METHOD_COLOR,button,1342242816

[CLS:CClassThemePropertyPage]
Type=0
HeaderFile=ClassThemePropertyPage.h
ImplementationFile=ClassThemePropertyPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CClassThemePropertyPage
VirtualFilter=idWC

[DLG:IDD_PROP_NOTE_THEME]
Type=1
Class=CNoteThemePropertyPage
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_BUTTON_NOTE_COLOR,button,1342242816
Control4=IDC_COMBO_NOTE_FONT,combobox,1344340226
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,button,1342177287

[CLS:CNoteThemePropertyPage]
Type=0
HeaderFile=notethemepropertypage.h
ImplementationFile=notethemepropertypage.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=CNoteThemePropertyPage

[DLG:IDD_PROP_RELATION_THEME]
Type=1
Class=CRelationThemePropertyPage
ControlCount=3
Control1=65535,button,1342177287
Control2=65535,static,1342308352
Control3=IDC_BUTTON_SYMBOL_COLOR,button,1342242816

[DLG:IDD_PROP_PACKAGE_THEME]
Type=1
Class=?
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_BUTTON_FILL_COLOR,button,1342242816
Control4=IDC_COMBO_NAME_FONT,combobox,1344340226
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,button,1342177287

[CLS:CRelationThemePropertyPage]
Type=0
HeaderFile=RelationThemePropertyPage.h
ImplementationFile=RelationThemePropertyPage.cpp
BaseClass=CDialog
Filter=D
LastObject=CRelationThemePropertyPage

[DLG:IDD_PROP_GENERAL_THEME]
Type=1
Class=CGeneralThemePropertyPage
ControlCount=13
Control1=IDC_STATIC,static,1342308352
Control2=IDC_BUTTON_NAME_COLOR,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_BUTTON_LINE_COLOR,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_BUTTON_SHADOW_COLOR,button,1342242816
Control8=IDC_EDIT_NAME_FONT_SIZE,edit,1350639744
Control9=IDC_SPIN_NAME_FONT_SIZE,msctls_updown32,1342177332
Control10=IDC_COMBO_NAME_FONT,combobox,1344340771
Control11=IDC_STATIC,static,1342308354
Control12=IDC_STATIC,button,1342177287
Control13=IDC_STATIC,static,1342308352

[CLS:CGeneralThemePropertyPage]
Type=0
HeaderFile=GeneralThemePropertyPage.h
ImplementationFile=GeneralThemePropertyPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CGeneralThemePropertyPage
VirtualFilter=idWC

[TB:IDR_DRAW_TOOLSBAR]
Type=1
Class=?
Command1=ID_TOOL_SELECT
Command2=ID_TOOL_CLASS
Command3=ID_TOOL_INTERFACE
Command4=ID_TOOL_NOTE
Command5=ID_TOOL_PACKAGE
Command6=ID_TOOL_GENERALIZATION
Command7=ID_TOOL_REALIZE
Command8=ID_TOOL_ASSOCIATION1
Command9=ID_TOOL_ASSOCIATION2
Command10=ID_TOOL_ASSOCIATION3
Command11=ID_TOOL_DEPENDENCY
CommandCount=11

[TB:IDR_DRAW_TOOLBAR]
Type=1
Class=?
Command1=ID_DRAW_TOOL_LINE
Command2=ID_DRAW_TOOL_RECT
Command3=ID_DRAW_TOOL_ELLIPSE
Command4=ID_DRAW_TOOL_ARC
Command5=ID_DRAW_TOOL_BEZIER
Command6=ID_TOOL_LABEL
Command7=ID_DRAW_TOOL_IMAGE
CommandCount=7

[TB:IDR_UML_TOOLBAR]
Type=1
Class=?
Command1=ID_TOOL_SELECT
Command2=ID_TOOL_CLASS
Command3=ID_TOOL_INTERFACE
Command4=ID_TOOL_NOTE
Command5=ID_TOOL_PACKAGE
Command6=ID_TOOL_GENERALIZATION
Command7=ID_TOOL_REALIZE
Command8=ID_TOOL_ASSOCIATION1
Command9=ID_TOOL_ASSOCIATION2
Command10=ID_TOOL_ASSOCIATION3
Command11=ID_TOOL_DEPENDENCY
CommandCount=11

[CLS:CToolShell]
Type=0
HeaderFile=ToolShell.h
ImplementationFile=ToolShell.cpp
BaseClass=CWnd
Filter=W
LastObject=CToolShell
VirtualFilter=WC

[DLG:IDD_NO_TOOL]
Type=1
Class=CNoToolDlg
ControlCount=1
Control1=IDC_STATIC,static,1342308353

[DLG:IDD_EDIT_METHOD_CODE]
Type=1
Class=CEditMethodCodeDlg
ControlCount=7
Control1=IDC_FRAME,static,1342177287
Control2=IDOK,button,1342177280
Control3=IDCANCEL,button,1342177280
Control4=IDC_EDIT_NAME,edit,1350567936
Control5=IDC_EDIT_BEGIN,edit,1350568064
Control6=IDC_EDIT_END,edit,1350568064
Control7=IDC_EDIT_COMMENTS,edit,1353715844

[CLS:CEditMethodCodeDlg]
Type=0
HeaderFile=EditMethodCodeDlg.h
ImplementationFile=EditMethodCodeDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CEditMethodCodeDlg
VirtualFilter=dWC

[DLG:IDD_WRITE_SOURCES]
Type=1
Class=CWriteSourceFiles
ControlCount=6
Control1=IDC_EDIT_REPOSITORY,edit,1350633600
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_LIST_FILES,SysListView32,1350631429
Control6=IDC_BUTTON_SELECT_REPOSITORY,button,1342242816

[CLS:CWriteSourceFiles]
Type=0
HeaderFile=WriteSourceFiles.h
ImplementationFile=WriteSourceFiles.cpp
BaseClass=CDialog
Filter=D
LastObject=CWriteSourceFiles
VirtualFilter=dWC

[DLG:IDD_PROP_GENERAL_THEME (Korean)]
Type=1
Class=CGeneralThemePropertyPage
ControlCount=13
Control1=IDC_STATIC,static,1342308352
Control2=IDC_BUTTON_NAME_COLOR,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_BUTTON_LINE_COLOR,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_BUTTON_SHADOW_COLOR,button,1342242816
Control8=IDC_EDIT_NAME_FONT_SIZE,edit,1350639744
Control9=IDC_SPIN_NAME_FONT_SIZE,msctls_updown32,1342177332
Control10=IDC_COMBO_NAME_FONT,combobox,1344340771
Control11=IDC_STATIC,static,1342308354
Control12=IDC_STATIC,button,1342177287
Control13=IDC_STATIC,static,1342308352

[DLG:IDD_PROP_NOTE_THEME (Korean)]
Type=1
Class=CNoteThemePropertyPage
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_BUTTON_NOTE_COLOR,button,1342242816
Control4=IDC_COMBO_NOTE_FONT,combobox,1344340226
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,button,1342177287

[DLG:IDD_PROP_PACKAGE_THEME (Korean)]
Type=1
Class=?
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_BUTTON_FILL_COLOR,button,1342242816
Control4=IDC_COMBO_NAME_FONT,combobox,1344340226
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,button,1342177287

[DLG:IDD_PROP_RELATION_THEME (Korean)]
Type=1
Class=CRelationThemePropertyPage
ControlCount=3
Control1=65535,button,1342177287
Control2=65535,static,1342308352
Control3=IDC_BUTTON_SYMBOL_COLOR,button,1342242816

[DLG:IDD_EDIT_METHOD_CODE (Korean)]
Type=1
Class=CEditMethodCodeDlg
ControlCount=7
Control1=IDC_FRAME,static,1342177287
Control2=IDOK,button,1342177280
Control3=IDCANCEL,button,1342177280
Control4=IDC_EDIT_NAME,edit,1350567936
Control5=IDC_EDIT_BEGIN,edit,1350568064
Control6=IDC_EDIT_END,edit,1350568064
Control7=IDC_EDIT_COMMENTS,edit,1353715844

[DLG:IDD_CLASS_EDITOR (Korean)]
Type=1
Class=CClassEditor
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552

[DLG:IDD_PROP_CLASS_THEME (Korean)]
Type=1
Class=CClassThemePropertyPage
ControlCount=23
Control1=IDC_BUTTON_CLASS_TITLE_COLOR,button,1342242816
Control2=IDC_BUTTON_CLASS_BACK_COLOR,button,1342242816
Control3=IDC_EDIT_ATTRIBUTE_FONT_SIZE,edit,1350639744
Control4=IDC_SPIN_ATTRIBUTE_FONT_SIZE,msctls_updown32,1342177332
Control5=IDC_COMBO_ATTRIBUTE_FONT,combobox,1344340771
Control6=IDC_EDIT_METHOD_FONT_SIZE,edit,1350639744
Control7=IDC_SPIN_METHOD_FONT_SIZE,msctls_updown32,1342177332
Control8=IDC_COMBO_METHOD_FONT,combobox,1344340771
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308354
Control12=IDC_STATIC,button,1342177287
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308354
Control15=IDC_STATIC,button,1342177287
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,button,1342177287
Control18=IDC_STATIC,static,1342308352
Control19=IDC_BUTTON_FOLDER_COLOR,button,1342242816
Control20=IDC_STATIC,static,1342308352
Control21=IDC_BUTTON_ATTRIBUTE_COLOR,button,1342242816
Control22=IDC_STATIC,static,1342308352
Control23=IDC_BUTTON_METHOD_COLOR,button,1342242816

[MNU:IDR_CLASS_EDITOR (Korean)]
Type=1
Class=?
Command1=ID_CLASS_EDIT_CUT
Command2=ID_CLASS_EDIT_COPY
Command3=ID_CLASS_EDIT_PASTE
Command4=ID_CLASS_EDIT_FIND
Command5=ID_CLASS_EDIT_REPLACE
CommandCount=5

[TB:IDR_MAINFRAME (Korean)]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_ARRANGE_BRING_TO_FRONT
Command8=ID_ARRANGE_SEND_TO_BACK
Command9=ID_EDIT_PROPERTIES
Command10=ID_FILE_READSOURCE
Command11=ID_FILE_SAVESOURCE
Command12=ID_EDIT_UNDO
Command13=ID_EDIT_REDO
Command14=ID_FILE_PRINT
Command15=ID_APP_ABOUT
CommandCount=15

[TB:IDR_DRAW_TOOLBAR (Korean)]
Type=1
Class=?
Command1=ID_TOOL_LABEL
CommandCount=1

[TB:IDR_VIEWBAR (Korean)]
Type=1
Class=?
Command1=ID_SCALE_COMBO
Command2=ID_VIEWMIN
Command3=ID_VIEWNORMAL
Command4=ID_VIEWMAX
Command5=ID_VIEWGRID
Command6=ID_VIEW_LOCK
CommandCount=6

[TB:IDR_CLASS_EDITOR (Korean)]
Type=1
Class=?
Command1=ID_CLASS_EDIT_CUT
Command2=ID_CLASS_EDIT_COPY
CommandCount=2

[TB:IDR_UML_TOOLBAR (Korean)]
Type=1
Class=?
Command1=ID_TOOL_SELECT
Command2=ID_TOOL_CLASS
Command3=ID_TOOL_INTERFACE
Command4=ID_TOOL_NOTE
Command5=ID_TOOL_PACKAGE
Command6=ID_TOOL_GENERALIZATION
Command7=ID_TOOL_REALIZE
Command8=ID_TOOL_ASSOCIATION1
Command9=ID_TOOL_ASSOCIATION2
Command10=ID_TOOL_ASSOCIATION3
Command11=ID_TOOL_DEPENDENCY
CommandCount=11

[MNU:IDR_CONTEXT_MENU]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_ARRANGE_BRING_TO_FRONT
Command5=ID_ARRANGE_SEND_TO_BACK
Command6=ID_EDIT_PROPERTIES
CommandCount=6

[MNU:IDR_POPUP_TOOLBAR]
Type=1
Class=?
Command1=ID_VIEW_TOOLBAR
Command2=ID_VIEW_WORKSPACE
Command3=ID_VIEW_OUTPUT
Command4=ID_VIEW_CUSTOMIZE
CommandCount=4

[DLG:IDD_NO_TOOL (Korean)]
Type=1
Class=CNoToolDlg
ControlCount=1
Control1=IDC_STATIC,static,1342308353

[DLG:IDD_WRITE_SOURCES (Korean)]
Type=1
Class=CWriteSourceFiles
ControlCount=6
Control1=IDC_EDIT_REPOSITORY,edit,1350633600
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_LIST_FILES,SysListView32,1350631429
Control6=IDC_BUTTON_SELECT_REPOSITORY,button,1342242816

[MNU:IDR_FILEVIEW_CONTEXT_MENU (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_ADD_TO_DOCUMENT
CommandCount=1

[DLG:IDD_PROP_LABEL (English (U.S.))]
Type=1
Class=CTinyUMLLabelPropertyPage
ControlCount=7
Control1=IDC_LABEL,edit,1350635648
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_BUTTON_NOTE_COLOR,button,1342242816
Control5=IDC_COMBO_NOTE_FONT,combobox,1344340226
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,button,1342177287

[CLS:CTinyUMLLabelPropertyPage]
Type=0
HeaderFile=TinyUMLLabelPropertyPage.h
ImplementationFile=TinyUMLLabelPropertyPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CTinyUMLLabelPropertyPage

[TB:IDR_STYLE_TOOLBAR]
Type=1
Class=?
Command1=ID_DRAWING_LINE_COLOR
Command2=ID_DRAWING_LINE_STYLE
Command3=ID_DRAWING_LINE_WEIGHT
CommandCount=3

