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

int show_hello_screen();						//��ʾ��ӭ����
void choose_start();
void cover_guangbiao();							//���ع��
void see_guangbiao();							//��ʾ���
void start();

#endif // !GUARD_HELLO_SCREEN_H
