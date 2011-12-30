@echo off
cd ../../src/Lua
SET LUASOURCE=LuaMirage.cpp
SET LUAPACKAGE=luamirage.pkg
FOR /F %%i IN ('DIR /B /O:D "%LUASOURCE%" "%LUAPACKAGE%"') DO SET NEWEST=%%i 
cd ..
cd ..

IF %NEWEST% EQU %LUAPACKAGE% (
echo Regenerating lua module from package...
"external/tolua++.exe" -o src/Lua/LuaMirage.cpp src/Lua/luamirage.pkg
echo done
) ELSE (
echo Skipping regeneration. No action needed.
)