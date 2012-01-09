@echo off
if "%PROFILE%"=="" (
echo Please set the Profile variable before running the script!
goto exit
)

if not exist ..\..\build mkdir ..\..\build
set cpy=xcopy /d /y /i /s

%cpy% "%PROFILE%\mirage.exe" ..\..\build\

cd ..\..
%cpy% data\gfx\* build\data\gfx\
%cpy% data\models\*.obj build\data\models\
%cpy% data\models\*.mtl build\data\models\
%cpy% data\scripts build\data\scripts\
%cpy% data\shaders build\data\shaders\

cd build
zip -r data *.* -x *.zip 
move data.zip mirage.%PROFILE%.zip
cd ..

:exit
	cd projectfiles\vc9