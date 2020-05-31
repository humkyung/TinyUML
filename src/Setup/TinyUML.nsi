; HM NIS Edit Wizard helper defines
!define PRODUCT_NAME "TinyUML"
!define PRODUCT_VERSION   "1.0.0.0"
!define PRODUCT_PUBLISHER "hTech"
!define PRODUCT_WEB_SITE "http://www.hTech.co.kr"
!define PRODUCT_DIR_REGKEY "Software\${PRODUCT_NAME}"
!define PRODUCT_UNINST_KEY "Software\${PRODUCT_NAME}\Uninstall"
!define PRODUCT_UNINST_ROOT_KEY "HKLM"

; MUI 1.67 compatible ------
!include "MUI.nsh"

; MUI Settings
!define MUI_ABORTWARNING
!define MUI_ICON "${NSISDIR}\Contrib\Graphics\Icons\modern-install.ico"
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\modern-uninstall.ico"

; Welcome page
!insertmacro MUI_PAGE_WELCOME
; Directory page
!insertmacro MUI_PAGE_DIRECTORY
; Instfiles page
!insertmacro MUI_PAGE_INSTFILES
; Finish page
!define MUI_FINISHPAGE_RUN "$INSTDIR\TinyUML.exe"
!insertmacro MUI_PAGE_FINISH

; Uninstaller pages
!insertmacro MUI_UNPAGE_INSTFILES

; Language files
!insertmacro MUI_LANGUAGE "Korean"

; MUI end ------

Name "${PRODUCT_NAME} ${PRODUCT_VERSION}"
OutFile "TinyUML_${PRODUCT_VERSION}.exe"
InstallDir "$PROGRAMFILES\${PRODUCT_PUBLISHER}\TinyUML"
InstallDirRegKey HKLM "${PRODUCT_DIR_REGKEY}" ""
ShowInstDetails show
ShowUnInstDetails show

Section "MainSection" SEC01
  SetOutPath "$INSTDIR"
  SetOverwrite ifnewer
  File "TinyUML.exe"
  
  CreateDirectory "$SMPROGRAMS\${PRODUCT_PUBLISHER}"
  CreateDirectory "$SMPROGRAMS\${PRODUCT_PUBLISHER}\TinyUML"
  CreateShortCut "$SMPROGRAMS\${PRODUCT_PUBLISHER}\TinyUML\TinyUML_${PRODUCT_VERSION}.lnk" "$INSTDIR\TinyUML.exe"
  CreateShortCut "$DESKTOP\TinyUML_${PRODUCT_VERSION}.lnk" "$INSTDIR\TinyUML.exe"
SectionEnd

Section "DLL" SEC02
  SetOutPath "$INSTDIR"
  File "Is.dll"
  File "IsGUI.dll"
  File "ClassParser.dll"
  File "IsDrawCtrl.dll"
  File "IsDraw.dll"
  File "BCGCB553.dll"
  File "mfc42.dll"
SectionEnd

Section -AdditionalIcons
  WriteIniStr "$INSTDIR\${PRODUCT_NAME}.url" "InternetShortcut" "URL" "${PRODUCT_WEB_SITE}"
  CreateShortCut "$SMPROGRAMS\${PRODUCT_PUBLISHER}\TinyUML\Website.lnk" "$INSTDIR\${PRODUCT_NAME}.url"
  CreateShortCut "$SMPROGRAMS\${PRODUCT_PUBLISHER}\TinyUML\Uninstall.lnk" "$INSTDIR\uninst.exe"
SectionEnd

Section -Post
  WriteUninstaller "$INSTDIR\uninst.exe"
  WriteRegStr HKLM "${PRODUCT_DIR_REGKEY}" "File"    "$INSTDIR\TinyUML.exe"
  WriteRegStr HKLM "${PRODUCT_DIR_REGKEY}" "Version" "${PRODUCT_VERSION}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayName" "$(^Name)"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "UninstallString" "$INSTDIR\uninst.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayIcon" "$INSTDIR\TinyUML.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayVersion" "${PRODUCT_VERSION}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "URLInfoAbout" "${PRODUCT_WEB_SITE}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "Publisher" "${PRODUCT_PUBLISHER}"
SectionEnd

Function .onInit
         ReadRegStr $R0 HKLM "${PRODUCT_UNINST_KEY}" "UninstallString"
         StrCmp $R0 "" done
         
         MessageBox MB_OKCANCEL|MB_ICONEXCLAMATION \
                    "${PRODUCT_NAME} is already installed. $\n$\nClick  `OK` to remove the \
                    previous version or `Cancel` to cancel this upgrade." \
                    IDOK uninst
                    Abort done
                    
uninst:
       ClearErrors
       ; Wait for completing Uninstaller
       ExecWait '"$R0" _?=$INSTDIR'
;       abort   - no more needed
       
       ifErrors no_remove_uninstaller
       no_remove_uninstaller:
done:
FunctionEnd

Function un.onUninstSuccess
  HideWindow
  MessageBox MB_ICONINFORMATION|MB_OK "$(^Name)는(은) 완전히 제거되었습니다."
FunctionEnd

Function un.onInit
  MessageBox MB_ICONQUESTION|MB_YESNO|MB_DEFBUTTON2 "$(^Name)을(를) 제거하시겠습니까?" IDYES +2
  Abort
FunctionEnd

Section Uninstall
  Delete "$INSTDIR\${PRODUCT_NAME}.url"
  
  Delete "$INSTDIR\*.*"
  
  Delete "$SMPROGRAMS\${PRODUCT_PUBLISHER}\TinyUML\Uninstall.lnk"
  Delete "$SMPROGRAMS\${PRODUCT_PUBLISHER}\TinyUML\Website.lnk"
  Delete "$DESKTOP\TinyUML  v${PRODUCT_VERSION}.lnk"
  Delete "$SMPROGRAMS\${PRODUCT_PUBLISHER}\TinyUML\TinyUML  v${PRODUCT_VERSION}.lnk"

  RMDir "$SMPROGRAMS\TinyUML"
  RMDir "$INSTDIR"

  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}"
  DeleteRegKey HKLM "${PRODUCT_DIR_REGKEY}"
  SetAutoClose true
SectionEnd