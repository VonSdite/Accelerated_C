@echo off
mode con cols=80 lines=20
:flag
if exist "GAME.SAV" set choice= 
if exist "GAME.SAV" set /p choice=        ��⵽�ϴδ浵,�Ƿ�Ҫ����(y/n): 
if exist "GAME.SAV" IF NOT "%choice%"=="" SET choice=%choice:~0,1%
if exist "GAME.SAV" if /i "%choice%"=="y" goto begin
if exist "GAME.SAV" if /i "%choice%"=="n" goto new_begin 
if exist "GAME.SAV" echo ѡ����Ч������������ 
if exist "GAME.SAV" pause
if exist "GAME.SAV" cls
if exist "GAME.SAV" goto flag
else goto begin

:new_begin
del "GAME.SAV"

:begin
