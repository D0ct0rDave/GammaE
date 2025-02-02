@echo off
type PREFIX > temp
type %1 >> temp
type SUFIX >> temp
move temp %1