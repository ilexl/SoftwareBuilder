@echo off
:a
pushd ..\
call vendor\premake\premake5.exe vs2022
popd
IF %ERRORLEVEL% NEQ 0 (
	PAUSE
	goto a
)