@echo off
premake5 %1 %2 %3 %4 %5 --file=generate_projects.lua
premake5 %1 %2 %3 %4 %5 --file=include_projects.lua
