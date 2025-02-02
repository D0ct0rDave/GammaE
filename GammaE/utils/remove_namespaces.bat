REM retrieve files to process
dir /s /b ..\*.h ..\*.cpp > files.txt

REM replace \ per /
set enabledealyedexpansion

for /F "tokens=*" %%A in (files.txt) do (
	echo %%A
	c:\utils\sed\bin\sed -i "/namespace GammaE {/d" %%A
	c:\utils\sed\bin\sed -i "/}; \/\/ namespace GammaE \/\/ namespace/d" %%A
	c:\utils\sed\bin\sed -i "s/\/\/ \//\/\/\//g" %%A
	// -----------------------------------------------------------------------------
	// -----------------------------------------------------------------------------

	// / 

)
rem c:\utils\SimpleSearchReplace\ssr.exe 0 \ / files.txt  (sed -i /keyword/substitution/command)
c:\utils\sed\bin\sed -i "s/\\/\//g" files.txt
del /S sed*
REM ident correctly files
c:\utils\uncrustify\uncrustify -c c:\utils\uncrustify\uncrustify.cfg -F files.txt --replace -l CPP 2> log.txt

@echo off
REM go back one directory
cd..

REM fix Doxygen comments
REM for /R %%f in (*.h *.cpp) do \utils\SimpleSearchReplace\ssr.exe 0 ///SSR_SP// /// %%f

REM delete backup files
del /S *.md5~
del /S *.unc-backup~


rem 
