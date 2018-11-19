cls

c:\GnuWin32\bin\flex Lexico.l

c:\GnuWin32\bin\bison -dyv Sintactico.y

c:\MinGW\bin\gcc.exe lex.yy.c y.tab.c -o Final.exe
Final.exe Prueba.txt
pause
pause
del lex.yy.c
del y.tab.c
del y.output
del y.tab.h
del Final.exe

pause
