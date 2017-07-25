; example2.nsi
;
; This script is based on example1.nsi, but it remember the directory, 
; has uninstall support and (optionally) installs start menu shortcuts.
;
; It will install example2.nsi into a directory that the user selects,

;--------------------------------

!define APP "ClipboardLib"

!system 'DefineAsmVer.exe "Release\${APP}.dll" "!define VER ""[SVER]"" " > Tmpver.nsh'
!include "Tmpver.nsh"
!searchreplace APV ${VER} "." "_"

; The name of the installer
Name "${APP} ${VER}"

; The file to write
OutFile "Setup_${APP}.exe"

; The default installation directory
InstallDir "$PROGRAMFILES\${APP}"

; Registry key to check for directory (so if you install again, it will 
; overwrite the old one automatically)
InstallDirRegKey HKLM "Software\${APP}" "Install_Dir"

; Request application privileges for Windows Vista
RequestExecutionLevel admin

;--------------------------------

; Pages

;Page components
Page directory
Page instfiles

UninstPage uninstConfirm
UninstPage instfiles

;--------------------------------

; The stuff to install
Section "Example2 (required)"

  SectionIn RO
  
  ; Set output path to the installation directory.
  SetOutPath $INSTDIR
  
  ; Put file there
  SetOutPath "$INSTDIR\x86"
  File "Release\${APP}.dll"
  ExecWait 'regsvr32.exe /s "${APP}.dll"' $0
  DetailPrint "Result: $0"

  SetOutPath "$INSTDIR\x64"
  File "x64\Release\${APP}.dll"
  ExecWait 'regsvr32.exe /s "${APP}.dll"' $0
  DetailPrint "Result: $0"

  ; Write the installation path into the registry
  WriteRegStr HKLM "Software\${APP}" "Install_Dir" "$INSTDIR"
  
  ; Write the uninstall keys for Windows
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP}" "DisplayName" "NSIS ${APP}"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP}" "UninstallString" '"$INSTDIR\uninstall.exe"'
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP}" "NoModify" 1
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP}" "NoRepair" 1
  WriteUninstaller "uninstall.exe"
  
SectionEnd

;--------------------------------

; Uninstaller

Section "Uninstall"
  
  ; Remove registry keys
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP}"
  DeleteRegKey HKLM "Software\${APP}"

  ; Remove files and uninstaller
  SetOutPath "$INSTDIR\x86"
  ExecWait 'regsvr32.exe /s /u "${APP}.dll"' $0
  DetailPrint "Result: $0"

  SetOutPath "$INSTDIR\x64"
  ExecWait 'regsvr32.exe /s /u "${APP}.dll"' $0
  DetailPrint "Result: $0"

  Delete "$INSTDIR\x86\${APP}.dll"
  Delete "$INSTDIR\x64\${APP}.dll"
  Delete "$INSTDIR\uninstall.exe"

  ; Remove shortcuts, if any

  ; Remove directories used
  RMDir "$INSTDIR"

SectionEnd
