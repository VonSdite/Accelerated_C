#ifndef GUARD_HELLO_SCREEN_H
#define GUARD_HELLO_SCREEN_H

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "show_menu.h"
#include <vector>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;

int show_hello_screen();						//显示欢迎界面
void choose_start();
void cover_guangbiao();							//隐藏光标
void see_guangbiao();							//显示光标
void start();

#endif // !GUARD_HELLO_SCREEN_H
