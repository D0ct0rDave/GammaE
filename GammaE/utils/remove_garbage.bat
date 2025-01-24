REM retrieve files to process
dir /s /b ..\*.h ..\*.cpp > files.txt

REM replace \ per /
set enabledealyedexpansion

for /F "tokens=*" %%A in (files.txt) do (
	echo %%A

	rem remove line with "namespace GammaE {"
	rem c:\utils\sed\bin\sed -i "/namespace GammaE {/d" %%A
	
	rem c:\utils\sed\bin\sed -i "/}; \/\/ namespace GammaE \/\/ namespace/d" %%A
	
	rem change // / -> //
	rem c:\utils\sed\bin\sed -i "s/\/\/ \//\/\//g" %%A
	
	rem remove lines with "// %X% %Q% %Z% %W%"
	c:\utils\sed\bin\sed -i "/\%X\% \%Q\% \%Z\% \%W\%/d" %%A
	rem c:\utils\sed\bin\sed '/\%X\%.*\%Q\%.*\%Z\%.*\%W\%/d' file_path

	rem change // / -> //
	rem c:\utils\sed\bin\sed -i "s/\/\/ -----------------------------------------------------------------------------\r\n\/\/ -----------------------------------------------------------------------------/\/\/ -----------------------------------------------------------------------------\r\n/g" %%A
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
