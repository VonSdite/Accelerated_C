@echo off
echo ���������˳�
pause > nul

mode con cols=80 lines=20
:cho
set choice= 
set /p choice=           �Ƿ�Ҫ�浵(y/n): 

IF NOT "%choice%"=="" SET choice=%choice:~0,1%
if /i "%choice%"=="y" goto end
if /i "%choice%"=="n" goto delete  
echo ѡ����Ч������������ 
pause 
cls
goto cho 

:delete
del "GAME.SAV"
copy "SAVE.SAV" "GAME.SAV"
cls
goto endend

:end
copy "GAME.SAV" "SAVE.SAV"
cls

:endend