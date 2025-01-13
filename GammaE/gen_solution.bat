@echo off
echo --------------- Generating project files -----------------------"
premake5 %1 %2 %3 %4 %5 --file=generate_projects.lua
echo --------------- Adding project files to solution ---------------"
premake5 %1 %2 %3 %4 %5 --file=include_projects.lua
