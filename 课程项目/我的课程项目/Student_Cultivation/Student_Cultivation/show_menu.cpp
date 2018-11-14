//��ʾ�������˵�
#include "show_menu.h"
#include <windows.h>

//�궨����ӷ������ɫ����
#define color_change_blue(a)  SetConsoleTextAttribute(handle, 0x0b);\
								cout << a;\
								SetConsoleTextAttribute(handle, 0x07)

#define color_change_red(a)  SetConsoleTextAttribute(handle, 0x0c);\
								cout << a;\
								SetConsoleTextAttribute(handle, 0x07)

//��ӡ�ɵȺš�=����ɵĺ���
void print_line()
{
	string s(50, '-');
	cout << s << endl;
}

//������ֵ�ĳ���
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

//��ʾһ�����˵�
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
	color_change_blue("΢�͌W���B��ϵ�y");
	cout << "                *" << endl;
	print_line();
	cout << "*             ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 1.ѧ��״̬��ѯ <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "               *" << endl;
	print_line();
	cout << "*                2.ѧ�������ѯ                  *" << endl;
	print_line();
	cout << "*                3.ѧ��������ѯ                  *" << endl;
	print_line();
	cout << "*                0.�˳�                          *" << endl;
	print_line();
	cout << "*  ";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"�س���\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "ѡ��, ";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"esc��\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "�˳�,";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"�˸��\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "������һ��";
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
	color_change_blue("΢�͌W���B��ϵ�y");
	cout <<"                *" << endl;
	print_line();
	cout << "*                1.ѧ��״̬��ѯ                  *" << endl;
	print_line();
	cout << "*             ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 2.ѧ�������ѯ <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout <<	"               *" << endl;
	print_line();
	cout << "*                3.ѧ��������ѯ                  *" << endl;
	print_line();
	cout << "*                0.�˳�                          *" << endl;
	print_line();
	cout << "*  ";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"�س���\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "ѡ��, ";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"esc��\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "�˳�,";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"�˸��\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "������һ��";
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
	color_change_blue("΢�͌W���B��ϵ�y");
	cout << "                *" << endl;
	print_line();
	cout << "*                1.ѧ��״̬��ѯ                  *" << endl;
	print_line();
	cout << "*                2.ѧ�������ѯ                  *" << endl;
	print_line();
	cout << "*             ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 3.ѧ��������ѯ <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout <<	"               *" << endl;
	print_line();
	cout << "*                0.�˳�                          *" << endl;
	print_line();
	cout << "*  ";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"�س���\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "ѡ��, ";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"esc��\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "�˳�,";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"�˸��\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "������һ��";
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
	color_change_blue("΢�͌W���B��ϵ�y");
	cout << "                *" << endl;
	print_line();
	cout << "*                1.ѧ��״̬��ѯ                  *" << endl;
	print_line();
	cout << "*                2.ѧ�������ѯ                  *" << endl;
	print_line();
	cout << "*                3.ѧ��������ѯ                  *" << endl;
	print_line();
	cout << "*             ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 0.�˳� <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "                       *" << endl;
	print_line();
	cout << "*  ";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"�س���\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "ѡ��, ";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"esc��\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "�˳�,";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "\"�˸��\"";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "������һ��";
	cout << "  *" << endl;
	print_line();
}


//��ʾ�����˵�����ѧ��״̬��ѯ
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
	color_change_blue("ѧ��״̬��ѯ");
	cout << "                  *" << endl;
	print_line();
	cout << "*            ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 1.��ѯĳѧ����״̬ <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "            *" << endl;
	print_line();
	cout << "*               2.״̬��ֵ��ѯ                   *" << endl;
	print_line();
	cout << "*               3.״̬��Χ��ѯ                   *" << endl;
	print_line();
	cout << "*               0.������һ���˵�                 *" << endl;
	print_line();
}

void status_menu2()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	print_line();
	cout << "*                  ";
	color_change_blue("ѧ��״̬��ѯ");
	cout << "                  *" << endl;
	print_line();
	cout << "*               1.��ѯĳѧ����״̬               *" << endl;
	print_line();
	cout << "*            ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 2.״̬��ֵ��ѯ <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "                *" << endl;
	print_line();
	cout << "*               3.״̬��Χ��ѯ                   *" << endl;
	print_line();
	cout << "*               0.������һ���˵�                 *" << endl;
	print_line();
}

