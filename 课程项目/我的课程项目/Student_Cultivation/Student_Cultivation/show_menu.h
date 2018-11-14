//显示几个主菜单
#ifndef GUARD_SHOW_MENU
#define GUARD_SHOW_MENU

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

//打印由等号“-”组成的横线
void print_line();

//计算数值的长度
int get_length(int);

//显示一级主菜单
void show_main_menu(const int);
void show_main_menu1();
void show_main_menu2();
void show_main_menu3();
void show_main_menu4();

//显示二级菜单——学生状态查询
void status_menu(const int);
void status_menu1();
void status_menu2();
void status_menu3();
void status_menu4();

//显示二级菜单——学生宿舍查询
void dorm_menu(const int);
void dorm_menu1();
void dorm_menu2();
void dorm_menu3();


//显示二级菜单——学生恋爱查询
void love_menu(const int);
void love_menu1();
void love_menu2();
void love_menu3();
void love_menu4();




#endif