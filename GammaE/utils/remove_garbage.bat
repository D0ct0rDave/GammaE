@echo off
REM retrieve files to process
dir /s /b ..\*.h ..\*.cpp > files.txt
c:\utils\sed\bin\sed -i "s/\\/\//g" files.txt

REM replace \ per /
for /F "tokens=*" %%A in (files.txt) do (
	echo %%A

	rem remove line with "namespace GammaE {"
	rem c:\utils\sed\bin\sed -i "/namespace GammaE {/d" %%A
	
	rem c:\utils\sed\bin\sed -i "/}; \/\/ namespace GammaE \/\/ namespace/d" %%A
	
	rem change // / -> //
	rem c:\utils\sed\bin\sed -i "s/\/\/ \//\/\//g" %%A
	
	rem remove lines with "// %X% %Q% %Z% %W%"
	rem c:\utils\sed\bin\sed -i "/\%X\% \%Q\% \%Z\% \%W\%/d" %%A
	rem c:\utils\sed\bin\sed '/\%X\%.*\%Q\%.*\%Z\%.*\%W\%/d' file_path

	rem change // / -> //
	rem c:\utils\sed\bin\sed -i "s/-------(.*)/-------\r\n\/\/%1/" %%A
	c:\utils\sed\bin\sed -n "/--\([A-Za-z]\)/p" %%A
)

rem c:\utils\SimpleSearchReplace\ssr.exe 0 \ / files.txt  (sed -i /keyword/substitution/command)
rem del /S sed*
REM ident correctly files
rem c:\utils\uncrustify\uncrustify -c c:\utils\uncrustify\uncrustify.cfg -F files.txt --replace -l CPP 2> log.txt

REM go back one directory
cd..

REM fix Doxygen comments
REM for /R %%f in (*.h *.cpp) do \utils\SimpleSearchReplace\ssr.exe 0 ///SSR_SP// /// %%f

REM delete backup files
rem del /S *.md5~
rem del /S *.unc-backup~

pause
	
rem 