void status_menu3()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	print_line();
	cout << "*                  ";
	color_change_blue("ѧ��״̬��ѯ");
	cout << "                  *" << endl;
	print_line();
	cout << "*               1.��ѯĳѧ����״̬               *" << endl;
	print_line();
	cout << "*               2.״̬��ֵ��ѯ                   *" << endl;
	print_line();
	cout << "*            ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 3.״̬��Χ��ѯ <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "                *" << endl;
	print_line();
	cout << "*               0.������һ���˵�                 *" << endl;
	print_line();
}

void status_menu4()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	print_line();
	cout << "*                  ";
	color_change_blue("ѧ��״̬��ѯ");
	cout << "                  *" << endl;
	print_line();
	cout << "*               1.��ѯĳѧ����״̬               *" << endl;
	print_line();
	cout << "*               2.״̬��ֵ��ѯ                   *" << endl;
	print_line();
	cout << "*               3.״̬��Χ��ѯ                   *" << endl;
	print_line();
	cout << "*            ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 0.������һ���˵� <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "              *" << endl;
	print_line();
}

//��ʾ�����˵�����ѧ�������ѯ
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
	color_change_blue("ѧ�������ѯ");
	cout << "                  *" << endl;
	print_line();
	cout << "*            ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 1.��ѯĳѧ������� <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "            *" << endl;
	print_line();
	cout << "*               2.��ѯ����Ŷ�Ӧѧ��             *" << endl;
	print_line();
	cout << "*               0.������һ���˵�                 *" << endl;
	print_line();
}

void dorm_menu2()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	print_line();
	cout << "*                  ";
	color_change_blue("ѧ�������ѯ");
	cout << "                  *" << endl;
	print_line();
	cout << "*               1.��ѯĳѧ�������               *" << endl;
	print_line();
	cout << "*            ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 2.��ѯ����Ŷ�Ӧѧ�� <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "          *" << endl;
	print_line();
	cout << "*               0.������һ���˵�                 *" << endl;
	print_line();
}

void dorm_menu3()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	print_line();
	cout << "*                  ";
	color_change_blue("ѧ�������ѯ");
	cout << "                  *" << endl;
	print_line();
	cout << "*               1.��ѯĳѧ�������               *" << endl;
	print_line();
	cout << "*               2.��ѯ����Ŷ�Ӧѧ��             *" << endl;
	print_line();
	cout << "*            ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 0.������һ���˵� <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "              *" << endl;
	print_line();
}

//��ʾ�����˵�����ѧ��������ѯ
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
	color_change_blue("ѧ��������ѯ");
	cout << "                  *" << endl;
	print_line();
	cout << "*          ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 1.��ѯĳѧ������ʷ <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "              *" << endl;
	print_line();
	cout << "*             2.��ѯ����ʷ����ѧ��             *" << endl;
	print_line();
	cout << "*             3.��������ֵ��ߵ�ѧ��             *" << endl;
	print_line();
	cout << "*             0.������һ���˵�                   *" << endl;
	print_line();
}

void love_menu2()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	print_line();
	cout << "*                  ";
	color_change_blue("ѧ��������ѯ");
	cout << "                  *" << endl;
	print_line();
	cout << "*             1.��ѯĳѧ������ʷ                 *" << endl;
	print_line();
	cout << "*          ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 2.��ѯ����ʷ����ѧ�� <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "          *" << endl;
	print_line();
	cout << "*             3.��������ֵ��ߵ�ѧ��             *" << endl;
	print_line();
	cout << "*             0.������һ���˵�                   *" << endl;
	print_line();
}

void love_menu3()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	print_line();
	cout << "*                  ";
	color_change_blue("ѧ��������ѯ");
	cout << "                  *" << endl;
	print_line();
	cout << "*             1.��ѯĳѧ������ʷ                 *" << endl;
	print_line();
	cout << "*             2.��ѯ����ʷ����ѧ��             *" << endl;
	print_line();
	cout << "*          ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 3.��������ֵ��ߵ�ѧ�� <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "          *" << endl;
	print_line();
	cout << "*             0.������һ���˵�                   *" << endl;
	print_line();
}

void love_menu4()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	print_line();
	cout << "*                  ";
	color_change_blue("ѧ��������ѯ");
	cout << "                  *" << endl;
	print_line();
	cout << "*             1.��ѯĳѧ������ʷ                 *" << endl;
	print_line();
	cout << "*             2.��ѯ����ʷ����ѧ��             *" << endl;
	print_line();
	cout << "*             3.��������ֵ��ߵ�ѧ��             *" << endl;
	print_line();
	cout << "*          ";
	SetConsoleTextAttribute(handle, 0x0e);
	cout << ">> 0.������һ���˵� <<";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "                *" << endl;
	print_line();
}

