REM retrieve files to process
dir /s /b ..\*.h ..\*.cpp > files.txt

REM replace \ per /
rem c:\utils\SimpleSearchReplace\ssr.exe 0 \ / files.txt
c:\utils\sed\bin\sed -i s/\\/\//g  files.txt

REM ident correctly files
c:\utils\uncrustify\uncrustify -c c:\utils\uncrustify\uncrustify.cfg -F files.txt --replace -l CPP 2> log.txt

REM go back one directory
cd..

REM fix Doxygen comments
rem for /R %%f in (*.h *.cpp) do \utils\SimpleSearchReplace\ssr.exe 0 ///SSR_SP// /// %%f

REM delete backup files
del /S *.md5~
del /S *.unc-backup~
