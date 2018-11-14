#include "hello_screen.h"

void start()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("mode con cols=110 lines=30");		//������ʾ���ڵ�����������

	const vector<string> citiao =
	{
		"�񰡣�����������ʵ��������(\"I am God\"): ",
		"������𾴵����أ�������(\"I am God\"): ",
		"�񰡣��µ�����㲻Ը�⿴�����������ʲô��������������(\"I am God\"): ",
		"�𾴵����Ҵ������࣬���۸��ң� ������(\"I am God\"): ",
		"�����Թ������ˣ� ������(\"I am God\"): ",
		"���ɣ� ����֮(\"I am God\"): "
	};
	const string greeting = "�װ����ϵۣ�\
			\n\n�㽫���ϵ۵��ӽǹ۲���ѧ������Ϣ��\
			\n\n�����ħ������������ϵͳ�ɣ�\
			\n\n������(I am God): ";
	char ch;

	cout << "��\"�س���\"ֱ��������ʾ\"" << endl << endl;

	SetConsoleTextAttribute(handle, 0x0F);
	for (size_t i = 0; i < greeting.length(); i++)
	{
		cout << greeting[i];
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 13)
			{
				for (size_t j = i + 1; j < greeting.length(); ++j)
				{
					cout << greeting[j];
				}
				break;
			}
		}
		Sleep(100);
	}
	SetConsoleTextAttribute(handle, 0x07);

	string tmp;
	srand((unsigned)time(NULL));
	unsigned int cnt = citiao.size();

	while (1)
	{
		SetConsoleTextAttribute(handle, 0x0c);
		getline(cin, tmp);
		SetConsoleTextAttribute(handle, 0x07);
		if ("I am God" != tmp)
		{
			SetConsoleTextAttribute(handle, 0x0F);
			cout << endl << citiao[rand() % cnt] << endl;
			SetConsoleTextAttribute(handle, 0x07);
		}
		else break;
		cin.clear();
	}
}


void choose_start()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	cout << endl;
	print_line();
	cout << "��������������������������������������������������" << endl;
	cout << "��" << string(46, '>') << "��" << endl;
	cout << "��" << string(46, ' ') << "��" << endl;
	cout << "��                                              ��" << endl;
	cout << "��                ";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "ѧ��֮����ϵͳ";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "                ��" << endl;
	cout << "��             ";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "Students ESimulation";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "             ��" << endl;
	cout << "��                                              ��" << endl;
	cout << "��" << string(46, ' ') << "��" << endl;
	cout << "��";
	SetConsoleTextAttribute(handle, 0x0f);
	cout << "         >>> Press Enter To Start <<<         ";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "��" << endl;
	cout << "��                                              ��" << endl;
	cout << "��                                              ��" << endl;
	cout << "��";
	SetConsoleTextAttribute(handle, 0x0c);
	cout << "              Press ESC To Quit               ";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "��" << endl;
	cout << "��" << string(46, ' ') << "��" << endl;
	cout << "��" << string(46, '<') << "��" << endl;
	cout << "��������������������������������������������������" << endl;
	print_line();
}

void cover_guangbiao()
{
	CONSOLE_CURSOR_INFO  cci;
	cci.dwSize = 1;					//������ù��Ĵ�С,ֵΪ1-100
	cci.bVisible = FALSE;			//������ù���Ƿ���ʾ

	HANDLE hOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	BOOL bResult = SetConsoleCursorInfo(hOutputHandle, &cci); //���ù����Ϣ
}

void see_guangbiao()
{
	CONSOLE_CURSOR_INFO  cci;
	cci.dwSize = 25;					//������ù��Ĵ�С,ֵΪ1-100
	cci.bVisible = TRUE;			//������ù���Ƿ���ʾ

	HANDLE hOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	BOOL bResult = SetConsoleCursorInfo(hOutputHandle, &cci); //���ù����Ϣ
}

int show_hello_screen()
{
	char ch;
	choose_start();
	cover_guangbiao();
	while (1)
	{
		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
			case 27:
				cout << endl;
				return 1;
			case 13:
				return 0;
				break;
			}
		}
	}
	return 0;
}