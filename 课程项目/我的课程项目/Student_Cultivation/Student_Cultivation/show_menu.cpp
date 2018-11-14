//显示几个主菜单
#include "show_menu.h"
#include <windows.h>

//宏定义更加方便改颜色！！
#define color_change_blue(a)  SetConsoleTextAttribute(handle, 0x0b);\
								cout << a;\
								SetConsoleTextAttribute(handle, 0x07)

#define color_change_red(a)  SetConsoleTextAttribute(handle, 0x0c);\
								cout << a;\
								SetConsoleTextAttribute(handle, 0x07)

//打印由等号“=”组成的横线
void print_line()
{
	string s(50, '-');
	cout << s << endl;
}

//计算数值的长度
int get_length(int n)
{
	int num_length = 0;

	while (0 != n)
	{
		n /= 10;
		num_length++;
	}

	return num_length;
}

//显示一级主菜单
void show_main_menu(const int select)
{
	switch (select)
	{
	case 1: show_main_menu1();
		break;
	case 2:	show_main_menu2();
		break;
	case 3: show_main_menu3();
		break;
	case 4: show_main_menu4();
		break;
	}
}

void show_main_menu1()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	print_line();
	cout << "*                ";
	color_change_blue("微型學生養成系統");
	cout << "                *" << endl;
	print_line();
	cout << "*             ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 1.学生状态查询 <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "               *" << endl;
	print_line();
	cout << "*                2.学生宿舍查询                  *" << endl;
	print_line();
	cout << "*                3.学生恋爱查询                  *" << endl;
	print_line();
	cout << "*                0.退出                          *" << endl;
	print_line();
	cout << "*  ";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"回车键\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "选择, ";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"esc键\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "退出,";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"退格键\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "返回上一级";
	cout << "  *" << endl;
	print_line();
}

void show_main_menu2()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	print_line();
	cout << "*                ";
	color_change_blue("微型學生養成系統");
	cout <<"                *" << endl;
	print_line();
	cout << "*                1.学生状态查询                  *" << endl;
	print_line();
	cout << "*             ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 2.学生宿舍查询 <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout <<	"               *" << endl;
	print_line();
	cout << "*                3.学生恋爱查询                  *" << endl;
	print_line();
	cout << "*                0.退出                          *" << endl;
	print_line();
	cout << "*  ";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"回车键\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "选择, ";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"esc键\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "退出,";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"退格键\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "返回上一级";
	cout << "  *" << endl;
	print_line();
}

void show_main_menu3()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	print_line();
	cout << "*                ";
	color_change_blue("微型學生養成系統");
	cout << "                *" << endl;
	print_line();
	cout << "*                1.学生状态查询                  *" << endl;
	print_line();
	cout << "*                2.学生宿舍查询                  *" << endl;
	print_line();
	cout << "*             ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 3.学生恋爱查询 <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout <<	"               *" << endl;
	print_line();
	cout << "*                0.退出                          *" << endl;
	print_line();
	cout << "*  ";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"回车键\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "选择, ";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"esc键\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "退出,";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"退格键\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "返回上一级";
	cout << "  *" << endl;
	print_line();
}

void show_main_menu4()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	print_line();
	cout << "*                ";
	color_change_blue("微型學生養成系統");
	cout << "                *" << endl;
	print_line();
	cout << "*                1.学生状态查询                  *" << endl;
	print_line();
	cout << "*                2.学生宿舍查询                  *" << endl;
	print_line();
	cout << "*                3.学生恋爱查询                  *" << endl;
	print_line();
	cout << "*             ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 0.退出 <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "                       *" << endl;
	print_line();
	cout << "*  ";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"回车键\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "选择, ";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"esc键\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "退出,";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"退格键\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "返回上一级";
	cout << "  *" << endl;
	print_line();
}


//显示二级菜单——学生状态查询
void status_menu(const int select)
{
	switch (select)
	{
	case 1: status_menu1();
		break;
	case 2:	status_menu2();
		break;
	case 3: status_menu3();
		break;
	case 4: status_menu4();
		break;
	}
}

void status_menu1()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	print_line();
	cout << "*                  ";
	color_change_blue("学生状态查询");
	cout << "                  *" << endl;
	print_line();
	cout << "*            ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 1.查询某学生的状态 <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "            *" << endl;
	print_line();
	cout << "*               2.状态最值查询                   *" << endl;
	print_line();
	cout << "*               3.状态范围查询                   *" << endl;
	print_line();
	cout << "*               0.返回上一级菜单                 *" << endl;
	print_line();
}

void status_menu2()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	print_line();
	cout << "*                  ";
	color_change_blue("学生状态查询");
	cout << "                  *" << endl;
	print_line();
	cout << "*               1.查询某学生的状态               *" << endl;
	print_line();
	cout << "*            ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 2.状态最值查询 <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "                *" << endl;
	print_line();
	cout << "*               3.状态范围查询                   *" << endl;
	print_line();
	cout << "*               0.返回上一级菜单                 *" << endl;
	print_line();
}

