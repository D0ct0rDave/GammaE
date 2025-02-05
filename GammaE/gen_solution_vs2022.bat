@echo off

echo --------------- Generating project files -----------------------"
..\Tools\premake5 vs2022 %2 %3 %4 %5 --file=generate_projects.lua

pause
