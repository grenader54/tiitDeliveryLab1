@echo off
tiit1.exe srand 5 build 1 10 1 2 3 4 5 6 7 8 9 10 view 1 > output1.txt
fc output1.txt answer1.txt > nul
if ERRORLEVEL 1 goto error1
echo OK1
goto :ok1
:error1
echo Wrong answer1
:ok1

tiit1.exe srand 5 build 1 10 1 2 3 4 5 6 7 8 9 11 view 1 erase 1 1 erase 1 2 erase 1 3 erase 1 4 erase 1 5 view 1 > output2.txt
fc output2.txt answer2.txt > nul
if ERRORLEVEL 1 goto error2
echo OK2
goto :ok2
:error2
echo Wrong answer2
:ok2

tiit1.exe srand 5 build 1 5 1 2 3 4 5 insert 1 1 10 insert 1 2 11 56 view 1 > output3.txt
fc output3.txt answer3.txt > nul
if ERRORLEVEL 1 goto error3
echo OK3
goto :ok3
:error3
echo Wrong answer3
:ok3

tiit1.exe srand 5 build 1 5 1 2 3 4 5 build 2 5 6 7 8 9 10 merge 1 view 1 > output4.txt
fc output4.txt answer4.txt > nul
if ERRORLEVEL 1 goto error4
echo OK4
goto :ok4
:error4
echo Wrong answer4
:ok4

tiit1.exe srand 5 build 1 5 1 2 3 4 5 build 2 5 1 2 3 9 10 interception > output5.txt
fc output5.txt answer5.txt > nul
if ERRORLEVEL 1 goto error5
echo OK5
goto :ok5
:error5
echo Wrong answer5
:ok5

tiit1.exe srand 5 build 1 5 1 2 3 4 5 find 1 1 find 1 30 view 1 > output6.txt
fc output6.txt answer6.txt > nul
if ERRORLEVEL 1 goto error6
echo OK6
goto :ok6
:error6
echo Wrong answer6
:ok6

tiit1.exe srand 5 build 1 5 1 2 3 4 view 1 > output7.txt
fc output7.txt answer7.txt > nul
if ERRORLEVEL 1 goto error7
echo OK7
goto :ok7
:error7
echo Wrong answer7
:ok7

tiit1.exe 1 2 3 4 5 > output8.txt
fc output8.txt answer8.txt > nul
if ERRORLEVEL 1 goto error8
echo OK8
goto :ok8
:error8
echo Wrong answer8
:ok8

TIMEOUT /t -1