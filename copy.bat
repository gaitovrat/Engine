@echo off

set build_dir=%1
set pwd=%~dp0

if "%build_dir%"=="" goto end

mkdir %build_dir%
copy /Y "%pwd%library\glfw\lib\glfw3.dll" "%build_dir%\glfw3.dll"
copy /Y "%pwd%library\glew\bin\glew32.dll" "%build_dir%\glew32.dll"
copy /Y "%pwd%library\assimp\bin\assimp-vc143-mt.dll" "%build_dir%\assimp-vc143-mt.dll"

xcopy /SYI "%pwd%engine\assets" "%build_dir%\assets"

:end
