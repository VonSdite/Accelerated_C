//��ʾ�������˵�
#ifndef GUARD_SHOW_MENU
#define GUARD_SHOW_MENU

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

//��ӡ�ɵȺš�-����ɵĺ���
void print_line();

//������ֵ�ĳ���
int get_length(int);

//��ʾһ�����˵�
void show_main_menu(const int);
void show_main_menu1();
void show_main_menu2();
void show_main_menu3();
void show_main_menu4();

//��ʾ�����˵�����ѧ��״̬��ѯ
void status_menu(const int);
void status_menu1();
void status_menu2();
void status_menu3();
void status_menu4();

//��ʾ�����˵�����ѧ�������ѯ
void dorm_menu(const int);
void dorm_menu1();
void dorm_menu2();
void dorm_menu3();


//��ʾ�����˵�����ѧ��������ѯ
void love_menu(const int);
void love_menu1();
void love_menu2();
void love_menu3();
void love_menu4();




#endif