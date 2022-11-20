@echo off

set build_dir=%1
set pwd=%~dp0

if "%build_dir%"=="" goto end

mkdir %build_dir%
copy /Y "%pwd%library\glfw\lib-vc2022\glfw3.dll" "%build_dir%\glfw3.dll"
copy /Y "%pwd%library\glew\bin\Release\x64\glew32.dll" "%build_dir%\glew32.dll"
copy /Y "%pwd%library\assimp\build\bin\Debug\assimp-vc143-mtd.dll" "%build_dir%\assimp-vc143-mtd.dll"

xcopy /SYI "%pwd%engine\assets" "%build_dir%\assets"

:end