void status_menu3()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	print_line();
	cout << "*                  ";
	color_change_blue("学生状态查询");
	cout << "                  *" << endl;
	print_line();
	cout << "*               1.查询某学生的状态               *" << endl;
	print_line();
	cout << "*               2.状态最值查询                   *" << endl;
	print_line();
	cout << "*            ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 3.状态范围查询 <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "                *" << endl;
	print_line();
	cout << "*               0.返回上一级菜单                 *" << endl;
	print_line();
}

void status_menu4()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	print_line();
	cout << "*                  ";
	color_change_blue("学生状态查询");
	cout << "                  *" << endl;
	print_line();
	cout << "*               1.查询某学生的状态               *" << endl;
	print_line();
	cout << "*               2.状态最值查询                   *" << endl;
	print_line();
	cout << "*               3.状态范围查询                   *" << endl;
	print_line();
	cout << "*            ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 0.返回上一级菜单 <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "              *" << endl;
	print_line();
}

//显示二级菜单——学生宿舍查询
void dorm_menu(const int select)
{
	switch (select)
	{
	case 1: dorm_menu1();
		break;
	case 2:	dorm_menu2();
		break;
	case 3: dorm_menu3();
		break;
	}
}

void dorm_menu1()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	print_line();
	cout << "*                  ";
	color_change_blue("学生宿舍查询");
	cout << "                  *" << endl;
	print_line();
	cout << "*            ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 1.查询某学生房间号 <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "            *" << endl;
	print_line();
	cout << "*               2.查询房间号对应学生             *" << endl;
	print_line();
	cout << "*               0.返回上一级菜单                 *" << endl;
	print_line();
}

void dorm_menu2()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	print_line();
	cout << "*                  ";
	color_change_blue("学生宿舍查询");
	cout << "                  *" << endl;
	print_line();
	cout << "*               1.查询某学生房间号               *" << endl;
	print_line();
	cout << "*            ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 2.查询房间号对应学生 <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "          *" << endl;
	print_line();
	cout << "*               0.返回上一级菜单                 *" << endl;
	print_line();
}

void dorm_menu3()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	print_line();
	cout << "*                  ";
	color_change_blue("学生宿舍查询");
	cout << "                  *" << endl;
	print_line();
	cout << "*               1.查询某学生房间号               *" << endl;
	print_line();
	cout << "*               2.查询房间号对应学生             *" << endl;
	print_line();
	cout << "*            ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 0.返回上一级菜单 <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "              *" << endl;
	print_line();
}

//显示二级菜单——学生恋爱查询
void love_menu(const int select)
{
	switch (select)
	{
	case 1: love_menu1();
		break;
	case 2:	love_menu2();
		break;
	case 3: love_menu3();
		break;
	case 4: love_menu4();
		break;
	}
}

void love_menu1()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	print_line();
	cout << "*                  ";
	color_change_blue("学生恋爱查询");
	cout << "                  *" << endl;
	print_line();
	cout << "*          ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 1.查询某学生恋爱史 <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "              *" << endl;
	print_line();
	cout << "*             2.查询恋爱史最多的学生             *" << endl;
	print_line();
	cout << "*             3.恋人魅力值最高的学生             *" << endl;
	print_line();
	cout << "*             0.返回上一级菜单                   *" << endl;
	print_line();
}

void love_menu2()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	print_line();
	cout << "*                  ";
	color_change_blue("学生恋爱查询");
	cout << "                  *" << endl;
	print_line();
	cout << "*             1.查询某学生恋爱史                 *" << endl;
	print_line();
	cout << "*          ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 2.查询恋爱史最多的学生 <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "          *" << endl;
	print_line();
	cout << "*             3.恋人魅力值最高的学生             *" << endl;
	print_line();
	cout << "*             0.返回上一级菜单                   *" << endl;
	print_line();
}

void love_menu3()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	print_line();
	cout << "*                  ";
	color_change_blue("学生恋爱查询");
	cout << "                  *" << endl;
	print_line();
	cout << "*             1.查询某学生恋爱史                 *" << endl;
	print_line();
	cout << "*             2.查询恋爱史最多的学生             *" << endl;
	print_line();
	cout << "*          ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 3.恋人魅力值最高的学生 <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "          *" << endl;
	print_line();
	cout << "*             0.返回上一级菜单                   *" << endl;
	print_line();
}

void love_menu4()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	print_line();
	cout << "*                  ";
	color_change_blue("学生恋爱查询");
	cout << "                  *" << endl;
	print_line();
	cout << "*             1.查询某学生恋爱史                 *" << endl;
	print_line();
	cout << "*             2.查询恋爱史最多的学生             *" << endl;
	print_line();
	cout << "*             3.恋人魅力值最高的学生             *" << endl;
	print_line();
	cout << "*          ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 0.返回上一级菜单 <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "                *" << endl;
	print_line();
}

