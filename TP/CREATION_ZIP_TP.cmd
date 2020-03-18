@echo off   

setlocal
set TEMPDIR=%TEMP%\ZIP
set OUTPUTZIP="DEFAULT"
if "%2"=="" set OUTPUTZIP=%1.zip

:: preparing VBS script
echo Set objArgs = WScript.Arguments > _zipIt.vbs
echo InputFolder = objArgs(0) >> _zipIt.vbs
echo ZipFile = objArgs(1) >> _zipIt.vbs
echo Set fso = WScript.CreateObject("Scripting.FileSystemObject") >> _zipIt.vbs
echo Set objZipFile = fso.CreateTextFile(ZipFile, True) >> _zipIt.vbs
echo objZipFile.Write "PK" ^& Chr(5) ^& Chr(6) ^& String(18, vbNullChar) >> _zipIt.vbs
echo objZipFile.Close >> _zipIt.vbs
echo Set objShell = WScript.CreateObject("Shell.Application") >> _zipIt.vbs
echo Set source = objShell.NameSpace(InputFolder).Items >> _zipIt.vbs
echo Set objZip = objShell.NameSpace(fso.GetAbsolutePathName(ZipFile)) >> _zipIt.vbs
echo if not (objZip is nothing) then  >> _zipIt.vbs
echo    objZip.CopyHere(source) >> _zipIt.vbs
echo    wScript.Sleep 12000 >> _zipIt.vbs
echo end if >> _zipIt.vbs

@ECHO Zipping, please wait...
mkdir %TEMPDIR%
xcopy /y /s *.cpp %TEMPDIR%
xcopy /y /s *.h %TEMPDIR%
xcopy /y /s *.hpp %TEMPDIR%
xcopy /y /s *.doc %TEMPDIR%
xcopy /y /s *.docx %TEMPDIR%
xcopy /y /s *.pdf %TEMPDIR%
WScript _zipIt.vbs  %TEMPDIR%  TP_%NOM%.zip
del _zipIt.vbs
rmdir /s /q  %TEMPDIR%

@ECHO ZIP Completed.
:end